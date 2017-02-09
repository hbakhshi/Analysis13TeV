#include "TH1D.h"
#include "TString.h"
#include "TList.h"
#include <map>
#include <set>
#include <sstream>

using namespace RooFit;
using namespace std;

float pos_one[2] = {1.0,1.0};
float pos_none[2] = {-1.0 , -1.0};

float mtwFit(TString outappendix , TString filename, TString channel , int charge = 0, const int nBinsMTW=20 , int pasformat = 0 , double minMT = 0 , TString noniso_str = "noniso" , float subtractionw_noniso[2] = pos_none /*top , vjets*/ , float nonqcd_iso_factors[2] = pos_one /*top , vjets*/ , bool threecomponents = false , bool usemctemplate=false , bool usemet = false , TString additionalisotree = "" , double efficiencyaddedisotree = 1.0 )
{
  // Objects that we need
  TFile *file = TFile::Open( filename );
 

  TTree* iso_tree = (TTree*)( file->Get( ("Trees/iso" + channel) ) );
  cout << iso_tree->GetEntries() << endl;
  if( additionalisotree != "" ){
    TTree* add_iso_tree = (TTree*)( file->Get( ("Trees/" + additionalisotree + channel)) );
    
    TList* treesss = new TList();
    treesss->Add( iso_tree );
    treesss->Add( add_iso_tree );
    gROOT->cd();
    TTree* t = TTree::MergeTrees( treesss );
    iso_tree = t;
  }
  cout << iso_tree->GetEntries() << endl;

  TTree* noniso_tree = (TTree*)( file->Get( ("Trees/" + noniso_str + channel)) );

  // Roofit variables that we need
  RooRealVar* mtw ;

  if(usemet)
    mtw = new RooRealVar("met", "met", minMT, 200); //N.B : NAME & TITLE exactly the same as the tree variable name !!
  else
    mtw = new RooRealVar("mtw", "m_{T}^{W} (GeV)", minMT, 200); //N.B : NAME & TITLE exactly the same as the tree variable name !!
  
  mtw->setBins(nBinsMTW);  

  RooRealVar weights("weight", "weight", -2., 20000.);//N.B : NAME & TITLE exactly the same as the tree variable name !!
  RooRealVar data("data", "data", -1, 2);
  RooRealVar qcd("qcd", "qcd", -1, 5);
  RooRealVar isPositive("isPositive", "isPositive", -1, 2);
  RooFormulaVar wNegativeW("weights","weights", TString::Format("%F*@0",subtractionw_noniso[1]), RooArgList(weights) ) ;
  RooFormulaVar wNegativeT("weights","weights", TString::Format("%F*@0",subtractionw_noniso[0]), RooArgList(weights) ) ;

  RooFormulaVar wW("weights","weights", TString::Format("%F*@0",nonqcd_iso_factors[1]), RooArgList(weights) ) ;
  RooFormulaVar wT("weights","weights", TString::Format("%F*@0",nonqcd_iso_factors[0]), RooArgList(weights) ) ;

  // wNegativeT.printMultiline( cout , 1 );
  // wNegativeW.printMultiline( cout , 1 );

  // wW.printMultiline(cout , 1);
  // wT.printMultiline( cout , 1);
  // Define cut sequence
  std::vector<std::string> cuts;
  std::string cutCharge("isPositive > -1" );
  if( charge > 0 )
    cutCharge = "isPositive == 1";
  else if(charge < 0)
    cutCharge = "isPositive == 0";
  std::string cutData("data == 1 && " + cutCharge);
  std::string cutTop("qcd == 2 && " + cutCharge);
  std::string cutVJets("qcd > 2.99 && " + cutCharge);
  std::string cutQCD("qcd == 1 && " + cutCharge);


  RooDataSet * uw_ds_data_iso = new RooDataSet( "uw_ds_data_iso" , "uw_ds_data_iso" , RooArgSet(*mtw,weights,data,qcd,isPositive), Import(*iso_tree), Cut( cutData.data() ) );
  RooDataSet * w_ds_data_iso = 	new RooDataSet( "w_ds_data_iso" , "w_ds_data_iso" , uw_ds_data_iso ,*uw_ds_data_iso->get(),0, weights.GetName()   );

  RooDataSet * uw_ds_top_iso = new RooDataSet("uw_ds_top_iso","uw_ds_top_iso",RooArgSet(*mtw,weights,data,qcd,isPositive),Import(*iso_tree), Cut( cutTop.data() ) );
  RooAbsArg* w_t = uw_ds_top_iso->addColumn(wT);
  RooDataSet * w_ds_top_iso = new RooDataSet("w_ds_top_iso","w_ds_top_iso",uw_ds_top_iso,*uw_ds_top_iso->get(),0, w_t->GetName());

  RooDataSet * uw_ds_vjets_iso = new RooDataSet("uw_ds_vjets_iso","uw_ds_vjets_iso",RooArgSet(*mtw,weights,data,qcd,isPositive),Import(*iso_tree), Cut( cutVJets.data() ) );
  RooAbsArg* w_w = uw_ds_vjets_iso->addColumn(wW);
  RooDataSet * w_ds_vjets_iso = new RooDataSet("w_ds_vjets_iso","w_ds_vjets_iso",uw_ds_vjets_iso,*uw_ds_vjets_iso->get(),0, w_w->GetName());

  RooDataSet * uw_ds_qcd_iso = new RooDataSet("uw_ds_qcd_iso","uw_ds_qcd_iso",RooArgSet(*mtw,weights,data,qcd,isPositive),Import(*iso_tree), Cut( cutQCD.data() ) );
  RooDataSet * w_ds_qcd_iso = new RooDataSet("w_ds_qcd_iso","w_ds_qcd_iso",uw_ds_qcd_iso,*uw_ds_qcd_iso->get(),0, weights.GetName());

  RooDataSet * w_ds_mc_iso = new RooDataSet(*w_ds_vjets_iso);
  w_ds_mc_iso->append( *w_ds_top_iso );


  RooDataSet * uw_ds_data_noniso = new RooDataSet("uw_ds_data_noniso" , "uw_ds_data_noniso",RooArgSet(*mtw,weights,data,qcd,isPositive), Import(*noniso_tree), Cut( cutData.data() ) );
  RooDataSet * w_ds_data_noniso = new RooDataSet("w_ds_data_noniso","w_ds_data_noniso",uw_ds_data_noniso ,*uw_ds_data_noniso->get(),0, weights.GetName());

  RooDataSet * uw_ds_top_noniso   = new RooDataSet("uw_ds_top_noniso"  ,"uw_ds_top_noniso"  ,RooArgSet(*mtw,weights,data,qcd,isPositive),Import(*noniso_tree), Cut( cutTop.data() ) );
  RooAbsArg* wn_t = uw_ds_top_noniso->addColumn(wNegativeT);
  RooDataSet * w_ds_top_noniso = new RooDataSet("w_ds_top_noniso","w_ds_top_noniso",uw_ds_top_noniso,*uw_ds_top_noniso->get(),0, wn_t->GetName() );

  RooDataSet * uw_ds_vjets_noniso = new RooDataSet("uw_ds_vjets_noniso","uw_ds_vjets_noniso",RooArgSet(*mtw,weights,data,qcd,isPositive),Import(*noniso_tree), Cut( cutVJets.data() ) );
  RooAbsArg* wn_v = uw_ds_vjets_noniso->addColumn(wNegativeW);
  RooDataSet * w_ds_vjets_noniso = new RooDataSet("w_ds_vjets_noniso","w_ds_vjets_noniso",uw_ds_vjets_noniso,*uw_ds_vjets_noniso->get(),0, wn_v->GetName() );

  RooDataSet * w_ds_mc_noniso = w_ds_top_noniso ;
  cout << "mc_non_iso (only top) : " << w_ds_top_noniso->sumEntries();
  cout << "  vjets_non_iso : " << w_ds_vjets_noniso->sumEntries();
  cout << "  vjets_iso : " << w_ds_vjets_iso->sumEntries();
  cout << "  top_iso : " << w_ds_top_iso->sumEntries();
  cout << "  mc_iso : " << w_ds_mc_iso->sumEntries();
  w_ds_mc_noniso->append( *w_ds_vjets_noniso ) ;
  cout << "         mc_non_iso (+W) : " << w_ds_mc_noniso->sumEntries() << endl;

  // C r e a t e   b i n n e d   v e r s i o n s   o f   d a t a s e t s
  // --
  RooDataHist *binnedQCDIsolated = new RooDataHist("binnedQCDIsolated","binnedQCDIsolated",RooArgSet(*mtw),*w_ds_qcd_iso);  
  double NQCDExpected = binnedQCDIsolated->sumEntries();

  RooDataHist *binnedDataIsolated = new RooDataHist("binnedDataIsolated","binnedDataIsolated",RooArgSet(*mtw),*w_ds_data_iso);
  RooDataHist *binnedMCIsolated = new RooDataHist("binnedMCIsolated" , "binnedMCIsolated" , RooArgSet(*mtw) , *w_ds_mc_iso) ;
  RooDataHist *binnedTopIsolated = new RooDataHist("binnedTopIsolated" , "binnedTopIsolated" , RooArgSet(*mtw) , *w_ds_top_iso);
  RooDataHist *binnedVJetsIsolated = new RooDataHist("binnedVJetsIsolated" , "binnedVJetsIsolated" , RooArgSet(*mtw) , *w_ds_vjets_iso);


  RooHistPdf NonQCD_PDF("NonQCD_PDF","NonQCD_PDF", *mtw , *binnedMCIsolated );

  RooHistPdf NonQCD_Top_PDF("NonQCD_Top_PDF","NonQCD_Top_PDF", *mtw , *binnedTopIsolated );
  RooHistPdf NonQCD_VJets_PDF("NonQCD_VJets_PDF","NonQCD_VJets_PDF", *mtw , *binnedVJetsIsolated );

  double TopExpected   = binnedTopIsolated->sumEntries();
  double VJetsExpected = binnedVJetsIsolated->sumEntries();

  double NonQCDExpected = binnedMCIsolated->sumEntries();
  cout << "In isolated region : data=" << binnedDataIsolated->sumEntries() << " non_qcd=" <<  NonQCDExpected << " qcd=" << NQCDExpected << endl; 

  RooDataHist *binnedDataAntiIsolated = new RooDataHist("binnedDataAntiIsolated","binnedDataAntiIsolated",RooArgSet(*mtw),*w_ds_data_noniso);
  RooDataHist *binnedMCAntiIsolated = new RooDataHist("binnedMCAntiIsolated" , "binnedMCAntiIsolated" , RooArgSet(*mtw) , *w_ds_mc_noniso) ;
   
  w_ds_data_noniso->append(*w_ds_mc_noniso);
  RooDataHist *binnedQCDAntiIsolatedTemplate = new RooDataHist("QCD template from antisolated region", "QCD template from antisolated region",RooArgSet(*mtw),*w_ds_data_noniso) ;

  RooHistPdf* QCD_PDF;
  if(usemctemplate)
    QCD_PDF = new RooHistPdf("QCD_PDF","QCD_PDF", *mtw , *binnedQCDIsolated );
  else
    QCD_PDF = new RooHistPdf("QCD_PDF","QCD_PDF",*mtw,*binnedQCDAntiIsolatedTemplate);
    

  // Parameter initial values and ranges
  double sigma_qcd =sqrt(NQCDExpected); double max_qcd= NQCDExpected + (1.5 * sigma_qcd); double min_qcd=0 ; // NQCDExpected - (50.0*sigma_qcd);
  double sigma_nqcd= sqrt(NonQCDExpected); double max_nqcd= NonQCDExpected + (50. * sigma_nqcd); double min_nqcd= NonQCDExpected - (50. * sigma_nqcd);
  double sigma_top= sqrt(TopExpected); double max_top= TopExpected + (50. * sigma_top); double min_top= TopExpected - (50. * sigma_top);
  double sigma_vjets= sqrt(VJetsExpected); double max_vjets= VJetsExpected + (50. * sigma_vjets); double min_vjets = VJetsExpected - (50. * sigma_vjets);

  RooRealVar NnQCD_VJets("NonQCD VJets Events","NnQCD_VJets",VJetsExpected,min_vjets,max_vjets);
  RooRealVar NnQCD_Top("NonQCD Top Events","NnQCD_Top",TopExpected,min_top,max_top);
  RooRealVar NnQCD("NonQCD Events","NnQCD",NonQCDExpected,min_nqcd,max_nqcd);
  RooRealVar NQCD("QCD Events","NQCD",NQCDExpected,min_qcd,max_qcd);

  // Objects for plotting 
  gStyle->SetTitleX(0.23);
  gStyle->SetTitleY(0.96);

  gStyle->SetLabelFont( 42 , "X" );
  gStyle->SetLabelOffset( 0.012 , "X" );
  gStyle->SetLabelSize( 0.05 , "X" );
  gStyle->SetTitleFont( 42 , "X" );
  gStyle->SetTitleSize( 0.06 , "X" );

  gStyle->SetLabelFont( 42 , "Y" );
  gStyle->SetLabelOffset( 0.012 , "Y" );
  gStyle->SetLabelSize( 0.04 , "Y" );
  gStyle->SetTitleFont( 42 , "Y" );
  gStyle->SetTitleSize( 0.04 , "Y" );
  gStyle->SetTitleOffset( 1.51 , "Y" );

  gStyle->SetPadLeftMargin(0.14);
  gStyle->SetPadBottomMargin(0.14);

  TCanvas* can=new TCanvas("Canvas","Canvas"); 
  can->cd();

  TString title = channel ;
  if( channel == "2j1t" )
    title = "2-jet 1-tag";
  else if ( channel == "3j2t" )
    title = "3-jet 2-tag";
  else if ( channel == "3j1t" )
    title = "3-jet 1-tag";

  if( charge == 0 )
    title += ", all #mu's";
  if( charge > 0 )
    title += ", #mu^{+}";
  if( charge < 0 )
    title += ", #mu^{-}";

  RooPlot* frame = mtw->frame(Title(title)); 

  RooAbsData::PlotOpt opts;
  opts.histName = "data";
  opts.drawOptions = "same";
  opts.histInvisible = true;
  binnedDataIsolated->plotOn(frame,opts );
        
  RooAddPdf* model;
  if(threecomponents)
    model =new RooAddPdf("model","model",RooArgList(*QCD_PDF,NonQCD_Top_PDF,NonQCD_VJets_PDF),RooArgList(NQCD,NnQCD_Top,NnQCD_VJets));
  else
    model =new RooAddPdf("model","model",RooArgList(*QCD_PDF,NonQCD_PDF),RooArgList(NQCD, NnQCD));
  RooFitResult* res = model->fitTo(*binnedDataIsolated,Extended(kTRUE),RooFit::Save(kTRUE), SumW2Error(kTRUE));

  // Plot result
  model->plotOn(frame,Name("Fit")); 
  if( pasformat == 0 )
    model->paramOn(frame);
  model->plotOn(frame, Name("qcd"), Components(RooArgList(*QCD_PDF)), LineColor(kRed),LineStyle(1), LineWidth(4));
  model->plotOn(frame, Name("non-qcd"), Components(RooArgList(NonQCD_PDF)), LineColor(kGreen),LineStyle(1), LineWidth(4));

  binnedDataIsolated->plotOn(frame,Name(""));

  //plot cms preliminary
  TPaveText *boxcms = new TPaveText(0.15, 0.75, 0.35, 0.89,"BRNDC");
  boxcms->SetFillColor(10);
  boxcms->SetBorderSize(0);
  boxcms->SetTextAlign(12);
  boxcms->SetFillStyle(1001);

  TText *text = 0;
  Char_t buf[50];
  sprintf( buf,  "CMS" );
  text = boxcms->AddText( buf );
  text->SetTextFont(42);
  text->SetTextSize( 0.042 );
  sprintf( buf,  "Preliminary" );
  text = boxcms->AddText( buf );
  text->SetTextFont(52);
  text->SetTextSize( 0.045 );
  frame->addObject( boxcms );

  // Plot chi2 result
  TPaveText *box;
  if( pasformat == 0 )
    box = new TPaveText(0.6, 0.55, 0.9, 0.8,"BRNDC");
  else
    box = new TPaveText(0.7, 0.5, 0.89, 0.6,"BRNDC");

  box->SetFillColor(10);
  box->SetBorderSize(!pasformat);
  box->SetTextAlign(12);
  box->SetTextSize(0.04F);
  box->SetFillStyle(1001);
  box->SetFillColor(10);
  text = 0;
  sprintf( buf,  "#chi^{2}/ndf = %.2f", frame->chiSquare("Fit" , "data" , 2) );
  text = box->AddText( buf );
  //frame->addObject(box) ;  
		
  TLegend* leg;
  if( pasformat == 0 )
    leg = new TLegend(0.75,0.2,0.90,0.45);
  else
    leg = new TLegend(0.7,0.6,0.89,0.89);
  leg->SetTextSize(0.037); leg->SetBorderSize(0); leg->SetLineStyle(0); leg->SetTextSize(0.027); leg->SetFillStyle(0); leg->SetFillColor(0);
    

  // Loop over fit results
  RooAbsArg* aptr = model->pdfList().find("QCD_PDF");
  TIterator * itPdf = model->pdfList().createIterator();
  TIterator * itCoef = model->coefList().createIterator();

  float ret = -1.0;
  for(int ii =0; ii < model->pdfList().getSize(); ii++)
    {
      RooAbsReal * argP = (RooAbsReal*)itPdf->Next();
      RooAbsReal * argC = (RooAbsReal*)itCoef->Next();
      std::cout << "Parameter "<<argC->GetName() << " has a best fit value of "<< argC->getVal() << " in the whole MTW region ";

      mtw->setRange("cut", 50., 200.); // Extrapolate in >50 region
      RooAbsReal *sig = argP->createIntegral(*mtw, NormSet(*mtw), Range("cut"));
      double IntegralValue = sig->getVal();
      std::cout << "and after extapolating to >50 region: "<< argC->getVal()*IntegralValue << std::endl;

      sprintf( buf,  "N_{%s}^{mtw>50} = %.2f", argC->GetName() , argC->getVal()*IntegralValue );
      if( ! TString(argC->GetName()).Contains("NonQCD") )
	ret = argC->getVal()*IntegralValue;
      if( pasformat == 0 )
	text = box->AddText( buf );
    }
    
  frame->addObject(box) ;  

  frame->Draw();
  leg->AddEntry("13TeV Data","SingleMu","PLE1"); leg->AddEntry("Fit","Fit","l"); leg->AddEntry("non-qcd","NonQCD","l"); leg->AddEntry("qcd","QCD","l"); leg->Draw();
    
  TLatex *   tex ;
  if(pasformat == 1)
    tex = new TLatex(0.91,0.92,"2.3 fb^{-1} (13 TeV)");
  else
    tex = new TLatex(0.91,0.95,"2.3 fb^{-1} (13 TeV)");
  tex->SetNDC();
  tex->SetTextAlign(31);
  tex->SetTextFont(42);
  tex->SetTextSize(0.048);
  tex->SetLineWidth(2);
  tex->Draw();


  TString outname = channel ;
  if( charge == 0 )
    outname += "_all";
  if( charge > 0 )
    outname += "_p";
  if( charge < 0 )
    outname += "_n";

  outname += "_" + outappendix + "_" + noniso_str ;

  can->SaveAs( outname + ".C");
  can->SaveAs( outname + ".pdf");

  can->SaveAs( outname + ".png");

  delete model;

  return efficiencyaddedisotree*ret;
}



//float mtwFit(TString filename, TString channel , int charge = 0, const int nBinsMTW=20 , int pasformat = 0 , double minMT = 0 , string noniso_str = "noniso" , float subtractionw_noniso[2] = pos_none /*top , vjets*/ , float nonqcd_iso_factors[2] = pos_one /*top , vjets*/ , bool threecomponents=false , bool usemctemplate=false , usemet = false , TString additionalisotree = "" , double efficiencyaddedisotree = 1.0 ) )
void mtwFit(TString noniso_name="noniso" , int charge=0 ,TString channel="2j1t" , TString filename = "../cp3_condor/TChFARM_V6/outputs/TChannel_V6.root"  ){
  float centralvalue = mtwFit( "central" , filename , channel , charge , 20 , 0 , 0 , noniso_name , pos_none , pos_one);

  float upup[2] = {1.2 , 1.3}; float updown[2] = {1.2 , -1.3}; float downdown[2] = {-1.2 , -1.3}; float downup[2] = {-1.2 , 1.3}; 
  float top_20_w_30  = mtwFit( "top_20_w_30" , filename , channel ,charge , 20 , 0 , 0 , noniso_name , upup , pos_one);
  float top_m20_w_m30  = mtwFit( "top_m20_w_m30" , filename , channel , charge , 20 , 0 , 0 , noniso_name , downdown  , pos_one);
  float top_m20_w_30  = mtwFit( "top_m20_w_30" , filename , channel , charge , 20 , 0 , 0 , noniso_name , downup , pos_one);
  float top_20_w_m30  = mtwFit( "top_20_w_m30" , filename , channel , charge , 20 , 0 , 0 , noniso_name , updown , pos_one);

  float mtw_gt_10 = mtwFit("mtw_gt_10" , filename , channel , charge , 19 , 0 , 10.0 , noniso_name , pos_none , pos_one);

  float separate_top_wjets = mtwFit( "separate_top_wjets" , filename , channel , charge , 20 , 0 , 0.0 , noniso_name , pos_none , pos_one , true);

  float mcqcdtemplate = mtwFit( "mcqcdtemplate", filename , channel , charge , 20 , 0 , 0.0 , noniso_name , pos_none , pos_one , false , true);

  float met = mtwFit( "met" , filename , channel , charge , 20 , 0 , 0.0 , noniso_name , pos_none , pos_one , false , false, true);

  float uptoiso12 = mtwFit( "uptoiso12" , filename , channel , charge , 20 , 0 , 0.0 , noniso_name , pos_none , pos_one , false , false, false , "midiso" , 0.5);

  cout << "central|" << "top_20_w_30|" << "top_m20_w_m30|" << "top_m20_w_30|" << "top_20_w_m30|" << "mtw_gt_10|"<< "separate_top_wjets|" << "mcqcdtemplate|" << "met|" << "uptoiso12|" << endl;

  cout << centralvalue<< "|" << top_20_w_30<< "|" << top_m20_w_m30<< "|" << top_m20_w_30<< "|" << top_20_w_m30<< "|" << mtw_gt_10<< "|"<< separate_top_wjets<< "|" << mcqcdtemplate<< "|" << met<< "|" << uptoiso12 << "|"  << endl;

}

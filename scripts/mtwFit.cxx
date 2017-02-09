#include "TH1D.h"
#include "TString.h"
#include "TList.h"
#include <map>
#include <set>
#include <sstream>

using namespace RooFit;
using namespace std;

void mtwFit(TString filename, TString channel , int charge = 0, const int nBinsMTW=20 , int pasformat = 0)
{
  // Objects that we need
  TFile *file = TFile::Open( filename );

  TFile *fileMG = TFile::Open( "../cp3_condor/TChFARM_V5/outputs/TChannel_V5.root" );

  TTree* iso_tree = (TTree*)( fileMG->Get( ("Trees/iso" + channel) ) );
  TTree* noniso_tree = (TTree*)( file->Get( ("Trees/noniso" + channel)) );

  // Roofit variables that we need
  RooRealVar mtw("mtw", "m_{T}^{W} (GeV)", 0, 200); //N.B : NAME & TITLE exactly the same as the tree variable name !!
  mtw.setBins(nBinsMTW);  
  RooRealVar weights("weight", "weight", -2., 20000.);//N.B : NAME & TITLE exactly the same as the tree variable name !!
  RooRealVar data("data", "data", -1, 2);
  RooRealVar qcd("qcd", "qcd", -1, 2);
  RooRealVar isPositive("isPositive", "isPositive", -1, 2);
  //RooFormulaVar wNegative("weights","weights","-1*2231.8*@0/2093.37", RooArgList(weights) ) ;
  RooFormulaVar wNegative("weights","weights","-1*@0", RooArgList(weights) ) ;

  // Define cut sequence
  std::vector<std::string> cuts;
  std::string cutCharge("isPositive > -1" );
  if( charge > 0 )
    cutCharge = "isPositive == 1";
  else if(charge < 0)
    cutCharge = "isPositive == 0";
  std::string cutData("data == 1 && " + cutCharge);
  std::string cutMC("data != 1 && qcd != 1 && " + cutCharge);
  std::string cutQCD("qcd == 1 && " + cutCharge);


  RooDataSet * uw_ds_data_iso = new RooDataSet( "uw_ds_data_iso" , "uw_ds_data_iso" , RooArgSet(mtw,weights,data,qcd,isPositive), Import(*iso_tree), Cut( cutData.data() ) );
  RooDataSet * w_ds_data_iso = 	new RooDataSet( "w_ds_data_iso" , "w_ds_data_iso" , uw_ds_data_iso ,*uw_ds_data_iso->get(),0, weights.GetName()   );

  RooDataSet * uw_ds_data_noniso = new RooDataSet("uw_ds_data_noniso" , "uw_ds_data_noniso",RooArgSet(mtw,weights,data,qcd,isPositive), Import(*noniso_tree), Cut( cutData.data() ) );
  RooDataSet * w_ds_data_noniso = new RooDataSet("w_ds_data_noniso","w_ds_data_noniso",uw_ds_data_noniso ,*uw_ds_data_noniso->get(),0, weights.GetName());

  RooDataSet * uw_ds_mc_iso = new RooDataSet("uw_ds_mc_iso","uw_ds_mc_iso",RooArgSet(mtw,weights,data,qcd,isPositive),Import(*iso_tree), Cut( cutMC.data() ) );
  RooDataSet * w_ds_mc_iso = new RooDataSet("w_ds_mc_iso","w_ds_mc_iso",uw_ds_mc_iso,*uw_ds_mc_iso->get(),0, weights.GetName());

  RooDataSet * uw_ds_qcd_iso = new RooDataSet("uw_ds_mc_iso","uw_ds_mc_iso",RooArgSet(mtw,weights,data,qcd,isPositive),Import(*iso_tree), Cut( cutQCD.data() ) );
  RooDataSet * w_ds_qcd_iso = new RooDataSet("w_ds_mc_iso","w_ds_mc_iso",uw_ds_qcd_iso,*uw_ds_qcd_iso->get(),0, weights.GetName());


  RooDataSet * uw_ds_mc_noniso = new RooDataSet("uw_ds_mc_noniso","uw_ds_mc_noniso",RooArgSet(mtw,weights,data,qcd,isPositive),Import(*noniso_tree), Cut( cutMC.data() ) );
  RooAbsArg* wn = uw_ds_mc_noniso->addColumn(wNegative);
  RooDataSet * w_ds_mc_noniso = new RooDataSet("w_ds_mc_noniso","w_ds_mc_noniso",uw_ds_mc_noniso,*uw_ds_mc_noniso->get(),0, wn->GetName() );


  
  // C r e a t e   b i n n e d   v e r s i o n s   o f   d a t a s e t s
  // --
  RooDataHist *binnedQCDIsolated = new RooDataHist("binnedQCDIsolated","binnedQCDIsolated",RooArgSet(mtw),*w_ds_qcd_iso);  

  RooDataHist *binnedDataLessIsolated = new RooDataHist("binnedDataLessIsolated","binnedDataLessIsolated",RooArgSet(mtw),*w_ds_data_iso);
  RooDataHist *binnedDataAntiIsolated = new RooDataHist("binnedDataAntiIsolated","binnedDataAntiIsolated",RooArgSet(mtw),*w_ds_data_noniso);

  RooDataHist *binnedMCLessIsolated = new RooDataHist("binnedMCLessIsolated" , "binnedMCLessIsolated" , RooArgSet(mtw) , *w_ds_mc_iso) ;
  RooDataHist *binnedMCAntiIsolated = new RooDataHist("binnedMCAntiIsolated" , "binnedMCAntiIsolated" , RooArgSet(mtw) , *w_ds_mc_noniso) ;

    
  w_ds_data_noniso->append(*w_ds_mc_noniso);
  RooDataHist *binnedQCDAntiIsolatedTemplate = new RooDataHist("QCD template from antisolated region", "QCD template from antisolated region",RooArgSet(mtw),*w_ds_data_noniso) ;
    
  // C r e a t e   P D F s   o f   b i n n e d  d a t a s e t s (t e m p l a t e s)
  // --

  RooHistPdf QCD_ISO_PDF("QCD_ISO_PDF","QCD_ISO_PDF",mtw,*binnedQCDIsolated);

  RooHistPdf QCD_PDF("QCD_PDF","QCD_PDF",mtw,*binnedQCDAntiIsolatedTemplate);
  RooHistPdf NonQCD_PDF("NonQCD_PDF","NonQCD_PDF",mtw,*binnedMCLessIsolated);

  //
  //To be done for a proper estimation of parameter range!! 
  //TH1 * h1 = dataAntiIsolated->createHistogram("",mtw,Binning(nBinsMTW));
  //Double_t error;
  //std::cout<<h1->Integral()<<" "<< h1->IntegralAndError(1,h1->GetNbinsX(), error)<< " "<<error<<std::endl;
  //
  //

  // Parameter initial values and ranges
  double NQCDExprected = binnedQCDIsolated->sumEntries();
  double NonQCDExprected = binnedMCLessIsolated->sumEntries();
  cout << NonQCDExprected << " , " << NQCDExprected << endl;
    

  double sigma_qcd =sqrt(NQCDExprected); double max_qcd= NQCDExprected + (1.5 * sigma_qcd); double min_qcd=0 ; // NQCDExprected - (50.0*sigma_qcd);
  double sigma_nqcd= sqrt(NonQCDExprected); double max_nqcd= NonQCDExprected + (50. * sigma_nqcd); double min_nqcd= NonQCDExprected - (50. * sigma_nqcd);

  RooRealVar NnQCD("NonQCD Events","NnQCD",NonQCDExprected,min_nqcd,max_nqcd);
  RooRealVar NQCD("QCD Events","NQCD",NQCDExprected,min_qcd,max_qcd);
  //RooRealVar F("F","F",0.5,0,1);
  //RooRealVar N("N","N",50000,0,100000);

  // Objecrts for plotting 
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

  RooPlot* frame = mtw.frame(Title(title)); 

  RooAbsData::PlotOpt opts;
  opts.histName = "data";
  opts.drawOptions = "same";
  opts.histInvisible = true;
  binnedDataLessIsolated->plotOn(frame,opts ); //Name(""));
        
  cout << "data : " << binnedDataLessIsolated->sumEntries() <<endl; 
  // C o n s t r u c t   p l a i n   l i k e l i h o o d
  // ---------------------------------------------------

  // Define your model, i.e. a two template fit
  //  RooAddPdf model("model","model",RooArgList(NonQCD_PDF,QCD_PDF),RooArgList(NnQCD,NQCD));
  RooAddPdf model("model","model",RooArgList(QCD_PDF,NonQCD_PDF),RooArgList(NQCD, NnQCD));
  // RooExtendPdf ext("ext","ext", model,N);
  // Minimize likelihood w.r.t all parameters before making plots
  RooFitResult* res = model.fitTo(*binnedDataLessIsolated,Extended(kTRUE),RooFit::Save(kTRUE), SumW2Error(kTRUE)) ; // , Range(0.,50.));

  // Plot result
  model.plotOn(frame,Name("Fit")); 
  if( pasformat == 0 )
    model.paramOn(frame);
  model.plotOn(frame, Name("qcd"), Components(RooArgList(QCD_PDF)), LineColor(kRed),LineStyle(1), LineWidth(4));
  model.plotOn(frame, Name("non-qcd"), Components(RooArgList(NonQCD_PDF)), LineColor(kGreen),LineStyle(1), LineWidth(4));

  binnedDataLessIsolated->plotOn(frame,Name(""));

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
  RooAbsArg* aptr = model.pdfList().find("QCD_PDF");
  TIterator * itPdf = model.pdfList().createIterator();
  TIterator * itCoef = model.coefList().createIterator();

  mtw.setRange("cut", 50., 200.); // Extrapolate in >50 region
  for(int ii =0; ii < model.pdfList().getSize(); ii++)
    {
      RooAbsReal * argP = (RooAbsReal*)itPdf->Next();
      RooAbsReal * argC = (RooAbsReal*)itCoef->Next();
      std::cout << "Parameter "<<argC->GetName() << " has a best fit value of "<< argC->getVal() << " in the whole MTW region ";

      
      RooAbsReal *sig = argP->createIntegral(mtw, NormSet(mtw), Range("cut"));
      double IntegralValue = sig->getVal();
      std::cout << IntegralValue << " and after extapolating to >50 region: "<< argC->getVal()*IntegralValue << std::endl;

      sprintf( buf,  "N_{%s}^{mtw>50} = %.2f", argC->GetName() , argC->getVal()*IntegralValue );
      if( pasformat == 0 )
	text = box->AddText( buf );
    }
    
  frame->addObject(box) ;  

  frame->Draw();
  leg->AddEntry("13TeV Data","SingleMu","PLE1"); leg->AddEntry("Fit","Fit","l"); leg->AddEntry("non-qcd","NonQCD","l"); leg->AddEntry("qcd","QCD","l"); leg->Draw();
    
  TLatex *   tex ;
  if(pasformat == 1)
    tex = new TLatex(0.91,0.92,"2.2 fb^{-1} (13 TeV)");
  else
    tex = new TLatex(0.91,0.95,"2.2 fb^{-1} (13 TeV)");
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

  can->SaveAs( outname + ".C");
  can->SaveAs( outname + ".pdf");

  can->SaveAs( outname + ".png");
    		
}

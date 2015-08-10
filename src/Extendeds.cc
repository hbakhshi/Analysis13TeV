#include "TList.h"
#include "Extendeds.hh"
#include <vector>
#include <string.h>
#include "TRandom.h"

void ExtendedObjectProperty::makeCard(double N, double S, double dS, double B, double dB, string sOut) {

    // === DATA CARD ===
    ofstream fOut(sOut.c_str());
    fOut.precision(3);
    fOut << "imax 1  number of channels" << std::endl;
    fOut << "jmax 1  number of backgrounds" << std::endl;
    fOut << "kmax 2  number of nuisance parameters (sources of systematic uncertainties)" << std::endl;
    fOut << "---" << std::endl;
    fOut << "bin b1" << std::endl;
    fOut << "observation " << N << std::endl;
    fOut << "---" << std::endl;
    fOut << "bin              b1     b1" << std::endl;
    fOut << "process         SMS    All" << std::endl;
    fOut << "process          0     1  " << std::endl;
    fOut << "rate           " << S << "\t" << B << std::endl;
    fOut << "---" << std::endl;
    fOut << "dS  lnN    " << 1 + dS << "\t-" << std::endl;
    fOut << "dB  lnN    - \t " << 1 + dB << std::endl;
    fOut.close();

}


void ExtendedObjectProperty::CalcSig(int LowerCut , int type,  int SUSCat , double sys  ) {

  TString cutType = LowerCut==0? "upperCut" : "lowerCut" ;
  TH1 *hBkg = allHistos["MC"];
  TString xtitle = Name;
  //Float_t  x[nBins], y[nBins];

  TString SignalHistoName = "SUSY";
  if( SUSCat > -1 && SUSCat < int(SUSYNames.size()) )
    SignalHistoName += "_" + SUSYNames[SUSCat] ;

  TH1 *hSgn = allHistos[SignalHistoName];

    int nbins = hSgn->GetXaxis()->GetNbins();
    float *x = new float[nbins];
    float *ex = new float[nbins];
    float *y = new float[nbins];
    float *ey = new float[nbins];
    float *eyp = new float[nbins];
    float *eym = new float[nbins];

    for (int i = 1; i <= nbins; i++) {

        x[i - 1] = hSgn->GetBinLowEdge(i);
        ex[i - 1] = hSgn->GetBinWidth(i);

        double s = (cutType == "lowerCut") ? hSgn->Integral(i, nbins + 1) : hSgn->Integral(0, i);
        double ds = sqrt(s) + s * sys;
        double b = (cutType == "lowerCut") ? hBkg->Integral(i, nbins + 1) : hBkg->Integral(0, i);
        double db = sqrt(b) + b * sys;


        if (b == 0 || s == 0) {
            y[i - 1] = .0;
            ey[i - 1] = .0;
        } else {
            if (type == 0) {
                y[i - 1] = s / sqrt(b);
                ey[i - 1] = y[i - 1] * (ds / s + db / (2 * b));
            }
            if (type == 1) {
                y[i - 1] = s / sqrt(s + b);
                ey[i - 1] = y[i - 1] * (ds / s + (db + ds) / (2 * (b + s)));
            }
            if (type == 2) {
                y[i - 1] = s / b;
                ey[i - 1] = y[i - 1] * (ds / s + db / b);
            }
            if (type == 3) {

                makeCard(b, s, sys, b, sys, "datacard");
                if (!(std::ifstream("datacard")).good()) continue;
                system("combine -M Asymptotic datacard");
                TTree* tree;
                TFile * flimit = new TFile("higgsCombineTest.Asymptotic.mH120.root");
                flimit->GetObject("limit", tree);

                Double_t limit;
                TBranch *b_limit; //!
                tree->SetBranchAddress("limit", &limit, &b_limit);

                Float_t quantileExpected;
                TBranch *b_quantileExpected; //!
                tree->SetBranchAddress("quantileExpected", &quantileExpected, &b_quantileExpected);

                std::vector<double> vLimit;
                Long64_t nEntrs = tree->GetEntriesFast();
                for (Long64_t iEntr = 0; iEntr < nEntrs; iEntr++) {
                    tree->GetEntry(iEntr);
                    cout << ">> quantileExpected: " << quantileExpected << "\tlimit: " << limit << endl;
                    vLimit.push_back(limit);
                }

                double  SgmP1(vLimit[1]), Mdn(vLimit[2]), SgmM1(vLimit[3]); // SgmP2(vLimit[0]), SgmM2(vLimit[4]), Obs(vLimit[5]);

                y[i - 1] = Mdn;
                eyp[i - 1] = SgmM1 - y[i - 1];
                eym[i - 1] = y[i - 1] - SgmP1;

                system("rm -f higgsCombineTest.Asymptotic.mH120.root");
                system("rm -f datacard");
                system("rm -f roostat*");

            }
        }
    }

    TGraphAsymmErrors *sig = new TGraphAsymmErrors(nbins, x, y, ex, ey);
    if (type == 3) sig = new TGraphAsymmErrors(nbins, x, y, ex, ex, eym, eyp);

    TString nnn = Name + "_" + std::to_string(LowerCut) + "_" + std::to_string(type) + "_" + SignalHistoName + "_" + CutName ;
    sig->SetName( nnn );
    //sig->SetTitle(SignalHistoName);
    //sig->GetXaxis()->SetTitle(Name + "(" + (LowerCut?"LowerLimit":"UpperLimit") + ")" );
  
    sig->SetTitle("");
    sig->GetXaxis()->SetTitle(xtitle + "_" + cutType);
    sig->SetMarkerStyle(20);
    sig->SetFillColor(kBlue-7);
    sig->SetFillStyle(3005);
    if (type == 0) sig->GetYaxis()->SetTitle("S/#sqrt{B}");
    if (type == 1) sig->GetYaxis()->SetTitle("S/#sqrt{S+B}");
    if (type == 2) sig->GetYaxis()->SetTitle("S/B");
    if (type == 3) sig->GetYaxis()->SetTitle("signal strength (r)");

    AllSignificances.push_back( sig );


//   for (int i = 1; i <=nBins+1; i++){
//     x[i-1] = theMCH->GetBinLowEdge(i);
//     if(verbose) cout <<i<<" x[i-1] "<<x[i-1]<<endl;
//     float s;
//     if(LowerCut == 1) 
//       s = allHistos[SignalHistoName]->Integral(i,nBins+1);
//     else	
//       s = allHistos[SignalHistoName]->Integral(0, i - 1);
//     if(verbose) cout <<" s "<<s<<endl;
//     float b;
//     if(LowerCut == 1) 
//       b = theMCH->Integral(i,nBins+1);
//     else
//       b = theMCH->Integral(0, i - 1);
//     if(verbose) cout <<" b "<<b<<endl;
//     if(b == 0)
//       y[i-1] = 5.0;
//     else{
//       if (type==0) {
// 	y[i-1] = s/sqrt(b);
//       }
//       if (type==1) {
// 	y[i-1] = s/sqrt(s+b);
//       }
//       if (type==2) {
// 	y[i-1] = s/b;
//       }
//       if(verbose) cout <<" y[i-1] "<<y[i-1]<<endl;
//     }
//   }
//   TGraph *sig = new TGraph(nBins+1,x,y);
//   sig->SetMarkerStyle(20);
//   if (type==0){
//     sig->GetYaxis()->SetTitle("S/#sqrt{B}");
//   }
//   if (type==1){
//     sig->GetYaxis()->SetTitle("S/#sqrt{S+B}");
//   }
//   if (type==2){
//     sig->GetYaxis()->SetTitle("S/B");
	  
//   }
}

void ExtendedObjectProperty::Print(TString option ) const{
  //cout << option << endl;
  if( option == ""  ){
    cout << "\t" 
	 << Name << " , " 
	 << Formula << " : " << endl ;

    cout << "\t" 
	 << CurrentSampleType << "," << CurrentSampleSName << "," << CurrentIsData << endl;

    cout << "\t\t" ;
    for(int i=0 ; i<NumberOfHistos ; i++){
      TString hName = histoNames[i];
      TH1* theH1 = allHistos.find( histoNames[i] )->second;
      cout << hName << ":"<< theH1->Integral() << " -- " ;
    }

    cout << endl;
  }else if( option == "cutflowtable" ){
    cout << endl << "||" ;
    for( int i=0 ; i<NumberOfHistos ; i++)
      cout << histoNames[i] << "|" ;
    cout << endl;

    for( int cut=1; cut<nBins+1 ; cut++){
      //cout << cut << endl;
      //allHistos.begin()->second->Print("ALL");
      cout << "|" << allHistos.begin()->second->GetXaxis()->GetBinLabel( cut ) << "|";
      for( int i=0 ; i<NumberOfHistos ; i++)
	cout <<std::setprecision(2)<< allHistos.find(histoNames[i])->second->GetBinContent(cut) << "+-" << allHistos.find(histoNames[i])->second->GetBinError(cut) << "|" ;
      cout << endl;      
    }
  }
}

ExtendedObjectProperty::ExtendedObjectProperty( TString cutname , TString name, TString formula , int nbins, double min, double max ,TString SUSYCatCommand_ , std::vector<TString> SUSYNames_,  std::vector<TString>* labels , TString _SampleNameForSyst , const std::vector<TString>& _SystNames ):
  CutName( cutname ),
  Name(name),
  Formula(formula),
  nBins(nbins),
  Min(min),
  Max(max),
  isString(false),
  tFormula(0),
  tSUSYCatFormula(0),
  SUSYNames( SUSYNames_ ),
  SUSYCatCommand( SUSYCatCommand_ ),
  SampleNameForSyst( _SampleNameForSyst ), nISOQCD(0), Labels(labels)
{

  gROOT->cd();

  TH1::SetDefaultSumw2();
   

  vector<TString>  cnames = {"QCD1", "VJets", "Top", "TChannel", "MC", "SUSY" , "data" };
  vector<int>      ccolor = {kGray, kGreen-2,kOrange-3, kRed, 500, 1, kBlack};
  //vector<TString>  cnames = {"tChannel",  "ttbar",      "tW" ,      "sChannel" ,    "WJets",   "DY",   "QCD",  "MC", "SUSY" , "data" };
  //vector<int>      ccolor = {   kRed   ,  kOrange+1, kOrange ,  kYellow  ,  kGreen+2 ,  kBlue+3,  kGray ,   500,      1 , kBlack };

  // vector<TString>  cnames = {"tChannel", "tbarChannel" , "ttbar", "tW" , "tbarW" , "sChannel" , "tbarS" , "WJets","DY","QCD",  "MC", "SUSY" , "data" };
  // vector<int>      ccolor = {  kRed, kRed,  kOrange, kOrange+1 , kOrange-1 ,kOrange-1 , kGreen+2 , kGreen+2 , kBlue, kGray , 500, 1 , kBlack };

  // vector<TString>  cnames = {"tChannel", "Wtolnu","QCD", "DY", "Top", "MC", "SUSY" , "data" };
  // vector<int>      ccolor = {  kRed,     417 , kGreen-7 , 419,   kOrange,  500, 1 , 632 };


  //vector<TString>  cnames = {"BCtoE", "EMEnriched" , "MuEnriched" , "GJets" , "VV" , "Wtolnu", "DY", "Top" ,"TTV" , "STop" , "MC", "SUSY" , "data" };
  //vector<int>      ccolor = {  kYellow, kYellow+3 , kYellow-9 , kYellow-6 , kGreen-7 ,  kGreen+3,   kOrange-3 , kBlue  ,kBlue-7  , kCyan-2,  500, kBlack , kRed };

  NumberOfHistos = (cnames.size() +SUSYNames_.size()) ;

  for( int i=0 ; i< int(SUSYNames.size()) ; i++){
    cnames.push_back( "SUSY_" + SUSYNames[i] );
    ccolor.push_back( 1 );
  }

  TString varname = Name;
  for (int i=0; i<NumberOfHistos ; i++){

    histoNames.push_back( cnames[i] );

    //cout << CutName + "_" + varname+"_"+cnames[i] << nBins << "-" << "-" <<  Min << "-" << Max << endl ;
    TH1* theH = allHistos[ cnames[i] ] = new TH1D( CutName + "_" + varname+"_"+cnames[i], "", nBins, Min, Max);
    theH -> SetFillColor  (ccolor[i]);
    theH -> SetLineColor  (kBlack);
    theH -> SetLineWidth  (1);
    theH -> SetMarkerColor(ccolor[i]);
    theH -> SetStats(false);

    TH1* theHP = NULL;
    TH1* theHN = NULL;
    if( cnames[i] == "TChannel" || cnames[i] == "VJets" || cnames[i] == "tbarChannel" || cnames[i] == "tbarS" ){
      theHP = allSignedHistos[ cnames[i]+"P" ] = new TH1D( CutName + "_" + varname+"_"+cnames[i] + "_P" , "", nBins, Min, Max);
      theHN = allSignedHistos[ cnames[i]+"N" ] = new TH1D( CutName + "_" + varname+"_"+cnames[i] + "_N" , "", nBins, Min, Max);
    }

    if(labels){
      int i = 1;
      for(std::vector<TString>::const_iterator itr = labels->begin() ; itr != labels->end() && i < nBins+1 ; itr++ , i++){
	theH->GetXaxis()->SetBinLabel( i , *itr);
	if(theHP)
	  theHP->GetXaxis()->SetBinLabel( i , *itr);
	if(theHN)
	  theHN->GetXaxis()->SetBinLabel( i , *itr);
      }
    }

    if(i == int(cnames.size()) -1){
      theH -> SetMarkerStyle(20);
      theH -> SetMarkerColor(kBlack);
      theH -> SetLineColor(kBlack);
    }
    if( i == int(cnames.size())-3){
      theH -> SetFillStyle(3004);
      theH -> SetFillColor(kBlack);
    }

    if( cnames[i] == SampleNameForSyst ){
      for( auto systName : _SystNames ){
	SystHistos[ systName ] = new TH1D( CutName + "_" + varname+"_"+cnames[i]+"_" + systName, "", nBins, Min, Max);
	SystHistos2D[ systName ] = new TH2D( CutName + "_" + varname+"_2d_"+cnames[i]+"_" + systName, "", nBins, Min, Max , 100 , -.5 , .5);
      }
      SystHistos2D[ SampleNameForSyst ] = new TH2D( CutName + "_" + varname+"_2d_"+cnames[i]+ "_Central" , "", nBins, Min, Max , 100 , -.5 , .5); 
    }
  }
}

  ExtendedObjectProperty::ExtendedObjectProperty( TString cutname , TString name, TString formula , int nbins, double* bins ,TString SUSYCatCommand_ , std::vector<TString> SUSYNames_,  std::vector<TString>* labels , TString _SampleNameForSyst ,const std::vector<TString>& _SystNames ):
  CutName( cutname ),
  Name(name),
  Formula(formula),
  nBins(nbins),
  Min(bins[0]),
  Max(bins[nbins]),
  isString(false),
  tFormula(0),
  tSUSYCatFormula(0),
  SUSYNames( SUSYNames_ ),
  SUSYCatCommand( SUSYCatCommand_ ),
  SampleNameForSyst(_SampleNameForSyst),
	      nISOQCD(0),Labels(labels){

  gROOT->cd();

  TH1::SetDefaultSumw2();
   
  vector<TString>  cnames = {"QCD1", "VJets", "Top", "TChannel", "MC", "SUSY" , "data" };
  vector<int>      ccolor = {kGray, kGreen-2,kOrange-3, kRed, 500, 1, kBlack};
  //vector<TString>  cnames = {"tChannel",  "ttbar",      "tW" ,      "sChannel" ,    "WJets",   "DY",   "QCD",  "MC", "SUSY" , "data" };
  //vector<int>      ccolor = {   kRed   ,  kOrange+1, kOrange ,  kYellow  ,  kGreen+2 ,  kBlue+3,  kGray ,   500,      1 , kBlack };

  // vector<TString>  cnames = {"tChannel", "tbarChannel" , "ttbar", "tW" , "tbarW" , "sChannel" , "tbarS" , "WJets","DY","QCD",  "MC", "SUSY" , "data" };
  // vector<int>      ccolor = {  kRed, kRed,  kOrange, kOrange+1 , kOrange-1 ,kOrange-1 , kGreen+2 , kGreen+2 , kBlue, kGray , 500, 1 , kBlack };

  //vector<TString>  cnames = {"BCtoE", "EMEnriched" , "MuEnriched" , "GJets" , "VV" , "Wtolnu", "DY", "Top" ,"TTV" , "STop" , "MC", "SUSY" , "data" };
  //vector<int>      ccolor = {  kYellow, kYellow+3 , kYellow-9 , kYellow-6 , kGreen-7 ,  kGreen+3,   kOrange-3 , kBlue  ,kBlue-7  , kCyan-2,  500, kBlack , kRed };

  NumberOfHistos = (cnames.size() +SUSYNames_.size()) ;

  for( int i=0 ; i< int(SUSYNames.size()) ; i++){
    cnames.push_back( "SUSY_" + SUSYNames[i] );
    ccolor.push_back( 1 );
  }

  TString varname = Name;
  for (int i=0; i<NumberOfHistos ; i++){

    histoNames.push_back( cnames[i] );

    TH1* theH = allHistos[ cnames[i] ] = new TH1D( CutName + "_" + varname+"_"+cnames[i], "", nBins, bins );
    theH -> SetFillColor  (ccolor[i]);
    theH -> SetLineColor  (kBlack);
    theH -> SetLineWidth  (1);
    theH -> SetMarkerColor(ccolor[i]);
    theH -> SetStats(false);

    TH1* theHP = NULL;
    TH1* theHN = NULL;
    if( cnames[i] == "TChannel" || cnames[i] == "VJets" || cnames[i] == "tbarChannel" || cnames[i] == "tbarS" ){
      cout << cnames[i] << endl;
      theHP = allSignedHistos[ cnames[i]+"P" ] = new TH1D( CutName + "_" + varname+"_"+cnames[i] + "_P" , "", nBins, Min, Max);
      theHN = allSignedHistos[ cnames[i]+"N" ] = new TH1D( CutName + "_" + varname+"_"+cnames[i] + "_N" , "", nBins, Min, Max);
    }

    if(labels){
      int i = 1;
      for(std::vector<TString>::const_iterator itr = labels->begin() ; itr != labels->end() && i < nBins+1 ; itr++ , i++){
	theH->GetXaxis()->SetBinLabel( i , *itr);
	if(theHP)
	  theHP->GetXaxis()->SetBinLabel( i , *itr);
	if(theHN)
	  theHN->GetXaxis()->SetBinLabel( i , *itr);
      }
    }

    if(i == int(cnames.size()) -1){
      theH -> SetMarkerStyle(20);
      theH -> SetMarkerColor(kBlack);
      theH -> SetLineColor(kBlack);
    }
    if( i == int(cnames.size())-3){
      theH -> SetFillStyle(3004);
      theH -> SetFillColor(kBlack);
    }

    if( cnames[i] == SampleNameForSyst ){
      for( auto systName : _SystNames ){
	SystHistos[ systName ] = new TH1D( CutName + "_" + varname+"_"+cnames[i]+"_"+ systName, "", nBins, bins);
	SystHistos2D[ systName ] = new TH2D( CutName + "_" + varname+"_2d_"+cnames[i]+"_"+ systName, "", nBins, bins , 100 , -.5 , 5);
      }
      SystHistos2D[ SampleNameForSyst ] = new TH2D( CutName + "_" + varname+"_2d_"+cnames[i]+ "_Central" , "", nBins, Min, Max , 100 , -.5 , .5); 
    }
  }
}

void ExtendedObjectProperty::ScaleData( TEfficiency* eff ){
  TH1* hdata = allHistos["data"];
  
  TH1* hEff =(TH1*)( hdata->Clone("hEff") );
  hEff->Reset("ICESM");

  for(int i=1 ; i < nBins + 1 ; i++ ){
    hEff->SetBinContent( i,  eff->GetEfficiency( i ) ) ;
    hEff->SetBinError( i , ( eff->GetEfficiencyErrorLow(i)+eff->GetEfficiencyErrorUp(i) )/2.0 );
  }

  hdata->Multiply( hEff );

  if( "data" == SampleNameForSyst )
    for( auto syst : SystHistos )
      syst.second->Multiply( hEff );

  delete hEff;
}

void ExtendedObjectProperty::SetTree( TTree* tree , TString sampletype, TString samplesname , TString cutname ){
  if( strcmp( cutname , "" ) != 0 )
    CutName = cutname;

  if(tFormula != 0)
    delete tFormula;

  if(tSUSYCatFormula != 0){
    delete tSUSYCatFormula;
    tSUSYCatFormula = 0;
  }

  tFormula = new TTreeFormula( Name.Data() , Formula.Data() , tree );
  isString = tFormula->IsString() ;

  theH = 0;
  CurrentIsData =( sampletype == "data" ) ;
  CurrentSampleType = sampletype;
  CurrentSampleSName = samplesname;

  theH_N = 0;
  theH_P = 0;
  //cout <<  << endl;
  if( CurrentSampleSName == "TChannel" || CurrentSampleSName == "VJets" ) { //|| cnames[i] == "tbarChannel" || cnames[i] == "tbarS" ){
    theH_P = allSignedHistos[ CurrentSampleSName +"P" ] ;
    theH_N = allSignedHistos[ CurrentSampleSName +"N" ] ;
  }

  //cout << CurrentSampleSName << " " << theH_N << "  " << theH_P << endl;

  
  if(CurrentIsData)
    theH = allHistos["data"];
  else if(CurrentSampleType == "susy"){
    theH = NULL;
    tSUSYCatFormula = new TTreeFormula( ( Name + "_SUSY" ).Data() , SUSYCatCommand.Data() , tree );
  }
  else
    theH = allHistos[ CurrentSampleSName ];

  if( CurrentSampleType == "mc" )
    theMCH = allHistos["MC"];
  else
    theMCH = 0;
}

void ExtendedObjectProperty::Fill(double w){
  if(isString){
    sVal = tFormula->EvalStringInstance(0);
  }
  else
    dVal = tFormula->EvalInstance(0);

  if( theH ){
    if(isString){
      theH->Fill( sVal , w);
      if( theH_N && w < 0.0 )
	theH_N->Fill( sVal , w);
      if( theH_P && w > 0.0 )
	theH_P->Fill( sVal , w);
    }
    else{
      theH->Fill( dVal , w);
      if( theH_N && w < 0.0 )
	theH_N->Fill( dVal , w);
      if( theH_P && w > 0.0 )
	theH_P->Fill( dVal , w);
    }
  }
  else if(tSUSYCatFormula){
    isString ? allHistos["SUSY"]->Fill(  sVal , w ) : allHistos["SUSY"]->Fill(  dVal , w );
    double suscatd = tSUSYCatFormula->EvalInstance(0) ;
    int suscat = int(suscatd);
    if( suscat < int(SUSYNames.size()) ){
      TString suscatname = SUSYNames[suscat];
      TString sushistname = "SUSY_" + suscatname ;
      isString ? allHistos[ sushistname ]->Fill( sVal , w ) : allHistos[ sushistname ]->Fill( dVal , w );
    }
  }

  if( theMCH )
    isString ? theMCH->Fill(sVal , w) : theMCH->Fill(dVal , w);
}

 void ExtendedObjectProperty::Fill(double dVal , double w , std::map<TString,double> WSyst ){
   this->Fill( dVal , w , false);

  if( WSyst.size() > 0 )
    SystHistos2D[ SampleNameForSyst ]->Fill( dVal , w );

  for(auto ws : WSyst){
    SystHistos[ ws.first ]->Fill( dVal , ws.second ); 
    SystHistos2D[ ws.first ]->Fill( dVal , ws.second ); 
  }
}

void ExtendedObjectProperty::Fill(double dVal , double w , bool isPSeudoData , bool iso ){
  if( CurrentSampleSName == "QCD" ){
    if( iso ){
      nISOQCD += w ;
      w = 0.0;
    }else
      w = 1.0;
    isPSeudoData = false;
  }

  //if( CurrentIsData ){
  isPSeudoData = false;
  //   w = 1.0;
  // }

  if( theH ){
    if(Labels){
      TString value = (*Labels)[ int(dVal-0.5) ];
      theH->Fill( value , w );

      // if( w < 0.0 )
      // 	cout << theH_N << " " << CurrentSampleSName << endl;
      if( theH_N && w < 0.0 ){
	theH_N->Fill( value , w);
	//cout << value << endl;
      }
      if( theH_P && w > 0.0 )
	theH_P->Fill( value , w);

      if(isPSeudoData)
	allHistos["data"]->Fill( value , fabs(w) < 1.0 ? w/fabs(w) : w  );
    }else{
      theH->Fill( dVal , w);

      if( theH_N && w < 0.0 ){
	theH_N->Fill( dVal , w);
      }
      if( theH_P && w > 0.0 )
	theH_P->Fill( dVal , w);

      if(isPSeudoData)
	allHistos["data"]->Fill( dVal ,  fabs(w) < 1.0 ? w/fabs(w) : w  );
    }
  }else if(tSUSYCatFormula){
    allHistos["SUSY"]->Fill( dVal , w );
    int suscat =int(tSUSYCatFormula->EvalInstance(0)) ;
    if( suscat < int(SUSYNames.size()) ){
      TString suscatname = SUSYNames[suscat];
      TString sushistname = "SUSY_" + suscatname ;
      allHistos[ sushistname ]->Fill( dVal , w );
    }
  }

  if( theMCH && CurrentSampleSName != "QCD" )
    theMCH->Fill(dVal , w);
}



void ExtendedObjectProperty::AddOverAndUnderFlow(TH1 * Histo, bool overflow, bool underflow){
  if(underflow){
    Histo->SetBinContent(1, Histo->GetBinContent(0) + Histo->GetBinContent(1));
    Histo->SetBinError(1, sqrt(Histo->GetBinError(0)*Histo->GetBinError(0)+
			       Histo->GetBinError(1)*Histo->GetBinError(1) ));
    Histo->SetBinContent(0, 0.0);
  } if(overflow){
    Histo->SetBinContent(Histo->GetNbinsX(),
			 Histo->GetBinContent(Histo->GetNbinsX()  )+ 
			 Histo->GetBinContent(Histo->GetNbinsX()+1) );
    Histo->SetBinError(Histo->GetNbinsX(),
		       sqrt(Histo->GetBinError(Histo->GetNbinsX()  )*
			    Histo->GetBinError(Histo->GetNbinsX()  )+
			    Histo->GetBinError(Histo->GetNbinsX()+1)*
			    Histo->GetBinError(Histo->GetNbinsX()+1)  ));
    Histo->SetBinContent(Histo->GetNbinsX() + 1, 0.0);
  }
}


TCanvas* ExtendedObjectProperty::plotRatioStack(THStack* hstack, TH1* h1_orig, TH1* h2_orig, vector<pair<TH1*,Color_t> > h3s, bool logflag, bool normalize, TString name, TLegend* leg, TString xtitle, TString ytitle,int njets,int nbjets, int nleps, float overlayScale, TString saveMacro , int lumi_ ){
  //LEO TRUE USE THIS

  // define canvas and pads 
  TH1D *h1 = (TH1D*)h1_orig->Clone("h1_copy");
  TH1D *h2 = (TH1D*)h2_orig->Clone("h2_copy");

  h1->SetStats(0);	
  h2->SetStats(0);	
  h1->SetMarkerStyle(20);
  h2->SetMarkerStyle(20);

	
  //TCanvas* c1 = new TCanvas(name,"", 20,100,1000,700);
  //TCanvas* c1 = new TCanvas(name+"c_ratio"+ "_" + Name + "_" + CutName,"",0,0,600,600 /*37, 60,636,670*/);
  //c1->SetFrameLineWidth(1);
  
  // Dimensions and margines for canvas
  TCanvas* c1 = new TCanvas(name+"c_ratio"+ "_" + Name + "_" + CutName,"",632,112,500,502);
  c1->SetHighLightColor(2);
  c1->Range(0,0,1,1);
  c1->SetFillColor(0);
  c1->SetBorderMode(0);
  c1->SetBorderSize(2);
  c1->SetLogy();
  c1->SetTickx(1);
  c1->SetTicky(1);
  c1->SetLeftMargin(0.16);
  c1->SetRightMargin(0.02);
  c1->SetTopMargin(0.05);
  c1->SetBottomMargin(0.13);
  c1->SetFrameFillStyle(0);
  c1->SetFrameBorderMode(0);
  c1 -> cd();
	
  float border = 0.2;
  float scale = (1-border)/border;
  if(border == scale)
    cout << "just to avoid warning message" << endl;

  //TPad *p_plot  = new TPad(name+"_plotpad"+ "_" + Name + "_" + CutName,  "Pad containing the overlay plot", 0,0.211838,1,1 /*0.00, border, 1.00, 1.00, 0, 0*/);
  //p_plot->SetBottomMargin(0.05);
  //p_plot->SetTopMargin(0.09);
  //p_plot->SetLeftMargin(0.1669107);
  //p_plot->SetRightMargin(0.02);
  //p_plot->SetLeftMargin(0.131579);
  //p_plot->SetRightMargin(0.08);
  //p_plot->SetTopMargin(0.06895515);
  //p_plot->SetBottomMargin(0.07206074);
  //p_plot->Draw();

// Dimensions and margines for main pad
  TPad *p_plot  = new TPad(name+"_plotpad"+ "_" + Name + "_" + CutName,  "Pad containing the overlay plot", 0,0.15,1,1);
  //p_plot->cd();
   p_plot->Range(-0.9756097,-809.2457,5.121951,5415.875);
   p_plot->SetFillColor(0);
   p_plot->SetBorderMode(0);
   p_plot->SetBorderSize(2);
   p_plot->SetTickx(1);
   p_plot->SetTicky(1);
   p_plot->SetLeftMargin(0.16);
   p_plot->SetRightMargin(0.02);
   p_plot->SetTopMargin(0.055);
   p_plot->SetBottomMargin(0.13);
   p_plot->SetFrameFillStyle(0);
   p_plot->SetFrameBorderMode(0);
   p_plot->SetFrameFillStyle(0);
   p_plot->SetFrameBorderMode(0);
   p_plot->Draw();

  //TPad *p_ratio = new TPad(name+"_ratiopad"+ "_" + Name + "_" + CutName, "Pad containing the ratio",   0,0.01863354,0.9967105,0.2189441/*     0.00, 0.05, 1.00, border, 0, 0*/);
  //p_ratio->SetTopMargin(0.03);
  //p_ratio->SetBottomMargin(0.05/*5*/);
  //p_ratio->SetRightMargin(0.02);
  //p_ratio->SetLeftMargin(0.1336634);	
  //p_ratio->SetRightMargin(0.075);
  //p_ratio->SetTopMargin(0.06976745);
  //p_ratio->SetBottomMargin(0.2790698);

  //p_ratio->Draw();
// Dimensions and margines for ratio pad
  TPad *p_ratio = new TPad(name+"_ratiopad"+ "_" + Name + "_" + CutName, "Pad containing the ratio",0,0,1,0.15);
  //p_ratio->cd();
   p_ratio->Range(-0.9756097,-0.3170732,5.121951,2.121951);
   p_ratio->SetFillColor(0);
   p_ratio->SetBorderMode(0);
   p_ratio->SetBorderSize(2);
   p_ratio->SetGridy();
   p_ratio->SetTickx(1);
   p_ratio->SetTicky(1);
   p_ratio->SetLeftMargin(0.16);
   p_ratio->SetRightMargin(0.02);
   p_ratio->SetTopMargin(0.05);
   p_ratio->SetBottomMargin(0.13);
   p_ratio->SetFrameFillStyle(0);
   p_ratio->SetFrameBorderMode(0);
   p_ratio->SetFrameFillStyle(0);
   p_ratio->SetFrameBorderMode(0);
   p_ratio->Draw();
 
  // draw overlay plot
  p_plot ->cd();

  if(logflag) gPad->SetLogy(1);
  gPad->SetFillStyle(0);
		
  // Scaling
  if(normalize){
    h1->Scale(1.0/h1->Integral());
    h2->Scale(1.0/h2->Integral());
  }
	
  // Determine plotting range
  double max1 = h1->GetMaximum();
  double max2 = h2->GetMaximum();
  double max  = (max1>max2)?max1:max2;
  if(logflag) max = 2.5*max;
  else max = 1.5*max;
  h1->SetMaximum(max);
  h2->SetMaximum(max);
  hstack->SetMaximum(max);
  //	h1->SetMinimum(0.000000001);
  //	h2->SetMinimum(0.000000001);
  stringstream yTitle;
  /*if(fEventsPerGeV){
    if(fabs(h1_orig->GetBinWidth(1) -h1_orig->GetBinWidth(h1_orig->GetNbinsX()-1))<0.01){
    double binwidth = h1_orig->GetBinWidth(1);
    yTitle.precision(3);
    yTitle << ytitle.Data();
    yTitle << " / ";
    yTitle << binwidth;
    yTitle << " GeV";
    } else{
    cout << h1_orig->GetBinWidth(1) << " " << h1_orig->GetBinWidth(h1_orig->GetNbinsX()-1) << endl;
    }
    }else{*/
  yTitle << ytitle.Data();
  //}
  hstack->Draw();
  //hstack->Print("all");

// Fonts and offset for the stacked histogram
	
  //MT2_bSel[0]->SetTitleSize(0.03);
  ///MT2_bSel[0]->SetTitleOffset(1.);
  hstack->SetMinimum(0.02);
  // if( CutName != "PreSelection" )
  //   hstack->GetXaxis()->SetTitle(xtitle);
  hstack->Draw("hist");

  // cout << hstack->GetXaxis()->GetTitle() << endl;
  //  hstack->GetXaxis()->SetTitle(xtitle);
  //  hstack->GetXaxis()->SetLabelFont(42);
  //  hstack->GetXaxis()->SetLabelOffset(0.007);
  //  hstack->GetXaxis()->SetLabelSize(0.045);
  //  hstack->GetXaxis()->SetTitleSize(0.06);
  //  hstack->GetXaxis()->SetTitleOffset(0.95);
  //  hstack->GetXaxis()->SetTitleFont(42);
  //  //hstack->GetYaxis()->SetTitle("Events / X");
  //  hstack->GetYaxis()->SetTitle(yTitle.str().c_str());
  //  hstack->GetYaxis()->SetLabelFont(42);
  //  hstack->GetYaxis()->SetLabelSize(0.045);
  //  hstack->GetYaxis()->SetTitleSize(0.06);
  //  hstack->GetYaxis()->SetTitleOffset(1.45);
  //  hstack->GetYaxis()->SetTitleFont(42);


  h2->SetMarkerColor(1);
  h2    ->Draw("sameE");

  for(auto h3c : h3s ){
    TH1* h3 = h3c.first;
    Color_t color = h3c.second;

    h3->Scale(overlayScale ? overlayScale : h2->Integral() / h3->Integral());
    h3->SetFillColor(0);
    h3->SetFillStyle(0);
    h3->SetLineStyle(1);
    h3->SetLineWidth(4);
    h3->SetLineColor(color);
    h3->Draw("samehist");
  }

  TLatex TitleBox;
  TitleBox.SetNDC();
  TitleBox.SetTextSize(0.03);

  TString text;
  if (njets>=10)
    text = TString::Format("%d-%d jets",njets/10,njets%10);
  else if(njets == -10)
    text += "";
  else
    text = njets < 0 ? TString::Format("#geq %d jets",abs(njets)) : TString::Format("%d jets",abs(njets));
  text += nbjets==-10 ? "" : nbjets < 0 ? TString::Format(", #geq %d b-tag",abs(nbjets)) : TString::Format(", %d b-tag",abs(nbjets));
  text += nleps == 1 ? ", 1 lepton" : "";


  // 	TString text ="";
  // 	text = fMT2Analysis?  "M_{T2} Analysis                                          ":"";
  // 	text +=fMT2bAnalysis? "M_{T2}b Analysis                                         ":"";
  // 	TString lumi = TString::Format("%1.2f",lumi_/1000.);
  // 	text +="CMS Preliminary, #sqrt{s} = 8 TeV, L = "+lumi+" fb^{-1}";
  TitleBox.DrawLatex(0.13,0.943,text.Data());
  TLatex LumiBox;
  LumiBox.SetNDC();
  LumiBox.SetTextSize(0.0305);
  TString lumi = TString::Format("%1.2f",lumi_/1000.);
  //LumiBox.DrawLatex(0.68,0.943,"#sqrt{s} = 13 TeV, L = "+lumi+" fb^{-1}");//standard
  //LumiBox.DrawLatex(0.49,0.943,"CMS Preliminary, #sqrt{s} = 8 TeV, L = "+lumi+" fb^{-1}");//for CMS Preliminary
  //LumiBox.DrawLatex(0.62,0.943,"CMS, #sqrt{s} = 8 TeV, L = "+lumi+" fb^{-1}");//for CMS

  p_plot ->Draw();
  gPad->RedrawAxis();


   TLatex *   tex = new TLatex(0.955,0.955,"41.0 pb^{-1} (13 TeV)");
   tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextFont(42);
   tex->SetTextSize(0.048);
   tex->SetLineWidth(2);
   tex->Draw();
   tex = new TLatex(0.8684108,4612.434,"CMS");
   tex->SetTextAlign(31);
   tex->SetTextSize(0.05956813);
   tex->SetLineWidth(2);
   tex->Draw();
   tex = new TLatex(1.421617,4179.812,"Preliminary");
   tex->SetTextAlign(31);
   tex->SetTextFont(52);
   tex->SetTextSize(0.048);
   tex->SetLineWidth(2);
   tex->Draw();


  //if(leg != NULL ){
   leg = new TLegend(0.6129032,0.5035989,0.7983871,0.9156118,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.0446761);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   
   TLegendEntry * entry=leg->AddEntry("NULL","Data","pl");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#it{t}-channel","f");

   entry->SetFillColor(kRed);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","t#bar{t}, tW, #it{s}-channel","f");

   entry->SetFillColor(kOrange - 3);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","W/Z+jets, dibosons","f");

   entry->SetFillColor(kGreen -2);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","QCD","f");

   entry->SetFillColor(kGray);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);

   leg->Draw();
  //} 
	
  // draw the ratio plot
  p_ratio ->cd();
  //gPad->SetLogy();
 
  TH1D *h_ratio = (TH1D*)h2_orig->Clone("h2_copy");	
  h_ratio ->SetStats(0);
  h_ratio ->SetMarkerStyle(20);

  h_ratio ->Divide(h2, h1);
  h_ratio ->SetMinimum(0.4);
  h_ratio ->SetMaximum(3.0);
  h_ratio ->GetYaxis()->SetTitleOffset(h1->GetYaxis()->GetTitleOffset());

  //MC with errors
  TH1D*h_ratio_mc = (TH1D*)h1_orig->Clone("h1_copy");
  h_ratio_mc->Divide(h1);
  h_ratio_mc->GetYaxis()->SetRangeUser(0,2);
// Fonts and offset for the ratio
   h_ratio_mc->GetXaxis()->SetLabelFont(42);
   h_ratio_mc->GetXaxis()->SetLabelSize(0);
   h_ratio_mc->GetXaxis()->SetTitleSize(0.035);
   h_ratio_mc->GetXaxis()->SetTitleFont(42);
   h_ratio_mc->GetYaxis()->SetTitle("Data / MC");
   h_ratio_mc->GetYaxis()->CenterTitle(true);
   h_ratio_mc->GetYaxis()->SetNdivisions(504);
   h_ratio_mc->GetYaxis()->SetLabelFont(42);
   h_ratio_mc->GetYaxis()->SetLabelOffset(0.007);
   h_ratio_mc->GetYaxis()->SetLabelSize(0.17);
   h_ratio_mc->GetYaxis()->SetTitleSize(0.24);
   h_ratio_mc->GetYaxis()->SetTitleOffset(0.35);
   h_ratio_mc->GetYaxis()->SetTitleFont(42);


  //h_ratio_mc->SetFillStyle(3001);
  //h_ratio_mc->SetFillColor(1);
  h_ratio_mc->Draw("E2");
  
  h_ratio->SetMarkerColor(1);
  h_ratio->SetLineColor(1);
  h_ratio ->DrawCopy("Esame");//LEO MOD
 
  TLine *l3 = new TLine(h1->GetXaxis()->GetXmin(), 1.00, h1->GetXaxis()->GetXmax(), 1.00);
  l3->SetLineWidth(2);
  l3->SetLineStyle(7);
  l3->Draw();
	
  gPad->RedrawAxis();
  p_ratio ->Draw();
  c1->Update();

  TString save=name+"_ratio";
  if(saveMacro != "")	
    c1->SaveAs(save + "." + saveMacro);
  p_plot->cd();

  return c1;
}

#include <algorithm>
void ExtendedObjectProperty::Write( TDirectory* dir , int lumi ,bool plotratiostack ,  bool logy){
  TDirectory* newdir = dir->mkdir(  Name  );
  newdir->cd();

  THStack* h_stack     = new THStack( CutName + "_" + Name, "");
  TLegend* Legend1 = new TLegend(.71,.54,.91,.92);

  vector< pair<TH1*, Color_t> > susycolors;

  for( auto h : allSignedHistos )
    h.second->Write();

  for(uint j = 0; j < (NumberOfHistos-SUSYNames.size()); j++){
    theH = allHistos[ histoNames[j] ];
    AddOverAndUnderFlow(theH, true, true);

    if( histoNames[j] == "QCD" ){
      theH->Scale( nISOQCD / theH->Integral() );

      allHistos["MC"]->Add( theH );

      TH1* hnewqcd = (TH1*) (theH->Clone("hPDQCD"));
      for(int iii = 1 ; iii <= hnewqcd->GetNbinsX() ; iii++){
	double val = hnewqcd->GetBinContent(iii);
	int newval = gRandom->Poisson( val );
	hnewqcd->SetBinContent( iii , newval );
	hnewqcd->SetBinError( iii , sqrt(newval) );
      }
      allHistos["data"]->Add( hnewqcd );
    }

    if(j < (NumberOfHistos -SUSYNames.size()- 3)){
      h_stack  -> Add(theH);
      Legend1->AddEntry(theH, histoNames[j] , "f");
    }else if( j == NumberOfHistos-SUSYNames.size()-1 ){
      Legend1->AddEntry(theH, "data", "pl");
    }

    theH->Write();
  }
  int color = 1;
  for(auto name : SUSYNames){
    TH1* h3 = allHistos["SUSY_"+name ];
    h3->Write();

    susycolors.push_back( make_pair( h3 , color ) );

    h3->SetFillColor(0);
    h3->SetFillStyle(0);
    h3->SetLineStyle(1);
    h3->SetLineWidth(4);
    h3->SetLineColor(color);

    Legend1->AddEntry( h3 , name , "l" );
    color++;
  }

  h_stack->Write();
  Legend1->Write();

  newdir->cd();

  if(plotratiostack){
    //plotRatioStack(h_stack, allHistos["MC"] , allHistos["data"], allHistos["SUSY"] , logy, false, Name + "_ratio", Legend1, Name, "Events", -10, -10, 2, true , "" , lumi)->Write();    
    //for(uint i =0 ; i<SUSYNames.size() ; i++){
    TCanvas* ccc = plotRatioStack(h_stack, allHistos["MC"] , allHistos["data"], susycolors , false, false, Name + "_ratio"+ "_AllSUSY", Legend1, Name, "Events", -10, -10, 2, true , "" , lumi ) ; // , allHistos["SUSY_" + SUSYNames[1]] );
    //if(Name == "One")
    //cout << CutName << "--" << allHistos["SUSY_"+SUSYNames[0] ]->GetEntries() << endl;

    //ccc->cd(0);
    //allHistos["SUSY_" + SUSYNames[1]]->Draw("SAME");
    ccc->Write();
    //gSystem->mkdir( CutName );
    //ccc->SetName( Name );
    
    //ccc->SaveAs(CutName + "/" + Name + ".C" );
    //ccc->SaveAs(CutName + "/" + Name + ".png" );
    //}
  }
  for( std::vector< TGraph* >::const_iterator itr = AllSignificances.begin() ; itr != AllSignificances.end() ; itr++)
    (*itr)->Write();

  if( allHistos[ SampleNameForSyst ] != NULL ){
    TDirectory* systdir = newdir->mkdir("Systematics");
    systdir->cd();
    TH1* theH = allHistos[ SampleNameForSyst ];
    for(auto ws : SystHistos){
      SystHistos[ ws.first ]->Add( theH , -1 ); 
      SystHistos[ ws.first ]->Multiply( SystHistos[ ws.first ] );
      for(int binii = 1 ; binii <= theH->GetNbinsX()  ; binii ++ ){
	SystHistos[ ws.first ]->SetBinContent( binii , sqrt( SystHistos[ ws.first ]->GetBinContent(binii) )/theH->GetBinContent(binii) );
	SystHistos[ ws.first ]->SetBinError( binii , 0.0001 );
      }
      SystHistos2D[ ws.first ]->Write();
      SystHistos[ ws.first ]->Write();
    } 
    SystHistos2D[ SampleNameForSyst ]->Write();
  }
}

void ExtendedCut::SaveTree(){
  StoreTree = true;

  theTreeToSave = new TTree( Name , Name);

  TIter nextprop( &Props );
  TObject* objtemp;
  while( (objtemp = nextprop()) ){
    ExtendedObjectProperty* castedobj = (ExtendedObjectProperty*)objtemp ;
    theTreeToSave->Branch( castedobj->Name , &(castedobj->dVal) , castedobj->Name + "/D" ) ;
  }  
  theTreeToSave->Branch( "XSec" , &(this->XSec) , "XSec/D" );
  theTreeToSave->Branch( "NInitialEvents" , &(this->NInitialEvents) , "NInitialEvents/I" );
  theTreeToSave->Branch( "KFactor" , &(this->KFactor) , "KFactor/D" );
  theTreeToSave->Branch( "AvgPuW" , &(this->AvgPuW) , "AvgPuW/D" );  

  theTreeToSave->Branch( "W" , &(this->CurrentWeightVal) , "W/D" );
  theTreeToSave->Branch( "isData" , &(this->isData) , "isData/O" );
  theTreeToSave->Branch( "isSUSY" , &(this->isSUSY) , "isSUSY/O" );
  theTreeToSave->Branch( "isMC" , &(this->isMC) , "isMC/O" );

  theTreeToSave->Branch( "SName" , &(this->CurrentSampleSNameS) );
  theTreeToSave->Branch( "SType" , &(this->CurrentSampleTypeS)  );
}

void ExtendedCut::Print(Option_t* option) const{
  cout << Name << ","
       << CutStr << " : "
       << "D:" << OnData << "(" << DataWeight << ")--"
       << "MC:" << OnMC << "(" << MCWeight << "- SUS:" << SUSYWeight << ")" << endl;
  
  TIter nextprop( &Props );
  TObject* objtemp;
  while( (objtemp = nextprop()) ){
    ((ExtendedObjectProperty*)objtemp)->Print();
  }

  TIter nexteventlist( &Events );
  cout << "Available Event Lists :" << endl;
  while( (objtemp = nexteventlist()) ){
    cout << "\t" << objtemp->GetName() << endl;
  }


}


ExtendedCut::ExtendedCut(TString name, TString cutstr , bool applyondata , bool applyonmc , TString dataweight , TString mcweight , bool susyw, bool applyonsusy , int verbose) :
    Name(name),
    CutStr(cutstr),
    fCut(0),
    OnSusy(applyonsusy),
    OnData(applyondata),
    OnMC(applyonmc),
    DataWeight(dataweight),
    fDW(0),
    MCWeight(mcweight),
    fMCW(0),
    SUSYWeight(susyw),
    Verbose(verbose),
    StoreTree(false),
    CurrentSampleTypeS(new TClonesArray("TObjString") ),
    CurrentSampleSNameS(new TClonesArray("TObjString") ){

  if(Verbose>1)
    this->Print();
}

void ExtendedCut::SetTree( TTree* tree , TString samplename , TString samplesname , TString sampletype , double xsec , int ninitialevents , double kfactor , double avgpuw  ){
  XSec = xsec;
  NInitialEvents = ninitialevents;
  KFactor = kfactor ;
  AvgPuW = avgpuw ;

  isData = (sampletype=="data");
  isMC = (sampletype == "mc" );
  isSUSY = (sampletype == "susy") ;

    if(fCut != 0){
      delete fCut;
      fCut = 0;
    }
    if(fDW !=0){
      delete fDW;
      fDW = 0;
    }
    if(fMCW != 0){
      delete fMCW;
      fMCW = 0 ;
    }

    fCut = new TTreeFormula("fCut" + Name , CutStr , tree);

    CurrentWeight = 0;

    if(isData && DataWeight != "" ){
      fDW = new TTreeFormula("fDW" + Name , DataWeight , tree);
      CurrentWeight = fDW;
    }
    if( !isData ){
      if( isMC && MCWeight != "" ){
	fMCW = new TTreeFormula("fMCW" + Name , MCWeight , tree);
	CurrentWeight = fMCW;
      }else if(isSUSY && MCWeight != "" && SUSYWeight ){
	fMCW = new TTreeFormula("fSUSYW" +Name , MCWeight , tree);
	CurrentWeight = fMCW;
      }
    }

    TIter nextprop( &Props );
    TObject* objtemp;
    cout << Props.GetSize() << endl; 
    while( (objtemp = nextprop()) ){
      ((ExtendedObjectProperty*)objtemp)->SetTree( tree , sampletype , samplesname , Name );
      if( Verbose > 1 )
	((ExtendedObjectProperty*)objtemp)->Print() ;
    }

    CurrentList = 0;

    if( (isData && OnData) || (isMC && OnMC) || (isSUSY && OnSusy) ){
      TString ListName = Name + "_" + samplename ;
      TIter nexteventlist( &Events );
      while( (objtemp = nexteventlist()) ){
	if(objtemp->GetName() == ListName)
	  CurrentList = (TEventList*)objtemp;
      }


      if(CurrentList == 0){
	gROOT->cd();
	CurrentList = new TEventList( ListName );
	Events.Add( CurrentList );
      }
    }

    CurrentSampleType = sampletype;
    CurrentSampleSName = samplesname;

    new ( (*CurrentSampleTypeS)[0] ) TObjString( sampletype );
    new ( (*CurrentSampleSNameS)[0] ) TObjString( samplesname );

    if(isData)
      CurrentSampleSName = "data";

    if(Verbose > 1){
      this->Print();
      cout << "\t" << CurrentSampleSName << "---" << CurrentSampleType << "---" << samplename << endl;
      TString CWT = CurrentWeight ? CurrentWeight->GetExpFormula() : "NONE---LIST:" ;
      TString CLT = CurrentList ? CurrentList->GetName():"NONE" ;
      cout << "\t isData:" <<  isData << "--" << "isSUSY:" << isSUSY << "--" << "W:" << CWT << CLT << endl;
    }
  }

bool ExtendedCut::Pass(long currententryindex , double& weight ){
    bool pass = false;
    if( isData && !OnData )
      pass = true;
    else if( isMC && !OnMC)
      pass = true;
    else if ( isSUSY && !OnSusy)
      pass = true;
    else
      pass = ( fCut->EvalInstance(0) != 0.0 );
    if(pass){
      if(CurrentWeight)
	weight *= CurrentWeight->EvalInstance(0);

      CurrentWeightVal = weight;

      if(CurrentList)
	CurrentList->Enter( currententryindex );

      TIter nextprop( &Props );
      TObject* objtemp;
      while( (objtemp = nextprop()) ){
	((ExtendedObjectProperty*)objtemp)->Fill( weight );
      }
    }

    if( StoreTree && pass )
      theTreeToSave->Fill();

    return pass;
}


void ExtendedCut::Write(TDirectory* dirparent , int lumi , vector< pair<int,int>  > sig_types , int nSUSYSig){
  TDirectory * dir = dirparent->mkdir( Name );
  dir->cd();

  TIter nextprop( &Props );
  TObject* objtemp;
  while( (objtemp = nextprop()) ){

    for( vector< pair<int,int> >::const_iterator itr = sig_types.begin() ; itr != sig_types.end() ; itr++ ){
      for( int susy_sig = -1 ; susy_sig < nSUSYSig ; susy_sig++ )
	((ExtendedObjectProperty*)objtemp)->CalcSig( itr->first , itr->second , susy_sig );
    }
    ((ExtendedObjectProperty*)objtemp)->Write( dir , lumi );
  }

  dir->mkdir( "EventLists" )->cd();
  TIter nexteventlist( &Events );
  while( (objtemp = nexteventlist()) ){
    objtemp->Write();
  }
    
  dirparent->cd();
}



void sample::ReconstructSName(){
  std::map< TString , TString > name_snames;
  name_snames["BCtoE"] = "BCtoE";
  name_snames["EMEnriched"] = "EMEnriched";
  name_snames["MuEnriched"] = "MuEnriched";
  name_snames["GJets_HT"] = "GJets";
  name_snames["WWJets"] = "VV";
  name_snames["ZZJets"] = "VV";
  name_snames["WZJets"] = "VV";
  name_snames["TTGJets"] = "TTV";
  name_snames["TTH"] = "TTV";
  name_snames["TTW"] = "TTV";
  name_snames["TTZ"] = "TTV";
  name_snames["SingleTop"] = "STop";

  for(auto nn : name_snames ){
    if( name.Index( nn.first  ) != kNPOS )
      sname = nn.second ;
  }
}

void sample::Print(double Weight){
  std::cout << setfill('=') << std::setw(70) << "" << std::endl;
  cout << "looping over :     " <<endl;	
  cout << "   Name:           " << name << endl;
  cout << "   File:           " << file->GetName() << endl;
  cout << "   Events:         " << nevents  << endl;
  cout << "   Events in tree: " << tree->GetEntries() << endl; 
  cout << "   Xsection:       " << xsection << endl;
  cout << "   kfactor:        " << kfact << endl;
  cout << "   avg PU weight:  " << PU_avg_weight << endl;
  cout << "   Weight:         " << Weight <<endl;
  std::cout << setfill('-') << std::setw(70) << "" << std::endl;

}



ExtendedEfficiency::ExtendedEfficiency(TString cutname , TString name, TString valueformula , TString nformula ,TString precond, TString condition , int nbins, double* bins ) : ExtendedObjectProperty::ExtendedObjectProperty(cutname, name , valueformula , nbins , 0.0 , 0.0 , "0" , {"A"} ){
//   ExtendedObjectProperty::CutName( cutname ),
//   ExtendedObjectProperty::Name(name),
//   ExtendedObjectProperty::Formula(valueformula),
//   ExtendedObjectProperty::nBins(nbins),
//   ExtendedObjectProperty::Min(-1),
//   ExtendedObjectProperty::Max(-1),
//   ExtendedObjectProperty::tFormula(0),
//   tCondFormula(0),
//   tNFormula(0),
//   ExtendedObjectProperty::tSUSYCatFormula(0),
//   NFormula(nformula),
//   CondFormula(condition)
// {

  NFormula = nformula;
  PreCondFormula = precond ;
  CondFormula = condition;
  Bins = bins;

  gROOT->cd();
  NumberOfHistos = 7;

  TH1::SetDefaultSumw2();

  //vector<TString>  cnames = {"tChannel",  "ttbar",      "tW" ,      "sChannel" ,    "WJets",   "DY",   "QCD",  "MC", "SUSY" , "data" };
  //vector<int>      ccolor = {   kRed   ,  kOrange+1, kOrange ,  kYellow  ,  kGreen+2 ,  kBlue+3,  kGray ,   500,      1 , kBlack };

  vector<TString>  cnames = {"QCD", "VJets", "Top", "TChannel", "MC", "SUSY" , "data" };
  vector<int>      ccolor = {kGray, kGreen-2,kOrange-3, kRed, 500, 1, kBlack};

  // vector<TString>  cnames = {"tChannel", "tbarChannel" , "ttbar", "tW" , "tbarW" , "sChannel" , "tbarS" , "WJets","DY","QCD",  "MC", "SUSY" , "data" };
  // vector<int>      ccolor = {  kRed, kRed,  kOrange, kOrange+1 , kOrange-1 ,kOrange-1 , kGreen+2 , kGreen+2 , kBlue, kGray , 500, 1 , kBlack };

  TString varname = Name;
  for (int i=0; i<NumberOfHistos ; i++){

    histoNames.push_back( cnames[i] );

    TEfficiency* theEff = allEffs[ cnames[i] ] = new TEfficiency( CutName + "_" + varname+"_"+cnames[i]+ "_eff" , "", nBins, bins) ;
    theEff -> SetFillColor  (ccolor[i]);
    theEff -> SetLineColor  (kBlack);
    theEff -> SetLineWidth  (2);
    theEff -> SetMarkerColor(ccolor[i]);

    if(i == 6){
      theEff -> SetMarkerStyle(20);
      theEff -> SetMarkerColor(kBlack);
      theEff -> SetLineColor(kBlack);
    }
    if( i == 4){
      theEff -> SetFillStyle(3004);
      theEff -> SetFillColor(kBlack);
    }
  }
}

void ExtendedEfficiency::SetTree( TTree* tree , TString sampletype , TString samplesname , TString Cutname){
  if( strcmp( Cutname , "" ) != 0 )
    CutName = Cutname;

  if(tFormula != 0){
    delete tFormula;
    delete tNFormula;
    delete tCondFormula;
    delete tPreCondFormula;
  }

  tFormula = new TTreeFormula( Name.Data() , Formula.Data() , tree );
  tNFormula = new TTreeFormula( (Name+"_NN").Data() , NFormula.Data() , tree);
  tCondFormula = new TTreeFormula( (Name+"_Cond").Data() , CondFormula.Data() , tree );
  tPreCondFormula = new TTreeFormula( (Name+"_PreCond").Data() , PreCondFormula.Data() , tree );

  theEff = 0;
  CurrentIsData =( sampletype == "data" ) ;
  CurrentSampleType = sampletype;
  CurrentSampleSName = samplesname;
  if(CurrentIsData)
    theEff = allEffs["data"];
  else if(CurrentSampleType == "susy"){
    theEff = allEffs["SUSY"];
  }
  else
    theEff = allEffs[ CurrentSampleSName ];

  if( CurrentSampleType == "mc" )
    theMCEff = allEffs["MC"];
  else
    theMCEff = 0;
}
void ExtendedEfficiency::Fill(double w ){
  int N = tNFormula->EvalInstance(0);

  dVal = tFormula->EvalInstance(0);
  
  int preCondsAll = tPreCondFormula->EvalInstance(0);
  if(preCondsAll == 0)
    return;
  vector<int> preCondsAllBits;
  while(preCondsAll) {
    if (preCondsAll&1)
      preCondsAllBits.push_back(1);
    else
      preCondsAllBits.push_back(0);
    preCondsAll>>=1;  
  }
  //reverse(preCondsAllBits.begin(),preCondsAllBits.end());

  for (int i=0 ; i<N ; i++){
    if( tPreCondFormula->GetNdata() > 100 ){
      if( tPreCondFormula->EvalInstance(i) == 0.0 )
	continue;
    }else{
      cout << preCondsAllBits[i] << endl;
      if( preCondsAllBits[i] == 0 )
	continue;
    }

    if( tFormula->GetNdata() > 1 )
      dVal = tFormula->EvalInstance(i);
    double cond = tCondFormula->EvalInstance(i);

    if( theEff )
      theEff->FillWeighted(cond != 0 , w , dVal);

    if( theMCEff )
      theMCEff->FillWeighted(cond != 0 , w , dVal);
  }
}

void ExtendedEfficiency::Write( TDirectory* dir , int lumi , bool plotratiostack , bool logy){
  dir->mkdir( Name )->cd();
  for(auto eff : allEffs){
    eff.second->Write();
  }
}


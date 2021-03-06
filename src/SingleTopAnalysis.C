// includes++ C
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <sstream>
#include <cmath>
#include <fstream>
#include <boost/lexical_cast.hpp>

#include <stdexcept>

// ROOT includes
#include <TROOT.h>
#include <TTree.h>
#include <TChain.h>
#include "TFile.h"

#include "TH2D.h"

#include <climits>

#include "BaseMassPlotter.hh"
#include "SingleTopTree.h"
#include "DMTopVariables.h"
#include <cmath>

#include "TRandom.h"

using namespace std;

void usage( int status ,TString execname ) {
  cout << "Usage: "<< execname << " [-d dir] [-v verbose] [-s sample] [-n nEventPerFile] [-f Outputfile]" << endl;
  cout << "  where:" << endl;
  cout << "     dir      is the output directory               " << endl;
  cout << "               default is ../MassPlots/             " << endl;
  cout << "     verbose  sets the verbose level                " << endl;
  cout << "               default is 0 (quiet mode)            " << endl;
  cout << "     sample   is the file with the list of samples" << endl;
  cout << "     nEventPerFile   is number of events per sample to be analyzed" << endl;
  cout << "     Outputfile   is the output file name" << endl;
  cout << endl;
  exit(status);
}


class MassPlotterSingleTop : public BaseMassPlotter{
public:
  MassPlotterSingleTop(TString outputdir) : BaseMassPlotter( outputdir ) {
    PSeudoDataRandom = new TRandom( 66436155 );
  };
  void singleTopAnalysis(TList* allcuts, Long64_t nevents,TString myfilename );

  TRandom* PSeudoDataRandom;
};

void MassPlotterSingleTop::singleTopAnalysis(TList* allCuts, Long64_t nevents ,TString myfileName ){

  TopUtilities topUtils ;

  int lumi = 0;

  TIter nextcut(allCuts); 
  TObject *objcut; 

  std::vector<TString> alllabels;
  while( objcut = nextcut() ){
    ExtendedCut* thecut = (ExtendedCut*)objcut ;
    alllabels.push_back( thecut->Name );
  }  
  //alllabels.push_back( "NoCut" );
  alllabels.push_back( "Trigger" );
  //alllabels.push_back( "MuonSelection" );
  //alllabels.push_back( "MuonVeto1" );
  //alllabels.push_back( "MuonVeto" );
  alllabels.push_back( "== 1#mu" );
  alllabels.push_back( "== 2-Jets" );
  alllabels.push_back( "== 1-bJet" );
  alllabels.push_back( "MT >50 GeV" );
  //alllabels.push_back( "j'-bVeto" );
  alllabels.push_back( "mtop" );
  //cout << alllabels.size() << endl;

  ExtendedObjectProperty cutflowtable("" , "cutflowtable" , "1" , alllabels.size() ,  0 , alllabels.size() , "2", {}, &alllabels );  
  ExtendedObjectProperty cutflowtablew1("" , "cutflowtablew1" , "1" , alllabels.size() ,  0 , alllabels.size() , "2", {}, &alllabels );  
  

  TString fileName = fOutputDir;
  if(!fileName.EndsWith("/")) fileName += "/";
  Util::MakeOutputDir(fileName);

  bool printEventIds = false;
  vector< ofstream* > EventIdFiles;
  if(printEventIds){
    for( int i = 0 ; i < alllabels.size() ; i++ ){
      ofstream* filetxt = new ofstream(fileName + "/IPM_" + myfileName  + "_step" + boost::lexical_cast<string>(i) + ".txt" );
      EventIdFiles.push_back( filetxt );
    }
  }


  ExtendedObjectProperty nJetsBeforeCut("LeptonVeto" , "nJets" , "1" , 8 , 0 , 8 , "2", {});
  ExtendedObjectProperty nJets20_47("OneBjet" , "nJets20_47" , "1" , 8 , 0 , 8 , "2", {});
  ExtendedObjectProperty nJets20_24("OneBjet" , "nJets20_24" , "1" , 8 , 0 , 8 , "2", {});
  ExtendedObjectProperty nbJets("Jets" , "nbJets" , "1" , 3 , 0 , 3 , "2", {});

  ExtendedObjectProperty MTBeforeCut("OneBjetNoMT" , "MT" , "1" , 30 , 0 , 300 , "2", {});

  ExtendedObjectProperty nPVBeforeCutsUnCorr("nPVBeforeCutsUnCorr" , "nPVBeforeCutsUnCorr" , "1" , 100 , 0 , 100 , "2", {});
  ExtendedObjectProperty nPVBeforeCuts("nPVBeforeCuts" , "nPVBeforeCuts" , "1" , 100 , 0 , 100 , "2", {});
  ExtendedObjectProperty nPVAfterCutsUnCorr("nPVAfterCutsUnCorr" , "nPVAfterCutsUnCorr" , "1" , 100 , 0 , 100 , "2", {});
  ExtendedObjectProperty nPVAfterCuts("nPVAfterCuts" , "nPVAfterCuts" , "1" , 100 , 0 , 100 , "2", {});

  ExtendedObjectProperty TopMass("OneBjet" , "TopMass" , "1" , 30 , 100 , 400 , "2", {});
  ExtendedObjectProperty jprimeEta("OneBjet" , "jPrimeEta" , "1" , 10 , 0 , 5.0 , "2", {});
  ExtendedObjectProperty jprimeEtaSB("SideBand" , "jPrimeEtaSB" , "1" , 10 , 0 , 5.0 , "2", {});
  ExtendedObjectProperty jprimePt("OneBjet" , "jPrimePt" , "1" , 30 , 30 , 330 , "2", {});
  ExtendedObjectProperty muPtOneB("OneBjet" , "muPt" , "1" , 20 , 20 , 120 , "2", {});
  ExtendedObjectProperty muCharge("OneBjet" , "muCharge" , "1" , 40 , -2 , 2 , "2", {});
  ExtendedObjectProperty muEtaOneB("OneBjet" , "muEta" , "1" , 10 , -2.5 , 2.5 , "2", {});
  ExtendedObjectProperty METOneBSR("OneBjet" , "MET_SR" , "1" , 20 , 0 , 200 , "2", {});
  ExtendedObjectProperty METOneBSB("OneBjet" , "MET_SB" , "1" , 20 , 0 , 200 , "2", {});
  ExtendedObjectProperty METOneBAll("OneBjet" , "MET_ALL" , "1" , 20 , 0 , 200 , "2", {});
  ExtendedObjectProperty bPtOneB("OneBjet" , "bPt" , "1" , 30 , 30 , 330 , "2", {});
  ExtendedObjectProperty bEtaOneB("OneBjet" , "bEta" , "1" , 10 , 0 , 5.0 , "2", {});
  ExtendedObjectProperty nonbCSV("OneBjet" , "jpCSV" , "1" , 20 , 0 , 1.0 , "2", {});

  ExtendedObjectProperty nLbjets1EJ24("1EJ24" , "nLbJets_1EJ24" , "1" , 2 , 0 , 2  , "2", {});
  ExtendedObjectProperty nTbjets1EJ24("1EJ24" , "nTbJets_1EJ24" , "1" , 2 , 0 , 2  , "2", {});

  ExtendedObjectProperty nLbjets2EJ24("2EJ24" , "nLbJets_2EJ24" , "1" , 3 , 0 , 3  , "2", {});
  ExtendedObjectProperty nTbjets2EJ24("2EJ24" , "nTbJets_2EJ24" , "1" , 3 , 0 , 3  , "2", {});

  ExtendedObjectProperty nLbjets3EJ24("3EJ24" , "nLbJets_3EJ24" , "1" , 4 , 0 , 4  , "2", {});
  ExtendedObjectProperty nTbjets3EJ24("3EJ24" , "nTbJets_3EJ24" , "1" , 4 , 0 , 4  , "2", {});

  ExtendedObjectProperty nLbjets4EJ24("4EJ24" , "nLbJets_4EJ24" , "1" , 5 , 0 , 5  , "2", {});
  ExtendedObjectProperty nTbjets4EJ24("4EJ24" , "nTbJets_4EJ24" , "1" , 5 , 0 , 5  , "2", {});

  ExtendedObjectProperty nLbjets1EJ47("1EJ47" , "nLbJets_1EJ47" , "1" , 2 , 0 , 2  , "2", {});
  ExtendedObjectProperty nTbjets1EJ47("1EJ47" , "nTbJets_1EJ47" , "1" , 2 , 0 , 2  , "2", {});

  ExtendedObjectProperty nLbjets2EJ47("2EJ47" , "nLbJets_2EJ47" , "1" , 3 , 0 , 3  , "2", {});
  ExtendedObjectProperty nTbjets2EJ47("2EJ47" , "nTbJets_2EJ47" , "1" , 3 , 0 , 3  , "2", {});

  ExtendedObjectProperty nLbjets3EJ47("3EJ47" , "nLbJets_3EJ47" , "1" , 4 , 0 , 4  , "2", {});
  ExtendedObjectProperty nTbjets3EJ47("3EJ47" , "nTbJets_3EJ47" , "1" , 4 , 0 , 4  , "2", {});

  ExtendedObjectProperty nLbjets4EJ47("4EJ47" , "nLbJets_4EJ47" , "1" , 5 , 0 , 5  , "2", {});
  ExtendedObjectProperty nTbjets4EJ47("4EJ47" , "nTbJets_4EJ47" , "1" , 5 , 0 , 5  , "2", {});

  TH1* hTopMass = new TH1D("hTopMass" , "Top Mass" , 500 , 0 , 500 );
  TH1* hTopMassEtaJ = new TH2D( "hTopMassEtaJ" , "Top Mass" , 500 , 0 , 500 , 20 , 0 , 5.0 );

  TH1* hEtajPDFScales[102];
  double ScalesPDF[102];
  double CurrentPDFWeights[102];
  for(int i=0 ; i < 102 ; i++){
    TString s(to_string(i));
    hEtajPDFScales[i] = new TH1D( TString("hEtaJp_PDF")+s , "" , 10 , 0 , 5.0 );
    ScalesPDF[i] = 0 ;
    CurrentPDFWeights[i] = 0;
  }

  TH1* hEtajWScales[9];
  double WScalesTotal[9];
  double CurrentLHEWeights[9];
  for(int i=0; i < 9; i++){
    TString s(to_string(i));
    hEtajWScales[i] = new TH1D( TString("hEtaJp_")+s , "" , 10 , 0 , 5.0 );
    WScalesTotal[i] = 0 ;
    CurrentLHEWeights[i] = 0;
  }

  std::vector<ExtendedObjectProperty*> allProps = {&cutflowtable, &cutflowtablew1 , &nJetsBeforeCut , &nbJets , &MTBeforeCut, &TopMass , &jprimeEta , &jprimeEtaSB , &jprimePt , &muPtOneB, &muCharge, &muEtaOneB , &METOneBSR ,&METOneBSB , &METOneBAll , & bPtOneB , &bEtaOneB , &nonbCSV ,&nJets20_24, &nJets20_47,&nPVAfterCuts, &nPVBeforeCuts , &nPVAfterCutsUnCorr , &nPVBeforeCutsUnCorr};

  std::vector<ExtendedObjectProperty*> JbJOptimizationProps = {&nLbjets1EJ24,&nTbjets1EJ24,&nLbjets2EJ24,&nTbjets2EJ24,&nLbjets3EJ24,&nTbjets3EJ24,&nLbjets4EJ24,&nTbjets4EJ24,&nLbjets1EJ47,&nTbjets1EJ47,&nLbjets2EJ47,&nTbjets2EJ47,&nLbjets3EJ47,&nTbjets3EJ47,&nLbjets4EJ47,&nTbjets4EJ47};
  nextcut.Reset();


  //codes for 2j0t selection
  TFile *theTreeFile = NULL;
  if(IsQCD==1)
    theTreeFile = new TFile( (fileName+ myfileName + "_Trees.root" ).Data(), "RECREATE");    

  double MT_QCD_Tree , TOPMASS_QCD_Tree , MuIso_QCD_Tree , Weight_QCD_Tree;

  TTree* theQCD_Tree = NULL;
  //end of 2j0t

  for(int ii = 0; ii < fSamples.size(); ii++){

    int data = 0;
    sample Sample = fSamples[ii];

    TEventList* list = 0;
   
    if(Sample.type == "data"){
      data = 1;
    }else
      lumi = Sample.lumi; 

    if( theTreeFile ){
      TString treename = Sample.sname ;
      if( data )
	treename = "Data";
      if( theTreeFile->Get( treename ) ){
	theQCD_Tree = (TTree*) (theTreeFile->Get( treename )) ; 
      }else{
	theTreeFile->cd();
	theQCD_Tree = new TTree( treename , treename + " tree for QCD shape/normalization studies" );
	theQCD_Tree->Branch( "MT/D" , &MT_QCD_Tree );
	theQCD_Tree->Branch( "TOPMASS/D" , &TOPMASS_QCD_Tree );
	theQCD_Tree->Branch( "MuIso/D" , &MuIso_QCD_Tree );
	theQCD_Tree->Branch( "Weight/D" , &Weight_QCD_Tree );
      }
    }


    double Weight = Sample.xsection * Sample.kfact * Sample.lumi / (Sample.nevents*Sample.PU_avg_weight);
    //Weight = 1.0;
    if(data == 1)
      Weight = 1.0;

    Sample.Print(Weight);

    SingleTopTree fTree( Sample.tree );
    Sample.tree->SetBranchStatus("*", 1);

    string lastFileName = "";

    Long64_t nentries =  Sample.tree->GetEntries();
    Long64_t maxloop = min(nentries, nevents);

    int counter = 0;
    double EventsIsPSeudoData ;
    int cutPassCounter = 0;
    for (Long64_t jentry=0; jentry<maxloop;jentry++, counter++) {
      Sample.tree->GetEntry(jentry);
      // //cout << fTree.Event_EventNumber << endl;
      // if(  !(fTree.Event_EventNumber == 11112683 || fTree.Event_EventNumber == 11112881 ) ){
      // 	//cout << " " ;
      // 	continue;
      // }
      // else{
      // 	cutPassCounter ++ ;
      // 	cout << cutPassCounter << " : " << fTree.Event_EventNumber << " : " << endl;
      // }
      EventsIsPSeudoData = PSeudoDataRandom->Uniform();

      if( lastFileName.compare( ((TChain*)Sample.tree)->GetFile()->GetName() ) != 0 ) {
	for(auto prop : allProps)
	  prop->SetTree( Sample.tree , Sample.type, Sample.sname );
	for(auto prop2 : JbJOptimizationProps ) 
	  prop2->SetTree( Sample.tree , Sample.type, Sample.sname );

	nextcut.Reset();
	while( objcut = nextcut() ){
	  ExtendedCut* thecut = (ExtendedCut*)objcut ;
	  thecut->SetTree( Sample.tree ,  Sample.name , Sample.sname , Sample.type , Sample.xsection, Sample.nevents, Sample.kfact , Sample.PU_avg_weight);
	}

	lastFileName = ((TChain*)Sample.tree)->GetFile()->GetName() ;
	cout << "new file : " << lastFileName << endl;
      }

      if ( counter == 100000 ){  
	fprintf(stdout, "\rProcessed events: %6d of %6d ", jentry + 1, nentries);
	fflush(stdout);
	counter = 0;
      }
 
      nextcut.Reset();
      double weight = Weight;

      if( !data ){
	weight *= fTree.Event_puWeight ;
      }

      if( Sample.UseLHEWeight ){
	//cout << "SIGNAL" << endl;
	weight *= fTree.Event_LHEWeightSign ;
	// if(fTree.Event_LHEWeightSign < 0.0)
	//   cout << fTree.Event_LHEWeightSign << endl;
      }

      #ifdef SingleTopTreeLHEWeights_h
      for( int i = 0 ; i < 102 ; i++ ){
	CurrentPDFWeights[i] = fTree.GetPDFWeight(i)/fabs(fTree.Event_LHEWeight) ;
	ScalesPDF[i] += CurrentPDFWeights[i] ;
      }

      if( Sample.name == "WJets" || Sample.name == "Signal" ){

	
	if(fTree.GetLHEWeight(0) != fTree.Event_LHEWeight0) cout << "Wrong GetLHEWeight(0) Value" << endl;
	if(fTree.GetLHEWeight(1) != fTree.Event_LHEWeight1) cout << "Wrong GetLHEWeight(1) Value" << endl;
	if(fTree.GetLHEWeight(2) != fTree.Event_LHEWeight2) cout << "Wrong GetLHEWeight(2) Value" << endl;
	if(fTree.GetLHEWeight(3) != fTree.Event_LHEWeight3) cout << "Wrong GetLHEWeight(3) Value" << endl;
	if(fTree.GetLHEWeight(4) != fTree.Event_LHEWeight4) cout << "Wrong GetLHEWeight(4) Value" << endl;
	if(fTree.GetLHEWeight(5) != fTree.Event_LHEWeight5) cout << "Wrong GetLHEWeight(5) Value" << endl;
	if(fTree.GetLHEWeight(6) != fTree.Event_LHEWeight6) cout << "Wrong GetLHEWeight(6) Value" << endl;
	if(fTree.GetLHEWeight(7) != fTree.Event_LHEWeight7) cout << "Wrong GetLHEWeight(7) Value" << endl;
	if(fTree.GetLHEWeight(8) != fTree.Event_LHEWeight8) cout << "Wrong GetLHEWeight(8) Value" << endl;
	
	// CurrentLHEWeights[0] = fTree.Event_LHEWeight /fabs(fTree.Event_LHEWeight) ;
	// CurrentLHEWeights[1] = fTree.Event_LHEWeight1/fabs(fTree.Event_LHEWeight) ;
	// CurrentLHEWeights[2] = fTree.Event_LHEWeight2/fabs(fTree.Event_LHEWeight) ;
	// CurrentLHEWeights[3] = fTree.Event_LHEWeight3/fabs(fTree.Event_LHEWeight) ;
	// CurrentLHEWeights[4] = fTree.Event_LHEWeight4/fabs(fTree.Event_LHEWeight) ;
	// CurrentLHEWeights[5] = fTree.Event_LHEWeight5/fabs(fTree.Event_LHEWeight) ;
	// CurrentLHEWeights[6] = fTree.Event_LHEWeight6/fabs(fTree.Event_LHEWeight) ;
	// CurrentLHEWeights[7] = fTree.Event_LHEWeight7/fabs(fTree.Event_LHEWeight) ;
	// CurrentLHEWeights[8] = fTree.Event_LHEWeight8/fabs(fTree.Event_LHEWeight) ;
	
	for(int i = 0 ; i<9 ;i++){
	  CurrentLHEWeights[i] = fTree.GetLHEWeight(i)/fabs(fTree.Event_LHEWeight) ;
	  WScalesTotal[i] += CurrentLHEWeights[i];
	}
      }
      #endif
      
      double cutindex = 0.5;
      bool pass=true;
      while( objcut = nextcut() ){
	ExtendedCut* thecut = (ExtendedCut*)objcut ;
	pass &= thecut->Pass(jentry , weight);
	if(! pass ){
	  break;
	}else{
	  if( isfinite (weight) ){
	    cutflowtable.Fill( cutindex , weight , EventsIsPSeudoData < fabs(weight) );
	    cutflowtablew1.Fill( cutindex , weight/fabs(weight) , EventsIsPSeudoData < fabs(weight) );
	  }
	  else
	    cout << "non-finite weight : " << weight << endl;
	}
	cutindex+=1.0;
      }

      if(! pass)
	continue;

      int cut = 0;

      //cout << alllabels[ int(cutindex) ] << endl;
//       cutflowtable.Fill( cutindex , weight , EventsIsPSeudoData < fabs(weight) );
//       cutflowtablew1.Fill( cutindex , weight/fabs(weight) , EventsIsPSeudoData < fabs(weight) );
//       cutindex ++ ;

      // if( data && !(fTree.Event_passesHLT_IsoMu20_eta2p1_v2 > 0.5) )
      // 	continue;
      
      // if( !data && !(fTree.Event_passesHLT_IsoMu20_eta2p1_v1 > 0.5) )
      // 	continue;

      nPVBeforeCutsUnCorr.Fill( fTree.Event_nPV , weight/fTree.Event_puWeight , false , true );
      nPVBeforeCuts.Fill( fTree.Event_nPV , weight , false, true);

      // if( printEventIds )
      // 	(*(EventIdFiles[cutindex])) << fTree.Event_EventNumber << endl; 
      // cutflowtable.Fill( cutindex , weight , EventsIsPSeudoData < fabs(weight) );
      // cutflowtablew1.Fill( cutindex , weight/fabs(weight) , EventsIsPSeudoData < fabs(weight) );
      // cutindex ++ ;
      
      if( data && !(fTree.Event_passesHLT_IsoMu20_v2 > 0.5 || fTree.Event_passesHLT_IsoMu20_v1 > 0.5 || fTree.Event_passesHLT_IsoMu20_v3 > 0.5)  )
	continue;
      if(!data && !(fTree.Event_passesHLT_IsoMu20_v1 > 0.5) )
	continue;

      if( printEventIds )
	(*(EventIdFiles[cutindex])) << fTree.Event_EventNumber << endl;
      cutflowtable.Fill( cutindex , weight , EventsIsPSeudoData < fabs(weight) );
      cutflowtablew1.Fill( cutindex , weight/fabs(weight) , EventsIsPSeudoData < fabs(weight) );
      cutindex ++ ;
      

      //cout << "nMuons : " << fTree.muons_size << endl;
      int tightMuIndex =-1;
      int nonTightMuIndex = -1;
      int nLooseMuos   = 0;
      int nTightMuons = 0;
      int nTightNonIsoMuons = 0;

      for( int imu=0 ; imu < fTree.muons_size ; imu++ ){
	// cout << imu << " : " << fTree.muons_Pt[imu] << "-" << fTree.muons_Eta[imu] << "-"
	//      << fTree.muons_IsTightMuon[imu] << "-" << fTree.muons_Iso04[imu] << endl;
	
	bool isTight = false;
      	if( fTree.muons_Pt[imu] > 22.0 &&
	    fabs(fTree.muons_Eta[imu]) < 2.1 &&
	    fTree.muons_IsTightMuon[imu] > 0.5 ){


	  if( fTree.muons_Iso04[imu] < 0.06 ){ 
	    isTight = true;
	    nTightMuons ++;
	    if( tightMuIndex == -1 )
	      tightMuIndex = imu;
	  }else if( fTree.muons_Iso04[imu] < 0.15 ){
	    nTightNonIsoMuons ++;
	    if( nonTightMuIndex == -1 )
	      nonTightMuIndex = imu;
	  }
	}

	if( ! isTight )
	  if( fTree.muons_Pt[ imu ] > 10.0 &&
	      fTree.muons_IsLooseMuon[ imu ] > 0.5 &&
	      fabs(fTree.muons_Eta[imu]) < 2.5 && 
	      fTree.muons_Iso04[imu] < 0.20 ){
	    nLooseMuos++;
	  }
      }      

      if(IsQCD){
	nLooseMuos = nTightMuons ;	
	nTightMuons = nTightNonIsoMuons ;
	tightMuIndex = nonTightMuIndex ;
      }


      if( nTightMuons != 1 )
	  continue;

      bool isiso = true;

      if( nLooseMuos > 0 )
      	continue;

#ifdef MUONCHARGEP
      if(fTree.muons_Charge[tightMuIndex] < 0)
	continue;
#endif
#ifdef MUONCHARGEN
      if(fTree.muons_Charge[tightMuIndex] > 0)
	continue;
#endif

      // if( printEventIds )
      // 	(*(EventIdFiles[cutindex])) << (fTree.Event_EventNumber) << endl ;
      // cutflowtable.Fill( cutindex , weight , EventsIsPSeudoData < fabs(weight) );
      // cutflowtablew1.Fill( cutindex , weight/fabs(weight) , EventsIsPSeudoData < fabs(weight) );
      // cutindex ++ ;

      int nLooseElectrons = 0;
      for( int iele = 0 ; iele < fTree.electrons_size;iele ++ ){
      	if( fTree.electrons_Pt[iele] > 20 &&
	    fabs(fTree.electrons_Eta[iele]) < 2.5 && 
	    ( fabs(fTree.electrons_Eta[iele]) < 1.4442 || fabs(fTree.electrons_Eta[iele]) > 1.566) &&
	    fTree.electrons_vidVeto[iele] > 0.5 )
	  nLooseElectrons++;
      }
      
      if( nLooseElectrons > 0 )
      	continue;

      if( printEventIds )
	(*(EventIdFiles[cutindex])) << (fTree.Event_EventNumber) << endl ;
      cutflowtable.Fill( cutindex , weight , EventsIsPSeudoData < fabs(weight) );
      cutflowtablew1.Fill( cutindex , weight/fabs(weight) , EventsIsPSeudoData < fabs(weight) );
      cutindex ++ ;

      int j1index = -1;
      int j2index = -1;
      int j3index = -1;
      int nJets = 0 ;
      int howManyBJets = 0;
      int bjIndex = -1;
      int bj2Index = -1;
      int jprimeIndex ; 

      int nJetsPt20_47 = 0;

      int nJetsPt20_24 = 0;
      int nLbJetsPt20 = 0;
      int nTbJetsPt20 = 0;

      TLorentzVector muon;
      muon.SetPtEtaPhiE( fTree.muons_Pt[tightMuIndex] , fTree.muons_Eta[tightMuIndex] , fTree.muons_Phi[tightMuIndex] , fTree.muons_E[tightMuIndex] );
      if( muon.Energy() == 0.0 )
	cout << "ZERO???" <<endl;
      for( int jid = 0 ; jid < fTree.jetsAK4_size ; jid++ ){

	float NHF = fTree.jetsAK4_JetID_neutralHadronEnergyFraction[jid] ;
	float NEMF = fTree.jetsAK4_JetID_neutralEmEnergyFraction[jid] ;
	float NumConst = fTree.jetsAK4_JetID_numberOfDaughters[jid] ;
	float eta = fTree.jetsAK4_Eta[jid] ;
	float CHF = fTree.jetsAK4_JetID_chargedHadronEnergyFraction[jid] ;
	float CHM = fTree.jetsAK4_JetID_chargedMultiplicity[jid] ;
	float CEMF = fTree.jetsAK4_JetID_chargedEmEnergyFraction[jid] ;
	float NumNeutralParticle = fTree.jetsAK4_JetID_neutralMultiplicity[jid] ;


	bool looseid ;
	if(  abs(eta)<=3.0 ) {
	  looseid = (NHF<0.99 && NEMF<0.99 && NumConst>1) && ((abs(eta)<=2.4 && CHF>0 && CHM>0 && CEMF<0.99) || abs(eta)>2.4) ;
	}
	else
	  looseid = (NEMF<0.90 && NumNeutralParticle>10) ;

      	if( fTree.jetsAK4_CorrPt[jid] > 20 &&
	    fabs( fTree.jetsAK4_Eta[jid] ) < 4.7 &&
	    looseid
	    ){
	  TLorentzVector jet;
	  jet.SetPtEtaPhiE( fTree.jetsAK4_CorrPt[jid] , fTree.jetsAK4_Eta[jid] , fTree.jetsAK4_Phi[jid] , fTree.jetsAK4_CorrE[jid] );
	  double DR = muon.DeltaR( jet );

	  if ( DR > 0.3 ){

	    if( fTree.jetsAK4_CorrPt[jid] <= 40 ){
	      nJetsPt20_47 ++ ;
	      if( fabs( fTree.jetsAK4_Eta[jid] ) < 2.4 ){
		nJetsPt20_24 ++;
		if( fTree.jetsAK4_CSV[jid] > 0.97 )
		  nTbJetsPt20++;
		else if( fTree.jetsAK4_CSV[jid] > 0.605 )
		  nLbJetsPt20++;
	      }
	      
	      continue;
	    }	    
	    nJets++;
	    if( nJets == 1 )
	      j1index = jid ;
	    else if(nJets == 2 )
	      j2index = jid ;
	    else if( nJets == 3 )
	      j3index = jid ;
	    
	    if( fTree.jetsAK4_IsCSVT[jid] == true  && fabs( fTree.jetsAK4_Eta[jid] ) <= 2.4 ){
	      howManyBJets ++;
	      if(howManyBJets==1)
		bjIndex = jid ;
	      else if(howManyBJets==2)
		bj2Index = jid ;
	    }else
	      jprimeIndex = jid ;
	  }
	}
      }
      
      nJetsBeforeCut.Fill( nJets , weight , EventsIsPSeudoData < fabs(weight) , isiso );
      if (nJets != NUMBEROFJETS)
	continue;


      if( printEventIds )
	(*(EventIdFiles[cutindex])) << (fTree.Event_EventNumber) << endl ;
      cutflowtable.Fill( cutindex , weight , EventsIsPSeudoData < fabs(weight) );
      cutflowtablew1.Fill( cutindex , weight/fabs(weight) , EventsIsPSeudoData < fabs(weight) );
      cutindex ++ ;
      
      nbJets.Fill( howManyBJets , weight , EventsIsPSeudoData < fabs(weight) , isiso);
      if( howManyBJets != NUMBEROFBJETS )
	continue;

      if( !data ){
	if( NUMBEROFBJETS == 2 )
	  weight *= fTree.Event_bWeight2CSVT ;
	else if (NUMBEROFBJETS == 1 )
	  weight *= fTree.Event_bWeight1CSVT ;
      }

      //weight = 1.0;

      if( printEventIds )
	(*(EventIdFiles[cutindex])) << (fTree.Event_EventNumber) << endl ;
      cutflowtable.Fill( cutindex , weight , EventsIsPSeudoData < fabs(weight) );
      cutflowtablew1.Fill( cutindex , weight/fabs(weight) , EventsIsPSeudoData < fabs(weight) );
      cutindex ++ ;

     
      double MT = sqrt( 2*fTree.met_Pt* fTree.muons_Pt[tightMuIndex]*(1-TMath::Cos( Util::DeltaPhi(fTree.met_Phi , fTree.muons_Phi[tightMuIndex]) ) )  ) ;
      MTBeforeCut.Fill( MT , weight , EventsIsPSeudoData < fabs(weight) , isiso );
      // if( fTree.met_Pt < 45 )
      // 	continue;
      if( MT < 50 && (NUMBEROFBJETS == 1 && NUMBEROFJETS == 2) && !IsQCD )
      	continue;

      if( printEventIds )
	(*(EventIdFiles[cutindex])) << (fTree.Event_EventNumber) << endl ;
     
      cutflowtable.Fill( cutindex , weight , EventsIsPSeudoData < fabs(weight) );
      cutflowtablew1.Fill( cutindex , weight/fabs(weight) , EventsIsPSeudoData < fabs(weight) );
      cutindex ++ ;

      nonbCSV.Fill( fTree.jetsAK4_CSV[jprimeIndex] , weight , EventsIsPSeudoData < fabs(weight) , isiso);

//       if( fTree.jetsAK4_CSV[jprimeIndex] > 0.605 )
// 	continue;

      // if( printEventIds )
      // 	(*(EventIdFiles[cutindex])) << (fTree.Event_EventNumber) << endl ;
      // cutflowtable.Fill( cutindex , weight , EventsIsPSeudoData < fabs(weight) );
      // cutflowtablew1.Fill( cutindex , weight/fabs(weight) , EventsIsPSeudoData < fabs(weight) );
      // cutindex ++ ;

      nJets20_47.Fill( nJetsPt20_47 , weight , EventsIsPSeudoData < fabs(weight) , isiso);
      nJets20_24.Fill( nJetsPt20_24 , weight , EventsIsPSeudoData < fabs(weight) , isiso);

      if(nJetsPt20_24 < 2){
	nLbjets1EJ24.Fill( nLbJetsPt20 , weight , EventsIsPSeudoData < fabs(weight) , isiso);
	nTbjets1EJ24.Fill( nTbJetsPt20 , weight , EventsIsPSeudoData < fabs(weight) , isiso);
      }
      if(nJetsPt20_24 < 3){
	nLbjets2EJ24.Fill( nLbJetsPt20 , weight , EventsIsPSeudoData < fabs(weight) , isiso);
	nTbjets2EJ24.Fill( nTbJetsPt20 , weight , EventsIsPSeudoData < fabs(weight) , isiso);
      }
      if(nJetsPt20_24 < 4){
	nLbjets3EJ24.Fill( nLbJetsPt20 , weight , EventsIsPSeudoData < fabs(weight) , isiso);
	nTbjets3EJ24.Fill( nTbJetsPt20 , weight , EventsIsPSeudoData < fabs(weight) , isiso);
      }
      if(nJetsPt20_24 < 5){
	nLbjets4EJ24.Fill( nLbJetsPt20 , weight , EventsIsPSeudoData < fabs(weight) , isiso);
	nTbjets4EJ24.Fill( nTbJetsPt20 , weight , EventsIsPSeudoData < fabs(weight) , isiso);
      }

      if(nJetsPt20_47 < 2){
	nLbjets1EJ47.Fill( nLbJetsPt20 , weight , EventsIsPSeudoData < fabs(weight) , isiso);
	nTbjets1EJ47.Fill( nTbJetsPt20 , weight , EventsIsPSeudoData < fabs(weight) , isiso);
      }
      if(nJetsPt20_47 < 3){
	nLbjets2EJ47.Fill( nLbJetsPt20 , weight , EventsIsPSeudoData < fabs(weight) , isiso);
	nTbjets2EJ47.Fill( nTbJetsPt20 , weight , EventsIsPSeudoData < fabs(weight) , isiso);
      }
      if(nJetsPt20_47 < 4){
	nLbjets3EJ47.Fill( nLbJetsPt20 , weight , EventsIsPSeudoData < fabs(weight) , isiso);
	nTbjets3EJ47.Fill( nTbJetsPt20 , weight , EventsIsPSeudoData < fabs(weight) , isiso);
      }
      if(nJetsPt20_47 < 5){
	nLbjets4EJ47.Fill( nLbJetsPt20 , weight , EventsIsPSeudoData < fabs(weight) , isiso);
	nTbjets4EJ47.Fill( nTbJetsPt20 , weight , EventsIsPSeudoData < fabs(weight) , isiso);
      }


      if( NUMBEROFBJETS == 2 )
	if( fTree.jetsAK4_CSV[bj2Index] > fTree.jetsAK4_CSV[bjIndex] )
	  std::swap( bj2Index , bjIndex );

      //int jprimeIndex = (bjIndex == j1index) ? j2index : j1index ;
      TLorentzVector muLV;
      muLV.SetPtEtaPhiE( fTree.muons_Pt[tightMuIndex] , fTree.muons_Eta[tightMuIndex] , fTree.muons_Phi[ tightMuIndex ] , fTree.muons_E[tightMuIndex] );
      TLorentzVector bjetLV;
      bjetLV.SetPtEtaPhiE( fTree.jetsAK4_CorrPt[ bjIndex ] , fTree.jetsAK4_Eta[ bjIndex ] , fTree.jetsAK4_Phi[ bjIndex ] , fTree.jetsAK4_CorrE[ bjIndex ] ) ; 
      double topMass = topUtils.top4Momentum( muLV , bjetLV , fTree.met_Px , fTree.met_Py ).mass();
      TopMass.Fill( topMass , weight , EventsIsPSeudoData < fabs(weight) , isiso ); //fTree.resolvedTopSemiLep_Mass[0]

      MT_QCD_Tree = MT;
      TOPMASS_QCD_Tree = topMass ;
      MuIso_QCD_Tree = fTree.muons_Iso04[tightMuIndex];
      Weight_QCD_Tree = weight ;

      if( IsQCD )
	theQCD_Tree->Fill();



      if( (130. < topMass && topMass < 225.) || NUMBEROFBJETS == 2 ){

	nPVAfterCutsUnCorr.Fill( fTree.Event_nPV , weight/fTree.Event_puWeight , EventsIsPSeudoData < fabs(weight) , isiso );
	nPVAfterCuts.Fill( fTree.Event_nPV , weight , EventsIsPSeudoData < fabs(weight) , isiso );

#ifdef SingleTopTreeLHEWeights_h
	for(int i = 0 ; i< 102 ; i++){
	  hEtajPDFScales[i]->Fill( fabs( fTree.jetsAK4_Eta[jprimeIndex] ) , weight*fabs( CurrentPDFWeights[i] ) );
	}
	if( Sample.name == "WJets" || Sample.name == "Signal"){
	  for(int i=0;i<9;i++)
	    hEtajWScales[i]->Fill( fabs( fTree.jetsAK4_Eta[jprimeIndex] ) , weight*fabs( CurrentLHEWeights[i] ) );
	}
#endif
	
	jprimeEta.Fill( fabs( fTree.jetsAK4_Eta[jprimeIndex] ) , weight , EventsIsPSeudoData < fabs(weight) , isiso);
	jprimePt.Fill( fTree.jetsAK4_CorrPt[jprimeIndex] , weight , EventsIsPSeudoData < fabs(weight) , isiso);
	muPtOneB.Fill( fTree.muons_Pt[tightMuIndex] , weight , EventsIsPSeudoData < fabs(weight) , isiso);
	muCharge.Fill( fTree.muons_Charge[tightMuIndex] , weight , EventsIsPSeudoData < fabs(weight) , isiso);
	muEtaOneB.Fill( fabs(fTree.muons_Eta[tightMuIndex]) , weight , EventsIsPSeudoData < fabs(weight), isiso );
	METOneBSR.Fill(  fTree.met_Pt , weight , EventsIsPSeudoData < fabs(weight) , isiso);
	bPtOneB.Fill( fTree.jetsAK4_CorrPt[bjIndex] , weight , EventsIsPSeudoData < fabs(weight), isiso );
	bEtaOneB.Fill(fabs( fTree.jetsAK4_Eta[bjIndex] ) , weight , EventsIsPSeudoData < fabs(weight), isiso );

	if( printEventIds )
	  (*(EventIdFiles[cutindex])) << (fTree.Event_EventNumber) << endl ;
	cutflowtable.Fill( cutindex , weight , EventsIsPSeudoData < fabs(weight) );
	cutflowtablew1.Fill( cutindex , weight/fabs(weight) , EventsIsPSeudoData < fabs(weight) );
	cutindex++;
      }else{
	jprimeEtaSB.Fill( fabs( fTree.jetsAK4_Eta[jprimeIndex] ) , weight , EventsIsPSeudoData < fabs(weight) , isiso );
	METOneBSB.Fill(  fTree.met_Pt , weight , EventsIsPSeudoData < fabs(weight) , isiso);
      }

      METOneBAll.Fill(  fTree.met_Pt , weight , EventsIsPSeudoData < fabs(weight) , isiso);

      if(Sample.name == "Signal" )
	hTopMass->Fill( topMass , weight );
      if(Sample.name == "WJets")
	hTopMassEtaJ->Fill( topMass ,fabs( fTree.jetsAK4_Eta[jprimeIndex] )  );
    }
    theQCD_Tree->Write();
    
  }

  theTreeFile->Close();
      

  // TString fileName = fOutputDir;
  // if(!fileName.EndsWith("/")) fileName += "/";
  // Util::MakeOutputDir(fileName);
  fileName += myfileName + ".root" ;

  TFile *theFile = new TFile(fileName.Data(), "RECREATE");

  nonbCSV.CalcSig( 0 , 0 , -1 , 0 ) ; 
  nonbCSV.CalcSig( 0 , 4 , -1 , 0.1); 
  nonbCSV.CalcSig( 0 , 2 , -1 , 0 ) ; 

  nJets20_24.CalcSig( 0 , 0 , -1 , 0 ) ; 
  nJets20_24.CalcSig( 0 , 4 , -1 , 0.1 ) ; 
  nJets20_24.CalcSig( 0 , 2 , -1 , 0 ) ; 
  nJets20_47.CalcSig( 0 , 0 , -1 , 0 ) ; 
  nJets20_47.CalcSig( 0 , 4 , -1 , 0.1 ) ; 
  nJets20_47.CalcSig( 0 , 2 , -1 , 0 ) ; 

  muCharge.CalcSig( 0 , 0 , -1 , 0 ) ; 
  muCharge.CalcSig( 0 , 4 , -1 , 0.1 ) ; 
  muCharge.CalcSig( 0 , 2 , -1 , 0 ) ; 
  muCharge.CalcSig( 1 , 0 , -1 , 0 ) ; 
  muCharge.CalcSig( 1 , 4 , -1 , 0.1 ) ; 
  muCharge.CalcSig( 1 , 2 , -1 , 0 ) ; 

  for(auto prop : allProps)
    prop->Write( theFile , 1000  );

#ifdef SingleTopTreeLHEWeights_h
  TDirectory* dirWScales = theFile->mkdir("WJScales");
  dirWScales->cd();
  for(int i=0;i<9;i++){
    cout << "WScalesTotal[i]" << WScalesTotal[i] << "," << WScalesTotal[0]/WScalesTotal[i] << endl;
    hEtajWScales[i]->Scale( WScalesTotal[0]/WScalesTotal[i] );
    hEtajWScales[i]->Write();
  }

  TDirectory* dirPDFScales = theFile->mkdir("PDFScales");
  dirPDFScales->cd();
  for(int i=0;i<102;i++){
    cout << "PDFScales[i]" << ScalesPDF[i] << "," << WScalesTotal[0]/ScalesPDF[i] << endl;
    hEtajPDFScales[i]->Scale( WScalesTotal[0]/ScalesPDF[i] );
    hEtajPDFScales[i]->Write();
  }
#endif

  TDirectory* dir2 = theFile->mkdir("JbJOptimizationProps");
  dir2->cd();

  for(auto prop2 : JbJOptimizationProps){
    prop2->CalcSig( 0 , 0 , -1 , 0 ) ; 
    prop2->CalcSig( 0 , 4 , -1 , 0.1 ) ; 
    prop2->CalcSig( 0 , 2 , -1 , 0 ) ; 
    prop2->Write( dir2 , 1000  );
  }

  theFile->cd();
  hTopMass->Write();
  hTopMassEtaJ->Write();
  //cutflowtable.Print("cutflowtable");
  theFile->Close();
  if( printEventIds )
    for( auto a : EventIdFiles ){
      a->close();
    }
}

//_____________________________________________________________________________________
int main(int argc, char* argv[]) {
#ifdef SingleTopTreeLHEWeights_h
  cout << "SingleTopTreeLHEWeights_h" << endl;
#endif
  TString execname = TString(argv[0]);
  // Default options
  TString outputfile = "EleTau_Signal_METBJetsCuts"; 
  TString outputdir = "./MassPlots/";
  TString samples = "./samples/samplesMineTauPlusX.dat";
  TString channel = "etau";
  Long64_t neventperfile = LONG_MAX;
  int verbose = 0;

  // Parse options
  char ch;
  while ((ch = getopt(argc, argv, "n:p:t:c:f:d:v:s:lh?")) != -1 ) {
    switch (ch) {
    case 'd': outputdir = TString(optarg); break;
    case 's': samples = TString(optarg); break;
    case 'v': verbose = atoi(optarg); break;
    case 'f': outputfile = TString(optarg); break;
    case 'n': neventperfile = atoi(optarg); break;
    case 'c': channel = TString(optarg); break;
    case '?':
    case 'h': usage(0,execname); break;
    default:
      cerr << "*** Error: unknown option " << optarg << std::endl;
      usage(-1 , execname);
    }
  }
	
  argc -= optind;
  argv += optind;

  // Check arguments
  if( argc>1 ) {
    usage(-1,execname );
  }

  cout << "--------------" << endl;
  cout << "OutputDir is:     " << outputdir << endl;
  cout << "Verbose level is: " << verbose << endl;
  cout << "Using sample file: " << samples << endl;
  cout << "nEventsPerFile is: " << neventperfile << endl;
  cout << "OutputFile is : " << outputfile << endl;
  cout << "--------------" << endl;

  MassPlotterSingleTop *tA = new MassPlotterSingleTop(outputdir);
  tA->setVerbose(verbose);
  tA->init(samples);



  TList allCuts;


  // ExtendedCut* TriggerCut = new ExtendedCut("Trigger" , "Event_passesHLT_IsoMu24_eta2p1_IterTrk02_v1 > 0.5 "  ,  true , true, "" , "" , true , true); 
  // allCuts.Add( TriggerCut );
  // ExtendedCut* MuonSelection = new ExtendedCut("MuonSelection" , "(Sum$(muons_Pt > 26 && abs(muons_Eta) < 2.1 && muons_IsTightMuon == 1 && muons_Iso04 < 0.12) == 1) && (Sum$(muons_Pt > 26 && abs(muons_Eta) < 2.1 && muons_IsTightMuon == 1) == 1)" ,  true , true, "" , "" , true , true); 
  // allCuts.Add( MuonSelection );
  // ExtendedCut* MuonVeto = new ExtendedCut("MuonVeto" , "(Sum$(muons_Pt > 10 && abs(muons_Eta) < 2.5 && muons_IsLooseMuon == 1 && muons_Iso04 < 0.2) == 1)"  ,  true , true, "" , "" , true , true); 
  // allCuts.Add( MuonVeto );
  // ExtendedCut* ElectronVeto = new ExtendedCut("ElectronVeto" , "(Sum$(electrons_Pt > 20 && abs(electrons_Eta) < 2.5 && (abs(electrons_Eta) < 1.4442 || abs(electrons_Eta) > 1.566) && electrons_isVeto == 1) == 0)"  ,  true , true, "" , "" , true , true); 
  // allCuts.Add( ElectronVeto );
  // ExtendedCut* JetSelection = new ExtendedCut("JetSelection" , " (Sum$(jetsAK4_Pt > 40 && abs(jetsAK4_Eta) < 4.7 && jetsAK4_IsLoose == 1 && jetsAK4_PassesDRtight == 1) == 2)"  ,  true , true, "" , "" , true , true); 
  // allCuts.Add( JetSelection );
  // ExtendedCut* bJetSelection = new ExtendedCut("bJet" , "(Sum$(jetsAK4_CSV > 0.941 && jetsAK4_Pt > 40 && abs(jetsAK4_Eta) < 2.4 && jetsAK4_IsLoose == 1 && jetsAK4_PassesDRtight == 1) == 1)"  ,  true , true, "" , "" , true , true); 
  // allCuts.Add( bJetSelection );

 
  tA->singleTopAnalysis(&allCuts, neventperfile ,  outputfile );

  delete tA;
  return 0;
}



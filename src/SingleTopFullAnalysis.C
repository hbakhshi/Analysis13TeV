// includes++ C
#include <stdexcept>
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
  cout << "Usage: "<< execname << " [-d dir] [-v verbose] [-s sample] [-n nEventPerFile] [-f Outputfile] [-a samplename] [-r From] [-t To]" << endl;
  cout << "  where:" << endl;
  cout << "     dir      is the output directory               " << endl;
  cout << "               default is ../MassPlots/             " << endl;
  cout << "     verbose  sets the verbose level                " << endl;
  cout << "               default is 0 (quiet mode)            " << endl;
  cout << "     sample   is the file with the list of samples" << endl;
  cout << "     nEventPerFile   is number of events per sample to be analyzed" << endl;
  cout << "     Outputfile   is the output file name" << endl;
  cout << "     SampleName   is the sample name to run over, default is all" << endl;
  cout << "     From   is the place to start from (in percent), default is 0.0" << endl;
  cout << "     To     is the place to end at (in percent), default is 100.0" << endl;
  cout << endl;
  exit(status);
}

class QCDFitTreeManager {
public:
  std::map<string , TTree*> trees;

  struct{
    float weight;
    float mtw;
    float met;
    bool data;
    bool qcd;
    bool isPositive;
  } info;
  

  QCDFitTreeManager(TDirectory* theFile){
    theFile->mkdir("Trees")->cd();

    trees["iso2j0t"] = new TTree("iso2j0t" , "iso2j0t");
    trees["iso2j1t"] = new TTree("iso2j1t" , "iso2j1t");
    trees["iso3j2t"] = new TTree("iso3j2t" , "iso3j2t");
    trees["iso3j1t"] = new TTree("iso3j1t" , "iso3j1t");

    trees["noniso2j0t"] = new TTree("noniso2j0t" , "noniso2j0t");
    trees["noniso2j1t"] = new TTree("noniso2j1t" , "noniso2j1t");
    trees["noniso3j2t"] = new TTree("noniso3j2t" , "noniso3j2t");
    trees["noniso3j1t"] = new TTree("noniso3j1t" , "noniso3j1t");

    for(auto tree : trees){
      //tree.second->Branch( "info" , &info , "weight:mtw:met:data/O:qcd" );
      tree.second->Branch( "weight" , &info.weight );
      tree.second->Branch( "mtw" , &info.mtw );
      tree.second->Branch( "met" , &info.met );
      tree.second->Branch( "data" , &info.data );
      tree.second->Branch( "qcd" , &info.qcd );
      tree.second->Branch( "isPositive" , &info.isPositive );
      tree.second->SetAutoSave(10000);
      //tree.second->AutoSave();
    }
  }

  void Fill(string channel ,
	    bool data,
	    bool qcd,
	    float weight,
	    float mtw,
	    float met,
	    bool isPositive){
    info.data = data;
    info.qcd = qcd ;
    info.weight = weight;
    info.mtw = mtw;
    info.met = met;
    info.isPositive = isPositive ;

    trees[channel]->Fill();
  }


};

class MassPlotterSingleTop : public BaseMassPlotter{
public:
  QCDFitTreeManager* trees;

  map<string, ExtendedObjectProperty*> iso2j0tprops;
  map<string, ExtendedObjectProperty*> iso2j1tprops;
  map<string, ExtendedObjectProperty*> iso3j1tprops;
  map<string, ExtendedObjectProperty*> iso3j2tprops;

  map<string, ExtendedObjectProperty*> noniso2j0tprops;
  map<string, ExtendedObjectProperty*> noniso2j1tprops;
  map<string, ExtendedObjectProperty*> noniso3j1tprops;
  map<string, ExtendedObjectProperty*> noniso3j2tprops;

  TopUtilities topUtils;
  int lumi;

  void Fill( vector<string> selections , string propname , double value , double weight );
  void AddProperty(string name , int nbins , double min , double max , vector<TString>* labels = NULL );
  void Write(TDirectory* theFile);
  MassPlotterSingleTop(TString outputdir, TDirectory* theFile);
  void singleTopAnalysis(Long64_t nevents , TString samplename , double from , double to);

private :
  map< string ,  map<string,ExtendedObjectProperty*>* > all_maps;
  
};

void MassPlotterSingleTop::Fill( vector<string> selections , string propname , double value , double weight ){
  for( auto selection : selections )
    all_maps[selection]->at( propname )->Fill( value , weight ) ;
  
}

void MassPlotterSingleTop::AddProperty(string name , int nbins , double min , double max , vector<TString>* labels ){

  for( auto collection : all_maps ){
    collection.second->insert( make_pair( name , new ExtendedObjectProperty(collection.first , name , "1" , nbins ,  min , max , "2", {}, labels ) ) ); 
  }
    
}

void MassPlotterSingleTop::Write(TDirectory* theFile){
  for( auto selection : all_maps ){
    TDirectory* dir = theFile->mkdir( selection.first.c_str() );
    for( auto prop : *(selection.second) )
      prop.second->Write( dir , lumi , false, false );
  }

}

MassPlotterSingleTop::MassPlotterSingleTop(TString outputdir, TDirectory* theFile) : BaseMassPlotter( outputdir ) {
  all_maps["iso2j0t"] = &iso2j0tprops ;
  all_maps["iso2j1t"] = &iso2j1tprops ;
  all_maps["iso3j2t"] = &iso3j2tprops ;
  all_maps["iso3j1t"] = &iso3j1tprops ;

  all_maps["noniso2j0t"] = &noniso2j0tprops ;
  all_maps["noniso2j1t"] = &noniso2j1tprops ;
  all_maps["noniso3j2t"] = &noniso3j2tprops ;
  all_maps["noniso3j1t"] = &noniso3j1tprops ;


  std::vector<TString> alllabels;
  alllabels.push_back( "NoCut" );
  alllabels.push_back( "Trigger" );
  alllabels.push_back( "Filter" );
  alllabels.push_back( "MuonSelection" );
  alllabels.push_back( "LooseMuonVeto" );
  alllabels.push_back( "ElectronVeto" );
  alllabels.push_back( "N-Jets" );
  alllabels.push_back( "N-bJet" );
  alllabels.push_back( "MT >50 GeV" );

  AddProperty("cft" , alllabels.size() ,  0 , alllabels.size() , &alllabels );
  AddProperty("cft_w1" , alllabels.size() ,  0 , alllabels.size() , &alllabels );

  AddProperty( "nPVBeforeCutsUnCorr",100 , 0 , 100 );
  AddProperty( "nPVBeforeCuts", 100 , 0 , 100 );
  AddProperty( "nPVAfterCutsUnCorr", 100 , 0 , 100 );
  AddProperty( "nPVAfterCuts", 100 , 0 , 100 );

  AddProperty( "muPt", 20 , 0 , 200 );
  AddProperty( "muEta", 11 , -2.1 , 2.1 );
  AddProperty( "muAbsEta", 10 , 0 , 2.5 );
  AddProperty( "MET", 20 , 0 , 200 );
  AddProperty( "MTBeforeCut", 30 , 0 , 300 );
  AddProperty( "MTAfterCut", 20 , 0 , 200 );
  AddProperty( "TopMass" , 30 , 100 , 400 );
  AddProperty( "jprimePt", 20 , 0 , 200 );
  AddProperty( "bPt",20 , 0 , 200 );
  AddProperty( "jprimeEta",10 , 0 , 5.0 );
  AddProperty( "bEta", 5 , 0 , 5.0 );

  AddProperty( "nbJets",3 , 0 , 3 );    
  AddProperty( "nJetsBeforeCut",8 , 0 , 8 );
  AddProperty( "muCharge", 40 , -2 , 2 );

  trees = new QCDFitTreeManager( theFile );
};


void MassPlotterSingleTop::singleTopAnalysis(Long64_t nevents , TString samplename , double from , double to){
  for(int ii = 0; ii < fSamples.size(); ii++){

    int data = 0;
    sample Sample = fSamples[ii];

    cout << Sample.name ;

    if( samplename != "all" )
      if( Sample.name != samplename ){
	cout << " is not selected to run over " << endl;
	continue;
      }
	 
    cout << " has been selected to run over." << endl;


    TEventList* list = 0;
   
    if(Sample.type == "data"){
      data = 1;
    }else
      lumi = Sample.lumi; 

    bool qcd = false;
    if( Sample.sname == "QCD1"){
      qcd = true;
    }
    cout << " sample data : " << data << " qcd : " << qcd << endl;
  
    double Weight = Sample.xsection * Sample.kfact * Sample.lumi / (Sample.nevents*Sample.PU_avg_weight);
    if(data == 1)
      Weight = 1.0;

    Sample.Print(Weight);

    SingleTopTree fTree( Sample.tree );
    Sample.tree->SetBranchStatus("*", 1);

    string lastFileName = "";
    Long64_t nentries =  Sample.tree->GetEntries();
    int counter = 0;

    Long64_t From( floor( (from/100.0)*nentries ) );
    Long64_t To( floor( (to/100.0)*nentries ) );
    Long64_t maxloop = min(To,abs(From+nevents));

    cout << "\t Loop over " << Sample.name << " from " << From << " To " << maxloop <<endl;

    for (Long64_t jentry=From; jentry<maxloop;jentry++, counter++) {
      Sample.tree->GetEntry(jentry);
      if( lastFileName.compare( ((TChain*)Sample.tree)->GetFile()->GetName() ) != 0 ) {
	for( auto mapentry : all_maps )
	  for( auto prop : *(mapentry.second) ){
	    prop.second->SetTree( Sample.tree , Sample.type, Sample.sname );
	  }

	lastFileName = ((TChain*)Sample.tree)->GetFile()->GetName() ;
      }

      if ( counter == 100000 ){  
	fprintf(stdout, "\rProcessed events: %6d of %6d from file %s", jentry + 1, nentries , lastFileName.c_str());
	fflush(stdout);
	counter = 0;
      }
    
    
      double weight = Weight;

      if( !data ){
	weight *= fTree.Event_puWeight ;
      }

      if( Sample.UseLHEWeight ){
	weight *= fTree.Event_LHEWeightSign ;
      }

      vector<string> allchannels = {  "iso2j0t", "iso2j1t" , "iso3j2t" , "iso3j1t" ,  "noniso2j0t", "noniso2j1t" , "noniso3j2t" , "noniso3j1t"};

      double cutindex = 0.5;
    
      Fill( allchannels , "cft" , cutindex , weight );
      Fill( allchannels , "cft_w1" , cutindex , 1.0 );
      cutindex += 1.0;
    
      Fill( {"iso2j1t"} ,  "nPVBeforeCutsUnCorr" , fTree.Event_nPV , weight/fTree.Event_puWeight );
      Fill( {"iso2j1t"} ,  "nPVBeforeCuts" , fTree.Event_nPV , weight );

      if( data && !(fTree.Event_passesHLT_IsoMu20_v2 > 0.5 || fTree.Event_passesHLT_IsoMu20_v1 > 0.5 || fTree.Event_passesHLT_IsoMu20_v3 > 0.5 || fTree.Event_passesHLT_IsoMu20_v4 > 0.5)  )
	continue;
      if(!data && !(fTree.Event_passesHLT_IsoMu20_v3 > 0.5) )
	continue;

      Fill( allchannels , "cft" , cutindex , weight );
      Fill( allchannels , "cft_w1" , cutindex , 1.0 );
      cutindex += 1.0 ;


      // vertex checking
      Fill( allchannels , "cft" , cutindex , weight );
      Fill( allchannels , "cft_w1" , cutindex , 1.0 );
      cutindex += 1.0 ;
    

      fTree.FillMuons();
      auto channel = allchannels.begin();

      if( fTree.TightIso06Muons.size() != 1  ){
	for( ; channel != allchannels.end() ;  ){
	  if( channel->substr(0 , 3) == "iso" )
	    channel = allchannels.erase( channel );
	  else
	    ++channel;
	}
      }else if(!data)
	weight *= fTree.GetMuSF() ;

      if( fTree.Tight12IsoMuons.size() != 1  )
	for(channel = allchannels.begin() ; channel != allchannels.end() ;  ){
	  if( channel->substr(0 , 6) == "noniso" )
	    channel = allchannels.erase( channel );
	  else
	    ++channel;
	}

      if(allchannels.size() == 0 )
	continue;
    
      Fill( allchannels , "cft" , cutindex , weight );
      Fill( allchannels , "cft_w1" , cutindex , 1.0 );
      cutindex += 1.0 ;


      if( fTree.LooseMuonsSignal.size() != 0  )
	for(channel = allchannels.begin() ; channel != allchannels.end() ;  ){
	  if( channel->substr(0 , 3) == "iso" )
	    channel = allchannels.erase( channel );
	  else
	    ++channel;
	}

      if( fTree.LooseMuonsQCD.size() != 0  )
	for(channel = allchannels.begin() ; channel != allchannels.end() ;  ){
	  if( channel->substr(0 , 6) == "noniso" )
	    channel = allchannels.erase( channel );
	  else
	    ++channel;
	}

      if(allchannels.size() == 0 )
	continue;

      if( allchannels.size() > 4 )
	throw logic_error("inconsistent number of muons");

      int tightMuIndex = fTree.TightIso06Muons.size() == 1 ? fTree.TightIso06Muons[0] : 
	(fTree.Tight12IsoMuons.size() == 1 ? fTree.Tight12IsoMuons[0] : -1 ) ;
      if( tightMuIndex < 0 )
	throw logic_error("inconsistent number of tight muons");

      bool IsQCD = (allchannels[0].substr(0,6)=="noniso") ;

      Fill( allchannels , "cft" , cutindex , weight );
      Fill( allchannels , "cft_w1" , cutindex , 1.0 );
      cutindex += 1.0 ;
    

      fTree.FillElectrons();
      if( fTree.VetoElectrons.size() > 0 )
	continue;

      Fill( allchannels , "cft" , cutindex , weight );
      Fill( allchannels , "cft_w1" , cutindex , 1.0 );
      cutindex += 1.0 ;

      fTree.FillJets();
    
      int nJets = fTree.Jets.size();
      Fill( allchannels, "nJetsBeforeCut" , nJets , weight );
      string njformat( TString::Format("%dj" , nJets ).Data() );

      for(channel = allchannels.begin() ; channel != allchannels.end() ;  ){
	if( channel->find(njformat) == string::npos  )
	  channel = allchannels.erase( channel );
	else
	  ++channel;
      }

      if( allchannels.size() == 0 )
	continue;

      // if( !IsQCD && nJets == 2 ){
      // 	cout << "\t" << fTree.Event_EventNumber << ",\t" << fTree.Event_RunNumber << ",\t" << fTree.Event_LumiBlock << endl;
      // }

      Fill( allchannels , "cft" , cutindex , weight );
      Fill( allchannels , "cft_w1" , cutindex , 1.0 );
      cutindex += 1.0 ;
      

      int howManyBJets = fTree.bJets.size() ;
      Fill( allchannels , "nbJets" , howManyBJets  , weight );
      string nbjformat( TString::Format("%dt" , howManyBJets ).Data() );

      for(channel = allchannels.begin() ; channel != allchannels.end() ;  ){
	if( channel->find(nbjformat) == string::npos )
	  channel = allchannels.erase( channel );
	else
	  ++channel;
      }

      if( allchannels.size() == 0 )
	continue;
      
      if( allchannels.size() > 1 ){
	cout << " more than one channel : " ;
	for ( auto channel : allchannels )
	  cout << channel << "," ;
	cout << endl;
	throw logic_error("inconsistent number of channels");
      }
      
      if( !data ){
	if( howManyBJets == 2 )
	  weight *= fTree.Event_bWeight2CSVT ;
	else if (howManyBJets == 1 )
	  weight *= fTree.Event_bWeight1CSVT ;
	else if (howManyBJets == 0 )
	  weight *= fTree.Event_bWeight0CSVT ;
      }

      Fill( allchannels , "cft" , cutindex , weight );
      Fill( allchannels , "cft_w1" , cutindex , 1.0 );
      cutindex += 1.0 ;
     
      double MT = sqrt( 2*fTree.met_Pt* fTree.muons_Pt[tightMuIndex]*(1-TMath::Cos( Util::DeltaPhi(fTree.met_Phi , fTree.muons_Phi[tightMuIndex]) ) )  ) ;
      Fill( allchannels , "MTBeforeCut" ,  MT , weight );

      trees->Fill(allchannels[0] ,data,qcd,weight,MT,fTree.met_Pt , fTree.muons_Charge[tightMuIndex]>0.0 );

      if( MT > 50 ){
	Fill( allchannels , "cft" , cutindex , weight );
	Fill( allchannels , "cft_w1" , cutindex , 1.0 );
	cutindex += 1.0 ;
      }else if( nJets == 2 && howManyBJets == 1 )
	continue;
    
      TLorentzVector muLV;
      muLV.SetPtEtaPhiE( fTree.muons_Pt[tightMuIndex] , fTree.muons_Eta[tightMuIndex] , fTree.muons_Phi[ tightMuIndex ] , fTree.muons_E[tightMuIndex] );

      int bjIndex = -1;
      int jprimeIndex = fTree.Jets[0];
    
   
      switch( howManyBJets ){
      case 0:
	for( auto jindex : fTree.Jets )
	  if( fabs(fTree.jetsAK4_Eta[jprimeIndex]) < fabs(fTree.jetsAK4_Eta[jindex]) )
	    jprimeIndex = jindex ;

	bjIndex = fTree.Jets[0]==jprimeIndex ? fTree.Jets[1] : fTree.Jets[0] ;
	break;
      case 1:
	bjIndex = fTree.bJets[0] ;
	if( bjIndex == jprimeIndex )
	  jprimeIndex = fTree.Jets[1];
	break;
      case 2:
	bjIndex = fTree.bJets[0] ;
	if( fTree.jetsAK4_CSVv2[ fTree.bJets[1] ] > fTree.jetsAK4_CSVv2[bjIndex] )
	  bjIndex = fTree.bJets[1];

	vector<int> diff;
	std::set_difference( fTree.Jets.begin() , fTree.Jets.end() , fTree.bJets.begin() , fTree.bJets.end() , std::inserter(diff, diff.begin()) );
	jprimeIndex = diff[0];
	
	if(diff.size() != 1)
	  throw logic_error("in 3j2t, the indices of jets and bjets are not consistent.");

	break;
      }

      TLorentzVector bjetLV;
      bjetLV.SetPtEtaPhiE( fTree.jetsAK4_CorrPt[ bjIndex ] , fTree.jetsAK4_Eta[ bjIndex ] , fTree.jetsAK4_Phi[ bjIndex ] , fTree.jetsAK4_CorrE[ bjIndex ] ) ; 
      double topMass = topUtils.top4Momentum( muLV , bjetLV , fTree.met_Px , fTree.met_Py ).mass();
      Fill( allchannels, "TopMass" , topMass , weight );

      Fill( allchannels , "nPVAfterCutsUnCorr" , fTree.Event_nPV , weight/fTree.Event_puWeight );
      Fill( allchannels , "nPVAfterCuts" , fTree.Event_nPV , weight );
    
      Fill( allchannels , "jprimeEta", fabs( fTree.jetsAK4_Eta[jprimeIndex] ) , weight );
      Fill( allchannels , "jprimePt", fTree.jetsAK4_CorrPt[jprimeIndex] , weight );
      Fill( allchannels , "muPt", fTree.muons_Pt[tightMuIndex] , weight );
      Fill( allchannels , "muCharge", fTree.muons_Charge[tightMuIndex] , weight );
      Fill( allchannels , "muEta", fTree.muons_Eta[tightMuIndex] , weight);
      Fill( allchannels , "muAbsEta", fabs( fTree.muons_Eta[tightMuIndex] ) , weight);
      Fill( allchannels , "MET",  fTree.met_Pt , weight );
      Fill( allchannels , "MTAfterCut" ,  MT , weight );
      Fill( allchannels , "bPt", fTree.jetsAK4_CorrPt[bjIndex] , weight );
      Fill( allchannels , "bEta",fabs( fTree.jetsAK4_Eta[bjIndex] ) , weight );
    }
  }
}

//_____________________________________________________________________________________
int main(int argc, char* argv[]) {
  TString execname = TString(argv[0]);
  // Default options
  TString outputfile = "EleTau_Signal_METBJetsCuts"; 
  TString outputdir = "./MassPlots/";
  TString samples = "./samples/samplesMineTauPlusX.dat";
  TString sampleToRun = "all";
  double From = 0.0;
  double To = 100.0;
  TString channel = "etau";
  Long64_t neventperfile = LONG_MAX;
  int verbose = 0;

  // Parse options
  char ch;
  while ((ch = getopt(argc, argv, "n:p:t:c:f:d:v:s:a:r:t:lh?")) != -1 ) {
    switch (ch) {
    case 'd': outputdir = TString(optarg); break;
    case 's': samples = TString(optarg); break;
    case 'v': verbose = atoi(optarg); break;
    case 'f': outputfile = TString(optarg); break;
    case 'n': neventperfile = atoi(optarg); break;
    case 'c': channel = TString(optarg); break;
    case 'a': sampleToRun = TString(optarg); break;
    case 'r': From = atof(optarg); break;
    case 't': To = atof(optarg); break;
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
  cout << "SampleToRun over is : " << sampleToRun << endl;
  cout << "From : " << From << " To : " << To << endl;
  cout << "--------------" << endl;


  TString fileName = outputdir;
  if(!fileName.EndsWith("/")) fileName += "/";
  Util::MakeOutputDir(fileName);
  fileName += outputfile + ".root" ;

  TFile *theFile = new TFile(fileName.Data(), "RECREATE");

  MassPlotterSingleTop *tA = new MassPlotterSingleTop(outputdir , theFile);
  tA->setVerbose(verbose);
  tA->init(samples , sampleToRun );
  
  tA->singleTopAnalysis( neventperfile , sampleToRun , From , To );
  tA->Write( theFile );

  theFile->Write();
  theFile->Close();

  delete tA;
  return 0;
}



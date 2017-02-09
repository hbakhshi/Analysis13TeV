#define SingleTopTree_cxx
#include "SingleTopTree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

#include <TLorentzVector.h>
#include <iostream>

using namespace std;

SingleTopTree::SingleTopTree(TTree *tree) : fChain(0) 
					  , hMuSFID(NULL)
{
   Init(tree);
}


double SingleTopTree::GetMuSF(){
  if( hMuSFID == NULL){
    TFile* f0 = TFile::Open("samples25ns/SFs/ScaleFactors.root");
    f0->ls();
    gROOT->cd();
    hMuSFIso = (TH2*)( f0->Get("SFIso")->Clone("MuSFIso") );
    hMuSFTrg = (TH2*)( f0->Get("SFTrigger_Weighted")->Clone("SFTrigger") );
    f0->Close();

    TFile* f1 = TFile::Open("samples25ns/SFs/MuonID_Z_RunCD_Reco76X_Feb15.root");
    f1->ls();
    gROOT->cd();
    hMuSFID = (TH2*)( f1->Get("MC_NUM_TightIDandIPCut_DEN_genTracks_PAR_pt_spliteta_bin1/pt_abseta_ratio")->Clone("MuSFID") );
    f1->Close();

    cout << "here are all the muon scale factors " << endl;
    hMuSFID->Print("ALL");
    hMuSFIso->Print("ALL");
    hMuSFTrg->Print("ALL");
  }

  int bin = hMuSFIso->FindBin( muons_Pt[ TightIso06Muons[0] ] , fabs( muons_Eta[ TightIso06Muons[0] ] ) );
  return ( hMuSFIso->GetBinContent( bin )*hMuSFID->GetBinContent( bin )*hMuSFTrg->GetBinContent( bin ) );
}

void SingleTopTree::FillMuons(){
  TightIso06Muons.clear();
  TightIso12Muons.clear();
  Tight12IsoMuons.clear();
  LooseMuonsQCD.clear();
  LooseMuonsSignal.clear();
  LooseMuonsIntermediate.clear();

  for( int imu=0 ; imu < muons_size ; imu++ ){
    
    bool isSignal = false;
    bool isQCD = false;
    bool isIntermediate = false;
    if( muons_Pt[imu] > 22.0 &&
	fabs(muons_Eta[imu]) < 2.1 &&
	muons_IsTightMuon[imu] > 0.5 ){
      
      if( muons_Iso04[imu] < 0.06 ){ 
	TightIso06Muons.push_back( imu );
	isSignal = true;
      }
      else if( muons_Iso04[imu] > 0.12 ){
	Tight12IsoMuons.push_back( imu );
	isQCD = true;
      }
      else{
	TightIso12Muons.push_back( imu );
	isIntermediate = true;
      }
    }

    if( muons_Pt[ imu ] > 10.0 &&
	muons_IsLooseMuon[ imu ] > 0.5 &&
	fabs(muons_Eta[imu]) < 2.5 && 
	muons_Iso04[imu] < 0.20 ){
      if( !isQCD )
	LooseMuonsQCD.push_back( imu );
      if( !isSignal )
	LooseMuonsSignal.push_back( imu );
      if( !isIntermediate )
	LooseMuonsIntermediate.push_back(imu);
    }
  }      
}

void SingleTopTree::FillElectrons(){
  VetoElectrons.clear();

  for( int iele = 0 ; iele < electrons_size;iele ++ ){
    if( electrons_Pt[iele] > 20 &&
	fabs(electrons_Eta[iele]) < 2.5 && 
	( fabs(electrons_Eta[iele]) < 1.4442 || fabs(electrons_Eta[iele]) > 1.566) &&
	electrons_vidVeto[iele] > 0.5 )
      VetoElectrons.push_back( iele );
  }
}

void SingleTopTree::FillJets(){
  Jets.clear();
  bJets.clear();

  TLorentzVector muon;
  int tightMuIndex;
  bool mu = TightIso06Muons.size() > 0;
  
  if( mu )
    tightMuIndex = TightIso06Muons[0] ;
  if(!mu){
    mu = Tight12IsoMuons.size() > 0 ;
    if( mu )
      tightMuIndex = Tight12IsoMuons[0] ;
  }
  if(!mu){
    mu = TightIso12Muons.size() > 0 ;
    if( mu )
      tightMuIndex = TightIso12Muons[0] ;
  }
  muon.SetPtEtaPhiE( muons_Pt[tightMuIndex] , muons_Eta[tightMuIndex] , muons_Phi[tightMuIndex] , muons_E[tightMuIndex] );

  for( int jid = 0 ; jid < jetsAK4_size ; jid++ ){

    //if( Event_EventNumber == 672782113 ) cout << (jetsAK4_CorrPt[jid] > 40) << " " <<  (fabs( jetsAK4_Eta[jid] ) < 4.7) << " " << jetsAK4_PassesID[jid];

    if( jetsAK4_CorrPt[jid] > 40 &&
	fabs( jetsAK4_Eta[jid] ) < 4.7 &&
	jetsAK4_PassesID[jid]
	){

      double DR = 1.0 ; 
      if( mu ){
	TLorentzVector jet;
	jet.SetPtEtaPhiE( jetsAK4_CorrPt[jid] , jetsAK4_Eta[jid] , jetsAK4_Phi[jid] , jetsAK4_CorrE[jid] );
	DR = muon.DeltaR( jet );
      }

      // if( Event_EventNumber == 672782113 )
      // 	cout << DR << endl;

      if ( DR > 0.3 ){
	Jets.push_back( jid );
	if( jetsAK4_IsCSVT[jid]  && fabs( jetsAK4_Eta[jid] ) <= 2.4 ){
	  bJets.push_back(jid);
	}
      }
    }
      //if( Event_EventNumber == 672782113 )
      //cout << endl;
  }
}

void SingleTopTree::ProcessEvent(){
}


void SingleTopTree::Loop()
{
//   In a ROOT session, you can do:
//      root> .L SingleTopTree.C
//      root> SingleTopTree t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
   }
}

#ifdef SingleTopTreeLHEWeights_h
Float_t SingleTopTree::GetPDFWeight(int i){
  Float_t* first = &( this->Event_LHEWeight9 );
  return *( first + i );
}
Float_t SingleTopTree::GetLHEWeight(int i){
  Float_t* first = &( this->Event_LHEWeight0 );
  return *( first + i );
}

#endif

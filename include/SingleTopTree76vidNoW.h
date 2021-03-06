//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Feb 19 09:25:34 2016 by ROOT version 6.02/05
// from TTree ttDM__noSyst/ttDM__noSyst
// found on file: Synchronization_76X_SingleMu.root
//////////////////////////////////////////////////////////

#ifndef SingleTopTree_h
#define SingleTopTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include <vector>
#include "TH2.h"
using namespace std;
// Header file for the classes stored in the TTree if any.

class SingleTopTree {
public :

  TH2* hMuSFID;
  TH2* hMuSFIso;
  TH2* hMuSFTrg;
  double GetMuSF();

  vector<int> TightIso06Muons;
  vector<int> TightIso12Muons;
  vector<int> Tight12IsoMuons;
  vector<int> LooseMuonsQCD;
  vector<int> LooseMuonsSignal;
  vector<int> LooseMuonsIntermediate;
  vector<int> VetoElectrons;
  vector<int> Jets;
  vector<int> bJets;

  void FillMuons();
  void FillElectrons();
  void FillJets();
  void ProcessEvent();
  

   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Float_t         met_Pt;
   Float_t         met_Phi;
   Float_t         met_Px;
   Float_t         met_Py;
   Float_t         met_uncorPhi;
   Float_t         met_uncorPt;
   Float_t         met_uncorSumEt;
   Float_t         met_CorrPt;
   Float_t         met_CorrPhi;
   Int_t           met_size;
   Float_t         muons_E[10];
   Float_t         muons_Pt[10];
   Float_t         muons_Eta[10];
   Float_t         muons_Phi[10];
   Float_t         muons_Charge[10];
   Float_t         muons_IsLooseMuon[10];
   Float_t         muons_IsTightMuon[10];
   Float_t         muons_Iso04[10];
   Int_t           muons_size;
   Float_t         electrons_E[10];
   Float_t         electrons_Pt[10];
   Float_t         electrons_Phi[10];
   Float_t         electrons_Eta[10];
   Float_t         electrons_Iso03[10];
   Float_t         electrons_vidHEEP[10];
   Float_t         electrons_vidLoose[10];
   Float_t         electrons_vidMedium[10];
   Float_t         electrons_vidTight[10];
   Float_t         electrons_vidVeto[10];
   Int_t           electrons_size;
   Float_t         jetsAK4_E[20];
   Float_t         jetsAK4_Pt[20];
   Float_t         jetsAK4_Eta[20];
   Float_t         jetsAK4_PartonFlavour[20];
   Float_t         jetsAK4_Phi[20];
   Float_t         jetsAK4_CSVv2[20];
   Float_t         jetsAK4_GenJetEta[20];
   Float_t         jetsAK4_GenJetPt[20];
   Float_t         jetsAK4_CorrPt[20];
   Float_t         jetsAK4_CorrE[20];
   Float_t         jetsAK4_MinDR[20];
   Float_t         jetsAK4_IsCSVT[20];
   Float_t         jetsAK4_IsCSVM[20];
   Float_t         jetsAK4_IsCSVL[20];
   Float_t         jetsAK4_PassesID[20];
   Float_t         jetsAK4_PassesDR[20];
   Float_t         jetsAK4_PassesDRtight[20];
   Float_t         jetsAK4_CorrMass[20];
   Float_t         jetsAK4_IsTight[20];
   Float_t         jetsAK4_IsLoose[20];
   Float_t         jetsAK4_JetID_numberOfDaughters[20];
   Float_t         jetsAK4_JetID_muonEnergyFraction[20];
   Float_t         jetsAK4_JetID_chargedMultiplicity[20];
   Float_t         jetsAK4_JetID_chargedHadronEnergyFraction[20];
   Float_t         jetsAK4_JetID_chargedEmEnergyFraction[20];
   Float_t         jetsAK4_JetID_neutralEmEnergyFraction[20];
   Float_t         jetsAK4_JetID_neutralHadronEnergyFraction[20];
   Float_t         jetsAK4_JetID_neutralMultiplicity[20];
   Int_t           jetsAK4_size;
   Float_t         Event_nTightMuons;
   Float_t         Event_nSoftMuons;
   Float_t         Event_nLooseMuons;
   Float_t         Event_nTightElectrons;
   Float_t         Event_nMediumElectrons;
   Float_t         Event_nLooseElectrons;
   Float_t         Event_nVetoElectrons;
   Float_t         Event_bWeight0CSVT;
   Float_t         Event_bWeight1CSVT;
   Float_t         Event_bWeight2CSVT;
   Float_t         Event_bWeight0CSVM;
   Float_t         Event_bWeight1CSVM;
   Float_t         Event_bWeight2CSVM;
   Float_t         Event_bWeight0CSVL;
   Float_t         Event_bWeight1CSVL;
   Float_t         Event_bWeight2CSVL;
   Float_t         Event_bWeightMisTagDown0CSVT;
   Float_t         Event_bWeightMisTagDown1CSVT;
   Float_t         Event_bWeightMisTagDown2CSVT;
   Float_t         Event_bWeightMisTagDown0CSVM;
   Float_t         Event_bWeightMisTagDown1CSVM;
   Float_t         Event_bWeightMisTagDown2CSVM;
   Float_t         Event_bWeightMisTagDown0CSVL;
   Float_t         Event_bWeightMisTagDown1CSVL;
   Float_t         Event_bWeightMisTagDown2CSVL;
   Float_t         Event_bWeightMisTagUp0CSVT;
   Float_t         Event_bWeightMisTagUp1CSVT;
   Float_t         Event_bWeightMisTagUp2CSVT;
   Float_t         Event_bWeightMisTagUp0CSVM;
   Float_t         Event_bWeightMisTagUp1CSVM;
   Float_t         Event_bWeightMisTagUp2CSVM;
   Float_t         Event_bWeightMisTagUp0CSVL;
   Float_t         Event_bWeightMisTagUp1CSVL;
   Float_t         Event_bWeightMisTagUp2CSVL;
   Float_t         Event_bWeightBTagUp0CSVT;
   Float_t         Event_bWeightBTagUp1CSVT;
   Float_t         Event_bWeightBTagUp2CSVT;
   Float_t         Event_bWeightBTagUp0CSVM;
   Float_t         Event_bWeightBTagUp1CSVM;
   Float_t         Event_bWeightBTagUp2CSVM;
   Float_t         Event_bWeightBTagUp0CSVL;
   Float_t         Event_bWeightBTagUp1CSVL;
   Float_t         Event_bWeightBTagUp2CSVL;
   Float_t         Event_bWeightBTagDown0CSVT;
   Float_t         Event_bWeightBTagDown1CSVT;
   Float_t         Event_bWeightBTagDown2CSVT;
   Float_t         Event_bWeightBTagDown0CSVM;
   Float_t         Event_bWeightBTagDown1CSVM;
   Float_t         Event_bWeightBTagDown2CSVM;
   Float_t         Event_bWeightBTagDown0CSVL;
   Float_t         Event_bWeightBTagDown1CSVL;
   Float_t         Event_bWeightBTagDown2CSVL;
   Float_t         Event_LHEWeightSign;
   Float_t         Event_LHEWeight;
   Int_t           Event_EventNumber;
   Float_t         Event_LumiBlock;
   Float_t         Event_RunNumber;
   Float_t         Event_mu_eff;
   Float_t         Event_mu_eff_up;
   Float_t         Event_mu_eff_down;
   Float_t         Event_nPV;
   Float_t         Event_nGoodPV;
   Float_t         Event_passesFlag_CSCTightHaloFilter;
   Float_t         Event_passesFlag_goodVertices;
   Float_t         Event_passesFlag_eeBadScFilter;
   Float_t         Event_passesMETFilters;
   Float_t         Event_passesHBHE;
   Float_t         Event_passesHLT_IsoMu20_v1;
   Float_t         Event_prescaleHLT_IsoMu20_v1;
   Float_t         Event_passesHLT_IsoMu20_v2;
   Float_t         Event_prescaleHLT_IsoMu20_v2;
   Float_t         Event_passesHLT_IsoMu20_v3;
   Float_t         Event_prescaleHLT_IsoMu20_v3;
   Float_t         Event_passesHLT_IsoMu20_v4;
   Float_t         Event_prescaleHLT_IsoMu20_v4;
   Float_t         Event_passesLeptonicTriggers;
   Float_t         Event_passesHadronicTriggers;
   Float_t         Event_puWeight;
   Float_t         Event_puWeightUp;
   Float_t         Event_puWeightDown;
   Float_t         Event_nTruePU;

   // List of branches
   TBranch        *b_met_Pt;   //!
   TBranch        *b_met_Phi;   //!
   TBranch        *b_met_Px;   //!
   TBranch        *b_met_Py;   //!
   TBranch        *b_met_uncorPhi;   //!
   TBranch        *b_met_uncorPt;   //!
   TBranch        *b_met_uncorSumEt;   //!
   TBranch        *b_met_CorrPt;   //!
   TBranch        *b_met_CorrPhi;   //!
   TBranch        *b_met_size;   //!
   TBranch        *b_muons_E;   //!
   TBranch        *b_muons_Pt;   //!
   TBranch        *b_muons_Eta;   //!
   TBranch        *b_muons_Phi;   //!
   TBranch        *b_muons_Charge;   //!
   TBranch        *b_muons_IsLooseMuon;   //!
   TBranch        *b_muons_IsTightMuon;   //!
   TBranch        *b_muons_Iso04;   //!
   TBranch        *b_muons_size;   //!
   TBranch        *b_electrons_E;   //!
   TBranch        *b_electrons_Pt;   //!
   TBranch        *b_electrons_Phi;   //!
   TBranch        *b_electrons_Eta;   //!
   TBranch        *b_electrons_Iso03;   //!
   TBranch        *b_electrons_vidHEEP;   //!
   TBranch        *b_electrons_vidLoose;   //!
   TBranch        *b_electrons_vidMedium;   //!
   TBranch        *b_electrons_vidTight;   //!
   TBranch        *b_electrons_vidVeto;   //!
   TBranch        *b_electrons_size;   //!
   TBranch        *b_jetsAK4_E;   //!
   TBranch        *b_jetsAK4_Pt;   //!
   TBranch        *b_jetsAK4_Eta;   //!
   TBranch        *b_jetsAK4_PartonFlavour;   //!
   TBranch        *b_jetsAK4_Phi;   //!
   TBranch        *b_jetsAK4_CSVv2;   //!
   TBranch        *b_jetsAK4_GenJetEta;   //!
   TBranch        *b_jetsAK4_GenJetPt;   //!
   TBranch        *b_jetsAK4_CorrPt;   //!
   TBranch        *b_jetsAK4_CorrE;   //!
   TBranch        *b_jetsAK4_MinDR;   //!
   TBranch        *b_jetsAK4_IsCSVT;   //!
   TBranch        *b_jetsAK4_IsCSVM;   //!
   TBranch        *b_jetsAK4_IsCSVL;   //!
   TBranch        *b_jetsAK4_PassesID;   //!
   TBranch        *b_jetsAK4_PassesDR;   //!
   TBranch        *b_jetsAK4_PassesDRtight;   //!
   TBranch        *b_jetsAK4_CorrMass;   //!
   TBranch        *b_jetsAK4_IsTight;   //!
   TBranch        *b_jetsAK4_IsLoose;   //!
   TBranch        *b_jetsAK4_JetID_numberOfDaughters;   //!
   TBranch        *b_jetsAK4_JetID_muonEnergyFraction;   //!
   TBranch        *b_jetsAK4_JetID_chargedMultiplicity;   //!
   TBranch        *b_jetsAK4_JetID_chargedHadronEnergyFraction;   //!
   TBranch        *b_jetsAK4_JetID_chargedEmEnergyFraction;   //!
   TBranch        *b_jetsAK4_JetID_neutralEmEnergyFraction;   //!
   TBranch        *b_jetsAK4_JetID_neutralHadronEnergyFraction;   //!
   TBranch        *b_jetsAK4_JetID_neutralMultiplicity;   //!
   TBranch        *b_jetsAK4_size;   //!
   TBranch        *b_Event_nTightMuons;   //!
   TBranch        *b_Event_nSoftMuons;   //!
   TBranch        *b_Event_nLooseMuons;   //!
   TBranch        *b_Event_nTightElectrons;   //!
   TBranch        *b_Event_nMediumElectrons;   //!
   TBranch        *b_Event_nLooseElectrons;   //!
   TBranch        *b_Event_nVetoElectrons;   //!
   TBranch        *b_Event_bWeight0CSVT;   //!
   TBranch        *b_Event_bWeight1CSVT;   //!
   TBranch        *b_Event_bWeight2CSVT;   //!
   TBranch        *b_Event_bWeight0CSVM;   //!
   TBranch        *b_Event_bWeight1CSVM;   //!
   TBranch        *b_Event_bWeight2CSVM;   //!
   TBranch        *b_Event_bWeight0CSVL;   //!
   TBranch        *b_Event_bWeight1CSVL;   //!
   TBranch        *b_Event_bWeight2CSVL;   //!
   TBranch        *b_Event_bWeightMisTagDown0CSVT;   //!
   TBranch        *b_Event_bWeightMisTagDown1CSVT;   //!
   TBranch        *b_Event_bWeightMisTagDown2CSVT;   //!
   TBranch        *b_Event_bWeightMisTagDown0CSVM;   //!
   TBranch        *b_Event_bWeightMisTagDown1CSVM;   //!
   TBranch        *b_Event_bWeightMisTagDown2CSVM;   //!
   TBranch        *b_Event_bWeightMisTagDown0CSVL;   //!
   TBranch        *b_Event_bWeightMisTagDown1CSVL;   //!
   TBranch        *b_Event_bWeightMisTagDown2CSVL;   //!
   TBranch        *b_Event_bWeightMisTagUp0CSVT;   //!
   TBranch        *b_Event_bWeightMisTagUp1CSVT;   //!
   TBranch        *b_Event_bWeightMisTagUp2CSVT;   //!
   TBranch        *b_Event_bWeightMisTagUp0CSVM;   //!
   TBranch        *b_Event_bWeightMisTagUp1CSVM;   //!
   TBranch        *b_Event_bWeightMisTagUp2CSVM;   //!
   TBranch        *b_Event_bWeightMisTagUp0CSVL;   //!
   TBranch        *b_Event_bWeightMisTagUp1CSVL;   //!
   TBranch        *b_Event_bWeightMisTagUp2CSVL;   //!
   TBranch        *b_Event_bWeightBTagUp0CSVT;   //!
   TBranch        *b_Event_bWeightBTagUp1CSVT;   //!
   TBranch        *b_Event_bWeightBTagUp2CSVT;   //!
   TBranch        *b_Event_bWeightBTagUp0CSVM;   //!
   TBranch        *b_Event_bWeightBTagUp1CSVM;   //!
   TBranch        *b_Event_bWeightBTagUp2CSVM;   //!
   TBranch        *b_Event_bWeightBTagUp0CSVL;   //!
   TBranch        *b_Event_bWeightBTagUp1CSVL;   //!
   TBranch        *b_Event_bWeightBTagUp2CSVL;   //!
   TBranch        *b_Event_bWeightBTagDown0CSVT;   //!
   TBranch        *b_Event_bWeightBTagDown1CSVT;   //!
   TBranch        *b_Event_bWeightBTagDown2CSVT;   //!
   TBranch        *b_Event_bWeightBTagDown0CSVM;   //!
   TBranch        *b_Event_bWeightBTagDown1CSVM;   //!
   TBranch        *b_Event_bWeightBTagDown2CSVM;   //!
   TBranch        *b_Event_bWeightBTagDown0CSVL;   //!
   TBranch        *b_Event_bWeightBTagDown1CSVL;   //!
   TBranch        *b_Event_bWeightBTagDown2CSVL;   //!
   TBranch        *b_Event_LHEWeightSign;   //!
   TBranch        *b_Event_LHEWeight;   //!
   TBranch        *b_Event_EventNumber;   //!
   TBranch        *b_Event_LumiBlock;   //!
   TBranch        *b_Event_RunNumber;   //!
   TBranch        *b_Event_mu_eff;   //!
   TBranch        *b_Event_mu_eff_up;   //!
   TBranch        *b_Event_mu_eff_down;   //!
   TBranch        *b_Event_nPV;   //!
   TBranch        *b_Event_nGoodPV;   //!
   TBranch        *b_Event_passesFlag_CSCTightHaloFilter;   //!
   TBranch        *b_Event_passesFlag_goodVertices;   //!
   TBranch        *b_Event_passesFlag_eeBadScFilter;   //!
   TBranch        *b_Event_passesMETFilters;   //!
   TBranch        *b_Event_passesHBHE;   //!
   TBranch        *b_Event_passesHLT_IsoMu20_v1;   //!
   TBranch        *b_Event_prescaleHLT_IsoMu20_v1;   //!
   TBranch        *b_Event_passesHLT_IsoMu20_v2;   //!
   TBranch        *b_Event_prescaleHLT_IsoMu20_v2;   //!
   TBranch        *b_Event_passesHLT_IsoMu20_v3;   //!
   TBranch        *b_Event_prescaleHLT_IsoMu20_v3;   //!
   TBranch        *b_Event_passesHLT_IsoMu20_v4;   //!
   TBranch        *b_Event_prescaleHLT_IsoMu20_v4;   //!
   TBranch        *b_Event_passesLeptonicTriggers;   //!
   TBranch        *b_Event_passesHadronicTriggers;   //!
   TBranch        *b_Event_puWeight;   //!
   TBranch        *b_Event_puWeightUp;   //!
   TBranch        *b_Event_puWeightDown;   //!
   TBranch        *b_Event_nTruePU;   //!

   SingleTopTree(TTree *tree=0);
   virtual ~SingleTopTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef SingleTopTree_cxx
SingleTopTree::~SingleTopTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t SingleTopTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t SingleTopTree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void SingleTopTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("met_Pt", &met_Pt, &b_met_Pt);
   fChain->SetBranchAddress("met_Phi", &met_Phi, &b_met_Phi);
   fChain->SetBranchAddress("met_Px", &met_Px, &b_met_Px);
   fChain->SetBranchAddress("met_Py", &met_Py, &b_met_Py);
   fChain->SetBranchAddress("met_uncorPhi", &met_uncorPhi, &b_met_uncorPhi);
   fChain->SetBranchAddress("met_uncorPt", &met_uncorPt, &b_met_uncorPt);
   fChain->SetBranchAddress("met_uncorSumEt", &met_uncorSumEt, &b_met_uncorSumEt);
   fChain->SetBranchAddress("met_CorrPt", &met_CorrPt, &b_met_CorrPt);
   fChain->SetBranchAddress("met_CorrPhi", &met_CorrPhi, &b_met_CorrPhi);
   fChain->SetBranchAddress("met_size", &met_size, &b_met_size);
   fChain->SetBranchAddress("muons_E", muons_E, &b_muons_E);
   fChain->SetBranchAddress("muons_Pt", muons_Pt, &b_muons_Pt);
   fChain->SetBranchAddress("muons_Eta", muons_Eta, &b_muons_Eta);
   fChain->SetBranchAddress("muons_Phi", muons_Phi, &b_muons_Phi);
   fChain->SetBranchAddress("muons_Charge", muons_Charge, &b_muons_Charge);
   fChain->SetBranchAddress("muons_IsLooseMuon", muons_IsLooseMuon, &b_muons_IsLooseMuon);
   fChain->SetBranchAddress("muons_IsTightMuon", muons_IsTightMuon, &b_muons_IsTightMuon);
   fChain->SetBranchAddress("muons_Iso04", muons_Iso04, &b_muons_Iso04);
   fChain->SetBranchAddress("muons_size", &muons_size, &b_muons_size);
   fChain->SetBranchAddress("electrons_E", electrons_E, &b_electrons_E);
   fChain->SetBranchAddress("electrons_Pt", electrons_Pt, &b_electrons_Pt);
   fChain->SetBranchAddress("electrons_Eta", electrons_Eta, &b_electrons_Eta);
   fChain->SetBranchAddress("electrons_Phi", electrons_Phi, &b_electrons_Phi);
//    fChain->SetBranchAddress("electrons_Eta", electrons_Eta, &b_electrons_Eta);
   fChain->SetBranchAddress("electrons_Iso03", electrons_Iso03, &b_electrons_Iso03);
   fChain->SetBranchAddress("electrons_vidHEEP", electrons_vidHEEP, &b_electrons_vidHEEP);
   fChain->SetBranchAddress("electrons_vidLoose", electrons_vidLoose, &b_electrons_vidLoose);
   fChain->SetBranchAddress("electrons_vidMedium", electrons_vidMedium, &b_electrons_vidMedium);
   fChain->SetBranchAddress("electrons_vidTight", electrons_vidTight, &b_electrons_vidTight);
   fChain->SetBranchAddress("electrons_vidVeto", electrons_vidVeto, &b_electrons_vidVeto);
   fChain->SetBranchAddress("electrons_size", &electrons_size, &b_electrons_size);
   fChain->SetBranchAddress("jetsAK4_E", jetsAK4_E, &b_jetsAK4_E);
   fChain->SetBranchAddress("jetsAK4_Pt", jetsAK4_Pt, &b_jetsAK4_Pt);
   fChain->SetBranchAddress("jetsAK4_Eta", jetsAK4_Eta, &b_jetsAK4_Eta);
   fChain->SetBranchAddress("jetsAK4_Phi", jetsAK4_Phi, &b_jetsAK4_Phi);
   fChain->SetBranchAddress("jetsAK4_PartonFlavour", jetsAK4_PartonFlavour, &b_jetsAK4_PartonFlavour);
//    fChain->SetBranchAddress("jetsAK4_Phi", jetsAK4_Phi, &b_jetsAK4_Phi);
   fChain->SetBranchAddress("jetsAK4_CSVv2", jetsAK4_CSVv2, &b_jetsAK4_CSVv2);
   fChain->SetBranchAddress("jetsAK4_GenJetEta", jetsAK4_GenJetEta, &b_jetsAK4_GenJetEta);
   fChain->SetBranchAddress("jetsAK4_GenJetPt", jetsAK4_GenJetPt, &b_jetsAK4_GenJetPt);
   fChain->SetBranchAddress("jetsAK4_CorrPt", jetsAK4_CorrPt, &b_jetsAK4_CorrPt);
   fChain->SetBranchAddress("jetsAK4_CorrE", jetsAK4_CorrE, &b_jetsAK4_CorrE);
   fChain->SetBranchAddress("jetsAK4_MinDR", jetsAK4_MinDR, &b_jetsAK4_MinDR);
   fChain->SetBranchAddress("jetsAK4_IsCSVT", jetsAK4_IsCSVT, &b_jetsAK4_IsCSVT);
   fChain->SetBranchAddress("jetsAK4_IsCSVM", jetsAK4_IsCSVM, &b_jetsAK4_IsCSVM);
   fChain->SetBranchAddress("jetsAK4_IsCSVL", jetsAK4_IsCSVL, &b_jetsAK4_IsCSVL);
   fChain->SetBranchAddress("jetsAK4_PassesID", jetsAK4_PassesID, &b_jetsAK4_PassesID);
   fChain->SetBranchAddress("jetsAK4_PassesDR", jetsAK4_PassesDR, &b_jetsAK4_PassesDR);
   fChain->SetBranchAddress("jetsAK4_PassesDRtight", jetsAK4_PassesDRtight, &b_jetsAK4_PassesDRtight);
   fChain->SetBranchAddress("jetsAK4_CorrMass", jetsAK4_CorrMass, &b_jetsAK4_CorrMass);
   fChain->SetBranchAddress("jetsAK4_IsTight", jetsAK4_IsTight, &b_jetsAK4_IsTight);
   fChain->SetBranchAddress("jetsAK4_IsLoose", jetsAK4_IsLoose, &b_jetsAK4_IsLoose);
   fChain->SetBranchAddress("jetsAK4_JetID_numberOfDaughters", jetsAK4_JetID_numberOfDaughters, &b_jetsAK4_JetID_numberOfDaughters);
   fChain->SetBranchAddress("jetsAK4_JetID_muonEnergyFraction", jetsAK4_JetID_muonEnergyFraction, &b_jetsAK4_JetID_muonEnergyFraction);
   fChain->SetBranchAddress("jetsAK4_JetID_chargedMultiplicity", jetsAK4_JetID_chargedMultiplicity, &b_jetsAK4_JetID_chargedMultiplicity);
   fChain->SetBranchAddress("jetsAK4_JetID_chargedHadronEnergyFraction", jetsAK4_JetID_chargedHadronEnergyFraction, &b_jetsAK4_JetID_chargedHadronEnergyFraction);
   fChain->SetBranchAddress("jetsAK4_JetID_chargedEmEnergyFraction", jetsAK4_JetID_chargedEmEnergyFraction, &b_jetsAK4_JetID_chargedEmEnergyFraction);
   fChain->SetBranchAddress("jetsAK4_JetID_neutralEmEnergyFraction", jetsAK4_JetID_neutralEmEnergyFraction, &b_jetsAK4_JetID_neutralEmEnergyFraction);
   fChain->SetBranchAddress("jetsAK4_JetID_neutralHadronEnergyFraction", jetsAK4_JetID_neutralHadronEnergyFraction, &b_jetsAK4_JetID_neutralHadronEnergyFraction);
   fChain->SetBranchAddress("jetsAK4_JetID_neutralMultiplicity", jetsAK4_JetID_neutralMultiplicity, &b_jetsAK4_JetID_neutralMultiplicity);
   fChain->SetBranchAddress("jetsAK4_size", &jetsAK4_size, &b_jetsAK4_size);
   fChain->SetBranchAddress("Event_nTightMuons", &Event_nTightMuons, &b_Event_nTightMuons);
   fChain->SetBranchAddress("Event_nSoftMuons", &Event_nSoftMuons, &b_Event_nSoftMuons);
   fChain->SetBranchAddress("Event_nLooseMuons", &Event_nLooseMuons, &b_Event_nLooseMuons);
   fChain->SetBranchAddress("Event_nTightElectrons", &Event_nTightElectrons, &b_Event_nTightElectrons);
   fChain->SetBranchAddress("Event_nMediumElectrons", &Event_nMediumElectrons, &b_Event_nMediumElectrons);
   fChain->SetBranchAddress("Event_nLooseElectrons", &Event_nLooseElectrons, &b_Event_nLooseElectrons);
   fChain->SetBranchAddress("Event_nVetoElectrons", &Event_nVetoElectrons, &b_Event_nVetoElectrons);
   fChain->SetBranchAddress("Event_bWeight0CSVT", &Event_bWeight0CSVT, &b_Event_bWeight0CSVT);
   fChain->SetBranchAddress("Event_bWeight1CSVT", &Event_bWeight1CSVT, &b_Event_bWeight1CSVT);
   fChain->SetBranchAddress("Event_bWeight2CSVT", &Event_bWeight2CSVT, &b_Event_bWeight2CSVT);
   fChain->SetBranchAddress("Event_bWeight0CSVM", &Event_bWeight0CSVM, &b_Event_bWeight0CSVM);
   fChain->SetBranchAddress("Event_bWeight1CSVM", &Event_bWeight1CSVM, &b_Event_bWeight1CSVM);
   fChain->SetBranchAddress("Event_bWeight2CSVM", &Event_bWeight2CSVM, &b_Event_bWeight2CSVM);
   fChain->SetBranchAddress("Event_bWeight0CSVL", &Event_bWeight0CSVL, &b_Event_bWeight0CSVL);
   fChain->SetBranchAddress("Event_bWeight1CSVL", &Event_bWeight1CSVL, &b_Event_bWeight1CSVL);
   fChain->SetBranchAddress("Event_bWeight2CSVL", &Event_bWeight2CSVL, &b_Event_bWeight2CSVL);
   fChain->SetBranchAddress("Event_bWeightMisTagDown0CSVT", &Event_bWeightMisTagDown0CSVT, &b_Event_bWeightMisTagDown0CSVT);
   fChain->SetBranchAddress("Event_bWeightMisTagDown1CSVT", &Event_bWeightMisTagDown1CSVT, &b_Event_bWeightMisTagDown1CSVT);
   fChain->SetBranchAddress("Event_bWeightMisTagDown2CSVT", &Event_bWeightMisTagDown2CSVT, &b_Event_bWeightMisTagDown2CSVT);
   fChain->SetBranchAddress("Event_bWeightMisTagDown0CSVM", &Event_bWeightMisTagDown0CSVM, &b_Event_bWeightMisTagDown0CSVM);
   fChain->SetBranchAddress("Event_bWeightMisTagDown1CSVM", &Event_bWeightMisTagDown1CSVM, &b_Event_bWeightMisTagDown1CSVM);
   fChain->SetBranchAddress("Event_bWeightMisTagDown2CSVM", &Event_bWeightMisTagDown2CSVM, &b_Event_bWeightMisTagDown2CSVM);
   fChain->SetBranchAddress("Event_bWeightMisTagDown0CSVL", &Event_bWeightMisTagDown0CSVL, &b_Event_bWeightMisTagDown0CSVL);
   fChain->SetBranchAddress("Event_bWeightMisTagDown1CSVL", &Event_bWeightMisTagDown1CSVL, &b_Event_bWeightMisTagDown1CSVL);
   fChain->SetBranchAddress("Event_bWeightMisTagDown2CSVL", &Event_bWeightMisTagDown2CSVL, &b_Event_bWeightMisTagDown2CSVL);
   fChain->SetBranchAddress("Event_bWeightMisTagUp0CSVT", &Event_bWeightMisTagUp0CSVT, &b_Event_bWeightMisTagUp0CSVT);
   fChain->SetBranchAddress("Event_bWeightMisTagUp1CSVT", &Event_bWeightMisTagUp1CSVT, &b_Event_bWeightMisTagUp1CSVT);
   fChain->SetBranchAddress("Event_bWeightMisTagUp2CSVT", &Event_bWeightMisTagUp2CSVT, &b_Event_bWeightMisTagUp2CSVT);
   fChain->SetBranchAddress("Event_bWeightMisTagUp0CSVM", &Event_bWeightMisTagUp0CSVM, &b_Event_bWeightMisTagUp0CSVM);
   fChain->SetBranchAddress("Event_bWeightMisTagUp1CSVM", &Event_bWeightMisTagUp1CSVM, &b_Event_bWeightMisTagUp1CSVM);
   fChain->SetBranchAddress("Event_bWeightMisTagUp2CSVM", &Event_bWeightMisTagUp2CSVM, &b_Event_bWeightMisTagUp2CSVM);
   fChain->SetBranchAddress("Event_bWeightMisTagUp0CSVL", &Event_bWeightMisTagUp0CSVL, &b_Event_bWeightMisTagUp0CSVL);
   fChain->SetBranchAddress("Event_bWeightMisTagUp1CSVL", &Event_bWeightMisTagUp1CSVL, &b_Event_bWeightMisTagUp1CSVL);
   fChain->SetBranchAddress("Event_bWeightMisTagUp2CSVL", &Event_bWeightMisTagUp2CSVL, &b_Event_bWeightMisTagUp2CSVL);
   fChain->SetBranchAddress("Event_bWeightBTagUp0CSVT", &Event_bWeightBTagUp0CSVT, &b_Event_bWeightBTagUp0CSVT);
   fChain->SetBranchAddress("Event_bWeightBTagUp1CSVT", &Event_bWeightBTagUp1CSVT, &b_Event_bWeightBTagUp1CSVT);
   fChain->SetBranchAddress("Event_bWeightBTagUp2CSVT", &Event_bWeightBTagUp2CSVT, &b_Event_bWeightBTagUp2CSVT);
   fChain->SetBranchAddress("Event_bWeightBTagUp0CSVM", &Event_bWeightBTagUp0CSVM, &b_Event_bWeightBTagUp0CSVM);
   fChain->SetBranchAddress("Event_bWeightBTagUp1CSVM", &Event_bWeightBTagUp1CSVM, &b_Event_bWeightBTagUp1CSVM);
   fChain->SetBranchAddress("Event_bWeightBTagUp2CSVM", &Event_bWeightBTagUp2CSVM, &b_Event_bWeightBTagUp2CSVM);
   fChain->SetBranchAddress("Event_bWeightBTagUp0CSVL", &Event_bWeightBTagUp0CSVL, &b_Event_bWeightBTagUp0CSVL);
   fChain->SetBranchAddress("Event_bWeightBTagUp1CSVL", &Event_bWeightBTagUp1CSVL, &b_Event_bWeightBTagUp1CSVL);
   fChain->SetBranchAddress("Event_bWeightBTagUp2CSVL", &Event_bWeightBTagUp2CSVL, &b_Event_bWeightBTagUp2CSVL);
   fChain->SetBranchAddress("Event_bWeightBTagDown0CSVT", &Event_bWeightBTagDown0CSVT, &b_Event_bWeightBTagDown0CSVT);
   fChain->SetBranchAddress("Event_bWeightBTagDown1CSVT", &Event_bWeightBTagDown1CSVT, &b_Event_bWeightBTagDown1CSVT);
   fChain->SetBranchAddress("Event_bWeightBTagDown2CSVT", &Event_bWeightBTagDown2CSVT, &b_Event_bWeightBTagDown2CSVT);
   fChain->SetBranchAddress("Event_bWeightBTagDown0CSVM", &Event_bWeightBTagDown0CSVM, &b_Event_bWeightBTagDown0CSVM);
   fChain->SetBranchAddress("Event_bWeightBTagDown1CSVM", &Event_bWeightBTagDown1CSVM, &b_Event_bWeightBTagDown1CSVM);
   fChain->SetBranchAddress("Event_bWeightBTagDown2CSVM", &Event_bWeightBTagDown2CSVM, &b_Event_bWeightBTagDown2CSVM);
   fChain->SetBranchAddress("Event_bWeightBTagDown0CSVL", &Event_bWeightBTagDown0CSVL, &b_Event_bWeightBTagDown0CSVL);
   fChain->SetBranchAddress("Event_bWeightBTagDown1CSVL", &Event_bWeightBTagDown1CSVL, &b_Event_bWeightBTagDown1CSVL);
   fChain->SetBranchAddress("Event_bWeightBTagDown2CSVL", &Event_bWeightBTagDown2CSVL, &b_Event_bWeightBTagDown2CSVL);
   fChain->SetBranchAddress("Event_LHEWeightSign", &Event_LHEWeightSign, &b_Event_LHEWeightSign);
   fChain->SetBranchAddress("Event_LHEWeight", &Event_LHEWeight, &b_Event_LHEWeight);
   fChain->SetBranchAddress("Event_EventNumber", &Event_EventNumber, &b_Event_EventNumber);
   fChain->SetBranchAddress("Event_LumiBlock", &Event_LumiBlock, &b_Event_LumiBlock);
   fChain->SetBranchAddress("Event_RunNumber", &Event_RunNumber, &b_Event_RunNumber);
   fChain->SetBranchAddress("Event_mu_eff", &Event_mu_eff, &b_Event_mu_eff);
   fChain->SetBranchAddress("Event_mu_eff_up", &Event_mu_eff_up, &b_Event_mu_eff_up);
   fChain->SetBranchAddress("Event_mu_eff_down", &Event_mu_eff_down, &b_Event_mu_eff_down);
   fChain->SetBranchAddress("Event_nPV", &Event_nPV, &b_Event_nPV);
   fChain->SetBranchAddress("Event_nGoodPV", &Event_nGoodPV, &b_Event_nGoodPV);
   fChain->SetBranchAddress("Event_passesFlag_CSCTightHaloFilter", &Event_passesFlag_CSCTightHaloFilter, &b_Event_passesFlag_CSCTightHaloFilter);
   fChain->SetBranchAddress("Event_passesFlag_goodVertices", &Event_passesFlag_goodVertices, &b_Event_passesFlag_goodVertices);
   fChain->SetBranchAddress("Event_passesFlag_eeBadScFilter", &Event_passesFlag_eeBadScFilter, &b_Event_passesFlag_eeBadScFilter);
   fChain->SetBranchAddress("Event_passesMETFilters", &Event_passesMETFilters, &b_Event_passesMETFilters);
   fChain->SetBranchAddress("Event_passesHBHE", &Event_passesHBHE, &b_Event_passesHBHE);
   fChain->SetBranchAddress("Event_passesHLT_IsoMu20_v1", &Event_passesHLT_IsoMu20_v1, &b_Event_passesHLT_IsoMu20_v1);
   fChain->SetBranchAddress("Event_prescaleHLT_IsoMu20_v1", &Event_prescaleHLT_IsoMu20_v1, &b_Event_prescaleHLT_IsoMu20_v1);
   fChain->SetBranchAddress("Event_passesHLT_IsoMu20_v2", &Event_passesHLT_IsoMu20_v2, &b_Event_passesHLT_IsoMu20_v2);
   fChain->SetBranchAddress("Event_prescaleHLT_IsoMu20_v2", &Event_prescaleHLT_IsoMu20_v2, &b_Event_prescaleHLT_IsoMu20_v2);
   fChain->SetBranchAddress("Event_passesHLT_IsoMu20_v3", &Event_passesHLT_IsoMu20_v3, &b_Event_passesHLT_IsoMu20_v3);
   fChain->SetBranchAddress("Event_prescaleHLT_IsoMu20_v3", &Event_prescaleHLT_IsoMu20_v3, &b_Event_prescaleHLT_IsoMu20_v3);
   fChain->SetBranchAddress("Event_passesHLT_IsoMu20_v4", &Event_passesHLT_IsoMu20_v4, &b_Event_passesHLT_IsoMu20_v4);
   fChain->SetBranchAddress("Event_prescaleHLT_IsoMu20_v4", &Event_prescaleHLT_IsoMu20_v4, &b_Event_prescaleHLT_IsoMu20_v4);
   fChain->SetBranchAddress("Event_passesLeptonicTriggers", &Event_passesLeptonicTriggers, &b_Event_passesLeptonicTriggers);
   fChain->SetBranchAddress("Event_passesHadronicTriggers", &Event_passesHadronicTriggers, &b_Event_passesHadronicTriggers);
   fChain->SetBranchAddress("Event_puWeight", &Event_puWeight, &b_Event_puWeight);
   fChain->SetBranchAddress("Event_puWeightUp", &Event_puWeightUp, &b_Event_puWeightUp);
   fChain->SetBranchAddress("Event_puWeightDown", &Event_puWeightDown, &b_Event_puWeightDown);
   fChain->SetBranchAddress("Event_nTruePU", &Event_nTruePU, &b_Event_nTruePU);
   Notify();
}

Bool_t SingleTopTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void SingleTopTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t SingleTopTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef SingleTopTree_cxx

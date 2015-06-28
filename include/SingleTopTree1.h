//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sun May 10 19:36:43 2015 by ROOT version 6.02/04
// from TTree singleTp__noSyst/singleTp__noSyst
// found on file: ../TTChannel_Synch6.root
//////////////////////////////////////////////////////////

#ifndef SingleTopTree_h
#define SingleTopTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class SingleTopTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Float_t         met_Pt;
   Float_t         met_Phi;
   Float_t         met_Px;
   Float_t         met_Py;
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
   Float_t         muons_SFTrigger[10];
   Float_t         muons_SFReco[10];
   Float_t         muons_isQCD[10];
   Int_t           muons_size;
   Float_t         electrons_E[10];
   Float_t         electrons_Pt[10];
   Float_t         electrons_Eta[10];
   Float_t         electrons_Phi[10];
  //Float_t         electrons_Eta[10];
   Float_t         electrons_Iso03[10];
   Float_t         electrons_isVeto[10];
   Float_t         electrons_isLoose[10];
   Float_t         electrons_isMedium[10];
   Float_t         electrons_isTight[10];
   Float_t         electrons_SFTrigger[10];
   Float_t         electrons_SFReco[10];
   Float_t         electrons_isQCD[10];
   Float_t         electrons_PassesDRmu[10];
   Int_t           electrons_size;
   Float_t         jetsAK4_E[20];
   Float_t         jetsAK4_Pt[20];
   Float_t         jetsAK4_Eta[20];
   Float_t         jetsAK4_Phi[20];
  //Float_t         jetsAK4_Phi[20];
   Float_t         jetsAK4_CSV[20];
   Float_t         jetsAK4_GenJetEta[20];
   Float_t         jetsAK4_GenJetPt[20];
   Float_t         jetsAK4_numberOfDaughters[20];
   Float_t         jetsAK4_neutralEmEnergy[20];
   Float_t         jetsAK4_neutralHadronEnergy[20];
   Float_t         jetsAK4_jecFactor0[20];
   Float_t         jetsAK4_CorrPt[20];
   Float_t         jetsAK4_CorrE[20];
   Float_t         jetsAK4_MinDR[20];
   Float_t         jetsAK4_IsCSVT[20];
   Float_t         jetsAK4_IsCSVM[20];
   Float_t         jetsAK4_IsCSVL[20];
   Float_t         jetsAK4_PassesID[20];
   Float_t         jetsAK4_PassesDR[20];
   Float_t         jetsAK4_CorrMass[20];
   Float_t         jetsAK4_IsTight[20];
   Float_t         jetsAK4_IsLoose[20];
   Int_t           jetsAK4_size;
   Float_t         resolvedTopSemiLep_Pt[20];
   Float_t         resolvedTopSemiLep_WMas[20];
   Float_t         resolvedTopSemiLep_Phi[20];
   Float_t         resolvedTopSemiLep_E[20];
   Float_t         resolvedTopSemiLep_Mass[20];
   Float_t         resolvedTopSemiLep_MT[20];
   Int_t           resolvedTopSemiLep_size;
   Float_t         Event_weight;
   Float_t         Event_nTightMuons;
   Float_t         Event_nSoftMuons;
   Float_t         Event_nLooseMuons;
   Float_t         Event_nTightElectrons;
   Float_t         Event_nMediumElectrons;
   Float_t         Event_nLooseElectrons;
   Float_t         Event_nVetoElectrons;
   Float_t         Event_nElectronsSF;
   Float_t         Event_mt;
   Float_t         Event_category;
   Float_t         Event_nMuonsSF;
   Float_t         Event_nCSVTJets;
   Float_t         Event_nCSVMJets;
   Float_t         Event_nCSVLJets;
   Float_t         Event_nTightJets;
   Float_t         Event_nLooseJets;
   Float_t         Event_LHEWeightSign;
   Float_t         Event_LHEWeight;
   Float_t         Event_EventNumber;
   Float_t         Event_LumiBlock;
   Float_t         Event_RunNumber;
   Float_t         Event_nJetsCut30;
   Float_t         Event_nCSVTJetsCut30;
   Float_t         Event_nCSVMJetsCut30;
   Float_t         Event_nCSVLJetsCut30;
   Float_t         Event_bWeight1CSVTWeightCut30;
   Float_t         Event_bWeight2CSVTWeightCut30;
   Float_t         Event_bWeight1CSVMWeightCut30;
   Float_t         Event_bWeight2CSVMWeightCut30;
   Float_t         Event_bWeight1CSVLWeightCut30;
   Float_t         Event_bWeight2CSVLWeightCut30;
   Float_t         Event_bWeight0CSVLWeightCut30;
  //Float_t         Event_bWeight0CSVLWeightCut30;
   Float_t         Event_LHEWeight1;
   Float_t         Event_LHEWeight2;
   Float_t         Event_LHEWeight3;
   Float_t         Event_LHEWeight4;
   Float_t         Event_LHEWeight5;
   Float_t         Event_LHEWeight6;
   Float_t         Event_LHEWeight7;
   Float_t         Event_LHEWeight8;
   Float_t         Event_LHEWeight9;
   Float_t         Event_passesHLT_Ele27_eta2p1_WP85_Gsf;
   Float_t         Event_prescaleHLT_Ele27_eta2p1_WP85_Gsf;
   Float_t         Event_passesHLT_IsoMu24_IterTrk02;
   Float_t         Event_prescaleHLT_IsoMu24_IterTrk02;
   Float_t         Event_passesHLT_IsoMu24_eta2p1_IterTrk02_v1;
   Float_t         Event_prescaleHLT_IsoMu24_eta2p1_IterTrk02_v1;
   Float_t         Event_passesHLT_Ele32_eta2p1_WP85_Gsf_v1;
   Float_t         Event_prescaleHLT_Ele32_eta2p1_WP85_Gsf_v1;
   Float_t         Event_passesHLT_PFMET120_NoiseCleaned_BTagCSV07;
   Float_t         Event_prescaleHLT_PFMET120_NoiseCleaned_BTagCSV07;
   Float_t         Event_passesLeptonicTriggers;
   Float_t         Event_passesHadronicTriggers;

   // List of branches
   TBranch        *b_met_Pt;   //!
   TBranch        *b_met_Phi;   //!
   TBranch        *b_met_Px;   //!
   TBranch        *b_met_Py;   //!
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
   TBranch        *b_muons_SFTrigger;   //!
   TBranch        *b_muons_SFReco;   //!
   TBranch        *b_muons_isQCD;   //!
   TBranch        *b_muons_size;   //!
   TBranch        *b_electrons_E;   //!
   TBranch        *b_electrons_Pt;   //!
   TBranch        *b_electrons_Eta;   //!
   TBranch        *b_electrons_Phi;   //!
  //TBranch        *b_electrons_Eta;   //!
   TBranch        *b_electrons_Iso03;   //!
   TBranch        *b_electrons_isVeto;   //!
   TBranch        *b_electrons_isLoose;   //!
   TBranch        *b_electrons_isMedium;   //!
   TBranch        *b_electrons_isTight;   //!
   TBranch        *b_electrons_SFTrigger;   //!
   TBranch        *b_electrons_SFReco;   //!
   TBranch        *b_electrons_isQCD;   //!
   TBranch        *b_electrons_PassesDRmu;   //!
   TBranch        *b_electrons_size;   //!
   TBranch        *b_jetsAK4_E;   //!
   TBranch        *b_jetsAK4_Pt;   //!
   TBranch        *b_jetsAK4_Eta;   //!
   TBranch        *b_jetsAK4_Phi;   //!
  //TBranch        *b_jetsAK4_Phi;   //!
   TBranch        *b_jetsAK4_CSV;   //!
   TBranch        *b_jetsAK4_GenJetEta;   //!
   TBranch        *b_jetsAK4_GenJetPt;   //!
   TBranch        *b_jetsAK4_numberOfDaughters;   //!
   TBranch        *b_jetsAK4_neutralEmEnergy;   //!
   TBranch        *b_jetsAK4_neutralHadronEnergy;   //!
   TBranch        *b_jetsAK4_jecFactor0;   //!
   TBranch        *b_jetsAK4_CorrPt;   //!
   TBranch        *b_jetsAK4_CorrE;   //!
   TBranch        *b_jetsAK4_MinDR;   //!
   TBranch        *b_jetsAK4_IsCSVT;   //!
   TBranch        *b_jetsAK4_IsCSVM;   //!
   TBranch        *b_jetsAK4_IsCSVL;   //!
   TBranch        *b_jetsAK4_PassesID;   //!
   TBranch        *b_jetsAK4_PassesDR;   //!
   TBranch        *b_jetsAK4_CorrMass;   //!
   TBranch        *b_jetsAK4_IsTight;   //!
   TBranch        *b_jetsAK4_IsLoose;   //!
   TBranch        *b_jetsAK4_size;   //!
   TBranch        *b_resolvedTopSemiLep_Pt;   //!
   TBranch        *b_resolvedTopSemiLep_WMas;   //!
   TBranch        *b_resolvedTopSemiLep_Phi;   //!
   TBranch        *b_resolvedTopSemiLep_E;   //!
   TBranch        *b_resolvedTopSemiLep_Mass;   //!
   TBranch        *b_resolvedTopSemiLep_MT;   //!
   TBranch        *b_resolvedTopSemiLep_size;   //!
   TBranch        *b_Event_weight;   //!
   TBranch        *b_Event_nTightMuons;   //!
   TBranch        *b_Event_nSoftMuons;   //!
   TBranch        *b_Event_nLooseMuons;   //!
   TBranch        *b_Event_nTightElectrons;   //!
   TBranch        *b_Event_nMediumElectrons;   //!
   TBranch        *b_Event_nLooseElectrons;   //!
   TBranch        *b_Event_nVetoElectrons;   //!
   TBranch        *b_Event_nElectronsSF;   //!
   TBranch        *b_Event_mt;   //!
   TBranch        *b_Event_category;   //!
   TBranch        *b_Event_nMuonsSF;   //!
   TBranch        *b_Event_nCSVTJets;   //!
   TBranch        *b_Event_nCSVMJets;   //!
   TBranch        *b_Event_nCSVLJets;   //!
   TBranch        *b_Event_nTightJets;   //!
   TBranch        *b_Event_nLooseJets;   //!
   TBranch        *b_Event_LHEWeightSign;   //!
   TBranch        *b_Event_LHEWeight;   //!
   TBranch        *b_Event_EventNumber;   //!
   TBranch        *b_Event_LumiBlock;   //!
   TBranch        *b_Event_RunNumber;   //!
   TBranch        *b_Event_nJetsCut30;   //!
   TBranch        *b_Event_nCSVTJetsCut30;   //!
   TBranch        *b_Event_nCSVMJetsCut30;   //!
   TBranch        *b_Event_nCSVLJetsCut30;   //!
   TBranch        *b_Event_bWeight1CSVTWeightCut30;   //!
   TBranch        *b_Event_bWeight2CSVTWeightCut30;   //!
   TBranch        *b_Event_bWeight1CSVMWeightCut30;   //!
   TBranch        *b_Event_bWeight2CSVMWeightCut30;   //!
   TBranch        *b_Event_bWeight1CSVLWeightCut30;   //!
   TBranch        *b_Event_bWeight2CSVLWeightCut30;   //!
   TBranch        *b_Event_bWeight0CSVLWeightCut30;   //!
  //TBranch        *b_Event_bWeight0CSVLWeightCut30;   //!
   TBranch        *b_Event_LHEWeight1;   //!
   TBranch        *b_Event_LHEWeight2;   //!
   TBranch        *b_Event_LHEWeight3;   //!
   TBranch        *b_Event_LHEWeight4;   //!
   TBranch        *b_Event_LHEWeight5;   //!
   TBranch        *b_Event_LHEWeight6;   //!
   TBranch        *b_Event_LHEWeight7;   //!
   TBranch        *b_Event_LHEWeight8;   //!
   TBranch        *b_Event_LHEWeight9;   //!
   TBranch        *b_Event_passesHLT_Ele27_eta2p1_WP85_Gsf;   //!
   TBranch        *b_Event_prescaleHLT_Ele27_eta2p1_WP85_Gsf;   //!
   TBranch        *b_Event_passesHLT_IsoMu24_IterTrk02;   //!
   TBranch        *b_Event_prescaleHLT_IsoMu24_IterTrk02;   //!
   TBranch        *b_Event_passesHLT_IsoMu24_eta2p1_IterTrk02_v1;   //!
   TBranch        *b_Event_prescaleHLT_IsoMu24_eta2p1_IterTrk02_v1;   //!
   TBranch        *b_Event_passesHLT_Ele32_eta2p1_WP85_Gsf_v1;   //!
   TBranch        *b_Event_prescaleHLT_Ele32_eta2p1_WP85_Gsf_v1;   //!
   TBranch        *b_Event_passesHLT_PFMET120_NoiseCleaned_BTagCSV07;   //!
   TBranch        *b_Event_prescaleHLT_PFMET120_NoiseCleaned_BTagCSV07;   //!
   TBranch        *b_Event_passesLeptonicTriggers;   //!
   TBranch        *b_Event_passesHadronicTriggers;   //!

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


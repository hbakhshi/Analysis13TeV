//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Jun 24 13:01:46 2015 by ROOT version 6.02/04
// from TTree ttDM__noSyst/ttDM__noSyst
// found on file: ../tchannel_t_1.root
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
  //   Float_t         electrons_Eta[10];
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
   Int_t           jetsAK4_size;
   Float_t         jetsAK8_E[4];
   Float_t         jetsAK8_Pt[4];
  //Float_t         jetsAK8_Mass[4];
   Float_t         jetsAK8_Eta[4];
   Float_t         jetsAK8_Phi[4];
   Float_t         jetsAK8_Mass[4];
   Float_t         jetsAK8_minmass[4];
   Float_t         jetsAK8_nSubJets[4];
   Float_t         jetsAK8_prunedMass[4];
   Float_t         jetsAK8_tau1[4];
   Float_t         jetsAK8_tau2[4];
   Float_t         jetsAK8_tau3[4];
   Float_t         jetsAK8_topMass[4];
   Float_t         jetsAK8_trimmedMass[4];
   Float_t         jetsAK8_wMass[4];
   Int_t           jetsAK8_size;
   Float_t         subjetsAK8_E[10];
   Float_t         subjetsAK8_Pt[10];
   Float_t         subjetsAK8_Mass[10];
   Float_t         subjetsAK8_Eta[10];
   Float_t         subjetsAK8_Phi[10];
   Float_t         subjetsAK8_subjetCSV[10];
   Int_t           subjetsAK8_size;
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
  //Float_t         Event_bWeight0CSVLWeightCut30;
   Float_t         Event_bWeight0CSVLWeightCut30;
   Float_t         Event_passesHLT_IsoMu24_IterTrk02;
   Float_t         Event_prescaleHLT_IsoMu24_IterTrk02;
   Float_t         Event_passesHLT_IsoMu24_eta2p1_IterTrk02_v1;
   Float_t         Event_prescaleHLT_IsoMu24_eta2p1_IterTrk02_v1;
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
  //TBranch        *b_electrons_Eta;   //!
   TBranch        *b_electrons_Phi;   //!
   TBranch        *b_electrons_Eta;   //!
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
   TBranch        *b_jetsAK4_size;   //!
   TBranch        *b_jetsAK8_E;   //!
   TBranch        *b_jetsAK8_Pt;   //!
  //TBranch        *b_jetsAK8_Mass;   //!
   TBranch        *b_jetsAK8_Eta;   //!
   TBranch        *b_jetsAK8_Phi;   //!
   TBranch        *b_jetsAK8_Mass;   //!
   TBranch        *b_jetsAK8_minmass;   //!
   TBranch        *b_jetsAK8_nSubJets;   //!
   TBranch        *b_jetsAK8_prunedMass;   //!
   TBranch        *b_jetsAK8_tau1;   //!
   TBranch        *b_jetsAK8_tau2;   //!
   TBranch        *b_jetsAK8_tau3;   //!
   TBranch        *b_jetsAK8_topMass;   //!
   TBranch        *b_jetsAK8_trimmedMass;   //!
   TBranch        *b_jetsAK8_wMass;   //!
   TBranch        *b_jetsAK8_size;   //!
   TBranch        *b_subjetsAK8_E;   //!
   TBranch        *b_subjetsAK8_Pt;   //!
   TBranch        *b_subjetsAK8_Mass;   //!
   TBranch        *b_subjetsAK8_Eta;   //!
   TBranch        *b_subjetsAK8_Phi;   //!
   TBranch        *b_subjetsAK8_subjetCSV;   //!
   TBranch        *b_subjetsAK8_size;   //!
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
  //TBranch        *b_Event_bWeight0CSVLWeightCut30;   //!
   TBranch        *b_Event_bWeight0CSVLWeightCut30;   //!
   TBranch        *b_Event_passesHLT_IsoMu24_IterTrk02;   //!
   TBranch        *b_Event_prescaleHLT_IsoMu24_IterTrk02;   //!
   TBranch        *b_Event_passesHLT_IsoMu24_eta2p1_IterTrk02_v1;   //!
   TBranch        *b_Event_prescaleHLT_IsoMu24_eta2p1_IterTrk02_v1;   //!
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

#ifdef SingleTopTree_cxx
SingleTopTree::SingleTopTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("../tchannel_t_1.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("../tchannel_t_1.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("../tchannel_t_1.root:/DMTreesDumper");
      dir->GetObject("ttDM__noSyst",tree);

   }
   Init(tree);
}

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
   fChain->SetBranchAddress("muons_SFTrigger", muons_SFTrigger, &b_muons_SFTrigger);
   fChain->SetBranchAddress("muons_SFReco", muons_SFReco, &b_muons_SFReco);
   fChain->SetBranchAddress("muons_isQCD", muons_isQCD, &b_muons_isQCD);
   fChain->SetBranchAddress("muons_size", &muons_size, &b_muons_size);
   fChain->SetBranchAddress("electrons_E", electrons_E, &b_electrons_E);
   fChain->SetBranchAddress("electrons_Pt", electrons_Pt, &b_electrons_Pt);
   fChain->SetBranchAddress("electrons_Eta", electrons_Eta, &b_electrons_Eta);
   fChain->SetBranchAddress("electrons_Phi", electrons_Phi, &b_electrons_Phi);
//    fChain->SetBranchAddress("electrons_Eta", electrons_Eta, &b_electrons_Eta);
   fChain->SetBranchAddress("electrons_Iso03", electrons_Iso03, &b_electrons_Iso03);
   fChain->SetBranchAddress("electrons_isVeto", electrons_isVeto, &b_electrons_isVeto);
   fChain->SetBranchAddress("electrons_isLoose", electrons_isLoose, &b_electrons_isLoose);
   fChain->SetBranchAddress("electrons_isMedium", electrons_isMedium, &b_electrons_isMedium);
   fChain->SetBranchAddress("electrons_isTight", electrons_isTight, &b_electrons_isTight);
   fChain->SetBranchAddress("electrons_SFTrigger", electrons_SFTrigger, &b_electrons_SFTrigger);
   fChain->SetBranchAddress("electrons_SFReco", electrons_SFReco, &b_electrons_SFReco);
   fChain->SetBranchAddress("electrons_isQCD", electrons_isQCD, &b_electrons_isQCD);
   fChain->SetBranchAddress("electrons_PassesDRmu", electrons_PassesDRmu, &b_electrons_PassesDRmu);
   fChain->SetBranchAddress("electrons_size", &electrons_size, &b_electrons_size);
   fChain->SetBranchAddress("jetsAK4_E", jetsAK4_E, &b_jetsAK4_E);
   fChain->SetBranchAddress("jetsAK4_Pt", jetsAK4_Pt, &b_jetsAK4_Pt);
   fChain->SetBranchAddress("jetsAK4_Eta", jetsAK4_Eta, &b_jetsAK4_Eta);
   fChain->SetBranchAddress("jetsAK4_Phi", jetsAK4_Phi, &b_jetsAK4_Phi);
//    fChain->SetBranchAddress("jetsAK4_Phi", jetsAK4_Phi, &b_jetsAK4_Phi);
   fChain->SetBranchAddress("jetsAK4_CSV", jetsAK4_CSV, &b_jetsAK4_CSV);
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
   fChain->SetBranchAddress("jetsAK4_size", &jetsAK4_size, &b_jetsAK4_size);
   fChain->SetBranchAddress("jetsAK8_E", jetsAK8_E, &b_jetsAK8_E);
   fChain->SetBranchAddress("jetsAK8_Pt", jetsAK8_Pt, &b_jetsAK8_Pt);
   fChain->SetBranchAddress("jetsAK8_Mass", jetsAK8_Mass, &b_jetsAK8_Mass);
   fChain->SetBranchAddress("jetsAK8_Eta", jetsAK8_Eta, &b_jetsAK8_Eta);
   fChain->SetBranchAddress("jetsAK8_Phi", jetsAK8_Phi, &b_jetsAK8_Phi);
//    fChain->SetBranchAddress("jetsAK8_Mass", jetsAK8_Mass, &b_jetsAK8_Mass);
   fChain->SetBranchAddress("jetsAK8_minmass", jetsAK8_minmass, &b_jetsAK8_minmass);
   fChain->SetBranchAddress("jetsAK8_nSubJets", jetsAK8_nSubJets, &b_jetsAK8_nSubJets);
   fChain->SetBranchAddress("jetsAK8_prunedMass", jetsAK8_prunedMass, &b_jetsAK8_prunedMass);
   fChain->SetBranchAddress("jetsAK8_tau1", jetsAK8_tau1, &b_jetsAK8_tau1);
   fChain->SetBranchAddress("jetsAK8_tau2", jetsAK8_tau2, &b_jetsAK8_tau2);
   fChain->SetBranchAddress("jetsAK8_tau3", jetsAK8_tau3, &b_jetsAK8_tau3);
   fChain->SetBranchAddress("jetsAK8_topMass", jetsAK8_topMass, &b_jetsAK8_topMass);
   fChain->SetBranchAddress("jetsAK8_trimmedMass", jetsAK8_trimmedMass, &b_jetsAK8_trimmedMass);
   fChain->SetBranchAddress("jetsAK8_wMass", jetsAK8_wMass, &b_jetsAK8_wMass);
   fChain->SetBranchAddress("jetsAK8_size", &jetsAK8_size, &b_jetsAK8_size);
   fChain->SetBranchAddress("subjetsAK8_E", subjetsAK8_E, &b_subjetsAK8_E);
   fChain->SetBranchAddress("subjetsAK8_Pt", subjetsAK8_Pt, &b_subjetsAK8_Pt);
   fChain->SetBranchAddress("subjetsAK8_Mass", subjetsAK8_Mass, &b_subjetsAK8_Mass);
   fChain->SetBranchAddress("subjetsAK8_Eta", subjetsAK8_Eta, &b_subjetsAK8_Eta);
   fChain->SetBranchAddress("subjetsAK8_Phi", subjetsAK8_Phi, &b_subjetsAK8_Phi);
   fChain->SetBranchAddress("subjetsAK8_subjetCSV", subjetsAK8_subjetCSV, &b_subjetsAK8_subjetCSV);
   fChain->SetBranchAddress("subjetsAK8_size", &subjetsAK8_size, &b_subjetsAK8_size);
   fChain->SetBranchAddress("resolvedTopSemiLep_Pt", resolvedTopSemiLep_Pt, &b_resolvedTopSemiLep_Pt);
   fChain->SetBranchAddress("resolvedTopSemiLep_WMas", resolvedTopSemiLep_WMas, &b_resolvedTopSemiLep_WMas);
   fChain->SetBranchAddress("resolvedTopSemiLep_Phi", resolvedTopSemiLep_Phi, &b_resolvedTopSemiLep_Phi);
   fChain->SetBranchAddress("resolvedTopSemiLep_E", resolvedTopSemiLep_E, &b_resolvedTopSemiLep_E);
   fChain->SetBranchAddress("resolvedTopSemiLep_Mass", resolvedTopSemiLep_Mass, &b_resolvedTopSemiLep_Mass);
   fChain->SetBranchAddress("resolvedTopSemiLep_MT", resolvedTopSemiLep_MT, &b_resolvedTopSemiLep_MT);
   fChain->SetBranchAddress("resolvedTopSemiLep_size", &resolvedTopSemiLep_size, &b_resolvedTopSemiLep_size);
   fChain->SetBranchAddress("Event_weight", &Event_weight, &b_Event_weight);
   fChain->SetBranchAddress("Event_nTightMuons", &Event_nTightMuons, &b_Event_nTightMuons);
   fChain->SetBranchAddress("Event_nSoftMuons", &Event_nSoftMuons, &b_Event_nSoftMuons);
   fChain->SetBranchAddress("Event_nLooseMuons", &Event_nLooseMuons, &b_Event_nLooseMuons);
   fChain->SetBranchAddress("Event_nTightElectrons", &Event_nTightElectrons, &b_Event_nTightElectrons);
   fChain->SetBranchAddress("Event_nMediumElectrons", &Event_nMediumElectrons, &b_Event_nMediumElectrons);
   fChain->SetBranchAddress("Event_nLooseElectrons", &Event_nLooseElectrons, &b_Event_nLooseElectrons);
   fChain->SetBranchAddress("Event_nVetoElectrons", &Event_nVetoElectrons, &b_Event_nVetoElectrons);
   fChain->SetBranchAddress("Event_nElectronsSF", &Event_nElectronsSF, &b_Event_nElectronsSF);
   fChain->SetBranchAddress("Event_mt", &Event_mt, &b_Event_mt);
   fChain->SetBranchAddress("Event_category", &Event_category, &b_Event_category);
   fChain->SetBranchAddress("Event_nMuonsSF", &Event_nMuonsSF, &b_Event_nMuonsSF);
   fChain->SetBranchAddress("Event_nCSVTJets", &Event_nCSVTJets, &b_Event_nCSVTJets);
   fChain->SetBranchAddress("Event_nCSVMJets", &Event_nCSVMJets, &b_Event_nCSVMJets);
   fChain->SetBranchAddress("Event_nCSVLJets", &Event_nCSVLJets, &b_Event_nCSVLJets);
   fChain->SetBranchAddress("Event_nTightJets", &Event_nTightJets, &b_Event_nTightJets);
   fChain->SetBranchAddress("Event_nLooseJets", &Event_nLooseJets, &b_Event_nLooseJets);
   fChain->SetBranchAddress("Event_LHEWeightSign", &Event_LHEWeightSign, &b_Event_LHEWeightSign);
   fChain->SetBranchAddress("Event_LHEWeight", &Event_LHEWeight, &b_Event_LHEWeight);
   fChain->SetBranchAddress("Event_EventNumber", &Event_EventNumber, &b_Event_EventNumber);
   fChain->SetBranchAddress("Event_LumiBlock", &Event_LumiBlock, &b_Event_LumiBlock);
   fChain->SetBranchAddress("Event_RunNumber", &Event_RunNumber, &b_Event_RunNumber);
   fChain->SetBranchAddress("Event_nJetsCut30", &Event_nJetsCut30, &b_Event_nJetsCut30);
   fChain->SetBranchAddress("Event_nCSVTJetsCut30", &Event_nCSVTJetsCut30, &b_Event_nCSVTJetsCut30);
   fChain->SetBranchAddress("Event_nCSVMJetsCut30", &Event_nCSVMJetsCut30, &b_Event_nCSVMJetsCut30);
   fChain->SetBranchAddress("Event_nCSVLJetsCut30", &Event_nCSVLJetsCut30, &b_Event_nCSVLJetsCut30);
   fChain->SetBranchAddress("Event_bWeight1CSVTWeightCut30", &Event_bWeight1CSVTWeightCut30, &b_Event_bWeight1CSVTWeightCut30);
   fChain->SetBranchAddress("Event_bWeight2CSVTWeightCut30", &Event_bWeight2CSVTWeightCut30, &b_Event_bWeight2CSVTWeightCut30);
   fChain->SetBranchAddress("Event_bWeight1CSVMWeightCut30", &Event_bWeight1CSVMWeightCut30, &b_Event_bWeight1CSVMWeightCut30);
   fChain->SetBranchAddress("Event_bWeight2CSVMWeightCut30", &Event_bWeight2CSVMWeightCut30, &b_Event_bWeight2CSVMWeightCut30);
   fChain->SetBranchAddress("Event_bWeight1CSVLWeightCut30", &Event_bWeight1CSVLWeightCut30, &b_Event_bWeight1CSVLWeightCut30);
   fChain->SetBranchAddress("Event_bWeight2CSVLWeightCut30", &Event_bWeight2CSVLWeightCut30, &b_Event_bWeight2CSVLWeightCut30);
   fChain->SetBranchAddress("Event_bWeight0CSVLWeightCut30", &Event_bWeight0CSVLWeightCut30, &b_Event_bWeight0CSVLWeightCut30);
//    fChain->SetBranchAddress("Event_bWeight0CSVLWeightCut30", &Event_bWeight0CSVLWeightCut30, &b_Event_bWeight0CSVLWeightCut30);
   fChain->SetBranchAddress("Event_passesHLT_IsoMu24_IterTrk02", &Event_passesHLT_IsoMu24_IterTrk02, &b_Event_passesHLT_IsoMu24_IterTrk02);
   fChain->SetBranchAddress("Event_prescaleHLT_IsoMu24_IterTrk02", &Event_prescaleHLT_IsoMu24_IterTrk02, &b_Event_prescaleHLT_IsoMu24_IterTrk02);
   fChain->SetBranchAddress("Event_passesHLT_IsoMu24_eta2p1_IterTrk02_v1", &Event_passesHLT_IsoMu24_eta2p1_IterTrk02_v1, &b_Event_passesHLT_IsoMu24_eta2p1_IterTrk02_v1);
   fChain->SetBranchAddress("Event_prescaleHLT_IsoMu24_eta2p1_IterTrk02_v1", &Event_prescaleHLT_IsoMu24_eta2p1_IterTrk02_v1, &b_Event_prescaleHLT_IsoMu24_eta2p1_IterTrk02_v1);
   fChain->SetBranchAddress("Event_passesLeptonicTriggers", &Event_passesLeptonicTriggers, &b_Event_passesLeptonicTriggers);
   fChain->SetBranchAddress("Event_passesHadronicTriggers", &Event_passesHadronicTriggers, &b_Event_passesHadronicTriggers);
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

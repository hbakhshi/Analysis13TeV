#define SingleTopTree_cxx
#include "SingleTopTree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

SingleTopTree::SingleTopTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("TTJets2_1.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("TTJets2_1.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("TTJets2_1.root:/DMTreesDumper");
      dir->GetObject("singleTp__noSyst",tree);

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
   fChain->SetBranchAddress("jetsAK4_numberOfDaughters", jetsAK4_numberOfDaughters, &b_jetsAK4_numberOfDaughters);
   fChain->SetBranchAddress("jetsAK4_neutralEmEnergy", jetsAK4_neutralEmEnergy, &b_jetsAK4_neutralEmEnergy);
   fChain->SetBranchAddress("jetsAK4_neutralHadronEnergy", jetsAK4_neutralHadronEnergy, &b_jetsAK4_neutralHadronEnergy);
   fChain->SetBranchAddress("jetsAK4_jecFactor0", jetsAK4_jecFactor0, &b_jetsAK4_jecFactor0);
   fChain->SetBranchAddress("jetsAK4_CorrPt", jetsAK4_CorrPt, &b_jetsAK4_CorrPt);
   fChain->SetBranchAddress("jetsAK4_CorrE", jetsAK4_CorrE, &b_jetsAK4_CorrE);
   fChain->SetBranchAddress("jetsAK4_MinDR", jetsAK4_MinDR, &b_jetsAK4_MinDR);
   fChain->SetBranchAddress("jetsAK4_IsCSVT", jetsAK4_IsCSVT, &b_jetsAK4_IsCSVT);
   fChain->SetBranchAddress("jetsAK4_IsCSVM", jetsAK4_IsCSVM, &b_jetsAK4_IsCSVM);
   fChain->SetBranchAddress("jetsAK4_IsCSVL", jetsAK4_IsCSVL, &b_jetsAK4_IsCSVL);
   fChain->SetBranchAddress("jetsAK4_PassesID", jetsAK4_PassesID, &b_jetsAK4_PassesID);
   fChain->SetBranchAddress("jetsAK4_PassesDR", jetsAK4_PassesDR, &b_jetsAK4_PassesDR);
   fChain->SetBranchAddress("jetsAK4_CorrMass", jetsAK4_CorrMass, &b_jetsAK4_CorrMass);
   fChain->SetBranchAddress("jetsAK4_IsTight", jetsAK4_IsTight, &b_jetsAK4_IsTight);
   fChain->SetBranchAddress("jetsAK4_IsLoose", jetsAK4_IsLoose, &b_jetsAK4_IsLoose);
   fChain->SetBranchAddress("jetsAK4_size", &jetsAK4_size, &b_jetsAK4_size);
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
   fChain->SetBranchAddress("Event_passesHLT_Ele27_eta2p1_WP85_Gsf", &Event_passesHLT_Ele27_eta2p1_WP85_Gsf, &b_Event_passesHLT_Ele27_eta2p1_WP85_Gsf);
   fChain->SetBranchAddress("Event_prescaleHLT_Ele27_eta2p1_WP85_Gsf", &Event_prescaleHLT_Ele27_eta2p1_WP85_Gsf, &b_Event_prescaleHLT_Ele27_eta2p1_WP85_Gsf);
   fChain->SetBranchAddress("Event_passesHLT_IsoMu24_IterTrk02", &Event_passesHLT_IsoMu24_IterTrk02, &b_Event_passesHLT_IsoMu24_IterTrk02);
   fChain->SetBranchAddress("Event_prescaleHLT_IsoMu24_IterTrk02", &Event_prescaleHLT_IsoMu24_IterTrk02, &b_Event_prescaleHLT_IsoMu24_IterTrk02);
   fChain->SetBranchAddress("Event_passesHLT_IsoMu24_eta2p1_IterTrk02_v1", &Event_passesHLT_IsoMu24_eta2p1_IterTrk02_v1, &b_Event_passesHLT_IsoMu24_eta2p1_IterTrk02_v1);
   fChain->SetBranchAddress("Event_prescaleHLT_IsoMu24_eta2p1_IterTrk02_v1", &Event_prescaleHLT_IsoMu24_eta2p1_IterTrk02_v1, &b_Event_prescaleHLT_IsoMu24_eta2p1_IterTrk02_v1);
   fChain->SetBranchAddress("Event_passesHLT_Ele32_eta2p1_WP85_Gsf_v1", &Event_passesHLT_Ele32_eta2p1_WP85_Gsf_v1, &b_Event_passesHLT_Ele32_eta2p1_WP85_Gsf_v1);
   fChain->SetBranchAddress("Event_prescaleHLT_Ele32_eta2p1_WP85_Gsf_v1", &Event_prescaleHLT_Ele32_eta2p1_WP85_Gsf_v1, &b_Event_prescaleHLT_Ele32_eta2p1_WP85_Gsf_v1);
   fChain->SetBranchAddress("Event_passesHLT_PFMET120_NoiseCleaned_BTagCSV07", &Event_passesHLT_PFMET120_NoiseCleaned_BTagCSV07, &b_Event_passesHLT_PFMET120_NoiseCleaned_BTagCSV07);
   fChain->SetBranchAddress("Event_prescaleHLT_PFMET120_NoiseCleaned_BTagCSV07", &Event_prescaleHLT_PFMET120_NoiseCleaned_BTagCSV07, &b_Event_prescaleHLT_PFMET120_NoiseCleaned_BTagCSV07);
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

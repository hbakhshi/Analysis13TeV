//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Jul 20 17:07:07 2015 by ROOT version 6.02/04
// from TTree ttDM__noSyst/ttDM__noSyst
// found on file: /home/hbakhshi//Desktop/SingleTop/Sync.root
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
   Float_t         muons_Mass[10];
   Float_t         muons_Eta[10];
   Float_t         muons_Phi[10];
   Float_t         muons_Charge[10];
   Float_t         muons_IsLooseMuon[10];
   Float_t         muons_IsSoftMuon[10];
   Float_t         muons_IsTightMuon[10];
   Float_t         muons_D0[10];
   Float_t         muons_D0err[10];
   Float_t         muons_Dz[10];
   Float_t         muons_Dzerr[10];
   Float_t         muons_GenMuonCharge[10];
   Float_t         muons_GenMuonEta[10];
   Float_t         muons_GenMuonPt[10];
   Float_t         muons_GenMuonE[10];
   Float_t         muons_GenMuonPhi[10];
   Float_t         muons_GenMuonY[10];
   Float_t         muons_GlbTrkNormChi2[10];
   Float_t         muons_InTrkNormChi2[10];
   Float_t         muons_IsGlobalMuon[10];
   Float_t         muons_IsPFMuon[10];
   Float_t         muons_IsTrackerMuon[10];
   Float_t         muons_Iso04[10];
   Float_t         muons_NumberMatchedStations[10];
   Float_t         muons_NumberOfPixelLayers[10];
   Float_t         muons_NumberOfValidTrackerHits[10];
   Float_t         muons_NumberTrackerLayers[10];
   Float_t         muons_NumberValidMuonHits[10];
   Float_t         muons_NumberValidPixelHits[10];
   Float_t         muons_SumChargedHadronPt[10];
   Float_t         muons_SumNeutralHadronPt[10];
   Float_t         muons_SumPUPt[10];
   Float_t         muons_SumPhotonPt[10];
   Float_t         muons_Y[10];
   Float_t         muons_SFTrigger[10];
   Float_t         muons_SFReco[10];
   Float_t         muons_isQCD[10];
   Int_t           muons_size;
   Float_t         electrons_E[10];
   Float_t         electrons_Pt[10];
   Float_t         electrons_Mass[10];
   Float_t         electrons_Phi[10];
   Float_t         electrons_Charge[10];
   Float_t         electrons_D0[10];
   Float_t         electrons_Dz[10];
   Float_t         electrons_Eta[10];
   Float_t         electrons_HoE[10];
   Float_t         electrons_Iso03[10];
   Float_t         electrons_Y[10];
   Float_t         electrons_dEtaIn[10];
   Float_t         electrons_dPhiIn[10];
   Float_t         electrons_missHits[10];
   Float_t         electrons_full5x5siee[10];
   Float_t         electrons_ooEmooP[10];
   Float_t         electrons_hasMatchedConVeto[10];
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
   Float_t         jetsAK4_Mass[20];
   Float_t         jetsAK4_Eta[20];
   Float_t         jetsAK4_PartonFlavour[20];
   Float_t         jetsAK4_Phi[20];
   Float_t         jetsAK4_CSV[20];
   Float_t         jetsAK4_CSVV1[20];
   Float_t         jetsAK4_Charge[20];
   Float_t         jetsAK4_ChargeMuEnergy[20];
   Float_t         jetsAK4_ChargedHadronMultiplicity[20];
   Float_t         jetsAK4_ElectronEnergy[20];
   Float_t         jetsAK4_GenJetCharge[20];
   Float_t         jetsAK4_GenJetE[20];
   Float_t         jetsAK4_GenJetEta[20];
   Float_t         jetsAK4_GenJetPhi[20];
   Float_t         jetsAK4_GenJetPt[20];
   Float_t         jetsAK4_GenJetY[20];
   Float_t         jetsAK4_GenPartonCharge[20];
   Float_t         jetsAK4_GenPartonE[20];
   Float_t         jetsAK4_GenPartonEta[20];
   Float_t         jetsAK4_GenPartonPhi[20];
   Float_t         jetsAK4_GenPartonPt[20];
   Float_t         jetsAK4_GenPartonY[20];
   Float_t         jetsAK4_HFEMEnergy[20];
   Float_t         jetsAK4_HFEMMultiplicity[20];
   Float_t         jetsAK4_HFHadronEnergy[20];
   Float_t         jetsAK4_HFHadronMultiplicity[20];
   Float_t         jetsAK4_HadronFlavour[20];
   Float_t         jetsAK4_SmearedE[20];
   Float_t         jetsAK4_SmearedPt[20];
   Float_t         jetsAK4_SmearedPEta[20];
   Float_t         jetsAK4_SmearedPhi[20];
   Float_t         jetsAK4_Y[20];
   Float_t         jetsAK4_electronMultiplicity[20];
   Float_t         jetsAK4_muonMultiplicity[20];
   Float_t         jetsAK4_neutralHadronMultiplicity[20];
   Float_t         jetsAK4_neutralMultiplicity[20];
   Float_t         jetsAK4_photonMultiplicity[20];
   Float_t         jetsAK4_numberOfDaughters[20];
   Float_t         jetsAK4_chargedHadronEnergy[20];
   Float_t         jetsAK4_chargedMultiplicity[20];
   Float_t         jetsAK4_chargedEmEnergy[20];
   Float_t         jetsAK4_MuonEnergy[20];
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
   Float_t         jetsAK8_E[4];
   Float_t         jetsAK8_Pt[4];
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
   Float_t         jetsAK8_CorrPt[4];
   Float_t         jetsAK8_CorrE[4];
   Float_t         jetsAK8_isType1[4];
   Float_t         jetsAK8_isType2[4];
   Float_t         jetsAK8_TopPt[4];
   Float_t         jetsAK8_TopEta[4];
   Float_t         jetsAK8_TopPhi[4];
   Float_t         jetsAK8_TopE[4];
   Float_t         jetsAK8_TopMass[4];
   Float_t         jetsAK8_TopWMass[4];
   Float_t         jetsAK8_nJ[4];
   Float_t         jetsAK8_nCSVM[4];
   Int_t           jetsAK8_size;
   Float_t         subjetsAK8_E[10];
   Float_t         subjetsAK8_Pt[10];
   Float_t         subjetsAK8_Mass[10];
   Float_t         subjetsAK8_Eta[10];
   Float_t         subjetsAK8_Phi[10];
   Int_t           subjetsAK8_size;
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
   Float_t         Event_Mt2w;
   Float_t         Event_category;
   Float_t         Event_nMuonsSF;
   Float_t         Event_nCSVTJets;
   Float_t         Event_nCSVMJets;
   Float_t         Event_nCSVLJets;
   Float_t         Event_nTightJets;
   Float_t         Event_nLooseJets;
   Float_t         Event_nType1TopJets;
   Float_t         Event_nType2TopJets;
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
   Float_t         Event_EventNumberI;
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
   Float_t         Event_passesHLT_IsoMu20_v1;
   Float_t         Event_prescaleHLT_IsoMu20_v1;
   Float_t         Event_passesHLT_IsoMu20_v2;
   Float_t         Event_prescaleHLT_IsoMu20_v2;
   Float_t         Event_passesHLT_IsoMu20_eta2p1_v1;
   Float_t         Event_prescaleHLT_IsoMu20_eta2p1_v1;
   Float_t         Event_passesHLT_IsoMu20_eta2p1_v2;
   Float_t         Event_prescaleHLT_IsoMu20_eta2p1_v2;
   Float_t         Event_passesHLT_IsoTkMu20_v1;
   Float_t         Event_prescaleHLT_IsoTkMu20_v1;
   Float_t         Event_passesHLT_IsoTkMu20_v2;
   Float_t         Event_prescaleHLT_IsoTkMu20_v2;
   Float_t         Event_passesHLT_IsoTkMu20_eta2p1_v1;
   Float_t         Event_prescaleHLT_IsoTkMu20_eta2p1_v1;
   Float_t         Event_passesHLT_IsoTkMu20_eta2p1_v2HLT_IsoMu20_eta2p1_IterTrk02_v1;
   Float_t         Event_prescaleHLT_IsoTkMu20_eta2p1_v2HLT_IsoMu20_eta2p1_IterTrk02_v1;
   Float_t         Event_passesLeptonicTriggers;
   Float_t         Event_passesHadronicTriggers;
   ULong64_t       Event_EventNumber;

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
   TBranch        *b_muons_Mass;   //!
   TBranch        *b_muons_Eta;   //!
   TBranch        *b_muons_Phi;   //!
   TBranch        *b_muons_Charge;   //!
   TBranch        *b_muons_IsLooseMuon;   //!
   TBranch        *b_muons_IsSoftMuon;   //!
   TBranch        *b_muons_IsTightMuon;   //!
   TBranch        *b_muons_D0;   //!
   TBranch        *b_muons_D0err;   //!
   TBranch        *b_muons_Dz;   //!
   TBranch        *b_muons_Dzerr;   //!
   TBranch        *b_muons_GenMuonCharge;   //!
   TBranch        *b_muons_GenMuonEta;   //!
   TBranch        *b_muons_GenMuonPt;   //!
   TBranch        *b_muons_GenMuonE;   //!
   TBranch        *b_muons_GenMuonPhi;   //!
   TBranch        *b_muons_GenMuonY;   //!
   TBranch        *b_muons_GlbTrkNormChi2;   //!
   TBranch        *b_muons_InTrkNormChi2;   //!
   TBranch        *b_muons_IsGlobalMuon;   //!
   TBranch        *b_muons_IsPFMuon;   //!
   TBranch        *b_muons_IsTrackerMuon;   //!
   TBranch        *b_muons_Iso04;   //!
   TBranch        *b_muons_NumberMatchedStations;   //!
   TBranch        *b_muons_NumberOfPixelLayers;   //!
   TBranch        *b_muons_NumberOfValidTrackerHits;   //!
   TBranch        *b_muons_NumberTrackerLayers;   //!
   TBranch        *b_muons_NumberValidMuonHits;   //!
   TBranch        *b_muons_NumberValidPixelHits;   //!
   TBranch        *b_muons_SumChargedHadronPt;   //!
   TBranch        *b_muons_SumNeutralHadronPt;   //!
   TBranch        *b_muons_SumPUPt;   //!
   TBranch        *b_muons_SumPhotonPt;   //!
   TBranch        *b_muons_Y;   //!
   TBranch        *b_muons_SFTrigger;   //!
   TBranch        *b_muons_SFReco;   //!
   TBranch        *b_muons_isQCD;   //!
   TBranch        *b_muons_size;   //!
   TBranch        *b_electrons_E;   //!
   TBranch        *b_electrons_Pt;   //!
   TBranch        *b_electrons_Mass;   //!
   TBranch        *b_electrons_Phi;   //!
   TBranch        *b_electrons_Charge;   //!
   TBranch        *b_electrons_D0;   //!
   TBranch        *b_electrons_Dz;   //!
   TBranch        *b_electrons_Eta;   //!
   TBranch        *b_electrons_HoE;   //!
   TBranch        *b_electrons_Iso03;   //!
   TBranch        *b_electrons_Y;   //!
   TBranch        *b_electrons_dEtaIn;   //!
   TBranch        *b_electrons_dPhiIn;   //!
   TBranch        *b_electrons_missHits;   //!
   TBranch        *b_electrons_full5x5siee;   //!
   TBranch        *b_electrons_ooEmooP;   //!
   TBranch        *b_electrons_hasMatchedConVeto;   //!
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
   TBranch        *b_jetsAK4_Mass;   //!
   TBranch        *b_jetsAK4_Eta;   //!
   TBranch        *b_jetsAK4_PartonFlavour;   //!
   TBranch        *b_jetsAK4_Phi;   //!
   TBranch        *b_jetsAK4_CSV;   //!
   TBranch        *b_jetsAK4_CSVV1;   //!
   TBranch        *b_jetsAK4_Charge;   //!
   TBranch        *b_jetsAK4_ChargeMuEnergy;   //!
   TBranch        *b_jetsAK4_ChargedHadronMultiplicity;   //!
   TBranch        *b_jetsAK4_ElectronEnergy;   //!
   TBranch        *b_jetsAK4_GenJetCharge;   //!
   TBranch        *b_jetsAK4_GenJetE;   //!
   TBranch        *b_jetsAK4_GenJetEta;   //!
   TBranch        *b_jetsAK4_GenJetPhi;   //!
   TBranch        *b_jetsAK4_GenJetPt;   //!
   TBranch        *b_jetsAK4_GenJetY;   //!
   TBranch        *b_jetsAK4_GenPartonCharge;   //!
   TBranch        *b_jetsAK4_GenPartonE;   //!
   TBranch        *b_jetsAK4_GenPartonEta;   //!
   TBranch        *b_jetsAK4_GenPartonPhi;   //!
   TBranch        *b_jetsAK4_GenPartonPt;   //!
   TBranch        *b_jetsAK4_GenPartonY;   //!
   TBranch        *b_jetsAK4_HFEMEnergy;   //!
   TBranch        *b_jetsAK4_HFEMMultiplicity;   //!
   TBranch        *b_jetsAK4_HFHadronEnergy;   //!
   TBranch        *b_jetsAK4_HFHadronMultiplicity;   //!
   TBranch        *b_jetsAK4_HadronFlavour;   //!
   TBranch        *b_jetsAK4_SmearedE;   //!
   TBranch        *b_jetsAK4_SmearedPt;   //!
   TBranch        *b_jetsAK4_SmearedPEta;   //!
   TBranch        *b_jetsAK4_SmearedPhi;   //!
   TBranch        *b_jetsAK4_Y;   //!
   TBranch        *b_jetsAK4_electronMultiplicity;   //!
   TBranch        *b_jetsAK4_muonMultiplicity;   //!
   TBranch        *b_jetsAK4_neutralHadronMultiplicity;   //!
   TBranch        *b_jetsAK4_neutralMultiplicity;   //!
   TBranch        *b_jetsAK4_photonMultiplicity;   //!
   TBranch        *b_jetsAK4_numberOfDaughters;   //!
   TBranch        *b_jetsAK4_chargedHadronEnergy;   //!
   TBranch        *b_jetsAK4_chargedMultiplicity;   //!
   TBranch        *b_jetsAK4_chargedEmEnergy;   //!
   TBranch        *b_jetsAK4_MuonEnergy;   //!
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
   TBranch        *b_jetsAK8_E;   //!
   TBranch        *b_jetsAK8_Pt;   //!
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
   TBranch        *b_jetsAK8_CorrPt;   //!
   TBranch        *b_jetsAK8_CorrE;   //!
   TBranch        *b_jetsAK8_isType1;   //!
   TBranch        *b_jetsAK8_isType2;   //!
   TBranch        *b_jetsAK8_TopPt;   //!
   TBranch        *b_jetsAK8_TopEta;   //!
   TBranch        *b_jetsAK8_TopPhi;   //!
   TBranch        *b_jetsAK8_TopE;   //!
   TBranch        *b_jetsAK8_TopMass;   //!
   TBranch        *b_jetsAK8_TopWMass;   //!
   TBranch        *b_jetsAK8_nJ;   //!
   TBranch        *b_jetsAK8_nCSVM;   //!
   TBranch        *b_jetsAK8_size;   //!
   TBranch        *b_subjetsAK8_E;   //!
   TBranch        *b_subjetsAK8_Pt;   //!
   TBranch        *b_subjetsAK8_Mass;   //!
   TBranch        *b_subjetsAK8_Eta;   //!
   TBranch        *b_subjetsAK8_Phi;   //!
   TBranch        *b_subjetsAK8_size;   //!
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
   TBranch        *b_Event_Mt2w;   //!
   TBranch        *b_Event_category;   //!
   TBranch        *b_Event_nMuonsSF;   //!
   TBranch        *b_Event_nCSVTJets;   //!
   TBranch        *b_Event_nCSVMJets;   //!
   TBranch        *b_Event_nCSVLJets;   //!
   TBranch        *b_Event_nTightJets;   //!
   TBranch        *b_Event_nLooseJets;   //!
   TBranch        *b_Event_nType1TopJets;   //!
   TBranch        *b_Event_nType2TopJets;   //!
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
   TBranch        *b_Event_EventNumberI;   //!
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
   TBranch        *b_Event_passesHLT_IsoMu20_v1;   //!
   TBranch        *b_Event_prescaleHLT_IsoMu20_v1;   //!
   TBranch        *b_Event_passesHLT_IsoMu20_v2;   //!
   TBranch        *b_Event_prescaleHLT_IsoMu20_v2;   //!
   TBranch        *b_Event_passesHLT_IsoMu20_eta2p1_v1;   //!
   TBranch        *b_Event_prescaleHLT_IsoMu20_eta2p1_v1;   //!
   TBranch        *b_Event_passesHLT_IsoMu20_eta2p1_v2;   //!
   TBranch        *b_Event_prescaleHLT_IsoMu20_eta2p1_v2;   //!
   TBranch        *b_Event_passesHLT_IsoTkMu20_v1;   //!
   TBranch        *b_Event_prescaleHLT_IsoTkMu20_v1;   //!
   TBranch        *b_Event_passesHLT_IsoTkMu20_v2;   //!
   TBranch        *b_Event_prescaleHLT_IsoTkMu20_v2;   //!
   TBranch        *b_Event_passesHLT_IsoTkMu20_eta2p1_v1;   //!
   TBranch        *b_Event_prescaleHLT_IsoTkMu20_eta2p1_v1;   //!
   TBranch        *b_Event_passesHLT_IsoTkMu20_eta2p1_v2HLT_IsoMu20_eta2p1_IterTrk02_v1;   //!
   TBranch        *b_Event_prescaleHLT_IsoTkMu20_eta2p1_v2HLT_IsoMu20_eta2p1_IterTrk02_v1;   //!
   TBranch        *b_Event_passesLeptonicTriggers;   //!
   TBranch        *b_Event_passesHadronicTriggers;   //!
   TBranch        *b_Event_EventNumber;   //!

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
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/home/hbakhshi//Desktop/SingleTop/Sync.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/home/hbakhshi//Desktop/SingleTop/Sync.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("/home/hbakhshi//Desktop/SingleTop/Sync.root:/DMTreesDumper");
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
   fChain->SetBranchAddress("muons_Mass", muons_Mass, &b_muons_Mass);
   fChain->SetBranchAddress("muons_Eta", muons_Eta, &b_muons_Eta);
   fChain->SetBranchAddress("muons_Phi", muons_Phi, &b_muons_Phi);
   fChain->SetBranchAddress("muons_Charge", muons_Charge, &b_muons_Charge);
   fChain->SetBranchAddress("muons_IsLooseMuon", muons_IsLooseMuon, &b_muons_IsLooseMuon);
   fChain->SetBranchAddress("muons_IsSoftMuon", muons_IsSoftMuon, &b_muons_IsSoftMuon);
   fChain->SetBranchAddress("muons_IsTightMuon", muons_IsTightMuon, &b_muons_IsTightMuon);
   fChain->SetBranchAddress("muons_D0", muons_D0, &b_muons_D0);
   fChain->SetBranchAddress("muons_D0err", muons_D0err, &b_muons_D0err);
   fChain->SetBranchAddress("muons_Dz", muons_Dz, &b_muons_Dz);
   fChain->SetBranchAddress("muons_Dzerr", muons_Dzerr, &b_muons_Dzerr);
   fChain->SetBranchAddress("muons_GenMuonCharge", muons_GenMuonCharge, &b_muons_GenMuonCharge);
   fChain->SetBranchAddress("muons_GenMuonEta", muons_GenMuonEta, &b_muons_GenMuonEta);
   fChain->SetBranchAddress("muons_GenMuonPt", muons_GenMuonPt, &b_muons_GenMuonPt);
   fChain->SetBranchAddress("muons_GenMuonE", muons_GenMuonE, &b_muons_GenMuonE);
   fChain->SetBranchAddress("muons_GenMuonPhi", muons_GenMuonPhi, &b_muons_GenMuonPhi);
   fChain->SetBranchAddress("muons_GenMuonY", muons_GenMuonY, &b_muons_GenMuonY);
   fChain->SetBranchAddress("muons_GlbTrkNormChi2", muons_GlbTrkNormChi2, &b_muons_GlbTrkNormChi2);
   fChain->SetBranchAddress("muons_InTrkNormChi2", muons_InTrkNormChi2, &b_muons_InTrkNormChi2);
   fChain->SetBranchAddress("muons_IsGlobalMuon", muons_IsGlobalMuon, &b_muons_IsGlobalMuon);
   fChain->SetBranchAddress("muons_IsPFMuon", muons_IsPFMuon, &b_muons_IsPFMuon);
   fChain->SetBranchAddress("muons_IsTrackerMuon", muons_IsTrackerMuon, &b_muons_IsTrackerMuon);
   fChain->SetBranchAddress("muons_Iso04", muons_Iso04, &b_muons_Iso04);
   fChain->SetBranchAddress("muons_NumberMatchedStations", muons_NumberMatchedStations, &b_muons_NumberMatchedStations);
   fChain->SetBranchAddress("muons_NumberOfPixelLayers", muons_NumberOfPixelLayers, &b_muons_NumberOfPixelLayers);
   fChain->SetBranchAddress("muons_NumberOfValidTrackerHits", muons_NumberOfValidTrackerHits, &b_muons_NumberOfValidTrackerHits);
   fChain->SetBranchAddress("muons_NumberTrackerLayers", muons_NumberTrackerLayers, &b_muons_NumberTrackerLayers);
   fChain->SetBranchAddress("muons_NumberValidMuonHits", muons_NumberValidMuonHits, &b_muons_NumberValidMuonHits);
   fChain->SetBranchAddress("muons_NumberValidPixelHits", muons_NumberValidPixelHits, &b_muons_NumberValidPixelHits);
   fChain->SetBranchAddress("muons_SumChargedHadronPt", muons_SumChargedHadronPt, &b_muons_SumChargedHadronPt);
   fChain->SetBranchAddress("muons_SumNeutralHadronPt", muons_SumNeutralHadronPt, &b_muons_SumNeutralHadronPt);
   fChain->SetBranchAddress("muons_SumPUPt", muons_SumPUPt, &b_muons_SumPUPt);
   fChain->SetBranchAddress("muons_SumPhotonPt", muons_SumPhotonPt, &b_muons_SumPhotonPt);
   fChain->SetBranchAddress("muons_Y", muons_Y, &b_muons_Y);
   fChain->SetBranchAddress("muons_SFTrigger", muons_SFTrigger, &b_muons_SFTrigger);
   fChain->SetBranchAddress("muons_SFReco", muons_SFReco, &b_muons_SFReco);
   fChain->SetBranchAddress("muons_isQCD", muons_isQCD, &b_muons_isQCD);
   fChain->SetBranchAddress("muons_size", &muons_size, &b_muons_size);
   fChain->SetBranchAddress("electrons_E", electrons_E, &b_electrons_E);
   fChain->SetBranchAddress("electrons_Pt", electrons_Pt, &b_electrons_Pt);
   fChain->SetBranchAddress("electrons_Mass", electrons_Mass, &b_electrons_Mass);
   fChain->SetBranchAddress("electrons_Eta", electrons_Eta, &b_electrons_Eta);
   fChain->SetBranchAddress("electrons_Phi", electrons_Phi, &b_electrons_Phi);
   fChain->SetBranchAddress("electrons_Charge", electrons_Charge, &b_electrons_Charge);
   fChain->SetBranchAddress("electrons_D0", electrons_D0, &b_electrons_D0);
   fChain->SetBranchAddress("electrons_Dz", electrons_Dz, &b_electrons_Dz);
//    fChain->SetBranchAddress("electrons_Eta", electrons_Eta, &b_electrons_Eta);
   fChain->SetBranchAddress("electrons_HoE", electrons_HoE, &b_electrons_HoE);
   fChain->SetBranchAddress("electrons_Iso03", electrons_Iso03, &b_electrons_Iso03);
   fChain->SetBranchAddress("electrons_Y", electrons_Y, &b_electrons_Y);
   fChain->SetBranchAddress("electrons_dEtaIn", electrons_dEtaIn, &b_electrons_dEtaIn);
   fChain->SetBranchAddress("electrons_dPhiIn", electrons_dPhiIn, &b_electrons_dPhiIn);
   fChain->SetBranchAddress("electrons_missHits", electrons_missHits, &b_electrons_missHits);
   fChain->SetBranchAddress("electrons_full5x5siee", electrons_full5x5siee, &b_electrons_full5x5siee);
   fChain->SetBranchAddress("electrons_ooEmooP", electrons_ooEmooP, &b_electrons_ooEmooP);
   fChain->SetBranchAddress("electrons_hasMatchedConVeto", electrons_hasMatchedConVeto, &b_electrons_hasMatchedConVeto);
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
   fChain->SetBranchAddress("jetsAK4_Mass", jetsAK4_Mass, &b_jetsAK4_Mass);
   fChain->SetBranchAddress("jetsAK4_Eta", jetsAK4_Eta, &b_jetsAK4_Eta);
   fChain->SetBranchAddress("jetsAK4_Phi", jetsAK4_Phi, &b_jetsAK4_Phi);
   fChain->SetBranchAddress("jetsAK4_PartonFlavour", jetsAK4_PartonFlavour, &b_jetsAK4_PartonFlavour);
//    fChain->SetBranchAddress("jetsAK4_Phi", jetsAK4_Phi, &b_jetsAK4_Phi);
   fChain->SetBranchAddress("jetsAK4_CSV", jetsAK4_CSV, &b_jetsAK4_CSV);
   fChain->SetBranchAddress("jetsAK4_CSVV1", jetsAK4_CSVV1, &b_jetsAK4_CSVV1);
   fChain->SetBranchAddress("jetsAK4_Charge", jetsAK4_Charge, &b_jetsAK4_Charge);
   fChain->SetBranchAddress("jetsAK4_ChargeMuEnergy", jetsAK4_ChargeMuEnergy, &b_jetsAK4_ChargeMuEnergy);
   fChain->SetBranchAddress("jetsAK4_ChargedHadronMultiplicity", jetsAK4_ChargedHadronMultiplicity, &b_jetsAK4_ChargedHadronMultiplicity);
   fChain->SetBranchAddress("jetsAK4_ElectronEnergy", jetsAK4_ElectronEnergy, &b_jetsAK4_ElectronEnergy);
   fChain->SetBranchAddress("jetsAK4_GenJetCharge", jetsAK4_GenJetCharge, &b_jetsAK4_GenJetCharge);
   fChain->SetBranchAddress("jetsAK4_GenJetE", jetsAK4_GenJetE, &b_jetsAK4_GenJetE);
   fChain->SetBranchAddress("jetsAK4_GenJetEta", jetsAK4_GenJetEta, &b_jetsAK4_GenJetEta);
   fChain->SetBranchAddress("jetsAK4_GenJetPhi", jetsAK4_GenJetPhi, &b_jetsAK4_GenJetPhi);
   fChain->SetBranchAddress("jetsAK4_GenJetPt", jetsAK4_GenJetPt, &b_jetsAK4_GenJetPt);
   fChain->SetBranchAddress("jetsAK4_GenJetY", jetsAK4_GenJetY, &b_jetsAK4_GenJetY);
   fChain->SetBranchAddress("jetsAK4_GenPartonCharge", jetsAK4_GenPartonCharge, &b_jetsAK4_GenPartonCharge);
   fChain->SetBranchAddress("jetsAK4_GenPartonE", jetsAK4_GenPartonE, &b_jetsAK4_GenPartonE);
   fChain->SetBranchAddress("jetsAK4_GenPartonEta", jetsAK4_GenPartonEta, &b_jetsAK4_GenPartonEta);
   fChain->SetBranchAddress("jetsAK4_GenPartonPhi", jetsAK4_GenPartonPhi, &b_jetsAK4_GenPartonPhi);
   fChain->SetBranchAddress("jetsAK4_GenPartonPt", jetsAK4_GenPartonPt, &b_jetsAK4_GenPartonPt);
   fChain->SetBranchAddress("jetsAK4_GenPartonY", jetsAK4_GenPartonY, &b_jetsAK4_GenPartonY);
   fChain->SetBranchAddress("jetsAK4_HFEMEnergy", jetsAK4_HFEMEnergy, &b_jetsAK4_HFEMEnergy);
   fChain->SetBranchAddress("jetsAK4_HFEMMultiplicity", jetsAK4_HFEMMultiplicity, &b_jetsAK4_HFEMMultiplicity);
   fChain->SetBranchAddress("jetsAK4_HFHadronEnergy", jetsAK4_HFHadronEnergy, &b_jetsAK4_HFHadronEnergy);
   fChain->SetBranchAddress("jetsAK4_HFHadronMultiplicity", jetsAK4_HFHadronMultiplicity, &b_jetsAK4_HFHadronMultiplicity);
   fChain->SetBranchAddress("jetsAK4_HadronFlavour", jetsAK4_HadronFlavour, &b_jetsAK4_HadronFlavour);
   fChain->SetBranchAddress("jetsAK4_SmearedE", jetsAK4_SmearedE, &b_jetsAK4_SmearedE);
   fChain->SetBranchAddress("jetsAK4_SmearedPt", jetsAK4_SmearedPt, &b_jetsAK4_SmearedPt);
   fChain->SetBranchAddress("jetsAK4_SmearedPEta", jetsAK4_SmearedPEta, &b_jetsAK4_SmearedPEta);
   fChain->SetBranchAddress("jetsAK4_SmearedPhi", jetsAK4_SmearedPhi, &b_jetsAK4_SmearedPhi);
   fChain->SetBranchAddress("jetsAK4_Y", jetsAK4_Y, &b_jetsAK4_Y);
   fChain->SetBranchAddress("jetsAK4_electronMultiplicity", jetsAK4_electronMultiplicity, &b_jetsAK4_electronMultiplicity);
   fChain->SetBranchAddress("jetsAK4_muonMultiplicity", jetsAK4_muonMultiplicity, &b_jetsAK4_muonMultiplicity);
   fChain->SetBranchAddress("jetsAK4_neutralHadronMultiplicity", jetsAK4_neutralHadronMultiplicity, &b_jetsAK4_neutralHadronMultiplicity);
   fChain->SetBranchAddress("jetsAK4_neutralMultiplicity", jetsAK4_neutralMultiplicity, &b_jetsAK4_neutralMultiplicity);
   fChain->SetBranchAddress("jetsAK4_photonMultiplicity", jetsAK4_photonMultiplicity, &b_jetsAK4_photonMultiplicity);
   fChain->SetBranchAddress("jetsAK4_numberOfDaughters", jetsAK4_numberOfDaughters, &b_jetsAK4_numberOfDaughters);
   fChain->SetBranchAddress("jetsAK4_chargedHadronEnergy", jetsAK4_chargedHadronEnergy, &b_jetsAK4_chargedHadronEnergy);
   fChain->SetBranchAddress("jetsAK4_chargedMultiplicity", jetsAK4_chargedMultiplicity, &b_jetsAK4_chargedMultiplicity);
   fChain->SetBranchAddress("jetsAK4_chargedEmEnergy", jetsAK4_chargedEmEnergy, &b_jetsAK4_chargedEmEnergy);
   fChain->SetBranchAddress("jetsAK4_MuonEnergy", jetsAK4_MuonEnergy, &b_jetsAK4_MuonEnergy);
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
   fChain->SetBranchAddress("jetsAK8_CorrPt", jetsAK8_CorrPt, &b_jetsAK8_CorrPt);
   fChain->SetBranchAddress("jetsAK8_CorrE", jetsAK8_CorrE, &b_jetsAK8_CorrE);
   fChain->SetBranchAddress("jetsAK8_isType1", jetsAK8_isType1, &b_jetsAK8_isType1);
   fChain->SetBranchAddress("jetsAK8_isType2", jetsAK8_isType2, &b_jetsAK8_isType2);
   fChain->SetBranchAddress("jetsAK8_TopPt", jetsAK8_TopPt, &b_jetsAK8_TopPt);
   fChain->SetBranchAddress("jetsAK8_TopEta", jetsAK8_TopEta, &b_jetsAK8_TopEta);
   fChain->SetBranchAddress("jetsAK8_TopPhi", jetsAK8_TopPhi, &b_jetsAK8_TopPhi);
   fChain->SetBranchAddress("jetsAK8_TopE", jetsAK8_TopE, &b_jetsAK8_TopE);
   fChain->SetBranchAddress("jetsAK8_TopMass", jetsAK8_TopMass, &b_jetsAK8_TopMass);
   fChain->SetBranchAddress("jetsAK8_TopWMass", jetsAK8_TopWMass, &b_jetsAK8_TopWMass);
   fChain->SetBranchAddress("jetsAK8_nJ", jetsAK8_nJ, &b_jetsAK8_nJ);
   fChain->SetBranchAddress("jetsAK8_nCSVM", jetsAK8_nCSVM, &b_jetsAK8_nCSVM);
   fChain->SetBranchAddress("jetsAK8_size", &jetsAK8_size, &b_jetsAK8_size);
   fChain->SetBranchAddress("subjetsAK8_E", subjetsAK8_E, &b_subjetsAK8_E);
   fChain->SetBranchAddress("subjetsAK8_Pt", subjetsAK8_Pt, &b_subjetsAK8_Pt);
   fChain->SetBranchAddress("subjetsAK8_Mass", subjetsAK8_Mass, &b_subjetsAK8_Mass);
   fChain->SetBranchAddress("subjetsAK8_Eta", subjetsAK8_Eta, &b_subjetsAK8_Eta);
   fChain->SetBranchAddress("subjetsAK8_Phi", subjetsAK8_Phi, &b_subjetsAK8_Phi);
   fChain->SetBranchAddress("subjetsAK8_size", &subjetsAK8_size, &b_subjetsAK8_size);
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
   fChain->SetBranchAddress("Event_Mt2w", &Event_Mt2w, &b_Event_Mt2w);
   fChain->SetBranchAddress("Event_category", &Event_category, &b_Event_category);
   fChain->SetBranchAddress("Event_nMuonsSF", &Event_nMuonsSF, &b_Event_nMuonsSF);
   fChain->SetBranchAddress("Event_nCSVTJets", &Event_nCSVTJets, &b_Event_nCSVTJets);
   fChain->SetBranchAddress("Event_nCSVMJets", &Event_nCSVMJets, &b_Event_nCSVMJets);
   fChain->SetBranchAddress("Event_nCSVLJets", &Event_nCSVLJets, &b_Event_nCSVLJets);
   fChain->SetBranchAddress("Event_nTightJets", &Event_nTightJets, &b_Event_nTightJets);
   fChain->SetBranchAddress("Event_nLooseJets", &Event_nLooseJets, &b_Event_nLooseJets);
   fChain->SetBranchAddress("Event_nType1TopJets", &Event_nType1TopJets, &b_Event_nType1TopJets);
   fChain->SetBranchAddress("Event_nType2TopJets", &Event_nType2TopJets, &b_Event_nType2TopJets);
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
   fChain->SetBranchAddress("Event_EventNumberI", &Event_EventNumberI, &b_Event_EventNumberI);
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
   fChain->SetBranchAddress("Event_passesHLT_IsoMu20_v1", &Event_passesHLT_IsoMu20_v1, &b_Event_passesHLT_IsoMu20_v1);
   fChain->SetBranchAddress("Event_prescaleHLT_IsoMu20_v1", &Event_prescaleHLT_IsoMu20_v1, &b_Event_prescaleHLT_IsoMu20_v1);
   fChain->SetBranchAddress("Event_passesHLT_IsoMu20_v2", &Event_passesHLT_IsoMu20_v2, &b_Event_passesHLT_IsoMu20_v2);
   fChain->SetBranchAddress("Event_prescaleHLT_IsoMu20_v2", &Event_prescaleHLT_IsoMu20_v2, &b_Event_prescaleHLT_IsoMu20_v2);
   fChain->SetBranchAddress("Event_passesHLT_IsoMu20_eta2p1_v1", &Event_passesHLT_IsoMu20_eta2p1_v1, &b_Event_passesHLT_IsoMu20_eta2p1_v1);
   fChain->SetBranchAddress("Event_prescaleHLT_IsoMu20_eta2p1_v1", &Event_prescaleHLT_IsoMu20_eta2p1_v1, &b_Event_prescaleHLT_IsoMu20_eta2p1_v1);
   fChain->SetBranchAddress("Event_passesHLT_IsoMu20_eta2p1_v2", &Event_passesHLT_IsoMu20_eta2p1_v2, &b_Event_passesHLT_IsoMu20_eta2p1_v2);
   fChain->SetBranchAddress("Event_prescaleHLT_IsoMu20_eta2p1_v2", &Event_prescaleHLT_IsoMu20_eta2p1_v2, &b_Event_prescaleHLT_IsoMu20_eta2p1_v2);
   fChain->SetBranchAddress("Event_passesHLT_IsoTkMu20_v1", &Event_passesHLT_IsoTkMu20_v1, &b_Event_passesHLT_IsoTkMu20_v1);
   fChain->SetBranchAddress("Event_prescaleHLT_IsoTkMu20_v1", &Event_prescaleHLT_IsoTkMu20_v1, &b_Event_prescaleHLT_IsoTkMu20_v1);
   fChain->SetBranchAddress("Event_passesHLT_IsoTkMu20_v2", &Event_passesHLT_IsoTkMu20_v2, &b_Event_passesHLT_IsoTkMu20_v2);
   fChain->SetBranchAddress("Event_prescaleHLT_IsoTkMu20_v2", &Event_prescaleHLT_IsoTkMu20_v2, &b_Event_prescaleHLT_IsoTkMu20_v2);
   fChain->SetBranchAddress("Event_passesHLT_IsoTkMu20_eta2p1_v1", &Event_passesHLT_IsoTkMu20_eta2p1_v1, &b_Event_passesHLT_IsoTkMu20_eta2p1_v1);
   fChain->SetBranchAddress("Event_prescaleHLT_IsoTkMu20_eta2p1_v1", &Event_prescaleHLT_IsoTkMu20_eta2p1_v1, &b_Event_prescaleHLT_IsoTkMu20_eta2p1_v1);
   fChain->SetBranchAddress("Event_passesHLT_IsoTkMu20_eta2p1_v2HLT_IsoMu20_eta2p1_IterTrk02_v1", &Event_passesHLT_IsoTkMu20_eta2p1_v2HLT_IsoMu20_eta2p1_IterTrk02_v1, &b_Event_passesHLT_IsoTkMu20_eta2p1_v2HLT_IsoMu20_eta2p1_IterTrk02_v1);
   fChain->SetBranchAddress("Event_prescaleHLT_IsoTkMu20_eta2p1_v2HLT_IsoMu20_eta2p1_IterTrk02_v1", &Event_prescaleHLT_IsoTkMu20_eta2p1_v2HLT_IsoMu20_eta2p1_IterTrk02_v1, &b_Event_prescaleHLT_IsoTkMu20_eta2p1_v2HLT_IsoMu20_eta2p1_IterTrk02_v1);
   fChain->SetBranchAddress("Event_passesLeptonicTriggers", &Event_passesLeptonicTriggers, &b_Event_passesLeptonicTriggers);
   fChain->SetBranchAddress("Event_passesHadronicTriggers", &Event_passesHadronicTriggers, &b_Event_passesHadronicTriggers);
   fChain->SetBranchAddress("Event_EventNumber", &Event_EventNumber, &b_Event_EventNumber);
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

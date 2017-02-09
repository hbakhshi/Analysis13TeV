//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Mar 18 12:22:58 2016 by ROOT version 6.02/05
// from TTree ttDM__noSyst/ttDM__noSyst
// found on file: /home/fynu/hbakhshiansohi/storage/TChannel25nsFiles/76/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/FullTrees/WJets_MG_TChannel_FullTrees_199.root
//////////////////////////////////////////////////////////

#ifndef SingleTopTree_h
#define SingleTopTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include <vector>
#include "TH2.h"
using namespace std;

#define SingleTopTreeLHEWeights_h

// Header file for the classes stored in the TTree if any.

class SingleTopTree {
public :
#ifdef SingleTopTreeLHEWeights_h
  Float_t GetPDFWeight(int i);
  Float_t GetLHEWeight(int i);
#endif

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
   Float_t         electrons_Eta[10];
   Float_t         electrons_Phi[10];
   Float_t         electrons_Iso03[10];
   Float_t         electrons_isVeto[10];
   Float_t         electrons_isLoose[10];
   Float_t         electrons_isMedium[10];
   Float_t         electrons_isTight[10];
   Float_t         electrons_vidHEEP[10];
   Float_t         electrons_vidLoose[10];
   Float_t         electrons_vidMedium[10];
   Float_t         electrons_vidTight[10];
   Float_t         electrons_vidVeto[10];
   Int_t           electrons_size;
   Float_t         jetsAK4_E[20];
   Float_t         jetsAK4_Pt[20];
   Float_t         jetsAK4_Eta[20];
   Float_t         jetsAK4_Phi[20];
   Float_t         jetsAK4_PartonFlavour[20];
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
   Float_t         Event_LHEWeight0;
   Float_t         Event_LHEWeight1;
   Float_t         Event_LHEWeight2;
   Float_t         Event_LHEWeight3;
   Float_t         Event_LHEWeight4;
   Float_t         Event_LHEWeight5;
   Float_t         Event_LHEWeight6;
   Float_t         Event_LHEWeight7;
   Float_t         Event_LHEWeight8;
   Float_t         Event_LHEWeight9;
   Float_t         Event_LHEWeight10;
   Float_t         Event_LHEWeight11;
   Float_t         Event_LHEWeight12;
   Float_t         Event_LHEWeight13;
   Float_t         Event_LHEWeight14;
   Float_t         Event_LHEWeight15;
   Float_t         Event_LHEWeight16;
   Float_t         Event_LHEWeight17;
   Float_t         Event_LHEWeight18;
   Float_t         Event_LHEWeight19;
   Float_t         Event_LHEWeight20;
   Float_t         Event_LHEWeight21;
   Float_t         Event_LHEWeight22;
   Float_t         Event_LHEWeight23;
   Float_t         Event_LHEWeight24;
   Float_t         Event_LHEWeight25;
   Float_t         Event_LHEWeight26;
   Float_t         Event_LHEWeight27;
   Float_t         Event_LHEWeight28;
   Float_t         Event_LHEWeight29;
   Float_t         Event_LHEWeight30;
   Float_t         Event_LHEWeight31;
   Float_t         Event_LHEWeight32;
   Float_t         Event_LHEWeight33;
   Float_t         Event_LHEWeight34;
   Float_t         Event_LHEWeight35;
   Float_t         Event_LHEWeight36;
   Float_t         Event_LHEWeight37;
   Float_t         Event_LHEWeight38;
   Float_t         Event_LHEWeight39;
   Float_t         Event_LHEWeight40;
   Float_t         Event_LHEWeight41;
   Float_t         Event_LHEWeight42;
   Float_t         Event_LHEWeight43;
   Float_t         Event_LHEWeight44;
   Float_t         Event_LHEWeight45;
   Float_t         Event_LHEWeight46;
   Float_t         Event_LHEWeight47;
   Float_t         Event_LHEWeight48;
   Float_t         Event_LHEWeight49;
   Float_t         Event_LHEWeight50;
   Float_t         Event_LHEWeight51;
   Float_t         Event_LHEWeight52;
   Float_t         Event_LHEWeight53;
   Float_t         Event_LHEWeight54;
   Float_t         Event_LHEWeight55;
   Float_t         Event_LHEWeight56;
   Float_t         Event_LHEWeight57;
   Float_t         Event_LHEWeight58;
   Float_t         Event_LHEWeight59;
   Float_t         Event_LHEWeight60;
   Float_t         Event_LHEWeight61;
   Float_t         Event_LHEWeight62;
   Float_t         Event_LHEWeight63;
   Float_t         Event_LHEWeight64;
   Float_t         Event_LHEWeight65;
   Float_t         Event_LHEWeight66;
   Float_t         Event_LHEWeight67;
   Float_t         Event_LHEWeight68;
   Float_t         Event_LHEWeight69;
   Float_t         Event_LHEWeight70;
   Float_t         Event_LHEWeight71;
   Float_t         Event_LHEWeight72;
   Float_t         Event_LHEWeight73;
   Float_t         Event_LHEWeight74;
   Float_t         Event_LHEWeight75;
   Float_t         Event_LHEWeight76;
   Float_t         Event_LHEWeight77;
   Float_t         Event_LHEWeight78;
   Float_t         Event_LHEWeight79;
   Float_t         Event_LHEWeight80;
   Float_t         Event_LHEWeight81;
   Float_t         Event_LHEWeight82;
   Float_t         Event_LHEWeight83;
   Float_t         Event_LHEWeight84;
   Float_t         Event_LHEWeight85;
   Float_t         Event_LHEWeight86;
   Float_t         Event_LHEWeight87;
   Float_t         Event_LHEWeight88;
   Float_t         Event_LHEWeight89;
   Float_t         Event_LHEWeight90;
   Float_t         Event_LHEWeight91;
   Float_t         Event_LHEWeight92;
   Float_t         Event_LHEWeight93;
   Float_t         Event_LHEWeight94;
   Float_t         Event_LHEWeight95;
   Float_t         Event_LHEWeight96;
   Float_t         Event_LHEWeight97;
   Float_t         Event_LHEWeight98;
   Float_t         Event_LHEWeight99;
   Float_t         Event_LHEWeight100;
   Float_t         Event_LHEWeight101;
   Float_t         Event_LHEWeight102;
   Float_t         Event_LHEWeight103;
   Float_t         Event_LHEWeight104;
   Float_t         Event_LHEWeight105;
   Float_t         Event_LHEWeight106;
   Float_t         Event_LHEWeight107;
   Float_t         Event_LHEWeight108;
   Float_t         Event_LHEWeight109;
   Float_t         Event_LHEWeight110;
   Float_t         Event_LHEWeight111;
   Float_t         Event_LHEWeight112;
   Float_t         Event_LHEWeight113;
   Float_t         Event_LHEWeight114;
   Float_t         Event_LHEWeight115;
   Float_t         Event_LHEWeight116;
   Float_t         Event_LHEWeight117;
   Float_t         Event_LHEWeight118;
   Float_t         Event_LHEWeight119;
   Float_t         Event_LHEWeight120;
   Float_t         Event_LHEWeight121;
   Float_t         Event_LHEWeight122;
   Float_t         Event_LHEWeight123;
   Float_t         Event_LHEWeight124;
   Float_t         Event_LHEWeight125;
   Float_t         Event_LHEWeight126;
   Float_t         Event_LHEWeight127;
   Float_t         Event_LHEWeight128;
   Float_t         Event_LHEWeight129;
   Float_t         Event_LHEWeight130;
   Float_t         Event_LHEWeight131;
   Float_t         Event_LHEWeight132;
   Float_t         Event_LHEWeight133;
   Float_t         Event_LHEWeight134;
   Float_t         Event_LHEWeight135;
   Float_t         Event_LHEWeight136;
   Float_t         Event_LHEWeight137;
   Float_t         Event_LHEWeight138;
   Float_t         Event_LHEWeight139;
   Float_t         Event_LHEWeight140;
   Float_t         Event_LHEWeight141;
   Float_t         Event_LHEWeight142;
   Float_t         Event_LHEWeight143;
   Float_t         Event_LHEWeight144;
   Float_t         Event_LHEWeight145;
   Float_t         Event_LHEWeight146;
   Float_t         Event_LHEWeight147;
   Float_t         Event_LHEWeight148;
   Float_t         Event_LHEWeight149;
   Float_t         Event_LHEWeight150;
   Float_t         Event_LHEWeight151;
   Float_t         Event_LHEWeight152;
   Float_t         Event_LHEWeight153;
   Float_t         Event_LHEWeight154;
   Float_t         Event_LHEWeight155;
   Float_t         Event_LHEWeight156;
   Float_t         Event_LHEWeight157;
   Float_t         Event_LHEWeight158;
   Float_t         Event_LHEWeight159;
   Float_t         Event_LHEWeight160;
   Float_t         Event_LHEWeight161;
   Float_t         Event_LHEWeight162;
   Float_t         Event_LHEWeight163;
   Float_t         Event_LHEWeight164;
   Float_t         Event_LHEWeight165;
   Float_t         Event_LHEWeight166;
   Float_t         Event_LHEWeight167;
   Float_t         Event_LHEWeight168;
   Float_t         Event_LHEWeight169;
   Float_t         Event_LHEWeight170;
   Float_t         Event_LHEWeight171;
   Float_t         Event_LHEWeight172;
   Float_t         Event_LHEWeight173;
   Float_t         Event_LHEWeight174;
   Float_t         Event_LHEWeight175;
   Float_t         Event_LHEWeight176;
   Float_t         Event_LHEWeight177;
   Float_t         Event_LHEWeight178;
   Float_t         Event_LHEWeight179;
   Float_t         Event_LHEWeight180;
   Float_t         Event_LHEWeight181;
   Float_t         Event_LHEWeight182;
   Float_t         Event_LHEWeight183;
   Float_t         Event_LHEWeight184;
   Float_t         Event_LHEWeight185;
   Float_t         Event_LHEWeight186;
   Float_t         Event_LHEWeight187;
   Float_t         Event_LHEWeight188;
   Float_t         Event_LHEWeight189;
   Float_t         Event_LHEWeight190;
   Float_t         Event_LHEWeight191;
   Float_t         Event_LHEWeight192;
   Float_t         Event_LHEWeight193;
   Float_t         Event_LHEWeight194;
   Float_t         Event_LHEWeight195;
   Float_t         Event_LHEWeight196;
   Float_t         Event_LHEWeight197;
   Float_t         Event_LHEWeight198;
   Float_t         Event_LHEWeight199;
   Float_t         Event_LHEWeight200;
   Float_t         Event_LHEWeight201;
   Float_t         Event_LHEWeight202;
   Float_t         Event_LHEWeight203;
   Float_t         Event_LHEWeight204;
   Float_t         Event_LHEWeight205;
   Float_t         Event_LHEWeight206;
   Float_t         Event_LHEWeight207;
   Float_t         Event_LHEWeight208;
   Float_t         Event_LHEWeight209;
   Float_t         Event_LHEWeight210;
   Float_t         Event_LHEWeight211;
   Float_t         Event_LHEWeight212;
   Float_t         Event_LHEWeight213;
   Float_t         Event_LHEWeight214;
   Float_t         Event_LHEWeight215;
   Float_t         Event_LHEWeight216;
   Float_t         Event_LHEWeight217;
   Float_t         Event_LHEWeight218;
   Float_t         Event_LHEWeight219;
   Float_t         Event_LHEWeight220;
   Float_t         Event_LHEWeight221;
   Float_t         Event_LHEWeight222;
   Float_t         Event_LHEWeight223;
   Float_t         Event_LHEWeight224;
   Float_t         Event_LHEWeight225;
   Float_t         Event_LHEWeight226;
   Float_t         Event_LHEWeight227;
   Float_t         Event_LHEWeight228;
   Float_t         Event_LHEWeight229;
   Float_t         Event_LHEWeight230;
   Float_t         Event_LHEWeight231;
   Float_t         Event_LHEWeight232;
   Float_t         Event_LHEWeight233;
   Float_t         Event_LHEWeight234;
   Float_t         Event_LHEWeight235;
   Float_t         Event_LHEWeight236;
   Float_t         Event_LHEWeight237;
   Float_t         Event_LHEWeight238;
   Float_t         Event_LHEWeight239;
   Float_t         Event_LHEWeight240;
   Float_t         Event_LHEWeight241;
   Float_t         Event_LHEWeight242;
   Float_t         Event_LHEWeight243;
   Float_t         Event_LHEWeight244;
   Float_t         Event_LHEWeight245;
   Float_t         Event_LHEWeight246;
   Float_t         Event_LHEWeight247;
   Float_t         Event_LHEWeight248;
   Float_t         Event_LHEWeight249;
   Float_t         Event_LHEWeight250;
   Float_t         Event_LHEWeight251;
   Float_t         Event_LHEWeight252;
   Float_t         Event_LHEWeight253;
   Float_t         Event_LHEWeight254;
   Float_t         Event_LHEWeight255;
   Float_t         Event_LHEWeight256;
   Float_t         Event_LHEWeight257;
   Float_t         Event_LHEWeight258;
   Float_t         Event_LHEWeight259;
   Float_t         Event_LHEWeight260;
   Float_t         Event_LHEWeight261;
   Float_t         Event_LHEWeight262;
   Float_t         Event_LHEWeight263;
   Float_t         Event_LHEWeight264;
   Float_t         Event_LHEWeight265;
   Float_t         Event_LHEWeight266;
   Float_t         Event_LHEWeight267;
   Float_t         Event_LHEWeight268;
   Float_t         Event_LHEWeight269;
   Float_t         Event_LHEWeight270;
   Float_t         Event_LHEWeight271;
   Float_t         Event_LHEWeight272;
   Float_t         Event_LHEWeight273;
   Float_t         Event_LHEWeight274;
   Float_t         Event_LHEWeight275;
   Float_t         Event_LHEWeight276;
   Float_t         Event_LHEWeight277;
   Float_t         Event_LHEWeight278;
   Float_t         Event_LHEWeight279;
   Float_t         Event_LHEWeight280;
   Float_t         Event_LHEWeight281;
   Float_t         Event_LHEWeight282;
   Float_t         Event_LHEWeight283;
   Float_t         Event_LHEWeight284;
   Float_t         Event_LHEWeight285;
   Float_t         Event_LHEWeight286;
   Float_t         Event_LHEWeight287;
   Float_t         Event_LHEWeight288;
   Float_t         Event_LHEWeight289;
   Float_t         Event_LHEWeight290;
   Float_t         Event_LHEWeight291;
   Float_t         Event_LHEWeight292;
   Float_t         Event_LHEWeight293;
   Float_t         Event_LHEWeight294;
   Float_t         Event_LHEWeight295;
   Float_t         Event_LHEWeight296;
   Float_t         Event_LHEWeight297;
   Float_t         Event_LHEWeight298;
   Float_t         Event_LHEWeight299;
   Float_t         Event_LHEWeight300;
   Float_t         Event_LHEWeight301;
   Float_t         Event_LHEWeight302;
   Float_t         Event_LHEWeight303;
   Float_t         Event_LHEWeight304;
   Float_t         Event_LHEWeight305;
   Float_t         Event_LHEWeight306;
   Float_t         Event_LHEWeight307;
   Float_t         Event_LHEWeight308;
   Float_t         Event_LHEWeight309;
   Float_t         Event_LHEWeight310;
   Float_t         Event_LHEWeight311;
   Float_t         Event_LHEWeight312;
   Float_t         Event_LHEWeight313;
   Float_t         Event_LHEWeight314;
   Float_t         Event_LHEWeight315;
   Float_t         Event_LHEWeight316;
   Float_t         Event_LHEWeight317;
   Float_t         Event_LHEWeight318;
   Float_t         Event_LHEWeight319;
   Float_t         Event_LHEWeight320;
   Float_t         Event_LHEWeight321;
   Float_t         Event_LHEWeight322;
   Float_t         Event_LHEWeight323;
   Float_t         Event_LHEWeight324;
   Float_t         Event_LHEWeight325;
   Float_t         Event_LHEWeight326;
   Float_t         Event_LHEWeight327;
   Float_t         Event_LHEWeight328;
   Float_t         Event_LHEWeight329;
   Float_t         Event_LHEWeight330;
   Float_t         Event_LHEWeight331;
   Float_t         Event_LHEWeight332;
   Float_t         Event_LHEWeight333;
   Float_t         Event_LHEWeight334;
   Float_t         Event_LHEWeight335;
   Float_t         Event_LHEWeight336;
   Float_t         Event_LHEWeight337;
   Float_t         Event_LHEWeight338;
   Float_t         Event_LHEWeight339;
   Float_t         Event_LHEWeight340;
   Float_t         Event_LHEWeight341;
   Float_t         Event_LHEWeight342;
   Float_t         Event_LHEWeight343;
   Float_t         Event_LHEWeight344;
   Float_t         Event_LHEWeight345;
   Float_t         Event_LHEWeight346;
   Float_t         Event_LHEWeight347;
   Float_t         Event_LHEWeight348;
   Float_t         Event_LHEWeight349;
   Float_t         Event_LHEWeight350;
   Float_t         Event_LHEWeight351;
   Float_t         Event_LHEWeight352;
   Float_t         Event_LHEWeight353;
   Float_t         Event_LHEWeight354;
   Float_t         Event_LHEWeight355;
   Float_t         Event_LHEWeight356;
   Float_t         Event_LHEWeight357;
   Float_t         Event_LHEWeight358;
   Float_t         Event_LHEWeight359;
   Float_t         Event_LHEWeight360;
   Float_t         Event_LHEWeight361;
   Float_t         Event_LHEWeight362;
   Float_t         Event_LHEWeight363;
   Float_t         Event_LHEWeight364;
   Float_t         Event_LHEWeight365;
   Float_t         Event_LHEWeight366;
   Float_t         Event_LHEWeight367;
   Float_t         Event_LHEWeight368;
   Float_t         Event_LHEWeight369;
   Float_t         Event_LHEWeight370;
   Float_t         Event_LHEWeight371;
   Float_t         Event_LHEWeight372;
   Float_t         Event_LHEWeight373;
   Float_t         Event_LHEWeight374;
   Float_t         Event_LHEWeight375;
   Float_t         Event_LHEWeight376;
   Float_t         Event_LHEWeight377;
   Float_t         Event_LHEWeight378;
   Float_t         Event_LHEWeight379;
   Float_t         Event_LHEWeight380;
   Float_t         Event_LHEWeight381;
   Float_t         Event_LHEWeight382;
   Float_t         Event_LHEWeight383;
   Float_t         Event_LHEWeight384;
   Float_t         Event_LHEWeight385;
   Float_t         Event_LHEWeight386;
   Float_t         Event_LHEWeight387;
   Float_t         Event_LHEWeight388;
   Float_t         Event_LHEWeight389;
   Float_t         Event_LHEWeight390;
   Float_t         Event_LHEWeight391;
   Float_t         Event_LHEWeight392;
   Float_t         Event_LHEWeight393;
   Float_t         Event_LHEWeight394;
   Float_t         Event_LHEWeight395;
   Float_t         Event_LHEWeight396;
   Float_t         Event_LHEWeight397;
   Float_t         Event_LHEWeight398;
   Float_t         Event_LHEWeight399;
   Float_t         Event_LHEWeight400;
   Float_t         Event_LHEWeight401;
   Float_t         Event_LHEWeight402;
   Float_t         Event_LHEWeight403;
   Float_t         Event_LHEWeight404;
   Float_t         Event_LHEWeight405;
   Float_t         Event_LHEWeight406;
   Float_t         Event_LHEWeight407;
   Float_t         Event_LHEWeight408;
   Float_t         Event_LHEWeight409;
   Float_t         Event_LHEWeight410;
   Float_t         Event_LHEWeight411;
   Float_t         Event_LHEWeight412;
   Float_t         Event_LHEWeight413;
   Float_t         Event_LHEWeight414;
   Float_t         Event_LHEWeight415;
   Float_t         Event_LHEWeight416;
   Float_t         Event_LHEWeight417;
   Float_t         Event_LHEWeight418;
   Float_t         Event_LHEWeight419;
   Float_t         Event_LHEWeight420;
   Float_t         Event_LHEWeight421;
   Float_t         Event_LHEWeight422;
   Float_t         Event_LHEWeight423;
   Float_t         Event_LHEWeight424;
   Float_t         Event_LHEWeight425;
   Float_t         Event_LHEWeight426;
   Float_t         Event_LHEWeight427;
   Float_t         Event_LHEWeight428;
   Float_t         Event_LHEWeight429;
   Float_t         Event_LHEWeight430;
   Float_t         Event_LHEWeight431;
   Float_t         Event_LHEWeight432;
   Float_t         Event_LHEWeight433;
   Float_t         Event_LHEWeight434;
   Float_t         Event_LHEWeight435;
   Float_t         Event_LHEWeight436;
   Float_t         Event_LHEWeight437;
   Float_t         Event_LHEWeight438;
   Float_t         Event_LHEWeight439;
   Float_t         Event_LHEWeight440;
   Float_t         Event_LHEWeight441;
   Float_t         Event_LHEWeight442;
   Float_t         Event_LHEWeight443;
   Float_t         Event_LHEWeight444;
   Float_t         Event_LHEWeight445;
   Float_t         Event_LHEWeight446;
   Float_t         Event_LHEWeight447;
   Float_t         Event_LHEWeight448;
   Float_t         Event_LHEWeight449;
   Float_t         Event_LHEWeight450;
   Float_t         Event_LHEWeight451;
   Float_t         Event_LHEWeight452;
   Float_t         Event_LHEWeight453;
   Float_t         Event_LHEWeight454;
   Float_t         Event_LHEWeight455;
   Float_t         Event_LHEWeight456;
   Float_t         Event_LHEWeight457;
   Float_t         Event_LHEWeight458;
   Float_t         Event_LHEWeight459;
   Float_t         Event_LHEWeight460;
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
   TBranch        *b_electrons_isVeto;   //!
   TBranch        *b_electrons_isLoose;   //!
   TBranch        *b_electrons_isMedium;   //!
   TBranch        *b_electrons_isTight;   //!
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
   TBranch        *b_Event_LHEWeight0;   //!
   TBranch        *b_Event_LHEWeight1;   //!
   TBranch        *b_Event_LHEWeight2;   //!
   TBranch        *b_Event_LHEWeight3;   //!
   TBranch        *b_Event_LHEWeight4;   //!
   TBranch        *b_Event_LHEWeight5;   //!
   TBranch        *b_Event_LHEWeight6;   //!
   TBranch        *b_Event_LHEWeight7;   //!
   TBranch        *b_Event_LHEWeight8;   //!
   TBranch        *b_Event_LHEWeight9;   //!
   TBranch        *b_Event_LHEWeight10;   //!
   TBranch        *b_Event_LHEWeight11;   //!
   TBranch        *b_Event_LHEWeight12;   //!
   TBranch        *b_Event_LHEWeight13;   //!
   TBranch        *b_Event_LHEWeight14;   //!
   TBranch        *b_Event_LHEWeight15;   //!
   TBranch        *b_Event_LHEWeight16;   //!
   TBranch        *b_Event_LHEWeight17;   //!
   TBranch        *b_Event_LHEWeight18;   //!
   TBranch        *b_Event_LHEWeight19;   //!
   TBranch        *b_Event_LHEWeight20;   //!
   TBranch        *b_Event_LHEWeight21;   //!
   TBranch        *b_Event_LHEWeight22;   //!
   TBranch        *b_Event_LHEWeight23;   //!
   TBranch        *b_Event_LHEWeight24;   //!
   TBranch        *b_Event_LHEWeight25;   //!
   TBranch        *b_Event_LHEWeight26;   //!
   TBranch        *b_Event_LHEWeight27;   //!
   TBranch        *b_Event_LHEWeight28;   //!
   TBranch        *b_Event_LHEWeight29;   //!
   TBranch        *b_Event_LHEWeight30;   //!
   TBranch        *b_Event_LHEWeight31;   //!
   TBranch        *b_Event_LHEWeight32;   //!
   TBranch        *b_Event_LHEWeight33;   //!
   TBranch        *b_Event_LHEWeight34;   //!
   TBranch        *b_Event_LHEWeight35;   //!
   TBranch        *b_Event_LHEWeight36;   //!
   TBranch        *b_Event_LHEWeight37;   //!
   TBranch        *b_Event_LHEWeight38;   //!
   TBranch        *b_Event_LHEWeight39;   //!
   TBranch        *b_Event_LHEWeight40;   //!
   TBranch        *b_Event_LHEWeight41;   //!
   TBranch        *b_Event_LHEWeight42;   //!
   TBranch        *b_Event_LHEWeight43;   //!
   TBranch        *b_Event_LHEWeight44;   //!
   TBranch        *b_Event_LHEWeight45;   //!
   TBranch        *b_Event_LHEWeight46;   //!
   TBranch        *b_Event_LHEWeight47;   //!
   TBranch        *b_Event_LHEWeight48;   //!
   TBranch        *b_Event_LHEWeight49;   //!
   TBranch        *b_Event_LHEWeight50;   //!
   TBranch        *b_Event_LHEWeight51;   //!
   TBranch        *b_Event_LHEWeight52;   //!
   TBranch        *b_Event_LHEWeight53;   //!
   TBranch        *b_Event_LHEWeight54;   //!
   TBranch        *b_Event_LHEWeight55;   //!
   TBranch        *b_Event_LHEWeight56;   //!
   TBranch        *b_Event_LHEWeight57;   //!
   TBranch        *b_Event_LHEWeight58;   //!
   TBranch        *b_Event_LHEWeight59;   //!
   TBranch        *b_Event_LHEWeight60;   //!
   TBranch        *b_Event_LHEWeight61;   //!
   TBranch        *b_Event_LHEWeight62;   //!
   TBranch        *b_Event_LHEWeight63;   //!
   TBranch        *b_Event_LHEWeight64;   //!
   TBranch        *b_Event_LHEWeight65;   //!
   TBranch        *b_Event_LHEWeight66;   //!
   TBranch        *b_Event_LHEWeight67;   //!
   TBranch        *b_Event_LHEWeight68;   //!
   TBranch        *b_Event_LHEWeight69;   //!
   TBranch        *b_Event_LHEWeight70;   //!
   TBranch        *b_Event_LHEWeight71;   //!
   TBranch        *b_Event_LHEWeight72;   //!
   TBranch        *b_Event_LHEWeight73;   //!
   TBranch        *b_Event_LHEWeight74;   //!
   TBranch        *b_Event_LHEWeight75;   //!
   TBranch        *b_Event_LHEWeight76;   //!
   TBranch        *b_Event_LHEWeight77;   //!
   TBranch        *b_Event_LHEWeight78;   //!
   TBranch        *b_Event_LHEWeight79;   //!
   TBranch        *b_Event_LHEWeight80;   //!
   TBranch        *b_Event_LHEWeight81;   //!
   TBranch        *b_Event_LHEWeight82;   //!
   TBranch        *b_Event_LHEWeight83;   //!
   TBranch        *b_Event_LHEWeight84;   //!
   TBranch        *b_Event_LHEWeight85;   //!
   TBranch        *b_Event_LHEWeight86;   //!
   TBranch        *b_Event_LHEWeight87;   //!
   TBranch        *b_Event_LHEWeight88;   //!
   TBranch        *b_Event_LHEWeight89;   //!
   TBranch        *b_Event_LHEWeight90;   //!
   TBranch        *b_Event_LHEWeight91;   //!
   TBranch        *b_Event_LHEWeight92;   //!
   TBranch        *b_Event_LHEWeight93;   //!
   TBranch        *b_Event_LHEWeight94;   //!
   TBranch        *b_Event_LHEWeight95;   //!
   TBranch        *b_Event_LHEWeight96;   //!
   TBranch        *b_Event_LHEWeight97;   //!
   TBranch        *b_Event_LHEWeight98;   //!
   TBranch        *b_Event_LHEWeight99;   //!
   TBranch        *b_Event_LHEWeight100;   //!
   TBranch        *b_Event_LHEWeight101;   //!
   TBranch        *b_Event_LHEWeight102;   //!
   TBranch        *b_Event_LHEWeight103;   //!
   TBranch        *b_Event_LHEWeight104;   //!
   TBranch        *b_Event_LHEWeight105;   //!
   TBranch        *b_Event_LHEWeight106;   //!
   TBranch        *b_Event_LHEWeight107;   //!
   TBranch        *b_Event_LHEWeight108;   //!
   TBranch        *b_Event_LHEWeight109;   //!
   TBranch        *b_Event_LHEWeight110;   //!
   TBranch        *b_Event_LHEWeight111;   //!
   TBranch        *b_Event_LHEWeight112;   //!
   TBranch        *b_Event_LHEWeight113;   //!
   TBranch        *b_Event_LHEWeight114;   //!
   TBranch        *b_Event_LHEWeight115;   //!
   TBranch        *b_Event_LHEWeight116;   //!
   TBranch        *b_Event_LHEWeight117;   //!
   TBranch        *b_Event_LHEWeight118;   //!
   TBranch        *b_Event_LHEWeight119;   //!
   TBranch        *b_Event_LHEWeight120;   //!
   TBranch        *b_Event_LHEWeight121;   //!
   TBranch        *b_Event_LHEWeight122;   //!
   TBranch        *b_Event_LHEWeight123;   //!
   TBranch        *b_Event_LHEWeight124;   //!
   TBranch        *b_Event_LHEWeight125;   //!
   TBranch        *b_Event_LHEWeight126;   //!
   TBranch        *b_Event_LHEWeight127;   //!
   TBranch        *b_Event_LHEWeight128;   //!
   TBranch        *b_Event_LHEWeight129;   //!
   TBranch        *b_Event_LHEWeight130;   //!
   TBranch        *b_Event_LHEWeight131;   //!
   TBranch        *b_Event_LHEWeight132;   //!
   TBranch        *b_Event_LHEWeight133;   //!
   TBranch        *b_Event_LHEWeight134;   //!
   TBranch        *b_Event_LHEWeight135;   //!
   TBranch        *b_Event_LHEWeight136;   //!
   TBranch        *b_Event_LHEWeight137;   //!
   TBranch        *b_Event_LHEWeight138;   //!
   TBranch        *b_Event_LHEWeight139;   //!
   TBranch        *b_Event_LHEWeight140;   //!
   TBranch        *b_Event_LHEWeight141;   //!
   TBranch        *b_Event_LHEWeight142;   //!
   TBranch        *b_Event_LHEWeight143;   //!
   TBranch        *b_Event_LHEWeight144;   //!
   TBranch        *b_Event_LHEWeight145;   //!
   TBranch        *b_Event_LHEWeight146;   //!
   TBranch        *b_Event_LHEWeight147;   //!
   TBranch        *b_Event_LHEWeight148;   //!
   TBranch        *b_Event_LHEWeight149;   //!
   TBranch        *b_Event_LHEWeight150;   //!
   TBranch        *b_Event_LHEWeight151;   //!
   TBranch        *b_Event_LHEWeight152;   //!
   TBranch        *b_Event_LHEWeight153;   //!
   TBranch        *b_Event_LHEWeight154;   //!
   TBranch        *b_Event_LHEWeight155;   //!
   TBranch        *b_Event_LHEWeight156;   //!
   TBranch        *b_Event_LHEWeight157;   //!
   TBranch        *b_Event_LHEWeight158;   //!
   TBranch        *b_Event_LHEWeight159;   //!
   TBranch        *b_Event_LHEWeight160;   //!
   TBranch        *b_Event_LHEWeight161;   //!
   TBranch        *b_Event_LHEWeight162;   //!
   TBranch        *b_Event_LHEWeight163;   //!
   TBranch        *b_Event_LHEWeight164;   //!
   TBranch        *b_Event_LHEWeight165;   //!
   TBranch        *b_Event_LHEWeight166;   //!
   TBranch        *b_Event_LHEWeight167;   //!
   TBranch        *b_Event_LHEWeight168;   //!
   TBranch        *b_Event_LHEWeight169;   //!
   TBranch        *b_Event_LHEWeight170;   //!
   TBranch        *b_Event_LHEWeight171;   //!
   TBranch        *b_Event_LHEWeight172;   //!
   TBranch        *b_Event_LHEWeight173;   //!
   TBranch        *b_Event_LHEWeight174;   //!
   TBranch        *b_Event_LHEWeight175;   //!
   TBranch        *b_Event_LHEWeight176;   //!
   TBranch        *b_Event_LHEWeight177;   //!
   TBranch        *b_Event_LHEWeight178;   //!
   TBranch        *b_Event_LHEWeight179;   //!
   TBranch        *b_Event_LHEWeight180;   //!
   TBranch        *b_Event_LHEWeight181;   //!
   TBranch        *b_Event_LHEWeight182;   //!
   TBranch        *b_Event_LHEWeight183;   //!
   TBranch        *b_Event_LHEWeight184;   //!
   TBranch        *b_Event_LHEWeight185;   //!
   TBranch        *b_Event_LHEWeight186;   //!
   TBranch        *b_Event_LHEWeight187;   //!
   TBranch        *b_Event_LHEWeight188;   //!
   TBranch        *b_Event_LHEWeight189;   //!
   TBranch        *b_Event_LHEWeight190;   //!
   TBranch        *b_Event_LHEWeight191;   //!
   TBranch        *b_Event_LHEWeight192;   //!
   TBranch        *b_Event_LHEWeight193;   //!
   TBranch        *b_Event_LHEWeight194;   //!
   TBranch        *b_Event_LHEWeight195;   //!
   TBranch        *b_Event_LHEWeight196;   //!
   TBranch        *b_Event_LHEWeight197;   //!
   TBranch        *b_Event_LHEWeight198;   //!
   TBranch        *b_Event_LHEWeight199;   //!
   TBranch        *b_Event_LHEWeight200;   //!
   TBranch        *b_Event_LHEWeight201;   //!
   TBranch        *b_Event_LHEWeight202;   //!
   TBranch        *b_Event_LHEWeight203;   //!
   TBranch        *b_Event_LHEWeight204;   //!
   TBranch        *b_Event_LHEWeight205;   //!
   TBranch        *b_Event_LHEWeight206;   //!
   TBranch        *b_Event_LHEWeight207;   //!
   TBranch        *b_Event_LHEWeight208;   //!
   TBranch        *b_Event_LHEWeight209;   //!
   TBranch        *b_Event_LHEWeight210;   //!
   TBranch        *b_Event_LHEWeight211;   //!
   TBranch        *b_Event_LHEWeight212;   //!
   TBranch        *b_Event_LHEWeight213;   //!
   TBranch        *b_Event_LHEWeight214;   //!
   TBranch        *b_Event_LHEWeight215;   //!
   TBranch        *b_Event_LHEWeight216;   //!
   TBranch        *b_Event_LHEWeight217;   //!
   TBranch        *b_Event_LHEWeight218;   //!
   TBranch        *b_Event_LHEWeight219;   //!
   TBranch        *b_Event_LHEWeight220;   //!
   TBranch        *b_Event_LHEWeight221;   //!
   TBranch        *b_Event_LHEWeight222;   //!
   TBranch        *b_Event_LHEWeight223;   //!
   TBranch        *b_Event_LHEWeight224;   //!
   TBranch        *b_Event_LHEWeight225;   //!
   TBranch        *b_Event_LHEWeight226;   //!
   TBranch        *b_Event_LHEWeight227;   //!
   TBranch        *b_Event_LHEWeight228;   //!
   TBranch        *b_Event_LHEWeight229;   //!
   TBranch        *b_Event_LHEWeight230;   //!
   TBranch        *b_Event_LHEWeight231;   //!
   TBranch        *b_Event_LHEWeight232;   //!
   TBranch        *b_Event_LHEWeight233;   //!
   TBranch        *b_Event_LHEWeight234;   //!
   TBranch        *b_Event_LHEWeight235;   //!
   TBranch        *b_Event_LHEWeight236;   //!
   TBranch        *b_Event_LHEWeight237;   //!
   TBranch        *b_Event_LHEWeight238;   //!
   TBranch        *b_Event_LHEWeight239;   //!
   TBranch        *b_Event_LHEWeight240;   //!
   TBranch        *b_Event_LHEWeight241;   //!
   TBranch        *b_Event_LHEWeight242;   //!
   TBranch        *b_Event_LHEWeight243;   //!
   TBranch        *b_Event_LHEWeight244;   //!
   TBranch        *b_Event_LHEWeight245;   //!
   TBranch        *b_Event_LHEWeight246;   //!
   TBranch        *b_Event_LHEWeight247;   //!
   TBranch        *b_Event_LHEWeight248;   //!
   TBranch        *b_Event_LHEWeight249;   //!
   TBranch        *b_Event_LHEWeight250;   //!
   TBranch        *b_Event_LHEWeight251;   //!
   TBranch        *b_Event_LHEWeight252;   //!
   TBranch        *b_Event_LHEWeight253;   //!
   TBranch        *b_Event_LHEWeight254;   //!
   TBranch        *b_Event_LHEWeight255;   //!
   TBranch        *b_Event_LHEWeight256;   //!
   TBranch        *b_Event_LHEWeight257;   //!
   TBranch        *b_Event_LHEWeight258;   //!
   TBranch        *b_Event_LHEWeight259;   //!
   TBranch        *b_Event_LHEWeight260;   //!
   TBranch        *b_Event_LHEWeight261;   //!
   TBranch        *b_Event_LHEWeight262;   //!
   TBranch        *b_Event_LHEWeight263;   //!
   TBranch        *b_Event_LHEWeight264;   //!
   TBranch        *b_Event_LHEWeight265;   //!
   TBranch        *b_Event_LHEWeight266;   //!
   TBranch        *b_Event_LHEWeight267;   //!
   TBranch        *b_Event_LHEWeight268;   //!
   TBranch        *b_Event_LHEWeight269;   //!
   TBranch        *b_Event_LHEWeight270;   //!
   TBranch        *b_Event_LHEWeight271;   //!
   TBranch        *b_Event_LHEWeight272;   //!
   TBranch        *b_Event_LHEWeight273;   //!
   TBranch        *b_Event_LHEWeight274;   //!
   TBranch        *b_Event_LHEWeight275;   //!
   TBranch        *b_Event_LHEWeight276;   //!
   TBranch        *b_Event_LHEWeight277;   //!
   TBranch        *b_Event_LHEWeight278;   //!
   TBranch        *b_Event_LHEWeight279;   //!
   TBranch        *b_Event_LHEWeight280;   //!
   TBranch        *b_Event_LHEWeight281;   //!
   TBranch        *b_Event_LHEWeight282;   //!
   TBranch        *b_Event_LHEWeight283;   //!
   TBranch        *b_Event_LHEWeight284;   //!
   TBranch        *b_Event_LHEWeight285;   //!
   TBranch        *b_Event_LHEWeight286;   //!
   TBranch        *b_Event_LHEWeight287;   //!
   TBranch        *b_Event_LHEWeight288;   //!
   TBranch        *b_Event_LHEWeight289;   //!
   TBranch        *b_Event_LHEWeight290;   //!
   TBranch        *b_Event_LHEWeight291;   //!
   TBranch        *b_Event_LHEWeight292;   //!
   TBranch        *b_Event_LHEWeight293;   //!
   TBranch        *b_Event_LHEWeight294;   //!
   TBranch        *b_Event_LHEWeight295;   //!
   TBranch        *b_Event_LHEWeight296;   //!
   TBranch        *b_Event_LHEWeight297;   //!
   TBranch        *b_Event_LHEWeight298;   //!
   TBranch        *b_Event_LHEWeight299;   //!
   TBranch        *b_Event_LHEWeight300;   //!
   TBranch        *b_Event_LHEWeight301;   //!
   TBranch        *b_Event_LHEWeight302;   //!
   TBranch        *b_Event_LHEWeight303;   //!
   TBranch        *b_Event_LHEWeight304;   //!
   TBranch        *b_Event_LHEWeight305;   //!
   TBranch        *b_Event_LHEWeight306;   //!
   TBranch        *b_Event_LHEWeight307;   //!
   TBranch        *b_Event_LHEWeight308;   //!
   TBranch        *b_Event_LHEWeight309;   //!
   TBranch        *b_Event_LHEWeight310;   //!
   TBranch        *b_Event_LHEWeight311;   //!
   TBranch        *b_Event_LHEWeight312;   //!
   TBranch        *b_Event_LHEWeight313;   //!
   TBranch        *b_Event_LHEWeight314;   //!
   TBranch        *b_Event_LHEWeight315;   //!
   TBranch        *b_Event_LHEWeight316;   //!
   TBranch        *b_Event_LHEWeight317;   //!
   TBranch        *b_Event_LHEWeight318;   //!
   TBranch        *b_Event_LHEWeight319;   //!
   TBranch        *b_Event_LHEWeight320;   //!
   TBranch        *b_Event_LHEWeight321;   //!
   TBranch        *b_Event_LHEWeight322;   //!
   TBranch        *b_Event_LHEWeight323;   //!
   TBranch        *b_Event_LHEWeight324;   //!
   TBranch        *b_Event_LHEWeight325;   //!
   TBranch        *b_Event_LHEWeight326;   //!
   TBranch        *b_Event_LHEWeight327;   //!
   TBranch        *b_Event_LHEWeight328;   //!
   TBranch        *b_Event_LHEWeight329;   //!
   TBranch        *b_Event_LHEWeight330;   //!
   TBranch        *b_Event_LHEWeight331;   //!
   TBranch        *b_Event_LHEWeight332;   //!
   TBranch        *b_Event_LHEWeight333;   //!
   TBranch        *b_Event_LHEWeight334;   //!
   TBranch        *b_Event_LHEWeight335;   //!
   TBranch        *b_Event_LHEWeight336;   //!
   TBranch        *b_Event_LHEWeight337;   //!
   TBranch        *b_Event_LHEWeight338;   //!
   TBranch        *b_Event_LHEWeight339;   //!
   TBranch        *b_Event_LHEWeight340;   //!
   TBranch        *b_Event_LHEWeight341;   //!
   TBranch        *b_Event_LHEWeight342;   //!
   TBranch        *b_Event_LHEWeight343;   //!
   TBranch        *b_Event_LHEWeight344;   //!
   TBranch        *b_Event_LHEWeight345;   //!
   TBranch        *b_Event_LHEWeight346;   //!
   TBranch        *b_Event_LHEWeight347;   //!
   TBranch        *b_Event_LHEWeight348;   //!
   TBranch        *b_Event_LHEWeight349;   //!
   TBranch        *b_Event_LHEWeight350;   //!
   TBranch        *b_Event_LHEWeight351;   //!
   TBranch        *b_Event_LHEWeight352;   //!
   TBranch        *b_Event_LHEWeight353;   //!
   TBranch        *b_Event_LHEWeight354;   //!
   TBranch        *b_Event_LHEWeight355;   //!
   TBranch        *b_Event_LHEWeight356;   //!
   TBranch        *b_Event_LHEWeight357;   //!
   TBranch        *b_Event_LHEWeight358;   //!
   TBranch        *b_Event_LHEWeight359;   //!
   TBranch        *b_Event_LHEWeight360;   //!
   TBranch        *b_Event_LHEWeight361;   //!
   TBranch        *b_Event_LHEWeight362;   //!
   TBranch        *b_Event_LHEWeight363;   //!
   TBranch        *b_Event_LHEWeight364;   //!
   TBranch        *b_Event_LHEWeight365;   //!
   TBranch        *b_Event_LHEWeight366;   //!
   TBranch        *b_Event_LHEWeight367;   //!
   TBranch        *b_Event_LHEWeight368;   //!
   TBranch        *b_Event_LHEWeight369;   //!
   TBranch        *b_Event_LHEWeight370;   //!
   TBranch        *b_Event_LHEWeight371;   //!
   TBranch        *b_Event_LHEWeight372;   //!
   TBranch        *b_Event_LHEWeight373;   //!
   TBranch        *b_Event_LHEWeight374;   //!
   TBranch        *b_Event_LHEWeight375;   //!
   TBranch        *b_Event_LHEWeight376;   //!
   TBranch        *b_Event_LHEWeight377;   //!
   TBranch        *b_Event_LHEWeight378;   //!
   TBranch        *b_Event_LHEWeight379;   //!
   TBranch        *b_Event_LHEWeight380;   //!
   TBranch        *b_Event_LHEWeight381;   //!
   TBranch        *b_Event_LHEWeight382;   //!
   TBranch        *b_Event_LHEWeight383;   //!
   TBranch        *b_Event_LHEWeight384;   //!
   TBranch        *b_Event_LHEWeight385;   //!
   TBranch        *b_Event_LHEWeight386;   //!
   TBranch        *b_Event_LHEWeight387;   //!
   TBranch        *b_Event_LHEWeight388;   //!
   TBranch        *b_Event_LHEWeight389;   //!
   TBranch        *b_Event_LHEWeight390;   //!
   TBranch        *b_Event_LHEWeight391;   //!
   TBranch        *b_Event_LHEWeight392;   //!
   TBranch        *b_Event_LHEWeight393;   //!
   TBranch        *b_Event_LHEWeight394;   //!
   TBranch        *b_Event_LHEWeight395;   //!
   TBranch        *b_Event_LHEWeight396;   //!
   TBranch        *b_Event_LHEWeight397;   //!
   TBranch        *b_Event_LHEWeight398;   //!
   TBranch        *b_Event_LHEWeight399;   //!
   TBranch        *b_Event_LHEWeight400;   //!
   TBranch        *b_Event_LHEWeight401;   //!
   TBranch        *b_Event_LHEWeight402;   //!
   TBranch        *b_Event_LHEWeight403;   //!
   TBranch        *b_Event_LHEWeight404;   //!
   TBranch        *b_Event_LHEWeight405;   //!
   TBranch        *b_Event_LHEWeight406;   //!
   TBranch        *b_Event_LHEWeight407;   //!
   TBranch        *b_Event_LHEWeight408;   //!
   TBranch        *b_Event_LHEWeight409;   //!
   TBranch        *b_Event_LHEWeight410;   //!
   TBranch        *b_Event_LHEWeight411;   //!
   TBranch        *b_Event_LHEWeight412;   //!
   TBranch        *b_Event_LHEWeight413;   //!
   TBranch        *b_Event_LHEWeight414;   //!
   TBranch        *b_Event_LHEWeight415;   //!
   TBranch        *b_Event_LHEWeight416;   //!
   TBranch        *b_Event_LHEWeight417;   //!
   TBranch        *b_Event_LHEWeight418;   //!
   TBranch        *b_Event_LHEWeight419;   //!
   TBranch        *b_Event_LHEWeight420;   //!
   TBranch        *b_Event_LHEWeight421;   //!
   TBranch        *b_Event_LHEWeight422;   //!
   TBranch        *b_Event_LHEWeight423;   //!
   TBranch        *b_Event_LHEWeight424;   //!
   TBranch        *b_Event_LHEWeight425;   //!
   TBranch        *b_Event_LHEWeight426;   //!
   TBranch        *b_Event_LHEWeight427;   //!
   TBranch        *b_Event_LHEWeight428;   //!
   TBranch        *b_Event_LHEWeight429;   //!
   TBranch        *b_Event_LHEWeight430;   //!
   TBranch        *b_Event_LHEWeight431;   //!
   TBranch        *b_Event_LHEWeight432;   //!
   TBranch        *b_Event_LHEWeight433;   //!
   TBranch        *b_Event_LHEWeight434;   //!
   TBranch        *b_Event_LHEWeight435;   //!
   TBranch        *b_Event_LHEWeight436;   //!
   TBranch        *b_Event_LHEWeight437;   //!
   TBranch        *b_Event_LHEWeight438;   //!
   TBranch        *b_Event_LHEWeight439;   //!
   TBranch        *b_Event_LHEWeight440;   //!
   TBranch        *b_Event_LHEWeight441;   //!
   TBranch        *b_Event_LHEWeight442;   //!
   TBranch        *b_Event_LHEWeight443;   //!
   TBranch        *b_Event_LHEWeight444;   //!
   TBranch        *b_Event_LHEWeight445;   //!
   TBranch        *b_Event_LHEWeight446;   //!
   TBranch        *b_Event_LHEWeight447;   //!
   TBranch        *b_Event_LHEWeight448;   //!
   TBranch        *b_Event_LHEWeight449;   //!
   TBranch        *b_Event_LHEWeight450;   //!
   TBranch        *b_Event_LHEWeight451;   //!
   TBranch        *b_Event_LHEWeight452;   //!
   TBranch        *b_Event_LHEWeight453;   //!
   TBranch        *b_Event_LHEWeight454;   //!
   TBranch        *b_Event_LHEWeight455;   //!
   TBranch        *b_Event_LHEWeight456;   //!
   TBranch        *b_Event_LHEWeight457;   //!
   TBranch        *b_Event_LHEWeight458;   //!
   TBranch        *b_Event_LHEWeight459;   //!
   TBranch        *b_Event_LHEWeight460;   //!
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
   fChain->SetBranchAddress("electrons_isVeto", electrons_isVeto, &b_electrons_isVeto);
   fChain->SetBranchAddress("electrons_isLoose", electrons_isLoose, &b_electrons_isLoose);
   fChain->SetBranchAddress("electrons_isMedium", electrons_isMedium, &b_electrons_isMedium);
   fChain->SetBranchAddress("electrons_isTight", electrons_isTight, &b_electrons_isTight);
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
   fChain->SetBranchAddress("Event_LHEWeight0", &Event_LHEWeight0, &b_Event_LHEWeight0);
   fChain->SetBranchAddress("Event_LHEWeight1", &Event_LHEWeight1, &b_Event_LHEWeight1);
   fChain->SetBranchAddress("Event_LHEWeight2", &Event_LHEWeight2, &b_Event_LHEWeight2);
   fChain->SetBranchAddress("Event_LHEWeight3", &Event_LHEWeight3, &b_Event_LHEWeight3);
   fChain->SetBranchAddress("Event_LHEWeight4", &Event_LHEWeight4, &b_Event_LHEWeight4);
   fChain->SetBranchAddress("Event_LHEWeight5", &Event_LHEWeight5, &b_Event_LHEWeight5);
   fChain->SetBranchAddress("Event_LHEWeight6", &Event_LHEWeight6, &b_Event_LHEWeight6);
   fChain->SetBranchAddress("Event_LHEWeight7", &Event_LHEWeight7, &b_Event_LHEWeight7);
   fChain->SetBranchAddress("Event_LHEWeight8", &Event_LHEWeight8, &b_Event_LHEWeight8);
   fChain->SetBranchAddress("Event_LHEWeight9", &Event_LHEWeight9, &b_Event_LHEWeight9);
   fChain->SetBranchAddress("Event_LHEWeight10", &Event_LHEWeight10, &b_Event_LHEWeight10);
   fChain->SetBranchAddress("Event_LHEWeight11", &Event_LHEWeight11, &b_Event_LHEWeight11);
   fChain->SetBranchAddress("Event_LHEWeight12", &Event_LHEWeight12, &b_Event_LHEWeight12);
   fChain->SetBranchAddress("Event_LHEWeight13", &Event_LHEWeight13, &b_Event_LHEWeight13);
   fChain->SetBranchAddress("Event_LHEWeight14", &Event_LHEWeight14, &b_Event_LHEWeight14);
   fChain->SetBranchAddress("Event_LHEWeight15", &Event_LHEWeight15, &b_Event_LHEWeight15);
   fChain->SetBranchAddress("Event_LHEWeight16", &Event_LHEWeight16, &b_Event_LHEWeight16);
   fChain->SetBranchAddress("Event_LHEWeight17", &Event_LHEWeight17, &b_Event_LHEWeight17);
   fChain->SetBranchAddress("Event_LHEWeight18", &Event_LHEWeight18, &b_Event_LHEWeight18);
   fChain->SetBranchAddress("Event_LHEWeight19", &Event_LHEWeight19, &b_Event_LHEWeight19);
   fChain->SetBranchAddress("Event_LHEWeight20", &Event_LHEWeight20, &b_Event_LHEWeight20);
   fChain->SetBranchAddress("Event_LHEWeight21", &Event_LHEWeight21, &b_Event_LHEWeight21);
   fChain->SetBranchAddress("Event_LHEWeight22", &Event_LHEWeight22, &b_Event_LHEWeight22);
   fChain->SetBranchAddress("Event_LHEWeight23", &Event_LHEWeight23, &b_Event_LHEWeight23);
   fChain->SetBranchAddress("Event_LHEWeight24", &Event_LHEWeight24, &b_Event_LHEWeight24);
   fChain->SetBranchAddress("Event_LHEWeight25", &Event_LHEWeight25, &b_Event_LHEWeight25);
   fChain->SetBranchAddress("Event_LHEWeight26", &Event_LHEWeight26, &b_Event_LHEWeight26);
   fChain->SetBranchAddress("Event_LHEWeight27", &Event_LHEWeight27, &b_Event_LHEWeight27);
   fChain->SetBranchAddress("Event_LHEWeight28", &Event_LHEWeight28, &b_Event_LHEWeight28);
   fChain->SetBranchAddress("Event_LHEWeight29", &Event_LHEWeight29, &b_Event_LHEWeight29);
   fChain->SetBranchAddress("Event_LHEWeight30", &Event_LHEWeight30, &b_Event_LHEWeight30);
   fChain->SetBranchAddress("Event_LHEWeight31", &Event_LHEWeight31, &b_Event_LHEWeight31);
   fChain->SetBranchAddress("Event_LHEWeight32", &Event_LHEWeight32, &b_Event_LHEWeight32);
   fChain->SetBranchAddress("Event_LHEWeight33", &Event_LHEWeight33, &b_Event_LHEWeight33);
   fChain->SetBranchAddress("Event_LHEWeight34", &Event_LHEWeight34, &b_Event_LHEWeight34);
   fChain->SetBranchAddress("Event_LHEWeight35", &Event_LHEWeight35, &b_Event_LHEWeight35);
   fChain->SetBranchAddress("Event_LHEWeight36", &Event_LHEWeight36, &b_Event_LHEWeight36);
   fChain->SetBranchAddress("Event_LHEWeight37", &Event_LHEWeight37, &b_Event_LHEWeight37);
   fChain->SetBranchAddress("Event_LHEWeight38", &Event_LHEWeight38, &b_Event_LHEWeight38);
   fChain->SetBranchAddress("Event_LHEWeight39", &Event_LHEWeight39, &b_Event_LHEWeight39);
   fChain->SetBranchAddress("Event_LHEWeight40", &Event_LHEWeight40, &b_Event_LHEWeight40);
   fChain->SetBranchAddress("Event_LHEWeight41", &Event_LHEWeight41, &b_Event_LHEWeight41);
   fChain->SetBranchAddress("Event_LHEWeight42", &Event_LHEWeight42, &b_Event_LHEWeight42);
   fChain->SetBranchAddress("Event_LHEWeight43", &Event_LHEWeight43, &b_Event_LHEWeight43);
   fChain->SetBranchAddress("Event_LHEWeight44", &Event_LHEWeight44, &b_Event_LHEWeight44);
   fChain->SetBranchAddress("Event_LHEWeight45", &Event_LHEWeight45, &b_Event_LHEWeight45);
   fChain->SetBranchAddress("Event_LHEWeight46", &Event_LHEWeight46, &b_Event_LHEWeight46);
   fChain->SetBranchAddress("Event_LHEWeight47", &Event_LHEWeight47, &b_Event_LHEWeight47);
   fChain->SetBranchAddress("Event_LHEWeight48", &Event_LHEWeight48, &b_Event_LHEWeight48);
   fChain->SetBranchAddress("Event_LHEWeight49", &Event_LHEWeight49, &b_Event_LHEWeight49);
   fChain->SetBranchAddress("Event_LHEWeight50", &Event_LHEWeight50, &b_Event_LHEWeight50);
   fChain->SetBranchAddress("Event_LHEWeight51", &Event_LHEWeight51, &b_Event_LHEWeight51);
   fChain->SetBranchAddress("Event_LHEWeight52", &Event_LHEWeight52, &b_Event_LHEWeight52);
   fChain->SetBranchAddress("Event_LHEWeight53", &Event_LHEWeight53, &b_Event_LHEWeight53);
   fChain->SetBranchAddress("Event_LHEWeight54", &Event_LHEWeight54, &b_Event_LHEWeight54);
   fChain->SetBranchAddress("Event_LHEWeight55", &Event_LHEWeight55, &b_Event_LHEWeight55);
   fChain->SetBranchAddress("Event_LHEWeight56", &Event_LHEWeight56, &b_Event_LHEWeight56);
   fChain->SetBranchAddress("Event_LHEWeight57", &Event_LHEWeight57, &b_Event_LHEWeight57);
   fChain->SetBranchAddress("Event_LHEWeight58", &Event_LHEWeight58, &b_Event_LHEWeight58);
   fChain->SetBranchAddress("Event_LHEWeight59", &Event_LHEWeight59, &b_Event_LHEWeight59);
   fChain->SetBranchAddress("Event_LHEWeight60", &Event_LHEWeight60, &b_Event_LHEWeight60);
   fChain->SetBranchAddress("Event_LHEWeight61", &Event_LHEWeight61, &b_Event_LHEWeight61);
   fChain->SetBranchAddress("Event_LHEWeight62", &Event_LHEWeight62, &b_Event_LHEWeight62);
   fChain->SetBranchAddress("Event_LHEWeight63", &Event_LHEWeight63, &b_Event_LHEWeight63);
   fChain->SetBranchAddress("Event_LHEWeight64", &Event_LHEWeight64, &b_Event_LHEWeight64);
   fChain->SetBranchAddress("Event_LHEWeight65", &Event_LHEWeight65, &b_Event_LHEWeight65);
   fChain->SetBranchAddress("Event_LHEWeight66", &Event_LHEWeight66, &b_Event_LHEWeight66);
   fChain->SetBranchAddress("Event_LHEWeight67", &Event_LHEWeight67, &b_Event_LHEWeight67);
   fChain->SetBranchAddress("Event_LHEWeight68", &Event_LHEWeight68, &b_Event_LHEWeight68);
   fChain->SetBranchAddress("Event_LHEWeight69", &Event_LHEWeight69, &b_Event_LHEWeight69);
   fChain->SetBranchAddress("Event_LHEWeight70", &Event_LHEWeight70, &b_Event_LHEWeight70);
   fChain->SetBranchAddress("Event_LHEWeight71", &Event_LHEWeight71, &b_Event_LHEWeight71);
   fChain->SetBranchAddress("Event_LHEWeight72", &Event_LHEWeight72, &b_Event_LHEWeight72);
   fChain->SetBranchAddress("Event_LHEWeight73", &Event_LHEWeight73, &b_Event_LHEWeight73);
   fChain->SetBranchAddress("Event_LHEWeight74", &Event_LHEWeight74, &b_Event_LHEWeight74);
   fChain->SetBranchAddress("Event_LHEWeight75", &Event_LHEWeight75, &b_Event_LHEWeight75);
   fChain->SetBranchAddress("Event_LHEWeight76", &Event_LHEWeight76, &b_Event_LHEWeight76);
   fChain->SetBranchAddress("Event_LHEWeight77", &Event_LHEWeight77, &b_Event_LHEWeight77);
   fChain->SetBranchAddress("Event_LHEWeight78", &Event_LHEWeight78, &b_Event_LHEWeight78);
   fChain->SetBranchAddress("Event_LHEWeight79", &Event_LHEWeight79, &b_Event_LHEWeight79);
   fChain->SetBranchAddress("Event_LHEWeight80", &Event_LHEWeight80, &b_Event_LHEWeight80);
   fChain->SetBranchAddress("Event_LHEWeight81", &Event_LHEWeight81, &b_Event_LHEWeight81);
   fChain->SetBranchAddress("Event_LHEWeight82", &Event_LHEWeight82, &b_Event_LHEWeight82);
   fChain->SetBranchAddress("Event_LHEWeight83", &Event_LHEWeight83, &b_Event_LHEWeight83);
   fChain->SetBranchAddress("Event_LHEWeight84", &Event_LHEWeight84, &b_Event_LHEWeight84);
   fChain->SetBranchAddress("Event_LHEWeight85", &Event_LHEWeight85, &b_Event_LHEWeight85);
   fChain->SetBranchAddress("Event_LHEWeight86", &Event_LHEWeight86, &b_Event_LHEWeight86);
   fChain->SetBranchAddress("Event_LHEWeight87", &Event_LHEWeight87, &b_Event_LHEWeight87);
   fChain->SetBranchAddress("Event_LHEWeight88", &Event_LHEWeight88, &b_Event_LHEWeight88);
   fChain->SetBranchAddress("Event_LHEWeight89", &Event_LHEWeight89, &b_Event_LHEWeight89);
   fChain->SetBranchAddress("Event_LHEWeight90", &Event_LHEWeight90, &b_Event_LHEWeight90);
   fChain->SetBranchAddress("Event_LHEWeight91", &Event_LHEWeight91, &b_Event_LHEWeight91);
   fChain->SetBranchAddress("Event_LHEWeight92", &Event_LHEWeight92, &b_Event_LHEWeight92);
   fChain->SetBranchAddress("Event_LHEWeight93", &Event_LHEWeight93, &b_Event_LHEWeight93);
   fChain->SetBranchAddress("Event_LHEWeight94", &Event_LHEWeight94, &b_Event_LHEWeight94);
   fChain->SetBranchAddress("Event_LHEWeight95", &Event_LHEWeight95, &b_Event_LHEWeight95);
   fChain->SetBranchAddress("Event_LHEWeight96", &Event_LHEWeight96, &b_Event_LHEWeight96);
   fChain->SetBranchAddress("Event_LHEWeight97", &Event_LHEWeight97, &b_Event_LHEWeight97);
   fChain->SetBranchAddress("Event_LHEWeight98", &Event_LHEWeight98, &b_Event_LHEWeight98);
   fChain->SetBranchAddress("Event_LHEWeight99", &Event_LHEWeight99, &b_Event_LHEWeight99);
   fChain->SetBranchAddress("Event_LHEWeight100", &Event_LHEWeight100, &b_Event_LHEWeight100);
   fChain->SetBranchAddress("Event_LHEWeight101", &Event_LHEWeight101, &b_Event_LHEWeight101);
   fChain->SetBranchAddress("Event_LHEWeight102", &Event_LHEWeight102, &b_Event_LHEWeight102);
   fChain->SetBranchAddress("Event_LHEWeight103", &Event_LHEWeight103, &b_Event_LHEWeight103);
   fChain->SetBranchAddress("Event_LHEWeight104", &Event_LHEWeight104, &b_Event_LHEWeight104);
   fChain->SetBranchAddress("Event_LHEWeight105", &Event_LHEWeight105, &b_Event_LHEWeight105);
   fChain->SetBranchAddress("Event_LHEWeight106", &Event_LHEWeight106, &b_Event_LHEWeight106);
   fChain->SetBranchAddress("Event_LHEWeight107", &Event_LHEWeight107, &b_Event_LHEWeight107);
   fChain->SetBranchAddress("Event_LHEWeight108", &Event_LHEWeight108, &b_Event_LHEWeight108);
   fChain->SetBranchAddress("Event_LHEWeight109", &Event_LHEWeight109, &b_Event_LHEWeight109);
   fChain->SetBranchAddress("Event_LHEWeight110", &Event_LHEWeight110, &b_Event_LHEWeight110);
   fChain->SetBranchAddress("Event_LHEWeight111", &Event_LHEWeight111, &b_Event_LHEWeight111);
   fChain->SetBranchAddress("Event_LHEWeight112", &Event_LHEWeight112, &b_Event_LHEWeight112);
   fChain->SetBranchAddress("Event_LHEWeight113", &Event_LHEWeight113, &b_Event_LHEWeight113);
   fChain->SetBranchAddress("Event_LHEWeight114", &Event_LHEWeight114, &b_Event_LHEWeight114);
   fChain->SetBranchAddress("Event_LHEWeight115", &Event_LHEWeight115, &b_Event_LHEWeight115);
   fChain->SetBranchAddress("Event_LHEWeight116", &Event_LHEWeight116, &b_Event_LHEWeight116);
   fChain->SetBranchAddress("Event_LHEWeight117", &Event_LHEWeight117, &b_Event_LHEWeight117);
   fChain->SetBranchAddress("Event_LHEWeight118", &Event_LHEWeight118, &b_Event_LHEWeight118);
   fChain->SetBranchAddress("Event_LHEWeight119", &Event_LHEWeight119, &b_Event_LHEWeight119);
   fChain->SetBranchAddress("Event_LHEWeight120", &Event_LHEWeight120, &b_Event_LHEWeight120);
   fChain->SetBranchAddress("Event_LHEWeight121", &Event_LHEWeight121, &b_Event_LHEWeight121);
   fChain->SetBranchAddress("Event_LHEWeight122", &Event_LHEWeight122, &b_Event_LHEWeight122);
   fChain->SetBranchAddress("Event_LHEWeight123", &Event_LHEWeight123, &b_Event_LHEWeight123);
   fChain->SetBranchAddress("Event_LHEWeight124", &Event_LHEWeight124, &b_Event_LHEWeight124);
   fChain->SetBranchAddress("Event_LHEWeight125", &Event_LHEWeight125, &b_Event_LHEWeight125);
   fChain->SetBranchAddress("Event_LHEWeight126", &Event_LHEWeight126, &b_Event_LHEWeight126);
   fChain->SetBranchAddress("Event_LHEWeight127", &Event_LHEWeight127, &b_Event_LHEWeight127);
   fChain->SetBranchAddress("Event_LHEWeight128", &Event_LHEWeight128, &b_Event_LHEWeight128);
   fChain->SetBranchAddress("Event_LHEWeight129", &Event_LHEWeight129, &b_Event_LHEWeight129);
   fChain->SetBranchAddress("Event_LHEWeight130", &Event_LHEWeight130, &b_Event_LHEWeight130);
   fChain->SetBranchAddress("Event_LHEWeight131", &Event_LHEWeight131, &b_Event_LHEWeight131);
   fChain->SetBranchAddress("Event_LHEWeight132", &Event_LHEWeight132, &b_Event_LHEWeight132);
   fChain->SetBranchAddress("Event_LHEWeight133", &Event_LHEWeight133, &b_Event_LHEWeight133);
   fChain->SetBranchAddress("Event_LHEWeight134", &Event_LHEWeight134, &b_Event_LHEWeight134);
   fChain->SetBranchAddress("Event_LHEWeight135", &Event_LHEWeight135, &b_Event_LHEWeight135);
   fChain->SetBranchAddress("Event_LHEWeight136", &Event_LHEWeight136, &b_Event_LHEWeight136);
   fChain->SetBranchAddress("Event_LHEWeight137", &Event_LHEWeight137, &b_Event_LHEWeight137);
   fChain->SetBranchAddress("Event_LHEWeight138", &Event_LHEWeight138, &b_Event_LHEWeight138);
   fChain->SetBranchAddress("Event_LHEWeight139", &Event_LHEWeight139, &b_Event_LHEWeight139);
   fChain->SetBranchAddress("Event_LHEWeight140", &Event_LHEWeight140, &b_Event_LHEWeight140);
   fChain->SetBranchAddress("Event_LHEWeight141", &Event_LHEWeight141, &b_Event_LHEWeight141);
   fChain->SetBranchAddress("Event_LHEWeight142", &Event_LHEWeight142, &b_Event_LHEWeight142);
   fChain->SetBranchAddress("Event_LHEWeight143", &Event_LHEWeight143, &b_Event_LHEWeight143);
   fChain->SetBranchAddress("Event_LHEWeight144", &Event_LHEWeight144, &b_Event_LHEWeight144);
   fChain->SetBranchAddress("Event_LHEWeight145", &Event_LHEWeight145, &b_Event_LHEWeight145);
   fChain->SetBranchAddress("Event_LHEWeight146", &Event_LHEWeight146, &b_Event_LHEWeight146);
   fChain->SetBranchAddress("Event_LHEWeight147", &Event_LHEWeight147, &b_Event_LHEWeight147);
   fChain->SetBranchAddress("Event_LHEWeight148", &Event_LHEWeight148, &b_Event_LHEWeight148);
   fChain->SetBranchAddress("Event_LHEWeight149", &Event_LHEWeight149, &b_Event_LHEWeight149);
   fChain->SetBranchAddress("Event_LHEWeight150", &Event_LHEWeight150, &b_Event_LHEWeight150);
   fChain->SetBranchAddress("Event_LHEWeight151", &Event_LHEWeight151, &b_Event_LHEWeight151);
   fChain->SetBranchAddress("Event_LHEWeight152", &Event_LHEWeight152, &b_Event_LHEWeight152);
   fChain->SetBranchAddress("Event_LHEWeight153", &Event_LHEWeight153, &b_Event_LHEWeight153);
   fChain->SetBranchAddress("Event_LHEWeight154", &Event_LHEWeight154, &b_Event_LHEWeight154);
   fChain->SetBranchAddress("Event_LHEWeight155", &Event_LHEWeight155, &b_Event_LHEWeight155);
   fChain->SetBranchAddress("Event_LHEWeight156", &Event_LHEWeight156, &b_Event_LHEWeight156);
   fChain->SetBranchAddress("Event_LHEWeight157", &Event_LHEWeight157, &b_Event_LHEWeight157);
   fChain->SetBranchAddress("Event_LHEWeight158", &Event_LHEWeight158, &b_Event_LHEWeight158);
   fChain->SetBranchAddress("Event_LHEWeight159", &Event_LHEWeight159, &b_Event_LHEWeight159);
   fChain->SetBranchAddress("Event_LHEWeight160", &Event_LHEWeight160, &b_Event_LHEWeight160);
   fChain->SetBranchAddress("Event_LHEWeight161", &Event_LHEWeight161, &b_Event_LHEWeight161);
   fChain->SetBranchAddress("Event_LHEWeight162", &Event_LHEWeight162, &b_Event_LHEWeight162);
   fChain->SetBranchAddress("Event_LHEWeight163", &Event_LHEWeight163, &b_Event_LHEWeight163);
   fChain->SetBranchAddress("Event_LHEWeight164", &Event_LHEWeight164, &b_Event_LHEWeight164);
   fChain->SetBranchAddress("Event_LHEWeight165", &Event_LHEWeight165, &b_Event_LHEWeight165);
   fChain->SetBranchAddress("Event_LHEWeight166", &Event_LHEWeight166, &b_Event_LHEWeight166);
   fChain->SetBranchAddress("Event_LHEWeight167", &Event_LHEWeight167, &b_Event_LHEWeight167);
   fChain->SetBranchAddress("Event_LHEWeight168", &Event_LHEWeight168, &b_Event_LHEWeight168);
   fChain->SetBranchAddress("Event_LHEWeight169", &Event_LHEWeight169, &b_Event_LHEWeight169);
   fChain->SetBranchAddress("Event_LHEWeight170", &Event_LHEWeight170, &b_Event_LHEWeight170);
   fChain->SetBranchAddress("Event_LHEWeight171", &Event_LHEWeight171, &b_Event_LHEWeight171);
   fChain->SetBranchAddress("Event_LHEWeight172", &Event_LHEWeight172, &b_Event_LHEWeight172);
   fChain->SetBranchAddress("Event_LHEWeight173", &Event_LHEWeight173, &b_Event_LHEWeight173);
   fChain->SetBranchAddress("Event_LHEWeight174", &Event_LHEWeight174, &b_Event_LHEWeight174);
   fChain->SetBranchAddress("Event_LHEWeight175", &Event_LHEWeight175, &b_Event_LHEWeight175);
   fChain->SetBranchAddress("Event_LHEWeight176", &Event_LHEWeight176, &b_Event_LHEWeight176);
   fChain->SetBranchAddress("Event_LHEWeight177", &Event_LHEWeight177, &b_Event_LHEWeight177);
   fChain->SetBranchAddress("Event_LHEWeight178", &Event_LHEWeight178, &b_Event_LHEWeight178);
   fChain->SetBranchAddress("Event_LHEWeight179", &Event_LHEWeight179, &b_Event_LHEWeight179);
   fChain->SetBranchAddress("Event_LHEWeight180", &Event_LHEWeight180, &b_Event_LHEWeight180);
   fChain->SetBranchAddress("Event_LHEWeight181", &Event_LHEWeight181, &b_Event_LHEWeight181);
   fChain->SetBranchAddress("Event_LHEWeight182", &Event_LHEWeight182, &b_Event_LHEWeight182);
   fChain->SetBranchAddress("Event_LHEWeight183", &Event_LHEWeight183, &b_Event_LHEWeight183);
   fChain->SetBranchAddress("Event_LHEWeight184", &Event_LHEWeight184, &b_Event_LHEWeight184);
   fChain->SetBranchAddress("Event_LHEWeight185", &Event_LHEWeight185, &b_Event_LHEWeight185);
   fChain->SetBranchAddress("Event_LHEWeight186", &Event_LHEWeight186, &b_Event_LHEWeight186);
   fChain->SetBranchAddress("Event_LHEWeight187", &Event_LHEWeight187, &b_Event_LHEWeight187);
   fChain->SetBranchAddress("Event_LHEWeight188", &Event_LHEWeight188, &b_Event_LHEWeight188);
   fChain->SetBranchAddress("Event_LHEWeight189", &Event_LHEWeight189, &b_Event_LHEWeight189);
   fChain->SetBranchAddress("Event_LHEWeight190", &Event_LHEWeight190, &b_Event_LHEWeight190);
   fChain->SetBranchAddress("Event_LHEWeight191", &Event_LHEWeight191, &b_Event_LHEWeight191);
   fChain->SetBranchAddress("Event_LHEWeight192", &Event_LHEWeight192, &b_Event_LHEWeight192);
   fChain->SetBranchAddress("Event_LHEWeight193", &Event_LHEWeight193, &b_Event_LHEWeight193);
   fChain->SetBranchAddress("Event_LHEWeight194", &Event_LHEWeight194, &b_Event_LHEWeight194);
   fChain->SetBranchAddress("Event_LHEWeight195", &Event_LHEWeight195, &b_Event_LHEWeight195);
   fChain->SetBranchAddress("Event_LHEWeight196", &Event_LHEWeight196, &b_Event_LHEWeight196);
   fChain->SetBranchAddress("Event_LHEWeight197", &Event_LHEWeight197, &b_Event_LHEWeight197);
   fChain->SetBranchAddress("Event_LHEWeight198", &Event_LHEWeight198, &b_Event_LHEWeight198);
   fChain->SetBranchAddress("Event_LHEWeight199", &Event_LHEWeight199, &b_Event_LHEWeight199);
   fChain->SetBranchAddress("Event_LHEWeight200", &Event_LHEWeight200, &b_Event_LHEWeight200);
   fChain->SetBranchAddress("Event_LHEWeight201", &Event_LHEWeight201, &b_Event_LHEWeight201);
   fChain->SetBranchAddress("Event_LHEWeight202", &Event_LHEWeight202, &b_Event_LHEWeight202);
   fChain->SetBranchAddress("Event_LHEWeight203", &Event_LHEWeight203, &b_Event_LHEWeight203);
   fChain->SetBranchAddress("Event_LHEWeight204", &Event_LHEWeight204, &b_Event_LHEWeight204);
   fChain->SetBranchAddress("Event_LHEWeight205", &Event_LHEWeight205, &b_Event_LHEWeight205);
   fChain->SetBranchAddress("Event_LHEWeight206", &Event_LHEWeight206, &b_Event_LHEWeight206);
   fChain->SetBranchAddress("Event_LHEWeight207", &Event_LHEWeight207, &b_Event_LHEWeight207);
   fChain->SetBranchAddress("Event_LHEWeight208", &Event_LHEWeight208, &b_Event_LHEWeight208);
   fChain->SetBranchAddress("Event_LHEWeight209", &Event_LHEWeight209, &b_Event_LHEWeight209);
   fChain->SetBranchAddress("Event_LHEWeight210", &Event_LHEWeight210, &b_Event_LHEWeight210);
   fChain->SetBranchAddress("Event_LHEWeight211", &Event_LHEWeight211, &b_Event_LHEWeight211);
   fChain->SetBranchAddress("Event_LHEWeight212", &Event_LHEWeight212, &b_Event_LHEWeight212);
   fChain->SetBranchAddress("Event_LHEWeight213", &Event_LHEWeight213, &b_Event_LHEWeight213);
   fChain->SetBranchAddress("Event_LHEWeight214", &Event_LHEWeight214, &b_Event_LHEWeight214);
   fChain->SetBranchAddress("Event_LHEWeight215", &Event_LHEWeight215, &b_Event_LHEWeight215);
   fChain->SetBranchAddress("Event_LHEWeight216", &Event_LHEWeight216, &b_Event_LHEWeight216);
   fChain->SetBranchAddress("Event_LHEWeight217", &Event_LHEWeight217, &b_Event_LHEWeight217);
   fChain->SetBranchAddress("Event_LHEWeight218", &Event_LHEWeight218, &b_Event_LHEWeight218);
   fChain->SetBranchAddress("Event_LHEWeight219", &Event_LHEWeight219, &b_Event_LHEWeight219);
   fChain->SetBranchAddress("Event_LHEWeight220", &Event_LHEWeight220, &b_Event_LHEWeight220);
   fChain->SetBranchAddress("Event_LHEWeight221", &Event_LHEWeight221, &b_Event_LHEWeight221);
   fChain->SetBranchAddress("Event_LHEWeight222", &Event_LHEWeight222, &b_Event_LHEWeight222);
   fChain->SetBranchAddress("Event_LHEWeight223", &Event_LHEWeight223, &b_Event_LHEWeight223);
   fChain->SetBranchAddress("Event_LHEWeight224", &Event_LHEWeight224, &b_Event_LHEWeight224);
   fChain->SetBranchAddress("Event_LHEWeight225", &Event_LHEWeight225, &b_Event_LHEWeight225);
   fChain->SetBranchAddress("Event_LHEWeight226", &Event_LHEWeight226, &b_Event_LHEWeight226);
   fChain->SetBranchAddress("Event_LHEWeight227", &Event_LHEWeight227, &b_Event_LHEWeight227);
   fChain->SetBranchAddress("Event_LHEWeight228", &Event_LHEWeight228, &b_Event_LHEWeight228);
   fChain->SetBranchAddress("Event_LHEWeight229", &Event_LHEWeight229, &b_Event_LHEWeight229);
   fChain->SetBranchAddress("Event_LHEWeight230", &Event_LHEWeight230, &b_Event_LHEWeight230);
   fChain->SetBranchAddress("Event_LHEWeight231", &Event_LHEWeight231, &b_Event_LHEWeight231);
   fChain->SetBranchAddress("Event_LHEWeight232", &Event_LHEWeight232, &b_Event_LHEWeight232);
   fChain->SetBranchAddress("Event_LHEWeight233", &Event_LHEWeight233, &b_Event_LHEWeight233);
   fChain->SetBranchAddress("Event_LHEWeight234", &Event_LHEWeight234, &b_Event_LHEWeight234);
   fChain->SetBranchAddress("Event_LHEWeight235", &Event_LHEWeight235, &b_Event_LHEWeight235);
   fChain->SetBranchAddress("Event_LHEWeight236", &Event_LHEWeight236, &b_Event_LHEWeight236);
   fChain->SetBranchAddress("Event_LHEWeight237", &Event_LHEWeight237, &b_Event_LHEWeight237);
   fChain->SetBranchAddress("Event_LHEWeight238", &Event_LHEWeight238, &b_Event_LHEWeight238);
   fChain->SetBranchAddress("Event_LHEWeight239", &Event_LHEWeight239, &b_Event_LHEWeight239);
   fChain->SetBranchAddress("Event_LHEWeight240", &Event_LHEWeight240, &b_Event_LHEWeight240);
   fChain->SetBranchAddress("Event_LHEWeight241", &Event_LHEWeight241, &b_Event_LHEWeight241);
   fChain->SetBranchAddress("Event_LHEWeight242", &Event_LHEWeight242, &b_Event_LHEWeight242);
   fChain->SetBranchAddress("Event_LHEWeight243", &Event_LHEWeight243, &b_Event_LHEWeight243);
   fChain->SetBranchAddress("Event_LHEWeight244", &Event_LHEWeight244, &b_Event_LHEWeight244);
   fChain->SetBranchAddress("Event_LHEWeight245", &Event_LHEWeight245, &b_Event_LHEWeight245);
   fChain->SetBranchAddress("Event_LHEWeight246", &Event_LHEWeight246, &b_Event_LHEWeight246);
   fChain->SetBranchAddress("Event_LHEWeight247", &Event_LHEWeight247, &b_Event_LHEWeight247);
   fChain->SetBranchAddress("Event_LHEWeight248", &Event_LHEWeight248, &b_Event_LHEWeight248);
   fChain->SetBranchAddress("Event_LHEWeight249", &Event_LHEWeight249, &b_Event_LHEWeight249);
   fChain->SetBranchAddress("Event_LHEWeight250", &Event_LHEWeight250, &b_Event_LHEWeight250);
   fChain->SetBranchAddress("Event_LHEWeight251", &Event_LHEWeight251, &b_Event_LHEWeight251);
   fChain->SetBranchAddress("Event_LHEWeight252", &Event_LHEWeight252, &b_Event_LHEWeight252);
   fChain->SetBranchAddress("Event_LHEWeight253", &Event_LHEWeight253, &b_Event_LHEWeight253);
   fChain->SetBranchAddress("Event_LHEWeight254", &Event_LHEWeight254, &b_Event_LHEWeight254);
   fChain->SetBranchAddress("Event_LHEWeight255", &Event_LHEWeight255, &b_Event_LHEWeight255);
   fChain->SetBranchAddress("Event_LHEWeight256", &Event_LHEWeight256, &b_Event_LHEWeight256);
   fChain->SetBranchAddress("Event_LHEWeight257", &Event_LHEWeight257, &b_Event_LHEWeight257);
   fChain->SetBranchAddress("Event_LHEWeight258", &Event_LHEWeight258, &b_Event_LHEWeight258);
   fChain->SetBranchAddress("Event_LHEWeight259", &Event_LHEWeight259, &b_Event_LHEWeight259);
   fChain->SetBranchAddress("Event_LHEWeight260", &Event_LHEWeight260, &b_Event_LHEWeight260);
   fChain->SetBranchAddress("Event_LHEWeight261", &Event_LHEWeight261, &b_Event_LHEWeight261);
   fChain->SetBranchAddress("Event_LHEWeight262", &Event_LHEWeight262, &b_Event_LHEWeight262);
   fChain->SetBranchAddress("Event_LHEWeight263", &Event_LHEWeight263, &b_Event_LHEWeight263);
   fChain->SetBranchAddress("Event_LHEWeight264", &Event_LHEWeight264, &b_Event_LHEWeight264);
   fChain->SetBranchAddress("Event_LHEWeight265", &Event_LHEWeight265, &b_Event_LHEWeight265);
   fChain->SetBranchAddress("Event_LHEWeight266", &Event_LHEWeight266, &b_Event_LHEWeight266);
   fChain->SetBranchAddress("Event_LHEWeight267", &Event_LHEWeight267, &b_Event_LHEWeight267);
   fChain->SetBranchAddress("Event_LHEWeight268", &Event_LHEWeight268, &b_Event_LHEWeight268);
   fChain->SetBranchAddress("Event_LHEWeight269", &Event_LHEWeight269, &b_Event_LHEWeight269);
   fChain->SetBranchAddress("Event_LHEWeight270", &Event_LHEWeight270, &b_Event_LHEWeight270);
   fChain->SetBranchAddress("Event_LHEWeight271", &Event_LHEWeight271, &b_Event_LHEWeight271);
   fChain->SetBranchAddress("Event_LHEWeight272", &Event_LHEWeight272, &b_Event_LHEWeight272);
   fChain->SetBranchAddress("Event_LHEWeight273", &Event_LHEWeight273, &b_Event_LHEWeight273);
   fChain->SetBranchAddress("Event_LHEWeight274", &Event_LHEWeight274, &b_Event_LHEWeight274);
   fChain->SetBranchAddress("Event_LHEWeight275", &Event_LHEWeight275, &b_Event_LHEWeight275);
   fChain->SetBranchAddress("Event_LHEWeight276", &Event_LHEWeight276, &b_Event_LHEWeight276);
   fChain->SetBranchAddress("Event_LHEWeight277", &Event_LHEWeight277, &b_Event_LHEWeight277);
   fChain->SetBranchAddress("Event_LHEWeight278", &Event_LHEWeight278, &b_Event_LHEWeight278);
   fChain->SetBranchAddress("Event_LHEWeight279", &Event_LHEWeight279, &b_Event_LHEWeight279);
   fChain->SetBranchAddress("Event_LHEWeight280", &Event_LHEWeight280, &b_Event_LHEWeight280);
   fChain->SetBranchAddress("Event_LHEWeight281", &Event_LHEWeight281, &b_Event_LHEWeight281);
   fChain->SetBranchAddress("Event_LHEWeight282", &Event_LHEWeight282, &b_Event_LHEWeight282);
   fChain->SetBranchAddress("Event_LHEWeight283", &Event_LHEWeight283, &b_Event_LHEWeight283);
   fChain->SetBranchAddress("Event_LHEWeight284", &Event_LHEWeight284, &b_Event_LHEWeight284);
   fChain->SetBranchAddress("Event_LHEWeight285", &Event_LHEWeight285, &b_Event_LHEWeight285);
   fChain->SetBranchAddress("Event_LHEWeight286", &Event_LHEWeight286, &b_Event_LHEWeight286);
   fChain->SetBranchAddress("Event_LHEWeight287", &Event_LHEWeight287, &b_Event_LHEWeight287);
   fChain->SetBranchAddress("Event_LHEWeight288", &Event_LHEWeight288, &b_Event_LHEWeight288);
   fChain->SetBranchAddress("Event_LHEWeight289", &Event_LHEWeight289, &b_Event_LHEWeight289);
   fChain->SetBranchAddress("Event_LHEWeight290", &Event_LHEWeight290, &b_Event_LHEWeight290);
   fChain->SetBranchAddress("Event_LHEWeight291", &Event_LHEWeight291, &b_Event_LHEWeight291);
   fChain->SetBranchAddress("Event_LHEWeight292", &Event_LHEWeight292, &b_Event_LHEWeight292);
   fChain->SetBranchAddress("Event_LHEWeight293", &Event_LHEWeight293, &b_Event_LHEWeight293);
   fChain->SetBranchAddress("Event_LHEWeight294", &Event_LHEWeight294, &b_Event_LHEWeight294);
   fChain->SetBranchAddress("Event_LHEWeight295", &Event_LHEWeight295, &b_Event_LHEWeight295);
   fChain->SetBranchAddress("Event_LHEWeight296", &Event_LHEWeight296, &b_Event_LHEWeight296);
   fChain->SetBranchAddress("Event_LHEWeight297", &Event_LHEWeight297, &b_Event_LHEWeight297);
   fChain->SetBranchAddress("Event_LHEWeight298", &Event_LHEWeight298, &b_Event_LHEWeight298);
   fChain->SetBranchAddress("Event_LHEWeight299", &Event_LHEWeight299, &b_Event_LHEWeight299);
   fChain->SetBranchAddress("Event_LHEWeight300", &Event_LHEWeight300, &b_Event_LHEWeight300);
   fChain->SetBranchAddress("Event_LHEWeight301", &Event_LHEWeight301, &b_Event_LHEWeight301);
   fChain->SetBranchAddress("Event_LHEWeight302", &Event_LHEWeight302, &b_Event_LHEWeight302);
   fChain->SetBranchAddress("Event_LHEWeight303", &Event_LHEWeight303, &b_Event_LHEWeight303);
   fChain->SetBranchAddress("Event_LHEWeight304", &Event_LHEWeight304, &b_Event_LHEWeight304);
   fChain->SetBranchAddress("Event_LHEWeight305", &Event_LHEWeight305, &b_Event_LHEWeight305);
   fChain->SetBranchAddress("Event_LHEWeight306", &Event_LHEWeight306, &b_Event_LHEWeight306);
   fChain->SetBranchAddress("Event_LHEWeight307", &Event_LHEWeight307, &b_Event_LHEWeight307);
   fChain->SetBranchAddress("Event_LHEWeight308", &Event_LHEWeight308, &b_Event_LHEWeight308);
   fChain->SetBranchAddress("Event_LHEWeight309", &Event_LHEWeight309, &b_Event_LHEWeight309);
   fChain->SetBranchAddress("Event_LHEWeight310", &Event_LHEWeight310, &b_Event_LHEWeight310);
   fChain->SetBranchAddress("Event_LHEWeight311", &Event_LHEWeight311, &b_Event_LHEWeight311);
   fChain->SetBranchAddress("Event_LHEWeight312", &Event_LHEWeight312, &b_Event_LHEWeight312);
   fChain->SetBranchAddress("Event_LHEWeight313", &Event_LHEWeight313, &b_Event_LHEWeight313);
   fChain->SetBranchAddress("Event_LHEWeight314", &Event_LHEWeight314, &b_Event_LHEWeight314);
   fChain->SetBranchAddress("Event_LHEWeight315", &Event_LHEWeight315, &b_Event_LHEWeight315);
   fChain->SetBranchAddress("Event_LHEWeight316", &Event_LHEWeight316, &b_Event_LHEWeight316);
   fChain->SetBranchAddress("Event_LHEWeight317", &Event_LHEWeight317, &b_Event_LHEWeight317);
   fChain->SetBranchAddress("Event_LHEWeight318", &Event_LHEWeight318, &b_Event_LHEWeight318);
   fChain->SetBranchAddress("Event_LHEWeight319", &Event_LHEWeight319, &b_Event_LHEWeight319);
   fChain->SetBranchAddress("Event_LHEWeight320", &Event_LHEWeight320, &b_Event_LHEWeight320);
   fChain->SetBranchAddress("Event_LHEWeight321", &Event_LHEWeight321, &b_Event_LHEWeight321);
   fChain->SetBranchAddress("Event_LHEWeight322", &Event_LHEWeight322, &b_Event_LHEWeight322);
   fChain->SetBranchAddress("Event_LHEWeight323", &Event_LHEWeight323, &b_Event_LHEWeight323);
   fChain->SetBranchAddress("Event_LHEWeight324", &Event_LHEWeight324, &b_Event_LHEWeight324);
   fChain->SetBranchAddress("Event_LHEWeight325", &Event_LHEWeight325, &b_Event_LHEWeight325);
   fChain->SetBranchAddress("Event_LHEWeight326", &Event_LHEWeight326, &b_Event_LHEWeight326);
   fChain->SetBranchAddress("Event_LHEWeight327", &Event_LHEWeight327, &b_Event_LHEWeight327);
   fChain->SetBranchAddress("Event_LHEWeight328", &Event_LHEWeight328, &b_Event_LHEWeight328);
   fChain->SetBranchAddress("Event_LHEWeight329", &Event_LHEWeight329, &b_Event_LHEWeight329);
   fChain->SetBranchAddress("Event_LHEWeight330", &Event_LHEWeight330, &b_Event_LHEWeight330);
   fChain->SetBranchAddress("Event_LHEWeight331", &Event_LHEWeight331, &b_Event_LHEWeight331);
   fChain->SetBranchAddress("Event_LHEWeight332", &Event_LHEWeight332, &b_Event_LHEWeight332);
   fChain->SetBranchAddress("Event_LHEWeight333", &Event_LHEWeight333, &b_Event_LHEWeight333);
   fChain->SetBranchAddress("Event_LHEWeight334", &Event_LHEWeight334, &b_Event_LHEWeight334);
   fChain->SetBranchAddress("Event_LHEWeight335", &Event_LHEWeight335, &b_Event_LHEWeight335);
   fChain->SetBranchAddress("Event_LHEWeight336", &Event_LHEWeight336, &b_Event_LHEWeight336);
   fChain->SetBranchAddress("Event_LHEWeight337", &Event_LHEWeight337, &b_Event_LHEWeight337);
   fChain->SetBranchAddress("Event_LHEWeight338", &Event_LHEWeight338, &b_Event_LHEWeight338);
   fChain->SetBranchAddress("Event_LHEWeight339", &Event_LHEWeight339, &b_Event_LHEWeight339);
   fChain->SetBranchAddress("Event_LHEWeight340", &Event_LHEWeight340, &b_Event_LHEWeight340);
   fChain->SetBranchAddress("Event_LHEWeight341", &Event_LHEWeight341, &b_Event_LHEWeight341);
   fChain->SetBranchAddress("Event_LHEWeight342", &Event_LHEWeight342, &b_Event_LHEWeight342);
   fChain->SetBranchAddress("Event_LHEWeight343", &Event_LHEWeight343, &b_Event_LHEWeight343);
   fChain->SetBranchAddress("Event_LHEWeight344", &Event_LHEWeight344, &b_Event_LHEWeight344);
   fChain->SetBranchAddress("Event_LHEWeight345", &Event_LHEWeight345, &b_Event_LHEWeight345);
   fChain->SetBranchAddress("Event_LHEWeight346", &Event_LHEWeight346, &b_Event_LHEWeight346);
   fChain->SetBranchAddress("Event_LHEWeight347", &Event_LHEWeight347, &b_Event_LHEWeight347);
   fChain->SetBranchAddress("Event_LHEWeight348", &Event_LHEWeight348, &b_Event_LHEWeight348);
   fChain->SetBranchAddress("Event_LHEWeight349", &Event_LHEWeight349, &b_Event_LHEWeight349);
   fChain->SetBranchAddress("Event_LHEWeight350", &Event_LHEWeight350, &b_Event_LHEWeight350);
   fChain->SetBranchAddress("Event_LHEWeight351", &Event_LHEWeight351, &b_Event_LHEWeight351);
   fChain->SetBranchAddress("Event_LHEWeight352", &Event_LHEWeight352, &b_Event_LHEWeight352);
   fChain->SetBranchAddress("Event_LHEWeight353", &Event_LHEWeight353, &b_Event_LHEWeight353);
   fChain->SetBranchAddress("Event_LHEWeight354", &Event_LHEWeight354, &b_Event_LHEWeight354);
   fChain->SetBranchAddress("Event_LHEWeight355", &Event_LHEWeight355, &b_Event_LHEWeight355);
   fChain->SetBranchAddress("Event_LHEWeight356", &Event_LHEWeight356, &b_Event_LHEWeight356);
   fChain->SetBranchAddress("Event_LHEWeight357", &Event_LHEWeight357, &b_Event_LHEWeight357);
   fChain->SetBranchAddress("Event_LHEWeight358", &Event_LHEWeight358, &b_Event_LHEWeight358);
   fChain->SetBranchAddress("Event_LHEWeight359", &Event_LHEWeight359, &b_Event_LHEWeight359);
   fChain->SetBranchAddress("Event_LHEWeight360", &Event_LHEWeight360, &b_Event_LHEWeight360);
   fChain->SetBranchAddress("Event_LHEWeight361", &Event_LHEWeight361, &b_Event_LHEWeight361);
   fChain->SetBranchAddress("Event_LHEWeight362", &Event_LHEWeight362, &b_Event_LHEWeight362);
   fChain->SetBranchAddress("Event_LHEWeight363", &Event_LHEWeight363, &b_Event_LHEWeight363);
   fChain->SetBranchAddress("Event_LHEWeight364", &Event_LHEWeight364, &b_Event_LHEWeight364);
   fChain->SetBranchAddress("Event_LHEWeight365", &Event_LHEWeight365, &b_Event_LHEWeight365);
   fChain->SetBranchAddress("Event_LHEWeight366", &Event_LHEWeight366, &b_Event_LHEWeight366);
   fChain->SetBranchAddress("Event_LHEWeight367", &Event_LHEWeight367, &b_Event_LHEWeight367);
   fChain->SetBranchAddress("Event_LHEWeight368", &Event_LHEWeight368, &b_Event_LHEWeight368);
   fChain->SetBranchAddress("Event_LHEWeight369", &Event_LHEWeight369, &b_Event_LHEWeight369);
   fChain->SetBranchAddress("Event_LHEWeight370", &Event_LHEWeight370, &b_Event_LHEWeight370);
   fChain->SetBranchAddress("Event_LHEWeight371", &Event_LHEWeight371, &b_Event_LHEWeight371);
   fChain->SetBranchAddress("Event_LHEWeight372", &Event_LHEWeight372, &b_Event_LHEWeight372);
   fChain->SetBranchAddress("Event_LHEWeight373", &Event_LHEWeight373, &b_Event_LHEWeight373);
   fChain->SetBranchAddress("Event_LHEWeight374", &Event_LHEWeight374, &b_Event_LHEWeight374);
   fChain->SetBranchAddress("Event_LHEWeight375", &Event_LHEWeight375, &b_Event_LHEWeight375);
   fChain->SetBranchAddress("Event_LHEWeight376", &Event_LHEWeight376, &b_Event_LHEWeight376);
   fChain->SetBranchAddress("Event_LHEWeight377", &Event_LHEWeight377, &b_Event_LHEWeight377);
   fChain->SetBranchAddress("Event_LHEWeight378", &Event_LHEWeight378, &b_Event_LHEWeight378);
   fChain->SetBranchAddress("Event_LHEWeight379", &Event_LHEWeight379, &b_Event_LHEWeight379);
   fChain->SetBranchAddress("Event_LHEWeight380", &Event_LHEWeight380, &b_Event_LHEWeight380);
   fChain->SetBranchAddress("Event_LHEWeight381", &Event_LHEWeight381, &b_Event_LHEWeight381);
   fChain->SetBranchAddress("Event_LHEWeight382", &Event_LHEWeight382, &b_Event_LHEWeight382);
   fChain->SetBranchAddress("Event_LHEWeight383", &Event_LHEWeight383, &b_Event_LHEWeight383);
   fChain->SetBranchAddress("Event_LHEWeight384", &Event_LHEWeight384, &b_Event_LHEWeight384);
   fChain->SetBranchAddress("Event_LHEWeight385", &Event_LHEWeight385, &b_Event_LHEWeight385);
   fChain->SetBranchAddress("Event_LHEWeight386", &Event_LHEWeight386, &b_Event_LHEWeight386);
   fChain->SetBranchAddress("Event_LHEWeight387", &Event_LHEWeight387, &b_Event_LHEWeight387);
   fChain->SetBranchAddress("Event_LHEWeight388", &Event_LHEWeight388, &b_Event_LHEWeight388);
   fChain->SetBranchAddress("Event_LHEWeight389", &Event_LHEWeight389, &b_Event_LHEWeight389);
   fChain->SetBranchAddress("Event_LHEWeight390", &Event_LHEWeight390, &b_Event_LHEWeight390);
   fChain->SetBranchAddress("Event_LHEWeight391", &Event_LHEWeight391, &b_Event_LHEWeight391);
   fChain->SetBranchAddress("Event_LHEWeight392", &Event_LHEWeight392, &b_Event_LHEWeight392);
   fChain->SetBranchAddress("Event_LHEWeight393", &Event_LHEWeight393, &b_Event_LHEWeight393);
   fChain->SetBranchAddress("Event_LHEWeight394", &Event_LHEWeight394, &b_Event_LHEWeight394);
   fChain->SetBranchAddress("Event_LHEWeight395", &Event_LHEWeight395, &b_Event_LHEWeight395);
   fChain->SetBranchAddress("Event_LHEWeight396", &Event_LHEWeight396, &b_Event_LHEWeight396);
   fChain->SetBranchAddress("Event_LHEWeight397", &Event_LHEWeight397, &b_Event_LHEWeight397);
   fChain->SetBranchAddress("Event_LHEWeight398", &Event_LHEWeight398, &b_Event_LHEWeight398);
   fChain->SetBranchAddress("Event_LHEWeight399", &Event_LHEWeight399, &b_Event_LHEWeight399);
   fChain->SetBranchAddress("Event_LHEWeight400", &Event_LHEWeight400, &b_Event_LHEWeight400);
   fChain->SetBranchAddress("Event_LHEWeight401", &Event_LHEWeight401, &b_Event_LHEWeight401);
   fChain->SetBranchAddress("Event_LHEWeight402", &Event_LHEWeight402, &b_Event_LHEWeight402);
   fChain->SetBranchAddress("Event_LHEWeight403", &Event_LHEWeight403, &b_Event_LHEWeight403);
   fChain->SetBranchAddress("Event_LHEWeight404", &Event_LHEWeight404, &b_Event_LHEWeight404);
   fChain->SetBranchAddress("Event_LHEWeight405", &Event_LHEWeight405, &b_Event_LHEWeight405);
   fChain->SetBranchAddress("Event_LHEWeight406", &Event_LHEWeight406, &b_Event_LHEWeight406);
   fChain->SetBranchAddress("Event_LHEWeight407", &Event_LHEWeight407, &b_Event_LHEWeight407);
   fChain->SetBranchAddress("Event_LHEWeight408", &Event_LHEWeight408, &b_Event_LHEWeight408);
   fChain->SetBranchAddress("Event_LHEWeight409", &Event_LHEWeight409, &b_Event_LHEWeight409);
   fChain->SetBranchAddress("Event_LHEWeight410", &Event_LHEWeight410, &b_Event_LHEWeight410);
   fChain->SetBranchAddress("Event_LHEWeight411", &Event_LHEWeight411, &b_Event_LHEWeight411);
   fChain->SetBranchAddress("Event_LHEWeight412", &Event_LHEWeight412, &b_Event_LHEWeight412);
   fChain->SetBranchAddress("Event_LHEWeight413", &Event_LHEWeight413, &b_Event_LHEWeight413);
   fChain->SetBranchAddress("Event_LHEWeight414", &Event_LHEWeight414, &b_Event_LHEWeight414);
   fChain->SetBranchAddress("Event_LHEWeight415", &Event_LHEWeight415, &b_Event_LHEWeight415);
   fChain->SetBranchAddress("Event_LHEWeight416", &Event_LHEWeight416, &b_Event_LHEWeight416);
   fChain->SetBranchAddress("Event_LHEWeight417", &Event_LHEWeight417, &b_Event_LHEWeight417);
   fChain->SetBranchAddress("Event_LHEWeight418", &Event_LHEWeight418, &b_Event_LHEWeight418);
   fChain->SetBranchAddress("Event_LHEWeight419", &Event_LHEWeight419, &b_Event_LHEWeight419);
   fChain->SetBranchAddress("Event_LHEWeight420", &Event_LHEWeight420, &b_Event_LHEWeight420);
   fChain->SetBranchAddress("Event_LHEWeight421", &Event_LHEWeight421, &b_Event_LHEWeight421);
   fChain->SetBranchAddress("Event_LHEWeight422", &Event_LHEWeight422, &b_Event_LHEWeight422);
   fChain->SetBranchAddress("Event_LHEWeight423", &Event_LHEWeight423, &b_Event_LHEWeight423);
   fChain->SetBranchAddress("Event_LHEWeight424", &Event_LHEWeight424, &b_Event_LHEWeight424);
   fChain->SetBranchAddress("Event_LHEWeight425", &Event_LHEWeight425, &b_Event_LHEWeight425);
   fChain->SetBranchAddress("Event_LHEWeight426", &Event_LHEWeight426, &b_Event_LHEWeight426);
   fChain->SetBranchAddress("Event_LHEWeight427", &Event_LHEWeight427, &b_Event_LHEWeight427);
   fChain->SetBranchAddress("Event_LHEWeight428", &Event_LHEWeight428, &b_Event_LHEWeight428);
   fChain->SetBranchAddress("Event_LHEWeight429", &Event_LHEWeight429, &b_Event_LHEWeight429);
   fChain->SetBranchAddress("Event_LHEWeight430", &Event_LHEWeight430, &b_Event_LHEWeight430);
   fChain->SetBranchAddress("Event_LHEWeight431", &Event_LHEWeight431, &b_Event_LHEWeight431);
   fChain->SetBranchAddress("Event_LHEWeight432", &Event_LHEWeight432, &b_Event_LHEWeight432);
   fChain->SetBranchAddress("Event_LHEWeight433", &Event_LHEWeight433, &b_Event_LHEWeight433);
   fChain->SetBranchAddress("Event_LHEWeight434", &Event_LHEWeight434, &b_Event_LHEWeight434);
   fChain->SetBranchAddress("Event_LHEWeight435", &Event_LHEWeight435, &b_Event_LHEWeight435);
   fChain->SetBranchAddress("Event_LHEWeight436", &Event_LHEWeight436, &b_Event_LHEWeight436);
   fChain->SetBranchAddress("Event_LHEWeight437", &Event_LHEWeight437, &b_Event_LHEWeight437);
   fChain->SetBranchAddress("Event_LHEWeight438", &Event_LHEWeight438, &b_Event_LHEWeight438);
   fChain->SetBranchAddress("Event_LHEWeight439", &Event_LHEWeight439, &b_Event_LHEWeight439);
   fChain->SetBranchAddress("Event_LHEWeight440", &Event_LHEWeight440, &b_Event_LHEWeight440);
   fChain->SetBranchAddress("Event_LHEWeight441", &Event_LHEWeight441, &b_Event_LHEWeight441);
   fChain->SetBranchAddress("Event_LHEWeight442", &Event_LHEWeight442, &b_Event_LHEWeight442);
   fChain->SetBranchAddress("Event_LHEWeight443", &Event_LHEWeight443, &b_Event_LHEWeight443);
   fChain->SetBranchAddress("Event_LHEWeight444", &Event_LHEWeight444, &b_Event_LHEWeight444);
   fChain->SetBranchAddress("Event_LHEWeight445", &Event_LHEWeight445, &b_Event_LHEWeight445);
   fChain->SetBranchAddress("Event_LHEWeight446", &Event_LHEWeight446, &b_Event_LHEWeight446);
   fChain->SetBranchAddress("Event_LHEWeight447", &Event_LHEWeight447, &b_Event_LHEWeight447);
   fChain->SetBranchAddress("Event_LHEWeight448", &Event_LHEWeight448, &b_Event_LHEWeight448);
   fChain->SetBranchAddress("Event_LHEWeight449", &Event_LHEWeight449, &b_Event_LHEWeight449);
   fChain->SetBranchAddress("Event_LHEWeight450", &Event_LHEWeight450, &b_Event_LHEWeight450);
   fChain->SetBranchAddress("Event_LHEWeight451", &Event_LHEWeight451, &b_Event_LHEWeight451);
   fChain->SetBranchAddress("Event_LHEWeight452", &Event_LHEWeight452, &b_Event_LHEWeight452);
   fChain->SetBranchAddress("Event_LHEWeight453", &Event_LHEWeight453, &b_Event_LHEWeight453);
   fChain->SetBranchAddress("Event_LHEWeight454", &Event_LHEWeight454, &b_Event_LHEWeight454);
   fChain->SetBranchAddress("Event_LHEWeight455", &Event_LHEWeight455, &b_Event_LHEWeight455);
   fChain->SetBranchAddress("Event_LHEWeight456", &Event_LHEWeight456, &b_Event_LHEWeight456);
   fChain->SetBranchAddress("Event_LHEWeight457", &Event_LHEWeight457, &b_Event_LHEWeight457);
   fChain->SetBranchAddress("Event_LHEWeight458", &Event_LHEWeight458, &b_Event_LHEWeight458);
   fChain->SetBranchAddress("Event_LHEWeight459", &Event_LHEWeight459, &b_Event_LHEWeight459);
   fChain->SetBranchAddress("Event_LHEWeight460", &Event_LHEWeight460, &b_Event_LHEWeight460);
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

#ifndef MassPlotterEleTau_HH
#define MassPlotterEleTau_HH

#include "TLatex.h"
#include "TLegend.h"
#include "TLegendEntry.h"
#include "TLine.h"
#include "TArrow.h"
#include "TBox.h"
#include "TMath.h"

#include "TEventList.h"
#include "TROOT.h"
#include "THStack.h"
#include "TTree.h"
#include "TH2.h"
#include "TTreeFormula.h"
#include "TGraph.h"
#include "TLorentzVector.h"

#include <vector>
#include <utility>

#include "Extendeds.hh"

using namespace std;


namespace Util {
//__________________________________________________________________________
inline TString MakeOutputDir(TString dir){
  if(!dir.EndsWith("/")) dir += "/";
  // Create directory if needed
  // >> NOTE: This function needs to be called before the booking functions!
  char cmd[100];
  sprintf(cmd,"mkdir -p %s", dir.Data());
  int restult = system(cmd);
  return dir;
}
  inline double DeltaPhi(double phi1, double phi2){
    // From cmssw reco::deltaPhi()
    double result = phi1 - phi2;
    while( result > TMath::Pi() ) result -= TMath::TwoPi();
    while( result <= -TMath::Pi() ) result += TMath::TwoPi();
    return TMath::Abs(result);
  }

  inline double GetDeltaR(double eta1, double eta2, double phi1, double phi2){
    double deta = eta1 - eta2;
    double dphi = Util::DeltaPhi(phi1, phi2);
    return sqrt( deta*deta + dphi*dphi );
  }

}

class BaseMassPlotter {
public:
  BaseMassPlotter(TString outputdir);
  
  TString fPath;
  TString fOutputDir;
  int fVerbose;
  void setVerbose(int v){ fVerbose = v;};
  void init(TString filename = "samples.dat");
  void loadSamples(const char* filename = "samples.dat");
  std::vector<sample>  fSamples;  


};

#endif

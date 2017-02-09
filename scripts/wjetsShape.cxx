#include "TH1D.h"
#include "TString.h"
#include "TList.h"
#include <map>
#include <set>
#include <sstream>
#include "TChain.h"
#include "TTreeViewer.h"

using namespace std;

TChain* chain_iso_amc;
TChain* chain_noniso_amc;
TChain* chain_iso_mg;
TChain* chain_noniso_mg;
TTreeViewer* v;

TH1* formatmg(TH1* h){
  h->SetLineColor(8);
  h->SetLineWidth(2);
  h->SetTitle("MG");
  
  return h;
}

TH1* formatamc(TH1* h){
  h->SetLineColor(46);
  h->SetTitle("amc@NLO");
  h->SetLineWidth(2);

  return h;
}

void wjetsShape(TString filename_amcatnlo, TString filename_madgraph, TString channel , int charge = 0 ){
  TString cutCharge("weight" );
  if( charge > 0 )
    cutCharge = "weight*(isPositive == 1)";
  else if(charge < 0)
    cutCharge = "weight*(isPositive == 0)";

  


  chain_iso_amc = new TChain("Trees/iso" + channel , "iso_amc");
  chain_iso_mg = new TChain("Trees/iso" + channel , "iso_mg");
  chain_noniso_amc = new TChain("Trees/noniso" + channel , "noniso_amc");
  chain_noniso_mg  = new TChain("Trees/noniso" + channel , "noniso_mg");

  chain_noniso_amc->Add(filename_amcatnlo);
  chain_iso_amc->Add(filename_amcatnlo);

  chain_noniso_mg->Add(filename_madgraph);
  chain_iso_mg->Add(filename_madgraph);

  TH1::SetDefaultSumw2();
  gStyle->SetOptTitle(false);
  gStyle->SetOptStat("nemri");
  TString title = channel ;
  if( channel == "2j1t" )
    title = "2-jet 1-tag";
  else if ( channel == "3j2t" )
    title = "3-jet 2-tag";
  else if ( channel == "3j1t" )
    title = "3-jet 1-tag";

  if( charge == 0 )
    title += ", all #mu's";
  if( charge > 0 )
    title += ", #mu^{+}";
  if( charge < 0 )
    title += ", #mu^{-}";

  TString outname = channel ;
  if( charge == 0 )
    outname += "_all";
  if( charge > 0 )
    outname += "_p";
  if( charge < 0 )
    outname += "_n";


  gROOT->cd();
  chain_iso_mg->Draw("mtw>>iso_mg(20,0,200)" , cutCharge );
  chain_iso_amc->Draw("mtw>>iso_amc(20,0,200)" , cutCharge);
  chain_noniso_mg->Draw("mtw>>noniso_mg(20,0,200)" , cutCharge );
  chain_noniso_amc->Draw("mtw>>noniso_amc(20,0,200)" , cutCharge );
  TCanvas* canvas = new TCanvas(outname , outname);
  canvas->Divide(2,1);
  TCanvas* currentc = (TCanvas*)( canvas->cd(1) );
  TH1* iso_mg = (TH1*)(gROOT->Get("iso_mg"));
  TH1* iso_amc = (TH1*)(gROOT->Get("iso_amc"));
  formatamc(iso_amc)->Draw();
  formatmg(iso_mg)->Draw("SAMES");
  TLegend* ll = currentc->BuildLegend();
  ll->SetHeader(title);

  currentc = (TCanvas*)(   canvas->cd(2) );
  TH1* noniso_mg = (TH1*)(gROOT->Get("noniso_mg"));
  TH1* noniso_amc = (TH1*)(gROOT->Get("noniso_amc"));
  formatmg(noniso_mg)->Draw();
  formatamc(noniso_amc)->Draw("SAMES");
  TLegend *l =currentc->BuildLegend();
  l->SetHeader(title);

  return;

  v = new TTreeViewer( chain_iso_amc );
  v->AppendTree( chain_noniso_amc );
  v->AppendTree( chain_noniso_mg );
  v->AppendTree( chain_iso_mg );


}


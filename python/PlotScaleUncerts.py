from ROOT import TH1D, TFile, TCanvas, kRed,kBlue
from math import sqrt, fabs

name = 'tm'
name2 = 'TopMass'
title = 'Top Mass (GeV)'
# name = 'jp'
# name2 = 'jprimeEta'
# title = "|#eta|_{j'}"
famcatnlo = TFile.Open("cp3_condor/TChFARM_V6/outputs/TChannel_WJets_amcatnlo.root")
hamcatnlo = famcatnlo.Get("iso2j1t/%s/iso2j1t_%s_VJets" % (name2 , name2) )

f = TFile.Open("cp3_condor/TChFARM_V6/outputs/TChannel_WJets_mg_full2.root")
hSums = f.Get("iso2j1t_systematics/hSumScaleWeights")

template = "iso2j1t_systematics/h%s_s%d"
c = TCanvas()
print hamcatnlo.Integral()
hamcatnlo.SetTitle("amc@nlo")
hamcatnlo.SetLineColor(kRed)
hamcatnlo.SetLineWidth(2)
hamcatnlo.GetXaxis().SetTitle( title )
hamcatnlo.SetFillColor( 0 )
hamcatnlo.DrawNormalized()
hmg = f.Get( template % ( name , 0) )
hmg.SetBinContent( hmg.GetNbinsX() , hmg.GetBinContent( hmg.GetNbinsX() )+hmg.GetBinContent( hmg.GetNbinsX()+1 ) )
hmg.SetTitle("MadGraph")
hmg.SetLineColor(kBlue)
hmg.SetLineWidth(2)
print hmg.Integral()
hmg.DrawNormalized("SAME")
hUncerts=hmg.Clone("hUncerts")
hUncerts.SetTitle("Scale Variations")
for i in range(0, hUncerts.GetNbinsX() + 2) :
    hUncerts.SetBinError( i , 0.0 )

for i in [1,2,3,4,6,8]:
    hi = f.Get( template % ( name , i) )
    hi.Scale( hSums.GetBinContent(1)/hSums.GetBinContent(i+1) )
    hi.SetBinError( hi.GetNbinsX() , sqrt( hi.GetBinError( hi.GetNbinsX() )**2 + hi.GetBinError( hi.GetNbinsX()+1 )**2 ) )
    
    for j in range(0, hUncerts.GetXaxis().GetNbins() + 2) :
        diff = fabs( hi.GetBinContent( j )-hmg.GetBinContent(j) )
        err = hUncerts.GetBinError( j )
        if diff > err :
            hUncerts.SetBinError( j , diff)
            

hUncerts.SetLineColor(3)
hUncerts.Scale( 1./ hUncerts.Integral() )
hUncerts.Print("ALL")
hUncerts.SetFillStyle(3001)
hUncerts.SetFillColor(3)
hUncerts.Draw("SAMES E2")




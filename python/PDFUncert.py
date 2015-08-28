from ROOT import TDirectory, TH1D, TCanvas, TList, TFile, TAxis, TPad, gPad, THStack, TLatex , TLine, TLegend, kRed , kBlue, Double
import re
from math import sqrt

from ObjectProperty import ObjectProperty

def PDFUncert( fileName, DirName , nominalDir , sampleName , nUncerts=102 ):
    f = TFile.Open(fileName)
    pdf_dir = f.GetDirectory(DirName)
    
    nominal_dir = f.GetDirectory(nominalDir)
    nominal_obj = ObjectProperty( nominal_dir , sampleName , ["SUSY" , "TChannel_N" , "TChannel_P" , "VJets_N" , "VJets_P"] )
    nominal_hist = nominal_obj.Signal
    

    hAvg = nominal_hist.Clone("hAvg")
    hAvg.Reset("M")
    hSumSquared = nominal_hist.Clone("hSumsquared")
    hSumSquared.Reset("M")

    allHistos = []
    c = TCanvas()
    
    for nUncert in range(0, nUncerts):
        hName = "hEtaJp_PDF%d" % (nUncert)
        hUncert = pdf_dir.Get( hName )
        c.cd()
        allHistos.append( hUncert.Clone("SAME%d"  % (nUncert)) )
        allHistos[-1].Draw("SAME")

        hAvg.Add( hUncert )

        hUncert.Multiply( hUncert )
        hSumSquared.Add( hUncert )

    hAvg.Scale( 1.0/nUncerts )
    hAvg.Multiply( hAvg )

    hSumSquared.Scale( 1.0/nUncerts )
    hSumSquared.Add( hAvg , -1 )

    for bin in range(0 , hSumSquared.GetNbinsX()+2 ):
        hSumSquared.SetBinContent( bin ,  sqrt( hSumSquared.GetBinContent(bin) ) )
        hSumSquared.SetBinError( bin , 0 )

    hSumSquared.GetYaxis().SetTitle("relative pdf variations for %s sample" % (sampleName))
    hSumSquared.Divide( nominal_hist )
    hSumSquared.SaveAs("b.C")

    c.cd()
    nominal_hist.Draw("same")
    nominal_hist.SetLineColor(kRed)
    c.SaveAs("a.C")

    return hAvg

pdf = PDFUncert( "MassPlots/PDFUncertW_Sample.root" , "PDFScales" , "jPrimeEta" , "VJets" )

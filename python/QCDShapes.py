from ObjectProperty import ObjectProperty
from ROOT import TFile, TDirectory, TH1D, Double
import sys

selections = ["noniso2j1t" , "noniso3j2t" , "noniso3j1t" ]
props = [ "muPt" , "muAbsEta" , "MET" , "MTAfterCut" , "TopMass" , "jprimePt" , "bPt" , "jprimeEta" , "bEta" ]
fn = sys.argv[1]
print fn

file = TFile.Open( fn )
fout = TFile.Open( "QCDShapes.root" , "RECREATE" )
for selection in selections:
    for prop in props:
        dir = file.GetDirectory( "%s/%s" % (selection , prop ) )
        obj = ObjectProperty( dir , "QCD1" , ["SUSY" , "TChannel_N" , "TChannel_P" , "VJets_N" , "VJets_P"] )
        qcd = obj.GetDataSumBKGsSubtracted()
        err = Double(0)
        val = qcd.IntegralAndError( -1 , 10000 , err )
        print "%s in %s is normalized to %.2f +- %.2f" % (prop , selection , val , err )
        qcd.Scale( 1.0/ val )
        fout.cd()
        qcd.SetName( "%s_%s" % (selection, prop ) )
        qcd.Write()

fout.Write()
fout.Close()

file.Close()



from ROOT import TFile, TTree

import FWCore.ParameterSet.VarParsing as opts

options = opts.VarParsing ('analysis')
options.register('dir',
                 '',
                 opts.VarParsing.multiplicity.singleton,
                 opts.VarParsing.varType.string,
                 'directory')

options.parseArguments()

if not options.dir.endswith("/"):
    options.dir += "/"
import os  

nPositiveEvents = 0
nNegativeEvents = 0
nTotal = 0

for fn in sorted(os.listdir(options.dir)):
    ffn = options.dir + fn
    if os.path.isfile(ffn) and fn.endswith('.root'):
        f = TFile.Open( ffn , "READ")
        tree = f.Get("DMTreesDumper/ttDM__noSyst")
        n = tree.GetEntries()
        nTotal += n
        nPositiveEvents += tree.Draw(">>allp" , "Event_LHEWeightSign>0")
        nNegativeEvents += tree.Draw(">>alln" , "Event_LHEWeightSign<0")
        print "%s\t%d" % (ffn, n)
        f.Close()

print "#Positive %d" % (nPositiveEvents)
print "#Negative %d" % (nNegativeEvents)
print "#Effective %d" % (nPositiveEvents - nNegativeEvents)
print "#Total %d" % (nTotal)

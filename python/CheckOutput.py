from ROOT import TFile, TTree

from os import listdir
from os.path import isfile, join

mypath = "TChFARM_V4/outputs/"

#onlyfiles = [f for f in listdir(mypath) if (("RunII_25ns" in f) and isfile(join(mypath, f)))]
onlyfiles = [f for f in listdir(mypath) if isfile(join(mypath, f))]
for file in onlyfiles:
    f = TFile.Open( join( mypath , file) )
    tree_names = ["iso2j0t"   ,
                  "noniso2j0t",
                  "iso2j1t"   ,
                  "noniso2j1t",
                  "iso3j1t"   ,
                  "noniso3j1t",
                  "iso3j2t"   ,
                  "noniso3j2t",
                  ]
    trees = {}

    total = 0
    for tn in tree_names:
        trees[tn] = f.Get( "Trees/" + tn )
        total += trees[tn].GetEntries()

    if total == 0:
        print "%s has no event in trees" %( file )
    #else:
        #print "%s/%s : %d" % (mypath , file , total)

    f.Close()
print "in total %d files were checked" % ( len( onlyfiles ) )


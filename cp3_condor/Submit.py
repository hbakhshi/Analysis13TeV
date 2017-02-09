import LaunchOnCondor

import urllib
import string
import os
import sys
import glob



cpVersion = "V7"
FarmDirectory = "TChFARM_"+cpVersion
JobName = "STFull_"+cpVersion

samples = {'RunII_25ns':74024153 , 'Signal':29257464 , 'QCDMuEnriched':21708235 , 'WJets':47161328 , 'DYJets':28751199 , 'SingleTop_tW':1000000 , 'SingleTopbar_tW':999400 , 'TTJets':97994442 , 'WJets_amcatnlo':239170847 , 'WJets_mg_full':47161328 }

nevents_perjob = 1200000
total_nevents = 0
for sample in samples:
    total_nevents += samples[sample]
print 'is going to run on %d events, ~%d events per job' % (total_nevents , nevents_perjob)


if not os.path.isdir( "/home/fynu/hbakhshiansohi/scratch/FARMS/" + FarmDirectory ):
    os.makedirs( "/home/fynu/hbakhshiansohi/scratch/FARMS/" + FarmDirectory )

if os.path.islink( "./" + FarmDirectory ):
    os.remove( "./" + FarmDirectory)
elif os.path.isdir( "./" + FarmDirectory ):
    os.rename( "./" + FarmDirectory , "./" + FarmDirectory + "_OLD" )
    print "old is renamed"
os.symlink( "/home/fynu/hbakhshiansohi/scratch/FARMS/" + FarmDirectory , "./" + FarmDirectory )

LaunchOnCondor.Jobs_FinalCmds.append('echo "damet-garm" \n')
LaunchOnCondor.SendCluster_Create(FarmDirectory, JobName)

outputdir = FarmDirectory + '/outputs/'
FileTemplate = 'TChannel_%(sample)s_%(from).0f_%(to).0f'
command = 'cd .. ; source env.sh ; bin/RunAll -s samples25ns/samplesMine76x.dat -f ' + FileTemplate + ' -a %(sample)s -r %(from).2f -t %(to).2f -d cp3_condor/' + outputdir

global_job_counter = 0
for sample in samples:
    if not sample == "WJets_amcatnlo" :
        continue
    nevt = samples[sample]
    portions = []
    lasteventadded = 0.0
    while lasteventadded < 100.0 :
        portions.append( lasteventadded )
        lasteventadded  += 100.0*nevents_perjob/nevt
    portions.append( 100.0 )

    for job in range( 0 , len(portions)-1 ):
        cmd = command % {'from':portions[job] , 'to':portions[job+1] , 'sample':sample }
        LaunchOnCondor.SendCluster_Push(["BASH", cmd ] , global_job_counter)
        #print cmd
        global_job_counter += 1

print "in total %d jobs are created" % (global_job_counter)

LaunchOnCondor.SendCluster_Submit()



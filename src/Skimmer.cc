// includes++ C
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <sstream>
#include <cmath>

#include <stdexcept>

// ROOT includes
#include <TROOT.h>
#include <TTree.h>
#include <TChain.h>
#include "TFile.h"

#include "TH2D.h"

#include <climits>

#include "BaseMassPlotter.hh"
#include "SingleTopTree.h"
#include "DMTopVariables.h"
#include <cmath>

#include "TRandom.h"

using namespace std;


int main(int argc, char* argv[]) {
  TString input = TString( argv[1] );
  TString treeName = TString( argv[2] );
  TString output = TString( argv[3] );

  TChain chain( treeName );
  chain.Add( input , 0 );
  
  SingleTopTree fTree( &chain );

  TFile fOut ( output , "RECREATE" );
  TTree* newTree = chain.CloneTree(0); 

  string lastFileName = "";
  int counter = 0;
  Long64_t nentries =  chain.GetEntries();
  cout << nentries << endl;
  //return 0;

  for (Long64_t jentry=0; jentry<nentries;jentry++, counter++) {    

    chain.GetEntry(jentry);
    
    if( lastFileName.compare( chain.GetFile()->GetName() ) != 0 ) {
      lastFileName = chain.GetFile()->GetName() ;
      cout << "new file : " << lastFileName << endl;
    }
    
    if ( counter == 10000 ){  
      fprintf(stdout, "\rProcessed events: %6d of %6d ", jentry + 1, nentries);
      fflush(stdout);
      counter = 0;
    }

    int nTightMuons = 0;

    for( int imu=0 ; imu < fTree.muons_size ; imu++ ){
      if( fTree.muons_Pt[imu] > 20.0 &&
	  fabs(fTree.muons_Eta[imu]) < 2.1 &&
	  fTree.muons_IsTightMuon[imu] > 0.5 )
	nTightMuons ++;
    }
    
    if( nTightMuons == 0)
      continue ;

    
    //chain.SetBranchStatus("*", 1 );
    chain.GetEntry(jentry);

    newTree->Fill();
    
  }

  newTree->Print();
  newTree->AutoSave();
  fOut.Close();

}

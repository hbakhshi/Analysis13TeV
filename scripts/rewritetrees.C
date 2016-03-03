using namespace std;
void rewritetrees(){
  TString trees[] = {"iso2j1t" , "noniso2j1t" , "iso2j0t" , "noniso2j0t" , "iso3j2t" , "noniso3j2t" , "iso3j1t" , "noniso3j1t" };

  struct{
    float weight;
    float mtw;
    float met;
    bool data;
    bool qcd;
  } info;

  TFile* fout = TFile::Open("out.root" , "RECREATE");

  for( int i=0 ; i < 8 ; i++){
    cout << trees[i] << endl;
    TTree* tree = (TTree*)( _file0->Get("Trees/" + trees[i] ) );
    tree->SetBranchAddress( "info" , &info );

    tree->Print();

    TTree* tout = new TTree( tree->GetName() , tree->GetTitle() );
    tout->SetAutoSave( 10000 );
    tout->Branch( "weight" , &info.weight );
    tout->Branch( "mtw" , &info.mtw);
    tout->Branch( "met" , &info.met );
    tout->Branch( "data" , &info.data );
    tout->Branch( "qcd" , &info.qcd );

    for(int j = 0 ; j < tree->GetEntries() ; j++){
      tree->GetEntry(j);
      tout->Fill();
      //cout << i ;
    }
    
    
  }

  fout->Write();
  fout->Close();
}

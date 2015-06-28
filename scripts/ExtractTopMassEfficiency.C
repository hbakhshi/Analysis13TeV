void ExtractTopMassEfficiency(){

  gDirectory->ls();

  double top_mass = 175;

  //TH1* hTopMass =  ;
  double total = hTopMass->Integral();

  TH2* hEfficiency = new TH2D("hEfficiency" , "Efficiency;LowerCut;UpperCut" , 50 , top_mass-50 , top_mass , 50 , top_mass , top_mass+50 ); 

  double maxEff = -1;
  int maxLower,
    maxUpper;
  
  for( int lower=0; lower<50 ; lower++ )
    for( int upper = 0 ; upper<50 ; upper++ )
      {
	double Upper = top_mass+upper;
	double Lower = top_mass-lower;

	int binLower = hTopMass->FindBin( Lower );
	int binUpper = hTopMass->FindBin( Upper );

	double entries = hTopMass->Integral( Lower , Upper );
	
	int binId = hEfficiency->FindBin( Lower , Upper );
	double eff = entries/total;
	hEfficiency->SetBinContent( binId , eff );

	if( eff > maxEff ){
	  maxEff = eff;
	  maxLower = lower;
	  maxUpper = upper;
	}
      }
  
  hEfficiency->Draw("COLZ");

  cout << maxEff << " : " << top_mass - maxLower << "--" << top_mass + maxUpper << endl;
}

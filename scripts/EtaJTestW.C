void EtaJTestW(){

  gDirectory->ls();

  double top_mass = 175;

  int steps = 1;
  //TH1* hTopMass =  ;
  //double total = hTopMass->Integral();

  double maxTestVal = -1;
  int maxUpper , maxLower ;

  TH2* hTestVals = new TH2D("hTestVals" , "KolmogorovTest;LowerCut;UpperCut" , 50/steps , top_mass-50 , top_mass , 50/steps , top_mass , top_mass+50 ); 
  TH2* hNumberOfEvents = new TH2D("hNumberOfEvents" , "NumberOfWEvents(in-out);LowerCut;UpperCut" , 50/steps , top_mass-50 , top_mass , 50/steps , top_mass , top_mass+50 ); 

  for( int lower=0; lower<50 ; lower+=steps )
    for( int upper = 0 ; upper<50 ; upper+=steps )
      {
	double Upper = top_mass+upper;
	double Lower = top_mass-lower;

	int binLower = hTopMass->FindBin( Lower );
	int binUpper = hTopMass->FindBin( Upper );

	TH1* hBeforeCut = hTopMassEtaJ->ProjectionY( "_BeforeCut" , 0 , binLower );
	TH1* hInside = hTopMassEtaJ->ProjectionY( "_Inside" ,  binLower , binUpper );
	TH1* hAfterCut = hTopMassEtaJ->ProjectionY( "_AfterCut" ,  binUpper , -1 );

	hBeforeCut->Add( hAfterCut );

	int binId = hTestVals->FindBin( Lower , Upper );
	double testval = hBeforeCut->KolmogorovTest( hInside  );
	if( testval > maxTestVal ){
	  maxTestVal = testval ;
	  maxUpper = upper ;
	  maxLower = lower ;
	}

	hTestVals->SetBinContent( binId , testval );
	hNumberOfEvents->SetBinContent( binId , hInside->Integral() - hBeforeCut->Integral() );
      }
  

  double Upper = 225 ;// top_mass+maxUpper;
  double Lower = 130 ;// top_mass-maxLower;

  cout << Upper << endl;
  cout << Lower << endl;
  
  int binLower = hTopMass->FindBin( Lower );
  int binUpper = hTopMass->FindBin( Upper );
  
  TH1* hBeforeCut = hTopMassEtaJ->ProjectionY( "_BeforeCut" , 0 , binLower );
  TH1* hInside = hTopMassEtaJ->ProjectionY( "_Inside" ,  binLower , binUpper );
  TH1* hAfterCut = hTopMassEtaJ->ProjectionY( "_AfterCut" ,  binUpper , -1 );

  hBeforeCut->Add( hAfterCut );

  cout << hInside->Integral() << endl;
  cout << hBeforeCut->Integral() << endl;

  //hInside->DrawNormalized();
  //hBeforeCut->DrawNormalized("SAMES");

  cout << hBeforeCut->KolmogorovTest( hInside ) << endl;
  cout << hBeforeCut->KolmogorovTest( hInside , "N" ) << endl;
  //hTestVals->Draw("COLZ");
  hNumberOfEvents->Draw("COLZ");
}

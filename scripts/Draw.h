TGraphAsymmErrors* GetGraph(float* XVals, float* exp , float* p , float* m){
  float y[nPoints];
  float eyl[nPoints];
  float eyh[nPoints];	
  float exl[nPoints];
  float exh[nPoints];	
  for(int i = 0; i < nPoints; i++){
    exl[i] = 0;
    exh[i] = 0;
  }
	
  for(unsigned int iNumbers = 0; iNumbers < nPoints; iNumbers++){
    y[iNumbers] = exp[iNumbers];
    
    eyl[iNumbers] = fabs(m[iNumbers]-exp[iNumbers]);
    eyh[iNumbers] = fabs(p[iNumbers]-exp[iNumbers]);
  }
  return new TGraphAsymmErrors(nPoints,XVals ,y,exl,exh,eyl,eyh);
}
void DrawAll(float* Nevent,float* Observed, float* Expected , float* ExpectedM2 , float* ExpectedM1 , float* ExpectedP1 , float* ExpectedP2 , TString Title ){

  TGraph* twoSigmaBand = GetGraph( Nevent, Expected , ExpectedP2 , ExpectedM2 );
  twoSigmaBand->SetName("TwoSigmaBand");
  twoSigmaBand->SetTitle( Title );
  twoSigmaBand->SetFillColor(kGreen);
  twoSigmaBand->Draw("Ap3");

  twoSigmaBand->GetHistogram()->GetXaxis()->SetTitle("number of signal events");
  twoSigmaBand->GetHistogram()->GetYaxis()->SetTitle("r-value");

  TGraph* oneSigmaBand = GetGraph( Nevent, Expected , ExpectedP1 , ExpectedM1 );
  oneSigmaBand->SetName("OneSigmaBand");
  oneSigmaBand->SetFillColor(kYellow);
  oneSigmaBand->Draw("p3");
  TGraph *graphObserved = new TGraph(nPoints, Nevent, Observed);
  graphObserved->SetName("Obs");
  graphObserved->SetFillColor(1);
  graphObserved->SetLineColor(2);
  graphObserved->SetLineWidth(3);
  graphObserved->Draw("C");
  TGraph *graphExpected = new TGraph(nPoints, Nevent, Expected);
  graphExpected->SetName("Expected");
  graphExpected->SetFillColor(1);
  graphExpected->Draw("C");
  TLine* lOne = new TLine( twoSigmaBand->GetHistogram()->GetXaxis()->GetXmin() , 1.00 , 
			   twoSigmaBand->GetHistogram()->GetXaxis()->GetXmax() , 1.00 );
  lOne->SetLineWidth(1);
  lOne->SetLineStyle(7);
  lOne->Draw();

  TLegend *leg = new TLegend(0.5,0.67,0.88,0.88,NULL,"brNDC");
  leg->AddEntry(graphObserved,"Observed","l");
  leg->AddEntry(graphExpected,"Expected","l");
  leg->AddEntry(oneSigmaBand,"#pm 1 #sigma","f");
  leg->AddEntry(twoSigmaBand,"#pm 2 #sigma","f");
  leg->Draw();

}


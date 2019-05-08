#include "../interface/Analysis_mc.h"



//______________________________________________
double Analysis_mc::FR_weight(TGraphAsymmErrors *fakeRate_mu_sFR[3],
                              TGraphAsymmErrors *fakeRate_e_sFR[3],
			      TGraphAsymmErrors *fakeRate_mumu_dFR[3],
                              TGraphAsymmErrors *fakeRate_ee_dFR[3],
			      TGraphAsymmErrors *fakeRate_emu_dFR[3],
			      bool   isSFR,
			      bool   isDFR,
			      double etaLepton,
                              double flavorsLepton,
                              double ptLepton,
			      double etaJet,
                              double flavorsJet,
                              double ptJet
			      ) {
  double factor=0;

  
  if (isSFR && flavorsLepton == 0 )  factor =  sFR_factor_e  (*&fakeRate_e_sFR ,etaLepton, ptLepton);
  if (isSFR && flavorsLepton == 1 )  factor =  sFR_factor_mu (*&fakeRate_mu_sFR ,etaLepton, ptLepton);

  if (isDFR && flavorsJet == 0 )     factor =  dFR_factor_ee   (*&fakeRate_ee_dFR ,etaJet, ptJet);
  if (isDFR && flavorsJet == 1 )     factor =  dFR_factor_mumu (*&fakeRate_mumu_dFR ,etaJet, ptJet);
  if (isDFR && flavorsJet == 2 )     factor =  dFR_factor_emu  (*&fakeRate_emu_dFR ,etaJet, ptJet);

  return factor;
}


//==================================================================
double Analysis_mc::dFR_factor_ee(TGraphAsymmErrors *fakeRate_e[3],                             
				  int eta,
				  double lptcone
				  ){
    
  const int nBinMu=5;
  const int nBinMu3=4;
    
  Double_t newBins_e1[nBinMu+1] = {10,25,35,55,70, 100};
  Double_t newBins_e3[nBinMu3+1] ={10,30,50,70, 100};
   
  TH1D *fakeRate_e_histo[3]; 
  fakeRate_e_histo[0]= new TH1D("fake_rate_e_histo_eta1","",nBinMu,newBins_e1);
  fakeRate_e_histo[1]= new TH1D("fake_rate_e_histo_eta2","",nBinMu,newBins_e1);
  fakeRate_e_histo[2]= new TH1D("fake_rate_e_histo_eta3","",nBinMu3,newBins_e3);  
  for (int i=0; i< 3; i++){
    if (i ==0 || i ==1) from_TGraph_to_TH1D(*&fakeRate_e[i],*&fakeRate_e_histo[i],nBinMu);
    if (i ==2) from_TGraph_to_TH1D(*&fakeRate_e[i],*&fakeRate_e_histo[i],nBinMu3);
  }
 
  double momentum = lptcone;
  double factore=0;
  if (momentum < 100){
    if (eta == 1)  factore = fakeRate_e_histo[0]->GetBinContent(fakeRate_e_histo[0]->FindBin(momentum));
    if (eta == 2)  factore = fakeRate_e_histo[1]->GetBinContent(fakeRate_e_histo[1]->FindBin(momentum));
    if (eta == 3)  factore = fakeRate_e_histo[2]->GetBinContent(fakeRate_e_histo[2]->FindBin(momentum));
  }//eta1
  else {
    if (eta == 1)  factore = fakeRate_e_histo[0]->GetBinContent(fakeRate_e_histo[0]->FindBin(90));
    if (eta == 2)  factore = fakeRate_e_histo[1]->GetBinContent(fakeRate_e_histo[1]->FindBin(90));
    if (eta == 3)  factore = fakeRate_e_histo[2]->GetBinContent(fakeRate_e_histo[2]->FindBin(90));
  }  
  delete fakeRate_e_histo[0];
  delete fakeRate_e_histo[1];
  delete fakeRate_e_histo[2];    
  return factore;  
}

//==================================================================
double Analysis_mc::dFR_factor_emu(TGraphAsymmErrors *fakeRate_e[3],                             
				  int eta,
				  double lptcone
				  ){
    
  const int nBinMu=5;
  const int nBinMu3=4;
    
  Double_t newBins_e1[nBinMu+1] = {10,15,25,40,70, 100};
  Double_t newBins_e3[nBinMu3+1] = {10,20,40,70, 100};

  TH1D *fakeRate_e_histo[3]; 
  fakeRate_e_histo[0]= new TH1D("fake_rate_e_histo_eta1","",nBinMu,newBins_e1);
  fakeRate_e_histo[1]= new TH1D("fake_rate_e_histo_eta2","",nBinMu,newBins_e1);
  fakeRate_e_histo[2]= new TH1D("fake_rate_e_histo_eta3","",nBinMu3,newBins_e3);  
  for (int i=0; i< 3; i++){
    if (i ==0 || i ==1) from_TGraph_to_TH1D(*&fakeRate_e[i],*&fakeRate_e_histo[i],nBinMu);
    if (i ==2) from_TGraph_to_TH1D(*&fakeRate_e[i],*&fakeRate_e_histo[i],nBinMu3);
  }
 
  double momentum = lptcone;
  double factore=0;
  if (momentum < 100){
    if (eta == 1)  factore = fakeRate_e_histo[0]->GetBinContent(fakeRate_e_histo[0]->FindBin(momentum));
    if (eta == 2)  factore = fakeRate_e_histo[1]->GetBinContent(fakeRate_e_histo[1]->FindBin(momentum));
    if (eta == 3)  factore = fakeRate_e_histo[2]->GetBinContent(fakeRate_e_histo[2]->FindBin(momentum));
  }//eta1
  else {
    if (eta == 1)  factore = fakeRate_e_histo[0]->GetBinContent(fakeRate_e_histo[0]->FindBin(90));
    if (eta == 2)  factore = fakeRate_e_histo[1]->GetBinContent(fakeRate_e_histo[1]->FindBin(90));
    if (eta == 3)  factore = fakeRate_e_histo[2]->GetBinContent(fakeRate_e_histo[2]->FindBin(90));
  }  
  delete fakeRate_e_histo[0];
  delete fakeRate_e_histo[1];
  delete fakeRate_e_histo[2];    
  return factore;  
}

//==================================================================
double Analysis_mc::dFR_factor_mumu(TGraphAsymmErrors *fakeRate_e[3],                             
				  int eta,
				  double lptcone
				  ){
    
  const int nBinMu=5;
  const int nBinMu3=4;
  Double_t newBins_e1[nBinMu+1] = {10,15,25,40,70, 100};    
  TH1D *fakeRate_e_histo[3];  
  fakeRate_e_histo[0]= new TH1D("fake_rate_e_histo_eta1","",nBinMu,newBins_e1);
  fakeRate_e_histo[1]= new TH1D("fake_rate_e_histo_eta2","",nBinMu,newBins_e1);
  fakeRate_e_histo[2]= new TH1D("fake_rate_e_histo_eta3","",nBinMu,newBins_e1);  
  for (int i=0; i< 3; i++){
    from_TGraph_to_TH1D(*&fakeRate_e[i],*&fakeRate_e_histo[i],nBinMu);
  }
  
  double momentum = lptcone;
  double factore=0;
  if (momentum < 100){
    if (eta == 1)  factore = fakeRate_e_histo[0]->GetBinContent(fakeRate_e_histo[0]->FindBin(momentum));
    if (eta == 2)  factore = fakeRate_e_histo[1]->GetBinContent(fakeRate_e_histo[1]->FindBin(momentum));
    if (eta == 3)  factore = fakeRate_e_histo[2]->GetBinContent(fakeRate_e_histo[2]->FindBin(momentum));
  }//eta1
  else {
    if (eta == 1)  factore = fakeRate_e_histo[0]->GetBinContent(fakeRate_e_histo[0]->FindBin(90));
    if (eta == 2)  factore = fakeRate_e_histo[1]->GetBinContent(fakeRate_e_histo[1]->FindBin(90));
    if (eta == 3)  factore = fakeRate_e_histo[2]->GetBinContent(fakeRate_e_histo[2]->FindBin(90));
  }  
  delete fakeRate_e_histo[0];
  delete fakeRate_e_histo[1];
  delete fakeRate_e_histo[2];    
  return factore;  
}


//______________________________________________
double Analysis_mc::sFR_factor_e (TGraphAsymmErrors *fakeRate[3],                             
				  double eta,                          
				  double lptcone
				  ){
  eta = fabs(eta);
  TH1D *fakeRate_histo[3];
  Double_t newBins[6] = {10, 15, 25, 35, 50, 70};
  fakeRate_histo[0]= new TH1D("fake_rate_e_histo_eta1","",5,newBins);
  fakeRate_histo[1]= new TH1D("fake_rate_e_histo_eta2","",5,newBins);
  fakeRate_histo[2]= new TH1D("fake_rate_e_histo_eta3","",5,newBins);
  for (int i=0; i< 3; i++){
    from_TGraph_to_TH1D(*&fakeRate[i],*&fakeRate_histo[i],5);
  }
  double momentum = lptcone;
  double factore=0;
  if (momentum < 70){
    if (eta < 0.8){
      factore = fakeRate_histo[0]->GetBinContent(fakeRate_histo[0]->FindBin(momentum));
    }//eta1
    else if (eta > 0.8 && eta<1.479){
      factore = fakeRate_histo[1]->GetBinContent(fakeRate_histo[1]->FindBin(momentum));
    }//eta1
    else {
      factore = fakeRate_histo[2]->GetBinContent(fakeRate_histo[2]->FindBin(momentum));
    }//eta1
  }// <70
  else {
    if (eta < 0.8){
      factore = fakeRate_histo[0]->GetBinContent(fakeRate_histo[0]->FindBin(68));
    }//eta1
    else if (eta > 0.8 && eta<1.479){
      factore = fakeRate_histo[1]->GetBinContent(fakeRate_histo[1]->FindBin(68));
    }//eta1
    else {
      factore = fakeRate_histo[2]->GetBinContent(fakeRate_histo[2]->FindBin(68));
    }//eta1
  }
 
  delete fakeRate_histo[0];
  delete fakeRate_histo[1];
  delete fakeRate_histo[2];
  return factore;
}


//______________________________________________
double Analysis_mc::sFR_factor_mu (TGraphAsymmErrors *fakeRate[3],                             
				  double eta,                          
				  double lptcone
				  ){
  eta = fabs(eta);
  TH1D *fakeRate_histo[3];
  Double_t newBins[7] = {5,10, 15, 25, 35, 50, 70};
  fakeRate_histo[0]= new TH1D("fake_rate_e_histo_eta1","",6,newBins);
  fakeRate_histo[1]= new TH1D("fake_rate_e_histo_eta2","",6,newBins);
  fakeRate_histo[2]= new TH1D("fake_rate_e_histo_eta3","",6,newBins);
  for (int i=0; i< 3; i++){
    from_TGraph_to_TH1D(*&fakeRate[i],*&fakeRate_histo[i],6);
  }
  double momentum = lptcone;
  double factore=0;
  if (momentum < 70){
    if (eta < 0.8){
      factore = fakeRate_histo[0]->GetBinContent(fakeRate_histo[0]->FindBin(momentum));
    }//eta1
    else if (eta > 0.8 && eta<1.479){
      factore = fakeRate_histo[1]->GetBinContent(fakeRate_histo[1]->FindBin(momentum));
    }//eta1
    else {
      factore = fakeRate_histo[2]->GetBinContent(fakeRate_histo[2]->FindBin(momentum));
    }//eta1
  }// <70
  else {
    if (eta < 0.8){
      factore = fakeRate_histo[0]->GetBinContent(fakeRate_histo[0]->FindBin(68));
    }//eta1
    else if (eta > 0.8 && eta<1.479){
      factore = fakeRate_histo[1]->GetBinContent(fakeRate_histo[1]->FindBin(68));
    }//eta1
    else {
      factore = fakeRate_histo[2]->GetBinContent(fakeRate_histo[2]->FindBin(68));
    }//eta1
  }
 
  delete fakeRate_histo[0];
  delete fakeRate_histo[1];
  delete fakeRate_histo[2];
  return factore;
}






//___________________________________________________________________

void Analysis_mc::from_TGraph_to_TH1D (TGraphAsymmErrors *graph, TH1D *histo, int number_point){
    
  const int numero= number_point;
    
  double x_graph[numero];
  double y_graph[numero];
  for (int i =0; i <number_point; i ++){
    x_graph[i]=0;
    y_graph[i]=0;
  }
  for (int i =0; i <number_point; i ++){
    graph -> GetPoint(i, x_graph[i], y_graph[i]);
    histo->SetBinContent (i+1, x_graph[i],  y_graph[i]);        
  }
}

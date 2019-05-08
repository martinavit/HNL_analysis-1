#ifndef ANALYSIS_MC_H
#define ANALYSIS_MC_H
#include "TObject.h"

#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include "TH1.h"
#include "TH2.h"
#include "TTree.h"
#include "TBranch.h"
#include "TLorentzVector.h"
#include "TLorentzRotation.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TPad.h"
#include "TF1.h"
#include "TF2.h"
#include "TStyle.h"
#include "TLine.h"
#include "TProfile.h"
#include "TAttFill.h"
#include "TGraphErrors.h"
#include "Riostream.h"
#include "TFile.h"
#include "TChain.h"
#include "TClonesArray.h"
#include "TLegendEntry.h"
#include "TGraphAsymmErrors.h"
#include "THStack.h"

//include other parts of the code
#include "Sample.h"



class Analysis_mc : public TObject {
    
 public:

  //Declare leaf types
  static const unsigned nL_max = 100;
  static const unsigned nJets_max = 100;
  static const unsigned gen_nL_max = 100;
  static const unsigned gen_nPh_max = 100;
  ULong64_t       _runNb;
  ULong64_t       _lumiBlock;
  ULong64_t       _eventNb;
  UChar_t         _nVertex;
  Float_t         _nTrueInt;
  Double_t        _weight;
  Double_t        _lheHTIncoming;
  Double_t        _ctauHN;
  UInt_t          _nLheTau;
  UInt_t          _nLheWeights;
  Double_t        _lheWeight[110];   //[_nLheWeights]
  UInt_t          _nPsWeights;
  Double_t        _psWeight[14];   //[_nPsWeights]
  UInt_t          _ttgEventType;
  UInt_t          _zgEventType;
  Double_t        _gen_met;
  Double_t        _gen_metPhi;
  UInt_t          _gen_nPh;
  UInt_t          _gen_phStatus[gen_nL_max];  //[_gen_nPh]
  Double_t        _gen_phPt[gen_nL_max];  //[_gen_nPh]
  Double_t        _gen_phEta[gen_nL_max];  //[_gen_nPh]
  Double_t        _gen_phPhi[gen_nL_max];  //[_gen_nPh]
  Double_t        _gen_phE[gen_nL_max];  //[_gen_nPh]
  Int_t           _gen_phMomPdg[gen_nL_max];  //[_gen_nPh]
  Bool_t          _gen_phIsPrompt[gen_nL_max];  //[_gen_nPh]
  Double_t        _gen_phMinDeltaR[gen_nL_max];  //[_gen_nPh]
  Bool_t          _gen_phPassParentage[gen_nL_max];  //[_gen_nPh]
  UInt_t          _gen_nL;
  Double_t        _gen_pdgID[gen_nL_max];  //[_gen_nL]
  Double_t        _gen_lPt[gen_nL_max];  //[_gen_nL]
  Double_t        _gen_lEta[gen_nL_max];  //[_gen_nL]
  Double_t        _gen_lPhi[gen_nL_max];  //[_gen_nL]
  Double_t        _gen_lE[gen_nL_max];  //[_gen_nL]
  UInt_t          _gen_lFlavor[gen_nL_max];  //[_gen_nL]
  Int_t           _gen_lCharge[gen_nL_max];  //[_gen_nL]
  Int_t           _gen_lMomPdg[gen_nL_max];  //[_gen_nL]
  Double_t        _gen_vertex_x[gen_nL_max];  //[_gen_nL]
  Double_t        _gen_vertex_y[gen_nL_max];  //[_gen_nL]
  Double_t        _gen_vertex_z[gen_nL_max];  //[_gen_nL]
  Bool_t          _gen_lIsPrompt[gen_nL_max];  //[_gen_nL]
  Double_t        _gen_lMinDeltaR[gen_nL_max];  //[_gen_nL]
  Bool_t          _gen_lPassParentage[gen_nL_max];  //[_gen_nL]
  Bool_t          _passMETFilters;
  Bool_t          _Flag_goodVertices;
  Bool_t          _Flag_HBHENoiseFilter;
  Bool_t          _Flag_HBHENoiseIsoFilter;
  Bool_t          _Flag_EcalDeadCellTriggerPrimitiveFilter;
  Bool_t          _Flag_BadPFMuonFilter;
  Bool_t          _Flag_BadChargedCandidateFilter;
  Bool_t          _updated_ecalBadCalibFilter;
  
  Bool_t          _passTrigger_1l;
  Bool_t          _HLT_Ele27_WPTight_Gsf;
  Bool_t          _HLT_IsoMu27;
  Bool_t          _HLT_IsoMu24;
  Bool_t          _HLT_IsoTkMu24;   
  Bool_t          _HLT_Ele32_WPTight_Gsf;
  Bool_t          _HLT_Ele35_WPTight_Gsf;
  Bool_t          _HLT_Ele32_WPTight_Gsf_L1DoubleEG;
  UInt_t          _nL;
  UInt_t          _nMu;
  UInt_t          _nEle;
  UInt_t          _nLight;
  UInt_t          _nTau;
  Double_t        _pvX;
  Double_t        _pvY;
  Double_t        _pvZ;
  Double_t        _pvXErr;
  Double_t        _pvYErr;
  Double_t        _pvZErr;
  UInt_t          _nVFit_os;
  UInt_t          _nVFit;
  UInt_t          _nGoodLeading;
  UInt_t          _nGoodDisplaced;
  Double_t        _vertices_os[50][12];   //[_nVFit_os]
  Double_t        _lDisplaced_os[50][24];  //[_nVFit_os]
  Double_t        _vertices[50][12];   //[_nVFit]
  Double_t        _lDisplaced[50][24];  //[_nVFit]
  UInt_t          _lHasTrigger[nL_max];  //[_nL]
  Double_t        _lPt[nL_max];  //[_nL]
  Double_t        _lEta[nL_max];  //[_nL]
  Double_t        _lEtaSC[nL_max];  //[_nLight]
  Double_t        _lPhi[nL_max];  //[_nL]
  Double_t        _lE[nL_max];  //[_nL]
  UInt_t          _lFlavor[nL_max];  //[_nL]
  Int_t           _lCharge[nL_max];  //[_nL]
  Double_t        _dxy[nL_max];  //[_nL]
  Double_t        _dz[nL_max];  //[_nL]
  Double_t        _3dIP[nL_max];  //[_nL]
  Double_t        _3dIPSig[nL_max];  //[_nL]
  Double_t        _2dIP[nL_max];  //[_nL]
  Double_t        _2dIPSig[nL_max];  //[_nL]
  Bool_t          _lElectronPassEmu[nL_max];  //[_nLight]
  Bool_t          _lLooseCBwoIsolationwoMissingInnerhitswoConversionVeto[nL_max];  //[_nL]
  Bool_t          _lElectronPassConvVeto[nL_max];  //[_nLight]
  Bool_t          _lElectronChargeConst[nL_max];  //[_nLight]
  UInt_t          _lElectronMissingHits[nL_max];  //[_nLight]
  Bool_t          _lPOGVeto[nL_max];  //[_nL]
  Bool_t          _lPOGLoose[nL_max];  //[_nL]
  Bool_t          _lPOGMedium[nL_max];  //[_nL]
  Bool_t          _lPOGTight[nL_max];  //[_nL]
  Bool_t          _lGlobalMuon[nL_max];  //[_nMu]
  Bool_t          _lTrackerMuon[nL_max];  //[_nMu]
  Double_t        _lInnerTrackValidFraction[nL_max];  //[_nMu]
  Double_t        _lGlobalTrackNormalizeChi2[nL_max];  //[_nMu]
  Double_t        _lCQChi2Position[nL_max];  //[_nMu]
  Double_t        _lCQTrackKink[nL_max];  //[_nMu]
  UInt_t          _lNumberOfMatchedStation[nL_max];  //[_nMu]
  UInt_t          _lNumberOfValidPixelHits[nL_max];  //[_nMu]
  UInt_t          _lTrackerLayersWithMeasurement[nL_max];  //[_nMu]
  Int_t           _lSimType[nL_max];  //[_nMu]
  Int_t           _lSimExtType[nL_max];  //[_nMu]
  Int_t           _lSimFlavour[nL_max];  //[_nMu]
  Int_t           _muDTStationsWithValidHits[nL_max];  //[_nMu]
  Int_t           _muCSCStationsWithValidHits[nL_max];  //[_nMu]
  Int_t           _muRPCStationsWithValidHits[nL_max];  //[_nMu]
  Int_t           _muMuonStationsWithValidHits[nL_max];  //[_nMu]
  Int_t           _lMuRPCTimenDof[nL_max];  //[_nMu]
  Int_t           _lMuTimenDof[nL_max];  //[_nMu]
  Double_t        _lMuRPCTime[nL_max];  //[_nMu]
  Double_t        _lMuRPCTimeErr[nL_max];  //[_nMu]
  Double_t        _lMuTime[nL_max];  //[_nMu]
  Double_t        _lMuTimeErr[nL_max];  //[_nMu]
  UInt_t          _muNumberInnerHits[nL_max];  //[_nMu]
  Bool_t          _lEleIsEB[nL_max];  //[_nLight]
  Bool_t          _lEleIsEE[nL_max];  //[_nLight]
  Double_t        _lEleSuperClusterOverP[nL_max];  //[_nLight]
  Double_t        _lEleEcalEnergy[nL_max];  //[_nLight]
  Double_t        _lElefull5x5SigmaIetaIeta[nL_max];  //[_nLight]
  Double_t        _lEleDEtaInSeed[nL_max];  //[_nLight]
  Double_t        _lEleDeltaPhiSuperClusterTrackAtVtx[nL_max];  //[_nLight]
  Double_t        _lElehadronicOverEm[nL_max];  //[_nLight]
  Double_t        _lEleInvMinusPInv[nL_max];  //[_nLight]
  Double_t        _puCorr[nL_max];  //[_nLight]
  Double_t        _absIso03[nL_max];  //[_nL]
  Double_t        _absIso04[nL_max];  //[_nMu]
  Double_t        _sumNeutralHadronEt04[nL_max];  //[_nMu]
  Double_t        _sumChargedHadronPt04[nL_max];  //[_nMu]
  Double_t        _sumPhotonEt04[nL_max];  //[_nMu]
  Double_t        _sumNeutralHadronEt03[nL_max];  //[_nLight]
  Double_t        _sumChargedHadronPt03[nL_max];  //[_nLight]
  Double_t        _sumPhotonEt03[nL_max];  //[_nLight]
  Double_t        _trackIso[nL_max];  //[_nLight]
  Double_t        _ecalIso[nL_max];  //[_nLight]
  Double_t        _hcalIso[nL_max];  //[_nLight]
  Double_t        _ecalPFClusterIso[nL_max];  //[_nLight]
  Double_t        _hcalPFClusterIso[nL_max];  //[_nLight]
  Bool_t          _tauMuonVeto[nL_max];  //[_nL]
  Bool_t          _tauEleVeto[nL_max];  //[_nL]
  Bool_t          _decayModeFindingNew[nL_max];  //[_nL]
  Bool_t          _tauVLooseMvaNew[nL_max];  //[_nL]
  Bool_t          _tauLooseMvaNew[nL_max];  //[_nL]
  Bool_t          _tauMediumMvaNew[nL_max];  //[_nL]
  Bool_t          _tauTightMvaNew[nL_max];  //[_nL]
  Bool_t          _tauVTightMvaNew[nL_max];  //[_nL]
  Bool_t          _tauVTightMvaOld[nL_max];  //[_nL]
  Double_t        _tauAgainstElectronMVA6Raw[nL_max];  //[_nL]
  Double_t        _tauCombinedIsoDBRaw3Hits[nL_max];  //[_nL]
  Double_t        _tauIsoMVAPWdR03oldDMwLT[nL_max];  //[_nL]
  Double_t        _tauIsoMVADBdR03oldDMwLT[nL_max];  //[_nL]
  Double_t        _tauIsoMVADBdR03newDMwLT[nL_max];  //[_nL]
  Double_t        _tauIsoMVAPWnewDMwLT[nL_max];  //[_nL]
  Double_t        _tauIsoMVAPWoldDMwLT[nL_max];  //[_nL]
  Double_t        _relIso[nL_max];  //[_nLight]
  Double_t        _relIso0p4[nL_max];  //[_nLight]
  Double_t        _relIso0p4MuDeltaBeta[nL_max];  //[_nMu]
  Double_t        _miniIso[nL_max];  //[_nLight]
  Double_t        _miniIsoCharged[nL_max];  //[_nLight]
  Double_t        _ptRel[nL_max];  //[_nLight]
  Double_t        _ptRatio[nL_max];  //[_nLight]
  Double_t        _closestJetCsvV2[nL_max];  //[_nLight]
  Double_t        _closestJetDeepCsv_b[nL_max];  //[_nLight]
  Double_t        _closestJEC[nL_max];  //[_nLight]
  Double_t        _closest_lepAwareJetE[nL_max];  //[_nLight]
  Double_t        _closest_lepAwareJetPx[nL_max];  //[_nLight]
  Double_t        _closest_lepAwareJetPy[nL_max];  //[_nLight]
  Double_t        _closest_lepAwareJetPz[nL_max];  //[_nLight]
  Double_t        _closest_l1JetE[nL_max];  //[_nLight]
  Double_t        _closest_l1JetPx[nL_max];  //[_nLight]
  Double_t        _closest_l1JetPy[nL_max];  //[_nLight]
  Double_t        _closest_l1JetPz[nL_max];  //[_nLight]
  Double_t        _closest_lJetE[nL_max];  //[_nLight]
  Double_t        _closest_lJetPx[nL_max];  //[_nLight]
  Double_t        _closest_lJetPy[nL_max];  //[_nLight]
  Double_t        _closest_lJetPz[nL_max];  //[_nLight]
  Double_t        _closestJetDeepCsv_bb[nL_max];  //[_nLight]
  Float_t         _lElectronSummer16MvaGP[nL_max];                                                           // OLD
  Float_t         _lElectronSummer16MvaHZZ[nL_max];                                                          // OLD
  Float_t         _lElectronMvaFall17v1NoIso[nL_max];                                                        // OLD
  Float_t         _lElectronMvaFall17Iso[nL_max];
  Float_t         _lElectronMvaFall17NoIso[nL_max];        
  UInt_t          _selectedTrackMult[nL_max];  //[_nLight]
  Double_t        _lMuonSegComp[nL_max];  //[_nMu]
  Double_t        _lMuonTrackPt[nL_max];  //[_nMu]
  Double_t        _lMuonTrackPtErr[nL_max];  //[_nMu]
  UInt_t          _lGenIndex[nL_max];  //[_nL]
  UInt_t          _lMatchType[nL_max];  //[_nL]
  Bool_t          _lIsPrompt[nL_max];  //[_nL]
  Bool_t          _lIsPromptFinalState[nL_max];  //[_nL]
  Bool_t          _lIsPromptDecayed[nL_max];  //[_nL]
  Int_t           _lMatchPdgId[nL_max];  //[_nL]
  Int_t           _lMomPdgId[nL_max];  //[_nL]
  UInt_t          _lProvenance[nL_max];  //[_nL]
  UInt_t          _lProvenanceCompressed[nL_max];  //[_nL]
  UInt_t          _lProvenanceConversion[nL_max];  //[_nL]
  Double_t        _lMatchPt[nL_max];  //[_nL]
  Double_t        _lMatchEta[nL_max];  //[_nL]
  Double_t        _lMatchPhi[nL_max];  //[_nL]
  Double_t        _lMatchVertexX[nL_max];  //[_nL]
  Double_t        _lMatchVertexY[nL_max];  //[_nL]
  Double_t        _lMatchVertexZ[nL_max];  //[_nL]
  Double_t        _lPtCorr[nL_max];  //[_nLight]
  Double_t        _lPtScaleUp[nL_max];  //[_nLight]
  Double_t        _lPtScaleDown[nL_max];  //[_nLight]
  Double_t        _lPtResUp[nL_max];  //[_nLight]
  Double_t        _lPtResDown[nL_max];  //[_nLight]
  Double_t        _lECorr[nL_max];  //[_nLight]
  Double_t        _lEScaleUp[nL_max];  //[_nLight]
  Double_t        _lEScaleDown[nL_max];  //[_nLight]
  Double_t        _lEResUp[nL_max];  //[_nLight]
  Double_t        _lEResDown[nL_max];  //[_nLight]
  UInt_t          _nPh;
  Double_t        _phPt[gen_nL_max];  //[_nPh]
  Double_t        _phEta[gen_nL_max];  //[_nPh]
  Double_t        _phEtaSC[gen_nL_max];  //[_nPh]
  Double_t        _phPhi[gen_nL_max];  //[_nPh]
  Double_t        _phE[gen_nL_max];  //[_nPh]
  Bool_t          _phCutBasedLoose[gen_nL_max];  //[_nPh]
  Bool_t          _phCutBasedMedium[gen_nL_max];  //[_nPh]
  Bool_t          _phCutBasedTight[gen_nL_max];  //[_nPh]
  Double_t        _phMva[gen_nL_max];  //[_nPh]
  Double_t        _phRandomConeChargedIsolation[gen_nL_max];  //[_nPh]
  Double_t        _phChargedIsolation[gen_nL_max];  //[_nPh]
  Double_t        _phNeutralHadronIsolation[gen_nL_max];  //[_nPh]
  Double_t        _phPhotonIsolation[gen_nL_max];  //[_nPh]
  Double_t        _phSigmaIetaIeta[gen_nL_max];  //[_nPh]
  Double_t        _phHadronicOverEm[gen_nL_max];  //[_nPh]
  Bool_t          _phPassElectronVeto[gen_nL_max];  //[_nPh]
  Bool_t          _phHasPixelSeed[gen_nL_max];  //[_nPh]
  Bool_t          _phIsPrompt[gen_nL_max];  //[_nPh]
  Int_t           _phTTGMatchCategory[gen_nL_max];  //[_nPh]
  Double_t        _phTTGMatchPt[gen_nL_max];  //[_nPh]
  Double_t        _phTTGMatchEta[gen_nL_max];  //[_nPh]
  Int_t           _phMatchPdgId[gen_nL_max];  //[_nPh]
  Double_t        _phPtCorr[gen_nL_max];  //[_nPh]
  Double_t        _phPtScaleUp[gen_nL_max];  //[_nPh]
  Double_t        _phPtScaleDown[gen_nL_max];  //[_nPh]
  Double_t        _phPtResUp[gen_nL_max];  //[_nPh]
  Double_t        _phPtResDown[gen_nL_max];  //[_nPh]
  Double_t        _phECorr[gen_nL_max];  //[_nPh]
  Double_t        _phEScaleUp[gen_nL_max];  //[_nPh]
  Double_t        _phEScaleDown[gen_nL_max];  //[_nPh]
  Double_t        _phEResUp[gen_nL_max];  //[_nPh]
  Double_t        _phEResDown[gen_nL_max];  //[_nPh]
  UInt_t          _nJets;
  Double_t        _jetPt[nJets_max];  //[_nJets]
  Double_t        _jetPt_JECDown[nJets_max];  //[_nJets]
  Double_t        _jetPt_JECUp[nJets_max];  //[_nJets]
  Double_t        _jetSmearedPt[nJets_max];  //[_nJets]
  Double_t        _jetSmearedPt_JECDown[nJets_max];  //[_nJets]
  Double_t        _jetSmearedPt_JECUp[nJets_max];  //[_nJets]
  Double_t        _jetSmearedPt_JERDown[nJets_max];  //[_nJets]
  Double_t        _jetSmearedPt_JERUp[nJets_max];  //[_nJets]
  Double_t        _jetPt_Uncorrected[nJets_max];  //[_nJets]
  Double_t        _jetPt_L1[nJets_max];  //[_nJets]
  Double_t        _jetPt_L2[nJets_max];  //[_nJets]
  Double_t        _jetPt_L3[nJets_max];  //[_nJets]
  Double_t        _jetEta[nJets_max];  //[_nJets]
  Double_t        _jetPhi[nJets_max];  //[_nJets]
  Double_t        _jetE[nJets_max];  //[_nJets]
  Double_t        _jetCsvV2[nJets_max];  //[_nJets]
  Double_t        _jetDeepCsv_udsg[nJets_max];  //[_nJets]
  Double_t        _jetDeepCsv_b[nJets_max];  //[_nJets]
  Double_t        _jetDeepCsv_c[nJets_max];  //[_nJets]
  Double_t        _jetDeepCsv_bb[nJets_max];  //[_nJets]
  UInt_t          _jetHadronFlavor[nJets_max];  //[_nJets]
  Bool_t          _jetIsLoose[nJets_max];  //[_nJets]
  Bool_t          _jetIsTight[nJets_max];  //[_nJets]
  Bool_t          _jetIsTightLepVeto[nJets_max];  //[_nJets]
  Double_t        _jetNeutralHadronFraction[nJets_max];  //[_nJets]
  Double_t        _jetChargedHadronFraction[nJets_max];  //[_nJets]
  Double_t        _jetNeutralEmFraction[nJets_max];  //[_nJets]
  Double_t        _jetChargedEmFraction[nJets_max];  //[_nJets]
  Double_t        _jetHFHadronFraction[nJets_max];  //[_nJets]
  Double_t        _jetHFEmFraction[nJets_max];  //[_nJets]
  Double_t        _met;
  Double_t        _metRaw;
  Double_t        _metJECDown;
  Double_t        _metJECUp;
  Double_t        _metUnclDown;
  Double_t        _metUnclUp;
  Double_t        _metPhi;
  Double_t        _metRawPhi;
  Double_t        _metPhiJECDown;
  Double_t        _metPhiJECUp;
  Double_t        _metPhiUnclDown;
  Double_t        _metPhiUnclUp;
  Double_t        _metSignificance;



   //list of branches
   TBranch        *b__runNb;   //!
   TBranch        *b__lumiBlock;   //!
   TBranch        *b__eventNb;   //!
   TBranch        *b__nVertex;   //!
   TBranch        *b__nTrueInt;   //!
   TBranch        *b__weight;   //!
   TBranch        *b__lheHTIncoming;   //!
   TBranch        *b__ctauHN;   //!
   TBranch        *b__nLheTau;   //!
   TBranch        *b__nLheWeights;   //!
   TBranch        *b__lheWeight;   //!
   TBranch        *b__nPsWeights;   //!
   TBranch        *b__psWeight;   //!
   TBranch        *b__ttgEventType;   //!
   TBranch        *b__zgEventType;   //!
   TBranch        *b__gen_met;   //!
   TBranch        *b__gen_metPhi;   //!
   TBranch        *b__gen_nPh;   //!
   TBranch        *b__gen_phStatus;   //!
   TBranch        *b__gen_phPt;   //!
   TBranch        *b__gen_phEta;   //!
   TBranch        *b__gen_phPhi;   //!
   TBranch        *b__gen_phE;   //!
   TBranch        *b__gen_phMomPdg;   //!
   TBranch        *b__gen_phIsPrompt;   //!
   TBranch        *b__gen_phMinDeltaR;   //!
   TBranch        *b__gen_phPassParentage;   //!
   TBranch        *b__gen_nL;   //!
   TBranch        *b__gen_pdgID;   //!
   TBranch        *b__gen_lPt;   //!
   TBranch        *b__gen_lEta;   //!
   TBranch        *b__gen_lPhi;   //!
   TBranch        *b__gen_lE;   //!
   TBranch        *b__gen_lFlavor;   //!
   TBranch        *b__gen_lCharge;   //!
   TBranch        *b__gen_lMomPdg;   //!
   TBranch        *b__gen_vertex_x;   //!
   TBranch        *b__gen_vertex_y;   //!
   TBranch        *b__gen_vertex_z;   //!
   TBranch        *b__gen_lIsPrompt;   //!
   TBranch        *b__gen_lMinDeltaR;   //!
   TBranch        *b__gen_lPassParentage;   //!
   TBranch        *b__passMETFilters;   //!
   TBranch        *b__Flag_goodVertices;   //!
   TBranch        *b__Flag_HBHENoiseFilter;   //!
   TBranch        *b__Flag_HBHENoiseIsoFilter;   //!
   TBranch        *b__Flag_EcalDeadCellTriggerPrimitiveFilter;   //!
   TBranch        *b__Flag_BadPFMuonFilter;   //!
   TBranch        *b__Flag_BadChargedCandidateFilter;   //!
   TBranch        *b__updated_ecalBadCalibFilter;   //!
    
    TBranch     *b__FR_single_lepton;
    TBranch     *b__HLT_Mu8;
    TBranch     *b__HLT_Mu17;
    TBranch     *b__HLT_Mu3_PFJet40;
    TBranch     *b__HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30;
    TBranch     *b__HLT_Ele8_CaloIdM_TrackIdM_PFJet30;
    
    
   TBranch        *b__passTrigger_1l;   //!
   TBranch        *b__HLT_Ele27_WPTight_Gsf;   //!
   TBranch        *b__HLT_IsoMu27;   //!
   TBranch        *b__HLT_IsoMu24;   //!
   TBranch        *b__HLT_IsoTkMu24;   //!
   TBranch        *b__HLT_Ele32_WPTight_Gsf;   //!
   TBranch        *b__HLT_Ele32_WPTight_Gsf_L1DoubleEG;   //!
   TBranch        *b__HLT_Ele35_WPTight_Gsf;   //!
   TBranch        *b__nL;   //!
   TBranch        *b__nMu;   //!
   TBranch        *b__nEle;   //!
   TBranch        *b__nLight;   //!
   TBranch        *b__nTau;   //!
   TBranch        *b__pvX;   //!
   TBranch        *b__pvY;   //!
   TBranch        *b__pvZ;   //!
   TBranch        *b__pvXErr;   //!
   TBranch        *b__pvYErr;   //!
   TBranch        *b__pvZErr;   //!
   TBranch        *b__nVFit_os;   //!
   TBranch        *b__nVFit;   //!
   TBranch        *b__nGoodLeading;   //!
   TBranch        *b__nGoodDisplaced;   //!
   TBranch        *b__vertices_os;   //!
   TBranch        *b__lDisplaced_os;   //!
   TBranch        *b__vertices;   //!
   TBranch        *b__lDisplaced;   //!
   TBranch        *b__lHasTrigger;   //!
   TBranch        *b__lPt;   //!
   TBranch        *b__lEta;   //!
   TBranch        *b__lEtaSC;   //!
   TBranch        *b__lPhi;   //!
   TBranch        *b__lE;   //!
   TBranch        *b__lFlavor;   //!
   TBranch        *b__lCharge;   //!
   TBranch        *b__dxy;   //!
   TBranch        *b__dz;   //!
   TBranch        *b__3dIP;   //!
   TBranch        *b__3dIPSig;   //!
   TBranch        *b__2dIP;   //!
   TBranch        *b__2dIPSig;   //!
   TBranch        *b__lElectronPassEmu;   //!
   TBranch        *b__lLooseCBwoIsolationwoMissingInnerhitswoConversionVeto;   //!
   TBranch        *b__lElectronPassConvVeto;   //!
   TBranch        *b__lElectronChargeConst;   //!
   TBranch        *b__lElectronMissingHits;   //!
   TBranch        *b__lPOGVeto;   //!
   TBranch        *b__lPOGLoose;   //!
   TBranch        *b__lPOGMedium;   //!
   TBranch        *b__lPOGTight;   //!
   TBranch        *b__lGlobalMuon;   //!
   TBranch        *b__lTrackerMuon;   //!
   TBranch        *b__lInnerTrackValidFraction;   //!
   TBranch        *b__lGlobalTrackNormalizeChi2;   //!
   TBranch        *b__lCQChi2Position;   //!
   TBranch        *b__lCQTrackKink;   //!
   TBranch        *b__lNumberOfMatchedStation;   //!
   TBranch        *b__lNumberOfValidPixelHits;   //!
   TBranch        *b__lTrackerLayersWithMeasurement;   //!
   TBranch        *b__lSimType;   //!
   TBranch        *b__lSimExtType;   //!
   TBranch        *b__lSimFlavour;   //!
   TBranch        *b__muDTStationsWithValidHits;   //!
   TBranch        *b__muCSCStationsWithValidHits;   //!
   TBranch        *b__muRPCStationsWithValidHits;   //!
   TBranch        *b__muMuonStationsWithValidHits;   //!
   TBranch        *b__lMuRPCTimenDof;   //!
   TBranch        *b__lMuTimenDof;   //!
   TBranch        *b__lMuRPCTime;   //!
   TBranch        *b__lMuRPCTimeErr;   //!
   TBranch        *b__lMuTime;   //!
   TBranch        *b__lMuTimeErr;   //!
   TBranch        *b__muNumberInnerHits;   //!
   TBranch        *b__lEleIsEB;   //!
   TBranch        *b__lEleIsEE;   //!
   TBranch        *b__lEleSuperClusterOverP;   //!
   TBranch        *b__lEleEcalEnergy;   //!
   TBranch        *b__lElefull5x5SigmaIetaIeta;   //!
   TBranch        *b__lEleDEtaInSeed;   //!
   TBranch        *b__lEleDeltaPhiSuperClusterTrackAtVtx;   //!
   TBranch        *b__lElehadronicOverEm;   //!
   TBranch        *b__lEleInvMinusPInv;   //!
   TBranch        *b__puCorr;   //!
   TBranch        *b__absIso03;   //!
   TBranch        *b__absIso04;   //!
   TBranch        *b__sumNeutralHadronEt04;   //!
   TBranch        *b__sumChargedHadronPt04;   //!
   TBranch        *b__sumPhotonEt04;   //!
   TBranch        *b__sumNeutralHadronEt03;   //!
   TBranch        *b__sumChargedHadronPt03;   //!
   TBranch        *b__sumPhotonEt03;   //!
   TBranch        *b__trackIso;   //!
   TBranch        *b__ecalIso;   //!
   TBranch        *b__hcalIso;   //!
   TBranch        *b__ecalPFClusterIso;   //!
   TBranch        *b__hcalPFClusterIso;   //!
   TBranch        *b__tauMuonVeto;   //!
   TBranch        *b__tauEleVeto;   //!
   TBranch        *b__decayModeFindingNew;   //!
   TBranch        *b__tauVLooseMvaNew;   //!
   TBranch        *b__tauLooseMvaNew;   //!
   TBranch        *b__tauMediumMvaNew;   //!
   TBranch        *b__tauTightMvaNew;   //!
   TBranch        *b__tauVTightMvaNew;   //!
   TBranch        *b__tauVTightMvaOld;   //!
   TBranch        *b__tauAgainstElectronMVA6Raw;   //!
   TBranch        *b__tauCombinedIsoDBRaw3Hits;   //!
   TBranch        *b__tauIsoMVAPWdR03oldDMwLT;   //!
   TBranch        *b__tauIsoMVADBdR03oldDMwLT;   //!
   TBranch        *b__tauIsoMVADBdR03newDMwLT;   //!
   TBranch        *b__tauIsoMVAPWnewDMwLT;   //!
   TBranch        *b__tauIsoMVAPWoldDMwLT;   //!
   TBranch        *b__relIso;   //!
   TBranch        *b__relIso0p4;   //!
   TBranch        *b__relIso0p4MuDeltaBeta;   //!
   TBranch        *b__miniIso;   //!
   TBranch        *b__miniIsoCharged;   //!
   TBranch        *b__ptRel;   //!
   TBranch        *b__ptRatio;   //!
   TBranch        *b__closestJetCsvV2;   //!
   TBranch        *b__closestJetDeepCsv_b;   //!
   TBranch        *b__closestJEC;   //!
   TBranch        *b__closest_lepAwareJetE;   //!
   TBranch        *b__closest_lepAwareJetPx;   //!
   TBranch        *b__closest_lepAwareJetPy;   //!
   TBranch        *b__closest_lepAwareJetPz;   //!
   TBranch        *b__closest_l1JetE;   //!
   TBranch        *b__closest_l1JetPx;   //!
   TBranch        *b__closest_l1JetPy;   //!
   TBranch        *b__closest_l1JetPz;   //!
   TBranch        *b__closest_lJetE;   //!
   TBranch        *b__closest_lJetPx;   //!
   TBranch        *b__closest_lJetPy;   //!
   TBranch        *b__closest_lJetPz;   //!
   TBranch        *b__closestJetDeepCsv_bb;   //!
    
   TBranch        *b__lElectronSummer16MvaGP;                                                           // OLD
   TBranch        *b__lElectronSummer16MvaHZZ;                                                          // OLD
   TBranch        *b__lElectronMvaFall17v1NoIso;                                                        // OLD
   TBranch        *b__lElectronMvaFall17Iso;
   TBranch        *b__lElectronMvaFall17NoIso;
                                             
   TBranch        *b__selectedTrackMult;   //!
   TBranch        *b__lMuonSegComp;   //!
   TBranch        *b__lMuonTrackPt;   //!
   TBranch        *b__lMuonTrackPtErr;   //!
   TBranch        *b__lGenIndex;   //!
   TBranch        *b__lMatchType;   //!
   TBranch        *b__lIsPrompt;   //!
   TBranch        *b__lIsPromptFinalState;   //!
   TBranch        *b__lIsPromptDecayed;   //!
   TBranch        *b__lMatchPdgId;   //!
   TBranch        *b__lMomPdgId;   //!
   TBranch        *b__lProvenance;   //!
   TBranch        *b__lProvenanceCompressed;   //!
   TBranch        *b__lProvenanceConversion;   //!
   TBranch        *b__lMatchPt;   //!
   TBranch        *b__lMatchEta;   //!
   TBranch        *b__lMatchPhi;   //!
   TBranch        *b__lMatchVertexX;   //!
   TBranch        *b__lMatchVertexY;   //!
   TBranch        *b__lMatchVertexZ;   //!
   TBranch        *b__lPtCorr;   //!
   TBranch        *b__lPtScaleUp;   //!
   TBranch        *b__lPtScaleDown;   //!
   TBranch        *b__lPtResUp;   //!
   TBranch        *b__lPtResDown;   //!
   TBranch        *b__lECorr;   //!
   TBranch        *b__lEScaleUp;   //!
   TBranch        *b__lEScaleDown;   //!
   TBranch        *b__lEResUp;   //!
   TBranch        *b__lEResDown;   //!
   TBranch        *b__nPh;   //!
   TBranch        *b__phPt;   //!
   TBranch        *b__phEta;   //!
   TBranch        *b__phEtaSC;   //!
   TBranch        *b__phPhi;   //!
   TBranch        *b__phE;   //!
   TBranch        *b__phCutBasedLoose;   //!
   TBranch        *b__phCutBasedMedium;   //!
   TBranch        *b__phCutBasedTight;   //!
   TBranch        *b__phMva;   //!
   TBranch        *b__phRandomConeChargedIsolation;   //!
   TBranch        *b__phChargedIsolation;   //!
   TBranch        *b__phNeutralHadronIsolation;   //!
   TBranch        *b__phPhotonIsolation;   //!
   TBranch        *b__phSigmaIetaIeta;   //!
   TBranch        *b__phHadronicOverEm;   //!
   TBranch        *b__phPassElectronVeto;   //!
   TBranch        *b__phHasPixelSeed;   //!
   TBranch        *b__phIsPrompt;   //!
   TBranch        *b__phTTGMatchCategory;   //!
   TBranch        *b__phTTGMatchPt;   //!
   TBranch        *b__phTTGMatchEta;   //!
   TBranch        *b__phMatchPdgId;   //!
   TBranch        *b__phPtCorr;   //!
   TBranch        *b__phPtScaleUp;   //!
   TBranch        *b__phPtScaleDown;   //!
   TBranch        *b__phPtResUp;   //!
   TBranch        *b__phPtResDown;   //!
   TBranch        *b__phECorr;   //!
   TBranch        *b__phEScaleUp;   //!
   TBranch        *b__phEScaleDown;   //!
   TBranch        *b__phEResUp;   //!
   TBranch        *b__phEResDown;   //!
   TBranch        *b__nJets;   //!
   TBranch        *b__jetPt;   //!
   TBranch        *b__jetPt_JECDown;   //!
   TBranch        *b__jetPt_JECUp;   //!
   TBranch        *b__jetSmearedPt;   //!
   TBranch        *b__jetSmearedPt_JECDown;   //!
   TBranch        *b__jetSmearedPt_JECUp;   //!
   TBranch        *b__jetSmearedPt_JERDown;   //!
   TBranch        *b__jetSmearedPt_JERUp;   //!
   TBranch        *b__jetPt_Uncorrected;   //!
   TBranch        *b__jetPt_L1;   //!
   TBranch        *b__jetPt_L2;   //!
   TBranch        *b__jetPt_L3;   //!
   TBranch        *b__jetEta;   //!
   TBranch        *b__jetPhi;   //!
   TBranch        *b__jetE;   //!
   TBranch        *b__jetCsvV2;   //!
   TBranch        *b__jetDeepCsv_udsg;   //!
   TBranch        *b__jetDeepCsv_b;   //!
   TBranch        *b__jetDeepCsv_c;   //!
   TBranch        *b__jetDeepCsv_bb;   //!
   TBranch        *b__jetHadronFlavor;   //!
   TBranch        *b__jetIsLoose;   //!
   TBranch        *b__jetIsTight;   //!
   TBranch        *b__jetIsTightLepVeto;   //!
   TBranch        *b__jetNeutralHadronFraction;   //!
   TBranch        *b__jetChargedHadronFraction;   //!
   TBranch        *b__jetNeutralEmFraction;   //!
   TBranch        *b__jetChargedEmFraction;   //!
   TBranch        *b__jetHFHadronFraction;   //!
   TBranch        *b__jetHFEmFraction;   //!
   TBranch        *b__met;   //!
   TBranch        *b__metRaw;   //!
   TBranch        *b__metJECDown;   //!
   TBranch        *b__metJECUp;   //!
   TBranch        *b__metUnclDown;   //!
   TBranch        *b__metUnclUp;   //!
   TBranch        *b__metPhi;   //!
   TBranch        *b__metRawPhi;   //!
   TBranch        *b__metPhiJECDown;   //!
   TBranch        *b__metPhiJECUp;   //!
   TBranch        *b__metPhiUnclDown;   //!
   TBranch        *b__metPhiUnclUp;   //!
   TBranch        *b__metSignificance;   //



  Analysis_mc();
  Analysis_mc(unsigned jaar,const std::string& list, const std::string& directory);
  virtual ~Analysis_mc();

  void printProgress(double progress) ;
  //______________________      inizialization functions       ________________________________// 
  //set up tree for reading and writing
  void initTree(TTree *tree, const bool isData = false,  unsigned jaar = 0);
  //skim tree
  void skimTree(const std::string&, std::string outputDirectory = "", const bool isData = false, unsigned jaar = 0);
  //set up tree for analysis
  void readSamples(const std::string&, const std::string&, std::vector<Sample>&);
  void readSamples(const std::string& list, const std::string& directory); //read sample list from file
  void initSample();                              //event weights will be set according to is2016() ( or equally is2017() ) flag
  void initSample(unsigned jaar, const Sample&);  
  //functions to analyze tree
  void GetEntry(long unsigned entry);
  void GetEntry(const Sample&, long unsigned entry);

  //______________________      analisi functions       ________________________________// 

  // Systematics categories -- systdir (where it applies): 0 = down, 1 = up
  //  0. central
  //  1. renormalization + factorization scales
  //  2. PDF + alpha_S
  //  3. PU
  //  4. prompt electron efficiencies
  //  5. prompt muon efficiencies
  //  6. prompt electron energy scale
  //  7. prompt muon momentum scale
  //  8. JEC 
  //  9. JER
  // 10. b tagging
  // 11. MC systematics
  //
  void analisi(  unsigned jaar, const std::string& list, const std::string& directory,
		 TString outfilename,
		int systcat = 0, int systdir = 0
		);

  double pu_weight ( TH1D *histo, double numberInteractions);




  //______________________      object functions       ________________________________// 
  //check lepton flavors 
  bool isElectron(const unsigned leptonIndex) const { return (_lFlavor[leptonIndex] == 0); }
  bool isMu(const unsigned leptonIndex) const { return (_lFlavor[leptonIndex] == 1); }
  bool isTau(const unsigned leptonIndex) const { return (_lFlavor[leptonIndex] == 2); }
  
  bool eleIsClean(const unsigned ) const;
  bool lepIsLoose(const unsigned ) const;
  bool eleIsLoose(const unsigned ) const;
  bool eleIsCleanBase(const unsigned , bool (Analysis_mc::*looseMuon)(const unsigned) const) const;
  bool eleIsClean2016(const unsigned ) const;
  bool eleIsClean2017(const unsigned ) const;
  bool eleIsClean2018(const unsigned ) const;
  bool lepIsLoose2016(const unsigned ) const;
  bool lepIsLoose2017(const unsigned ) const;
  bool lepIsLoose2018(const unsigned ) const;
  bool eleIsLoose2016(const unsigned ) const;
  bool eleIsLoose2017(const unsigned ) const;
  bool eleIsLoose2018(const unsigned ) const;
  bool muOurMedium(const unsigned ) const;
  bool muTimeVeto(const unsigned ) const;
  bool lepIsFOBase(const unsigned ) const;
  bool lepIsTightDisplaced(const unsigned ) const;
  bool lepIsTightPrompt(const unsigned ) const;
  bool lepPromptTriggerMatching(const unsigned ) const;
  bool elePassMVA(const unsigned ) const;
  bool jetIsCleanBase(const unsigned , bool (Analysis_mc::*leptonIsFO)(const unsigned) const) const;
  bool jetIsClean(const unsigned ) const;
  bool jetIsGood(const unsigned ) const;
  bool jetIsBJet(const unsigned ) const;
  double deepCSV(const unsigned ) const;

  //______________________      event selection functions       ________________________________// 

  void orderByPt(std::vector<unsigned>& , const double* , const unsigned ) const;
  double coneCorr(const unsigned ) const;
  void applyConeCorrection();
  unsigned selectLep(std::vector<unsigned>& ) const;
  unsigned selectLepConeCorr(std::vector<unsigned>& );
  int l1Index(const std::vector<unsigned>& );
  bool lepIsDisplaced(const unsigned leptonIndex, int index_taken_by_l1, std::vector<unsigned>& ind) const;
  bool vertex_found(const unsigned leptonIndex1, const unsigned leptonIndex2, int vertex_index) const;
  int l2l3_vertex_variable(const unsigned leptonIndex1, const unsigned leptonIndex2);

  //______________________      analysis tool functions       ________________________________// 
  double FR_weight(TGraphAsymmErrors *fakeRate_mu_sFR[3],  TGraphAsymmErrors *fakeRate_e_sFR[3], TGraphAsymmErrors *fakeRate_mumu_dFR[3], TGraphAsymmErrors *fakeRate_ee_dFR[3],   TGraphAsymmErrors *fakeRate_emu_dFR[3],bool   isSFR, bool   isDFR,double etaLepton,double flavorsLepton, double ptLepton, double etaJet,double flavorsJet,double ptJe ) ;
  double dFR_factor_ee(TGraphAsymmErrors *fakeRate_e[3],       int eta,  double lptcone  );
  double dFR_factor_mumu(TGraphAsymmErrors *fakeRate_e[3],       int eta,  double lptcone  );
  double dFR_factor_emu(TGraphAsymmErrors *fakeRate_e[3],       int eta,  double lptcone  );
  double sFR_factor_e (TGraphAsymmErrors *fakeRate[3], double eta,     double lptcone );
  double sFR_factor_mu (TGraphAsymmErrors *fakeRate[3], double eta,     double lptcone );






  
 private:
  unsigned year;
  unsigned jaar;
  
  TTree* fChain;                                                          //current Tree
  std::shared_ptr<TFile> sampleFile;                                      //current sample
  std::vector<Sample> samples;                                            //combined list of samples
  Sample currentSample;                                                   //reference to current sample, needed to check what era sample belongs to
  int currentSampleIndex = -1;                                            //current index in list
  //bool isData = false;
  double scale = 0;
  double weight = 1;                                                      //weight of given event
  unsigned long nEntries = 0;
  const double lumi2017 = 41.53;                                          //in units of 1/fb
  const double lumi2016 = 35.867;                 
  const double lumi2018 = 59.74;
  // Weight for b-jet veto
  double bwght = 1.;

  //check whether sample is 2017 or not
  bool isData() const { return currentSample.isData(); }
  bool isMC() const { return currentSample.isMC(); }
  bool is2017() const { return (jaar == 1); }
  bool is2016() const { return (jaar == 0); }
  bool is2018() const { return (jaar == 2); } 


  //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PARAMETERS AND CUTS >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  //pt displaced
  const double mu_pt=3.;
  const double ele_pt=7.;
  //pt prompt
  const double mu_2016=25;
  const double mu_2017=28;
  const double mu_2018=28;
  const double ele_2016=30;
  const double ele_2017=38;
  const double ele_2018=35;
  //iso FO
  const double mu_iso_loose=1.2;
  const double ele_iso_loose=1.2;
  const double mu_iso_tight=0.2;
  const double ele_iso_tight=0.2;
  //jet pt
  const double jet_pt_cut = 25.;
  //wp bjet loose
  const double bjet_loose_2016 = 0.2217;
  const double bjet_loose_2017 = 0.1522;
  const double bjet_loose_2018 = 0.1241;

  //dxy
  const double dxy_cut = 0.01;

  
  const double met_cuts =80;
  const int number_veto_leptons=3;

  const double isolation_loose=1.2;
  const double isolation_tight=0.2;
    
  
  const double MVA_cuts_pt15[3] = {0.77, 0.56, 0.48};
  const double MVA_cuts_pt25[3] = {0.52, 0.11, -0.01};


  
  int               goodjet=0;
  int               bjet=0;
  unsigned          promptC = 0;
  double            iV_ls=0;
  double            iV_lt=0;
  double            iV_st=0;  
  Double_t          _mll_min=50000;
  Double_t          _mll_min_os=50000;
  TLorentzVector    lepton_reco[3];
  int               flavors_3l[3];
  int               charge_3l[3];
  TLorentzVector    sum_3l_rec;	//M_3l
  TLorentzVector    pair [3];
  int               kind[1] ={-1}; // 0 no-ossf
  TLorentzVector    sum_2l_rec_pair; 	//M_2l best Z candidate
  int               event_clas[1]={-1}; // 1* = eee   2* = emm   3* = eem  4* = mmm
  int               skip_event[1]= {-1};
  TLorentzVector    lepton_transv[3];
  TLorentzVector    METvec;
  


  

  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<            
 







  

  
  // ClassDef(Analysis_mc,1) 
    };

#endif

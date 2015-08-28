from ROOT import TDirectory, TH1D, TCanvas, TList, TFile, TAxis, TPad, gPad, THStack, TLatex , TLine, TLegend, kRed , kBlue, Double
import re
from math import sqrt

class ObjectProperty:
    def __init__(self, directory , signalname , ignorelist = [] ):
        self.BKGs = []
        self.SignalName = signalname
        self.Name = directory.GetName()
        searchre = re.compile( r'(?P<cutname>.*)_' + directory.GetName() + '_(?P<histname>.*)' )
        directory.ReadAll()
        list1 = directory.GetList()
        for i in range(0 , list1.GetSize() ):
            name = list1.At( i ).GetName() 
            obj = directory.Get( name )
            type = obj.Class().GetName()
            if type=="TH1D" :
                m = searchre.match( name )
                if m.group('histname') == signalname :
                    self.Signal = obj
                    self.CutName = m.group('cutname')
                    self.From = self.Signal.GetXaxis().GetXmin()
                    self.To = self.Signal.GetXaxis().GetXmax()
                    self.NBins = self.Signal.GetXaxis().GetNbins()
                    self.IsVariableBinSize = self.Signal.GetXaxis().IsVariableBinSize()
                elif m.group('histname') == 'data' :
                    self.Data = obj
                elif m.group('histname') == 'MC' :
                    self.MC = obj
                elif not m.group('histname') in ignorelist :
                    setattr( self , m.group('histname') , obj )
                    self.BKGs.append(  m.group('histname') )
            elif type=='TCanvas':
                self.Canvas = obj


    def GetFormattedIntegral( self, name , formaT = "{0:.2f}" ): #+-{1:.2f}" ):
        hist = getattr( self , name )
        err = Double(0)
        val = hist.IntegralAndError( -1 , 1000 , err)
        err1 = 0.0
        err1 += err
        return formaT.format( val , err )
    def PrintSummary( self ):
        print self.SignalName + " | " + self.GetFormattedIntegral( "Signal" )
        for bkg in self.BKGs:
            print bkg + " | " + self.GetFormattedIntegral( bkg )
        print "Sum" + " | " + self.GetFormattedIntegral( "MC" )
        print "Data | " + self.GetFormattedIntegral("Data") 

    def GetFormattedBinContent( self, name , biN , formaT = "{0:.2f},{1:.2f}" ):
        hist = getattr( self , name )
        val = hist.GetBinContent( biN )
        err = hist.GetBinError( biN )
        if( not name == "Data" ):
            val *= (41.9/41.0)
            err *= (41.9/41.0)
        return formaT.format( val , err )
    def PrintCutFlowTable(self):
        firstLine = " | - | " + self.SignalName + " | " 
        for bkg in self.BKGs :
            firstLine += bkg + " | "
        firstLine += " MC | Data | Data/MC |"
        print firstLine

        for bin in range(1,self.NBins+1):
            cutName = self.Signal.GetXaxis().GetBinLabel(bin)
            if cutName == "":
                cutName = "{0:.0f}-{1:.0f}".format(self.Signal.GetXaxis().GetBinLowEdge(bin) , self.Signal.GetXaxis().GetBinUpEdge(bin) )
            line = " | " + cutName + " | " + self.GetFormattedBinContent( "Signal" , bin ) + " | "
            for bkg in self.BKGs :
                line += self.GetFormattedBinContent(bkg,bin) + " | "
            line += self.GetFormattedBinContent("MC" , bin , "{0:.2f}$\pm${1:.2f}" ) + " | " + self.GetFormattedBinContent("Data" , bin) + "|"
            data = getattr(self, "Data").GetBinContent( bin )
            dataErr = getattr(self, "Data").GetBinError( bin )

            mc = getattr(self, "MC").GetBinContent( bin )
            mcErr = getattr(self, "MC").GetBinError( bin )

            dataOmc = 0
            dataOmcErr = 0
            if mc != 0 and data != 0 :
                dataOmc = data/mc
                dataOmcErr = dataOmc*sqrt( dataErr*dataErr/(data*data) + mcErr*mcErr/(mc*mc) )

            line += "{0:.2f}+-{1:.2f}".format( dataOmc , dataOmcErr ) + "|"
            print line

    def GetSumBKGs(self):
        ret = getattr( self , self.BKGs[0] ).Clone("SumBkgs_" + self.Name + "_" + self.CutName )
        for i in range( 1 , len(self.BKGs) ):
            ret.Add( getattr( self , self.BKGs[i] ) )
        return ret
        
    def GetDataSumBKGsSubtracted(self):
        sumbkgs = self.GetSumBKGs()
        self.DataSumBKGsSubtracted = self.Signal.Clone("DataClone1")
        self.DataSumBKGsSubtracted.Add(self.Data , sumbkgs , 1 , -1 )
        return self.DataSumBKGsSubtracted

    def GetStack(self , include_signal = True ):
        self.Stack = THStack( self.Name + "_STack_" + self.CutName , "" ) 
        if include_signal :
            #self.Signal.Rebin(50)
            self.Stack.Add( self.Signal )
            
        for bkg in self.BKGs :
            #getattr( self , bkg ).Rebin(50)
            self.Stack.Add( getattr( self , bkg )  )
        return self.Stack

    def RatioPlot(self , xtitle):
        self.h2 = self.Data.Clone("h1_copy")
        self.h1 = self.MC.Clone("h2_copy")
        hstack = self.GetStack()

        self.h1.SetStats(0)	
        self.h2.SetStats(0)	
        self.h1.SetMarkerStyle(20)
        self.h2.SetMarkerStyle(20)

        self.RatioPlot = TCanvas(self.Name+"_ratio"+ "_"  + self.CutName,"",0,0,600,600 )
        self.RatioPlot.SetFrameLineWidth(1)
        self.RatioPlot.cd()
	
        border = 0.2
        scale = (1-border)/border
        p_plot  = TPad(self.Name +"_plotpad"+ "_" + self.CutName,  "Pad containing the overlay plot", 0,0.211838,1,1 )
        p_plot.SetLeftMargin(0.131579)
        p_plot.SetRightMargin(0.08)
        p_plot.SetTopMargin(0.06895515)
        p_plot.SetBottomMargin(0.07206074)
        p_plot.Draw()

        p_ratio = TPad(self.Name + "_ratiopad"+  "_" + self.CutName, "Pad containing the ratio",   0,0.01863354,0.9967105,0.2189441 )
        p_ratio.SetLeftMargin(0.1336634)	
        p_ratio.SetRightMargin(0.075)
        p_ratio.SetTopMargin(0.06976745)
        p_ratio.SetBottomMargin(0.2790698)
        p_ratio.Draw()
 
        
        p_plot .cd()
        gPad.SetFillStyle(0)

        max1 = self.h1.GetMaximum()
        max2 = self.h2.GetMaximum()
        maximum  = 1.5*max( max1, max2 )
        self.h1.SetMaximum(maximum)
        self.h2.SetMaximum(maximum)
        hstack.SetMaximum(maximum)
        hstack.SetMinimum(0.02)

        yTitle = "Events"
        hstack.Draw();
        hstack.GetYaxis().SetTitle(yTitle);
        hstack.GetYaxis().SetLabelSize(0.05);
        hstack.GetYaxis().SetTitleSize(0.05);
        hstack.GetYaxis().SetTitleOffset(1.3);

        hstack.Draw("hist")
        self.h2.SetMarkerColor(1)
        #self.h2.Rebin(50)
        self.h2.Draw("sameE")

        TitleBox = TLatex()
        TitleBox.SetNDC()
        TitleBox.SetTextSize(0.03)
        text = ""
        TitleBox.DrawLatex(0.13,0.943,text)

        LumiBox = TLatex()
        LumiBox.SetNDC()
        LumiBox.SetTextSize(0.0305)
        LumiBox.DrawLatex(0.68,0.943,"#sqrt{s} = 13 TeV, L = 1.0 fb^{-1}")

        self.Legend1 = TLegend(.71,.54,.91,.92)
        self.Legend1.AddEntry( self.Signal , self.SignalName , 'f' )
        for bkg in self.BKGs :
            self.Legend1.AddEntry( getattr( self , bkg ) , bkg , 'f' )
        self.Legend1.AddEntry( self.Data , "data" , 'f' )
        self.Legend1.Draw()

        p_plot.Draw()
        gPad.RedrawAxis()

        p_ratio.cd()
        
        self.h_ratio = self.Data.Clone("data_copy_ratio")	
        self.h_ratio.SetStats(0)
        self.h_ratio.SetMarkerStyle(20)

        self.h_ratio.Divide(self.h2, self.h1)
        self.h_ratio.SetMinimum(0.4)
        self.h_ratio.SetMaximum(3.0)
        self.h_ratio.GetYaxis().SetTitleOffset(self.h1.GetYaxis().GetTitleOffset())

        self.h_ratio_mc = self.MC.Clone("h1_copy_MC_ratio")
        self.h_ratio_mc.Divide(self.h1)
        self.h_ratio_mc.GetYaxis().SetRangeUser(0,2)
        self.h_ratio_mc.GetXaxis().SetLabelSize( 0.)
        self.h_ratio_mc.GetYaxis().SetTitle("Data / MC")
        self.h_ratio_mc.GetXaxis().SetTitle(xtitle)
        self.h_ratio_mc.GetXaxis().SetTitleSize(0.2)
        self.h_ratio_mc.GetXaxis().SetTitleOffset(0.5)
        self.h_ratio_mc.GetYaxis().SetLabelSize(0.19)
        self.h_ratio_mc.GetXaxis().SetTickLength(0.09)
        self.h_ratio_mc.GetYaxis().SetTitleSize(0.18)
        self.h_ratio_mc.GetYaxis().SetTitleOffset(0.36)
        self.h_ratio_mc.GetYaxis().SetNdivisions(509)
  
	
        self.h_ratio_mc.SetFillStyle(3001)
        self.h_ratio_mc.SetFillColor(1)
        self.h_ratio_mc.Draw("E2")

        self.h_ratio.SetMarkerColor(1)
        self.h_ratio.SetLineColor(1)
        self.h_ratio.DrawCopy("Esame")

        l3 = TLine(self.h1.GetXaxis().GetXmin(), 1.00, self.h1.GetXaxis().GetXmax(), 1.00);
        l3.SetLineWidth(2)
        l3.SetLineStyle(7)
        l3.Draw()

        gPad.RedrawAxis()
        p_ratio.Draw()
        self.RatioPlot.Update()




class Draw:
    def __init__(self,  hist , opt = "" ):
        self.C = TCanvas()
        hist.Draw(opt)



def STauCutFlow():
    f = TFile.Open("/home/hbakhshi/Desktop/STau/CharginoCharginoNewPUTauPt25_Histos.root") #Closure_MuFR_SSOS_Histos.root
    dir = f.GetDirectory("cutflowtable")
    dir.ls()
    estimationres = ObjectProperty( dir , "SUSY_380_0" , [ "SUSY" , "SUSY_180_60" , "SUSY_240_60" , "SUSY_240_80"] ) # , "SUSY_380_1" , "QCD" ,  "ZX" , "Top" , "WW" , "Higgs"  ] )
    estimationres.PrintCutFlowTable()


def TChannel_JPCSV():
    f = TFile.Open("MassPlots/2j1tmoreinfo.root" )
    dir = f.GetDirectory("jpCSV") 
    jpcsv = ObjectProperty( dir , "TChannel" , ["SUSY" , "TChannel_N" , "TChannel_P" , "VJets_N" , "VJets_P"] )
    jpcsv.RatioPlot("")


def TChannel_CutFlow():
    f = TFile.Open("MassPlots/spring_dcsonlydata41_2j1t_VJetsSF1NewCFT.root")
    dir = f.GetDirectory("cutflowtable") 
    cutflowtable = ObjectProperty( dir , "TChannel" , ["SUSY" , "TChannel_N" , "TChannel_P" , "VJets_N" , "VJets_P"] )
    cutflowtable.Data.SetBinContent(1, 334639)
    cutflowtable.Data.SetBinContent(2, 11537)
    cutflowtable.Data.SetBinContent(3, 583)
    cutflowtable.Data.SetBinContent(4, 376)
    cutflowtable.Data.SetBinContent(5, 231)
    cutflowtable.PrintCutFlowTable()

def TChannel_CutFlowW1():
    dirw1 = f.GetDirectory("cutflowtablew1") 
    cutflowtablew1 = ObjectProperty( dirw1 , "tChannel" , ["SUSY"] )
    cutflowtablew1.PrintCutFlowTable()


def TChannel_Plotter():
    f = TFile.Open("./MassPlots/2j1t_correctws_syncedFull2.root")
    # f = TFile.Open("MassPlots/spring_dcsonlydata.root")
    dir1 = f.GetDirectory("MT")
    MT = ObjectProperty( dir1 , "TChannel" , ["QCD1" , "SUSY" , "TChannel_N" , "TChannel_P" , "VJets_N" , "VJets_P"] )
    MT.RatioPlot("MT")

def TChannel_WEstiamtion():
    f = TFile.Open("MassPlots/spring_dcsonlydata41_2j1t_VJetsSF1.root")
    dir1 = f.GetDirectory("jPrimeEta" )
    jPrimeEta = ObjectProperty( dir1 , "VJets" ,  ["SUSY" , "TChannel_N" , "TChannel_P" , "VJets_N" , "VJets_P"] )
    jPrimeEta.QCD1.Scale( 5.0/jPrimeEta.QCD1.Integral() )
    jPrimeEta.PrintSummary()
    dir2 = f.GetDirectory("jPrimeEtaSB" )
    jPrimeEtaSB = ObjectProperty( dir2 ,"VJets" , ["SUSY" , "TChannel_N" , "TChannel_P" , "VJets_N" , "VJets_P"] )
    jPrimeEtaSB.QCD1.Scale( 1.0/jPrimeEtaSB.QCD1.Integral() )
    jPrimeEtaSB.PrintSummary()

    jPrimeDD_SB = jPrimeEtaSB.GetDataSumBKGsSubtracted()
    errDD = Double(0)
    valDD = jPrimeDD_SB.IntegralAndError( -1 , 10000 , errDD )
    print errDD
    print valDD
    jPrimeDD_SB.Scale( 1.0/jPrimeDD_SB.Integral() ) #jPrimeEta.Signal.Integral()
    jPrimeDD_SB.SetLineColor( kRed )
    jPrimeDD_SB.SetLineWidth( 3 )
    jPrimeDD_SB.SetTitle( "Data Driven (SB)" )
    jPrimeDD_SB.GetXaxis().SetTitle( "|#eta_{j'}|" )
    jPrimeDD_SB.GetYaxis().SetTitle( "Normalized" )
    a = Draw( jPrimeDD_SB )
    jPrimeEta.Signal.Scale( 1.0 /jPrimeEta.Signal.Integral() )
    jPrimeEta.Signal.SetLineColor( kBlue )
    jPrimeEta.Signal.SetLineWidth( 3 )
    jPrimeEta.Signal.SetTitle( "W+jets MC (SR)" )
    jPrimeEta.Signal.Draw("same")

def Others():
    # fqcd = TFile.Open( "/home/hbakhshi/Desktop/ThisMonth/SingleTop/PrePreApproval/qcd.root" )
    # hQCD = fqcd.Get("QCDEtaJ")
    # hQCD.Rebin( 2 )
    # hQCD.Scale( jPrimeEtaSB.QCD.Integral() / hQCD.Integral() )
    # jPrimeEtaSB.QCD = hQCD

    # fqcd = TFile.Open( "/home/hbakhshi/Documents/Physics/Analysis13TeV/MassPlots/QCD_Pt-20toInf_MuEnrichedPt15_PionKaonDecay_Tune4C_13TeV_pythia8_absetajetprime_SB_2j1t.root" )
    # hQCD = fqcd.Get("abs_eta_other_Je")
    # jPrimeEtaSB.QCD = hQCD

    jPrimeEtaSB.QCD1.Scale( (15.3+22.3)/(229.3) )
    # dataSB =  jPrimeEtaSB.Data.Integral()
    # MCSB = jPrimeEtaSB.MC.Integral()

    # jPrimeEtaSB.QCD1.Scale( dataSB/MCSB )
    # jPrimeEtaSB.Top.Scale( dataSB/MCSB )
    # jPrimeEtaSB.Signal.Scale( dataSB/MCSB )
    
    jPrimeDD_SB = jPrimeEtaSB.GetDataSumBKGsSubtracted()
    errDD = Double(0)
    valDD = jPrimeDD_SB.IntegralAndError( -1 , 10000 , errDD )
    print errDD
    print valDD
    jPrimeDD_SB.Scale( 1.0/jPrimeDD_SB.Integral() ) #jPrimeEta.Signal.Integral()
    jPrimeDD_SB.SetLineColor( kRed )
    jPrimeDD_SB.SetLineWidth( 3 )
    jPrimeDD_SB.SetTitle( "Data Driven (SB)" )
    jPrimeDD_SB.GetXaxis().SetTitle( "|#eta_{j'}|" )
    jPrimeDD_SB.GetYaxis().SetTitle( "Normalized" )
    a = Draw( jPrimeDD_SB )
    jPrimeEta.Signal.Scale( 1.0 /jPrimeEta.Signal.Integral() )
    jPrimeEta.Signal.SetLineColor( kBlue )
    jPrimeEta.Signal.SetLineWidth( 3 )
    jPrimeEta.Signal.SetTitle( "W+jets MC (SR)" )
    jPrimeEta.Signal.Draw("same")
    
    # jPrimeEta = ObjectProperty( dir2 , "tChannel" , ["SUSY"] )
    # jPrimeDD_SB.Scale( jPrimeEta.VJets.Integral()/jPrimeDD_SB.Integral() )
    # jPrimeEta.MC.Add( jPrimeEta.VJets , -1 )
    # jPrimeEta.MC.Add( jPrimeDD_SB , +1 )
    # jPrimeEta.RatioPlot("")


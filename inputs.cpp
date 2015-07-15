#include"inputs.h"
#include"CodeNCTUns/cmInfo.h"
#include "CodeNCTUns/channel_Model.h"
#include <cstdlib>
#include <iostream>
#include<list>
#include<cmath>

using namespace std;

void
Dump_CM_List(struct cmInfo *cminfo) {

    list<string> models;

    //models.push_back ( "[Theoretical Path Loss Model]::PropModel");
    models.push_back("0: Free_Space");
    models.push_back("1: Two_Ray_Ground");
    models.push_back("2: Free_Space_and_Shadowing");
    /*
            models.push_back ( "[Theoretical Fading Model]::FadingOpt");
            models.push_back ( "0: None");
            models.push_back ( "1: Rayleigh");
            models.push_back ( "2: Ricean");
     */
    //models.push_back ( "[Empirical Model]::PropModel");
    models.push_back("3: LEE_Microcell");
    models.push_back("4: Okumura_Hata_VHF_UHF");
    models.push_back("5: Okumura_Hata_large_urban");
    models.push_back("6: Okumura_Hata_medium_urban");
    models.push_back("7: Okumura_Hata_suburban");
    models.push_back("8: Okumura_Hata_open_areas");
    models.push_back("9: COST_231_Hata");
    models.push_back("10: Suburban_1_9GHz_TA");
    models.push_back("11: Suburban_1_9GHz_TB");
    models.push_back("12: Suburban_1_9GHz_TC");
    models.push_back("13: M2M_UMTS_LOS");
    models.push_back("14: M2M_UMTS_NLOS");
    models.push_back("15: ECC33");
    models.push_back("16: ECC33_dversion");
    models.push_back("17: AdHoc_LOS");
    models.push_back("18: HarXiaMicrocell_Low_Rise_NLOS");
    models.push_back("19: HarXiaMicrocell_High_Rise_Lateral");
    models.push_back("20: HarXiaMicrocell_High_Rise_ST");
    models.push_back("21: HarXiaMicrocell_LOS");
    models.push_back("22: HowardXia_UniformRoofTop");
    models.push_back("23: HowardXia_BSAntennaAboveRoofTopLevel");
    models.push_back("24: HowardXia_BSAntennaBelowRoofTopLevel");
    models.push_back("25: Indoor_2_4G_LOS_80211_a_b");
    models.push_back("26: Indoor_5_3G_LOS_80211_a_b");
    models.push_back("27: Indoor_2_4G_NLOS_80211_a_b");
    models.push_back("28: Indoor_5_3G_NLOS_80211_a_b");
    models.push_back("29: Bertoni_Walfisch_Urban");
    models.push_back("30: Egli_Urban_Rural");
    models.push_back("31: COST_231_Hata_3GPP_TR_25966_V8_Urban");
    models.push_back("32: COST_231_Hata_3GPP_TR_25966_V8_Suburban");

    cout << "PROPAGATION MODEL ESTIMATOR\n\n";
    cout << "IMPLEMETED WITH NCTUNS 6.0 CODE \n\n";
    cout << "PROPAGATION MODEL LIST\n\n";
    list<string>::iterator it = models.begin();
    for (it; it != models.end(); ++it)
        cout << *it << endl;
    cout << "\nPlease choose the number of the propagation model\t";
    cin >> cminfo->PropModel;
    it = models.begin();
    for (int i = 0; i < cminfo->PropModel; i++)
        ++it;

    cout << endl << "You choose option number " << *it << endl;

    /*
    cminfo->pathlossExp_ = PLExp_;		// path loss exponent
    cminfo->std_db_ = std_db_;		// standard deviation
    cminfo->dist0_ = dist0_;		// close-in distance (meter)
        
     */
    models.clear();

    /*Inicio obligatorio de ids*/

    cminfo->txNid = rand() % 31; // tx node id Raicean function
    cminfo->rxNid = rand() % 31; // my node id (rx node id) Rician function
}

void
Dump_FM_List(struct cmInfo *cminfo) {

    if (cminfo->PropModel < 3) {

        list<string> models;
        models.push_back("0: None");
        models.push_back("1: Rayleigh");
        models.push_back("2: Ricean");

        cout << "\n\nThe selected propagation model can be used with a fading model\n";
        list<string>::iterator it = models.begin();
        for (it; it != models.end(); ++it)
            cout << *it << endl;
        cout << "\nPlease choose one\t";
        cin >> cminfo->fadingOpt_; // index of the fading model
        it = models.begin();
        for (int i = 0; i < cminfo->fadingOpt_; i++)
            ++it;

        cout << endl << endl << "You choose option number " << *it << endl;

        models.clear();

        switch (cminfo->fadingOpt_) {
            case 1:
                cout << "Ingrese Fading Var de Rayleigh fading\t";
                cin >> cminfo->fv; // used in Rayleigh fading
                break;
            case 2:
                cout << "Ingrese el factor K de Rician fading (db)\t";
                double Riceank;
                cin>>Riceank;
                cminfo->RiceanK = Riceank; // db

                break;
            case 0:
                break;
            default:
                break;

        }


    }
}

void Dump_GDM_List(struct cmInfo *cminfo) {
    cout << "\nGeneral Data of Tx and RX nodes\n";

    cout << "\n TX Power transmission  (dbm)-> \t";
    cin >> cminfo->Pt;
    cminfo->Pt = pow(10, (cminfo->Pt) / 10) * 1e-3; // Watt

    /* 
           cminfo->Pt = wphyinfo->TxPr_; 		// tx power (watt)
     */
    cout << "\n TX Antenna Gain  (dbi) [NCTuns/Estinet 2dbi omnidirectional]-> \t";
    cin >> cminfo->Gt;
    cout << "\n RX Antenna Gain  (dbi) [NCTuns/Estinet 2dbi omnidirectional]-> \t";
    cin >> cminfo->Gr;
    /*
            cminfo->Gt = txGain;			// tx gain (dbi)
            cminfo->Gr = rxGain;			// rx gain (dbi)
     */
    cout << "\nDistance between nodes (m)-> \t";
    cin >> cminfo->nodeDist;

    cout << "\nPath loss exponent (adimensional)-> \t";
    cin >> cminfo->pathlossExp_; // path loss exponent
    /*
            cminfo->nodeDist = sqrt((rX-tX)*(rX-tX) + (rY-tY)*(rY-tY) + (rZ-tZ)*(rZ-tZ));
     */
    /*
            double tX = T_locX+t1; 
            double tY = T_locY+t2;	
            double tZ = T_locZ + *txAntennaHeight;
            double rX = R_locX+r1; 
            double rY = R_locY+r2;	
            double rZ = R_locZ + antennaHeight;
     */
    cout << "\nFor the propagation model selected, you must provide the following data\n";

    if (cminfo->PropModel != 0 && cminfo->PropModel != 2 && (cminfo->PropModel < 25 || cminfo->PropModel > 28)) {
        cout << "\nAntenna Height is the sum of the height where is located the node and\n"
                "the antenna height\n";
        cout << "\nTX node Antenna Height (m)-> \t";
        cin >> cminfo->txAntennaHeight;
        cout << "\nRX node Antenna Height (m)-> \t";
        cin >> cminfo->rxAntennaHeight;
    }
    if (cminfo->PropModel == 2) {
        cout << "\nPath loss exponent (adimensional)-> \t";
        cin >> cminfo->pathlossExp_; // path loss exponent
        cout << "\nThe standard deviation-> \t";
        cin >> cminfo->std_db_; // standard deviation
        cout << "\nThe close-in distance (m)-> \t";
        cin >> cminfo->dist0_; // close-in distance (meter)
        /*
        cminfo->pathlossExp_ = PLExp_;		// path loss exponent
        cminfo->std_db_ = std_db_;		// standard deviation
        cminfo->dist0_ = dist0_;		// close-in distance (meter)
         */
    }
    if (cminfo->PropModel < 3) {
        cout << "you can include system loss(for instance antenna coupling losses)\n";
        cout << "\nSystem loss (adimensional)-> \t";
        cin >> cminfo->L; // systom loss
    }
    if (cminfo->PropModel >= 22 && cminfo->PropModel <= 24) {
        cout << "\nstreet width (m)-> \t";
        cin >> cminfo->w; // street width (meter)
        cout << "\naverage heights of surrounding buildings (m)-> \t";
        cin >> cminfo->hbd; // average heights of surrounding buildings (meter)
        cout << "\naverage separation distance between the rows of buildings (m)-> \t";
        cin >> cminfo->d; // average separation distance between the rows of buildings (meter)
    }
    if (cminfo->PropModel == 29) {
        cout << "\naverage heights of surrounding buildings (m)-> \t";
        cin >> cminfo->hbd; // average heights of surrounding buildings (meter)
        cout << "\naverage separation distance between the rows of buildings (m)-> \t";
        cin >> cminfo->d; // average separation distance between the rows of buildings (meter)
    }
    if (cminfo->PropModel == 14 || cminfo->PropModel == 18) {
        cout << "\naverage heights of surrounding buildings (m)-> \t";
        cin >> cminfo->hbd; // average heights of surrounding buildings (meter)
    }
    /*	
           cminfo->hbd = averageHB; 		// average heights of surrounding buildings (meter)
           cminfo->w = streetWidth;		// street width (meter)
           cminfo->d = averageDist; 		// average separation distance between the rows of buildings (meter)
     */
}

double Create_PM() {
    double Freq;
    cout << "\nPlease introduce the frequency operation(MHz)-> \t";
    cin>>Freq;
    return Freq;

}

void Dump_Results(channelModel *propModel, struct cmInfo *cminfo) {
    double Pr = 9.0; //Potencia de salida
    int repeatPr = 0;
    cout << endl;
    Pr = propModel->Pr(cminfo);
    //cout.precision(2);
    cout << endl << "The estimation of Power at Recepction is\t" << Pr;

    if (cminfo->PropModel < 3 && cminfo->fadingOpt_ > 0) {
        cout << "\tRepeat(1 , 0)\t";
        cin>>repeatPr;
    }

    //To see how vary as result of Fading
    while (repeatPr && cminfo->PropModel < 3 && cminfo->fadingOpt_ > 0) {
        Pr = propModel->Pr(cminfo);
        cout << endl << "The estimation of Power at Recepction is\t" << Pr;
        cout << "\t Repeat(1 , 0)\t";
        cin>>repeatPr;
    }

}

void ShowCarrierSenseDistance(channelModel *propModel, struct cmInfo *cminfo) {
    double CSThresh; //Carrier sense Treshold
    double CSThreshD;
    int repeatPr = 0;
    cout << endl << endl << "\n\nWhich is the Carrier Sense Threshold of the RX(dbm)->\t";
    cin>>CSThresh;
    CSThreshD = propModel->Calculate_Carrier_Sense_Dist(cminfo, CSThresh);
    cout << endl << "\n\n The estimate Carrier Sense range is" << CSThreshD << " (m)" << endl;
    if (cminfo->PropModel < 3 && cminfo->fadingOpt_ > 0) {
        cout << "\tRepeat(1 , 0)\t";
        cin>>repeatPr;
    }
    while (repeatPr && cminfo->PropModel < 3 && cminfo->fadingOpt_ > 0) {
        cout << endl << endl << "\n\nWhich is the Carrier Sense Threshold of the RX(dbm)->\t";
        cin>>CSThresh;
        CSThreshD = propModel->Calculate_Carrier_Sense_Dist(cminfo, CSThresh);
        cout << endl << "\n\n The estimate Carrier Sense range is" << CSThreshD << " (m)" << endl;
        cout << "\t Repeat(1 , 0)\t";
        cin>>repeatPr;
    }
}

void ShowPtxAtDistance(channelModel *propModel, struct cmInfo *cminfo) {
    double CSThresh; //Carrier sense Treshold
    double CSThreshD;
    double Ptx = 0;
    int repeatPr = 0;
    cout << endl << endl << "\n\nWhich is the Carrier Sense Threshold of the RX(dbm)->\t";
    cin>>CSThresh;
    cout << endl << endl << "\n\nWhich is the Distance of the RX(m)->\t";
    cin>>CSThreshD;
    Ptx = propModel->Calculate_Ptx(cminfo, CSThresh, CSThreshD);
    cout << endl << "\n\n The estimate Tx Power range is" << Ptx << " (dbm)" << endl;
    if (cminfo->PropModel < 3 && cminfo->fadingOpt_ > 0) {
        cout << "\tRepeat(1 , 0)\t";
        cin>>repeatPr;
    }
    while (repeatPr && cminfo->PropModel < 3 && cminfo->fadingOpt_ > 0) {
        cout << endl << endl << "\n\nWhich is the Carrier Sense Threshold of the RX(dbm)->\t";
        cin>>CSThresh;
        cout << endl << endl << "\n\nWhich is the Distance of the RX(m)->\t";
        cin>>CSThreshD;
        Ptx = propModel->Calculate_Ptx(cminfo, CSThresh, CSThreshD);
        cout << endl << "\n\n The estimate Tx Power range is" << Ptx << " (dbm)" << endl;
        cout << "\t Repeat(1 , 0)\t";
        cin>>repeatPr;
    }

}

void PtxAtDistance(channelModel *propModel, struct cmInfo *cminfo) {
    double Pr = 9.0; //Potencia de salida
    int repeatPr = 0;
    cout << endl;
    Pr = propModel->Pr(cminfo);
    //cout.precision(2);
    cout << endl << "ingrese la distance maxima";
    cout << endl << "The estimation of Power at Recepction is\t" << Pr;

    if (cminfo->PropModel < 3 && cminfo->fadingOpt_ > 0) {
        cout << "\tRepeat(1 , 0)\t";
        cin>>repeatPr;
    }

    //To see how vary as result of Fading
    while (repeatPr && cminfo->PropModel < 3 && cminfo->fadingOpt_ > 0) {
        Pr = propModel->Pr(cminfo);
        cout << endl << "The estimation of Power at Recepction is\t" << Pr;
        cout << "\t Repeat(1 , 0)\t";
        cin>>repeatPr;
    }
}
//usar luego
/*models.push_back (" Note:");
models.push_back ("   PropModel: index of the channel model");
models.push_back ("   fv: fading variable");
models.push_back ("   L: system loss >= 1");
models.push_back ("   Pt: transmitter power");
models.push_back ("   Gt: transmitter gain");
models.push_back ("   Gr: receiver gain");
models.push_back ("   dist: distance between transmitter and receiver");
models.push_back ("   hbd: average height of surrounding buildings (rooftops)");
models.push_back ("   w: street width");
models.push_back ("   d: average separation distance between the rows of buildings");
models.push_back ("   Pr: received power of receiver (dbm)");
models.push_back ("                            _____     _____");
models.push_back ("                           |_____|   |_____|");
models.push_back ("                            |   |     |   |");
models.push_back ("                            |   |     |   |");
models.push_back ("                            |___|     |___|");
models.push_back ("                                 --w--");
models.push_back ("                              -----d-----");

 */
/*
        assert(cminfo);
        cminfo->PropModel = PropModel;		// index of the propagation channel model
        cminfo->fadingOpt_ = fadingOpt;		// index of the fading model
        cminfo->txNid = txNid;			// tx node id
        cminfo->rxNid = get_nid();		// my node id (rx node id)
        cminfo->fv = FadingVar;			// used in Rayleigh fading
        cminfo->RiceanK = RiceanK; 		// db
        double tX = T_locX+t1; 
        double tY = T_locY+t2;	
        double tZ = T_locZ + *txAntennaHeight;
        double rX = R_locX+r1; 
        double rY = R_locY+r2;	
        double rZ = R_locZ + antennaHeight;
        cminfo->txAntennaHeight = tZ;
        cminfo->rxAntennaHeight = rZ;
        cminfo->nodeDist = sqrt((rX-tX)*(rX-tX) + (rY-tY)*(rY-tY) + (rZ-tZ)*(rZ-tZ));
        cminfo->L = L_;				// system loss
        cminfo->Pt = wphyinfo->TxPr_; 		// tx power (watt)
        cminfo->Gt = txGain;			// tx gain (dbi)
        cminfo->Gr = rxGain;			// rx gain (dbi)
        cminfo->hbd = averageHB; 		// average heights of surrounding buildings (meter)
        cminfo->w = streetWidth;		// street width (meter)
        cminfo->d = averageDist; 		// average separation distance between the rows of buildings (meter)
        cminfo->pathlossExp_ = PLExp_;		// path loss exponent
        cminfo->std_db_ = std_db_;		// standard deviation
        cminfo->dist0_ = dist0_;		// close-in distance (meter)
 */


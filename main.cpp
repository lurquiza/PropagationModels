/* 
 * File:   main.cpp
 * Author: LuisUrquiza
 *
 * Created on 23 de abril de 2013, 17:03
 */

#include <cstdlib>
#include <iostream>
#include "CodeNCTUns/channel_Model.h"
#include"CodeNCTUns/cmInfo.h"
#include<list>
//#include <iomanip>
#include"inputs.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    bool repeat = 1;
    do {
        channelModel *propModel; // propagation channel model
        struct cmInfo *cminfo; // channel model information
        cminfo = (struct cmInfo *) malloc(sizeof (struct cmInfo));
        assert(cminfo);
        //free(cminfo);


        Dump_CM_List(cminfo); // index of the propagation channel model
        propModel = new channelModel(Create_PM()*1e6); //Create propagation channel model
        Dump_GDM_List(cminfo); //General Data model 
        Dump_FM_List(cminfo); //Fading model selection
        /* channel model power function */
        Dump_Results(propModel, cminfo);
        ShowCarrierSenseDistance(propModel, cminfo);
        ShowPtxAtDistance(propModel, cminfo);
        cout << "Do you want to do a new calculus (1 Yes 0 No)\t";
        cin>>repeat;
        //system("cls");
        free(propModel);
        free(cminfo);
    } while (repeat != 0);

    /*

	
 
        
        
            propModel = new channelModel((qcm->Freq) * 1e6);

                    assert(propModel);

                    if((qcm->TxAGPOpt) == 1){
                            parseAGPFile((qcm->TxAGPFileName), txGainUser);
                    }
                    if((qcm->RxAGPOpt) == 1){
                            parseAGPFile((qcm->RxAGPFileName), rxGainUser);
                    }

                    cminfo->PropModel = qcm->PropModel;
                    cminfo->txNid = qcm->TxNid;
                    cminfo->rxNid = qcm->RxNid;
                    cminfo->fadingOpt_ = qcm->FadingOpt;
                    cminfo->fv = qcm->FadingVar;
                    cminfo->RiceanK = qcm->RiceanK; // db
                    cminfo->txAntennaHeight = qcm->TxAntennaHeight;
                    cminfo->rxAntennaHeight = qcm->RxAntennaHeight;
                    cminfo->nodeDist = qcm->DTR;
                    cminfo->L = qcm->SystemLoss;
                    cminfo->Pt = pow(10, (qcm->TransPower)/10) * 1e-3; // Watt
                    cminfo->Gt = Get_Antenna_Gain(qcm->TxAngle, qcm->TxBeamwidth, qcm->TxAGPOpt, txGainUser);
                    cminfo->Gr = Get_Antenna_Gain(qcm->RxAngle, qcm->RxBeamwidth, qcm->RxAGPOpt, rxGainUser);
                    cminfo->hbd = qcm->AverageBuildingHeight; // meter
                    cminfo->w = qcm->StreetWidth; // meter
                    cminfo->d = qcm->AverageBuildingDist; // meter 
                    cminfo->pathlossExp_ = qcm->PathLossExponent;
                    cminfo->std_db_ = qcm->StandardDeviation;
                    cminfo->dist0_ = qcm->CloseInDist;	// meter

                    // output the results to stdout
                    outcm->TxGain = cminfo->Gt;
                    outcm->RxGain = cminfo->Gr;
                    outcm->Dist = propModel->Calculate_Carrier_Sense_Dist(cminfo, qcm->CSThresh);
                    outcm->CRPT = propModel->Pr(cminfo); // Corresponding Received Power Threshold by DTR

                    cminfo->nodeDist = qcm->DIR_;
                    outcm->CCSPT = propModel->Pr(cminfo); // Corresponding Carrier Sense Power Threshold by DIR
                    writen(1, (char *)outcm, sizeof(struct CM_reply));
                    delete propModel;
 
    cout<<option<<endl;
     */

    return 0;

}


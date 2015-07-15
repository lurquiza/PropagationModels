/* 
 * File:   inputs.h
 * Author: LuisUrquiza
 *
 * Created on 24 de abril de 2013, 11:12
 */

#ifndef INPUTS_H
#define	INPUTS_H
#include "CodeNCTUns/channel_Model.h"

void Dump_CM_List(struct cmInfo *cminfo);
double Create_PM();
void Dump_FM_List(struct cmInfo *cminfo);
void Dump_GDM_List(struct cmInfo *cminfo);
void Dump_Results(channelModel *propModel, struct cmInfo *cminfo);
void ShowCarrierSenseDistance(channelModel *propModel, struct cmInfo *cminfo);
void ShowPtxAtDistance(channelModel *propModel, struct cmInfo *cminfo);
void PtxAtDistance(channelModel *propModel, struct cmInfo *cminfo);
#endif	/* INPUTS_H */


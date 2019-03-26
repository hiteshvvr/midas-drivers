/**********************************************************************************
 *
 * Name:  v2495.c
 * Created By:  HVRahangdale
 * Adapted from v1290N.c creaed by Vincent Sulkosky
 *
 * Contents: Midas driver file for Programmable logic unit V2495
 *
 * $Id$
 * *******************************************************************************/

#include <stdio.h>
#include <string.h>
#include "v2495.h"

/********************************************************************************/

WORD v2495_Read16(MVME_INTERFACE *mvme, DWORD base, int offset)
{
    mvme_set_am(mvme, MVME_AM_A32_ND);
    mvme_set_dmode(mvme, MVME_DMODE_D16);
    return mvme_read_value(mvme, base, offset);
} 

DWORD v2495_Read32(MVME_INTERFACE *mvme, DWORD base, int offset)
{
    mvme_set_am(mvme, MVME_AM_A32_ND);
    mvme_set_dmode(mvme, MVME_DMODE_D32);
    return mvme_read_value(mvme, base, offset);
}

void v2495_Write16(MVME_INTERFACE *mvme, DWORD base, int offset, WORD value)
{
  mvme_set_am(mvme, MVME_AM_A32_ND);
  mvme_set_dmode(mvme, MVME_DMODE_D16);
  mvme_write_value(mvme, base, offset, value);
}

void v2495_Write32(MVME_INTERFACE *mvme, DWORD base, int offset, WORD value)
{
  mvme_set_am(mvme, MVME_AM_A32_ND);
  mvme_set_dmode(mvme, MVME_DMODE_D32);
  mvme_write_value(mvme, base, offset, value);
}


void v2495_EarlyWindow(MVME_INTERFACE *mvme, DWORD base, WORD value)
{
  int cmode;
  
  mvme_get_dmode(mvme, &cmode);
  mvme_set_dmode(mvme, MVME_DMODE_D16);
  mvme_write_value(mvme, base, V2495_EARLY_WINDOW_W, value);
  mvme_set_dmode(mvme, cmode);
}

void v2495_LateWindow(MVME_INTERFACE *mvme, DWORD base, WORD value)
{
  int cmode;
  
  mvme_get_dmode(mvme, &cmode);
  mvme_set_dmode(mvme, MVME_DMODE_D16);
  mvme_write_value(mvme, base, V2495_LATE_WINDOW_W, value);
  mvme_set_dmode(mvme, cmode);
}

void v2495_FirmwareRevision(MVME_INTERFACE *mvme, DWORD base)
{
  int cmode, data=0;

  mvme_get_dmode(mvme, &cmode);
  mvme_set_dmode(mvme, MVME_DMODE_D16);
  data = mvme_read_value(mvme, base, V2495_FIRM_RV_RO);
  printf("FirmWare Revision: 0x%04x\n", data);
  mvme_set_dmode(mvme, cmode);
}

int v2495_GetValidEventRate(MVME_INTERFACE *mvme, DWORD base)
{
  return v2495_Read32(mvme, base, V2495_VALID_EVENT_FREQ); 
}

int v2495_GetElecRate(MVME_INTERFACE *mvme, DWORD base)
{
  return v2495_Read32(mvme, base, V2495_EN_EVENT_FREQ);
}

int v2495_GetIonRate(MVME_INTERFACE *mvme, DWORD base)
{
  return v2495_Read32(mvme, base, V2495_ION_EVENT_FREQ); 
}
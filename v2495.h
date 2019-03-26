/*********************************************************************************************
 *
 *
 * Name:    v2495.h
 * Created By: HVRahangdale
 *
 * Contents: Midas driver for Programmable logic unit V2495
 *
 * $Id$
 * *****************************************************************************************/


#include "mvmestd.h"

#ifndef V2495_INCLUDE_H
#define V2495_INCLUDE_H

#ifdef __cplusplus
extern "C" {
#endif
/* FPGA: Field Programmable Gate Array */
/* V2495 MAIN FPGA Addresses */






/* V2495 USER FPGA Addresses */

#define V2495_EARLY_WINDOW_W           (DWORD)       (0X1800)
#define V2495_LATE_WINDOW_W            (DWORD)       (0X1804)
#define V2495_FIRM_RV_RO               (DWORD)       (0x1838)
#define V2495_EN_EVENT_FREQ            (DWORD)       (0X18C0)
#define V2495_ION_EVENT_FREQ           (DWORD)       (0X18C4)
#define V2495_VALID_EVENT_FREQ         (DWORD)       (0X18C8)



/*Functions*/
WORD v2495_Read16(MVME_INTERFACE *mvme, DWORD base, int offset);
DWORD v2495_Read32(MVME_INTERFACE *mvme, DWORD base, int offset);
void v2495_Write16(MVME_INTERFACE *mvme, DWORD base, int offset, WORD value);
void v2495_Write32(MVME_INTERFACE *mvme, DWORD base, int offset, WORD value);
void v2495_EarlyWindow(MVME_INTERFACE *mvme, DWORD base, WORD value);
void v2495_LateWindow(MVME_INTERFACE *mvme, DWORD base, WORD value);
void v2495_FirmwareRevision(MVME_INTERFACE *mvme, DWORD base);
int v2495_GetValidEventRate(MVME_INTERFACE *mvme, DWORD base);
int v2495_GetElecRate(MVME_INTERFACE *mvme, DWORD base);
int v2495_GetIonRate(MVME_INTERFACE *mvme, DWORD base);


#ifdef __cplusplus
}
#endif
#endif // for line V2495_INCLUDE_H

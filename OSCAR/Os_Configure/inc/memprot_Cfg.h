#ifndef MEMPROT_CFG_H
#define MEMPROT_CFG_H
#include "task_Cfg.h"

/* OS Protection Area */
extern MemProtAreaType MemProtArea_OS[3];

extern MemProtAreaType MemStackArea[2];

extern MemProtAreaType MemProtArea_SysTask_core0[2];
extern MemProtAreaType MemProtArea_SysTask_core1[2];

extern MemProtAreaType MemProtArea_T001[2];
extern MemProtAreaType MemProtArea_T002[2];
extern MemProtAreaType MemProtArea_T003[2];
extern MemProtAreaType MemProtArea_T004[2];
extern MemProtAreaType MemProtArea_T005[2];
extern MemProtAreaType MemProtArea_T006[2];
extern MemProtAreaType MemProtArea_I002[2];
extern MemProtAreaType MemProtArea_I003[2];
extern MemProtAreaType MemProtArea_I005[2];
extern MemProtAreaType MemProtArea_I006[2];

extern MemProtAreaType MemProtArea_T101[2];
extern MemProtAreaType MemProtArea_T102[2];
extern MemProtAreaType MemProtArea_T103[2];
extern MemProtAreaType MemProtArea_T104[2];
extern MemProtAreaType MemProtArea_T105[2];
extern MemProtAreaType MemProtArea_T106[2];
extern MemProtAreaType MemProtArea_I102[2];
extern MemProtAreaType MemProtArea_I103[2];
extern MemProtAreaType MemProtArea_I105[2];
extern MemProtAreaType MemProtArea_I106[2];

extern MemProtAreaType MemProtArea_app_lion[2];
extern MemProtAreaType MemProtArea_app2[2];
extern MemProtAreaType MemProtArea_app3[2];
extern MemProtAreaType MemProtArea_app4[2];

#define PERI_COOL_ID 0
#define PERI_WOW_ID 1
#define PERI_HAHA_ID 2
#define PERI_FUN_ID 3
#define PERI_TRY_ID 4
#define OsPeriAreaID_INVALID 5
#define OsPeriAreaID_COUNT 5

extern OsPeriAreaInfoType OsPeriAreaInfoArr[OsPeriAreaID_COUNT];

#pragma section

#endif


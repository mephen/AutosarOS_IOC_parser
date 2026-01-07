/*==================[inclusions]=============================================*/
#include "isr_Cfg.h"
#include "task_Cfg.h"
#include "isr2.h"
#include "system.h"
#include "os.h"
#include "task.h"
#include "dr7f701527.dvf.h"
#include "scheduler.h"

extern int PrintText(char *TextArray);
extern int PrintText_R35(char *TextArray);

IsrConstType Isr_const_core0[ISR_ALL_COUNT_CORE0] = {
    {
        I002,
        ISR_CAT_2,
        10,//uint8 ISRprio;
        44,//uint16 ISRchannel;
        (I002 + TASKS_COUNT_CORE0 - 1),       //TaskType ISR2TaskRefIndex;
    },
    {
        I003,
        ISR_CAT_2,
        3,//uint8 ISRprio;
        93,//uint16 ISRchannel;
        (I003 + TASKS_COUNT_CORE0 - 1),       //TaskType ISR2TaskRefIndex;
    },
    {
        I005,
        ISR_CAT_2,
        12,//uint8 ISRprio;
        94,//uint16 ISRchannel;
        (I005 + TASKS_COUNT_CORE0 - 1),       //TaskType ISR2TaskRefIndex;
    },
    {
        I006,
        ISR_CAT_2,
        13,//uint8 ISRprio;
        95,//uint16 ISRchannel;
        (I006 + TASKS_COUNT_CORE0 - 1),       //TaskType ISR2TaskRefIndex;
    },
    {
        I001,
        ISR_CAT_1,
        2,//uint8 ISRprio;
        43,//uint16 ISRchannel;
        0,       //TaskType ISR2TaskRefIndex;
    },
    {
        I004,
        ISR_CAT_1,
        4,//uint8 ISRprio;
        69,//uint16 ISRchannel;
        0,       //TaskType ISR2TaskRefIndex;
    },
};
IsrConstType Isr_const_core1[ISR_ALL_COUNT_CORE1] = {
    {
        I102,
        ISR_CAT_2,
        10,//uint8 ISRprio;
        129,//uint16 ISRchannel;
        (I102 + TASKS_COUNT_CORE1 - 1),       //TaskType ISR2TaskRefIndex;
    },
    {
        I103,
        ISR_CAT_2,
        11,//uint8 ISRprio;
        130,//uint16 ISRchannel;
        (I103 + TASKS_COUNT_CORE1 - 1),       //TaskType ISR2TaskRefIndex;
    },
    {
        I105,
        ISR_CAT_2,
        12,//uint8 ISRprio;
        187,//uint16 ISRchannel;
        (I105 + TASKS_COUNT_CORE1 - 1),       //TaskType ISR2TaskRefIndex;
    },
    {
        I106,
        ISR_CAT_2,
        13,//uint8 ISRprio;
        188,//uint16 ISRchannel;
        (I106 + TASKS_COUNT_CORE1 - 1),       //TaskType ISR2TaskRefIndex;
    },
    {
        I101,
        ISR_CAT_1,
        2,//uint8 ISRprio;
        128,//uint16 ISRchannel;
        0,       //TaskType ISR2TaskRefIndex;
    },
    {
        I104,
        ISR_CAT_1,
        3,//uint8 ISRprio;
        186,//uint16 ISRchannel;
        0,       //TaskType ISR2TaskRefIndex;
    },
};
IsrConstRefType Isr_const[OsNumberOfCores] = {
    Isr_const_core0,
    Isr_const_core1,
};
IsrAutosarType IsrAutosar_core0[ISR_ALL_COUNT_CORE0] = {
    //I002
    {
        app_lion,
        0 | (1 << app_lion) | (1 << app2) ,
    },
    //I003
    {
        app_lion,
        0 | (1 << app_lion) | (1 << app2) ,
    },
    //I005
    {
        app3,
        0 | (1 << app_lion) | (1 << app2) | (1 << app3) | (1 << app4) ,
    },
    //I006
    {
        app3,
        0 | (1 << app_lion) | (1 << app2) | (1 << app3) | (1 << app4) ,
    },
    //I001
    {
        app_lion,
        0 | (1 << app_lion) | (1 << app2) ,
    },
    //I004
    {
        app_lion,
        0 | (1 << app_lion) | (1 << app2) ,
    },
};

IsrAutosarType IsrAutosar_core1[ISR_ALL_COUNT_CORE1] = {
    //I102
    {
        app2,
        0 | (1 << app_lion) | (1 << app2) ,
    },
    //I103
    {
        app2,
        0 | (1 << app_lion) | (1 << app2) ,
    },
    //I105
    {
        app4,
        0 | (1 << app_lion) | (1 << app2) | (1 << app3) | (1 << app4) ,
    },
    //I106
    {
        app4,
        0 | (1 << app_lion) | (1 << app2) | (1 << app3) | (1 << app4) ,
    },
    //I101
    {
        app2,
        0 | (1 << app_lion) | (1 << app2) ,
    },
    //I104
    {
        app2,
        0 | (1 << app_lion) | (1 << app2) ,
    },
};

/*==================[ISR launhcer]========================================*/
/* I002 launhcer*/
#pragma interrupt ISR_I002_LAUNCHER(enable = manual, channel = 44, callt = false, fpu = false)
void ISR_I002_LAUNCHER(void)
{
    DisableMPU();
    ActivateISR2(I002);
    EnableMPU();
}

/* I003 launhcer*/
#pragma interrupt ISR_I003_LAUNCHER(enable = manual, channel = 44, callt = false, fpu = false)
void ISR_I003_LAUNCHER(void)
{
    DisableMPU();
    ActivateISR2(I003);
    EnableMPU();
}

/* I005 launhcer*/
#pragma interrupt ISR_I005_LAUNCHER(enable = manual, channel = 44, callt = false, fpu = false)
void ISR_I005_LAUNCHER(void)
{
    DisableMPU();
    ActivateISR2(I005);
    EnableMPU();
}

/* I006 launhcer*/
#pragma interrupt ISR_I006_LAUNCHER(enable = manual, channel = 44, callt = false, fpu = false)
void ISR_I006_LAUNCHER(void)
{
    DisableMPU();
    ActivateISR2(I006);
    EnableMPU();
}

/* I001 launhcer*/
#pragma interrupt ISR_I001_LAUNCHER(enable = manual, channel = 44, callt = false, fpu = false)
void ISR_I001_LAUNCHER(void)
{
    DisableMPU();
    systemFlag |= IN_ISR1_HANDLER;
    MILKSHOP_ISR_I001();
    systemFlag &= ~IN_ISR1_HANDLER;
    EnableMPU();
}

/* I004 launhcer*/
#pragma interrupt ISR_I004_LAUNCHER(enable = manual, channel = 44, callt = false, fpu = false)
void ISR_I004_LAUNCHER(void)
{
    DisableMPU();
    systemFlag |= IN_ISR1_HANDLER;
    MILKSHOP_ISR_I004();
    systemFlag &= ~IN_ISR1_HANDLER;
    EnableMPU();
}

/* I102 launhcer*/
#pragma interrupt ISR_I102_LAUNCHER(enable = manual, channel = 44, callt = false, fpu = false)
void ISR_I102_LAUNCHER(void)
{
    DisableMPU();
    ActivateISR2(I102);
    EnableMPU();
}

/* I103 launhcer*/
#pragma interrupt ISR_I103_LAUNCHER(enable = manual, channel = 44, callt = false, fpu = false)
void ISR_I103_LAUNCHER(void)
{
    DisableMPU();
    ActivateISR2(I103);
    EnableMPU();
}

/* I105 launhcer*/
#pragma interrupt ISR_I105_LAUNCHER(enable = manual, channel = 44, callt = false, fpu = false)
void ISR_I105_LAUNCHER(void)
{
    DisableMPU();
    ActivateISR2(I105);
    EnableMPU();
}

/* I106 launhcer*/
#pragma interrupt ISR_I106_LAUNCHER(enable = manual, channel = 44, callt = false, fpu = false)
void ISR_I106_LAUNCHER(void)
{
    DisableMPU();
    ActivateISR2(I106);
    EnableMPU();
}

/* I101 launhcer*/
#pragma interrupt ISR_I101_LAUNCHER(enable = manual, channel = 44, callt = false, fpu = false)
void ISR_I101_LAUNCHER(void)
{
    DisableMPU();
    systemFlag |= IN_ISR1_HANDLER;
    MILKSHOP_ISR_I101();
    systemFlag &= ~IN_ISR1_HANDLER;
    EnableMPU();
}

/* I104 launhcer*/
#pragma interrupt ISR_I104_LAUNCHER(enable = manual, channel = 44, callt = false, fpu = false)
void ISR_I104_LAUNCHER(void)
{
    DisableMPU();
    systemFlag |= IN_ISR1_HANDLER;
    MILKSHOP_ISR_I104();
    systemFlag &= ~IN_ISR1_HANDLER;
    EnableMPU();
}


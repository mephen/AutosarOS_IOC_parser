/*==================[inclusions]=============================================*/
#include "alarm_Cfg.h"
#include "alarm.h"
#include "os_Cfg.h"
#include "task_Cfg.h"
#include "event_Cfg.h"
#include "counter.h"
#include "counter_Cfg.h"
#include "scheduleTable_Cfg.h"
#include "application_Cfg.h"
/*==================[declarations]=============================================*/
#pragma section

/* ScheduleTables */
//ST1;
//ST2;
//ST3;
ExpiryPointType expirypoints_ST1[EXPIRYPOINT_COUNT_ST1] = {
    {
        2, /*offset*/
        0, /*task start*/
        1, /*task end*/
        0, /*event start*/
        0, /*event end*/
        1, /*maxShorten*/
        1, /*maxLengthen*/
        NULL, /*next*/
    },
    {
        5, /*offset*/
        1, /*task start*/
        2, /*task end*/
        0, /*event start*/
        0, /*event end*/
        1, /*maxShorten*/
        1, /*maxLengthen*/
        NULL, /*next*/
    },
    {
        8, /*offset*/
        2, /*task start*/
        3, /*task end*/
        0, /*event start*/
        0, /*event end*/
        1, /*maxShorten*/
        1, /*maxLengthen*/
        NULL, /*next*/
    },
};
TaskType ST1_taskArray[3] = {
    T002,
    T003,
    T004,
};
ExpiryPointType expirypoints_ST2[EXPIRYPOINT_COUNT_ST2] = {
    {
        2, /*offset*/
        0, /*task start*/
        1, /*task end*/
        0, /*event start*/
        0, /*event end*/
        0, /*maxShorten*/
        0, /*maxLengthen*/
        NULL, /*next*/
    },
    {
        5, /*offset*/
        1, /*task start*/
        2, /*task end*/
        0, /*event start*/
        0, /*event end*/
        0, /*maxShorten*/
        0, /*maxLengthen*/
        NULL, /*next*/
    },
};
TaskType ST2_taskArray[2] = {
    T004,
    T005,
};
const ScheduleTableConstType ScheduleTableConst_core0[SCHEDULETABLE_COUNT_CORE0] = {
    {
        EXPLICIT, /*syncStrategy*/
        FALSE, /*repeating*/
        counter3, /*counter*/
        counter_ST1, /*syncCounter*/
        0, /*ExplicitPrecision*/
        3, /*EPAmount*/
        10, /*duration*/
        2, /*initOffset*/
        2, /*finalDelay*/
        alarm_ST1, /*callbackAlarm*/
        expirypoints_ST1, /*expiryPoints*/
        ST1_taskArray, /*taskArray*/
        NULL,
    },
    {
        NONE, /*syncStrategy*/
        FALSE, /*repeating*/
        counter3, /*counter*/
        DriveCounter, /*syncCounter*/
        0, /*ExplicitPrecision*/
        2, /*EPAmount*/
        7, /*duration*/
        2, /*initOffset*/
        2, /*finalDelay*/
        alarm_ST2, /*callbackAlarm*/
        expirypoints_ST2, /*expiryPoints*/
        ST2_taskArray, /*taskArray*/
        NULL,
    },
};
ScheduleTableVarType ScheduleTableVar_core0[SCHEDULETABLE_COUNT_CORE0] = {
    {
        SCHEDULETABLE_STOPPED, /*status*/
        0, /*deviation*/
        0, /*currentEPIndex*/
        SCHEDULETABLE_COUNT_CORE0 /*next*/
    },
    {
        SCHEDULETABLE_STOPPED, /*status*/
        0, /*deviation*/
        0, /*currentEPIndex*/
        SCHEDULETABLE_COUNT_CORE0 /*next*/
    },
};
ScheduleTableAutosarType ScheduleTableAutosar_core0[SCHEDULETABLE_COUNT_CORE0] = {
    /* ScheduleTable ST1 */
    {
        app_lion,
        0,    },
    /* ScheduleTable ST2 */
    {
        app_lion,
        0,    },
};
/* Brief Callback Declaration of Callback ExpiryPointCallbackFuncST1 */
DeclareCallback(ExpiryPointCallbackFuncST1);
/* Brief Callback Declaration of Callback ExpiryPointCallbackFuncST2 */
DeclareCallback(ExpiryPointCallbackFuncST2);
ExpiryPointType expirypoints_ST3[EXPIRYPOINT_COUNT_ST3] = {
    {
        30, /*offset*/
        0, /*task start*/
        1, /*task end*/
        0, /*event start*/
        0, /*event end*/
        2, /*maxShorten*/
        5, /*maxLengthen*/
        NULL, /*next*/
    },
    {
        31, /*offset*/
        1, /*task start*/
        2, /*task end*/
        0, /*event start*/
        0, /*event end*/
        4, /*maxShorten*/
        3, /*maxLengthen*/
        NULL, /*next*/
    },
};
TaskType ST3_taskArray[2] = {
    T106,
    T102,
};
const ScheduleTableConstType ScheduleTableConst_core1[SCHEDULETABLE_COUNT_CORE1] = {
    {
        EXPLICIT, /*syncStrategy*/
        TRUE, /*repeating*/
        counter1, /*counter*/
        counter_ST3, /*syncCounter*/
        2, /*ExplicitPrecision*/
        2, /*EPAmount*/
        50, /*duration*/
        30, /*initOffset*/
        19, /*finalDelay*/
        alarm_ST3, /*callbackAlarm*/
        expirypoints_ST3, /*expiryPoints*/
        ST3_taskArray, /*taskArray*/
        NULL,
    },
};
ScheduleTableVarType ScheduleTableVar_core1[SCHEDULETABLE_COUNT_CORE1] = {
    {
        SCHEDULETABLE_STOPPED, /*status*/
        0, /*deviation*/
        0, /*currentEPIndex*/
        SCHEDULETABLE_COUNT_CORE1 /*next*/
    },
};
ScheduleTableAutosarType ScheduleTableAutosar_core1[SCHEDULETABLE_COUNT_CORE1] = {
    /* ScheduleTable ST3 */
    {
        0,    },
};
/* Brief Callback Declaration of Callback ExpiryPointCallbackFuncST3 */
DeclareCallback(ExpiryPointCallbackFuncST3);

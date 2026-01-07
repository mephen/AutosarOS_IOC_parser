/*==================[inclusions]=============================================*/
#include "application_Cfg.h"
#include "task_Cfg.h"
#include "os_Cfg.h"
#include "alarm_Cfg.h"
#include "counter.h"
#include "scheduletable_Cfg.h"
#include "isr_Cfg.h"
#include "trustedFunc_Cfg.h"
#include "memsection.h"
#include "memprot_Cfg.h"
#include "resource_Cfg.h"
/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[external functions declaration]=========================*/

/* Brief per-OsApp Hook */
extern void StartupHook_OSAPP_app_lion(void);
extern void ShutdownHook_OSAPP_app_lion(StatusType Error);
extern void ErrorHook_OSAPP_app_lion(StatusType Error);

extern void StartupHook_OSAPP_app2(void);
extern void ShutdownHook_OSAPP_app2(StatusType Error);
extern void ErrorHook_OSAPP_app2(StatusType Error);

extern void StartupHook_OSAPP_app3(void);
extern void ShutdownHook_OSAPP_app3(StatusType Error);
extern void ErrorHook_OSAPP_app3(StatusType Error);

extern void StartupHook_OSAPP_app4(void);
extern void ShutdownHook_OSAPP_app4(StatusType Error);
extern void ErrorHook_OSAPP_app4(StatusType Error);

/*==================[internal data definition]===============================*/

#pragma section

#define ZERO_OBJECT_DUMMY_COUNT 1

#define TASKS_COUNT_app_lion 3
#define COUNTERS_COUNT_app_lion 2
#define ALARMS_COUNT_app_lion 4
#define SCHEDULETABLES_COUNT_app_lion 2
#define ISRS_COUNT_app_lion 4
#define TRUSTEDFUNC_COUNT_app_lion 3

#define TASKS_COUNT_app2 3
#define COUNTERS_COUNT_app2 2
#define ALARMS_COUNT_app2 2
#define SCHEDULETABLES_COUNT_app2 1
#define ISRS_COUNT_app2 4
#define TRUSTEDFUNC_COUNT_app2 2

#define TASKS_COUNT_app3 3
#define COUNTERS_COUNT_app3 1
#define ALARMS_COUNT_app3 0
#define SCHEDULETABLES_COUNT_app3 0
#define ISRS_COUNT_app3 2
#define TRUSTEDFUNC_COUNT_app3 0

#define TASKS_COUNT_app4 3
#define COUNTERS_COUNT_app4 1
#define ALARMS_COUNT_app4 0
#define SCHEDULETABLES_COUNT_app4 0
#define ISRS_COUNT_app4 2
#define TRUSTEDFUNC_COUNT_app4 0

/* core0 */
/********[app_lion]*********/
TaskType Tasks_app_lion[TASKS_COUNT_app_lion] = {
    T001,
    T002,
    T003
};

CounterType Counters_app_lion[COUNTERS_COUNT_app_lion] = {
    counter3,
    counter_ST1,
};

AlarmType Alarms_app_lion[ALARMS_COUNT_app_lion] = {
    alarm3,
    alarm4,
    alarm_ST1,
    alarm_ST2,
};

ScheduleTableType ScheduleTables_app_lion[SCHEDULETABLES_COUNT_app_lion] = {
    ST1,
    ST2
};

ISRType Isrs_app_lion[ISRS_COUNT_app_lion] = {
    I001,
    I002,
    I003,
    I004
};

TrustedFunctionIndexType TrustedFunc_app_lion[TRUSTEDFUNC_COUNT_app_lion] = {
    TF_AIMER,
    TF_IKURA,
    TF_YORUSHIKA,
};

/********[app3]*********/
TaskType Tasks_app3[TASKS_COUNT_app3] = {
    T004,
    T005,
    T006
};

CounterType Counters_app3[COUNTERS_COUNT_app3] = {
    counter4,
};

AlarmType Alarms_app3[ZERO_OBJECT_DUMMY_COUNT] = {
    INVALID_ALARM_ID
};

ScheduleTableType ScheduleTables_app3[ZERO_OBJECT_DUMMY_COUNT] = {
    INVALID_SCHEDULETABLE_ID
};

ISRType Isrs_app3[ISRS_COUNT_app3] = {
    I005,
    I006
};

TrustedFunctionIndexType TrustedFunc_app3[ZERO_OBJECT_DUMMY_COUNT] = {
    INVALID_TF_ID
};

/* core1 */
/********[app2]*********/
TaskType Tasks_app2[TASKS_COUNT_app2] = {
    T101,
    T102,
    T103
};

CounterType Counters_app2[COUNTERS_COUNT_app2] = {
    counter1,
    counter_ST3,
};

AlarmType Alarms_app2[ALARMS_COUNT_app2] = {
    alarm1,
    alarm_ST3,
};

ScheduleTableType ScheduleTables_app2[SCHEDULETABLES_COUNT_app2] = {
    ST3
};

ISRType Isrs_app2[ISRS_COUNT_app2] = {
    I101,
    I102,
    I103,
    I104
};

TrustedFunctionIndexType TrustedFunc_app2[TRUSTEDFUNC_COUNT_app2] = {
    TF_YUURI,
    TF_HITORIE,
};

/********[app4]*********/
TaskType Tasks_app4[TASKS_COUNT_app4] = {
    T104,
    T105,
    T106
};

CounterType Counters_app4[COUNTERS_COUNT_app4] = {
    counter2,
};

AlarmType Alarms_app4[ZERO_OBJECT_DUMMY_COUNT] = {
    INVALID_ALARM_ID
};

ScheduleTableType ScheduleTables_app4[ZERO_OBJECT_DUMMY_COUNT] = {
    INVALID_SCHEDULETABLE_ID
};

ISRType Isrs_app4[ISRS_COUNT_app4] = {
    I105,
    I106
};

TrustedFunctionIndexType TrustedFunc_app4[ZERO_OBJECT_DUMMY_COUNT] = {
    INVALID_TF_ID
};

/*==================[external data definition]===============================*/
ApplicationObjectsType ApplicationObjects_core0[APPLICATIONS_COUNT_CORE0] = {
    /* app_lion */
    {
        /* Tasks */
        {
            Tasks_app_lion,
            TASKS_COUNT_app_lion
        },
        /* Counters */
        {
            Counters_app_lion,
            COUNTERS_COUNT_app_lion
        },
        /* Alarms */
        {
            Alarms_app_lion,
            ALARMS_COUNT_app_lion
        },
        /* ScheduleTables */
        {
            ScheduleTables_app_lion,
            SCHEDULETABLES_COUNT_app_lion
        },
        /* ISRs */
        {
            Isrs_app_lion,
            ISRS_COUNT_app_lion
        },
        /* TFs */
        {
            TrustedFunc_app_lion,
            TRUSTEDFUNC_COUNT_app_lion
        },
    },
    /* app3 */
    {
        /* Tasks */
        {
            Tasks_app3,
            TASKS_COUNT_app3
        },
        /* Counters */
        {
            Counters_app3,
            COUNTERS_COUNT_app3
        },
        /* Alarms */
        {
            Alarms_app3,
            ALARMS_COUNT_app3
        },
        /* ScheduleTables */
        {
            ScheduleTables_app3,
            SCHEDULETABLES_COUNT_app3
        },
        /* ISRs */
        {
            Isrs_app3,
            ISRS_COUNT_app3
        },
        /* TFs */
        {
            TrustedFunc_app3,
            TRUSTEDFUNC_COUNT_app3
        },
    },
};

ApplicationObjectsType ApplicationObjects_core1[APPLICATIONS_COUNT_CORE1] = {
    /* app2 */
    {
        /* Tasks */
        {
            Tasks_app2,
            TASKS_COUNT_app2
        },
        /* Counters */
        {
            Counters_app2,
            COUNTERS_COUNT_app2
        },
        /* Alarms */
        {
            Alarms_app2,
            ALARMS_COUNT_app2
        },
        /* ScheduleTables */
        {
            ScheduleTables_app2,
            SCHEDULETABLES_COUNT_app2
        },
        /* ISRs */
        {
            Isrs_app2,
            ISRS_COUNT_app2
        },
        /* TFs */
        {
            TrustedFunc_app2,
            TRUSTEDFUNC_COUNT_app2
        },
    },
    /* app4 */
    {
        /* Tasks */
        {
            Tasks_app4,
            TASKS_COUNT_app4
        },
        /* Counters */
        {
            Counters_app4,
            COUNTERS_COUNT_app4
        },
        /* Alarms */
        {
            Alarms_app4,
            ALARMS_COUNT_app4
        },
        /* ScheduleTables */
        {
            ScheduleTables_app4,
            SCHEDULETABLES_COUNT_app4
        },
        /* ISRs */
        {
            Isrs_app4,
            ISRS_COUNT_app4
        },
        /* TFs */
        {
            TrustedFunc_app4,
            TRUSTEDFUNC_COUNT_app4
        },
    },
};

ApplicationVarType ApplicationVar[APPLICATIONS_COUNT] = {
    /* Application app_lion */
    {
        app_lion,  //ID
        APPLICATION_ACCESSIBLE,
        TRUE,                    //OsTrustedType OsTrusted;
        ECUC_PARTITION_DEFAULT_ID,
        OS_CORE_ID_0,
        TRUE, //uint8 OsTrustedApplicationWithProtection
        FALSE, //OsTrustedAppWithTimingProt
        TRUE, //OsTrustedApplicationDelayTimingViolationCall, only truted-app care this
        T003, //RestartTask
        &ApplicationObjects_core0[0],
        //AppHookFuncArrayType AppHookFuncArray
        {
            StartupHook_OSAPP_app_lion,
            ShutdownHook_OSAPP_app_lion,
            ErrorHook_OSAPP_app_lion,
        },

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_SOSAPP_app_lion_SEC_data),
            (uint32*)(_EOSAPP_app_lion_SEC_data),
            (uint32*)(_SOSAPP_app_lion_SEC_data_R),
            (uint32*)(_SOSAPP_app_lion_SEC_bss),
            (uint32*)(_EOSAPP_app_lion_SEC_bss)
        },
        MemProtArea_app_lion,
        resourceapp_lion,
    },
    /* Application app2 */
    {
        app2,  //ID
        APPLICATION_ACCESSIBLE,
        TRUE,                    //OsTrustedType OsTrusted;
        ECUC_PARTITION_DEFAULT_ID,
        OS_CORE_ID_1,
        FALSE, //uint8 OsTrustedApplicationWithProtection
        FALSE, //OsTrustedAppWithTimingProt
        TRUE, //OsTrustedApplicationDelayTimingViolationCall, only truted-app care this
        T103, //RestartTask
        &ApplicationObjects_core1[0],
        //AppHookFuncArrayType AppHookFuncArray
        {
            StartupHook_OSAPP_app2,
            ShutdownHook_OSAPP_app2,
            ErrorHook_OSAPP_app2,
        },

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_SOSAPP_app2_SEC_data),
            (uint32*)(_EOSAPP_app2_SEC_data),
            (uint32*)(_SOSAPP_app2_SEC_data_R),
            (uint32*)(_SOSAPP_app2_SEC_bss),
            (uint32*)(_EOSAPP_app2_SEC_bss)
        },
        MemProtArea_app2,
        resourceapp2,
    },
    /* Application app3 */
    {
        app3,  //ID
        APPLICATION_ACCESSIBLE,
        TRUE,                    //OsTrustedType OsTrusted;
        ECUC_PARTITION_DEFAULT_ID,
        OS_CORE_ID_0,
        FALSE, //uint8 OsTrustedApplicationWithProtection
        FALSE, //OsTrustedAppWithTimingProt
        FALSE, //OsTrustedApplicationDelayTimingViolationCall, only truted-app care this
        T006, //RestartTask
        &ApplicationObjects_core0[1],
        //AppHookFuncArrayType AppHookFuncArray
        {
            StartupHook_OSAPP_app3,
            ShutdownHook_OSAPP_app3,
            ErrorHook_OSAPP_app3,
        },

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_SOSAPP_app3_SEC_data),
            (uint32*)(_EOSAPP_app3_SEC_data),
            (uint32*)(_SOSAPP_app3_SEC_data_R),
            (uint32*)(_SOSAPP_app3_SEC_bss),
            (uint32*)(_EOSAPP_app3_SEC_bss)
        },
        MemProtArea_app3,
        resourceapp3,
    },
    /* Application app4 */
    {
        app4,  //ID
        APPLICATION_ACCESSIBLE,
        FALSE,                    //OsTrustedType OsTrusted;
        ECUC_PARTITION_DEFAULT_ID,
        OS_CORE_ID_1,
        FALSE, //uint8 OsTrustedApplicationWithProtection
        FALSE, //OsTrustedAppWithTimingProt
        FALSE, //OsTrustedApplicationDelayTimingViolationCall, only truted-app care this
        T106, //RestartTask
        &ApplicationObjects_core1[1],
        //AppHookFuncArrayType AppHookFuncArray
        {
            StartupHook_OSAPP_app4,
            ShutdownHook_OSAPP_app4,
            ErrorHook_OSAPP_app4,
        },

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_SOSAPP_app4_SEC_data),
            (uint32*)(_EOSAPP_app4_SEC_data),
            (uint32*)(_SOSAPP_app4_SEC_data_R),
            (uint32*)(_SOSAPP_app4_SEC_bss),
            (uint32*)(_EOSAPP_app4_SEC_bss)
        },
        MemProtArea_app4,
        resourceapp4,
    },
};
LockType lockForApplicationState[APPLICATIONS_COUNT];
/*==================[end of file]============================================*/
#pragma section

/*==================[inclusions]=============================================*/
#include "alarm_Cfg.h"
#include "os_Cfg.h"
#include "task_Cfg.h"
#include "event_Cfg.h"
#include "application_Cfg.h"
#include "counter_Cfg.h"
#include "scheduleTable_Cfg.h"
/*==================[external data declaration]==============================*/

#pragma section

/* Brief AlarmVar Array */
AlarmVarType AlarmVar_core0[ALARMS_COUNT_CORE0] = {
    /* Alarm alarm3 */
    {
        NULL, /* pointer to next AlarmVar */
        NULL, /* Pointer to previous AlarmVar */
        alarm3,
        0, /* Inactive */
        0, /* first absolute tick counts to expire */
        0, /* tick counts to repeat expire after first expire */
    },
    /* Alarm alarm4 */
    {
        NULL, /* pointer to next AlarmVar */
        NULL, /* Pointer to previous AlarmVar */
        alarm4,
        0, /* Inactive */
        0, /* first absolute tick counts to expire */
        0, /* tick counts to repeat expire after first expire */
    },
    /* Alarm alarm_ST1 */
    {
        NULL, /* pointer to next AlarmVar */
        NULL, /* Pointer to previous AlarmVar */
        alarm_ST1,
        0, /* Inactive */
        0, /* first absolute tick counts to expire */
        0, /* tick counts to repeat expire after first expire */
    },
    /* Alarm alarm_ST2 */
    {
        NULL, /* pointer to next AlarmVar */
        NULL, /* Pointer to previous AlarmVar */
        alarm_ST2,
        0, /* Inactive */
        0, /* first absolute tick counts to expire */
        0, /* tick counts to repeat expire after first expire */
    }
};
/* Brief AlarmVar Array */
AlarmVarType AlarmVar_core1[ALARMS_COUNT_CORE1] = {
    /* Alarm alarm1 */
    {
        NULL, /* pointer to next AlarmVar */
        NULL, /* Pointer to previous AlarmVar */
        alarm1,
        0, /* Inactive */
        0, /* first absolute tick counts to expire */
        0 /* tick counts to repeat expire after first expire */
    },
    /* Alarm alarm_ST3 */
    {
        NULL, /* pointer to next AlarmVar */
        NULL, /* Pointer to previous AlarmVar */
        alarm_ST3,
        0, /* Inactive */
        0, /* first absolute tick counts to expire */
        0 /* tick counts to repeat expire after first expire */
    }
};
/* Brief AlarmConst Array */
const AlarmConstType AlarmConst_core0[ALARMS_COUNT_CORE0] = {
    /* Alarm alarm3 */
    {
        counter4, /*counter ID */
        ACTIVATETASK, /* alarm action */
        {
            0, /* no callback */
            T005, /* TaskID */
            0, /* no event */
            0, /* no counter */
            0 /* no schduletable */
        }
    },
    /* Alarm alarm4 */
    {
        counter4, /*counter ID */
        ACTIVATETASK, /* alarm action */
        {
            0, /* no callback */
            T104, /* TaskID */
            0, /* no event */
            0, /* no counter */
            0 /* no schduletable */
        }
    },
    /* Alarm alarm_ST1 */
    {
        counter3, /*counter*/
        EPCALLBACK, /* alarm action */
        {
            0, /* no callback */
            0, /* no task */
            0, /* no event */
            0, /* no counter */
            ST1 /* schduletable */
        }
    },
    /* Alarm alarm_ST2 */
    {
        counter3, /*counter*/
        EPCALLBACK, /* alarm action */
        {
            0, /* no callback */
            0, /* no task */
            0, /* no event */
            0, /* no counter */
            ST2 /* schduletable */
        }
    },
};

/* Brief AlarmConst Array */
const AlarmConstType AlarmConst_core1[ALARMS_COUNT_CORE1] = {
    /* Alarm alarm1 */
    {
        counter1, /*counter ID */
        ACTIVATETASK, /* alarm action */
        {
            NULL, /* no callback */
            T101, /* TaskID */
            0, /* no event */
            0, /* no counter */
            0 /* no schduletable */
        }
    },
    /* Alarm alarm_ST3 */
    {
        counter1, /*counter*/
        EPCALLBACK, /* alarm action */
        {
            0, /* no callback */
            0, /* no task */
            0, /* no event */
            0, /* no counter */
            ST3 /* schduletable */
        }
    },
};

AlarmAutosarType AlarmAutosar_core0[ALARMS_COUNT_CORE0] = {
    /* Alarm alarm3 */
    {
        app_lion,
        0 | (1 << app_lion) 
    },
    /* Alarm alarm4 */
    {
        app_lion,
        0 | (1 << app2) | (1 << app_lion) 
    },
    /* Alarm alarm_ST1 */
    {
        app_lion,
        0,    },
    /* Alarm alarm_ST2 */
    {
        app_lion,
        0,    },
};
AlarmAutosarType AlarmAutosar_core1[ALARMS_COUNT_CORE1] = {
    /* Alarm alarm1 */
    {
        app2,
        0
    },
    /* Alarm alarm_ST3 */
    {
        app2,
        0,    },
};
#pragma section

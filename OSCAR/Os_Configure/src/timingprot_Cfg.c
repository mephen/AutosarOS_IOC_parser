#include "typedefine.h"
#include "timingprot_Cfg.h"

#pragma section

/** core 0 **/
TimingProtCounterType TaskExecutingCounter_core0[TASK_OBJECTS_COUNT_CORE0] = {
    /* Task IdleTask */
    {
        IDLETASKBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T001 */
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T002 */
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T003 */
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T004 */
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T005 */
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T006 */
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Isr I002 Task*/
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Isr I003 Task*/
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Isr I005 Task*/
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Isr I006 Task*/
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
};

TimingProtCounterType TaskArrivalCounter_core0[TASK_OBJECTS_COUNT_CORE0] ={
    /* Task IdleTask */
    {
        IDLETASKBUDGET, // ProtectionType
        1, // Bound
        1, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T001 */
    {
        TIMEFRAME, // ProtectionType
        21.0, // Bound
        21.0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T002 */
    {
        TIMEFRAME, // ProtectionType
        21.0, // Bound
        21.0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T003 */
    {
        TIMEFRAME, // ProtectionType
        10000, // Bound
        10000, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T004 */
    {
        TIMEFRAME, // ProtectionType
        21.0, // Bound
        21.0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T005 */
    {
        TIMEFRAME, // ProtectionType
        21.0, // Bound
        21.0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T006 */
    {
        TIMEFRAME, // ProtectionType
        10000, // Bound
        10000, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Isr I002 Task*/
    {
        TIMEFRAME, // ProtectionType
        10000, // Bound
        10000, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Isr I003 Task*/
    {
        TIMEFRAME, // ProtectionType
        10000, // Bound
        10000, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Isr I005 Task*/
    {
        TIMEFRAME, // ProtectionType
        10000, // Bound
        10000, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Isr I006 Task*/
    {
        TIMEFRAME, // ProtectionType
        1.02, // Bound
        1.02, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
};

TimingProtCounterType ResourceTimingCounter_core0[RESOURCES_COUNT_CORE0];
TimingProtCounterType InterruptTimingCounter_core0[3];

const LockBudgetType LockBudget_T001[3] = {
    /* All Interrupt */
    {
        0,
        10
    },
    /* OS Interrupt */
    {
        1,
        10
    },
    /* resource resourceapp_lion */
    {
        resourceapp_lion,
        99999
    },
};
const LockBudgetType LockBudget_T002[3] = {
    /* All Interrupt */
    {
        0,
        10
    },
    /* OS Interrupt */
    {
        1,
        10
    },
    /* resource resourceapp_lion */
    {
        resourceapp_lion,
        99999
    },
};
const LockBudgetType LockBudget_T003[3] = {
    /* All Interrupt */
    {
        0,
        10000
    },
    /* OS Interrupt */
    {
        1,
        10000
    },
    /* resource resourceapp_lion */
    {
        resourceapp_lion,
        99999
    },
};
const LockBudgetType LockBudget_T004[3] = {
    /* All Interrupt */
    {
        0,
        20
    },
    /* OS Interrupt */
    {
        1,
        20
    },
    /* resource resourceapp3 */
    {
        resourceapp3,
        99999
    },
};
const LockBudgetType LockBudget_T005[6] = {
    /* All Interrupt */
    {
        0,
        30
    },
    /* OS Interrupt */
    {
        1,
        30
    },
    /* resource resource1 */
    {
        resource1,
        30,
    },
    /* resource resource2 */
    {
        resource2,
        30,
    },
    /* resource resource3 */
    {
        resource3,
        10,
    },
    /* resource resourceapp3 */
    {
        resourceapp3,
        99999
    },
};
const LockBudgetType LockBudget_T006[3] = {
    /* All Interrupt */
    {
        0,
        10000
    },
    /* OS Interrupt */
    {
        1,
        10000
    },
    /* resource resourceapp3 */
    {
        resourceapp3,
        99999
    },
};
const LockBudgetType LockBudget_I002[3] = {
    /* All Interrupt */
    {
        0,
        10000
    },
    /* OS Interrupt */
    {
        1,
        10000
    },
    /* resource resourceapp_lion */
    {
        resourceapp_lion,
        99999
    },
};
const LockBudgetType LockBudget_I003[3] = {
    /* All Interrupt */
    {
        0,
        10000
    },
    /* OS Interrupt */
    {
        1,
        10000
    },
    /* resource resourceapp_lion */
    {
        resourceapp_lion,
        99999
    },
};
const LockBudgetType LockBudget_I005[3] = {
    /* All Interrupt */
    {
        0,
        10000
    },
    /* OS Interrupt */
    {
        1,
        10000
    },
    /* resource resourceapp3 */
    {
        resourceapp3,
        99999
    },
};
const LockBudgetType LockBudget_I006[6] = {
    /* All Interrupt */
    {
        0,
        0.03
    },
    /* OS Interrupt */
    {
        1,
        0.03
    },
    /* resource resource4 */
    {
        resource4,
        0.03,
    },
    /* resource resource5 */
    {
        resource5,
        0.03,
    },
    /* resource resource6 */
    {
        resource6,
        0.01,
    },
    /* resource resourceapp3 */
    {
        resourceapp3,
        99999
    },
};
const TimingProtBudgetType TimingProtBudget_core0[TASK_OBJECTS_COUNT_CORE0] = {
    /* idle task */
    {
        999, /* ExecuteBudget */
        1, /* TimeFrame */
        NULL /* LockBudgetRef */
    },
    /* Task_T001 */
    {
        50000, /* ExecuteBudget */
        20, /* TimeFrame */
        LockBudget_T001 /* LockBudgetRef */
    },
    /* Task_T002 */
    {
        50000, /* ExecuteBudget */
        20, /* TimeFrame */
        LockBudget_T002 /* LockBudgetRef */
    },
    /* Task_T003 */
    {
        999, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_T003 /* LockBudgetRef */
    },
    /* Task_T004 */
    {
        3, /* ExecuteBudget */
        20, /* TimeFrame */
        LockBudget_T004 /* LockBudgetRef */
    },
    /* Task_T005 */
    {
        100, /* ExecuteBudget */
        20, /* TimeFrame */
        LockBudget_T005 /* LockBudgetRef */
    },
    /* Task_T006 */
    {
        999, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_T006 /* LockBudgetRef */
    },
    /* isr I002 Task  */
    {
        999, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_I002 /* LockBudgetRef */
    },
    /* isr I003 Task  */
    {
        999, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_I003 /* LockBudgetRef */
    },
    /* isr I005 Task  */
    {
        999, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_I005 /* LockBudgetRef */
    },
    /* isr I006 Task  */
    {
        0.05, /* ExecuteBudget */
        0.02, /* TimeFrame */
        LockBudget_I006 /* LockBudgetRef */
    },
};

/** core 1 **/
TimingProtCounterType TaskExecutingCounter_core1[TASK_OBJECTS_COUNT_CORE1] = {
    /* Task IdleTask */
    {
        IDLETASKBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T101 */
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T102 */
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T103 */
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T104 */
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T105 */
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T106 */
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Isr I102 Task*/
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Isr I103 Task*/
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Isr I105 Task*/
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Isr I106 Task*/
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
};

TimingProtCounterType TaskArrivalCounter_core1[TASK_OBJECTS_COUNT_CORE1] ={
    /* Task IdleTask */
    {
        IDLETASKBUDGET, // ProtectionType
        1, // Bound
        1, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T101 */
    {
        TIMEFRAME, // ProtectionType
        21.0, // Bound
        21.0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T102 */
    {
        TIMEFRAME, // ProtectionType
        21.0, // Bound
        21.0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T103 */
    {
        TIMEFRAME, // ProtectionType
        10000, // Bound
        10000, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T104 */
    {
        TIMEFRAME, // ProtectionType
        10000, // Bound
        10000, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T105 */
    {
        TIMEFRAME, // ProtectionType
        10000, // Bound
        10000, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T106 */
    {
        TIMEFRAME, // ProtectionType
        10000, // Bound
        10000, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Isr I102 Task*/
    {
        TIMEFRAME, // ProtectionType
        10000, // Bound
        10000, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Isr I103 Task*/
    {
        TIMEFRAME, // ProtectionType
        10000, // Bound
        10000, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Isr I105 Task*/
    {
        TIMEFRAME, // ProtectionType
        10000, // Bound
        10000, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Isr I106 Task*/
    {
        TIMEFRAME, // ProtectionType
        10000, // Bound
        10000, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
};

TimingProtCounterType ResourceTimingCounter_core1[RESOURCES_COUNT_CORE1];
TimingProtCounterType InterruptTimingCounter_core1[3];

const LockBudgetType LockBudget_T101[3] = {
    /* All Interrupt */
    {
        0,
        10
    },
    /* OS Interrupt */
    {
        1,
        10
    },
    /* resource resourceapp2 */
    {
        resourceapp2,
        99999
    },
};
const LockBudgetType LockBudget_T102[3] = {
    /* All Interrupt */
    {
        0,
        10
    },
    /* OS Interrupt */
    {
        1,
        10
    },
    /* resource resourceapp2 */
    {
        resourceapp2,
        99999
    },
};
const LockBudgetType LockBudget_T103[3] = {
    /* All Interrupt */
    {
        0,
        10000
    },
    /* OS Interrupt */
    {
        1,
        10000
    },
    /* resource resourceapp2 */
    {
        resourceapp2,
        99999
    },
};
const LockBudgetType LockBudget_T104[3] = {
    /* All Interrupt */
    {
        0,
        10000
    },
    /* OS Interrupt */
    {
        1,
        10000
    },
    /* resource resourceapp4 */
    {
        resourceapp4,
        99999
    },
};
const LockBudgetType LockBudget_T105[3] = {
    /* All Interrupt */
    {
        0,
        10000
    },
    /* OS Interrupt */
    {
        1,
        10000
    },
    /* resource resourceapp4 */
    {
        resourceapp4,
        99999
    },
};
const LockBudgetType LockBudget_T106[3] = {
    /* All Interrupt */
    {
        0,
        10000
    },
    /* OS Interrupt */
    {
        1,
        10000
    },
    /* resource resourceapp4 */
    {
        resourceapp4,
        99999
    },
};
const LockBudgetType LockBudget_I102[3] = {
    /* All Interrupt */
    {
        0,
        10000
    },
    /* OS Interrupt */
    {
        1,
        10000
    },
    /* resource resourceapp2 */
    {
        resourceapp2,
        99999
    },
};
const LockBudgetType LockBudget_I103[3] = {
    /* All Interrupt */
    {
        0,
        10000
    },
    /* OS Interrupt */
    {
        1,
        10000
    },
    /* resource resourceapp2 */
    {
        resourceapp2,
        99999
    },
};
const LockBudgetType LockBudget_I105[3] = {
    /* All Interrupt */
    {
        0,
        10000
    },
    /* OS Interrupt */
    {
        1,
        10000
    },
    /* resource resourceapp4 */
    {
        resourceapp4,
        99999
    },
};
const LockBudgetType LockBudget_I106[3] = {
    /* All Interrupt */
    {
        0,
        10000
    },
    /* OS Interrupt */
    {
        1,
        10000
    },
    /* resource resourceapp4 */
    {
        resourceapp4,
        99999
    },
};
const TimingProtBudgetType TimingProtBudget_core1[TASK_OBJECTS_COUNT_CORE1] = {
    /* idle task */
    {
        999, /* ExecuteBudget */
        1, /* TimeFrame */
        NULL /* LockBudgetRef */
    },
    /* Task_T101 */
    {
        50000, /* ExecuteBudget */
        20, /* TimeFrame */
        LockBudget_T101 /* LockBudgetRef */
    },
    /* Task_T102 */
    {
        50000, /* ExecuteBudget */
        20, /* TimeFrame */
        LockBudget_T102 /* LockBudgetRef */
    },
    /* Task_T103 */
    {
        10000, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_T103 /* LockBudgetRef */
    },
    /* Task_T104 */
    {
        10000, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_T104 /* LockBudgetRef */
    },
    /* Task_T105 */
    {
        10000, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_T105 /* LockBudgetRef */
    },
    /* Task_T106 */
    {
        10000, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_T106 /* LockBudgetRef */
    },
    /* isr I102 Task  */
    {
        10000, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_I102 /* LockBudgetRef */
    },
    /* isr I103 Task  */
    {
        10000, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_I103 /* LockBudgetRef */
    },
    /* isr I105 Task  */
    {
        10000, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_I105 /* LockBudgetRef */
    },
    /* isr I106 Task  */
    {
        10000, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_I106 /* LockBudgetRef */
    },
};

/** system **/

TimingProtCounterType *TimingCounterList[OsNumberOfCores];
SystemTimingCounterType SystemTimingCounter[OsNumberOfCores] = {
    /* Core 0 */
    {
        TaskExecutingCounter_core0,
        TaskArrivalCounter_core0,
        ResourceTimingCounter_core0,
        InterruptTimingCounter_core0,
        TimingProtBudget_core0
    },
    /* Core 1 */
    {
        TaskExecutingCounter_core1,
        TaskArrivalCounter_core1,
        ResourceTimingCounter_core1,
        InterruptTimingCounter_core1,
        TimingProtBudget_core1
    }
};

#pragma section

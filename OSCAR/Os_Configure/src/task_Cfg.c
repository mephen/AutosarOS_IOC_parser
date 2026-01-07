/*==================[inclusions]=============================================*/
#include "task_Cfg.h"
#include "event_Cfg.h"
#include "application_Cfg.h"
#include "spinlock_Cfg.h"
#include "memsection.h"
#include "memprot_Cfg.h"

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/* core 0 */
#pragma section ALL_TASK_ISR_STACK_PE1
/* Brief idle task stack */
uint8 StackTaskIdleTask_core0[StackTaskIdleTask_core0_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief sys task stack */
uint8 StackTaskSysTask_core0[StackTaskSysTask_core0_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief T001 stack */
uint8 StackTaskT001[ StackTaskT001_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief T002 stack */
uint8 StackTaskT002[ StackTaskT002_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief T003 stack */
uint8 StackTaskT003[ StackTaskT003_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief T004 stack */
uint8 StackTaskT004[ StackTaskT004_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief T005 stack */
uint8 StackTaskT005[ StackTaskT005_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief T006 stack */
uint8 StackTaskT006[ StackTaskT006_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief I002 stack */
uint8 StackIsr2TaskI002[StackIsr2TaskI002_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief I003 stack */
uint8 StackIsr2TaskI003[StackIsr2TaskI003_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief I005 stack */
uint8 StackIsr2TaskI005[StackIsr2TaskI005_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief I006 stack */
uint8 StackIsr2TaskI006[StackIsr2TaskI006_SIZE + STACK_MONITOR_APPEND_SIZE];

/* core 1 */
#pragma section ALL_TASK_ISR_STACK_PE2
/* Brief idle task stack */
uint8 StackTaskIdleTask_core1[StackTaskIdleTask_core1_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief sys task stack */
uint8 StackTaskSysTask_core1[StackTaskSysTask_core1_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief T101 stack */
uint8 StackTaskT101[ StackTaskT101_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief T102 stack */
uint8 StackTaskT102[ StackTaskT102_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief T103 stack */
uint8 StackTaskT103[ StackTaskT103_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief T104 stack */
uint8 StackTaskT104[ StackTaskT104_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief T105 stack */
uint8 StackTaskT105[ StackTaskT105_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief T106 stack */
uint8 StackTaskT106[ StackTaskT106_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief I102 stack */
uint8 StackIsr2TaskI102[StackIsr2TaskI102_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief I103 stack */
uint8 StackIsr2TaskI103[StackIsr2TaskI103_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief I105 stack */
uint8 StackIsr2TaskI105[StackIsr2TaskI105_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief I106 stack */
uint8 StackIsr2TaskI106[StackIsr2TaskI106_SIZE + STACK_MONITOR_APPEND_SIZE];

#pragma section
/* Brief idle task context */
TaskContextType ContextIdleTask_core0;
/* Brief sys task context */
TaskContextType ContextSysTask_core0;
/* Brief T001 context */
TaskContextType ContextT001;
/* Brief T002 context */
TaskContextType ContextT002;
/* Brief T003 context */
TaskContextType ContextT003;
/* Brief T004 context */
TaskContextType ContextT004;
/* Brief T005 context */
TaskContextType ContextT005;
/* Brief T006 context */
TaskContextType ContextT006;
/* Brief I002 context */
TaskContextType ContextI002;
/* Brief I003 context */
TaskContextType ContextI003;
/* Brief I005 context */
TaskContextType ContextI005;
/* Brief I006 context */
TaskContextType ContextI006;

TaskVarType *ReadyList_core0[READYLISTS_COUNT_CORE0];

TaskVarType *ReadyListTail_core0[READYLISTS_COUNT_CORE0];

/* Brief idle task context */
TaskContextType ContextIdleTask_core1;
/* Brief sys task context */
TaskContextType ContextSysTask_core1;
/* Brief T101 context */
TaskContextType ContextT101;
/* Brief T102 context */
TaskContextType ContextT102;
/* Brief T103 context */
TaskContextType ContextT103;
/* Brief T104 context */
TaskContextType ContextT104;
/* Brief T105 context */
TaskContextType ContextT105;
/* Brief T106 context */
TaskContextType ContextT106;
/* Brief I102 context */
TaskContextType ContextI102;
/* Brief I103 context */
TaskContextType ContextI103;
/* Brief I105 context */
TaskContextType ContextI105;
/* Brief I106 context */
TaskContextType ContextI106;

TaskVarType *ReadyList_core1[READYLISTS_COUNT_CORE1];

TaskVarType *ReadyListTail_core1[READYLISTS_COUNT_CORE1];

const TaskConstType TaskConst_core0[TASK_OBJECTS_COUNT_CORE0] = {
    /* Task IdleTask */
    {
        TASK_ENTRY(IdleTask),            /* task entry point */
        &ContextIdleTask_core0,          /* pointer to task context */
        StackTaskIdleTask_core0,         /* pointer to stack memory */
        StackTaskIdleTask_core0_SIZE + STACK_MONITOR_APPEND_SIZE,    /* stack size */
        IdleTask_core0,                  /* task id */
        {      /* task const flags */
            0, /* basic task */
            1, /* preemptive task */
            0  /* not isr2 task */
        },
        task_static_prio_idle_core0, /* task priority */
        1, /* task max activations */
        0, /* events mask */
        0,  /* resources mask */

        //RomToRamInitTableType RomToRamInitTable
        {
            0,  /* IdleTask special case */
            0,  /* IdleTask special case */
            0,  /* IdleTask special case */
            0,  /* IdleTask special case */
            0   /* IdleTask special case */
        }
    },
    /* Task T001 */
    {
        TASK_ENTRY(T001),            /* task entry point */
        &ContextT001, /* pointer to task context */
        StackTaskT001,    /* pointer to stack memory */
        StackTaskT001_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        T001, /* task id */
        {      /* task const flags */
            0, /* not extended task */
            1, /* preemptive task */
            0  /* not isr2 task */
        },
        task_static_prio_T001, /* task priority */
        55, /* task max activations */
        0,
        0 | (1 << (resource1 & 0xffff)) | (1 << (resourceapp_lion & 0xffff)), 

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_STASK_T001_SEC_data),
            (uint32*)(_ETASK_T001_SEC_data),
            (uint32*)(_STASK_T001_SEC_data_R),
            (uint32*)(_STASK_T001_SEC_bss),
            (uint32*)(_ETASK_T001_SEC_bss)
        }
    },
    /* Task T002 */
    {
        TASK_ENTRY(T002),            /* task entry point */
        &ContextT002, /* pointer to task context */
        StackTaskT002,    /* pointer to stack memory */
        StackTaskT002_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        T002, /* task id */
        {      /* task const flags */
            1, /* extended task */
            1, /* preemptive task */
            0  /* not isr2 task */
        },
        task_static_prio_T002, /* task priority */
        10, /* task max activations */
        0,
        0 | (1 << (resource1 & 0xffff)) | (1 << (resource2 & 0xffff)) | (1 << (resourceapp_lion & 0xffff)), 

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_STASK_T002_SEC_data),
            (uint32*)(_ETASK_T002_SEC_data),
            (uint32*)(_STASK_T002_SEC_data_R),
            (uint32*)(_STASK_T002_SEC_bss),
            (uint32*)(_ETASK_T002_SEC_bss)
        }
    },
    /* Task T003 */
    {
        TASK_ENTRY(T003),            /* task entry point */
        &ContextT003, /* pointer to task context */
        StackTaskT003,    /* pointer to stack memory */
        StackTaskT003_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        T003, /* task id */
        {      /* task const flags */
            0, /* not extended task */
            1, /* preemptive task */
            0  /* not isr2 task */
        },
        task_static_prio_T003, /* task priority */
        10, /* task max activations */
        0 | event3,
        0 | (1 << (resourceapp_lion & 0xffff)), 

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_STASK_T003_SEC_data),
            (uint32*)(_ETASK_T003_SEC_data),
            (uint32*)(_STASK_T003_SEC_data_R),
            (uint32*)(_STASK_T003_SEC_bss),
            (uint32*)(_ETASK_T003_SEC_bss)
        }
    },
    /* Task T004 */
    {
        TASK_ENTRY(T004),            /* task entry point */
        &ContextT004, /* pointer to task context */
        StackTaskT004,    /* pointer to stack memory */
        StackTaskT004_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        T004, /* task id */
        {      /* task const flags */
            1, /* extended task */
            1, /* preemptive task */
            0  /* not isr2 task */
        },
        task_static_prio_T004, /* task priority */
        10, /* task max activations */
        0,
        0 | (1 << (resource1 & 0xffff)) | (1 << (resource2 & 0xffff)) | (1 << (resourceapp3 & 0xffff)), 

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_STASK_T004_SEC_data),
            (uint32*)(_ETASK_T004_SEC_data),
            (uint32*)(_STASK_T004_SEC_data_R),
            (uint32*)(_STASK_T004_SEC_bss),
            (uint32*)(_ETASK_T004_SEC_bss)
        }
    },
    /* Task T005 */
    {
        TASK_ENTRY(T005),            /* task entry point */
        &ContextT005, /* pointer to task context */
        StackTaskT005,    /* pointer to stack memory */
        StackTaskT005_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        T005, /* task id */
        {      /* task const flags */
            0, /* not extended task */
            1, /* preemptive task */
            0  /* not isr2 task */
        },
        task_static_prio_T005, /* task priority */
        1, /* task max activations */
        0 | event3,
        0 | (1 << (resourceapp3 & 0xffff)), 

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_STASK_T005_SEC_data),
            (uint32*)(_ETASK_T005_SEC_data),
            (uint32*)(_STASK_T005_SEC_data_R),
            (uint32*)(_STASK_T005_SEC_bss),
            (uint32*)(_ETASK_T005_SEC_bss)
        }
    },
    /* Task T006 */
    {
        TASK_ENTRY(T006),            /* task entry point */
        &ContextT006, /* pointer to task context */
        StackTaskT006,    /* pointer to stack memory */
        StackTaskT006_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        T006, /* task id */
        {      /* task const flags */
            0, /* not extended task */
            1, /* preemptive task */
            0  /* not isr2 task */
        },
        task_static_prio_T006, /* task priority */
        10, /* task max activations */
        0,
        0 | (1 << (resource1 & 0xffff)) | (1 << (resource2 & 0xffff)) | (1 << (resourceapp3 & 0xffff)), 

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_STASK_T006_SEC_data),
            (uint32*)(_ETASK_T006_SEC_data),
            (uint32*)(_STASK_T006_SEC_data_R),
            (uint32*)(_STASK_T006_SEC_bss),
            (uint32*)(_ETASK_T006_SEC_bss)
        }
    },
    /* isr I002 Task */
    {
        ISR_ENTRY(I002),            /* task entry point */
        &ContextI002, /* pointer to task context */
        StackIsr2TaskI002,    /* pointer to stack memory */
        StackIsr2TaskI002_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        I002 + TASKS_COUNT_CORE0 -1 ,  /* isr2 task id */
        {      /* task const flags */
            0, /* not extended task */
            1, /* preemptive task */
            1  /* isr2 task */
        },
        task_static_prio_I002, /* task priority */
        255, /* task max activations */
        0, 
        0 | (1 << (resourceapp_lion & 0xffff)), 

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_SISR_I002_SEC_data),
            (uint32*)(_EISR_I002_SEC_data),
            (uint32*)(_SISR_I002_SEC_data_R),
            (uint32*)(_SISR_I002_SEC_bss),
            (uint32*)(_EISR_I002_SEC_bss)
        }
    },
    /* isr I003 Task */
    {
        ISR_ENTRY(I003),            /* task entry point */
        &ContextI003, /* pointer to task context */
        StackIsr2TaskI003,    /* pointer to stack memory */
        StackIsr2TaskI003_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        I003 + TASKS_COUNT_CORE0 -1 ,  /* isr2 task id */
        {      /* task const flags */
            0, /* not extended task */
            1, /* preemptive task */
            1  /* isr2 task */
        },
        task_static_prio_I003, /* task priority */
        255, /* task max activations */
        0, 
        0 | (1 << (resourceapp_lion & 0xffff)), 

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_SISR_I003_SEC_data),
            (uint32*)(_EISR_I003_SEC_data),
            (uint32*)(_SISR_I003_SEC_data_R),
            (uint32*)(_SISR_I003_SEC_bss),
            (uint32*)(_EISR_I003_SEC_bss)
        }
    },
    /* isr I005 Task */
    {
        ISR_ENTRY(I005),            /* task entry point */
        &ContextI005, /* pointer to task context */
        StackIsr2TaskI005,    /* pointer to stack memory */
        StackIsr2TaskI005_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        I005 + TASKS_COUNT_CORE0 -1 ,  /* isr2 task id */
        {      /* task const flags */
            0, /* not extended task */
            1, /* preemptive task */
            1  /* isr2 task */
        },
        task_static_prio_I005, /* task priority */
        255, /* task max activations */
        0, 
        0 | (1 << (resourceapp3 & 0xffff)), 

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_SISR_I005_SEC_data),
            (uint32*)(_EISR_I005_SEC_data),
            (uint32*)(_SISR_I005_SEC_data_R),
            (uint32*)(_SISR_I005_SEC_bss),
            (uint32*)(_EISR_I005_SEC_bss)
        }
    },
    /* isr I006 Task */
    {
        ISR_ENTRY(I006),            /* task entry point */
        &ContextI006, /* pointer to task context */
        StackIsr2TaskI006,    /* pointer to stack memory */
        StackIsr2TaskI006_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        I006 + TASKS_COUNT_CORE0 -1 ,  /* isr2 task id */
        {      /* task const flags */
            0, /* not extended task */
            1, /* preemptive task */
            1  /* isr2 task */
        },
        task_static_prio_I006, /* task priority */
        255, /* task max activations */
        0, 
        0 | (1 << (resourceapp3 & 0xffff)), 

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_SISR_I006_SEC_data),
            (uint32*)(_EISR_I006_SEC_data),
            (uint32*)(_SISR_I006_SEC_data_R),
            (uint32*)(_SISR_I006_SEC_bss),
            (uint32*)(_EISR_I006_SEC_bss)
        }
    },
    /* Task sysTask */
    {
        TASK_ENTRY(SysTask),            /* task entry point */
        &ContextSysTask_core0, /* pointer to task context */
        StackTaskSysTask_core0,    /* pointer to stack memory */
        StackTaskSysTask_core0_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        SysTask_core0,
        {      /* task const flags */
            0, /* not extended task */
            1, /* not preemptive task */
            0  /* not isr2 task */
        },
        task_static_prio_sys_core0, /* task priority */
        255, /* task max activations */
        0,
        0 | (1 << (resourceapp_lion & 0xffff)) | (1 << (resourceapp3 & 0xffff)), 

        //RomToRamInitTableType RomToRamInitTable
        {
            0,  /* SysTask special case */
            0,  /* SysTask special case */
            0,  /* SysTask special case */
            0,  /* SysTask special case */
            0,  /* SysTask special case */
        }
    },
};
const TaskConstType TaskConst_core1[TASK_OBJECTS_COUNT_CORE1] = {
    /* Task IdleTask */
    {
        TASK_ENTRY(IdleTask),            /* task entry point */
        &ContextIdleTask_core1,          /* pointer to task context */
        StackTaskIdleTask_core1,         /* pointer to stack memory */
        StackTaskIdleTask_core1_SIZE + STACK_MONITOR_APPEND_SIZE,    /* stack size */
        IdleTask_core1,                  /* task id */
        {      /* task const flags */
            0, /* basic task */
            1, /* preemptive task */
            0  /* not isr2 task */
        },
        task_static_prio_idle_core1, /* task priority */
        1, /* task max activations */
        0, /* events mask */
        0,  /* resources mask */

        //RomToRamInitTableType RomToRamInitTable
        {
            0,  /* IdleTask special case */
            0,  /* IdleTask special case */
            0,  /* IdleTask special case */
            0,  /* IdleTask special case */
            0   /* IdleTask special case */
        }
    },
    /* Task T101 */
    {
        TASK_ENTRY(T101),            /* task entry point */
        &ContextT101, /* pointer to task context */
        StackTaskT101,    /* pointer to stack memory */
        StackTaskT101_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        T101, /* task id */
        {      /* task const flags */
            1, /* extended task */
            1, /* preemptive task */
            0  /* not isr2 task */
        },
        task_static_prio_T101, /* task priority */
        10, /* task max activations */
        0,
        0 | (1 << (resource1 & 0xffff)) | (1 << (resource2 & 0xffff)) | (1 << (resourceapp2 & 0xffff)), 

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_STASK_T101_SEC_data),
            (uint32*)(_ETASK_T101_SEC_data),
            (uint32*)(_STASK_T101_SEC_data_R),
            (uint32*)(_STASK_T101_SEC_bss),
            (uint32*)(_ETASK_T101_SEC_bss)
        }
    },
    /* Task T102 */
    {
        TASK_ENTRY(T102),            /* task entry point */
        &ContextT102, /* pointer to task context */
        StackTaskT102,    /* pointer to stack memory */
        StackTaskT102_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        T102, /* task id */
        {      /* task const flags */
            0, /* not extended task */
            1, /* preemptive task */
            0  /* not isr2 task */
        },
        task_static_prio_T102, /* task priority */
        10, /* task max activations */
        0,
        0 | (1 << (resourceapp2 & 0xffff)), 

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_STASK_T102_SEC_data),
            (uint32*)(_ETASK_T102_SEC_data),
            (uint32*)(_STASK_T102_SEC_data_R),
            (uint32*)(_STASK_T102_SEC_bss),
            (uint32*)(_ETASK_T102_SEC_bss)
        }
    },
    /* Task T103 */
    {
        TASK_ENTRY(T103),            /* task entry point */
        &ContextT103, /* pointer to task context */
        StackTaskT103,    /* pointer to stack memory */
        StackTaskT103_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        T103, /* task id */
        {      /* task const flags */
            0, /* not extended task */
            1, /* preemptive task */
            0  /* not isr2 task */
        },
        task_static_prio_T103, /* task priority */
        10, /* task max activations */
        0,
        0 | (1 << (resourceapp2 & 0xffff)), 

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_STASK_T103_SEC_data),
            (uint32*)(_ETASK_T103_SEC_data),
            (uint32*)(_STASK_T103_SEC_data_R),
            (uint32*)(_STASK_T103_SEC_bss),
            (uint32*)(_ETASK_T103_SEC_bss)
        }
    },
    /* Task T104 */
    {
        TASK_ENTRY(T104),            /* task entry point */
        &ContextT104, /* pointer to task context */
        StackTaskT104,    /* pointer to stack memory */
        StackTaskT104_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        T104, /* task id */
        {      /* task const flags */
            0, /* not extended task */
            1, /* preemptive task */
            0  /* not isr2 task */
        },
        task_static_prio_T104, /* task priority */
        10, /* task max activations */
        0,
        0 | (1 << (resourceapp4 & 0xffff)), 

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_STASK_T104_SEC_data),
            (uint32*)(_ETASK_T104_SEC_data),
            (uint32*)(_STASK_T104_SEC_data_R),
            (uint32*)(_STASK_T104_SEC_bss),
            (uint32*)(_ETASK_T104_SEC_bss)
        }
    },
    /* Task T105 */
    {
        TASK_ENTRY(T105),            /* task entry point */
        &ContextT105, /* pointer to task context */
        StackTaskT105,    /* pointer to stack memory */
        StackTaskT105_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        T105, /* task id */
        {      /* task const flags */
            0, /* not extended task */
            1, /* preemptive task */
            0  /* not isr2 task */
        },
        task_static_prio_T105, /* task priority */
        10, /* task max activations */
        0,
        0 | (1 << (resourceapp4 & 0xffff)), 

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_STASK_T105_SEC_data),
            (uint32*)(_ETASK_T105_SEC_data),
            (uint32*)(_STASK_T105_SEC_data_R),
            (uint32*)(_STASK_T105_SEC_bss),
            (uint32*)(_ETASK_T105_SEC_bss)
        }
    },
    /* Task T106 */
    {
        TASK_ENTRY(T106),            /* task entry point */
        &ContextT106, /* pointer to task context */
        StackTaskT106,    /* pointer to stack memory */
        StackTaskT106_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        T106, /* task id */
        {      /* task const flags */
            0, /* not extended task */
            1, /* preemptive task */
            0  /* not isr2 task */
        },
        task_static_prio_T106, /* task priority */
        10, /* task max activations */
        0,
        0 | (1 << (resourceapp4 & 0xffff)), 

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_STASK_T106_SEC_data),
            (uint32*)(_ETASK_T106_SEC_data),
            (uint32*)(_STASK_T106_SEC_data_R),
            (uint32*)(_STASK_T106_SEC_bss),
            (uint32*)(_ETASK_T106_SEC_bss)
        }
    },
    /* isr I102 Task */
    {
        ISR_ENTRY(I102),            /* task entry point */
        &ContextI102, /* pointer to task context */
        StackIsr2TaskI102,    /* pointer to stack memory */
        StackIsr2TaskI102_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        I102 + TASKS_COUNT_CORE1 -1 ,  /* isr2 task id */
        {      /* task const flags */
            0, /* not extended task */
            1, /* preemptive task */
            1  /* isr2 task */
        },
        task_static_prio_I102, /* task priority */
        255, /* task max activations */
        0, 
        0 | (1 << (resourceapp2 & 0xffff)), 

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_SISR_I102_SEC_data),
            (uint32*)(_EISR_I102_SEC_data),
            (uint32*)(_SISR_I102_SEC_data_R),
            (uint32*)(_SISR_I102_SEC_bss),
            (uint32*)(_EISR_I102_SEC_bss)
        }
    },
    /* isr I103 Task */
    {
        ISR_ENTRY(I103),            /* task entry point */
        &ContextI103, /* pointer to task context */
        StackIsr2TaskI103,    /* pointer to stack memory */
        StackIsr2TaskI103_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        I103 + TASKS_COUNT_CORE1 -1 ,  /* isr2 task id */
        {      /* task const flags */
            0, /* not extended task */
            1, /* preemptive task */
            1  /* isr2 task */
        },
        task_static_prio_I103, /* task priority */
        255, /* task max activations */
        0, 
        0 | (1 << (resourceapp2 & 0xffff)), 

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_SISR_I103_SEC_data),
            (uint32*)(_EISR_I103_SEC_data),
            (uint32*)(_SISR_I103_SEC_data_R),
            (uint32*)(_SISR_I103_SEC_bss),
            (uint32*)(_EISR_I103_SEC_bss)
        }
    },
    /* isr I105 Task */
    {
        ISR_ENTRY(I105),            /* task entry point */
        &ContextI105, /* pointer to task context */
        StackIsr2TaskI105,    /* pointer to stack memory */
        StackIsr2TaskI105_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        I105 + TASKS_COUNT_CORE1 -1 ,  /* isr2 task id */
        {      /* task const flags */
            0, /* not extended task */
            1, /* preemptive task */
            1  /* isr2 task */
        },
        task_static_prio_I105, /* task priority */
        255, /* task max activations */
        0, 
        0 | (1 << (resourceapp4 & 0xffff)), 

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_SISR_I105_SEC_data),
            (uint32*)(_EISR_I105_SEC_data),
            (uint32*)(_SISR_I105_SEC_data_R),
            (uint32*)(_SISR_I105_SEC_bss),
            (uint32*)(_EISR_I105_SEC_bss)
        }
    },
    /* isr I106 Task */
    {
        ISR_ENTRY(I106),            /* task entry point */
        &ContextI106, /* pointer to task context */
        StackIsr2TaskI106,    /* pointer to stack memory */
        StackIsr2TaskI106_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        I106 + TASKS_COUNT_CORE1 -1 ,  /* isr2 task id */
        {      /* task const flags */
            0, /* not extended task */
            1, /* preemptive task */
            1  /* isr2 task */
        },
        task_static_prio_I106, /* task priority */
        255, /* task max activations */
        0, 
        0 | (1 << (resourceapp4 & 0xffff)), 

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_SISR_I106_SEC_data),
            (uint32*)(_EISR_I106_SEC_data),
            (uint32*)(_SISR_I106_SEC_data_R),
            (uint32*)(_SISR_I106_SEC_bss),
            (uint32*)(_EISR_I106_SEC_bss)
        }
    },
    /* Task sysTask */
    {
        TASK_ENTRY(SysTask),            /* task entry point */
        &ContextSysTask_core1, /* pointer to task context */
        StackTaskSysTask_core1,    /* pointer to stack memory */
        StackTaskSysTask_core1_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        SysTask_core1,
        {      /* task const flags */
            0, /* not extended task */
            1, /* not preemptive task */
            0  /* not isr2 task */
        },
        task_static_prio_sys_core1, /* task priority */
        255, /* task max activations */
        0,
        0 | (1 << (resourceapp2 & 0xffff)) | (1 << (resourceapp4 & 0xffff)), 

        //RomToRamInitTableType RomToRamInitTable
        {
            0,  /* SysTask special case */
            0,  /* SysTask special case */
            0,  /* SysTask special case */
            0,  /* SysTask special case */
            0,  /* SysTask special case */
        }
    },
};

TaskAutosarType TaskAutosar_core0[TASK_OBJECTS_COUNT_CORE0] = {
    /* Task IdleTask */
    {
        INVALID_OSAPPLICATION,
        0,
        INVALID_SPINLOCK,
        NULL
    },
    /* Task T001 */
    {
        app_lion,
        0 | (1 << app_lion) | (1 << app2) | (1 << app3) | (1 << app4), 
        INVALID_SPINLOCK,
        MemProtArea_T001 /* MemArea */
    },
    /* Task T002 */
    {
        app_lion,
        0 | (1 << app_lion) | (1 << app2) | (1 << app3) | (1 << app4), 
        INVALID_SPINLOCK,
        MemProtArea_T002 /* MemArea */
    },
    /* Task T003 */
    {
        app_lion,
        0 | (1 << app_lion) | (1 << app2) | (1 << app3) | (1 << app4), 
        INVALID_SPINLOCK,
        MemProtArea_T003 /* MemArea */
    },
    /* Task T004 */
    {
        app3,
        0 | (1 << app_lion) | (1 << app2) | (1 << app3) | (1 << app4), 
        INVALID_SPINLOCK,
        MemProtArea_T004 /* MemArea */
    },
    /* Task T005 */
    {
        app3,
        0 | (1 << app_lion) | (1 << app2) | (1 << app3) | (1 << app4), 
        INVALID_SPINLOCK,
        MemProtArea_T005 /* MemArea */
    },
    /* Task T006 */
    {
        app3,
        0 | (1 << app_lion) | (1 << app2) | (1 << app3) | (1 << app4), 
        INVALID_SPINLOCK,
        MemProtArea_T006 /* MemArea */
    },
    /* isrTask I002 */
    {
        app_lion,
        0 | (1 << app_lion),
        INVALID_SPINLOCK,
        MemProtArea_I002 /* MemArea */
    },
    /* isrTask I003 */
    {
        app_lion,
        0 | (1 << app_lion),
        INVALID_SPINLOCK,
        MemProtArea_I003 /* MemArea */
    },
    /* isrTask I005 */
    {
        app3,
        0 | (1 << app3),
        INVALID_SPINLOCK,
        MemProtArea_I005 /* MemArea */
    },
    /* isrTask I006 */
    {
        app3,
        0 | (1 << app3),
        INVALID_SPINLOCK,
        MemProtArea_I006 /* MemArea */
    },
    /* Task SysTask */
    {
        INVALID_OSAPPLICATION,
        0,
        INVALID_SPINLOCK,
        MemProtArea_SysTask_core0 /* MemArea */
    },
};

TaskAutosarType TaskAutosar_core1[TASK_OBJECTS_COUNT_CORE1] = {
    /* Task IdleTask */
    {
        INVALID_OSAPPLICATION,
        0,
        INVALID_SPINLOCK,
        NULL
    },
    /* Task T101 */
    {
        app2,
        0 | (1 << app_lion) | (1 << app2) | (1 << app3) | (1 << app4), 
        INVALID_SPINLOCK,
        MemProtArea_T101 /* MemArea */
    },
    /* Task T102 */
    {
        app2,
        0 | (1 << app_lion) | (1 << app2) | (1 << app3) | (1 << app4), 
        INVALID_SPINLOCK,
        MemProtArea_T102 /* MemArea */
    },
    /* Task T103 */
    {
        app2,
        0 | (1 << app_lion) | (1 << app2) | (1 << app3) | (1 << app4), 
        INVALID_SPINLOCK,
        MemProtArea_T103 /* MemArea */
    },
    /* Task T104 */
    {
        app4,
        0 | (1 << app_lion) | (1 << app2) | (1 << app3) | (1 << app4), 
        INVALID_SPINLOCK,
        MemProtArea_T104 /* MemArea */
    },
    /* Task T105 */
    {
        app4,
        0 | (1 << app_lion) | (1 << app2) | (1 << app3) | (1 << app4), 
        INVALID_SPINLOCK,
        MemProtArea_T105 /* MemArea */
    },
    /* Task T106 */
    {
        app4,
        0 | (1 << app_lion) | (1 << app2) | (1 << app3) | (1 << app4), 
        INVALID_SPINLOCK,
        MemProtArea_T106 /* MemArea */
    },
    /* isrTask I102 */
    {
        app2,
        0 | (1 << app2),
        INVALID_SPINLOCK,
        MemProtArea_I102 /* MemArea */
    },
    /* isrTask I103 */
    {
        app2,
        0 | (1 << app2),
        INVALID_SPINLOCK,
        MemProtArea_I103 /* MemArea */
    },
    /* isrTask I105 */
    {
        app4,
        0 | (1 << app4),
        INVALID_SPINLOCK,
        MemProtArea_I105 /* MemArea */
    },
    /* isrTask I106 */
    {
        app4,
        0 | (1 << app4),
        INVALID_SPINLOCK,
        MemProtArea_I106 /* MemArea */
    },
    /* Task SysTask */
    {
        INVALID_OSAPPLICATION,
        0,
        INVALID_SPINLOCK,
        MemProtArea_SysTask_core1 /* MemArea */
    },
};
TaskVarType TaskVar_core0[TASK_OBJECTS_COUNT_CORE0] = {
    /* Task IdleTask */
    {
        &TaskConst_core0[0], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_idle_core0,    /* task priority */
        0,    /* task state */
        NULL,  /* point to the internal resource */
    },
    /* Task T001 */
    {
        &TaskConst_core0[1], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_T001,
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app_lion, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* Task T002 */
    {
        &TaskConst_core0[2], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_T002,
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app_lion, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* Task T003 */
    {
        &TaskConst_core0[3], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_T003,
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app_lion, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* Task T004 */
    {
        &TaskConst_core0[4], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_T004,
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app3, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* Task T005 */
    {
        &TaskConst_core0[5], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_T005,
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app3, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* Task T006 */
    {
        &TaskConst_core0[6], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_T006,
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app3, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* IsrTask I002 */
    {
        &TaskConst_core0[7], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_I002,
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app_lion, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* IsrTask I003 */
    {
        &TaskConst_core0[8], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_I003,
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app_lion, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* IsrTask I005 */
    {
        &TaskConst_core0[9], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_I005,
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app3, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* IsrTask I006 */
    {
        &TaskConst_core0[10], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_I006,
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app3, /* the executing application id */
        0, /* nesting trust function count */
    },
/* Task SysTask */
    {
        &TaskConst_core0[11], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_sys_core0,    /* task priority */
        0,    /* task state */
        NULL  /* point to the internal resource */
    },
};
TaskVarType TaskVar_core1[TASK_OBJECTS_COUNT_CORE1] = {
    /* Task IdleTask */
    {
        &TaskConst_core1[0], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_idle_core1,    /* task priority */
        0,    /* task state */
        NULL,  /* point to the internal resource */
    },
    /* Task T101 */
    {
        &TaskConst_core1[1], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_T101,
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app2, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* Task T102 */
    {
        &TaskConst_core1[2], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_T102,
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app2, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* Task T103 */
    {
        &TaskConst_core1[3], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_T103,
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app2, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* Task T104 */
    {
        &TaskConst_core1[4], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_T104,
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app4, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* Task T105 */
    {
        &TaskConst_core1[5], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_T105,
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app4, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* Task T106 */
    {
        &TaskConst_core1[6], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_T106,
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app4, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* IsrTask I102 */
    {
        &TaskConst_core1[7], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_I102,
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app2, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* IsrTask I103 */
    {
        &TaskConst_core1[8], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_I103,
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app2, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* IsrTask I105 */
    {
        &TaskConst_core1[9], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_I105,
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app4, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* IsrTask I106 */
    {
        &TaskConst_core1[10], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_I106,
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app4, /* the executing application id */
        0, /* nesting trust function count */
    },
/* Task SysTask */
    {
        &TaskConst_core1[11], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_sys_core0,    /* task priority */
        0,    /* task state */
        NULL  /* point to the internal resource */
    },
};
/* brief List of Auto Start Tasks in Application Mode AppMode1 */
const TaskType TasksAutoStartAppMode1[TASK_AUTOSTART_AppMode1_COUNT]  = {
   T001,
   T002,
   T101,
   T102,
};
/* brief AutoStart Array */
const AutoStartType AutoStart[1]  = {
   /* Application Mode AppMode1 */
    {
        TASK_AUTOSTART_AppMode1_COUNT, /* Total Auto Start Tasks in this Application Mode */
        (TaskRefType)TasksAutoStartAppMode1 /* Pointer to the list of Auto Start Stacks on this Application Mode */
    },
};

TaskType SysTaskID[OsNumberOfCores] = {
    SysTask_core0,
    SysTask_core1,
};

#pragma section

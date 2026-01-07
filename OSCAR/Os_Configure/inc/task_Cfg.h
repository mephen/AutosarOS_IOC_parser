#ifndef TASK_CFG_H
#define TASK_CFG_H

/*==================[inclusions]=============================================*/
#include "typedefine.h"
#include "memprot.h"
#include "resource_Cfg.h"
#include "os_Cfg.h"
#include "isr_Cfg.h"
/*==================[macros]=================================================*/

/* Brief Count of all task(include extended task) */
/* The count includes basic/extended tasks and "1 idle" task, "1 sys" task (no isr2 task)*/
#define TASKS_COUNT_CORE0 8U
#define TASKS_COUNT_CORE1 8U
#define TASKS_COUNT 16U
/* Brief Count of extended task */
#define EXTENDED_TASKS_COUNT_CORE0 2U
#define EXTENDED_TASKS_COUNT_CORE1 1U
#define EXTENDED_TASKS_COUNT 3U
/* Brief Count of ISR2 task */
#define ISR2_TASKS_COUNT_CORE0 4U
#define ISR2_TASKS_COUNT_CORE1 4U
#define ISR2_TASKS_COUNT 8U
/* Brief Count of task object*/
/* Idle task, sys task, basic task, extended task, ISR2 task have task object*/
#define TASK_OBJECTS_COUNT_CORE0 12U
#define TASK_OBJECTS_COUNT_CORE1 12U
#define TASK_OBJECTS_COUNT 24U
/* core0 */
#define IdleTask_core0  0x00000000
#define T001             0x00000001
#define T002             0x00000002
#define T003             0x00000003
#define T004             0x00000004
#define T005             0x00000005
#define T006             0x00000006
#define SysTask_core0   0x0000000b

/* core1 */
#define IdleTask_core1  0x00010000
#define T101             0x00010001
#define T102             0x00010002
#define T103             0x00010003
#define T104             0x00010004
#define T105             0x00010005
#define T106             0x00010006
#define SysTask_core1   0x0001000b

#define INVALID_TASK_ID 0X00020010

#define StackTaskIdleTask_core0_SIZE 512
#define StackTaskSysTask_core0_SIZE 512
#define StackTaskT001_SIZE 512
#define StackTaskT002_SIZE 512
#define StackTaskT003_SIZE 512
#define StackTaskT004_SIZE 512
#define StackTaskT005_SIZE 512
#define StackTaskT006_SIZE 512
#define StackIsr2TaskI002_SIZE 512
#define StackIsr2TaskI003_SIZE 512
#define StackIsr2TaskI005_SIZE 512
#define StackIsr2TaskI006_SIZE 512


#define StackTaskIdleTask_core1_SIZE 512
#define StackTaskSysTask_core1_SIZE 512
#define StackTaskT101_SIZE 512
#define StackTaskT102_SIZE 512
#define StackTaskT103_SIZE 512
#define StackTaskT104_SIZE 512
#define StackTaskT105_SIZE 512
#define StackTaskT106_SIZE 512
#define StackIsr2TaskI102_SIZE 512
#define StackIsr2TaskI103_SIZE 512
#define StackIsr2TaskI105_SIZE 512
#define StackIsr2TaskI106_SIZE 512


#define task_static_prio_idle_core0 0
#define task_static_prio_T001 2
#define task_static_prio_T002 3
#define task_static_prio_T003 4
#define task_static_prio_T004 3
#define task_static_prio_T005 3
#define task_static_prio_T006 1
#define task_static_prio_I002 7
#define task_static_prio_I003 8
#define task_static_prio_I005 6
#define task_static_prio_I006 5
#define task_static_prio_sys_core0 9

#define task_static_prio_idle_core1 0
#define task_static_prio_T101 1
#define task_static_prio_T102 2
#define task_static_prio_T103 2
#define task_static_prio_T104 2
#define task_static_prio_T105 2
#define task_static_prio_T106 2
#define task_static_prio_I102 6
#define task_static_prio_I103 5
#define task_static_prio_I105 4
#define task_static_prio_I106 3
#define task_static_prio_sys_core1 7
/* Brief NON_PREEMPTIVE macro definition */
#define NON_PREEMPTIVE OSEK_DISABLE
/* Brief Count of priority */
#define NORMAL_TASK_PRIO_COUNT_CORE0 5  
#define NORMAL_TASK_PRIO_COUNT_CORE1 3  
#define ISR2_TASK_PRIO_COUNT_CORE0 4  
#define ISR2_TASK_PRIO_COUNT_CORE1 4  
/* Brief Count of all priority numbers, including idle and systask, so will "+1" */
#define READYLISTS_COUNT_CORE0 (NORMAL_TASK_PRIO_COUNT_CORE0 + ISR2_TASK_PRIO_COUNT_CORE0 +1)
#define READYLISTS_COUNT_CORE1 (NORMAL_TASK_PRIO_COUNT_CORE1 + ISR2_TASK_PRIO_COUNT_CORE1 +1)
/* brief TASK_AUTOSTART_COUNT define */ //how many mode
#define TASK_AUTOSTART_AppMode1_COUNT 4
/*==================[external data declaration]==============================*/
extern const TaskConstType TaskConst_core0[TASK_OBJECTS_COUNT_CORE0];
extern const TaskConstType TaskConst_core1[TASK_OBJECTS_COUNT_CORE1];

extern TaskVarType TaskVar_core0[TASK_OBJECTS_COUNT_CORE0];
extern TaskVarType TaskVar_core1[TASK_OBJECTS_COUNT_CORE1];

/* Brief Accessible App of Task */
extern TaskAutosarType TaskAutosar_core0[TASK_OBJECTS_COUNT_CORE0];
extern TaskAutosarType TaskAutosar_core1[TASK_OBJECTS_COUNT_CORE1];

extern uint8 ApplicationMode;

/* Brief AutoStart Array */
extern const AutoStartType AutoStart[1];

/* Brief Ready List */
extern TaskVarType *ReadyList_core0[READYLISTS_COUNT_CORE0];
extern TaskVarType *ReadyList_core1[READYLISTS_COUNT_CORE1];

/* Brief Ready List Tail */
/* In order to prevent linear search in AddReady */
extern TaskVarType *ReadyListTail_core0[READYLISTS_COUNT_CORE0];
extern TaskVarType *ReadyListTail_core1[READYLISTS_COUNT_CORE1];

extern TaskType SysTaskID[OsNumberOfCores];

/*==================[external functions declaration]=========================*/
/* Brief Task Declaration of Task IdleTask */
TASK(IdleTask);
TASK(SysTask);
TASK(SysTask_core0);
TASK(SysTask_core1);
/* Brief Task Declaration of Task T001 */
TASK(T001);
/* Brief Task Declaration of Task T002 */
TASK(T002);
/* Brief Task Declaration of Task T003 */
TASK(T003);
/* Brief Task Declaration of Task T004 */
TASK(T004);
/* Brief Task Declaration of Task T005 */
TASK(T005);
/* Brief Task Declaration of Task T006 */
TASK(T006);
/* Brief ISR Declaration of ISR I001 */
ISR(I001);
/* Brief ISR Declaration of ISR I002 */
ISR(I002);
/* Brief ISR Declaration of ISR I003 */
ISR(I003);
/* Brief ISR Declaration of ISR I004 */
ISR(I004);
/* Brief ISR Declaration of ISR I005 */
ISR(I005);
/* Brief ISR Declaration of ISR I006 */
ISR(I006);


/* Brief Task Declaration of Task T101 */
TASK(T101);
/* Brief Task Declaration of Task T102 */
TASK(T102);
/* Brief Task Declaration of Task T103 */
TASK(T103);
/* Brief Task Declaration of Task T104 */
TASK(T104);
/* Brief Task Declaration of Task T105 */
TASK(T105);
/* Brief Task Declaration of Task T106 */
TASK(T106);
/* Brief ISR Declaration of ISR I101 */
ISR(I101);
/* Brief ISR Declaration of ISR I102 */
ISR(I102);
/* Brief ISR Declaration of ISR I103 */
ISR(I103);
/* Brief ISR Declaration of ISR I104 */
ISR(I104);
/* Brief ISR Declaration of ISR I105 */
ISR(I105);
/* Brief ISR Declaration of ISR I106 */
ISR(I106);


/*==================[end of file]============================================*/
#endif /* #ifndef TASK_CFG_H */

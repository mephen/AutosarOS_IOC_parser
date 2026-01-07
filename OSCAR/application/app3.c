#include "iodefine.h"
#include "board.h"
#include "os.h"
#include "timer.h"
#include "os_Cfg.h"
#include "task_Cfg.h"
#include "event_Cfg.h"
#include "alarm_Cfg.h"
#include "application_Cfg.h"
#include "counter.h"
#include "alarm.h"
#include "task.h"
#include "isr2.h"
#include "event.h"
#include "memsection.h"
#include "memprot_Cfg.h"
#include "string_format_test.h"
#include "systemcall.h"
#include "application.h"
#include "ISRInit.h"
#include "isr_Cfg.h"
#include "spinlock.h"
#include "resource.h"
#include "memsection.h"
#include "trustedFunc_Cfg.h"
#include "spinlock_Cfg.h"
#include "Ioc.h"

extern int PrintText(char *TextArray);
extern int PrintText_R35(char *TextArray);

/************* USER_SHARED_SEC *****************/
#pragma section USER_SHARED_SEC

extern int PrintText(char *TextArray);
extern int PrintText_R35(char *TextArray);

/************* OSAPP_app3 *****************/
#pragma section OSAPP_app3_SEC

int app3_test_data = 0x22;
/* Brief StartupHook */
void StartupHook_OSAPP_app3(void)
{
}

/* Brief ShutdownHook */
void ShutdownHook_OSAPP_app3(StatusType Error)
{
}

/* Brief ErrorHook */
void ErrorHook_OSAPP_app3(StatusType Error)
{
    switch (Error)
    {
    case E_OS_CALLEVEL:
        PrintText("[ErrorHook]: E_OS_CALLEVEL\r\n");
        break;
    case E_OS_ID:
        PrintText("[ErrorHook]: E_OS_ID\r\n");
        break;
    case E_OS_LIMIT:
        PrintText("[ErrorHook]: E_OS_LIMIT\r\n");
        break;
    case E_OS_NOFUNC:
        PrintText("[ErrorHook]: E_OS_NOFUNC\r\n");
        break;
    case E_OS_RESOURCE:
        PrintText("[ErrorHook]: E_OS_RESOURCE\r\n");
        break;
    case E_OS_STATE:
        PrintText("[ErrorHook]: E_OS_STATE\r\n");
        break;
    case E_OS_VALUE:
        PrintText("[ErrorHook]: E_OS_VALUE\r\n");
        break;
    case E_OS_SYS_NOFUNC:
        PrintText("[ErrorHook]: E_OS_SYS_NOFUNC\r\n");
        break;
    case E_OS_SERVICEID:
        PrintText("[ErrorHook]: E_OS_SERVICEID\r\n");
        break;
    case E_OS_INTERFERENCE_DEADLOCK:
        PrintText("[ErrorHook]: E_OS_INTERFERENCE_DEADLOCK\r\n");
        break;
    case E_OS_SYS_OK_CROSSCORE:
        PrintText("[ErrorHook]: E_OS_SYS_OK_CROSSCORE\r\n");
        break;
    case E_OS_SPINLOCK:
        PrintText("[ErrorHook]: E_OS_SPINLOCK\r\n");
        break;
    case E_OS_DISABLEDINT:
        PrintText("[ErrorHook]: E_OS_DISABLEDINT\r\n");
        break;
    case IOC_E_OK:
        PrintText("[ErrorHook]: IOC_E_OK\r\n");
        break;
    case IOC_E_NOK:
        PrintText("[ErrorHook]: IOC_E_NOK\r\n");
        break;
    case IOC_E_LENGTH:
        PrintText("[ErrorHook]: IOC_E_LENGTH\r\n");
        break;
    case IOC_E_LIMIT:
        PrintText("[ErrorHook]: IOC_E_LIMIT\r\n");
        break;
    case IOC_E_LOST_DATA:
        PrintText("[ErrorHook]: IOC_E_LOST_DATA\r\n");
        break;
    case IOC_E_NO_DATA:
        PrintText("[ErrorHook]: IOC_E_NO_DATA\r\n");
        break;
    default:
        PrintText("[ErrorHook]: \r\n");
        break;
    }
}
#pragma section ISR_I005_SEC
ISR(I005)
{
};

#pragma section ISR_I006_SEC
ISR(I006)
{
};

#pragma section TASK_T004_SEC
TASK(T004)
{
};

#pragma section TASK_T005_SEC
TASK(T005)
{
};

#pragma section TASK_T006_SEC
TASK(T006)
{
};


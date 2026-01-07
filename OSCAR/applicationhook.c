#include "typedefine.h"
#include "scheduler.h"
#include "memprot.h"
#include "os.h"
#include "task.h"
#include "string_format_test.h"
extern CoreIdType _CoreID;
extern int kernelDisableMPUCounter;

#pragma section GLOBAL_RAM_A

char my_prot_err_str_arr[32];

#pragma section default
extern int PrintText(char *TextArray);

/* Brief PreTaskHook */
void PreTaskHook(void)
{
}

/* Brief PostTaskHook */
void PostTaskHook(void)
{
}

/* Brief ErrorHook */
void ErrorHook(StatusType Error)
{   
    //DisableMPU();
    TaskType taskID;
    GetTaskID(&taskID);
    PrintText("System Error Hook:\r");
    switch (Error)
    {   
    // case E_OS_ACCESS:
    //     PrintText("[ErrorHook]: E_OS_ACCESS\r\n");
    //     break;
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
    //EnableMPU();
}

/* Brief StartupHook */
void StartupHook(void)
{
}

/* Brief ShutdownHook */
void ShutdownHook(StatusType Error)
{
}

ProtectionReturnType ProtectionHook(StatusType Error)
{
    ProtectionReturnType retMsg = PRO_IGNORE;
    itoa_16_show_id(my_prot_err_str_arr, CURRENTTASK.currentID);
    switch (Error)
    {
    case E_OS_PROTECTION_ARRIVAL:

        retMsg = PRO_IGNORE;
        break;
    case E_OS_PROTECTION_LOCKED:

        retMsg = PRO_IGNORE;
        break;
    case E_OS_PROTECTION_TIME:

        retMsg = PRO_TERMINATETASKISR;
        break;
    case E_OS_PROTECTION_MEMORY:

        retMsg = PRO_TERMINATEAPPL;
        break;
    case E_OS_STACKFAULT:

        retMsg = PRO_TERMINATETASKISR;
        break;
    default:

        break;
    }

return retMsg;
}

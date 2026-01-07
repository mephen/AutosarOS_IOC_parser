#include "Ioc.h"
#include "os.h"
#include "system.h"
#include "application_Cfg.h"
#include "lock.h"
#include "os_Cfg.h"
#include "core.h"
#include "task_Cfg.h"
#include "task.h"
#include "scheduler.h"
#include "ISRInit.h"

void memcpy_j(int id, void *data, int n, int flag)
{
    IOCCB *cb = &icb[id];
    char *src = (char *)data;
    switch (flag)
    {
    case PUSH:
        for (int i = 0; i < n; i++)
        {
            cb->buffer[cb->tail] = *src;
            cb->tail = (cb->tail + 1) % cb->length;
            src = src + 1;
        }
        break;
    case POP:
        for (int i = 0; i < n; i++)
        {
            *src = cb->buffer[cb->head];
            cb->head = (cb->head + 1) % cb->length;
            src = src + 1;
        }
        break;
    default:
        break;
    }
}

Std_ReturnType IOC_API(int id, void *input_data, int flag)
{
    switch (id)
    {
    case Q1:
    {
        struct IOC_Q1_struct *d = (struct IOC_Q1_struct *)input_data;
        if (flag == IOC_SEND_Q1_SND1)
        {
            return SysIocWrite_Q1_SND1(d-> data_1);
        }
        if (flag == IOC_RECEIVER_Q1_RCV1)
        {
            return SysIocRead_Q1_RCV1(d-> data_1_r);
        }
        break;
    }
    case Q2:
    {
        struct IOC_Q2_struct *d = (struct IOC_Q2_struct *)input_data;
        if (flag == IOC_SEND_Q2_SND1)
        {
            return SysIocWrite_Q2_SND1(d-> ptr_1);
        }
        if (flag == IOC_RECEIVER_Q2_RCV1)
        {
            return SysIocRead_Q2_RCV1(d-> ptr_1);
        }
        break;
    }
    case Q3:
    {
        struct IOC_Q3_struct *d = (struct IOC_Q3_struct *)input_data;
        if (flag == IOC_SEND_Q3_SND1)
        {
            return SysIocWrite_Q3_SND1(d-> ptr_1, d->length_1);
        }
        if (flag == IOC_RECEIVER_Q3_RCV1)
        {
            return SysIocRead_Q3_RCV1(d-> ptr_1, d->length_1_r);
        }
        break;
    }
    case Q4:
    {
        struct IOC_Q4_struct *d = (struct IOC_Q4_struct *)input_data;
        if (flag == IOC_SEND_Q4_SND1)
        {
            return SysIocWriteGroup_Q4_SND1(d-> data_1, d-> ptr_2);
        }
        if (flag == IOC_RECEIVER_Q4_RCV1)
        {
            return SysIocReadGroup_Q4_RCV1(d-> data_1_r, d-> ptr_2);
        }
        break;
    }
    case Q5:
    {
        struct IOC_Q5_struct *d = (struct IOC_Q5_struct *)input_data;
        if (flag == IOC_SEND_Q5_SND1)
        {
            return SysIocWriteGroup_Q5_SND1(d-> data_1, d-> ptr_2, d->length_2);
        }
        if (flag == IOC_RECEIVER_Q5_RCV1)
        {
            return SysIocReadGroup_Q5_RCV1(d-> data_1_r, d-> ptr_2, d->length_2_r);
        }
        break;
    }
    case Q6:
    {
        struct IOC_Q6_struct *d = (struct IOC_Q6_struct *)input_data;
        if (flag == IOC_SEND_Q6_SND1)
        {
            return SysIocWriteGroup_Q6_SND1(d-> ptr_1, d->length_1, d-> ptr_2, d->length_2);
        }
        if (flag == IOC_RECEIVER_Q6_RCV1)
        {
            return SysIocReadGroup_Q6_RCV1(d-> ptr_1, d->length_1_r, d-> ptr_2, d->length_2_r);
        }
        break;
    }
    case Q7:
    {
        struct IOC_Q7_struct *d = (struct IOC_Q7_struct *)input_data;
        if (flag == IOC_SEND_Q7_SND)
        {
            return SysIocSendGroup_Q7_SND(d-> ptr_1, d->length_1, d-> ptr_2, d->length_2);
        }
        if (flag == IOC_RECEIVER_Q7_RCV)
        {
            return SysIocReceiveGroup_Q7_RCV(d-> ptr_1, d->length_1_r, d-> ptr_2, d->length_2_r);
        }
        else if(flag == IOC_EMPTY)
        {
            return SysIocEmptyQueue_Q7();
        }
        break;
    }
    }
}

uint16 lock_Q1 = 0;
uint8 buffer_Q1[100];
uint16 lock_Q2 = 0;
uint8 buffer_Q2[100];
uint16 lock_Q3 = 0;
uint8 buffer_Q3[100];
uint16 lock_Q4 = 0;
uint8 buffer_Q4[100];
uint16 lock_Q5 = 0;
uint8 buffer_Q5[100];
uint16 lock_Q6 = 0;
uint8 buffer_Q6[100];
uint16 lock_Q7 = 0;
uint8 buffer_Q7[30];
extern CoreIdType _CoreID;
static uint16 lock_bit = 7;

// PUSH info to systask
Std_ReturnType SetCallbackfunctionAction(ApplicationType reveiverID, void (*callback)(void))
{
    CoreIdType CoreID = (ApplicationVar[reveiverID].CoreRef);
    if (_CoreID == CoreID)
    {
        SysTaskInformationType info;
        info.ApplID = reveiverID;
        info.FunctionPointer = callback;
        info.SysTaskAction = IOCCALLBACK;
        EnSysTaskActionQueue(info);
        ActivateTaskInternal(SysTaskID[_CoreID]);
        ScheduleKernel();
    }
    else
    {
        enableCrossCoreISR();
        GetLock(&CoreParaLock[CoreID], lock_bit);
        CrossCoreServicePara[CoreID].serviceID = SERVICE_CALLBACKFUNCTION;
        CrossCoreServicePara[CoreID].para1 = reveiverID;
        CrossCoreServicePara[CoreID].para2 = callback;
        // CrossCoreServicePara[reveiverID].App = ExecutingApp[_CoreID];

        CoreIntFlag[CoreID] = 1;
        InterruptToCore(CoreID);
        while (CoreIntFlag[CoreID] == 1)
            ;
        ReleaseLock(&CoreParaLock[CoreID], lock_bit);
        disableCrossCoreISR();
    }
}


ReceiverType receiver_Q1[1] = {
    {
        .appID = app2,
    },
};
ReceiverType receiver_Q2[1] = {
    {
        .appID = app2,
    },
};
ReceiverType receiver_Q3[1] = {
    {
        .appID = app2,
    },
};
ReceiverType receiver_Q4[1] = {
    {
        .appID = app2,
    },
};
ReceiverType receiver_Q5[1] = {
    {
        .appID = app2,
    },
};
ReceiverType receiver_Q6[1] = {
    {
        .appID = app2,
    },
};
ReceiverType receiver_Q7[1] = {
    {
        .appID = app2,
    },
};
IocAutosarType Ioc_channel_sender[IOCID_COUNT] = {
    0 | (1 << app_lion),
    0 | (1 << app_lion),
    0 | (1 << app_lion),
    0 | (1 << app_lion),
    0 | (1 << app_lion),
    0 | (1 << app_lion),
    0 | (1 << app_lion),
};

IocAutosarType Ioc_channel_receiver[IOCID_COUNT] = {
    0 | (1 << FALSE),
    0 | (1 << FALSE),
    0 | (1 << FALSE),
    0 | (1 << FALSE),
    0 | (1 << FALSE),
    0 | (1 << FALSE),
    0 | (1 << app2),
};

IOCCB icb[IOCID_COUNT] = {
    {.head = 0,
     .tail = 0,
     .length = FALSE,
     .channel_receive_num = 1,
     .receiver = receiver_Q1,
     .callbackFlag = 0,
     .lostFlag = 0,
     .buffer = buffer_Q1},
    {.head = 0,
     .tail = 0,
     .length = FALSE,
     .channel_receive_num = 1,
     .receiver = receiver_Q2,
     .callbackFlag = 0,
     .lostFlag = 0,
     .buffer = buffer_Q2},
    {.head = 0,
     .tail = 0,
     .length = FALSE,
     .channel_receive_num = 1,
     .receiver = receiver_Q3,
     .callbackFlag = 0,
     .lostFlag = 0,
     .buffer = buffer_Q3},
    {.head = 0,
     .tail = 0,
     .length = FALSE,
     .channel_receive_num = 1,
     .receiver = receiver_Q4,
     .callbackFlag = 0,
     .lostFlag = 0,
     .buffer = buffer_Q4},
    {.head = 0,
     .tail = 0,
     .length = FALSE,
     .channel_receive_num = 1,
     .receiver = receiver_Q5,
     .callbackFlag = 0,
     .lostFlag = 0,
     .buffer = buffer_Q5},
    {.head = 0,
     .tail = 0,
     .length = FALSE,
     .channel_receive_num = 1,
     .receiver = receiver_Q6,
     .callbackFlag = 0,
     .lostFlag = 0,
     .buffer = buffer_Q6},
    {.head = 0,
     .tail = 0,
     .length = 30,
     .channel_receive_num = 1,
     .receiver = receiver_Q7,
     .callbackFlag = 0,
     .lostFlag = 0,
     .buffer = buffer_Q7},
};

#define OS_OSAPP_app_lion_START_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType IocWrite_Q1_SND1(uint8 data_1)
{
    struct IOC_Q1_struct d;
    d.data_1 = data_1;
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = Q1; // ioc channel
    para.para2 = &d; // parameter
    para.para3 = IOC_SEND_Q1_SND1;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}

#define OS_OSAPP_app_lion_STOP_SEC_CODE
#include "OS_MemMap.h"

Std_ReturnType SysIocWrite_Q1_SND1(uint8 data_1)
{
    Std_ReturnType ret = IOC_E_OK;
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_s[Q1].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == IOC_E_OK)
    {
        GetLock(&lock_Q1, lock_bit);
        IOCCB *cb = &icb[Q1];
        if (ret == IOC_E_OK)
        {
            memcpy_j(Q1, &data_1, sizeof(uint8), PUSH);

            if (ret == IOC_E_OK && icb[Q1].callbackFlag == 1)
            {
                for (int i = 0; i < cb->channel_receive_num; i++)
                {
                    SetCallbackfunctionAction(cb->receiver[i].appID, cb->receiver[i].callback);
                }
            }
        }
        ReleaseLock(&lock_Q1, lock_bit);
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)

    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */

#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if (ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}

#define OS_OSAPP_app2_START_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType IocRead_Q1_RCV1(uint8 *data_1)
{
    struct IOC_Q1_struct d;
    d.data_1_r = data_1;
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = Q1; // ioc channel
    para.para2 = &d; // parameter
    para.para3 = IOC_RECEIVER_Q1_RCV1;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}

void callback_Q1_False(void)
{
    PrintText("callback sucess\r\n\0");
}

#define OS_OSAPP_app2_STOP_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType SysIocRead_Q1_RCV1(uint8 *data_1)
{
    Std_ReturnType ret = IOC_E_OK;
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_r[Q1].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == IOC_E_OK)
    {
        GetLock(&lock_Q1, lock_bit);
        IOCCB *cb = &icb[Q1];
        memcpy_j(Q1, data_1, sizeof(uint8), POP);
        cb->head = cb->tail = 0;
        ReleaseLock(&lock_Q1, lock_bit);
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)

    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */

#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if (ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}

#define OS_OSAPP_app_lion_START_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType IocWrite_Q2_SND1(str* ptr_1)
{
    struct IOC_Q2_struct d;
    d.ptr_1 = ptr_1;
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = Q2; // ioc channel
    para.para2 = &d; // parameter
    para.para3 = IOC_SEND_Q2_SND1;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}

#define OS_OSAPP_app_lion_STOP_SEC_CODE
#include "OS_MemMap.h"

Std_ReturnType SysIocWrite_Q2_SND1(str* ptr_1)
{
    Std_ReturnType ret = IOC_E_OK;
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_s[Q2].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == IOC_E_OK)
    {
        GetLock(&lock_Q2, lock_bit);
        IOCCB *cb = &icb[Q2];
        if (ret == IOC_E_OK)
        {
            memcpy_j(Q2, ptr_1, sizeof(str*), PUSH);
            if (ret == IOC_E_OK && icb[Q2].callbackFlag == 1)
            {
                for (int i = 0; i < cb->channel_receive_num; i++)
                {
                    SetCallbackfunctionAction(cb->receiver[i].appID, cb->receiver[i].callback);
                }
            }
        }
        ReleaseLock(&lock_Q2, lock_bit);
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)

    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */

#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if (ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}

#define OS_OSAPP_app2_START_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType IocRead_Q2_RCV1(str* ptr_1)
{
    struct IOC_Q2_struct d;
    d.ptr_1 = ptr_1;
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = Q2; // ioc channel
    para.para2 = &d; // parameter
    para.para3 = IOC_RECEIVER_Q2_RCV1;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}

void callback_Q2_False(void)
{
    PrintText("callback sucess\r\n\0");
}

#define OS_OSAPP_app2_STOP_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType SysIocRead_Q2_RCV1(str* ptr_1)
{
    Std_ReturnType ret = IOC_E_OK;
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_r[Q2].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == IOC_E_OK)
    {
        GetLock(&lock_Q2, lock_bit);
        IOCCB *cb = &icb[Q2];
        memcpy_j(Q2, ptr_1, sizeof(str*), POP);
        cb->head = cb->tail = 0;
        ReleaseLock(&lock_Q2, lock_bit);
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)

    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */

#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if (ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}

#define OS_OSAPP_app_lion_START_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType IocWrite_Q3_SND1(str* ptr_1, uint16 length_1)
{
    struct IOC_Q3_struct d;
    d.ptr_1 = ptr_1;
    d.length_1 = length_1;
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = Q3; // ioc channel
    para.para2 = &d; // parameter
    para.para3 = IOC_SEND_Q3_SND1;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}

#define OS_OSAPP_app_lion_STOP_SEC_CODE
#include "OS_MemMap.h"

Std_ReturnType SysIocWrite_Q3_SND1(str* ptr_1, uint16 length_1)
{
    Std_ReturnType ret = IOC_E_OK;
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_s[Q3].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == IOC_E_OK)
    {
        GetLock(&lock_Q3, lock_bit);
        IOCCB *cb = &icb[Q3];
        if (length_1 == 0 || length_1 > cb->length)
        {
            ret = IOC_E_LENGTH;
        }
        if (ret == IOC_E_OK)
        {
            memcpy_j(Q3, &length_1, sizeof(uint16), PUSH);
            memcpy_j(Q3, ptr_1, length_1, PUSH);
            cb->tail = cb->head = 0;
            if (cb->callbackFlag == 1)
            {
                for (int i = 0; i < cb->channel_receive_num; i++)
                {
                    SetCallbackfunctionAction(cb->receiver[i].appID, cb->receiver[i].callback);
                }
            }
        }
        ReleaseLock(&lock_Q3, lock_bit);
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)

    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */

#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if (ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}

#define OS_OSAPP_app2_START_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType IocRead_Q3_RCV1(str* ptr_1, uint16* length_1)
{
    struct IOC_Q3_struct d;
    d.ptr_1 = ptr_1;
    d.length_1_r = length_1;
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = Q3; // ioc channel
    para.para2 = &d; // parameter
    para.para3 = IOC_RECEIVER_Q3_RCV1;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}

void callback_Q3_False(void)
{
    PrintText("callback sucess\r\n\0");
}

#define OS_OSAPP_app2_STOP_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType SysIocRead_Q3_RCV1(str* ptr_1, uint16* length_1)
{
    Std_ReturnType ret = IOC_E_OK;
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_r[Q3].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == IOC_E_OK)
    {
        GetLock(&lock_Q3, lock_bit);
        IOCCB *cb = &icb[Q3];
        memcpy_j(Q3, length_1, sizeof(uint16), POP);
        memcpy_j(Q3, ptr_1, *length_1, POP);
        cb->head = cb->tail = 0;
        ReleaseLock(&lock_Q3, lock_bit);
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)

    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */

#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if (ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}

#define OS_OSAPP_app_lion_START_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType IocWriteGroup_Q4_SND1(uint8 data_1, str* ptr_2)
{
    struct IOC_Q4_struct d;
    d.data_1 = data_1;
    d.ptr_2 = ptr_2;
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = Q4; // ioc channel
    para.para2 = &d; // parameter
    para.para3 = IOC_SEND_Q4_SND1;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}

#define OS_OSAPP_app_lion_STOP_SEC_CODE
#include "OS_MemMap.h"

Std_ReturnType SysIocWriteGroup_Q4_SND1(uint8 data_1, str* ptr_2)
{
    Std_ReturnType ret = IOC_E_OK;
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_s[Q4].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == IOC_E_OK)
    {
        GetLock(&lock_Q4, lock_bit);
        IOCCB *cb = &icb[Q4];
        if (ret == IOC_E_OK)
        {
            memcpy_j(Q4, &data_1, sizeof(uint8), PUSH);
            memcpy_j(Q4, ptr_2, sizeof(str*), PUSH);
            cb->tail = cb->head = 0;
            if (cb->callbackFlag == 1)
            {
                for (int i = 0; i < cb->channel_receive_num; i++)
                {
                    SetCallbackfunctionAction(cb->receiver[i].appID, cb->receiver[i].callback);
                }
            }
        }
        ReleaseLock(&lock_Q4, lock_bit);
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)

    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */

#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if (ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}

#define OS_OSAPP_app2_START_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType IocReadGroup_Q4_RCV1(uint8* data_1, str* ptr_2)
{
    struct IOC_Q4_struct d;
    d.data_1_r = data_1;
    d.ptr_2 = ptr_2;
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = Q4; // ioc channel
    para.para2 = &d; // parameter
    para.para3 = IOC_RECEIVER_Q4_RCV1;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}

void callback_Q4_False(void)
{
    PrintText("callback sucess\r\n\0");
}

#define OS_OSAPP_app2_STOP_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType SysIocReadGroup_Q4_RCV1(uint8* data_1, str* ptr_2)
{
    Std_ReturnType ret = IOC_E_OK;
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_r[Q4].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == IOC_E_OK)
    {
        GetLock(&lock_Q4, lock_bit);
        IOCCB *cb = &icb[Q4];
            memcpy_j(Q4, &data_1, sizeof(uint8), PUSH);
            memcpy_j(Q4, ptr_2, sizeof(str*), PUSH);
        cb->head = cb->tail = 0;
        ReleaseLock(&lock_Q4, lock_bit);
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)

    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */

#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if (ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}

#define OS_OSAPP_app_lion_START_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType IocWriteGroup_Q5_SND1(uint8 data_1, str* ptr_2, uint16 length_2)
{
    struct IOC_Q5_struct d;
    d.data_1 = data_1;
    d.ptr_2 = ptr_2;
    d.length_2 = length_2;
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = Q5; // ioc channel
    para.para2 = &d; // parameter
    para.para3 = IOC_SEND_Q5_SND1;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}

#define OS_OSAPP_app_lion_STOP_SEC_CODE
#include "OS_MemMap.h"

Std_ReturnType SysIocWriteGroup_Q5_SND1(uint8 data_1, str* ptr_2, uint16 length_2)
{
    Std_ReturnType ret = IOC_E_OK;
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_s[Q5].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == IOC_E_OK)
    {
        GetLock(&lock_Q5, lock_bit);
        IOCCB *cb = &icb[Q5];
        int length = length_2;
        if (length == 0 || length > cb->length)
        {
            ret = IOC_E_LENGTH;
        }
        if (ret == IOC_E_OK)
        {
            memcpy_j(Q5, &data_1, sizeof(uint8), PUSH);
            memcpy_j(Q5, &length_2, sizeof(uint16), PUSH);
            memcpy_j(Q5, ptr_2, length_2, PUSH);
            cb->tail = cb->head = 0;
            if (cb->callbackFlag == 1)
            {
                for (int i = 0; i < cb->channel_receive_num; i++)
                {
                    SetCallbackfunctionAction(cb->receiver[i].appID, cb->receiver[i].callback);
                }
            }
        }
        ReleaseLock(&lock_Q5, lock_bit);
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)

    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */

#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if (ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}

#define OS_OSAPP_app2_START_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType IocReadGroup_Q5_RCV1(uint8* data_1, str* ptr_2, uint16* length_2)
{
    struct IOC_Q5_struct d;
    d.data_1_r = data_1;
    d.ptr_2 = ptr_2;
    d.length_2_r = length_2;
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = Q5; // ioc channel
    para.para2 = &d; // parameter
    para.para3 = IOC_RECEIVER_Q5_RCV1;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}

void callback_Q5_False(void)
{
    PrintText("callback sucess\r\n\0");
}

#define OS_OSAPP_app2_STOP_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType SysIocReadGroup_Q5_RCV1(uint8* data_1, str* ptr_2, uint16* length_2)
{
    Std_ReturnType ret = IOC_E_OK;
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_r[Q5].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == IOC_E_OK)
    {
        GetLock(&lock_Q5, lock_bit);
        IOCCB *cb = &icb[Q5];
            memcpy_j(Q5, &data_1, sizeof(uint8), PUSH);
            memcpy_j(Q5, &length_2, sizeof(uint16), PUSH);
            memcpy_j(Q5, ptr_2, length_2, PUSH);
        cb->head = cb->tail = 0;
        ReleaseLock(&lock_Q5, lock_bit);
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)

    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */

#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if (ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}

#define OS_OSAPP_app_lion_START_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType IocWriteGroup_Q6_SND1(str* ptr_1, uint16 length_1, str* ptr_2, uint16 length_2)
{
    struct IOC_Q6_struct d;
    d.ptr_1 = ptr_1;
    d.length_1 = length_1;
    d.ptr_2 = ptr_2;
    d.length_2 = length_2;
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = Q6; // ioc channel
    para.para2 = &d; // parameter
    para.para3 = IOC_SEND_Q6_SND1;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}

#define OS_OSAPP_app_lion_STOP_SEC_CODE
#include "OS_MemMap.h"

Std_ReturnType SysIocWriteGroup_Q6_SND1(str* ptr_1, uint16 length_1, str* ptr_2, uint16 length_2)
{
    Std_ReturnType ret = IOC_E_OK;
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_s[Q6].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == IOC_E_OK)
    {
        GetLock(&lock_Q6, lock_bit);
        IOCCB *cb = &icb[Q6];
        int length = length_1 + length_2;
        if (length == 0 || length > cb->length)
        {
            ret = IOC_E_LENGTH;
        }
        if (ret == IOC_E_OK)
        {
            memcpy_j(Q6, &length_1, sizeof(uint16), PUSH);
            memcpy_j(Q6, ptr_1, length_1, PUSH);
            memcpy_j(Q6, &length_2, sizeof(uint16), PUSH);
            memcpy_j(Q6, ptr_2, length_2, PUSH);
            cb->tail = cb->head = 0;
            if (cb->callbackFlag == 1)
            {
                for (int i = 0; i < cb->channel_receive_num; i++)
                {
                    SetCallbackfunctionAction(cb->receiver[i].appID, cb->receiver[i].callback);
                }
            }
        }
        ReleaseLock(&lock_Q6, lock_bit);
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)

    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */

#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if (ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}

#define OS_OSAPP_app2_START_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType IocReadGroup_Q6_RCV1(str* ptr_1, uint16* length_1, str* ptr_2, uint16* length_2)
{
    struct IOC_Q6_struct d;
    d.ptr_1 = ptr_1;
    d.length_1_r = length_1;
    d.ptr_2 = ptr_2;
    d.length_2_r = length_2;
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = Q6; // ioc channel
    para.para2 = &d; // parameter
    para.para3 = IOC_RECEIVER_Q6_RCV1;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}

void callback_Q6_False(void)
{
    PrintText("callback sucess\r\n\0");
}

#define OS_OSAPP_app2_STOP_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType SysIocReadGroup_Q6_RCV1(str* ptr_1, uint16* length_1, str* ptr_2, uint16* length_2)
{
    Std_ReturnType ret = IOC_E_OK;
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_r[Q6].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == IOC_E_OK)
    {
        GetLock(&lock_Q6, lock_bit);
        IOCCB *cb = &icb[Q6];
            memcpy_j(Q6, &length_1, sizeof(uint16), PUSH);
            memcpy_j(Q6, ptr_1, length_1, PUSH);
            memcpy_j(Q6, &length_2, sizeof(uint16), PUSH);
            memcpy_j(Q6, ptr_2, length_2, PUSH);
        cb->head = cb->tail = 0;
        ReleaseLock(&lock_Q6, lock_bit);
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)

    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */

#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if (ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}

#define OS_OSAPP_app_lion_START_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType IocSendGroup_Q7_SND(str* ptr_1, uint16 length_1, str* ptr_2, uint16 length_2)
{
    struct IOC_Q7_struct d;
    d.ptr_1 = ptr_1;
    d.length_1 = length_1;
    d.ptr_2 = ptr_2;
    d.length_2 = length_2;
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = Q7; // ioc channel
    para.para2 = &d; // parameter
    para.para3 = IOC_SEND_Q7_SND;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}

#define OS_OSAPP_app_lion_STOP_SEC_CODE
#include "OS_MemMap.h"

Std_ReturnType SysIocSendGroup_Q7_SND(str* ptr_1, uint16 length_1, str* ptr_2, uint16 length_2)
{
    Std_ReturnType ret = IOC_E_OK;

    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_s[Q7].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == IOC_E_OK)
    {
        GetLock(&lock_Q7, lock_bit);
        IOCCB *cb = &icb[Q7];
        int length = length_1 + length_2;
        if (length == 0 || length > cb->length)
        {
            ret = IOC_E_LENGTH;
        }
        if (ret == IOC_E_OK)
        {
            int data_size = length_1 + sizeof(uint16) + length_2 + sizeof(uint16);
            int remain_size = (cb->head - cb->tail + cb->length - 1) % cb->length;
            if (data_size > remain_size)
            {
                cb->lostFlag = 1;
                ret = IOC_E_LIMIT;
            }
        }
        if (ret == IOC_E_OK)
        {
            memcpy_j(Q7, &length_1, sizeof(uint16), PUSH);
            memcpy_j(Q7, ptr_1, length_1, PUSH);
            memcpy_j(Q7, &length_2, sizeof(uint16), PUSH);
            memcpy_j(Q7, ptr_2, length_2, PUSH);
        }
        if (ret == IOC_E_OK && icb[Q7].callbackFlag == 1)
        {
            for (int i = 0; i < cb->channel_receive_num; i++)
            {
                SetCallbackfunctionAction(cb->receiver[i].appID, cb->receiver[i].callback);
            }
        }
        ReleaseLock(&lock_Q7, lock_bit);
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)

    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */

#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if (ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}

#define OS_OSAPP_app2_START_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType IocReceiveGroup_Q7_RCV(str* ptr_1, uint16* length_1, str* ptr_2, uint16* length_2)
{
    struct IOC_Q7_struct d;
    d.ptr_1 = ptr_1;
    d.length_1_r = length_1;
    d.ptr_2 = ptr_2;
    d.length_2_r = length_2;
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = Q7; // ioc channel
    para.para2 = &d; // parameter
    para.para3 = IOC_RECEIVER_Q7_RCV;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}

void callback_Q7_False(void)
{
    int data;
    PrintText("callback sucess\r\n\0");
}

#define OS_OSAPP_app2_STOP_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType SysIocReceiveGroup_Q7_RCV(str* ptr_1, uint16* length_1, str* ptr_2, uint16* length_2)
{
    Std_ReturnType ret = IOC_E_OK;
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_r[Q7].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == IOC_E_OK)
    {
        GetLock(&lock_Q7, lock_bit);
        IOCCB *cb = &icb[Q7];
        if (cb->head == cb->tail)
        {
            ret = IOC_E_NO_DATA;
        }
        if (ret == IOC_E_OK)
        {
            memcpy_j(Q7, length_1, sizeof(uint16), POP);
            memcpy_j(Q7, ptr_1, *length_1, POP);
            memcpy_j(Q7, length_2, sizeof(uint16), POP);
            memcpy_j(Q7, ptr_2, *length_2, POP);
            if (cb->lostFlag == 1)
            {
                cb->lostFlag = 0;
                ret = IOC_E_LOST_DATA;
            }
        }
        ReleaseLock(&lock_Q7, lock_bit);
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)

    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */

#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if (ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}

Std_ReturnType IocEmptyQueue_Q7()
{
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = Q7;        // ioc channel
    para.para2 = NULL;      // parameter
    para.para3 = IOC_EMPTY; // flag 0: send / 1: receive
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}

Std_ReturnType SysIocEmptyQueue_Q7(void)
{
    Std_ReturnType ret = IOC_E_OK;
    // how to get appID
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_r[Q7].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == E_OK)
    {
        GetLock(&lock_Q7, lock_bit);
        IOCCB *cb = &icb[Q7];
        cb->head = cb->tail = 0;
        ReleaseLock(&lock_Q7, lock_bit);
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)

    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */
#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if (ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}

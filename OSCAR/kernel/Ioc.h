#ifndef IOC_H
#define IOC_H
/* the generated configuration of ioc */
/*==================[inclusions]=============================================*/
#include "typedefine.h"
//#include "Rte_Type.h"
/*==================[macros]=================================================*/
#define IOC_SEND_Q1_SND1 0
#define IOC_RECEIVER_Q1_RCV1 10
#define IOC_SEND_Q2_SND1 1
#define IOC_RECEIVER_Q2_RCV1 11
#define IOC_SEND_Q3_SND1 2
#define IOC_RECEIVER_Q3_RCV1 12
#define IOC_SEND_Q4_SND1 3
#define IOC_RECEIVER_Q4_RCV1 13
#define IOC_SEND_Q5_SND1 4
#define IOC_RECEIVER_Q5_RCV1 14
#define IOC_SEND_Q6_SND1 5
#define IOC_RECEIVER_Q6_RCV1 15
#define IOC_EMPTY 20

/*
per channel has one IOCCB, with IOCCB 
we can get the  information of the communication of channel
*/
typedef struct{
    ApplicationType appID;
    void (*callback)(void);
}ReceiverType;

typedef struct IOCCB{
    uint32 head; //internel buffer index
    uint32 tail; //internel buffer index
    uint32 length; // internel buffer length
    uint32 channel_receive_num; // the number of receiver
    ReceiverType *receiver; // point to array that store the receiver and callback function informationl
    uint8 callbackFlag; // if the callback function is set, set this flag
    uint8 lostFlag; // if the data is lost, set this flag
    uint8* buffer; // point to the internel buffer
}IOCCB;

#define POP 0
#define PUSH 1
#define IOCID_COUNT 6

#define Q1 0
#define Q2 1
#define Q3 2
#define Q4 3
#define Q5 4
#define Q6 5
/*mask*/
extern IocAutosarType Ioc_channel_sender[IOCID_COUNT];
extern IocAutosarType Ioc_channel_receiver[IOCID_COUNT];
struct IOC_Q1_struct{
    union{
        uint8 data_1;
        uint8* data_1_r;
    };
};
struct IOC_Q2_struct{
    union{
        ClientServerInfoType_test data_1;
        ClientServerInfoType_test* data_1_r;
    };
};
struct IOC_Q3_struct{
    composite* ptr_1;
    union{
        uint16 length_1;
        uint16* length_1_r;
    };
};
struct IOC_Q4_struct{
    union{
        uint8 data_1;
        uint8* data_1_r;
    };
};
struct IOC_Q5_struct{
    str* ptr_1;
    str* ptr_2;
    union{
        uint16 length_2;
        uint16* length_2_r;
    };
};
struct IOC_Q6_struct{
    union{
        XXXType data_1;
        XXXType* data_1_r;
    };
};
extern IOCCB icb[IOCID_COUNT];

Std_ReturnType IOC_API(int id, void* input_data,int flag);
Std_ReturnType SetCallbackfunctionAction(ApplicationType ,void (*callback)(void));
void memcpy_j(int iocid, void *data, int size, int flag);


extern uint16 lock_Q1 ;
extern uint8 buffer_Q1[20];
extern ReceiverType receiver_Q1[1] ;
Std_ReturnType IocSend_Q1_SND1(uint8);
Std_ReturnType SysIocSend_Q1_SND1(uint8);
Std_ReturnType IocReceive_Q1(uint8*);
Std_ReturnType SysIocReceive_Q1(uint8*);
Std_ReturnType IocEmptyQueue_Q1(void);
Std_ReturnType SysIocEmptyQueue_Q1(void);


extern uint16 lock_Q2 ;
extern uint8 buffer_Q2[20];
extern ReceiverType receiver_Q2[1] ;
Std_ReturnType IocSend_Q2_SND1(ClientServerInfoType_test);
Std_ReturnType SysIocSend_Q2_SND1(ClientServerInfoType_test);
Std_ReturnType IocReceive_Q2(ClientServerInfoType_test*);
Std_ReturnType SysIocReceive_Q2(ClientServerInfoType_test*);
Std_ReturnType IocEmptyQueue_Q2(void);
Std_ReturnType SysIocEmptyQueue_Q2(void);


extern uint16 lock_Q3 ;
extern uint8 buffer_Q3[20];
extern ReceiverType receiver_Q3[1] ;
Std_ReturnType IocSend_Q3_SND1(composite*, uint16);
Std_ReturnType SysIocSend_Q3_SND1(composite*, uint16);
Std_ReturnType IocReceive_Q3(composite*,uint16*);
Std_ReturnType SysIocReceive_Q3(composite*,uint16*);
Std_ReturnType IocEmptyQueue_Q3(void);
Std_ReturnType SysIocEmptyQueue_Q3(void);

Std_ReturnType IocWrite_Q4_SND1(uint8);
Std_ReturnType SysIocWrite_Q4_SND1(uint8);
Std_ReturnType IocRead_Q4_RCV1(uint8*);
Std_ReturnType SysIocRead_Q4_RCV1(uint8*);


Std_ReturnType IocWriteGroup_Q5_SND1(str*, str*, uint16);
Std_ReturnType SysIocWriteGroup_Q5_SND1(str*, str*, uint16);
Std_ReturnType IocReadGroup_Q5_RCV1(str*, str*, uint16*);
Std_ReturnType SysIocReadGroup_Q5_RCV1(str*, str*, uint16*);



extern uint16 lock_Q6 ;
extern uint8 buffer_Q6[20];
extern ReceiverType receiver_Q6[1] ;
Std_ReturnType IocSend_Q6_SND1(XXXType);
Std_ReturnType SysIocSend_Q6_SND1(XXXType);
Std_ReturnType IocReceive_Q6(XXXType*);
Std_ReturnType SysIocReceive_Q6(XXXType*);
Std_ReturnType IocEmptyQueue_Q6(void);
Std_ReturnType SysIocEmptyQueue_Q6(void);

#endif

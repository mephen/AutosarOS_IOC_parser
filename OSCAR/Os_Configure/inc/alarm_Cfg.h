#ifndef ALARM_CFG_H
#define ALARM_CFG_H
/* This file content the generated configuration of alarm */
/*==================[inclusions]=============================================*/
#include "typedefine.h"
/*==================[macros]=================================================*/
/* Brief Definition of the DeclareAlarmCallback Macro */
#define DeclareCallback(name) void MILKSHOP_CALLBACK_ ## name (void)
/* brief ALARMS_COUNT define */
#define ALARMS_COUNT_CORE0 4 
#define ALARMS_COUNT_CORE1 2 
#define ALARMS_COUNT 6 
/* brief ALARMS_AUTOSTART_COUNT define */
#define ALARMS_AUTOSTART_COUNT_CORE0 0 
#define ALARMS_AUTOSTART_COUNT_CORE1 0 
#define ALARMS_AUTOSTART_COUNT 0 
/* brief Definition of the Alarm alarm3 */
#define alarm3 0x00000000
/* brief Definition of the Alarm alarm4 */
#define alarm4 0x00000001
/* brief Definition of the Alarm alarm_ST1 */
#define alarm_ST1 0x00000002
/* brief Definition of the Alarm alarm_ST2 */
#define alarm_ST2 0x00000003


/* brief Definition of the Alarm alarm1 */
#define alarm1 0x00010000
/* brief Definition of the Alarm alarm_ST3 */
#define alarm_ST3 0x00010001


#define INVALID_ALARM_ID 0x00020000

/*==================[external data declaration]=========================*/
/* brief Alarm Variable Structure */
extern AlarmVarType AlarmVar_core0[ALARMS_COUNT_CORE0];
extern AlarmVarType AlarmVar_core1[ALARMS_COUNT_CORE1];

/* brief Alarm Constant Structure */
extern const AlarmConstType AlarmConst_core0[ALARMS_COUNT_CORE0];
extern const AlarmConstType AlarmConst_core1[ALARMS_COUNT_CORE1];

/* brief Accessible App of Alarm */
extern AlarmAutosarType AlarmAutosar_core0[ALARMS_COUNT_CORE0];
extern AlarmAutosarType AlarmAutosar_core1[ALARMS_COUNT_CORE1];

/*==================[end of file]============================================*/
#endif /* #ifndef ALARM_CFG_H */

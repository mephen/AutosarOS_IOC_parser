/* This file content the generated configuration of trustedFunction */

/*==================[inclusions]=============================================*/
#include "typedefine.h"
#include "application_Cfg.h"
#include "trustedFunc_Cfg.h"
#include "resource_Cfg.h"

#pragma section

TrustedFuncPtrType* TF_array[2] = {
    TF_array_core0,
    TF_array_core1,
};

TrustedFuncPtrType TF_array_core0[TRUSTED_FUNC_COUNT_CORE0] = {
    TRUSTED_TF_AIMER,
    TRUSTED_TF_IKURA,
    TRUSTED_TF_YORUSHIKA,
};
TrustedFuncPtrType TF_array_core1[TRUSTED_FUNC_COUNT_CORE1] = {
    TRUSTED_TF_YUURI,
    TRUSTED_TF_HITORIE,
};
TrustedFunctionAutosarType TrustedFuncAutosar_core0[TRUSTED_FUNC_COUNT_CORE0] = {
    /* TRUSTED_TF_AIMER */
    {
        app_lion,
        0 | (1 << app_lion) | (1 << app3), 
    },
    /* TRUSTED_TF_IKURA */
    {
        app_lion,
        0 | (1 << app_lion) | (1 << app3), 
    },
    /* TRUSTED_TF_YORUSHIKA */
    {
        app_lion,
        0 | (1 << app_lion) | (1 << app3), 
    },
};
TrustedFunctionAutosarType TrustedFuncAutosar_core1[TRUSTED_FUNC_COUNT_CORE1] = {
    /* TRUSTED_TF_YUURI */
    {
        app2,
        0 | (1 << app2) | (1 << app4), 
    },
    /* TRUSTED_TF_HITORIE */
    {
        app2,
        0 | (1 << app2) | (1 << app4), 
    },
};
#pragma section

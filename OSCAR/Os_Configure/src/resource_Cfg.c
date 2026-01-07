#include "resource_Cfg.h"
/* brief Resources Priorities */
const TaskPriorityType ResourcesPriority_core0[RESOURCES_COUNT_CORE0] = {
    3,
    3,
    2,
    2,
    2,
};

/* Brief ResourceVar Array */
ResourceVarType ResourceVar_core0[RESOURCES_COUNT_CORE0] = {

    /* General resource resource1 */
    {
        NULL,                         /* NextResource pointer */
        &ResourcesPriority_core0[(resource1 & 0xffff)], /* celingPriority */
        0,                            /* previousPriority */
        0,                            /* owner */
        resource1,                    /* id */
    },
    /* General resource resource2 */
    {
        NULL,                         /* NextResource pointer */
        &ResourcesPriority_core0[(resource2 & 0xffff)], /* celingPriority */
        0,                            /* previousPriority */
        0,                            /* owner */
        resource2,                    /* id */
    },
    /* General resource resource3 */
    {
        NULL,                         /* NextResource pointer */
        &ResourcesPriority_core0[(resource3 & 0xffff)], /* celingPriority */
        0,                            /* previousPriority */
        0,                            /* owner */
        resource3,                    /* id */
    },
    /* Sys resource resourceapp_lion */
    {
        NULL,                         /* NextResource pointer */
        &ResourcesPriority_core0[(resourceapp_lion & 0xffff)], /* celingPriority */
        0,                            /* previousPriority */
        0,                            /* owner */
        resourceapp_lion                            /* id */
    },
    /* Sys resource resourceapp3 */
    {
        NULL,                         /* NextResource pointer */
        &ResourcesPriority_core0[(resourceapp3 & 0xffff)], /* celingPriority */
        0,                            /* previousPriority */
        0,                            /* owner */
        resourceapp3                            /* id */
    },
};

/* brief Resources Priorities */
const TaskPriorityType ResourcesPriority_core1[RESOURCES_COUNT_CORE1] = {
    2,
    2,
    2,
    2,
    2,
};

/* Brief ResourceVar Array */
ResourceVarType ResourceVar_core1[RESOURCES_COUNT_CORE1] = {

    /* General resource resource4 */
    {
        NULL,                         /* NextResource pointer */
        &ResourcesPriority_core1[(resource4 & 0xffff)], /* celingPriority */
        0,                            /* previousPriority */
        0,                            /* owner */
        resource4,                    /* id */
    },
    /* General resource resource5 */
    {
        NULL,                         /* NextResource pointer */
        &ResourcesPriority_core1[(resource5 & 0xffff)], /* celingPriority */
        0,                            /* previousPriority */
        0,                            /* owner */
        resource5,                    /* id */
    },
    /* General resource resource6 */
    {
        NULL,                         /* NextResource pointer */
        &ResourcesPriority_core1[(resource6 & 0xffff)], /* celingPriority */
        0,                            /* previousPriority */
        0,                            /* owner */
        resource6,                    /* id */
    },
    /* Sys resource resourceapp2 */
    {
        NULL,                         /* NextResource pointer */
        &ResourcesPriority_core1[(resourceapp2 & 0xffff)], /* celingPriority */
        0,                            /* previousPriority */
        0,                            /* owner */
        resourceapp2                            /* id */
    },
    /* Sys resource resourceapp4 */
    {
        NULL,                         /* NextResource pointer */
        &ResourcesPriority_core1[(resourceapp4 & 0xffff)], /* celingPriority */
        0,                            /* previousPriority */
        0,                            /* owner */
        resourceapp4                            /* id */
    },
};

ResourceAutosarType ResourceAutosar_core0[RESOURCES_COUNT_CORE0] = {
    /* Resource resource1 */
    {
        0 | (1 << app_lion) 
    },
    /* Resource resource2 */
    {
        0 | (1 << app_lion) 
    },
    /* Resource resource3 */
    {
        0 | (1 << app3) 
    },
    /* Resource resourceapp_lion */
    {
        0 | (1 << app_lion) | (1 << app3) 
    },
    /* Resource resourceapp3 */
    {
        0 | (1 << app_lion) | (1 << app3) 
    },
};

ResourceAutosarType ResourceAutosar_core1[RESOURCES_COUNT_CORE1] = {
    /* Resource resource4 */
    {
        0 | (1 << app2) | (1 << app4) 
    },
    /* Resource resource5 */
    {
        0 | (1 << app2) | (1 << app4) 
    },
    /* Resource resource6 */
    {
        0 | (1 << app2) | (1 << app4) 
    },
    /* Resource resourceapp2 */
    {
        0 | (1 << app2) | (1 << app4) 
    },
    /* Resource resourceapp4 */
    {
        0 | (1 << app2) | (1 << app4) 
    },
};

#pragma section

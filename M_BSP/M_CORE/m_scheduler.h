#ifndef __M_SCHEDULER_H
#define __M_SCHEDULER_H

#include "stm32f10x.h"
#include <stdbool.h>
#include "printf.h"

#define SchedulerNumTasks_MAX 16
//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
//! \addtogroup scheduler_api
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
// Prototype of a function that the scheduler can call periodically.
//
//*****************************************************************************
typedef void (*tSchedulerFunction)(void *pvParam);

//*****************************************************************************
//
//! The structure defining a function which the scheduler will call
//! periodically.
//
//*****************************************************************************
typedef struct
{
		const char *Scheduler_Name;
	
    //
    //! A pointer to the function which is to be called periodically by the
    //! scheduler.
    //
    void (*pfnFunction)(void *);

    //
    //! The parameter which is to be passed to this function when it is called.
    //
    void *pvParam;

    //
    //! The frequency the function is to be called expressed in terms of system
    //! ticks.  If this value is 0, the function will be called on every call
    //! to SchedulerRun.
    //
    uint32_t ui32FrequencyTicks;

    //
    //! Tick count when this function was last called.  This field is updated
    //! by the scheduler.
    //
    uint32_t ui32LastCall;

    //
    //! A flag indicating whether or not this task is active.  If true, the
    //! function will be called periodically.  If false, the function is
    //! disabled and will not be called.
    //
    bool bActive ;
}
tSchedulerTask;

//*****************************************************************************
//
//! This global table must be populated by the client and contains information
//! on each function that the scheduler is to call.
//
//*****************************************************************************
extern tSchedulerTask *g_psSchedulerTable;

//*****************************************************************************
//
//! This global variable must be exported by the client.  It must contain the
//! number of entries in the g_psSchedulerTable array.
//
//*****************************************************************************
extern uint32_t g_ui32SchedulerNumTasks;

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
// Public function prototypes
//
//*****************************************************************************
extern void SchedulerSysTickIntHandler(void);
extern void SchedulerInit(uint32_t ui32TicksPerSecond);
extern void SchedulerRun(void);
extern void SchedulerTaskEnable(uint32_t ui32Index, bool bRunNow);
extern void SchedulerTaskDisable(uint32_t ui32Index);
extern uint32_t SchedulerTickCountGet(void);
extern uint32_t SchedulerElapsedTicksGet(uint32_t ui32TickCount);
extern uint32_t SchedulerElapsedTicksCalc(uint32_t ui32TickStart,
                                               uint32_t ui32TickEnd);

extern int Scheduler_Create(const char *Create_Name,uint32_t Scheduler_Frenquency,bool Enable,void (*Func_Callback)(void *), void* UserParameters);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif

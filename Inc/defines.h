/*
 * defines.h
 *
 *  Created on: Nov 22, 2025
 *      Author: PRASHANT AJABE
 */

#ifndef DEFINES_H_
#define DEFINES_H_

#define DUMMY_XPSR				0x01000000
#define MAX_TASKS				2
#define SIZE_TASK_STACK			1024U
#define SIZE_SCHEDULER_STACK	1024U

#define SRAM_START				0x20000000U
#define SRAM_SIZE				( (20) * (1024) )
#define SRAM_END				( (SRAM_START) + (SRAM_SIZE) )

#define TASK1_STACK_START		SRAM_END
#define TASK2_STACK_START		( (SRAM_END) - (1 * SIZE_TASK_STACK) )
#define SHCEDULER_STACK_START	( (SRAM_END) - (2 * SIZE_TASK_STACK) )



#endif /* DEFINES_H_ */

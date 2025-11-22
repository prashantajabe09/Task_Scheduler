/*
 * system.c
 *
 *  Created on: Nov 22, 2025
 *      Author: PRASHANT AJABE
 */


#include "system.h"

void nvic_en_irq(irqn_type irqn)
{
	uint8_t register_position = irqn / 32;
	uint8_t irq_position = irqn % 32;
	NVIC->ISER[register_position] = (1 << irq_position);
}

void systick_init(void)
{
	// Reload Value
	SYSTICK->RVR = 7999; //for 1 ms @ 8 Mhz
	// Clear the current count
	SYSTICK->CVR = 0;

	// Clock Selection
	SYSTICK->CSR |= (1 << 2) | (1 << 1) | ((1 << 0)); //AHB selected

}

void SysTick_Handler(void)
{
	/*
	 * save the context of the current task
	 * 1. Get runing current task's PSP value
	 * 2. Using that PSP value store SF2 (R4 to R11)
	 * 3. save the current value of PSP
	 *
	 * Retrive the context of next task
	 *
	 * 1. Decide next task to run
	 * 2. get its past PSP value
	 * 3. using that PSP value retrieve SF2
	 * 4. update the PSP and exit
	 */
}

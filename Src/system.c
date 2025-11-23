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

__attribute__((naked)) void SysTick_Handler(void)
{
	__asm volatile("MRS R0, PSP"); // Read the PSP value in RO
	 __asm volatile("STMDB R0!, {R4-R11}"); // Save the R4-R11 register to private stack
	 __asm volatile("PUSH {LR}"); // Preserve the LR
	 __asm volatile("BL save_psp_value"); // Save the current tasks PSP to global array.
	 __asm volatile("pop {LR}"); // Retrieve the LR


	 __asm volatile("PUSH {LR}"); // Push LR as we going to call multiple functions below
	  __asm volatile("BL get_next_task"); // decides which task to run next
	  __asm volatile("BL get_psp_value"); // get the next tasks stored PSP. this is the lates PSP of that task.
	  __asm volatile("LDMIA R0!,{R4-R11}"); // retrieve the R4-R11 register values
	  __asm volatile("MSR PSP,R0"); // assing PSP
	  __asm volatile("pop {LR}"); // pop LR
	  __asm volatile("BX LR"); // exit the handler.

}

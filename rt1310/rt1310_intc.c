/*
 * Copyright (c) 2024 Hiroki Mori. All rights reserved.
 */

#include "rt1310_reg.h"

int args[8];

int irq_enable(int irq, int arg)
{
unsigned long *lptr;
unsigned long reg;

	args[irq] = arg;
	lptr = (unsigned long *)(RT_INTC_BASE + RT_INTC_IECR);
	reg = *lptr;
	reg |= (1 << irq);
	*lptr = reg;
	lptr = (unsigned long *)(RT_INTC_BASE + RT_INTC_IMR);
	*lptr = reg;

}

int irq_init(void)
{
	timer_init();
	irq_enable(RT_INTC_TIMER0INT, 0);

	enable_irq();
}

void irqch(void)
{
unsigned long *lptr;
unsigned long status;

	lptr = (unsigned long *)(RT_INTC_BASE + RT_INTC_IPR);
	status = *lptr;

	if (status & (1 << RT_INTC_MAC0INT)) {
		ether_intr(args[RT_INTC_MAC0INT]);
	}
	if (status & (1 << RT_INTC_TIMER0INT)) {
		timer_intr();
	}

	lptr = (unsigned long *)(RT_INTC_BASE + RT_INTC_ICCR);
	*lptr = status;
}

#ifndef CMSIS_H
#define CMSIS_H

#include <generated/autoconf.h>

#ifdef CONFIG_STM32WB55
#include <stm32wb55xx.h>
#endif

#include <cmsis_gcc.h>

#ifdef CONFIG_CORTEX_M
#include <core_cm4.h>
#endif


#endif

#ifndef __MAIN_H
#define __MAIN_H


// MCU header
#include "stm32l4xx.h"

// Internal peripherals
#include "rcc.h"
#include "pwr.h"
#include "gpio.h"
#include "usart.h"
#include "delay.h"
#include "crc.h"
#include "sdcard.h"

// Standard libraries
#include <string.h>


// Clock sources notation, just for nice debugging output
static char const * const _sysclk_src_str[] = {
		"UNKNOWN", "MSI", "HSI", "HSE", "MSI->PLL", "HSI->PLL", "HSE->PLL"
};


// Debug USART port
#define DBG_USART                  USART1

// Alias for printf, redirect output to debug USART port)
#if (USART_USE_PRINTF)
#define printf(...)                USART_printf(DBG_USART, __VA_ARGS__)
#endif


// Separator string
#define sepstr                     "--------------------\r\n"


uint32_t i, j, k;

uint32_t addr;
uint32_t start_addr;
uint32_t blk_size;

volatile uint32_t ms_count;

uint32_t sd_count;
uint32_t sd_error;
uint32_t sd_crc;
uint32_t sd_amount;
uint32_t sd_addr;

uint8_t crc_val;
uint8_t crc_ref;

#endif // __MAIN_H

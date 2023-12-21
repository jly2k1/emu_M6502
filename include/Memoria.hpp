#pragma once

#include <cstdint>
#include <sys/types.h>

const int total_mem = 0x10000;

class Memoria
{
	protected:
		uint8_t pag_zero[0x100];
		uint8_t stack_m[0x100];
		uint8_t datos[total_mem];
};

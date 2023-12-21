#include "../include/M6502.hpp"
#include <cstdint>

using namespace std; 
 

//Accesos a la memoria. 

uint8_t mos6502::Read_mem(uint16_t direccion)
{
	if(direccion <= 0x00FF)
	{
		return mem.pag_zero[direccion];
	}
	else if(direccion > 0x00FF && direccion <= 0x01FF)
	{
		uint32_t dir_exacta;

		dir_exacta = direccion - 0x0100;

		return mem.stack_m[dir_exacta];
	}
	else
	{
		uint32_t dir_exacta;

		dir_exacta = direccion - 0x0200;

		return mem.datos[dir_exacta];
	}

	return 1; //Retornará 1 como un error en el acceso a la memoria.
}

void mos6502::Write_mem(uint16_t direccion, uint8_t datos)
{
	if(direccion <= 0x00FF)
	{
		 mem.pag_zero[direccion] = datos;
	}
	else if(direccion > 0x00FF && direccion <= 0x01FF)
	{
		uint32_t dir_exacta;

		dir_exacta = direccion - 0x0100;

		mem.stack_m[dir_exacta] = datos;
	}
	else
	{
		uint32_t dir_exacta;

		dir_exacta = direccion - 0x0200;

		mem.datos[dir_exacta] = datos;
	}

};

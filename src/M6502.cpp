#include "../include/M6502.hpp"
#include <cstdint>
#include <sys/types.h>

using namespace std; 


//getters y setters

void mos6502::set_PC(uint16_t PC)
{
	this->PC = PC; 
}

uint16_t mos6502::get_PC()
{
	return this->PC;
}

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

//Modos de direccionamiento;

uint16_t mos6502::dic_abs() //Direccionamiento absoluto.
{
	uint16_t dir_comp;
	
	uint16_t pc = get_PC();

	//Parte alta y baja de la direccion.
	uint8_t dir_low =  Read_mem(pc++);
	uint8_t dir_high = Read_mem(pc); 
	
	dir_comp = (dir_low << 8) | dir_high; //obtenemos la direccion completa
	
	return  dir_comp;
}

//modo de direccionamiento abs_x / abs_y 

uint16_t mos6502::dic_imp() //no se ocupa en el emulador. Direccionamiento implicito. 
{
	return 0; 
}

//modo de direccionamiento indirecto (ind).

uint16_t mos6502::dic_rel() //Direccionamiento relativo.
{
	uint16_t pc = get_PC();

	uint16_t dir = Read_mem(pc++);

	if(dir & 0x80)
	{
		dir |= 0xFF00;
	}

	return dir;
}

uint16_t mos6502::dic_zp() //Direccionamiento 'pagina cero' o 'zero page'.
{
	uint16_t pc = get_PC();
	
	uint8_t dir_low = Read_mem(pc++);

	uint16_t dir_comp = 0;

	dir_comp = dir_low;

	return 0;
}

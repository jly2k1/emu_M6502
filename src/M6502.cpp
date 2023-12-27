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

void mos6502::set_regX(uint8_t reg_X)
{
	this->reg_X = reg_X;
}

uint8_t mos6502::get_regX()
{
	return this->reg_X;
}

void mos6502::set_regY(uint8_t reg_Y)
{
	this->reg_Y = reg_Y;
}

uint8_t mos6502::get_regY()
{
	return this->reg_Y;
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

uint16_t mos6502::dic_inm() //direccionamiento inmediato.
{
	uint16_t pc = get_PC();

	return pc++;
}

uint16_t mos6502::dic_abs() //Direccionamiento absoluto.
{
	uint16_t dir_comp;
	
	uint16_t pc = get_PC();

	//Parte alta y baja de la direccion.
	uint8_t dir_low =  Read_mem(pc);
	uint8_t dir_high = Read_mem(pc++); 
	
	dir_comp = (dir_high << 8) | dir_low; //obtenemos la direccion completa
	
	return  dir_comp;
}

uint16_t mos6502::dic_absX() //Modo de direccionamiento absoluto-X
{
	uint16_t pc = get_PC();

	uint16_t dir_low = Read_mem(pc);
	uint16_t dir_high = Read_mem(pc++);

	uint16_t dir_comp = (dir_high << 8) | dir_low;

	dir_comp += get_regX();

	return dir_comp;
}

uint16_t mos6502::dic_absY() //Modo de direccionamiento absoluto-Y
{
	uint16_t pc = get_PC();

	uint16_t dir_low = Read_mem(pc);
	uint16_t dir_high = Read_mem(pc++);

	uint16_t dir_comp = (dir_high << 8) | dir_low;

	dir_comp += get_regY();

	return dir_comp;

}

uint16_t mos6502::dic_imp() //no se ocupa en el emulador. Direccionamiento implicito. 
{
	return 0; 
}

uint16_t mos6502::dic_ind() //modo de direccionamiento indirecto. !
{
	uint16_t pc = get_PC();
	
	uint8_t dir_low = Read_mem(pc);
	uint8_t dir_high = Read_mem(pc++);

	uint16_t dir_comp = (dir_high << 8) | dir_low;
	
	uint16_t dir_real;

	if(dir_comp == 0x00FF) //Evitamos bug al cruzar el limite de una pagina de la memoria. 
	{
		dir_real = (Read_mem(dir_comp & 0xFF00) << 8) | Read_mem(dir_comp);
	}
	else
	{
		dir_real = (Read_mem(dir_comp + 1) << 8) | Read_mem(dir_comp);
	}

	return dir_real;
}

uint16_t mos6502::dic_indX() //Modo de direccionamiento indirecto-X
{
	uint16_t pc = get_PC();

	uint16_t dir_zpl = Read_mem(pc);
	uint16_t dir_zph = 0; 

		
	dir_zpl += get_regX();
	dir_zpl &= 0x00FF; 
	 
	dir_zph = (dir_zpl + 1) & 0x00FF; 

	uint16_t dir_real = (Read_mem(dir_zph) << 8) + Read_mem(dir_zpl);
	
	return dir_real;
}

uint16_t mos6502::dic_indY() //Modo de direccionamiento-Y
{
	uint16_t pc = get_PC();

	uint16_t dir_zpl = Read_mem(pc);
	uint16_t dir_zph = 0; 

		
	dir_zpl += get_regY();
	dir_zpl &= 0x00FF; 
	 
	dir_zph = (dir_zpl + 1) & 0x00FF; 

	uint16_t dir_real = (Read_mem(dir_zph) << 8) + Read_mem(dir_zpl);
	
	return dir_real;

}

uint16_t mos6502::dic_rel() //Direccionamiento relativo.
{
	uint16_t pc = get_PC();

	uint16_t dir = Read_mem(pc); //!

	if(dir & 0x80)
	{
		dir |= 0xFF00;
	}

	return dir;
}

uint16_t mos6502::dic_zp() //Direccionamiento 'pagina cero' o 'zero page'.
{
	uint16_t pc = get_PC();
	
	uint8_t dir_low = Read_mem(pc);

	uint16_t dir_comp = 0;

	dir_comp = dir_low;

	return dir_comp;
}

uint16_t mos6502::dic_zpX() //Modo de direccionamiento pagina cero-X
{
	uint16_t pc = get_PC();
	
	uint8_t dir_low = Read_mem(pc);

	uint16_t dir_comp = 0;

	dir_comp = dir_low;
	
	dir_comp += get_regX();

	return dir_comp;
}

uint16_t mos6502::dic_zpY() //Modo de direccionamiento pagina cero-Y
{	
	uint16_t pc = get_PC();
	
	uint8_t dir_low = Read_mem(pc);

	uint16_t dir_comp = 0;

	dir_comp = dir_low;
	
	dir_comp += get_regY();

	return dir_comp;
}

#pragma once

#include <cstdint>
#include <string>

using namespace std;

const uint8_t CARRY_FLAG = 0x01;
const uint8_t ZERO_FLAG = 0x02;
const uint8_t INT_FLAG = 0x04;
const uint8_t DEC_FLAG = 0x08;
const uint8_t BRK_FLAG = 0x10;
const uint8_t OVERFLOW_FLAG = 0x40;
const uint8_t SIG_FLAG = 0x80;

class mos6502 
{
	protected:
		//Registros

		uint8_t acumulador;
		uint8_t reg_X;
		uint8_t reg_Y;
		uint16_t PC; //Contador de programa.
		uint8_t SP; //Puntero de pila.
		uint8_t reg_estado; //registro de estado (FLAGS).
		
		//Instrucciones.
		struct instruccion
		{
			string *nombre;
			uint8_t (*opcode)(void);
			uint8_t (*modo)(void);
			uint8_t ciclos;
		};

		struct instruccion instrucciones[256];

			
};

#pragma once

#include <cstdint>
#include <string>
#include <sys/types.h>
#include "../include/Memoria.hpp"

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
		
		//Memoria
		Memoria mem;

		//Instrucciones.
		struct instruccion
		{
			string *nombre;
			uint8_t (*opcode)(void);
			uint8_t (*modo)(void);
			uint8_t ciclos;
		};

		struct instruccion instrucciones[256];

		public:
			//Memoria.

			uint8_t Read_mem(uint16_t direccion);
			void Write_mem(uint16_t direccion, uint8_t datos);

			//Modos de direccionamiento. 
			uint8_t dic_abs();
			uint8_t dic_absX();
			uint8_t dic_absY();
			uint8_t dic_imp();
			uint8_t dic_ind();
			uint8_t dic_indX();
			uint8_t dic_indY();
			uint8_t dic_rel();
			uint8_t dic_zp();
			uint8_t dic_zpX();
			uint8_t dic_zpY();	
};

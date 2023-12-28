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
			//getters y setters.
			
			void set_acum(uint8_t acumulador);
			uint8_t get_acum();
			void set_regX(uint8_t reg_X);
			uint8_t get_regX();
			void set_regY(uint8_t reg_Y);
			uint8_t get_regY();			
			void set_PC(uint16_t PC);
			uint16_t get_PC();
			void set_SP(uint8_t SP);
			uint8_t get_SP();
			void set_regEst(uint8_t reg_estado);
			uint8_t get_regEst();

			//Memoria.

			uint8_t Read_mem(uint16_t direccion);
			void Write_mem(uint16_t direccion, uint8_t datos);
			
			//Modos de direccionamiento. 
			uint16_t dic_inm();
			uint16_t dic_abs();
			uint16_t dic_absX();
			uint16_t dic_absY();
			uint16_t dic_imp();
			uint16_t dic_ind();
			uint16_t dic_indX();
			uint16_t dic_indY();
			uint16_t dic_rel();
			uint16_t dic_zp();
			uint16_t dic_zpX();
			uint16_t dic_zpY();	

			//Opcodes.

			void op_LDA(uint16_t dir);
			void op_LDX(uint16_t dir);
			void op_LDY(uint16_t dir);
			void op_STA(uint16_t dir);
			void op_STX(uint16_t dir);
			void op_STY(uint16_t dir);
			
			void op_TAX(uint16_t dir);
			void op_TAY(uint16_t dir);
			void op_TSX(uint16_t dir);
			void op_TXA(uint16_t dir);
			void op_TXS(uint16_t dir);
			void op_TYA(uint16_t dir);
};

//*****************************************************************************
//--ALUSimulator.c
//
//		Author: 		Gary J. Minden
//		Organization:	KU/EECS/EECS 645
//		Date:			2017-04-22 (B70422)
//		Version:		1.0
//		Description:	This is the test standin for a simple ALU simulator
//		Notes:
//
//*****************************************************************************
//

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>

#include <stdio.h>
#include <stdlib.h>

#include "RegisterFile_01.h"
#include "ALUSimulator.h"

uint32_t WrtAddr = 9;

extern void ALUSimulator( RegisterFile theRegisterFile,
				uint32_t OpCode,
				uint32_t Rs, uint32_t Rt, uint32_t Rd,
				uint32_t ShiftAmt,
				uint32_t FunctionCode,
				uint32_t ImmediateValue,
				uint32_t* Status ) {
				
	printf( ">>ALU: Opcode: %02X; Rs: %02X; Rt: %02X; Rd: %02X;\n",
				OpCode,
				Rs,
				Rt,
				Rd );
				
	printf( ">>>>ALU: ShiftAmt: %02X; FunctionCode: %02X; ImmediateValue: %04X;\n",
				ShiftAmt,
				FunctionCode,
				ImmediateValue );
				
//gcc -o ALUSimulator_Main AluSimulator_Main.c AlUSimulator.c RegisterFIle_01.c -I.

	// ./ALUSimulator_Main
uint32_t* RdValue_S = NULL;
uint32_t* RdValue_T = NULL;

RdValue_S = malloc(sizeof(uint32_t));
RdValue_T = malloc(sizeof(uint32_t));

RegisterFile_Read(  theRegisterFile,
								 Rs, RdValue_S,
								 Rt,  RdValue_T );

	if(OpCode == 000000){
		if(FunctionCode == 000000){ //NOOP/SLL no op / shift left logical
			Rd = *RdValue_S << 1;
		}
		else if(FunctionCode == 000010){ //SRL shift right logical
			Rd = *RdValue_S >> 1;
		}
		else if(FunctionCode == 000011){ // SRA shift right arithmetic //0x03
			Rd = *RdValue_S >> 1;
		}
		else if(FunctionCode == 000100){ // SLLV shift left logical variable amount
			Rd = *RdValue_S << ShiftAmt;
		}
		else if(FunctionCode == 000110){ //SRLV shift right logical variable amount
			Rd = *RdValue_S >> ShiftAmt;
		}
		else if(FunctionCode == 100000){ // ADD
			Rd = *RdValue_S + *RdValue_T;
		}
		else if(FunctionCode == 100001){ // ADDU
			Rd = *RdValue_S + *RdValue_T;
		}
		else if(FunctionCode == 100010){ // SUB
			Rd = *RdValue_S - *RdValue_T;
		}
		else if(FunctionCode == 100011){ // SUBU
			Rd = *RdValue_S - *RdValue_T;
		}
		else if(FunctionCode == 100100){ // AND
			Rd = *RdValue_S & *RdValue_T;
		}
		else if(FunctionCode == 100101){ // OR
			Rd = *RdValue_S | *RdValue_T;
		}
		else if(FunctionCode == 100110){ // XOR
			Rd = *RdValue_S ^ *RdValue_T;
		}
		else if(FunctionCode == 101010){ // SLT
			Rd = (*RdValue_S < *RdValue_T);
		}
		else if(FunctionCode == 101011){ // SLTU DOES THIS RETURN BOOL OR INT?
			Rd = (*RdValue_S < *RdValue_T);
		}
	}
	else if(OpCode == 001000){ // ADDI
		*RdValue_T = *RdValue_S + ImmediateValue;
	}
	else if(OpCode == 001001){ //ADDIU
		*RdValue_T = *RdValue_S + ImmediateValue;
	}
	else if (OpCode == 001010){ // SLTI
		*RdValue_T = (*RdValue_S < ImmediateValue);
	}
	else if (OpCode == 001011){ // SLTIU
		*RdValue_T = (*RdValue_S < ImmediateValue);
	}

	if(OpCode == 000000){
		RegisterFile_Write(  theRegisterFile, 1, WrtAddr, Rd );
	}
	else{
		RegisterFile_Write(  theRegisterFile, 1, WrtAddr, *RdValue_T );
	}
	WrtAddr++;
}				

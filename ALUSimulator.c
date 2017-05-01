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

	if(OpCode == 0x00){
		if(FunctionCode == 0x00){ //NOOP/SLL no op / shift left logical
			Rd = *RdValue_S << 1;
		}
		else if(FunctionCode == 0x02){ //SRL shift right logical
			Rd = *RdValue_S >> 1;
		}
		else if(FunctionCode == 0x03){ // SRA shift right arithmetic //0x03
			Rd = *RdValue_S >> 1;
		}
		else if(FunctionCode == 0x04){ // SLLV shift left logical variable amount
			Rd = *RdValue_S << ShiftAmt;
		}
		else if(FunctionCode == 0x06){ //SRLV shift right logical variable amount
			Rd = *RdValue_S >> ShiftAmt;
		}
		else if(FunctionCode == 0x20){ // ADD
			Rd = *RdValue_S + *RdValue_T;
		}
		else if(FunctionCode == 0x21){ // ADDU
			Rd = *RdValue_S + *RdValue_T;
		}
		else if(FunctionCode == 0x22){ // SUB
			Rd = *RdValue_S - *RdValue_T;
		}
		else if(FunctionCode == 0x23){ // SUBU
			Rd = *RdValue_S - *RdValue_T;
		}
		else if(FunctionCode == 0x24){ // AND
			Rd = *RdValue_S & *RdValue_T;
		}
		else if(FunctionCode == 0x25){ // OR
			Rd = *RdValue_S | *RdValue_T;
		}
		else if(FunctionCode == 0x26){ // XOR
			Rd = *RdValue_S ^ *RdValue_T;
		}
		else if(FunctionCode == 0x2A){ // SLT
			Rd = (*RdValue_S < *RdValue_T);
		}
		else if(FunctionCode == 0x2B){ // SLTU DOES THIS RETURN BOOL OR INT?
			Rd = (*RdValue_S < *RdValue_T);
		}
	}
	else if(OpCode == 0x08){ // ADDI
		*RdValue_T = *RdValue_S + ImmediateValue;
	}
	else if(OpCode == 0x09){ //ADDIU
		*RdValue_T = *RdValue_S + ImmediateValue;
	}
	else if (OpCode == 0x0A){ // SLTI
		*RdValue_T = (*RdValue_S < ImmediateValue);
	}
	else if (OpCode == 0x0B){ // SLTIU
		*RdValue_T = (*RdValue_S < ImmediateValue);
	}

	if(OpCode == 0x00){
		RegisterFile_Write(  theRegisterFile, 1, WrtAddr, Rd );
	}
	else{
		RegisterFile_Write(  theRegisterFile, 1, WrtAddr, *RdValue_T );
	}
	WrtAddr++;
}				

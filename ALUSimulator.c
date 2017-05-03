
#include "ALUSimulator.h"
#include "RegisterFile.h"
#include <string.h>
#include <math.h>
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

#include "RegisterFile.h"
#include "ALUSimulator.h"

//uint32_t WrtAddr = 9;

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

//	printf( ">>>>ALU: ShiftAmt: %02X; FunctionCode: %02X; ImmediateValue: %04X;\n",
//				ShiftAmt,
//				FunctionCode,
//				ImmediateValue );

//gcc -o ALUSimulator_Main ALUSimulator_Main.c ALUSimulator.c RegisterFile_01.c -I.

	// ./ALUSimulator_Main
uint32_t* RdValue_S = NULL;
uint32_t* RdValue_T = NULL;

RdValue_S = malloc(sizeof(uint32_t));
RdValue_T = malloc(sizeof(uint32_t));

uint32_t result = 0;

RegisterFile_Read(theRegisterFile,Rs, RdValue_S, Rt, RdValue_T);

	if(OpCode == 0){
		if(FunctionCode == 0){ //NOOP/SLL no op / shift left logical
            printf("sll \n");
			result = *RdValue_S << ShiftAmt;
		}
		else if(FunctionCode == 2){ //SRL shift right logical
			result = *RdValue_S >> ShiftAmt;
		}
		else if(FunctionCode == 3){ // SRA shift right arithmetic //0x03
			result = *RdValue_S >> ShiftAmt;
		}
		else if(FunctionCode == 4){ // SLLV shift left logical variable amount
			result = *RdValue_S << *RdValue_T;
		}
		else if(FunctionCode == 6){ //SRLV shift right logical variable amount
			result = *RdValue_S >> *RdValue_T;
		}
		else if(FunctionCode == 32){ // ADD
                        printf("add \n");
			result = *RdValue_S + *RdValue_T;
		}
		else if(FunctionCode == 33){ // ADDU
			result = *RdValue_S + *RdValue_T;
		}
		else if(FunctionCode == 34){ // SUB
            printf("sub \n");
			result = *RdValue_S - *RdValue_T;
		}
		else if(FunctionCode == 35){ // SUBU
			result = *RdValue_S - *RdValue_T;
		}
		else if(FunctionCode == 36){ // AND
			result = *RdValue_S & *RdValue_T;
		}
		else if(FunctionCode == 37){ // OR
		            printf("or \n");
			result = *RdValue_S | *RdValue_T;
		}
		else if(FunctionCode == 38){ // XOR
		            printf("xor \n");
			result = *RdValue_S ^ *RdValue_T;
		}
		else if(FunctionCode == 42){ // SLT
			result = (*RdValue_S < *RdValue_T);
		}
		else if(FunctionCode == 43){ // SLTU DOES THIS RETURN BOOL OR INT?
			result = (*RdValue_S < *RdValue_T);
		}

		RegisterFile_Write(theRegisterFile, 1, Rd, result);
	}

	else if(OpCode == 8){ // ADDI
        printf("addi \n");
		result = *RdValue_S + ImmediateValue;
		RegisterFile_Write(theRegisterFile, 1, Rt, result);
	}
	else if(OpCode == 9){ //ADDIU
		result = *RdValue_S + ImmediateValue;
		RegisterFile_Write(theRegisterFile, 1, Rt, result);
	}
	else if (OpCode == 10){ // SLTI
		result = (*RdValue_S < ImmediateValue);
        RegisterFile_Write(theRegisterFile, 1, Rt, result);
	}
	else if (OpCode == 11){ // SLTIU
		result = (*RdValue_S < ImmediateValue);
        RegisterFile_Write(theRegisterFile, 1, Rt, result);
	}

}

//  Created by Patrick Beuhler April 26, 2017.
//  Copyright 2017 Patrick Beuhler. All rights reserved.
//
//  
//
//
//	Description:
//			This program simulates an ALU.
//

#include <stdio.h>
#include <time.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>

#include "RegisterFile_01.h"



extern void ALUSimulator( RegisterFile theRegisterFile, uint32_t OpCode, uint32_t Rs, uint32_t Rt, 
								uint32_t Rd, uint32_t ShiftAmt, uint32_t FunctionCode, uint32_t ImmediateValue
								uint32_t* Status) {
/*
RegisterFile_Read( theRegisterFile,
								uint32_t RdAddr_S, uint32_t* RdValue_S,
								uint32_t RdAddr_T, uint32_t* RdValue_T );
*/

	if(OpCode == 000000){
		if(FunctionCode == 00_0000){ //NOOP/SLL no op / shift left logical
			Rd = Rs << 1;
		}
		else if(FunctionCode == 00_0010){ //SRL shift right logical
			Rd = Rs >> 1;
		}
		else if(FunctionCode == 00_0011){ // SRA shift right arithmetic
			Rd = Rs >> 1;
		}
		else if(FunctionCode == 00_0100){ // SLLV shift left logical variable amount
			Rd = Rs << ShiftAmt;
		}
		else if(FunctionCode == 00_0110){ //SRLV shift right logical variable amount
			Rd = Rs >> ShiftAmt;
		}
		else if(FunctionCode == 01_0000){ //MFHI move from high, get the top 32 bits?
			
		}
		else if(FunctionCode == 01_0010){ // MFLO get the lower 32 bits?
			
		}
		else if(FunctionCode == 01_1000){ // MULT Need to check for overflow! still to do

		}
		else if(FunctionCode == 01_1001){ // MULTU
			Rd = Rs * Rt;
		}
		else if(FunctionCode == 01_1010){ // DIV

		}
		else if(FunctionCode == 01_1011){ // DIVU
			Rd = Rs / Rt;
		}
		else if(FunctionCode == 10_0000){ // ADD
			
		}
		else if(FunctionCode == 10_0001){ // ADDU
			Rd = Rs + Rt;
		}
		else if(FunctionCode == 10_0010){ // SUB
			
		}
		else if(FunctionCode == 10_0011){ // SUBU
			Rd = Rs - Rt;
		}
		else if(FunctionCode == 10_0100){ // AND
			Rd = Rs & Rt;
		}
		else if(FunctionCode == 10_0101){ // OR
			Rd = Rs | Rt;
		}
		else if(FunctionCode == 10_0110){ // XOR
			Rd = Rs ^ Rt;
		}
		else if(FunctionCode == 10_1010){ // SLT
			
		}
		else if(FunctionCode == 10_1011){ // SLTU DOES THIS RETURN BOOL OR INT?
			Rd = (Rs < Rt);
		}
	}
	else if(OpCode == 001000){ // ADDI

	}
	else if(OpCode == 001001){ //ADDIU
		Rd = Rs + ImmediateValue;
	}
	else if (OpCode == 001010){ // SLTI

	}
	else if (OpCode == 001011){ // SLTIU
			Rd = (Rs < ImmediateValue);
	}
				
}

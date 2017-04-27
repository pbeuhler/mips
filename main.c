#include <stdio.h>
#include <stdlib.h>
#include "RegisterFile.h"

int main()
{
    printf("ALU Simulation \n");

    //1)INITIALIZE CONTENTS OF REGISTER FILE

    //Register file object
    RegisterFile thefile;
    //MIPS instructions set
    //32 bit -> 31 ... 0
    // 6 -> 5 -> 5 -> 5-> 5-> 6
    uint32_t OpCode;
    int op_mask = (1 << 6) - 1; //6

    uint32_t Rs;
    int rs_mask = (1 << 5)-1;  // 5

    uint32_t Rt; // 5

    uint32_t Rd;// 5

    uint32_t ShiftAmt; // 5

    uint32_t FunctionCode; // 6

    //NO IDEA
    uint32_t ImmediateValue;
    uint32_t* Status;

    //1) END

    //read file in binary
    FILE *file = NULL;
    file = fopen("file_name.bin","rb");


    //open checker
    if(!file){
        printf("file not open \n");
    }
    else{
    //get length
    uint32_t length = get_length(file);

    //place temporarily values on buffer array
    int* buffer= new int[length];


    //2) LOAD A LIST OF INSTRUCTIONS FROM A FILE

    //read data from file with 4 bytes at a time
    fread(buffer,4,length,file);

    //2) END

    for(int i=0; i< length; i++){
        //Set fields to their corresponding values

        OpCode = (buffer[i] >> bits-6) & op_mask;
        Rs = (buffer[i] >> bits-(5+6)) & rs_mask;
        Rt = (buffer[i] >> bits-(5+5+6)) & rs_mask;
        Rd = (buffer[i] >> bits-(5+5+6+5)) & rs_mask;
        ShiftAmt = (buffer[i] >> bits-(5+5+6+5+5)) & rs_mask;
        FunctionCode = (buffer[i] >> 0) & op_mask;

        //3) CALL SIMULATOR FOR EACH INSTRUCTION
        ALUSimulator(thefile, OpCode, Rs, Rt, Rd, ShiftAmt, FunctionCode, ImmediateValue, Status);
        //3) END
    }

    }//end for loop

    return 0;
} //end main

extern void ALUSimulator( RegisterFile theRegisterFile, uint32_t OpCode, uint32_t Rs, uint32_t Rt, 
								uint32_t Rd, uint32_t ShiftAmt, uint32_t FunctionCode, uint32_t ImmediateValue
								uint32_t* Status) {

	if(OpCode == 000000){
		if(FunctionCode == 00_0000){ //NOOP/SLL

		}
		else if(FunctionCode == 00_0010){ //SRL

		}
		else if(FunctionCode == 00_0011){ // SRA
			
		}
		else if(FunctionCode == 00_0100){ // SLLV
			
		}
		else if(FunctionCode == 00_0110){ //SRLV
			
		}
		else if(FunctionCode == 01_0000){ //MFHI
			
		}
		else if(FunctionCode == 01_0010){ // MFLO
			
		}
		else if(FunctionCode == 01_1000){ // MULT
			
		}
		else if(FunctionCode == 01_1001){ // MULTU
			
		}
		else if(FunctionCode == 01_1010){ // DIV
			
		}
		else if(FunctionCode == 01_1011){ // DIVU
			
		}
		else if(FunctionCode == 10_0000){ // ADD
			
		}
		else if(FunctionCode == 10_0001){ // ADDU
			
		}
		else if(FunctionCode == 10_0010){ // SUB
			
		}
		else if(FunctionCode == 10_0011){ // SUBU
			
		}
		else if(FunctionCode == 10_0100){ // AND
			
		}
		else if(FunctionCode == 10_0101){ // OR
			
		}
		else if(FunctionCode == 10_0110){ // XOR
			
		}
		else if(FunctionCode == 10_1010){ // SLT
			
		}
		else if(FunctionCode == 10_1011){ // SLTU
			
		}
	}
	else if(OpCode == 001000){ // ADDI

	}
	else if(OpCode == 001001){ //ADDIU

	}
	else if (OpCode == 001010){ // SLTI

	}
	else if (OpCode == 001011){ // SLTIU

	}
				
}

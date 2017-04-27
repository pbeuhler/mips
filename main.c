#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("ALU Simulations \n");

    //1)INITIALIZE CONTENTS OF REGISTER FILE

    //file
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

ALUSimulator(RegisterFile thefile, uint32_t OpCode, uint32_t Rs,
    uint32_t Rt, uint32_t Rd, uint32_t ShiftAmt, uint32_t FunctionCode,
        uint32_t ImmediateValue, uint32_t* Status){



}

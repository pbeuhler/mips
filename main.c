#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("ALU Simulations \n");
    //file
    RegisterFile thefile;
    //MIPS instructions set
    //32 bit -> 31 ... 0
    uint32_t OpCode;
    //ignore last 26 bits 32-26 = 6
    int op_mask = (1 << 26-1)-1; //6
    uint32_t Rs;
    int rs_mask = (1 << 21-1)-1;  // 5
    uint32_t Rt;
    int rt_mask = (1 << 16-1)-1; // 5
    uint32_t Rd;
    int rd_mask = (1 << 11-1)-1; // 5
    uint32_t ShiftAmt; // 5
    int shift_mask = (1 << 26-1)-1;
    uint32_t FunctionCode; // 6
    int func_mask = (1 << 31-6)-1

    //NO IDEA
    uint32_t ImmediateValue;
    uint32_t* Status;

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

    //read data from file with 4 bytes at a time
    fread(buffer,4,length,file);

    for(int i=0; i< length; i++){
        //address length
        OpCode = (buffer[i] >> 32-6) & (6-1) ;
        Rs = (buffer[i] >> 32-(5+6)) & ();
        Rt = (buffer[i] >> 32-(5+5+6));
        Rd = (buffer[i] >> 32-6);
        OpCode = (buffer[i] >> 32-6);
        ALUSimulator();
    }

    }
    return 0;
}

ALUSimulator(RegisterFile thefile, uint32_t OpCode, uint32_t Rs,
    uint32_t Rt, uint32_t Rd, uint32_t ShiftAmt, uint32_t FunctionCode,
        uint32_t ImmediateValue, uint32_t* Status){



}

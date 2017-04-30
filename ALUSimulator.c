
#include "ALUSimulator.h"
#include "RegisterFile.h"
#include <string.h>
//MFHI
//MFLO
//MULT
//MULTU
//DIV
//DIVU

extern void ALUSimulator( RegisterFile theRegisterFile,
				uint32_t OpCode,
				uint32_t Rs, uint32_t Rt, uint32_t Rd,
				uint32_t ShiftAmt,
				uint32_t FunctionCode,
				uint32_t ImmediateValue,
				uint32_t* Status ){

				//storage pointers
				uint32_t* p_s ;
				uint32_t* p_t ;

				uint32_t result = 0;
                //printf("AQUIIIIIIIIIIIII %d", theRegisterFile[3]);

                //NOOP //SLL
                if(FunctionCode == 0){
                      //nothing
                }
                //SRL
                if(FunctionCode == 2){
                    RegisterFile_Read(theRegisterFile,Rs,p_s,Rt,p_t);
                    int rt = *p_t;
                    result = (rt/ 2*(ShiftAmt));
                    RegisterFile_Write(theRegisterFile,true,Rd,result);
                }
                //SRA //srl with msb being the sign
                if(FunctionCode == 4){
                    RegisterFile_Read(theRegisterFile,Rs,p_s,Rt,p_t);
                }
                //SLLV
                if(FunctionCode == 6){
                      RegisterFile_Read(theRegisterFile,Rs,p_s,Rt,p_t);
                      int rs = *p_s;
                      int rt = *p_t;
                      result = (rt*(2*(rs)));
                      RegisterFile_Write(theRegisterFile,true,Rd,result);
                }
                //SRLV
                if(FunctionCode == 8){
                      RegisterFile_Read(theRegisterFile,Rs,p_s,Rt,p_t);
                      int rs = *p_s;
                      int rt = *p_t;
                      result = (rt/(2*(rs)));
                      RegisterFile_Write(theRegisterFile,true,Rd,result);
                }
                //ADD // disregard overflow
                if(FunctionCode == 32){
                      RegisterFile_Read(theRegisterFile,Rs,p_s,Rt,p_t);
                      int rs = *p_s;
                      int rt = *p_t;
                      result = rs+rt;

                    //do overflow
                      result = (rt+(2*(rs)));
                      RegisterFile_Write(theRegisterFile,true,Rd,result);
                }
                //ADDU // overflow
                if(FunctionCode == 33){
                      RegisterFile_Read(theRegisterFile,Rs,p_s,Rt,p_t);
                      int rs = *p_s;
                      int rt = *p_t;
                      result = (rt+rs);
                      RegisterFile_Write(theRegisterFile,true,Rd,result);
                }
                //SUB
                if(FunctionCode == 34){
                      RegisterFile_Read(theRegisterFile,Rs,p_s,Rt,p_t);
                      int rs = *p_s;
                      int rt = *p_t;
                      result = (rt-rs);
                      RegisterFile_Write(theRegisterFile,true,Rd,result);
                }
                //SUBU
                if(FunctionCode == 35){
                      RegisterFile_Read(theRegisterFile,Rs,p_s,Rt,p_t);
                      int rs = *p_s;
                      int rt = *p_t;
                      result = (rt-rs);
                      if(result < 0){result = result*(-1);}
                      RegisterFile_Write(theRegisterFile,true,Rd,result);
                }
}

extern void binary(uint32_t* rs, uint32_t* rt){
    char s[20];
    char t[20];

    int x = *rs;
    int y = *rt;

    itoa(x,s,2);
    itoa(y,t,2);

    *rs = atoi(s);
    *rt = atoi(t);
}

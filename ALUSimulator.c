
#include "ALUSimulator.h"
#include "RegisterFile.h"

extern void ALUSimulator( RegisterFile theRegisterFile,
				uint32_t OpCode,
				uint32_t Rs, uint32_t Rt, uint32_t Rd,
				uint32_t ShiftAmt,
				uint32_t FunctionCode,
				uint32_t ImmediateValue,
				uint32_t* Status ){

				//storage pointers
				uint32_t* p_s = NULL;
				uint32_t* p_t = NULL;

				uint32_t result = 0;

                //SRLV
                if(OpCode == 8){
                    RegisterFile_Read(theRegisterFile,Rs, p_s,Rt,p_t);
                    int x = p_t;
                    int y = p_s;
                    printf("%d and %d", x,y);
//                    result = (*p_t/ (2*(*p_s)));
                    //RegisterFile_Write(theRegisterFile,true,Rd,result);
                }

}

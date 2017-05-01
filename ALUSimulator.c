
#include "ALUSimulator.h"
#include "RegisterFile.h"
#include <string.h>
#include <math.h>
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
				uint32_t* p_s = NULL;
				uint32_t* p_t = NULL;
				uint32_t result = 0;
                //NOOP idk

                //SLL // done
                if(FunctionCode == 0){
                    RegisterFile_Read(theRegisterFile,Rs,p_s,Rt,p_t);
                    int rt = p_t;
                    result = (rt*2*(ShiftAmt));
                    RegisterFile_Write(theRegisterFile,true,Rd,result);
                }
                //SRL //done
                if(FunctionCode == 2){
                    RegisterFile_Read(theRegisterFile,Rs,p_s,Rt,p_t);
                    int rt = p_t;
                    result = (rt/ 2*(ShiftAmt));
                    RegisterFile_Write(theRegisterFile,true,Rd,result);
                }
                //SRA //srl with msb being the sign
                if(FunctionCode == 4){
                    RegisterFile_Read(theRegisterFile,Rs,p_s,Rt,p_t);
                    int rs = p_s;
                    int rt = p_t;

                    binary(p_s,p_t);
                    //need to check Rt sign

                    //msb
                    if(p_t[0] == 1){
                        p_t[0] = 0;
                        int i, j;

                        for(j; j <ShiftAmt; j++){
                        for(i = 1 ; i<strlen(p_t)-1; i++){
                            p_t[i] = p_t[i-1];
                        }
                        }

                        p_t[0] = 1;
                        result = atoi(p_t);
                    }
                    else{
                        result = (rt/(2*(ShiftAmt)));
                    }
                    RegisterFile_Write(theRegisterFile,true,Rd,result);

                }
                //SLLV // done
                if(FunctionCode == 6){
                      RegisterFile_Read(theRegisterFile,Rs,p_s,Rt,p_t);
                      int rs = p_s;
                      int rt = p_t;
                      result = (rt*(2*(rs)));
                      RegisterFile_Write(theRegisterFile,true,Rd,result);
                }
                //SRLV // done
                if(FunctionCode == 8){
                      RegisterFile_Read(theRegisterFile,Rs,p_s,Rt,p_t);
                      int rs = p_s;
                      int rt = p_t;
                      result = (rt/(2*(rs)));
                      RegisterFile_Write(theRegisterFile,true,Rd,result);
                }
                //ADD //overflow //done
                if(FunctionCode == 32){
                      RegisterFile_Read(theRegisterFile,Rs,p_s,Rt,p_t);
                      int rs = p_s;
                      int rt = p_t;
                      result = rs+rt;

                      char s[] = binary(p_s);
                      char t[] = binary(p_t);

                        int m_len = 0;
                        if(strlen(s) > strlen(t)){m_len = pow(2,strlen(s));}
                        if(strlen(t) > strlen(s)){m_len = pow(2,strlen(l);}
                        else{m_len = pow(2,strlen(s);}

                        if(result > pow(2,m_len)){
                            //carry
                            Status = 1;
                        }
                      RegisterFile_Write(theRegisterFile,true,Rd,result);
                }
                //ADDU //no overflow // done
                if(FunctionCode == 33){
                      RegisterFile_Read(theRegisterFile,Rs,p_s,Rt,p_t);
                      int rs = p_s;
                      int rt = p_t;
                      result = (rt+rs);
                      RegisterFile_Write(theRegisterFile,true,Rd,result);
                }
                //SUB //done
                if(FunctionCode == 34){
                      RegisterFile_Read(theRegisterFile,Rs,p_s,Rt,p_t);
                      int rs = p_s;
                      int rt = p_t;
                      result = (rt-rs);
                      RegisterFile_Write(theRegisterFile,true,Rd,result);
                }
                //SUBU //done
                if(FunctionCode == 35){
                      RegisterFile_Read(theRegisterFile,Rs,p_s,Rt,p_t);
                      int rs = p_s;
                      int rt = p_t;
                      result = (rt-rs);
                      if(result < 0){result = result*(-1);}
                      RegisterFile_Write(theRegisterFile,true,Rd,result);
                }
                //AND
                if(FunctionCode == 36){
                RegisterFile_Read(theRegisterFile,Rs,p_s,Rt,p_t);
                int rs = p_s;
                int rt = p_t;

                binary(p_s);
                binary(p_t);


                RegisterFile_Write(theRegisterFile,true,Rd,result);
                }
                //OR
                if(FunctionCode == 37){}
                //XOR
                if(FunctionCode == 38){}

}

extern void binary(uint32_t* rs){
    char s[20];
    //give value from pointer
    int x = rs;
    //convert number x and y to binary char s and t
    itoa(x,s,2);
    //store string in pointers
    rs = s;
}

extern void check_binary(uint32_t* rs, uint32_t* rt, int option){
    rs = binary(rs);
    rt = binary(rt);
}

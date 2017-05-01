#ifndef __ALUSimulator_H_
#define __ALUSimulator_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>

#include "RegisterFile.h"

extern void ALUSimulator( RegisterFile theRegisterFile,
				uint32_t OpCode,
				uint32_t Rs, uint32_t Rt, uint32_t Rd,
				uint32_t ShiftAmt,
				uint32_t FunctionCode,
				uint32_t ImmediateValue,
				uint32_t* Status );
extern void binary(uint32_t* rs);
extern void binary_op(uint32_t* rs, uint32_t* rt, int option);


#endif

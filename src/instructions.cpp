
#include "instructions.h"

uint64_t I_Inst::get_IMM(I_Inst* inst){
	return inst.imm11_0;
}

uint64_t I_Inst::get_IMM(I_Inst* inst){
	return (inst.imm11_0 & 0x01F);
}

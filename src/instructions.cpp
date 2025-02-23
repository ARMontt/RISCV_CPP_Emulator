
#include "instructions.h"

uint64_t I_Inst::I_IMM(I_Inst* inst){
	return inst->imm11_0;
}

uint64_t I_Inst::I_SHAMT(I_Inst* inst){
	return (inst->imm11_0 & 0x01F);
}

uint64_t S_Inst::get_IMM(S_Inst* inst){
  return ((inst->imm11_5<<5)|(imm4_0));
}

uint64_t B_Inst::get_IMM(B_Inst* inst){
  return ((inst->imm12<<12)|(inst->imm11<<11)|(inst->imm10_5<<5)|(inst->imm4_1));
}

uint64_t U_Inst::get_IMM(U_Inst* inst){
  return (inst->imm31_12);
}

uint64_t J_Inst::get_IMM(J_Inst* inst){
  return ((inst->imm20<<19)|(inst->imm10_1<<9)|(imm11<<8)|(imm19_12));
}

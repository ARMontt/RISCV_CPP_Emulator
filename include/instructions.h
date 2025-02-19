#pragma once
#include<cstdint>

class R_Inst{
  public:
    uint32_t r_inst;

    uint64_t opcode = (uint64_t)  (r_inst &0x007F); //Logic AND 16 bits: 0000 0000 0111 1111
    uint64_t rd     = (uint64_t)  (r_inst &0x0F80);
    uint64_t funct3 = (uint64_t)  (r_inst &0x7000);
    uint64_t rs1    = (uint64_t)  (r_inst>>15) &0x1F;
    uint64_t rs2    = (uint64_t)  (r_inst>>20) &0x1F;
    uint64_t funct7 = (uint64_t)  (r_inst>>25) &0x7F;
};

class I_Inst{
  public:
    uint32_t i_inst;

    uint64_t opcode   = (uint64_t)  (i_inst &0x007F); //Logic AND 16 bits: 0000 0000 0111 1111
    uint64_t rd       = (uint64_t)  (i_inst &0x0F80);
    uint64_t funct3   = (uint64_t)  (i_inst &0x7000);
    uint64_t rs1      = (uint64_t)  (i_inst>>15) &0x1F;
    uint64_t imm11_0  = (uint64_t)  (i_inst>>20) &0x0FFF; //inst[31:20] = imm[11:0]
};


class S_Inst{
  public:
    uint32_t s_inst;

    uint64_t opcode   = (uint64_t)  (s_inst &0x007F); //Logic AND 16 bits: 0000 0000 0111 1111
    uint64_t imm4_0   = (uint64_t)  (s_inst &0x0F80);
    uint64_t funct3   = (uint64_t)  (s_inst &0x7000);
    uint64_t rs1      = (uint64_t)  (s_inst>>15) &0x1F;
    uint64_t rs2      = (uint64_t)  (s_inst>>20) &0x1F;
    uint64_t imm11_5  = (uint64_t)  (s_inst>>25) &0x7F;

    uint64_t imm = (uint64_t)(imm11_5<<5)|(imm4_0);
};



class B_Inst{
  public:
    uint32_t b_inst;

    uint64_t opcode       = (uint64_t)  (b_inst &0x007F); //Logic AND 16 bits: 0000 0000 0111 1111
    uint64_t imm4_1_11    = (uint64_t)  (b_inst &0x0F80);
    uint64_t funct3       = (uint64_t)  (b_inst &0x7000);
    uint64_t rs1          = (uint64_t)  (b_inst>>15) &0x1F;
    uint64_t rs2          = (uint64_t)  (b_inst>>20) &0x1F;
    uint64_t imm12_10_5   = (uint64_t)  (b_inst>>25) &0x7F;

    uint64_t imm11        = (imm4_1_11>>7) &0x01;
    uint64_t imm4_1       = (imm4_1_11>>8) &0xFF;
    uint64_t imm10_5      = (imm12_10_5) &0x3F;
    uint64_t imm12        = (imm12_10_5) &0x40;

    uint64_t imm = (uint64_t) (imm12<<12)|(imm11<<11)|(imm10_5<<5)|(imm4_1); //13 bit IMM
};



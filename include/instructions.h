/**
  ******************************************************************************
  * @file           : instructions.h
  * @brief          : Instruction Library - Header File
  * @author         : Alan R. Montt @ ARMontt
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 ARMontt.
  * All rights reserved.
  *
  ******************************************************************************
  */
#pragma once
#include<cstdint>

/*
*
* The following OPCODES were obtained through "github.com/fmash16/riscv_emulator" 
* and the document RISC-V Reference available online from CS295 Simon Fraser University
*
*/

#define LUI 		0x37
#define AUIPC 		0x17

#define JAL 		0x6F
#define JALR 		0x67

#define B_TYPE 		0x63 /*0110 0011*/
	#define BEQ	0x0
	#define BNE	0x1
	#define BLT	0x4
	#define BGE	0x5
	#define BLTU	0x6
	#define BGEU	0x7

#define LOAD 		0x03 /*0000 0011*/
	#define LB	0x0
	#define LH	0x1
	#define LW	0x2
	#define LD	0x3
	#define LBU	0x4
	#define LHU	0x5
	#define LWU	0x6

#define S_TYPE		0x23 /*0010 0011*/
	#define SB	0x0
	#define SH	0x1
	#define SW	0x2
	#define SD	0x3

#define I_TYPE 		0x13 /*0001 0011*/
	#define ADDI	0x0
	#define SLLI	0x1
	#define SLTI	0x2
	#define SLTIU	0x3
	#define XORI	0x4
	#define SRI	0x5
		#define SRLI	0x00	/*FUNCT7 value*/
		#define SRAI	0x20	/*FUNCT7 value*/
	#define ORI	0x6
	#define ANDI	0x7

#define R_TYPE		0x33 /*0011 0011*/
	#define ADD	0x0
	#define SUB	0x0
	#define SLL	0x1
	#define SLT	0x2
	#define SLTU	0x3
	#define XOR	0x4
	#define SR	0x5
		#define SRA 	0x20	/*FUNCT7 value*/
		#define SRL	0x00	/*FUNCT7 value*/
	#define OR	0x6
	#define AND	0x7
 

class R_Inst{
  public:
    uint32_t r_inst;

    uint64_t opcode = (uint64_t)  (r_inst &0x007F); //Logic AND 16 bits: 0000 0000 0111 1111
    uint64_t rd     = (uint64_t)  ((r_inst>>7)  &0x1F);
    uint64_t funct3 = (uint64_t)  ((r_inst>>12) &0x07);
    uint64_t rs1    = (uint64_t)  ((r_inst>>15) &0x1F);
    uint64_t rs2    = (uint64_t)  ((r_inst>>20) &0x1F);
    uint64_t funct7 = (uint64_t)  ((r_inst>>25) &0x7F);
};

class I_Inst{
  public:
    uint32_t i_inst;

    uint64_t opcode   = (uint64_t)  (i_inst &0x007F); //Logic AND 16 bits: 0000 0000 0111 1111
    uint64_t rd       = (uint64_t)  ((i_inst>>7)  &0x1F);
    uint64_t funct3   = (uint64_t)  ((i_inst>>12) &0x07);
    uint64_t rs1      = (uint64_t)  ((i_inst>>15) &0x1F);
    uint64_t imm11_0  = (uint64_t)  ((i_inst>>20) &0x0FFF); //inst[31:20] = imm[11:0]

    uint64_t I_IMM(I_Inst* inst);
    uint64_t I_SHAMT(I_Inst* inst);
};


class S_Inst{
  public:
    uint32_t s_inst;

    uint64_t opcode   = (uint64_t)  (s_inst &0x007F); //Logic AND 16 bits: 0000 0000 0111 1111
    uint64_t imm4_0   = (uint64_t)  ((s_inst>>7) &0x1F);
    uint64_t funct3   = (uint64_t)  ((s_inst>>12) &0x07);
    uint64_t rs1      = (uint64_t)  ((s_inst>>15) &0x1F);
    uint64_t rs2      = (uint64_t)  ((s_inst>>20) &0x1F);
    uint64_t imm11_5  = (uint64_t)  ((s_inst>>25) &0x7F);

    uint64_t get_IMM(S_Inst* inst);
};



class B_Inst{
  public:
    uint32_t b_inst;

    uint64_t opcode       = (uint64_t)  (b_inst &0x007F); //Logic AND 16 bits: 0000 0000 0111 1111
    uint64_t imm4_1_11    = (uint64_t)  ((b_inst>>7)  &0x1F);
    uint64_t funct3       = (uint64_t)  ((b_inst>>12) &0x07);
    uint64_t rs1          = (uint64_t)  ((b_inst>>15) &0x1F);
    uint64_t rs2          = (uint64_t)  ((b_inst>>20) &0x1F);
    uint64_t imm12_10_5   = (uint64_t)  ((b_inst>>25) &0x7F);

    uint64_t imm11        = (imm4_1_11>>7) &0x01;
    uint64_t imm4_1       = (imm4_1_11>>8) &0xFF;
    uint64_t imm10_5      = (imm12_10_5) &0x3F;
    uint64_t imm12        = (imm12_10_5) &0x40;

    uint64_t get_IMM(B_Inst* inst); //13 bit IMM
};



class U_Inst{
  public:
    uint32_t u_inst;

    uint64_t opcode       = (uint64_t)  (u_inst &0x007F); //Logic AND 16 bits: 0000 0000 0111 1111
    uint64_t rd		  = (uint64_t)	((u_inst>>7)  &0x1F);
    uint64_t imm31_12     = (uint64_t)  ((u_inst>>12) &0x000FFFFF);
    
    uint64_t get_IMM(U_Inst* inst); 

};


class J_Inst{
  public:
    uint32_t j_inst;

    uint64_t opcode       = (uint64_t)  (j_inst &0x007F); //Logic AND 16 bits: 0000 0000 0111 1111
    uint64_t rd		  = (uint64_t)	((j_inst>>7)  &0x1F);
    uint64_t imm31_12     = (uint64_t)  ((j_inst>>12) &0x000FFFFF);
    
    uint64_t imm19_12	  = (uint64_t)  ((imm31_12) 	&0xFF);
    uint64_t imm11	  = (uint64_t)  ((imm31_12>>9)  &0x01);
    uint64_t imm10_1	  = (uint64_t)	((imm31_12>>10) &0x3FF);
    uint64_t imm20	  = (uint64_t)  ((imm31_12>>20) &0x01);
	
    uint64_t get_IMM(J_Inst* inst);
};


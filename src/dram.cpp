/**
  ******************************************************************************
  * @file           : dram.cpp
  * @brief          : DRAM Library - Source Code
  * @author         : Alan R. Montt @ OpenDoDo
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 OpenDoDo
  * All rights reserved.
  *
  ******************************************************************************
  */
#include "dram.h"

uint64_t DRAM::dram_load_8(DRAM* dram, uint64_t addr){
	return (uint64_t) dram->mem[addr - DRAM_BASE];
}

uint64_t DRAM::dram_load_16(DRAM* dram, uint64_t addr){
	return (uint64_t) dram->mem[addr-DRAM_BASE]
		| (uint64_t) dram->mem[addr-DRAM_BASE + 1] << 8;
}

uint64_t DRAM::dram_load_32(DRAM* dram, uint64_t addr){
	
	return (uint64_t) dram->mem[addr-DRAM_BASE]
		| (uint64_t) dram->mem[addr-DRAM_BASE + 1] << 8
		| (uint64_t) dram->mem[addr-DRAM_BASE + 2] << 16
		| (uint64_t) dram->mem[addr-DRAM_BASE + 3] << 24;
}


uint64_t DRAM::dram_load_64(DRAM* dram, uint64_t addr){
	
	return (uint64_t) dram->mem[addr-DRAM_BASE]
		| (uint64_t) dram->mem[addr-DRAM_BASE + 1] << 8
		| (uint64_t) dram->mem[addr-DRAM_BASE + 2] << 16
		| (uint64_t) dram->mem[addr-DRAM_BASE + 3] << 24
		| (uint64_t) dram->mem[addr-DRAM_BASE + 4] << 32
		| (uint64_t) dram->mem[addr-DRAM_BASE + 5] << 40
		| (uint64_t) dram->mem[addr-DRAM_BASE + 6] << 48
		| (uint64_t) dram->mem[addr-DRAM_BASE + 7] << 56;		
}


uint64_t DRAM::dram_load(DRAM* dram, uint64_t addr, uint64_t size){
	switch(size){
		case 8: return dram_load_8(dram, addr); break;
		case 16: return dram_load_16(dram, addr); break;
		case 32: return dram_load_32(dram, addr); break;
		case 64: return dram_load_64(dram, addr); break;
		default: return 1;
	}
};

void DRAM::dram_store(DRAM* dram, uint64_t addr, uint64_t size, uint64_t value){
	switch(size){
		case 8: dram_store_8(dram, addr, value);break;
		case 16: dram_store_16(dram, addr, value);break;
		case 32: dram_store_32(dram, addr, value);break;
		case 64: dram_store_64(dram, addr, value);break;
		default:;
	}
};

void DRAM::dram_store_8(DRAM* dram, uint64_t addr, uint64_t value){
	dram->mem[addr-DRAM_BASE] = (uint8_t) (value & 0xff);
}

void DRAM::dram_store_16(DRAM* dram, uint64_t addr, uint64_t value){
	for(int i=0; i<2; i++){
		dram->mem[addr-DRAM_BASE+i] = (uint8_t) ((value >> (8*i)) & 0xff);
	}
};
void DRAM::dram_store_32(DRAM* dram, uint64_t addr, uint64_t value){
	for(int i=0; i<4; i++){
		dram->mem[addr-DRAM_BASE+i] = (uint8_t) ((value >> (8*i)) & 0xff);
	}
};
void DRAM::dram_store_64(DRAM* dram, uint64_t addr, uint64_t value){
	for(int i=0; i<8; i++){
		dram->mem[addr-DRAM_BASE+i] = (uint8_t) ((value >> (8*i)) & 0xff);
	}
};
 

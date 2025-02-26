/**
  ******************************************************************************
  * @file           : dram.h
  * @brief          : DRAM Library - Header File
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

#define DRAM_SIZE 1024*1024*1 //1 MiB = 1 048 576 Bytes
#define DRAM_BASE 0x80000000

class DRAM{
	public:
		uint8_t mem[DRAM_SIZE]; //DRAM memory fo DRAM_SIZE
		

		uint64_t dram_load(DRAM* dram, uint64_t addr, uint64_t size);
		uint64_t dram_load_8(DRAM* dram, uint64_t addr);
		uint64_t dram_load_16(DRAM* dram, uint64_t addr);
		uint64_t dram_load_32(DRAM* dram, uint64_t addr);
		uint64_t dram_load_64(DRAM* dram, uint64_t addr);
		
		void dram_store(DRAM* dram, uint64_t addr, uint64_t size, uint64_t value);
		void dram_store_8(DRAM* dram, uint64_t addr, uint64_t value);
		void dram_store_32(DRAM* dram, uint64_t addr, uint64_t value);
		void dram_store_16(DRAM* dram, uint64_t addr, uint64_t value);
		void dram_store_64(DRAM* dram, uint64_t addr, uint64_t value);
 
};


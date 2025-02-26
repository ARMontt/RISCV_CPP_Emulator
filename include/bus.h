/**
  ******************************************************************************
  * @file           : bus.h
  * @brief          : BUS Library - Header File
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
#include "dram.h"

class BUS{
	public:
		DRAM dram;
		
		uint64_t bus_load(BUS* bus, uint64_t addr, uint64_t size);

		void bus_store(BUS* bus, uint64_t addr, uint64_t size, uint64_t value);
};


/**
  ******************************************************************************
  * @file           : cpu.h
  * @brief          : CPU Library - Header File
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
#include "bus.h"

class CPU{
  public:
    uint64_t regs[32];
    uint64_t pc;
    BUS bus;

    void cpu_init(CPU* cpu);
    uint32_t cpu_fetch(CPU* cpu);
    int cpu_execute(CPU* cpu, uint32_t inst);
    void dump_registers(CPU* cpu);
    uint64_t cpu_load(CPU* cpu, uint64_t addr, uint64_t size);  
    void cpu_store(CPU* cpu, uint64_t addr, uint64_t size, uint64_t value);

    void exec_ADDI(CPU* cpu, uint32_t inst);
    void exec_SLTI(CPU* cpu, uint32_t inst);
    void exec_SRAI(CPU* cpu, uint32_t inst);
};

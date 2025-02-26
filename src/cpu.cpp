
#include "cpu.h"

void CPU::cpu_init(CPU* cpu){
  cpu->regs[0] = 0x00;
  cpu->regs[2] = DRAM_BASE + DRAM_SIZE;
  cpu->pc      = DRAM_BASE;
}

uint32_t CPU::cpu_fetch(CPU* cpu){
  uint32_t inst = bus.bus_load(&(cpu->bus), cpu->pc,32);
  return inst;
}

uint64_t CPU::cpu_load(CPU* cpu, uint64_t addr, uint64_t size){
  return bus.bus_load(&(cpu->bus),addr,size);
}

void CPU::cpu_store(CPU* cpu, uint64_t addr, uint64_t size, uint64_t value){
  bus.bus_store(&(cpu->bus), addr, size, value);
}

int cpu_execute(CPU* cpu, uint32_t inst){
  int opcode = inst & 0x7f;
  int funct3 = (inst >> 12) & 0x7;
  int funct7 = (inst >> 25) & 0x7f;

  cpu->regs[0] = 0;
}

#include "bus.h"

uint64_t BUS::bus_load(BUS* bus, uint64_t addr, uint64_t size){
	return dram.dram_load(&(bus->dram), addr, size);
}

void BUS::bus_store(BUS* bus, uint64_t addr, uint64_t size, uint64_t value){
	dram.dram_store(&(bus->dram), addr, size, value);
}


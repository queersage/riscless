#pragma once


struct RISCLESSOptions {
  size_t ram_size;       // ram size in byes
  uint32_t entry_point;  // the initial value of the pc
  bool enable_logging;   // logging or no logging
};

struct RISCLESSContext {
  uint32_t* regs;     // 32 general purpose registers
  uint8_t* ram;       // ram bank in bytes
  uint32_t pc;        // program counter
  bool is_running;    // is it running tho
  RISCLESSOptions options;  // options for the vm
  uint32_t ram_size; // ram size in bytes
};

bool init_riscless_vm;
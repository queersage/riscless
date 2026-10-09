#include "debug.h"
#include "vm_data.h"
#include <cstdint>


bool step_riscless_vm(RISCLESSContext* ctx) {
  if (!ctx || !ctx->is_running){
    DEBUG_LOG("ERROR", "Failed to step VM, is it running annd does it exist?");
    return false;
  };

  if(ctx->pc+3>ctx->ram_size){
    ctx->is_running = false;
    DEBUG_LOG("ERROR", "VM PC exceeded the VM's memory allocation.");
    return false;
  }

  uint32_t instr = *(uint32_t*)&ctx->ram[ctx->pc];

  uint8_t opcode = instr & 0x7F;
  uint8_t rd = (instr >> 7) & 0x1F;
  uint8_t funct3 = (instr >> 12) & 0x07;
  uint8_t rs1 = (instr >> 15) & 0x1F;
  uint8_t rs2 = (instr >> 20) & 0x1F;

  return true;
}
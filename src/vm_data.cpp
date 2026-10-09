#include <algorithm>
#include <cstring> // Required for std::memcpy
#include <cstdint>
#include "vm_data.h"
#include "debug.h"

bool init_riscless_vm(RISCLESSContext* ctx, RISCLESSOptions* options){
  if(!ctx||!options||options->ram_size==0){
    DEBUG_LOG("ERROR", "Invalid options to VM");
    return false;
  }

  ctx->regs = (uint32_t*)calloc(32, sizeof(uint32_t));
  ctx->ram = (uint8_t*)calloc(options->ram_size, sizeof(uint8_t));
  ctx->ram_size = options->ram_size;

  if (!ctx->regs || !ctx->ram) {
    free(ctx->regs);
    free(ctx->ram);
    return false;
  }

  ctx->options = *options;
  ctx->pc = options->entry_point;
  ctx->is_running = false;

  return true;
}

bool load_riscv_binary(RISCLESSContext* ctx,const uint8_t* binary_data, size_t binary_size){
  if(!ctx||!ctx->ram){
    DEBUG_LOG("ERROR", "Failed to load binary due to invalid VM context.");
    return false;
  }

  
  if(binary_size>=sizeof(ctx->ram)){
    DEBUG_LOG("ERROR","Failed to load binary due to insufficient VM context memory.");
    return false;
  }
  std::memcpy(0, ctx->ram, binary_size);

  return true;
}

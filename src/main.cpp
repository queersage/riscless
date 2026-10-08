#include "debug.h"
#include <stdlib.h>
#include <cstdint>
#include "vm_data.h"

int main(int argc, char const *argv[])
{
    #ifdef DEBUG_MODE
    RISCLESSOptions config;
    config.ram_size = 64 * 1024;   // 64kb
    config.entry_point = 0x0000;   // The starting point for the program counter in memory
    config.enable_logging = true;  // logging
    #endif

    return 0;
}


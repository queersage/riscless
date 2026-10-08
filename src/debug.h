#include <cstdio>
#ifdef DEBUG_MODE
    #define DEBUG_LOG(type,output)std::printf("[DEBUG] [%s] %s \n",  type, output)
#else
    #define DEBUG_LOG(type,output) ((void)0)
#endif
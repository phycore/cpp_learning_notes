#ifndef _PLAT_PACKED_H
#define _PLAT_PACKED_H

// clang-format off
#if defined(_WIN32)
    #define PACK(__Declaration__) __pragma(pack(push, 1)) __Declaration__ __pragma(pack(pop))
#elif defined(__linux__)
    #ifdef __GNUC__
        #define PACK(__Declaration__) __Declaration__ __attribute__((__packed__))
    #else
        #error GNU compiler required!
    #endif
#else
    #error No operating system specified!
#endif
// clang-format on

#endif
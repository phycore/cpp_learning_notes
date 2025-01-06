#ifndef _PLAT_STRING_H
#define _PLAT_STRING_H

#include <string.h>

#if defined(_WIN32)
#include <windows.h>
#define PATH_LEN MAX_PATH
#elif defined(__linux__)
#include <limits.h>
#define PATH_LEN PATH_MAX
#endif

#endif  // _PLAT_STRING_H
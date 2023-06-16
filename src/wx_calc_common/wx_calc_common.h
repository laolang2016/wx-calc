#pragma once


#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
//define something for Windows (32-bit and 64-bit, this part is common)
#ifdef _WIN64
#define DllExport __declspec(dllexport)
#else
#define DllExport __declspec(dllexport)
#endif
#elif __APPLE__
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR
// iOS Simulator
#elif TARGET_OS_IPHONE
// iOS device
#elif TARGET_OS_MAC
// Other kinds of Mac OS
#else
#   error "Unknown Apple platform"
#endif
#elif __linux__
// linux
#define DllExport
#elif __unix__ // all unices not caught above
// Unix
#elif defined(_POSIX_VERSION)
// POSIX
#else
#   error "Unknown compiler"
#endif

#define KHL_CALC_START namespace khl { namespace calc {
#define KHL_CALC_END }; };

KHL_CALC_START

enum
{
    ID_MIN = 6000,
    ID_Hello
};

KHL_CALC_END


#include "runtime_internal.h"

#ifdef BITS_64
#define WIN32API
#else
#define WIN32API __stdcall
#endif

extern "C" {

WIN32API void *LoadLibrary(const char *);
WIN32API void *GetProcAddress(void *, const char *);
WIN32API int FreeLibrary(void *);

WEAK void *halide_get_symbol(const char *name) {
    return GetProcAddress(NULL, name);
}

WEAK void *halide_load_library(const char *name) {
    return LoadLibrary(name);
}

WEAK void *halide_get_library_symbol(void *lib, const char *name) {
    return GetProcAddress(lib, name);
}

WEAK void halide_free_library(void *lib) {
    FreeLibrary(lib);
}

}

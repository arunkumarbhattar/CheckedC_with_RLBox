#ifndef __WASM_C_DEFINITIONS_LIB_WASM_H_GENERATED_
#define __WASM_C_DEFINITIONS_LIB_WASM_H_GENERATED_

#define WASM_CURR_MODULE_PREFIX 
/* Automically generated by wasm2c */
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "wasm-rt.h"

#ifndef WASM_RT_MODULE_PREFIX
#define WASM_RT_MODULE_PREFIX
#endif

#define WASM_RT_PASTE_(x, y) x ## y
#define WASM_RT_PASTE(x, y) WASM_RT_PASTE_(x, y)
#define WASM_RT_ADD_PREFIX(x) WASM_RT_PASTE(WASM_RT_MODULE_PREFIX, x)

#define WASM_CURR_ADD_PREFIX(x) WASM_RT_PASTE(WASM_CURR_MODULE_PREFIX, x)

/* TODO(binji): only use stdint.h types in header */
typedef uint8_t u8;
typedef int8_t s8;
typedef uint16_t u16;
typedef int16_t s16;
typedef uint32_t u32;
typedef int32_t s32;
typedef uint64_t u64;
typedef int64_t s64;
typedef float f32;
typedef double f64;

#ifndef WASM_DONT_EXPORT_FUNCS
# if defined(_WIN32)
#   define FUNC_EXPORT __declspec(dllexport)
# else
#   define FUNC_EXPORT
# endif
#else
# define FUNC_EXPORT
#endif

FUNC_EXPORT wasm2c_sandbox_funcs_t WASM_CURR_ADD_PREFIX(get_wasm2c_sandbox_info)();

struct wasm2c_sandbox_t;
typedef struct wasm2c_sandbox_t wasm2c_sandbox_t;

/* import: 'wasi_snapshot_preview1' 'fd_seek' */
extern u32 Z_wasi_snapshot_preview1Z_fd_seekZ_iijii(void*, u32, u64, u32, u32);
/* import: 'wasi_snapshot_preview1' 'fd_write' */
extern u32 Z_wasi_snapshot_preview1Z_fd_writeZ_iiiii(void*, u32, u32, u32, u32);
/* import: 'wasi_snapshot_preview1' 'fd_close' */
extern u32 Z_wasi_snapshot_preview1Z_fd_closeZ_ii(void*, u32);
/* import: 'wasi_snapshot_preview1' 'fd_fdstat_get' */
extern u32 Z_wasi_snapshot_preview1Z_fd_fdstat_getZ_iii(void*, u32, u32);

FUNC_EXPORT u32 w2c_parse_image_header(wasm2c_sandbox_t* const, u32);
FUNC_EXPORT void w2c_parse_image_body(wasm2c_sandbox_t* const, u32, u32, u32, u32);
FUNC_EXPORT void w2c_image_parsing_progress(wasm2c_sandbox_t* const, u32);
FUNC_EXPORT u32 w2c_validate_image_headers(wasm2c_sandbox_t* const, u32);
FUNC_EXPORT u32 w2c_malloc(wasm2c_sandbox_t* const, u32);
FUNC_EXPORT u32 w2c_dlmalloc(wasm2c_sandbox_t* const, u32);
FUNC_EXPORT void w2c_free(wasm2c_sandbox_t* const, u32);
FUNC_EXPORT void w2c_dlfree(wasm2c_sandbox_t* const, u32);
FUNC_EXPORT u32 w2c_calloc(wasm2c_sandbox_t* const, u32, u32);
FUNC_EXPORT u32 w2c_realloc(wasm2c_sandbox_t* const, u32, u32);
FUNC_EXPORT void w2c_dispose_chunk(wasm2c_sandbox_t* const, u32, u32);
FUNC_EXPORT u32 w2c_posix_memalign(wasm2c_sandbox_t* const, u32, u32, u32);
FUNC_EXPORT u32 w2c_internal_memalign(wasm2c_sandbox_t* const, u32, u32);
FUNC_EXPORT u32 w2c_aligned_alloc(wasm2c_sandbox_t* const, u32, u32);
FUNC_EXPORT u32 w2c_malloc_usable_size(wasm2c_sandbox_t* const, u32);
FUNC_EXPORT void w2c_abort(wasm2c_sandbox_t* const);
FUNC_EXPORT u32 w2c_sbrk(wasm2c_sandbox_t* const, u32);
FUNC_EXPORT u32 w2c_printf(wasm2c_sandbox_t* const, u32, u32);
FUNC_EXPORT u32 w2c_fwrite(wasm2c_sandbox_t* const, u32, u32, u32, u32);
FUNC_EXPORT u32 w2c_strerror(wasm2c_sandbox_t* const, u32);
FUNC_EXPORT u32 w2c_writev(wasm2c_sandbox_t* const, u32, u32, u32);
FUNC_EXPORT u32 w2c_fputs(wasm2c_sandbox_t* const, u32, u32);
FUNC_EXPORT u32 w2c_vfprintf(wasm2c_sandbox_t* const, u32, u32, u32);
FUNC_EXPORT u32 w2c_printf_core(wasm2c_sandbox_t* const, u32, u32, u32, u32, u32);
FUNC_EXPORT void w2c_pop_arg(wasm2c_sandbox_t* const, u32, u32, u32);
FUNC_EXPORT void w2c_long_double_not_supported(wasm2c_sandbox_t* const);
FUNC_EXPORT u32 w2c_close(wasm2c_sandbox_t* const, u32);
FUNC_EXPORT u32 w2c_strnlen(wasm2c_sandbox_t* const, u32, u32);
FUNC_EXPORT u32 w2c_memcpy(wasm2c_sandbox_t* const, u32, u32, u32);
FUNC_EXPORT u32 w2c_memset(wasm2c_sandbox_t* const, u32, u32, u32);
FUNC_EXPORT u32 w2c_strlen(wasm2c_sandbox_t* const, u32);
FUNC_EXPORT u32 w2c_memchr(wasm2c_sandbox_t* const, u32, u32, u32);
FUNC_EXPORT u32 w2c_dummy(wasm2c_sandbox_t* const, u32, u32);
FUNC_EXPORT u32 w2c_wctomb(wasm2c_sandbox_t* const, u32, u32);
FUNC_EXPORT u32 w2c_wcrtomb(wasm2c_sandbox_t* const, u32, u32, u32);
FUNC_EXPORT f64 w2c_frexp(wasm2c_sandbox_t* const, f64, u32);

#ifdef __cplusplus
}
#endif

#endif  /* __WASM_C_DEFINITIONS_LIB_WASM_H_GENERATED_ */

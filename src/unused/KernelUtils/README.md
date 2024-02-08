# RadianceOS 2.0 folder structure - KernelUtils

- [RadianceOS 2.0 folder structure - KernelUtils](#radianceos-20-folder-structure---kernelutils)
  - [kernelutils.cpp](#kernelutilscpp)
    - [`void* memcpy(void* dest, const void* src, size_t n)`](#void-memcpyvoid-dest-const-void-src-size_t-n)
    - [`void* memset(void* s, int c, size_t n)`](#void-memsetvoid-s-int-c-size_t-n)
    - [`int memcmp(const void* s1, const void* s2, size_t n)`](#int-memcmpconst-void-s1-const-void-s2-size_t-n)
    - [`static void hcf(void)`](#static-void-hcfvoid)
    - [`void printf(char* printchars)`](#void-printfchar-printchars)
  - [kernelutils.h](#kernelutilsh)

## kernelutils.cpp
The Kernel Utilities file.

### `void* memcpy(void* dest, const void* src, size_t n)`
This is used for copying memory from one place to another.
- `void* dest` - The destination
- `void* src`  - The source
- `size_t n`   - The size of the memory being copied

### `void* memset(void* s, int c, size_t n)`
This is used for setting a part of memory.
- `void* s`  - The memory being set
- `int c`    - ?
- `size_t n` - The size of the memory being set

### `int memcmp(const void* s1, const void* s2, size_t n)`
I atually don't know what this does, can be documented later

### `static void hcf(void)`
This is used to halt the CPU, this should only be used when things go wrong.

### `void printf(char* printchars)`
Pretty easy to guess what it does, prints characters to the screen
(Not implemented yet)
- `char* printchars` - The characters to print to the screen

## kernelutils.h
The header file for kernelutils.cpp

Includes:
- `<stdint.h>`
- `<stddef.h>`
- `<stdbool.h>`

Definitions:
- `void* memcpy(void* dest, const void* src, size_t n)`   - [Usage](#void-memcpyvoid-dest-const-void-src-size_t-n)
- `void* memset(void* s, int c, size_t n)`                - [Usage](#void-memsetvoid-s-int-c-size_t-n)
- `void* memmove(void* dest, const void* src, size_t n)`  - [Usage](#int-memcmpconst-void-s1-const-void-size_t-n)
- `int memcmpy(const void* s1, const void* s2, size_t n)` - [Usage](#int-memcmpconst-void-s1-const-void-s2-size_t-n)
- `static void hcf(void)`                                 - [Usage](#static-void-hcfvoid)
- `void printf(char* printchars)`                         - [Usage](#void-printfchar-printchars)
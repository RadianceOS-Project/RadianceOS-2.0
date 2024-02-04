#pragma once
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
void* memcpy(void* dest, const void* src, size_t n);
void* memset(void* s, int c, size_t n);
void* memmove(void* dest, const void* src, size_t n);
int memcmp(const void* s1, const void* s2, size_t n);
static void hcf(void);
void printf(char* printchars);
typedef struct {
	uint8_t status;
	uint32_t size;
} alloc_t;

void mm_init(uint32_t kernel_end);
void mm_print_out();

char* pmalloc(size_t size); /* page aligned alloc */
char* malloc(size_t size);
void free(void* mem);
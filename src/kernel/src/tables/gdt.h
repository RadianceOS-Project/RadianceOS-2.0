#pragma once

#include <inttypes.h>

typedef struct {
    uint16_t segment_limit;         // Segment limit first 0-15 bits
    uint16_t base_low;              // Base first 0-15 bits
    uint8_t base_middle;            // Base 16-23 bits
    uint8_t access;                 // Access byte
    uint8_t granularity;            // High 4 bits (flags) low 4 bits (limit 4 last bits)(limit is 20 bit wide)
    uint8_t base_high;              // Base 24-31 bits
} __attribute__((packed)) GDT;

typedef struct {
    uint16_t limit;                 // Limit size of all GDT segments
    uint32_t base_address;          // Base address of the first GDT segment
} __attribute__((packed)) GDT_PTR;
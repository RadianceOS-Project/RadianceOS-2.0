#include <limine.h>
#include <stdbool.h>
#include <stddef.h>

#include <hardware/hardwareutils.h>

#define LIMINE_SMP_X2APIC (1 << 0)

struct limine_smp_request smp_request = {
    .id = LIMINE_SMP_REQUEST,
    .revision = 0,
    //.response = NULL,
    .flags = LIMINE_SMP_X2APIC
};

void* InitialiseSMP(void) {
    if(smp_request.response == NULL) {
        //return smp_request;
    } else {
        struct limine_smp_response *smp_response = smp_request.response;

        return smp_response;
    }
}

bool IsSMPInit(void) {
    if(smp_request.response == NULL) return false;

    return true;
}

inline void PortWriteByte(const uint16_t port, const uint8_t val)
{
    __asm__ volatile("outb %b0, %w1" : : "a"(val), "Nd"(port) : "memory");
}

inline uint8_t PortReadByte(const uint16_t port)
{
    uint8_t retval;
    __asm__ volatile("inb %w1, %b0" : "=a"(retval) : "Nd"(port) : "memory");
    return retval;
}

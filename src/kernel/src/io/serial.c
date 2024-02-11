/*
 * serial.c
 *
 * Routines for writing to and reading from serial ports.
 */

#include "serial.h"

#define REGOFF_DATA         (0)
#define REGOFF_INT_ENB      (1)
#define REGOFF_INT_ID       (2)
#define REGOFF_LINE_CTRL    (3)
#define REGOFF_MODEM_CTRL   (4)
#define REGOFF_LN_STATUS    (5)
#define REGOFF_MODEM_STATUS (6)
#define REGOFF_SCRATCH      (7)

#define REGOFF_DLAB_BAUDDIV_LSB (0)
#define REGOFF_DLAB_BAUDDIV_MSB (1)

static bool IsReadyToWrite(const uint16_t port)
{
    return PortReadByte(port + REGOFF_LN_STATUS) & 0x20;
}

static bool IsReadyToRead(const uint16_t port)
{
    return PortReadByte(port + REGOFF_LN_STATUS) & 1;
}

Status SerialInit(const uint16_t port, const uint16_t baudDivisor)
{
    PortWriteByte(port + REGOFF_INT_ENB, 0x00); // Disable all interrupts

    SerialSetBaudRate(port, baudDivisor);

    PortWriteByte(port + REGOFF_INT_ID, 0xC7); // Enable FIFO, clear them, with 14-byte threshold
    PortWriteByte(port + REGOFF_MODEM_CTRL, 0x0B); // IRQs enabled, RTS/DSR set

    /*
     * Test serial chip (send byte 0xAE and check if serial returns same byte)
     */
    PortWriteByte(port + REGOFF_MODEM_CTRL, 0x1E); // Set in loopback mode
    PortWriteByte(port + REGOFF_DATA, 0xAE);
    if (PortReadByte(port + REGOFF_DATA) != 0xAE)
    {
        return FAIL;
    }
    // If serial is not faulty, return to normal operation mode
    // (not-loopback with IRQs enabled and OUT#1 and OUT#2 bits enabled)
    PortWriteByte(port + REGOFF_MODEM_CTRL, 0x0F);

    return OKAY;
}

void SerialSetBaudRate(const uint16_t port, const uint16_t baudDivisor)
{
    const uint8_t msb = (baudDivisor >> 8) & 0xFF;
    const uint8_t lsb = baudDivisor & 0xFF;

    PortWriteByte(port + REGOFF_LINE_CTRL, 0x80); // Enable DLAB (set baud rate divisor)

    PortWriteByte(port + REGOFF_DLAB_BAUDDIV_MSB, msb);
    PortWriteByte(port + REGOFF_DLAB_BAUDDIV_LSB, lsb);

    PortWriteByte(port + REGOFF_LINE_CTRL, 0x03); // 8 bits, no parity, one stop bit
}

void SerialWriteByte(const uint16_t port, const uint8_t val)
{
    while (!IsReadyToWrite(port));

    PortWriteByte(port + REGOFF_DATA, val);
}

void SerialWriteString(const uint16_t port, const char *str)
{
    const char *c = str;
    while (*c)
    {
        SerialWriteByte(port, (uint8_t)*c);
        c++;
    }
}

uint8_t SerialReadByte(const uint16_t port)
{
    while (!IsReadyToRead(port));

    return PortReadByte(port + REGOFF_DATA);
}

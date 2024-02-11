/*
 * serial.h
 * 
 * Routine headers and definitions for writing to and reading from serial ports.
 */

#pragma once

#include <stdint.h>

#include <hardware/hardwareutils.h>

/// Represents a binary success-or-failure status.
typedef uint8_t Status;
/// The operation was successful.
#define OKAY ((Status)(0))
/// The operation was unsuccessful.
#define FAIL ((Status)(1))

/// The port number of the COM1 serial port.
#define COM1 (0x3F8)
/// The port number of the COM2 serial port.
#define COM2 (0x2F8)
/// The port number of the COM3 serial port.
#define COM3 (0x3E8)
/// The port number of the COM4 serial port.
#define COM4 (0x2E8)
/// The port number of the COM5 serial port.
#define COM5 (0x5F8)
/// The port number of the COM6 serial port.
#define COM6 (0x4F8)
/// The port number of the COM7 serial port.
#define COM7 (0x5E8)
/// The port number of the COM8 serial port.
#define COM8 (0x4E8)

/// Baud rate divisor for 115,200 bits per second.
#define BAUDDIV_115200 (1)
/// Baud rate divisor for 57,600 bits per second.
#define BAUDDIV_57600 (2)
/// Baud rate divisor for 38,400 bits per second.
#define BAUDDIV_38400 (3)
/// Baud rate divisor for 19,200 bits per second.
#define BAUDDIV_19200 (6)
/// Baud rate divisor for 9,600 bits per second.
#define BAUDDIV_9600 (12)
/// Baud rate divisor for 4,800 bits per second.
#define BAUDDIV_4800 (24)

/// @brief Initialise a serial port. This must be called before writing to or reading from the port. Only call this routine once per port.
/// @param port The serial port to initialise.
/// @param baudDivisor The initial baud rate divisor of the serial port.
/// @return OKAY if the serial port was successfully initialised, otherwise FAIL.
/// @attention The callee must check and handle the return value.
Status SerialInit(const uint16_t port, const uint16_t baudDivisor);

/// @brief Set the baud rate of a serial port.
/// @param port The serial port to set the baud rate of.
/// @param baudDivisor The baud rate divisor.
void SerialSetBaudRate(const uint16_t port, const uint16_t baudDivisor);

/// @brief Write a single byte to a serial port.
/// @param port The serial port to write to.
/// @param val The byte to write.
/// @attention The serial port must first be initialised with SerialInit.
void SerialWriteByte(const uint16_t port, const uint8_t val);

/// @brief Write a string to a serial port.
/// @param port The serial port to write to.
/// @param str The string to write.
/// @attention The serial port must first be initialised with SerialInit.
void SerialWriteString(const uint16_t port, const char *str);

/// @brief Read a single byte from a serial port.
/// @param port The serial port to read from.
/// @return The read byte.
/// @attention The serial port must first be initialised with SerialInit.
uint8_t SerialReadByte(const uint16_t port);

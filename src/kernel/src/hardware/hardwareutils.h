#include <stdbool.h>
#include <stdint.h>

void* InitialiseSMP(void);
bool IsSMPInit(void);

bool COM1Init(void);
bool COM2Init(void);
bool COM3Init(void);
bool COM4Init(void);
bool COM5Init(void);
bool COM6Init(void);
bool COM7Init(void);
bool COM8Init(void);

/// @brief Writes a single byte to an I/O port.
/// @param port The port.
/// @param val The byte to write.
void PortWriteByte(const uint16_t port, const uint8_t val);

/// @brief Writes a single byte to an I/O port.
/// @param port The port.
/// @param val The byte to write.
/// @return The read byte.
uint8_t PortReadByte(const uint16_t port);

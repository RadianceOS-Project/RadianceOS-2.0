#include <stdbool.h>
#include <stdint.h>

void* InitialiseSMP(void);
bool IsSMPInit(void);

/// @brief Writes a single byte to an I/O port.
/// @param port The port.
/// @param val The byte to write.
void PortWriteByte(const uint16_t port, const uint8_t val);

/// @brief Writes a single byte to an I/O port.
/// @param port The port.
/// @param val The byte to write.
/// @return The read byte.
uint8_t PortReadByte(const uint16_t port);

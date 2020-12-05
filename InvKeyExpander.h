#ifndef H_InvKEYEXPANDER

#define H_InvKEYEXPANDER

#include <stdint.h>
typedef uint8_t byte;

extern byte Inv_S_BOX[256];
extern byte S_BOX[256];

void InvComputeKey(byte *key, int round);

byte R_CON[] = {
	0x01 , 0x02 , 0x04 , 0x08 , 0x10 , 0x20 , 0x40 , 0x80 , 0x1b , 0x36,
};

#endif
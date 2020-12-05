#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "InvMixColumn.h"

void InvMixColumn(byte *state){
  uint8_t i, a, b, c, d, e;

  /* Process a column at a time */
  for(i = 0; i < 16; i+=4){
    a = state[i];
    b = state[i+1];
    c = state[i+2];
    d = state[i+3];
    e = a ^ b ^ c ^ d; // a + b + c + d in GF(2^8)
    e ^= xtime(e) ^ xtime(xtime(e)) ^ xtime(xtime(xtime(e))); // b1111 * (a + b + c + d) in GF(2^8)
    // b1110 * a + b1011 * b + b1101 * c + b1001 * d in GF(2^8)
    // = e + a + b100 * b + b10 * c + b110 * d
    state[i  ] ^= e ^ xtime(xtime(b)) ^ xtime(c) ^ xtime(xtime(d)) ^ xtime(d);
    // b1001 * a + b1110 * b + b1011 * c + b1101 * d in GF(2^8)
    // = e + b110 * a + b + b100 * c + b10 * d
    state[i+1] ^= e ^ xtime(xtime(a)) ^ xtime(a) ^ xtime(xtime(c)) ^ xtime(d);
    // b1101 * a + b1001 * b + b1110 * c + b1011 * d in GF(2^8)
    // = e + b10 * a + b110 * b + c + b100 * d
    state[i+2] ^= e ^ xtime(a) ^ xtime(xtime(b)) ^ xtime(b) ^ xtime(xtime(d));
    // b1011 * a + b1101 * b + b1001 * c + b1110 * d in GF(2^8)
    // = e + b100 * a + b10 * b + b110 * c + d
    state[i+3] ^= e ^ xtime(xtime(a)) ^ xtime(b) ^ xtime(xtime(c)) ^ xtime(c);
  }

}


byte xtime(byte x){
	return (x & 0x80) ? ((x << 1) ^ 0x1b) : (x<<1);
}
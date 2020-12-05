#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "InvShiftRow.h"

void InvShiftRow(byte *state){
  uint8_t temp;

  //Row 2
  temp = state[13];
  state[13] = state[9];
  state[ 9] = state[5];
  state[ 5] = state[1];
  state[ 1] = temp;
  //Row 3
  temp = state[14];
  state[14] = state[6];
  state[6] = temp;
  temp = state[10];
  state[10] = state[2];
  state[2] = temp;
  //Row 4
  temp = state[3];
  state[ 3] = state[ 7];
  state[ 7] = state[11];
  state[11] = state[15];
  state[15] = temp;
}

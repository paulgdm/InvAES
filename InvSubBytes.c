#include "InvSubBytes.h"

void InvSubBytes(byte *state){
  state[0] = Inv_S_BOX[ state[0] ];
  state[1] = Inv_S_BOX[ state[1] ];
  state[2] = Inv_S_BOX[ state[2] ];
  state[3] = Inv_S_BOX[ state[3] ];
  state[4] = Inv_S_BOX[ state[4] ];
  state[5] = Inv_S_BOX[ state[5] ];
  state[6] = Inv_S_BOX[ state[6] ];
  state[7] = Inv_S_BOX[ state[7] ];
  state[8] = Inv_S_BOX[ state[8] ];
  state[9] = Inv_S_BOX[ state[9] ];
  state[10] = Inv_S_BOX[ state[10] ];
  state[11] = Inv_S_BOX[ state[11] ];
  state[12] = Inv_S_BOX[ state[12] ];
  state[13] = Inv_S_BOX[ state[13] ];
  state[14] = Inv_S_BOX[ state[14] ];
  state[15] = Inv_S_BOX[ state[15] ];
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdint.h>

typedef uint8_t byte;

extern void InvAddRoundKey(byte *state,byte *key);
extern void InvSubBytes(byte *state);
extern void InvShiftRow(byte *state);
extern void InvMixColumn(byte *state);
extern void InvComputeKey(byte *key,int round);



byte cipher_key[16] = {0xd0,0x14,0xf9,0xa8,0xc9,0xee,0x25,0x89,0xe1,0x3f,0x0c,0xc8,0xb6,0x63,0x0c,0xa6};

void afficher(byte *tab);

int main(int argc,char* argv[]){

	byte state[16];
	for (int i=0;i<16;i++){
		state[i]=strtol(argv[i+1],NULL,16);
	}

	InvAddRoundKey(state,cipher_key);
	for (int i=9;i>=1;i--){
		InvShiftRow(state);
		InvSubBytes(state);
		InvComputeKey(cipher_key,i);
		InvAddRoundKey(state,cipher_key);
		InvMixColumn(state);	
	}
	InvShiftRow(state);
	InvSubBytes(state);
	InvComputeKey(cipher_key,0);
	InvAddRoundKey(state,cipher_key);
	afficher(state);
	return 0;
}

void afficher(byte *tab){
	for (int i=0;i<16;i++){
		printf("%.2x ",tab[i]);
	}
	printf("\n");
}
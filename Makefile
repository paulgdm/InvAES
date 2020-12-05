CC=gcc

LDFLAGS=
EXEC=InvAES

SRC = ${wildcard *.c}
OBJ=${SRC:.c=.o}

all: $(EXEC)

InvAES: ${OBJ}
	$(CC) -o $@ $^ $(LDFLAGS)

AES.o: KeyExpander.h InvSubBytes.h InvAddRoundKey.h InvShiftRow.h InvMixColumn.h

%.o: %.c
	$(CC) -o $@ -c $< 

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
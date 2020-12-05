make clean
make all

rm result.txt
rm cleartext.txt

#hexdump -e '16/1 "%02x " "\n"' cleartext.txt >> result.txt

cat ./../ciphertext.txt | while  read ligne ; do
	echo $ligne
  	./InvAES $ligne | xxd -r -p >> result.txt
done

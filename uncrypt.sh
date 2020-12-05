make clean
make all

rm result.txt
rm cleartext.txt

cat $1.txt | while  read ligne ; do
	echo $ligne
  	./InvAES $ligne | xxd -r -p >> $2.txt
done

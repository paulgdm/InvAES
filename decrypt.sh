rm cleartext.txt

cat $1 | while  read ligne ; do
  	./InvAES $ligne | xxd -r -p >> $2
done

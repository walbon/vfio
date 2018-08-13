
compile : 
	gcc -g -o bug170313.exe bug170313.c 

run : compile
	@read -p "Enter the address: " addr;\
	sudo ./bug170313.exe $$addr

clean : 
	rm bug170313.exe

gdb : compile
	gdb bug170313.exe

all : compile run

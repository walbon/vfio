
compile : 
	gcc -g -o vfio_probing.exe vfio_probing.c 

run : compile
	@read -p "Enter the address: " addr;\
	sudo ./vfio_probing.exe $$addr

clean : 
	rm vfio_probing.exe

gdb : compile
	gdb vfio_probing.exe

all : compile run


compile : 
	gcc -g -o bug170313.exe bug170313.c 

run : 
	sudo ./bug170313.exe 

all : compile run

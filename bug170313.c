#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>

#define DEVICE "/dev/mem"

int main(int argc, char *argv[])
{
    if (!argv[1]) {
        fprintf(stderr, "missing address\n");
        return 1;
    }

    unsigned long io_base = strtol(argv[1],NULL,16); // lspci -v Memory address
    void *io_mem;
    int iofd;
    int pagesize;

    // map the memory
    iofd = open(DEVICE, O_RDWR);
    if (iofd == -1) {
        fprintf(stderr, "can't open /dev/mem for rw\n");
        return 1;
    }

    io_mem = mmap(NULL,
                  pagesize=getpagesize(), // possivelmente brincar aqui
                  PROT_READ | PROT_WRITE,
                  MAP_SHARED,
                  iofd,
                  io_base);

    // bkpt no io_mem, ver o que ele retorna, ver se consegue retornar aquele erro

    if (io_mem){
	fprintf(stdout, "\n--------------------");
    	fprintf(stdout, "\nIO_MEM=%p", io_mem);
	fprintf(stdout, "\nPageSize=%d bytes", pagesize);
	fprintf(stdout, "\n--------------------\n");
    }
    else printf("IO_MEM ¯\\_(ツ)_/¯\n");

    close(iofd);
    return 0;
}

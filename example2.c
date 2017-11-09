#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define SZ_BUF 1024

int main (int argc, char *argv[])
{
	int fd_in;
	int fd_out;
	if(argc != 3)
	{
		fprintf(stderr,"usage: mycp sourcefile targetfile\n");
		exit(0);
	}

	fd_in = open(argv[1],O_RDONLY);
	fd_out = open(argv[2],O_WRONLY);
	if((fd_in == -1)||(fd_out == -1))
	{
		perror("HYORIM");
		exit(0);
	}
	else
	{
		int nb;
		char buf[SZ_BUF];
		while( nb = read(fd_in,buf,SZ_BUF) )
		{
			write(fd_out,buf,nb);
		}
		printf("%s\n",argv[2]);
	}
	close(fd_in);
	close(fd_out);
	return 0;
}

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
int main()
{
	int fd[2];
	pipe(fd);
	printf("%d\n", fd[0]);
	close(fd[0]);
	char *tmp;
	tmp = (char *)malloc(10);
	free(tmp);
	close(fd[0]);
	printf("%d\n", fd[0]);

}
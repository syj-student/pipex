#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int	main(void)
{
	int fd;
	char buffer[6];
	int ipcfd[2];
	pid_t pid;

	fd = open("./test.txt", O_RDONLY);
	pipe(ipcfd);

	pid = fork();
	if (!pid)
	{
		printf("child ppid : %d\n", getppid());
		close(ipcfd[0]);
		write(ipcfd[1], "Hello\n", 6);
		printf("child exit\n");
		sleep(2);
		printf("child pid : %d\n", getppid());
	}
	else
	{
		printf("parent pid : %d\n", pid);
		close(ipcfd[1]);
		read(ipcfd[0], buffer, 6);
		write(1, buffer, 6);
		printf("parent exit\n");
	}
	return 2;
}
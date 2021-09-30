#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	global;

int	main(void)
{
	int		automatic;
	int		*heap;
	pid_t	pid;

	global = 10;
	automatic = 10;
	heap = (int *)malloc(sizeof(int));
	if (!heap)
		return (1);
	*heap = 10;
	pid = fork();
	if (pid == -1)
	{
		free(heap);
		return (1);
	}
	else if (!pid)
	{
		printf("Child: Before operations -> %d (Global), %d (Automatic), %d (Heap)\n", global, automatic, *heap);
		global += 10;
		automatic += 10;
		*heap += 10;
		printf("Child: After operations -> %d (Global), %d (Automatic), %d (Heap)\n", global, automatic, *heap);
	}
	else if (pid)
	{
		printf("Parent: Before operations -> %d (Global), %d (Automatic), %d (Heap)\n", global, automatic, *heap);
		global += 20;
		automatic += 20;
		*heap += 20;
		printf("Parent: After operations -> %d (Global), %d (Automatic), %d (Heap)\n", global, automatic, *heap);
	}
	free(heap);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:42:03 by yusong            #+#    #+#             */
/*   Updated: 2021/08/19 11:42:03 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfile.h"

int	main(int argc, char **argv, char ** env)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
	{
		write(1, "ARGUMENT_FAILURE\n", 18);
		return (0);
	}
	if (pipe(fd) == -1)
		errorExit("PIPE_FAILURE");
	pid = fork();
	if (pid == -1)
		errorExit("FORK_FAILURE");
	if (pid == 0)
		childProcess(argv, env, fd);
	if (waitpid(pid, NULL, 0) == -1)
		errorExit("WAIT_FAILURE");
	parentProcess(argv, env, fd);
	close(fd[0]);
	close(fd[1]);
	return (EXIT_FAILURE);
}
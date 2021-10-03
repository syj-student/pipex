/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 10:23:25 by yusong            #+#    #+#             */
/*   Updated: 2021/10/01 10:23:25 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfile.h"

void	errorExit(char *errorMsg)
{
	ft_put(errorMsg);
	exit(EXIT_FAILURE);
}

void	childProcess(char **argv, char **env, int *fd)
{
	int inputFilefd;

	inputFilefd = open(argv[1], O_RDONLY);
	if (inputFilefd == -1)
		errorExit("INFILE_FAILURE");
	dup2(inputFilefd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(inputFilefd);
	close(fd[1]);
	close(fd[0]);
	execCommand(env, argv[2]);
	errorExit("EXECVE(CHILD)_FAILURE");
}

void	parentProcess(char **argv, char **env, int *fd)
{
	int outputFilefd;

	wait(NULL);
	outputFilefd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outputFilefd == -1)
		errorExit("OUTFILE_FAILURE");
	dup2(fd[0], STDIN_FILENO);
	dup2(outputFilefd, STDOUT_FILENO);
	close(outputFilefd);
	close(fd[0]);
	close(fd[1]);
	execCommand(env, argv[3]);
	errorExit("EXECVE(PARENT)_FAILURE");
}

void	execCommand(char **env, char *argv)
{
	/*
	1. 환경변수에서 path 부분 split
	2. findPath에 환경변수 path + 명령어[0] 부분 검색
	3. 찾은 path로 execve() 실행
	*/
	int		i;
	char	**paths;
	char	**cmd;

	i = -1;
	while (!ft_strnstr(env[++i], "PATH", 4))
		continue ;
	paths = ft_split(env[i] + 5, ':');
	cmd = ft_split(argv, ' ');
	if (execve(findPath(paths, cmd), cmd, env) == -1)
		errorExit("EXECVE_FAILURE");
}

char	*findPath(char **paths, char **cmd)
{
	int		i;
	char	*tmp;
	char	*path;

	i = -1;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, cmd[0]);
		free(tmp);
		if (!access(path, X_OK))
			return (path);
	}
	errorExit("PATHFIND_FAILURE");
	return (0);
}

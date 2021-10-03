/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headerfile.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 10:23:47 by yusong            #+#    #+#             */
/*   Updated: 2021/08/19 10:23:47 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERFILE_H
# define HEADERFILE_H

#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>

//		processor_utils_1.c		/	full
void	errorExit(char *errorMsg);
void	childProcess(char **argv, char **env, int *fd);
void	parentProcess(char **argv, char **env, int *fd);
void	execCommand(char **env, char *argv);
char	*findPath(char **paths, char **cmd);

//		lib_1.c					/	full
void	ft_put(char *msg);
char	**ft_split(char const *s, char c);

//		lib_2.c					/	1
size_t	ft_strlen(const char *str);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);


#endif
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
#include <stdio.h>
#include <stdlib.h>

void	errorExit(void);
void	childProcess(char **argv, char **envp, int *fd);
void	parentProcess(char **argv, char **envp, int *fd);

#endif
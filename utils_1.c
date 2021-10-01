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

void	errorExit(void)
{
	perror("Error ");
	exit(EXIT_FAILURE);
}

void	childProcess(char **argv, char **envp, int *fd)
{

}

void	parentProcess(char **argv, char **envp, int *fd)
{

}

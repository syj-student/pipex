/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 09:56:59 by yusong            #+#    #+#             */
/*   Updated: 2021/10/02 09:56:59 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headerfile.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	temp;

	i = 0;
	if (s2[i] == 0)
		return ((char *)s1);
	while (s1[i] && i < len)
	{
		temp = 0;
		if (s2[temp] == s1[i + temp])
		{
			while (s2[temp] && s1[i + temp])
			{
				if (s2[temp] != s1[i + temp] || (i + temp) >= len)
					break ;
				temp++;
			}
			if (s2[temp] == 0)
				return (&((char *)s1)[i]);
		}
		i++;
	}
	return ((void *)0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*ret;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ret = (char *)malloc(len_s1 + len_s2 + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len_s2)
		ret[i++] = s2[j++];
	ret[i] = 0;
	return (ret);
}

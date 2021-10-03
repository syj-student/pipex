/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 06:47:19 by yusong            #+#    #+#             */
/*   Updated: 2021/10/02 06:47:19 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headerfile.h"

static size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (dest == 0 || src == 0)
		return (0);
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (i < len && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (len);
}

static char	**free_array(char **temp, int cnt)
{
	int	i;

	i = 0;
	while (i < cnt + 1)
		free(temp[i++]);
	free(temp);
	return (0);
}

static size_t	g_cnt(char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	if (s == 0)
		return (0);
	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			cnt++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (cnt);
}

static char	**splitEarlyError(char *s, char c)
{
	char **ret;

	if (!s)
		return (0);
	ret = (char **)malloc(sizeof(char *) * (g_cnt(s, c) + 1));
	if (!ret)
		return (0);
	return (ret);
}


char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	*start;
	size_t	i;
	size_t	len;

	ret = splitEarlyError(s, c);
	if (!ret)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = (char *)s;
			while (*s && *s != c)
				s++;
			len = s - start + 1;
			ret[i] = (char *)malloc(sizeof(char) * len);
			if (!(ret[i]))
				return (free_array(ret, i));
			ft_strlcpy(ret[i++], start, len);
		}
		else
			s++;
	}
	ret[i] = 0;
	return (ret);
}

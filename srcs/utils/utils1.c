/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:49:36 by ybelatar          #+#    #+#             */
/*   Updated: 2023/12/14 16:02:15 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	if (!s1 || !s2)
		return (-1);
	if (!s1 && !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*res;

	if (!s)
		return (NULL);
	res = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

int	plen(char **map)
{
	int	i;

	if (!map || !(*map))
		return (0);
	i = 0;
	while (map[i])
		i++;
	return (i);
}

char	**join_tab(char **map, char *str)
{
	char	**res;
	int		i;

	res = malloc(sizeof(char *) * (plen(map) + 2));
	if (!res)
		return (NULL);
	if (!map || !(*map))
	{
		res[0] = str;
		res[1] = NULL;
		return (res);
	}
	i = 0;
	while (map[i])
	{
		res[i] = map[i];
		i++;
	}
	res[i++] = str;
	res[i] = NULL;
	free(map);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:40:49 by ybelatar          #+#    #+#             */
/*   Updated: 2023/12/13 21:35:47 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	full_close(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

void	check_closed(t_game *game)
{
	int	len;
	int	i;

	len = ft_strlen(game->map[0]);
	i = 0;
	while (game->map[i])
	{
		if (i == 0 || i == game->counter.lines - 1)
		{
			if (full_close(game->map[i]))
				exit_error(ERR_CLOSED, 1, 0, game);
		}
		else if (game->map[i][0] != '1' || game->map[i][len - 1] != '1')
			exit_error(ERR_CLOSED, 1, 0, game);
		i++;
	}
}

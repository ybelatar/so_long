/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_winnable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:41:01 by ybelatar          #+#    #+#             */
/*   Updated: 2023/12/19 16:25:11 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char ***map, int x, int y, t_game *game)
{
	if (x >= game->counter.lines || x < 0 || y >= game->counter.columns
		|| y < 0)
		return ;
	if ((*map)[x][y] == '1')
		return ;
	(*map)[x][y] = '1';
	flood_fill(map, x + 1, y, game);
	flood_fill(map, x, y + 1, game);
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x, y - 1, game);
}


void mid_check(char **copy, t_game *game)
{
	int i;
	int j;

	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (copy[i][j] != '0' && copy[i][j] != '1')
			{
				free_map(copy);
				close(game->fd);
				exit_error(ERR_WINNABLE, 1, 0, game);
			}
			j++;
		}
		i++;
	}
}

void	check_winnable(t_game *game)
{
	char	**copy;
	int		h;

	h = game->counter.lines;
	game->counter.columns = ft_strlen(game->map[0]);
	copy = ft_copy(game->map, game);
	flood_fill(&copy, game->position.x, game->position.y, game);
	mid_check(copy, game);
	free_map(copy);
}

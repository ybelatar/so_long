/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:40:56 by ybelatar          #+#    #+#             */
/*   Updated: 2023/12/19 16:24:50 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_counter(t_game *game)
{
	game->counter.player = 0;
	game->counter.exit = 0;
	game->counter.collectible = 0;
}

void	add_player(t_game *game, int i, int j)
{
	game->position.x = i;
	game->position.y = j;
	game->counter.player++;
}

void trnover(char *str, t_game *game)
{
	close(game->fd);
	exit_error(str, 1, 0, game);
}

void	check_count(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	init_counter(game);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				add_player(game, i, j);
			else if (game->map[i][j] == 'E')
				game->counter.exit++;
			else if (game->map[i][j] == 'C')
				game->counter.collectible++;
			else if (game->map[i][j] != '0' && game->map[i][j] != '1')
				trnover(ERR_UKNWN, game);
			j++;
		}
		i++;
	}
	if (game->counter.player != 1 || game->counter.exit != 1
		|| game->counter.collectible < 1)
		trnover(ERR_COUNT, game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:05:05 by ybelatar          #+#    #+#             */
/*   Updated: 2023/12/13 21:38:00 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_sprites(t_game *game)
{
	if (!game->sprite.player || !game->sprite.collectible || !game->sprite.exit
		|| !game->sprite.floor || !game->sprite.wall)
		return (1);
	return (0);
}

void	exit_size(t_game *game)
{
	ft_putstr(ERR_SCREEN);
	if (game->mlx)
	{
		mlx_destroy_display((*game).mlx);
		free((*game).mlx);
	}
	free_map(game->map);
	free(game);
	exit(1);
}

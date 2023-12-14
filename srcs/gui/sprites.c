/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 08:59:12 by ybelatar          #+#    #+#             */
/*   Updated: 2023/12/13 21:46:11 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	import_sprites(t_game *game)
{
	int	i;
	int	j;

	game->sprite.player = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm",
			&i, &j);
	game->sprite.exit = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm", &i,
			&j);
	game->sprite.collectible = mlx_xpm_file_to_image(game->mlx,
			"assets/collectible.xpm", &i, &j);
	game->sprite.floor = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm",
			&i, &j);
	game->sprite.wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &i,
			&j);
}

void	put_player(t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->window, game->sprite.player, j
		* 40, i * 40);
	game->position.x = i;
	game->position.y = j;
}

void	put_one(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'P')
		put_player(game, i, j);
	if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite.collectible, j * 40, i * 40);
	if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite.exit, j * 40, i * 40);
	if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite.floor, j * 40, i * 40);
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite.wall, j * 40, i * 40);
}

void	put_images(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			put_one(game, i, j);
			j++;
		}
		i++;
	}
}

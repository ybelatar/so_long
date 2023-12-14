/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:44:33 by ybelatar          #+#    #+#             */
/*   Updated: 2023/12/13 21:38:15 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_img(t_game *game)
{
	mlx_destroy_image(game->mlx, game->sprite.player);
	mlx_destroy_image(game->mlx, game->sprite.exit);
	mlx_destroy_image(game->mlx, game->sprite.collectible);
	mlx_destroy_image(game->mlx, game->sprite.floor);
	mlx_destroy_image(game->mlx, game->sprite.wall);
}

void	exit_error(char *str, int fmap, int fmlx, t_game *game)
{
	ft_putstr(str);
	if (fmap)
		free_map(game->map);
	if (fmlx)
	{
		free_img(game);
		if (game->window)
			mlx_destroy_window(game->mlx, game->window);
		if (game->mlx)
			mlx_destroy_display((*game).mlx);
		free((*game).mlx);
	}
	free(game);
	exit(1);
}

void	exit_win(t_game *game)
{
	free_img(game);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
	{
		mlx_destroy_display((*game).mlx);
		free((*game).mlx);
	}
	free_map(game->map);
	free(game);
	exit(1);
}

int	exit_click(t_game *game)
{
	free_img(game);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
	{
		mlx_destroy_display((*game).mlx);
		free((*game).mlx);
	}
	free_map(game->map);
	free(game);
	exit(1);
	return (0);
}

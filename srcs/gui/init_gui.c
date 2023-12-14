/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 04:01:11 by ybelatar          #+#    #+#             */
/*   Updated: 2023/12/13 21:36:07 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_screen_size(t_game *game)
{
	int	i;
	int	j;

	mlx_get_screen_size(game->mlx, &i, &j);
	if (j < game->counter.lines * 40 || i < game->counter.columns * 40)
		exit_size(game);
}

void	init_gui(t_game *game)
{
	game->mlx = mlx_init();
	if (!(game->mlx))
		exit_error(ERR_MLX, 1, 0, game);
	check_screen_size(game);
	game->window = mlx_new_window(game->mlx, game->counter.columns * 40,
			game->counter.lines * 40, "so_long");
	import_sprites(game);
	put_images(game);
	mlx_key_hook(game->window, controls, game);
	mlx_hook(game->window, 17, 0, exit_click, game);
	mlx_loop(game->mlx);
}

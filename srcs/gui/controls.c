/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 05:09:42 by ybelatar          #+#    #+#             */
/*   Updated: 2023/12/13 21:36:19 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	try_move(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'E')
	{
		if (game->counter.collectible != 0)
			return (0);
		ft_putstr("\n-----\n\nYou won !!!\n\n-----\n");
		exit_win(game);
	}
	if (game->map[i][j] == 'C')
	{
		game->map[i][j] = 'P';
		game->position.x = i;
		game->position.y = j;
		game->counter.collectible--;
		game->steps++;
	}
	if (game->map[i][j] == '0')
	{
		game->map[i][j] = 'P';
		game->position.x = i;
		game->position.y = j;
		game->steps++;
	}
	ft_printf("Steps : %d \n", game->steps);
	return (1);
}

static int	key_w_or_s(t_game *game, int key)
{
	int	i;
	int	j;
	int	k;

	i = game->position.x;
	j = game->position.y;
	if (key == 119)
	{
		if (game->map[--i][j] == '1')
			return (0);
		k = try_move(game, i, j);
		if (!k)
			return (0);
		game->map[i + 1][j] = '0';
	}
	else
	{
		if (game->map[++i][j] == '1')
			return (0);
		k = try_move(game, i, j);
		if (!k)
			return (0);
		game->map[i - 1][j] = '0';
	}
	return (1);
}

static int	key_a_or_d(t_game *game, int key)
{
	int	i;
	int	j;
	int	k;

	i = game->position.x;
	j = game->position.y;
	if (key == 97)
	{
		if (game->map[i][--j] == '1')
			return (0);
		k = try_move(game, i, j);
		if (!k)
			return (0);
		game->map[i][j + 1] = '0';
	}
	else
	{
		if (game->map[i][++j] == '1')
			return (0);
		k = try_move(game, i, j);
		if (!k)
			return (0);
		game->map[i][j - 1] = '0';
	}
	return (1);
}

int	controls(int key, t_game *game)
{
	int	possible;

	possible = 0;
	if (key == 65307)
		exit_error(EXIT, 1, 1, game);
	if (key == 115)
		possible = key_w_or_s(game, key);
	if (key == 119)
		possible = key_w_or_s(game, key);
	if (key == 97)
		possible = key_a_or_d(game, key);
	if (key == 100)
		possible = key_a_or_d(game, key);
	if (possible)
		put_images(game);
	return (1);
}

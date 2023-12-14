/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:57:08 by ybelatar          #+#    #+#             */
/*   Updated: 2023/12/14 15:52:38 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_var(t_game *game)
{
	game->position.x = 0;
	game->position.y = 0;
	game->steps = 0;
	game->counter.columns = ft_strlen(game->map[0]);
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
	{
		ft_putstr("Error\nMalloc failed\n");
		return (0);
	}
	if (ac != 2)
	{
		free(game);
		ft_putstr("Error\nTry ./so_long MAP_NAME.ber\n");
		return (0);
	}
	init_map(av[1], game);
	init_var(game);
	init_gui(game);
}

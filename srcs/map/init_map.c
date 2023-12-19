/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:41:04 by ybelatar          #+#    #+#             */
/*   Updated: 2023/12/19 16:18:10 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkings(t_game *game)
{
	check_rectangle(game);
	check_closed(game);
	check_count(game);
	check_winnable(game);
}

char	**get_map(int fd, t_game *game)
{
	char	**map;
	char	*str;

	map = NULL;
	game->counter.lines = 0;
	while (fd)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		game->counter.lines++;
		map = join_tab(map, str);
	}
	return (map);
}

void	init_map(char *path, t_game *game)
{
	int	fd;

	if (!check_extension(path))
		exit_error(ERR_EXTENSION, 0, 0, game);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_error(ERR_OPEN, 0, 0, game);
	game->fd = fd;
	game->map = get_map(fd, game);
	if (!(game->map))
	{
		close(fd);
		exit_error(ERR_READ, 0, 0, game);
	}
	checkings(game);
	close(fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:40:58 by ybelatar          #+#    #+#             */
/*   Updated: 2023/12/19 16:19:04 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rectangle(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != len)
		{
			close(game->fd);
			exit_error(ERR_RECTANGLE, 1, 0, game);
		}
		i++;
	}
}

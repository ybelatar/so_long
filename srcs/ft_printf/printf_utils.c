/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:53:09 by ybelatar          #+#    #+#             */
/*   Updated: 2023/12/13 21:32:53 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putcharbis(char c, int *length)
{
	write(1, &c, 1);
	*length = *length + 1;
}

void	ft_putstrbis(char *str, int *length)
{
	int	i;

	if (!str)
	{
		write(1, "(null)", 6);
		*length = *length + 6;
		return ;
	}
	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		*length = *length + 1;
		i++;
	}
}

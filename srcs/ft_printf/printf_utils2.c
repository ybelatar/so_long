/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:16:57 by ybelatar          #+#    #+#             */
/*   Updated: 2023/12/13 21:32:59 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbrbasebis(uintptr_t n, int maj, uintptr_t base, int *length)
{
	char	*b;

	b = "0123456789abcdef0123456789ABCDEF";
	if (n > base - 1)
		ft_putnbrbasebis(n / base, maj, base, length);
	ft_putcharbis(b[maj * base + n % base], length);
}

void	ft_putptrhexabis(uintptr_t ptr, int *length)
{
	if (!ptr)
	{
		write(1, "(nil)", 5);
		*length = *length + 5;
		return ;
	}
	write(1, "0x", 2);
	*length = *length + 2;
	ft_putnbrbasebis(ptr, 0, 16, length);
}

void	ft_putnbrdecabis(int n, int *length)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*length = *length + 11;
		return ;
	}
	if (n < 0)
	{
		ft_putcharbis('-', length);
		n *= -1;
	}
	ft_putnbrbasebis(n, 0, 10, length);
}

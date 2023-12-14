/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:56:35 by ybelatar          #+#    #+#             */
/*   Updated: 2023/11/11 03:03:10 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_match(char c, va_list *parameters, int *length)
{
	if (c == 'i' || c == 'd')
		return (ft_putnbrdecabis(va_arg(*parameters, int), length));
	if (c == 'u')
		return (ft_putnbrbasebis(va_arg(*parameters, unsigned int), 0, 10,
				length));
	if (c == 'c')
		return (ft_putcharbis(va_arg(*parameters, int), length));
	if (c == 's')
		return (ft_putstrbis(va_arg(*parameters, char *), length));
	if (c == 'p')
		return (ft_putptrhexabis((uintptr_t)va_arg(*parameters, void *),
				length));
	if (c == 'x')
		return (ft_putnbrbasebis(va_arg(*parameters, unsigned int), 0, 16,
				length));
	if (c == 'X')
		return (ft_putnbrbasebis(va_arg(*parameters, unsigned int), 1, 16,
				length));
	if (c == '%')
		return (ft_putcharbis('%', length));
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		length;
	va_list	parameters;

	va_start(parameters, str);
	i = 0;
	length = 0;
	while (str[i])
	{
		while (str[i] && str[i] != '%')
		{
			write(1, str + i, 1);
			length++;
			i++;
		}
		if (str[i] == '%' && str[i + 1])
			ft_match(str[++i], &parameters, &length);
		if (str[i])
			i++;
	}
	va_end(parameters);
	return (length);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:45:33 by ybelatar          #+#    #+#             */
/*   Updated: 2023/12/13 21:32:41 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

void	ft_match(char c, va_list *parameters, int *length);
int		ft_printf(const char *str, ...);
void	ft_putcharbis(char c, int *length);
void	ft_putstrbis(char *str, int *length);
void	ft_putptrhexabis(uintptr_t ptr, int *length);
void	ft_putnbrbasebis(uintptr_t n, int maj, uintptr_t base, int *length);
void	ft_putnbrdecabis(int n, int *length);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcan <rcan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:12:48 by rcan              #+#    #+#             */
/*   Updated: 2023/11/26 21:31:34 by rcan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_decider(va_list *ap, char c, int *len)
{
	if (c == 'c')
		ft_putchar(va_arg(*ap, int), len);
	else if (c == 's')
		ft_putstr(va_arg(*ap, char *), len);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(*ap, int), len);
	else if (c == 'u')
		ft_putnbr(va_arg(*ap, unsigned int), len);
	else if (c == 'x')
		ft_phex(va_arg(*ap, unsigned int), "0123456789abcdef", len);
	else if (c == 'X')
		ft_phex(va_arg(*ap, unsigned int), "0123456789ABCDEF", len);
	else if (c == 'p')
	{
		ft_putstr("0x", len);
		ft_phex(va_arg(*ap, unsigned long long), "0123456789abcdef", len);
	}
	else if (c == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	va_list	ap;

	i = 0;
	len = 0;
	va_start(ap, s);
	while (s[i] && s)
	{
		if (s[i] == '%' && s[i + 1])
			ft_decider(&ap, s[++i], &len);
		else if (s[i] != '%')
			ft_putchar(s[i], &len);
		i++;
	}
	va_end (ap);
	return (len);
}

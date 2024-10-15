/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sidekicks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcan <rcan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:30:19 by rcan              #+#    #+#             */
/*   Updated: 2023/11/26 21:27:22 by rcan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	write (1, &c, 1);
	*len += 1;
}

void	ft_putstr(char *str, int *len)
{
	int	i;

	i = 0;
	if (!str)
	{
		str = "(null)";
	}
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	*len += i;
}

void	ft_putnbr(long nb, int *len)
{
	if (nb < 0)
	{
		ft_putchar('-', len);
		ft_putnbr(-nb, len);
	}
	else if (nb <= 9)
	{
		ft_putchar(nb + 48, len);
	}
	else
	{
		ft_putnbr(nb / 10, len);
		ft_putchar(nb % 10 + 48, len);
	}
}

void	ft_phex(unsigned long long i, char *base, int *len)
{
	if (i >= 16)
	{
		ft_phex(i / 16, base, len);
		ft_phex(i % 16, base, len);
	}
	else
		ft_putchar(base[i], len);
}

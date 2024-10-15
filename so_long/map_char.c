/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcan <rcan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:32:57 by rcan              #+#    #+#             */
/*   Updated: 2024/05/09 18:32:57 by rcan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	char_control(t_map *so, int x, int y)
{
	so->player_count = 0;
	so->exit_count = 0;
	so->coin_count = 0;
	y = 0;
	while (so->map_line[y])
	{
		x = 0;
		while (so->map_line[y][x])
		{
			if (so->map_line[y][x] == 'E')
				so->exit_count++;
			if (so->map_line[y][x] == 'C')
				so->coin_count++;
			if (so->map_line[y][x] == 'P')
			{
				so->p_y = y;
				so->p_x = x;
				so->player_count++;
			}
			x++;
		}
		y++;
	}
}

int	char_count(t_map *so)
{
	char_control(so, 0, 0);
	if (so->exit_count != 1)
	{
		ft_printf("Error : Exit count is not 1!");
		return (1);
	}
	if (so->player_count != 1)
	{
		ft_printf("Error : Player count is not 1!");
		return (1);
	}
	if (so->coin_count == 0)
	{
		ft_printf("Error : Coin count is 0!");
		return (1);
	}
	return (0);
}

int	char_checker(t_map *so)
{
	int	y;
	int	x;

	y = 0;
	while (so->map_line[y])
	{
		x = 0;
		while (so->map_line[y][x] != '\n' && so->map_line[y][x] != '\0')
		{
			if (ft_strchr("01CEP", so->map_line[y][x]))
				x++;
			else
			{
				ft_printf("Error : There is invalid character in map!");
				return (1);
			}
		}
		y++;
	}
	return (0);
}

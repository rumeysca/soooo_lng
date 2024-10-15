/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcan <rcan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:33:04 by rcan              #+#    #+#             */
/*   Updated: 2024/05/09 18:33:04 by rcan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_reachable(t_map *so)
{
	player_movable(so, so->p_y, so->p_x);
	if (coin_check(so) || exit_check(so))
		return (1);
	return (0);
}

void	player_movable(t_map *so, int y, int x)
{
	if (so->map_line[y][x + 1] == '0' || so->map_line[y][x + 1] == 'C')
	{
		so->map_line[y][x + 1] = 'P';
		player_movable(so, y, x + 1);
	}
	if (so->map_line[y][x - 1] == '0' || so->map_line[y][x - 1] == 'C')
	{
		so->map_line[y][x - 1] = 'P';
		player_movable(so, y, x - 1);
	}
	if (so->map_line[y + 1][x] == '0' || so->map_line[y + 1][x] == 'C')
	{
		so->map_line[y + 1][x] = 'P';
		player_movable(so, y + 1, x);
	}
	if (so->map_line[y - 1][x] == '0' || so->map_line[y - 1][x] == 'C')
	{
		so->map_line[y - 1][x] = 'P';
		player_movable(so, y - 1, x);
	}
}

int	coin_check(t_map *so)
{
	int	y;
	int	x;

	y = 0;
	while (so->map_line[y])
	{
		x = 0;
		while (so->map_line[y][x] != 0 && so->map_line[y][x] != '\n')
		{
			if (so->map_line[y][x] == 'C')
			{
				ft_printf("Error : Player can't reach the collectible");
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	exit_check(t_map *so)
{
	int	y;
	int	x;

	y = 0;
	while (so->map_line[y] != 0)
	{
		x = 0;
		while (so->map_line[y][x] != '\n')
		{
			if (so->map_line[y][x] == 'E')
				break ;
			x++;
		}
		if (so->map_line[y][x] == 'E')
			break ;
		y++;
	}
	if (so->map_line[y][x + 1] == 'P' || so->map_line[y][x - 1] == 'P' || \
			so->map_line[y + 1][x] == 'P' || so->map_line[y - 1][x] == 'P')
		return (0);
	ft_printf("Error : Player can't reach the exit\n");
	return (1);
}

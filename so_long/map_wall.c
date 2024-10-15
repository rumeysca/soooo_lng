/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcan <rcan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:33:26 by rcan              #+#    #+#             */
/*   Updated: 2024/05/09 18:33:26 by rcan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wall_check(t_map *so)
{
	int	y;
	int	firstend;
	int	middle;

	y = 0;
	firstend = wall_first_end(so, y);
	if (firstend != 0)
	{
		ft_printf("Error : Wall Error!");
		return (1);
	}
	y = 1;
	middle = wall_middle(so, y);
	if (middle != 0)
	{
		ft_printf("Error : Wall Error!");
		return (1);
	}
	return (0);
}

int	wall_first_end(t_map *so, int y)
{
	int	x;
	int	len;

	len = so->map_y_line;
	if (y == 0 || y == (len - 1))
	{
		x = 0;
		while (so->map_line[y][x] != '\n')
		{
			if (so->map_line[0][x] != '1')
				return (1);
			if (so->map_line[len - 1][x] != '1')
				return (1);
			x++;
		}
	}
	return (0);
}

int	wall_middle(t_map *so, int y)
{
	int	len;

	len = ft_strlen(so->map_line[0]) - 2;
	while (so->map_line[y] != 0)
	{
		if (so->map_line[y][0] != '1'
				|| so->map_line[y][len] != '1')
			return (y + 1);
		y++;
	}
	return (0);
}

int	check_shape(t_map *so)
{
	int	y;
	int	x;
	int	len;

	len = ft_strlen(so->map_line[0]);
	so->map_x_line = len;
	y = 0;
	while (y < so->map_y_line)
	{
		x = 0;
		while (so->map_line[y] && so->map_line[y][x] != '\n' && \
			x < (int)(ft_strlen(so->map_line[y])))
			x++;
		if (x != len -1)
		{
			ft_printf("Error : The map is not a rectangle!\n");
			return (1);
		}
		y++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcan <rcan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:33:09 by rcan              #+#    #+#             */
/*   Updated: 2024/05/09 18:33:09 by rcan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_xpm(t_map *so)
{
	int	x;
	int	y;

	so->exit_img = mlx_xpm_file_to_image(so->mlx, \
					"./textures/doner.xpm", &x, &y);
	so->coinimg = mlx_xpm_file_to_image(so->mlx, \
					"./textures/bread.xpm", &x, &y);
	so->wall_img = mlx_xpm_file_to_image(so->mlx, \
					"./textures/wall.xpm", &x, &y);
	so->player_img = mlx_xpm_file_to_image(so->mlx, \
					"./textures/player.xpm", &x, &y);
	so->background_img = mlx_xpm_file_to_image(so->mlx, \
					"./textures/back.xpm", &x, &y);
	if (!so->background_img || !so->coinimg || !so->exit_img || \
		!so->player_img || !so->wall_img)
		return (1);
	return (0);
}

int	put_image(t_map *so)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (so->map_line[y][x])
	{
		if (so->map_line[y] && so->map_line[y][x] == '\n')
		{
			y++;
			x = 0;
		}
		if (so->map_line[y][x] == 'E')
			put_image_extra(so, so->exit_img, x, y);
		if (so->map_line[y][x] == 'C')
			put_image_extra(so, so->coinimg, x, y);
		if (so->map_line[y][x] == 'P')
			put_image_extra(so, so->player_img, so->p_x, so->p_y);
		if (so->map_line[y][x] == '0')
			put_image_extra(so, so->background_img, x, y);
		if (so->map_line[y][x] == '1')
			put_image_extra(so, so->wall_img, x, y);
		x++;
	}
	return (0);
}

void	put_image_extra(t_map *so, void *img, int x, int y)
{
	mlx_put_image_to_window(so->mlx, so->mlx_win, img, 64 * x, 64 * y);
}

int	ft_move(int key, t_map *so)
{
	int		x;
	int		y;
	char	*move;

	x = so->p_x;
	y = so->p_y;
	if (key == 13)
		y--;
	else if (key == 1)
		y++;
	else if (key == 2)
		x++;
	else if (key == 0)
		x--;
	else if (key == 53)
		safe_exit(so);
	else
		return (0);
	mlx_clear_window(so->mlx, so->mlx_win);
	map_move(so, x, y);
	put_image(so);
	move = ft_itoa(so->playermove);
	mlx_string_put(so->mlx, so->mlx_win, 15, 15, 16777215, move);
	free(move);
	return (0);
}

void	map_move(t_map *so, int x, int y)
{
	if (so->map_line[y][x] != '1' && so->map_line[y][x] != 'E')
	{
		ft_printf("Move Count: %d\n", ++so->playermove);
		if (so->map_line[y][x] == 'C')
			so->coin_count--;
		so->map_line[so->p_y][so->p_x] = '0';
		so->map_line[y][x] = 'P';
		so->p_y = y;
		so->p_x = x;
	}
	else if (so->map_line[y][x] == 'E' && so->coin_count == 0)
	{
		ft_printf("Move Count: %d\n", ++so->playermove);
		safe_exit(so);
	}
}

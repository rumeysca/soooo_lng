/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcan <rcan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:33:18 by rcan              #+#    #+#             */
/*   Updated: 2024/05/09 18:33:18 by rcan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	arg_checker(int argc, char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (argc != 2)
	{
		ft_printf("Error : Invalid number of arguments!\n");
		return (1);
	}
	if (argv[len - 1] != 'r' && argv[len - 2] != 'e' && \
			argv[len - 3] != 'b' && argv[len - 4] != '.')
	{
		ft_printf("Error : File extension must be .ber!\n");
		return (1);
	}
	return (0);
}

int	map_read_check(t_map *so, char *f_name)
{
	read_chars(so, f_name);
	if (!(so->map_line))
	{
		ft_printf("Error : Cannot read the map!\n");
		return (1);
	}
	return (0);
}

int	map_checker(t_map *so)
{
	if (check_shape(so) || char_count(so) || wall_check(so) || \
			char_checker(so) || is_reachable(so))
	{
		free_map(so);
		return (1);
	}
	free_map(so);
	return (0);
}

int	map_init(t_map *so, char *argv)
{
	int	x;

	map_read_check(so, argv);
	so->playermove = 0;
	so->mlx = mlx_init();
	x = ft_strlen(so->map_line[0]) - 1;
	so->mlx_win = mlx_new_window(so->mlx, \
		64 * x, 64 * so->map_y_line, "SO_LONG");
	if (!so->mlx || !so->mlx_win || create_xpm(so))
	{
		ft_printf("Error : mlx or mlx_win is NULL!\n");
		return (1);
	}
	put_image(so);
	mlx_string_put(so->mlx, so->mlx_win, 15, 15, 16777215, "0");
	mlx_hook(so->mlx_win, 2, 1L << 2, ft_move, so);
	mlx_hook(so->mlx_win, 17, 1L << 2, safe_exit, so);
	mlx_loop(so->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	so;

	if (arg_checker(argc, argv[1]) || map_read_check(&so, argv[1]))
		return (1);
	if (map_checker(&so))
		return (1);
	if ((&so)->map_y_line > 20 || (&so)->map_x_line > 40)
	{
		ft_printf("Error : extends out!\n");
		return (1);
	}
	if (map_init(&so, argv[1]))
		return (1);
	return (0);
}

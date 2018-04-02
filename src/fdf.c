/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:52:07 by htkachuk          #+#    #+#             */
/*   Updated: 2018/03/19 15:36:59 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	exit_x(void)
{
	exit(1);
}

int	main(int argc, char **argv)
{
	t_all ev;

	if (argc != 2)
	{
		ft_putstr_fd("Usage : ./fdf <filename> [ case_size z_size ]\n", 2);
		return (-1);
	}
	count_map(argv[1], &ev);
	ev.zoom = SIZE_X / fmax(ev.len, (ev.count / ev.len));
	ev.right = 0;
	ev.down = 0;
	ev.angle = 0;
	if (!(ev.coords = (t_coord*)malloc(sizeof(t_coord) * ev.count)))
		return (0);
	ev.mlx = mlx_init();
	ev.win = mlx_new_window(ev.mlx, SIZE_X, SIZE_Y, "fdf");
	ft_create_img(&ev);
	ft_print(ev);
	mlx_hook(ev.win, 2, 5, ft_key, &ev);
	mlx_hook(ev.win, 17, 1L << 17, exit_x, &ev);
	mlx_loop(ev.mlx);
	return (0);
}

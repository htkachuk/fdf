/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_picture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 18:11:36 by htkachuk          #+#    #+#             */
/*   Updated: 2018/03/05 18:11:38 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_pxl(t_all ev, int x, int y)
{
	int	i;

	if (x < 0 || x >= SIZE_X || y < 0 || y >= SIZE_Y)
		return ;
	i = x * 4 + y * ev.size;
	if (i < SIZE_X * SIZE_Y * 4)
	{
		ev.str[i] = ev.coords[ev.cur_0].blue;
		ev.str[i + 1] = ev.coords[ev.cur_0].green;
		ev.str[i + 2] = ev.coords[ev.cur_0].red;
	}
}

static void	pr_x_max(t_all ev)
{
	int	d;
	int	d1;
	int	d2;
	int	i;

	d = (ev.dy << 1) - ev.dx;
	d1 = ev.dy << 1;
	d2 = (ev.dy - ev.dx) << 1;
	draw_pxl(ev, ev.coords[ev.cur_0].x, ev.coords[ev.cur_0].y);
	ev.x = ev.coords[ev.cur_0].x + ev.sx;
	ev.y = ev.coords[ev.cur_0].y;
	i = 1;
	while (i <= ev.dx)
	{
		if (d > 0)
		{
			d += d2;
			ev.y += ev.sy;
		}
		else
			d += d1;
		draw_pxl(ev, ev.x, ev.y);
		ev.x += ev.sx;
		i++;
	}
}

static void	pr_y_max(t_all ev)
{
	int	d;
	int	d1;
	int	d2;
	int	i;

	d = (ev.dx << 1) - ev.dy;
	d1 = ev.dx << 1;
	d2 = (ev.dx - ev.dy) << 1;
	draw_pxl(ev, ev.coords[ev.cur_0].x, ev.coords[ev.cur_0].y);
	ev.y = ev.coords[ev.cur_0].y + ev.sy;
	ev.x = ev.coords[ev.cur_0].x;
	i = 1;
	while (i <= ev.dy)
	{
		if (d > 0)
		{
			d += d2;
			ev.x += ev.sx;
		}
		else
			d += d1;
		draw_pxl(ev, ev.x, ev.y);
		ev.y += ev.sy;
		i++;
	}
}

void		line(t_all ev)
{
	ev.dx = abs(ev.coords[ev.cur_1].x - ev.coords[ev.cur_0].x);
	ev.dy = abs(ev.coords[ev.cur_1].y - ev.coords[ev.cur_0].y);
	ev.sx = ev.coords[ev.cur_1].x >= ev.coords[ev.cur_0].x ? 1 : -1;
	ev.sy = ev.coords[ev.cur_1].y >= ev.coords[ev.cur_0].y ? 1 : -1;
	ev.dy <= ev.dx ? pr_x_max(ev) : pr_y_max(ev);
}

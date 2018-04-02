/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 20:12:15 by htkachuk          #+#    #+#             */
/*   Updated: 2018/03/09 20:12:18 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_all	ft_zoom(t_all ev)
{
	int		i;
	double	x;
	double	y;
	double	z;

	i = 0;
	while (i < ev.count)
	{
		y = ev.coords[i].y;
		x = ev.coords[i].x;
		z = ev.coords[i].z;
		x = x * cos(ev.angle) - ev.coords[i].y * sin(ev.angle);
		y = (ev.coords[i].x * sin(ev.angle)) + ev.coords[i].y * cos(ev.angle);
		x = x * cos(ev.angle) + ev.coords[i].z * sin(ev.angle);
		z = -1 * (ev.coords[i].x * sin(ev.angle))
		+ ev.coords[i].z * cos(ev.angle);
		x = x * ev.zoom;
		y = y * ev.zoom - z;
		ev.coords[i].x = x;
		ev.coords[i].y = y;
		ev.coords[i].x += (SIZE_X / 2) + ev.right;
		ev.coords[i].y += (SIZE_Y / 2) + ev.down;
		i++;
	}
	return (ev);
}

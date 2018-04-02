/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 19:00:19 by htkachuk          #+#    #+#             */
/*   Updated: 2018/03/16 19:00:24 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_func(int *param, int smth, t_all *ev)
{
	ft_create_img(ev);
	*param += smth;
	ft_print(*ev);
	return (1);
}

int			ft_key(int keycode, t_all *ev)
{
	if (keycode == 53)
	{
		exit(1);
	}
	(keycode == 69) ? ft_func(&(ev->zoom), 1, ev) : 0;
	(keycode == 78) ? ft_func(&(ev->zoom), -1, ev) : 0;
	(keycode == 124) ? ft_func(&(ev->right), 10, ev) : 0;
	(keycode == 123) ? ft_func(&(ev->right), -10, ev) : 0;
	(keycode == 125) ? ft_func(&(ev->down), 10, ev) : 0;
	(keycode == 126) ? ft_func(&(ev->down), -10, ev) : 0;
	if (keycode == 0)
	{
		ft_create_img(ev);
		ev->angle += 0.1;
		ft_print(*ev);
	}
	if (keycode == 2)
	{
		ft_create_img(ev);
		ev->angle -= 0.1;
		ft_print(*ev);
	}
	return (1);
}

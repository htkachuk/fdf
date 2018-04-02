/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 19:17:03 by htkachuk          #+#    #+#             */
/*   Updated: 2018/03/16 19:17:06 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_create_img(t_all *ev)
{
	ev->img = mlx_new_image(ev->mlx, SIZE_X, SIZE_Y);
	ev->str = mlx_get_data_addr(ev->img, &(ev->bits), &(ev->size), &(ev->end));
}

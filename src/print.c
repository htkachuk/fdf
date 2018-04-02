/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:06:12 by htkachuk          #+#    #+#             */
/*   Updated: 2018/03/19 18:42:09 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_col_cost(int z)
{
	if (z < 11)
		return (ft_atoi_16("0xdee8f7"));
	if (z > 10 && z < 16)
		return (ft_atoi_16("0xadc9f4"));
	if (z > 16 && z < 21)
		return (ft_atoi_16("0x79a9f7"));
	if (z > 21 && z < 30)
		return (ft_atoi_16("0x91b8f7"));
	if (z > 30 && z < 40)
		return (ft_atoi_16("0x79a7f2"));
	if (z > 40 && z < 50)
		return (ft_atoi_16("0x5b94ef"));
	if (z > 50 && z < 60)
		return (ft_atoi_16("0x4786ed"));
	if (z > 60 && z < 70)
		return (ft_atoi_16("0x4786ed"));
	if (z > 70 && z < 80)
		return (ft_atoi_16("0x337ef7"));
	if (z > 80 && z < 90)
		return (ft_atoi_16("0x2171f2"));
	if (z > 90 && z < 100)
		return (ft_atoi_16("0x0e65f2"));
	else
		return (ft_atoi_16("0x025def"));
}

static int	char_idx(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (str[i] == c ? i : -1);
}

int			ft_atoi_16(char *str)
{
	int		i[2];
	int		mask;
	int		res;

	mask = 1;
	res = 0;
	i[0] = ft_strlen(str);
	while (i[0]-- > 2)
	{
		i[1] = !((ft_strchr("0123456789ABCDEF", str[i[0]]))) ? -1
		: char_idx("0123456789ABCDEF", str[i[0]]);
		if (i[1] == -1)
			i[1] = !((ft_strchr("0123456789abcdef", str[i[0]]))) ? -1
		: char_idx("0123456789abcdef", str[i[0]]);
		if (i[1] != -1)
		{
			res = res + i[1] * mask;
			mask = mask * 16;
		}
	}
	return (res);
}

static void	ft_change_coord(t_all ev)
{
	int		i;

	i = 0;
	while (i < ev.count)
	{
		ev.coords[i].x = ev.c_chn[i].x;
		ev.coords[i].y = ev.c_chn[i].y;
		ev.coords[i].z = ev.c_chn[i].z;
		ev.coords[i].color = ev.c_chn[i].color;
		ev.coords[i].red = ev.c_chn[i].red;
		ev.coords[i].green = ev.c_chn[i].green;
		ev.coords[i].blue = ev.c_chn[i].blue;
		i++;
	}
}

void		ft_print(t_all ev)
{
	int		i;
	int		j;

	ft_change_coord(ev);
	ev = ft_zoom(ev);
	i = 0;
	j = ev.len + 1;
	while (i < ev.count)
	{
		if (((i + 1) <= ev.count) && (j % ev.len))
		{
			ev.cur_0 = i;
			ev.cur_1 = i + 1;
			line(ev);
		}
		if ((i + ev.len) < ev.count)
		{
			ev.cur_0 = i;
			ev.cur_1 = i + ev.len;
			line(ev);
		}
		j++;
		i++;
	}
	mlx_put_image_to_window(ev.mlx, ev.win, ev.img, 0, 0);
}

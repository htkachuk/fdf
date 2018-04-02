/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_write_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 18:24:17 by htkachuk          #+#    #+#             */
/*   Updated: 2018/03/02 18:24:22 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_color(int i, int j, t_all *ev, char **split)
{
	char	**sp_col;
	int		k;

	if (!(ft_strchr(split[i], ',')))
		ev->c_chn[i + j].color = (ev->c_chn[i + j].z == 0
			? ft_atoi_16("0xffffff") : ft_col_cost(ev->c_chn[i + j].z));
	else
	{
		sp_col = ft_strsplit(split[i], ',');
		ev->c_chn[i + j].color = ft_atoi_16(sp_col[1]);
		k = 0;
		while (sp_col[k])
			ft_strdel(&sp_col[k++]);
		ft_memdel((void**)&sp_col);
	}
	ev->c_chn[i + j].red = (ev->c_chn[i + j].color >> 16);
	ev->c_chn[i + j].green = (ev->c_chn[i + j].color >> 8)
	- (ev->c_chn[i + j].red << 8);
	ev->c_chn[i + j].blue = (ev->c_chn[i + j].color)
	- (ev->c_chn[i + j].red << 16) - (ev->c_chn[i + j].green << 8);
}

static size_t	write_map(char *line, t_all *ev, int c, int j)
{
	char	**split;
	size_t	i;
	int		k;

	i = 0;
	split = ft_strsplit(line, ' ');
	while (split[i])
	{
		ev->c_chn[i + j].z = ft_atoi(split[i]);
		ft_color(i, j, ev, split);
		i == 0 ? ev->c_chn[i + j].x = 0 - (ev->len / 2)
		: (ev->c_chn[i + j].x = ev->c_chn[i + j - 1].x + 1);
		ev->c_chn[i + j].y = c - (ev->count / ev->len / 2);
		i++;
	}
	k = 0;
	while (split[k])
		ft_strdel(&split[k++]);
	ft_memdel((void**)&split);
	return (i + j - 1);
}

static void		allocate_mem_write(size_t count, t_all *ev, int fd, char *argv)
{
	int			c;
	char		*line;
	int			j;
	int			s;

	c = 0;
	j = 0;
	ev->count = count;
	if (!(ev->c_chn = (t_coord*)malloc(sizeof(t_coord) * count)))
		return ;
	close(fd);
	fd = open(argv, O_RDONLY);
	while ((s = get_next_line(fd, &line)))
	{
		j = write_map(line, ev, c, j);
		ft_strdel(&line);
		c++;
		j++;
	}
}

static int		count_column(char *line, t_all *ev)
{
	char	**split;
	size_t	i;
	int		k;

	i = 0;
	split = ft_strsplit(line, ' ');
	while (split[i])
		i++;
	ev->len = i;
	k = 0;
	while (split[k])
		ft_strdel(&split[k++]);
	ft_memdel((void**)&split);
	return (i);
}

void			count_map(char *argv, t_all *ev)
{
	char				*line;
	int					ret;
	int					fd;
	static int			r = 0;
	size_t				check[2];

	fd = open(argv, O_RDONLY);
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
		{
			ft_putstr_fd("usage: ./fdf source_FILE!\n", 2);
			exit(0);
		}
		r == 0 ? check[0] = count_column(line, ev)
		: (check[1] = count_column(line, ev));
		if (check[0] != check[1] && r != 0)
		{
			ft_putstr_fd("map is not valid\n", 2);
			exit(0);
		}
		r++;
		ft_strdel(&line);
	}
	allocate_mem_write((check[0] * r), ev, fd, argv);
}

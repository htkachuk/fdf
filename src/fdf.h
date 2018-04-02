/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 15:42:18 by htkachuk          #+#    #+#             */
/*   Updated: 2018/03/21 14:35:41 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define SIZE_Y 1200
# define SIZE_X 1200

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <stdio.h>
# include "get_next_line.h"
# include <math.h>

typedef struct		s_coord
{
	int				x;
	int				y;
	int				z;
	int				color;
	int				red;
	int				green;
	int				blue;
}					t_coord;

typedef struct		s_all
{
	int				count;
	int				len;
	void			*mlx;
	void			*win;
	char			*str;
	void			*img;
	int				bits;
	int				size;
	int				end;
	t_coord			*coords;
	t_coord			*c_chn;
	int				cur_0;
	int				cur_1;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				x;
	int				y;
	int				zoom;
	int				right;
	int				down;
	double			angle;
}					t_all;

int					get_next_line(const int fd, char **line);
void				count_map(char *argv, t_all *all);
void				line(t_all ev);
void				ft_print(t_all ev);
t_all				ft_zoom(t_all ev);
void				ft_create_img(t_all *ev);
int					ft_key(int keycode, t_all *ev);
int					ft_atoi_16(char *str);
void				ft_create_img(t_all *ev);
int					ft_col_cost(int z);

#endif

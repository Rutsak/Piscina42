/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:42:20 by doller-m          #+#    #+#             */
/*   Updated: 2024/01/04 14:01:32 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "./libft/libft.h"
# include "keys.h"

typedef struct s_screen_data
{
	void	*mlx;
	void	*mlx_w;
	void	*mlx_img;
	char	*addr;
	int		bits_pixel;
	int		l_length;
	int		endian;
	int		x_win;
	int		y_win;
	int		color;
	float	scale;
	float	elastic_z;
	int		frame_x;
	int		frame_y;
	int		grades_x;
	int		grades_y;
	int		grades_z;
}	t_scr_dt;

typedef struct s_map_data
{
	int		**geo_coord;
	int		map_lines;
	int		map_col;
	int		i;
	int		j;
	char	*a;
	char	**row_splited;
	int		row_int;
}	t_map_dt;

typedef struct s_point_3d
{
	float	axis[3];
}	t_point_3d;

typedef struct s_2D_point
{
	double	x;
	double	y;
}	t_2D_point;

typedef struct s_param
{
	t_map_dt	*map_dt;
	t_scr_dt	*scr_dt;
	int			a;
	int			b;
	t_2D_point	p_origin;
	t_2D_point	p_end;
}	t_param;

int			scr_win_gen(t_map_dt *map_dt);
int			scr_init(t_param *param, t_scr_dt *scr_dt);
void		scr_draw(t_param *param);
void		image_generator(t_scr_dt *scr_dt);
void		image_pixel_put(t_scr_dt *scr_dt, int x, int y, int color);
t_point_3d	mul_mat(float matrix[3][3], t_point_3d point);
void		rotate_x(t_point_3d *points, t_point_3d *proy, float ang, int len);
void		rotate_y(t_point_3d *points, t_point_3d *proy, float ang, int len);
void		rotate_z(t_point_3d *points, t_point_3d *proy, float ang, int len);
void		scale(t_point_3d *points, t_point_3d *proy, float scale, int len);
t_2D_point	map_dot_loader(t_map_dt *map_dt, t_scr_dt *scr_dt, int x, int y);
int			map_long(char **row_splited, t_map_dt map_dt);
void		fdf_free(void **index);
void		init_map(t_map_dt *map_dt);
void		init_scr(t_scr_dt *scr_dt);
int			key_pressed(int keycode, t_param *param);
int			close_window(t_param *param);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:42:20 by doller-m          #+#    #+#             */
/*   Updated: 2023/12/12 12:48:50 by doller-m         ###   ########.fr       */
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
	int		x_win;
	int		y_win;
	int		color;
	float	scale;
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
}	t_map_dt;

typedef struct s_param
{
	t_map_dt	*map_dt;
	t_scr_dt	*scr_dt;
}	t_param;

typedef struct s_point_3d
{
	float	axis[3];
}	t_point_3d;

typedef struct s_2D_point
{
	double	x;
	double	y;
}	t_2D_point;

int			scr_win_gen(t_map_dt *map_dt);
int			scr_pix_gen(t_scr_dt scr_dt, int x, int y);
int			scr_draw(t_param *param);
int			scr_x_convert(int x, int y, int z, t_scr_dt scr_dt);
int			scr_y_convert(int x, int y, int z, t_scr_dt scr_dt);
void		rotate_x(t_point_3d *points, t_point_3d *proy, float ang, int len);
void		rotate_y(t_point_3d *points, t_point_3d *proy, float ang, int len);
void		rotate_z(t_point_3d *points, t_point_3d *proy, float ang, int len);
void		scale(t_point_3d *points, t_point_3d *proy, float scale, int len);
t_2D_point	map_dot_loader(t_map_dt *map_dt, t_scr_dt *scr_dt, int x, int y);
void		fdf_free(int **index, int i);
int			key_pressed(int keycode, t_param *param);
int			close_window(t_param *param);

#endif
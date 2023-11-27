/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:42:20 by doller-m          #+#    #+#             */
/*   Updated: 2023/11/27 17:35:22 by doller-m         ###   ########.fr       */
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

/* struct s_screen_data
{
	void	*mlx;
	void	*mlx_w;
	int		x_win;
	int		y_win;
} scr_dt; */

typedef struct s_screen_data
{
	void		*mlx;
	void		*mlx_w;
	int			x_win;
	int			y_win;
	int			color;
	float		scale;
	int			frame_x;
	int			frame_y;
	int			grades_x;
	int			grades_y;
	int			grades_z;
	int			proj_grades;
}	t_scr_dt;

/* struct s_map_data
{
	int		**geo_coord;
	int		map_lines;
	int		map_col;
} map_dt; */

typedef struct s_map_data
{
	int		**geo_coord;
	int		map_lines;
	int		map_col;
}	t_map_dt;

typedef struct s_point_3d
{
	long int	x;
	long int	y;
	long int	z;
}	t_point_3d;

typedef struct s_2D_point
{
	double	x;
	double	y;
}	t_2D_point;

int			scr_win_gen(t_map_dt *map_dt);
int			scr_pix_gen(t_scr_dt scr_dt, int x, int y);
int			scr_x_convert(int x, int y, int z, t_scr_dt scr_dt);
int			scr_y_convert(int x, int y, int z, t_scr_dt scr_dt);
t_2D_point	map_dot_loader(t_map_dt *map_dt, t_scr_dt *scr_dt, int x, int y);
int			close_window(t_scr_dt *scr_dt, t_map_dt *map_dt);


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:00:17 by doller-m          #+#    #+#             */
/*   Updated: 2023/11/20 14:44:02 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include "fdf.h"

int	scr_pix_gen(t_scr_dt scr_dt, int x, int y)
{
	mlx_pixel_put(scr_dt.mlx, scr_dt.mlx_w, x, y, scr_dt.color);
	return (1);
}

int	scr_line_drw(t_scr_dt scr_dt, t_2D_point origin, t_2D_point end)
{
	double	x_line;
	double	y_line;
	double	x_pixel;
	double	y_pixel;
	int		pixels;

	x_line = end.x - origin.x;
	y_line = end.y - origin.y;
	pixels = sqrt((x_line * x_line) + (y_line * y_line));
	x_line /= pixels;
	y_line /= pixels;
	x_pixel = origin.x;
	y_pixel = origin.y;
	while (pixels)
	{
		scr_pix_gen(scr_dt, x_pixel, y_pixel);
		x_pixel += x_line;
		y_pixel += y_line;
		--pixels;
	}
	return (0);
}

int	scr_draw(t_scr_dt scr_dt, t_map_dt map_dt)
{
	int			i;
	int			j;
	t_2D_point	p_origin;
	t_2D_point	p_end;

	i = 0;
	j = 0;
	printf("Filas: %i\n", map_dt.map_lines);
	printf("Columnas: %i\n", map_dt.map_col);
	while (i < map_dt.map_lines)
	{
		while (j < map_dt.map_col)
		{
			printf("Altura [%i][%i]: %i\n", i, j, map_dt.geo_coord[i][j]);
			p_origin = map_dot_loader(map_dt, scr_dt, i, j);
			p_end = map_dot_loader(map_dt, scr_dt, i, j + 1);
			if (j <= map_dt.map_col - 2)
				scr_line_drw(scr_dt, p_origin, p_end);
			p_end = map_dot_loader(map_dt, scr_dt, i + 1, j);
			if (i <= map_dt.map_lines - 2)
				scr_line_drw(scr_dt, p_origin, p_end);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	scr_win_gen(t_map_dt map_dt)
{
	t_scr_dt	scr_dt;

	scr_dt.color = 0xFFFFFF;
	scr_dt.x_win = 500;
	scr_dt.y_win = 500;
	scr_dt.mlx = mlx_init();
	if (scr_dt.mlx == NULL)
		return (0);
	scr_dt.mlx_w = mlx_new_window(scr_dt.mlx, scr_dt.x_win, scr_dt.y_win, "Hi");
	if (scr_dt.mlx_w == NULL)
	{
		free(scr_dt.mlx);
		return (0);
	}
	scr_dt.scale = 10;
	scr_dt.frame_x = 50;
	scr_dt.frame_y = 50;
	scr_draw(scr_dt, map_dt);
	mlx_loop(scr_dt.mlx);
	mlx_destroy_window(scr_dt.mlx, scr_dt.mlx_w);
	free(scr_dt.mlx);
	return (0);
}

/* int	main(void)
{
	scr_win_gen();
	return (0);
} */

/* int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		x_window;
	int		y_window;
	int 	x;
	int		y;

	x_window = 500;
	y_window = 500;
	x = 0;
	y = 0;
	mlx = mlx_init();
	if (mlx == NULL)
		return (0);
	mlx_win = mlx_new_window(mlx, x_window, y_window, "Hello world!");
	if (mlx_win == NULL)
	{
		free(mlx);
		return (0);
	}
	while (x != 400)
	{
		x++;
		y++;
		mlx_pixel_put(mlx, mlx_win, x, y, 0xFFFFFF);
	}*/
/* 	mlx_pixel_put(mlx, mlx_win, x, 51, 0xFFFFFF);
	mlx_pixel_put(mlx, mlx_win, x, 52, 0xFFFFFF);
	mlx_pixel_put(mlx, mlx_win, x, 53, 0xFFFFFF);
	mlx_pixel_put(mlx, mlx_win, x, 54, 0xFFFFFF); */
/*	mlx_loop(mlx);
	mlx_destroy_window(mlx, mlx_win);
	free(mlx);
} */
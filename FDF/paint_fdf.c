/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:00:17 by doller-m          #+#    #+#             */
/*   Updated: 2023/12/13 17:04:33 by doller-m         ###   ########.fr       */
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
		if (x_pixel > 0 && x_pixel < scr_dt.x_win)
		{
			if (y_pixel > 0 && y_pixel < scr_dt.y_win)
//				scr_pix_gen(scr_dt, x_pixel, y_pixel);
				image_pixel_put(&scr_dt, x_pixel, y_pixel, scr_dt.color);
		}
		x_pixel += x_line;
		y_pixel += y_line;
		--pixels;
	}
	return (0);
}

int	scr_draw(t_param *param)
{
	int			i;
	int			j;
	t_2D_point	p_origin;
	t_2D_point	p_end;

	i = 0;
	j = 0;
/* 	printf("puntero PARAM: %p \n", param);
	printf("Filas: %i\n", param->map_dt->map_lines);
	printf("Columnas: %i\n", param->map_dt->map_col);
	printf("Window: [%i][%i]\n", param->scr_dt->x_win, param->scr_dt->y_win);
	printf("Color/Scale/Frame: %i/%f/[%i][%i]\n", param->scr_dt->color, param->scr_dt->scale, param->scr_dt->frame_x, param->scr_dt->frame_y);
	printf("X-Grades: %i\n", param->scr_dt->grades_x);
	printf("Y-Grades: %i\n", param->scr_dt->grades_y);
	printf("Z-Grades: %i\n", param->scr_dt->grades_z);
	printf("puntero mlx: %p \n", param->scr_dt->mlx);
	printf("puntero mlx_w param: %p \n", param->scr_dt->mlx_w); */
	if (param->scr_dt->mlx_img != NULL)
		mlx_destroy_image(param->scr_dt->mlx, param->scr_dt->mlx_img);
	image_generator(param->scr_dt);
	mlx_clear_window(param->scr_dt->mlx, param->scr_dt->mlx_w);
	while (i < param->map_dt->map_lines)
	{
		while (j < param->map_dt->map_col)
		{
//			printf("Altura [%i][%i]: %i\n", i, j, param->map_dt->geo_coord[i][j]);
			p_origin = map_dot_loader(param->map_dt, param->scr_dt, i, j);
//			printf("p_origin [%i][%i][%i] -> {%f, %f} \n", i, j, param->map_dt->geo_coord[i][j], p_origin.x, p_origin.y);
			p_end = map_dot_loader(param->map_dt, param->scr_dt, i, j + 1);
			if (j <= param->map_dt->map_col - 2)
				scr_line_drw(*param->scr_dt, p_origin, p_end);
			if (i + 1 < param->map_dt->map_lines)
			{
				p_end = map_dot_loader(param->map_dt, param->scr_dt, i + 1, j);
				if (i <= param->map_dt->map_lines - 2)
				{
					scr_line_drw(*param->scr_dt, p_origin, p_end);
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(param->scr_dt->mlx, param->scr_dt->mlx_w, param->scr_dt->mlx_img, 0, 0);
	return (0);
}

int	scr_win_gen(t_map_dt *map_dt)
{
	t_scr_dt	scr_dt;
	t_param		param;

	param.scr_dt = &scr_dt;
	param.map_dt = map_dt;
	param.scr_dt->mlx = NULL;
	param.scr_dt->mlx_w = NULL;
	scr_dt.color = 0xFFFFFF;
	scr_dt.x_win = 1020;
	scr_dt.y_win = 700;
	scr_dt.mlx = mlx_init();
	scr_dt.scale = 20;
	scr_dt.elastic_z = -0.1;
	scr_dt.frame_x = scr_dt.x_win / 2;
	scr_dt.frame_y = scr_dt.y_win / 2;
	scr_dt.grades_x = 30;
	scr_dt.grades_y = 215;
	scr_dt.grades_z = 310;
	if (scr_dt.mlx == NULL)
		return (0);
	scr_dt.mlx_w = mlx_new_window(scr_dt.mlx, scr_dt.x_win, scr_dt.y_win, "FDF");
	if (scr_dt.mlx_w == NULL)
	{
		free(scr_dt.mlx);
		return (0);
	}
	mlx_key_hook(scr_dt.mlx_w, key_pressed, &param);
	scr_draw(&param);
	mlx_loop(scr_dt.mlx);
	return (0);
}

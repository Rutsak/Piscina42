/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:00:17 by doller-m          #+#    #+#             */
/*   Updated: 2024/01/04 13:03:54 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include "fdf.h"

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
				image_pixel_put(&scr_dt, x_pixel, y_pixel, scr_dt.color);
		}
		x_pixel += x_line;
		y_pixel += y_line;
		--pixels;
	}
	return (0);
}

int	scr_init(t_param *param, t_scr_dt *scr_dt)
{
	if (param->scr_dt->mlx_img != NULL)
		mlx_destroy_image(param->scr_dt->mlx, param->scr_dt->mlx_img);
	image_generator(param->scr_dt);
	mlx_clear_window(param->scr_dt->mlx, param->scr_dt->mlx_w);
	scr_draw(param);
	mlx_put_image_to_window(scr_dt->mlx, scr_dt->mlx_w, scr_dt->mlx_img, 0, 0);
	return (0);
}

void	scr_draw(t_param *param)
{
	param->a = 0;
	param->b = 0;
	while (param->a < param->map_dt->map_lines)
	{
		while (param->b < param->map_dt->map_col)
		{
			param->p_origin = map_dot_loader(param->map_dt, param->scr_dt,
					param->a, param->b);
			param->p_end = map_dot_loader(param->map_dt, param->scr_dt,
					param->a, param->b + 1);
			if (param->b <= param->map_dt->map_col - 2)
				scr_line_drw(*param->scr_dt, param->p_origin, param->p_end);
			if (param->a + 1 < param->map_dt->map_lines)
			{
				param->p_end = map_dot_loader(param->map_dt, param->scr_dt,
						param->a + 1, param->b);
				if (param->a <= param->map_dt->map_lines - 2)
					scr_line_drw(*param->scr_dt, param->p_origin, param->p_end);
			}
			param->b++;
		}
		param->b = 0;
		param->a++;
	}
}

int	scr_win_gen(t_map_dt *map_dt)
{
	t_scr_dt	scr_dt;
	t_param		param;

	init_scr(&scr_dt);
	param.scr_dt = &scr_dt;
	param.map_dt = map_dt;
	param.scr_dt->mlx = NULL;
	param.scr_dt->mlx_w = NULL;
	scr_dt.mlx = mlx_init();
	if (scr_dt.mlx == NULL)
		return (0);
	param.a = scr_dt.x_win;
	param.b = scr_dt.y_win;
	scr_dt.mlx_w = mlx_new_window(scr_dt.mlx, param.a, param.b, "FDF");
	if (scr_dt.mlx_w == NULL)
	{
		free(scr_dt.mlx);
		return (0);
	}
	mlx_key_hook(scr_dt.mlx_w, key_pressed, &param);
	mlx_hook(scr_dt.mlx_w, 17, 0, close_window, &param);
	scr_init(&param, &scr_dt);
	mlx_loop(scr_dt.mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:55:14 by doller-m          #+#    #+#             */
/*   Updated: 2023/12/13 17:06:07 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include "fdf.h"

int	key_pressed(int keycode, t_param *param)
{
	if (keycode == ESC_KEY)
	{
		close_window(param);
	}
	if (keycode == LEFT_KEY)
	{
		param->scr_dt->grades_z += 10;
		scr_draw(param);
		printf("Z_graus modificats a %i\n", param->scr_dt->grades_z);
	}
	if (keycode == RIGHT_KEY)
	{
		param->scr_dt->grades_z -= 10;
		scr_draw(param);
		printf("Z_graus modificats a %i\n", param->scr_dt->grades_z);
	}
	if (keycode == UP_KEY)
	{
		param->scr_dt->grades_y += 10;
		scr_draw(param);
		printf("Y_graus modificats a %i\n", param->scr_dt->grades_y);
	}
	if (keycode == DOWN_KEY)
	{
		param->scr_dt->grades_y -= 10;
		scr_draw(param);
		printf("Y_graus modificats a %i\n", param->scr_dt->grades_y);
	}
	if (keycode == A_KEY)
	{
		param->scr_dt->grades_x += 10;
		scr_draw(param);
		printf("X_graus modificats a %i\n", param->scr_dt->grades_x);
	}
	if (keycode == S_KEY)
	{
		param->scr_dt->grades_x -= 10;
		scr_draw(param);
		printf("X_graus modificats a %i\n", param->scr_dt->grades_x);
	}
	if (keycode == Z_KEY)
	{
		param->scr_dt->scale += 1;
		scr_draw(param);
		printf("Zoom modificat a %f\n", param->scr_dt->scale);
	}
	if (keycode == X_KEY)
	{
		param->scr_dt->scale -= 1;
		scr_draw(param);
		printf("Zoom modificat a %f\n", param->scr_dt->scale);
	}
	if (keycode == Q_KEY)
	{
		param->scr_dt->elastic_z += 0.1;
		scr_draw(param);
		printf("Z-Elastic modificat a %f\n", param->scr_dt->elastic_z);
	}
	if (keycode == W_KEY)
	{
		param->scr_dt->elastic_z -= 0.1;
		scr_draw(param);
		printf("Z-Elastic modificat a %f\n", param->scr_dt->elastic_z);
	}
	return (0);
}

int	close_window(t_param *param)
{
	printf("Free pendent\n");
	fdf_free(param->map_dt->geo_coord, param->map_dt->map_lines);
	printf("Free fet\n");
	printf("puntero mlx: %p \n", param->scr_dt->mlx);
	printf("puntero mlx_w: %p \n", param->scr_dt->mlx_w);
	mlx_clear_window(param->scr_dt->mlx, param->scr_dt->mlx_w);
	mlx_destroy_window(param->scr_dt->mlx, param->scr_dt->mlx_w);
	exit (EXIT_SUCCESS);
}
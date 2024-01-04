/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:55:14 by doller-m          #+#    #+#             */
/*   Updated: 2024/01/04 13:17:29 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include "fdf.h"

void	key_loop(t_param *param, int *variable, int new_valor)
{
	int	a;

	a = *variable;
	*variable = a + new_valor;
	scr_init(param, param->scr_dt);
	printf("Valor a %i\n", new_valor);
}

void	key_loop_float(t_param *param, float *variable, float new_valor)
{
	float	a;

	a = *variable;
	*variable = a + new_valor;
	scr_init(param, param->scr_dt);
	printf("Valor a %f\n", new_valor);
}

int	key_pressed(int keycode, t_param *param)
{
	if (keycode == ESC_KEY)
	{
		close_window(param);
	}
	if (keycode == LEFT_KEY)
		key_loop(param, &param->scr_dt->grades_z, 10);
	if (keycode == RIGHT_KEY)
		key_loop(param, &param->scr_dt->grades_z, -10);
	if (keycode == UP_KEY)
		key_loop(param, &param->scr_dt->grades_y, 10);
	if (keycode == DOWN_KEY)
		key_loop(param, &param->scr_dt->grades_y, -10);
	if (keycode == Z_KEY)
		key_loop_float(param, &param->scr_dt->scale, 1);
	if (keycode == X_KEY)
		key_loop_float(param, &param->scr_dt->scale, -1);
	if (keycode == Q_KEY)
		key_loop_float(param, &param->scr_dt->elastic_z, 0.1);
	if (keycode == W_KEY)
		key_loop_float(param, &param->scr_dt->elastic_z, -0.1);
	return (0);
}

int	close_window(t_param *param)
{
	printf("Free pendent\n");
	fdf_free((void **)param->map_dt->geo_coord);
	printf("Free fet\n");
	printf("puntero mlx: %p \n", param->scr_dt->mlx);
	printf("puntero mlx_w: %p \n", param->scr_dt->mlx_w);
	mlx_clear_window(param->scr_dt->mlx, param->scr_dt->mlx_w);
	mlx_destroy_window(param->scr_dt->mlx, param->scr_dt->mlx_w);
	exit (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:55:14 by doller-m          #+#    #+#             */
/*   Updated: 2023/12/05 17:05:52 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include "fdf.h"

int	key_pressed(int keycode, t_param *param)
{
	if (keycode == ESC_KEY)
		close_window(param);
	if (keycode == LEFT_KEY)
	{
		param->scr_dt->scale += 10;
		scr_draw(param->scr_dt, param->map_dt);
		printf("Escala modificada a %f\n", param->scr_dt->scale);
	}
	return (0);
}

int	close_window(t_param *param)
{
//	printf("Free pendent\n");
	fdf_free(param->map_dt->geo_coord, param->map_dt->map_lines);
//	printf("Free fet\n");
//	mlx_destroy_image(scr_dt->mlx, scr_dt->mlx_w);
	mlx_clear_window(param->scr_dt->mlx, param->scr_dt->mlx_w);
	mlx_destroy_window(param->scr_dt->mlx, param->scr_dt->mlx_w);
//	mlx_destroy_image(scr_dt->mlx, ((mlx_ptr_t *)scr_dt->mlx)->img_list);
	exit (EXIT_SUCCESS);
}
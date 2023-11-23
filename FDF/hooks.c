/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:55:14 by doller-m          #+#    #+#             */
/*   Updated: 2023/11/23 11:40:17 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include "fdf.h"

int	key_pressed(int keycode, t_scr_dt *scr_dt, t_map_dt *map_dt)
{
	if (keycode == ESC_KEY)
		close_window(scr_dt, map_dt);
	return (0);
}

int	close_window(t_scr_dt *scr_dt, t_map_dt *map_dt)
{
	free(map_dt->geo_coord);
//	mlx_destroy_image(scr_dt->mlx, scr_dt->img.img);
	mlx_clear_window(scr_dt->mlx, scr_dt->mlx_w);
	mlx_destroy_window(scr_dt->mlx, scr_dt->mlx_w);
//	mlx_destroy_image(scr_dt->mlx, ((mlx_ptr_t *)scr_dt->mlx)->img_list);
	exit (EXIT_SUCCESS);
}
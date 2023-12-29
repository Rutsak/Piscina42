/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struc_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:29:33 by doller-m          #+#    #+#             */
/*   Updated: 2023/12/19 15:49:25 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_map(t_map_dt *map_dt)
{
	map_dt->geo_coord = NULL;
	map_dt->map_lines = 0;
	map_dt->map_col = 0;
}

void	init_scr(t_scr_dt *scr_dt)
{
	scr_dt->mlx = NULL;
	scr_dt->mlx_w = NULL;
	scr_dt->mlx_img = NULL;
	scr_dt->addr = 0;
	scr_dt->bits_pixel = 0;
	scr_dt->l_length = 0;
	scr_dt->endian = 0;
	scr_dt->x_win = 0;
	scr_dt->y_win = 0;
	scr_dt->color = 0;
	scr_dt->scale = 0;
	scr_dt->elastic_z = 0;
	scr_dt->frame_x = 0;
	scr_dt->frame_y = 0;
	scr_dt->grades_x = 0;
	scr_dt->grades_y = 0;
	scr_dt->grades_z = 0;
}
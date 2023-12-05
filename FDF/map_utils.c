/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:51:02 by doller-m          #+#    #+#             */
/*   Updated: 2023/12/05 16:18:50 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_2D_point	map_dot_loader(t_map_dt *map_dt, t_scr_dt *scr_dt, int x, int y)
{
	double		x_conv;
	double		y_conv;
	t_point_3d	temp_3d_ori;
	t_point_3d	temp_3d_dst;
	t_2D_point	a;

	a.x = 0;
	a.y = 0;
	temp_3d_ori.axis[0] = x;
	temp_3d_ori.axis[1] = y;
	temp_3d_ori.axis[2] = map_dt->geo_coord[x][y];
	temp_3d_dst.axis[0] = 0;
	temp_3d_dst.axis[1] = 0;
	temp_3d_dst.axis[2] = 0;
	rotate_x(&temp_3d_ori, &temp_3d_dst, scr_dt->grades_z, 3);
	rotate_y(&temp_3d_dst, &temp_3d_ori, scr_dt->grades_y, 3);
	rotate_z(&temp_3d_ori, &temp_3d_dst, scr_dt->grades_z, 3);
	scale(&temp_3d_dst, &temp_3d_ori, scr_dt->scale, 3);
	x_conv = temp_3d_ori.axis[0];
	y_conv = temp_3d_ori.axis[1];
	a.x = x_conv + scr_dt->frame_x;
	a.y = y_conv + scr_dt->frame_y;
	return (a);
}

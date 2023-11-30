/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:51:02 by doller-m          #+#    #+#             */
/*   Updated: 2023/11/30 16:37:30 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* void	x_rotate(t_scr_dt *scr_dt, t_point_3d *pnt3d)
{
	int	y;
	int	z;

	y = (pnt3d->axis[0] * cos(scr_dt->grades_x)) - (pnt3d->axis[2] * sin(scr_dt->grades_x));
	z = (pnt3d->axis[1] * sin(scr_dt->grades_x)) + (pnt3d->axis[2] * cos(scr_dt->grades_x));
	pnt3d->axis[1] = y;
	pnt3d->axis[2] = z;
}

void	y_rotate(t_scr_dt *scr_dt, t_point_3d *pnt3d)
{
	int	x;
	int	z;

	x = (pnt3d->axis[0] * cos(scr_dt->grades_y)) - (pnt3d->axis[2] * sin(scr_dt->grades_y));
	z = (pnt3d->axis[2] * cos(scr_dt->grades_y)) + (pnt3d->axis[0] * sin(scr_dt->grades_y));
	pnt3d->axis[0] = x;
	pnt3d->axis[2] = z;
}

void	z_rotate(t_scr_dt *scr_dt, t_point_3d *pnt3d)
{
	int	x;
	int	y;

	x = (pnt3d->axis[0] * cos(scr_dt->grades_z)) - (pnt3d->axis[1] * sin(scr_dt->grades_z));
	y = (pnt3d->axis[0] * sin(scr_dt->grades_z)) + (pnt3d->axis[1] * cos(scr_dt->grades_z));
	pnt3d->axis[0] = x;
	pnt3d->axis[1] = y;
} */

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
	scr_dt->left = 0;
	scr_dt->right = map_dt->map_col;
	scr_dt->bottom = 0;
	scr_dt->top = map_dt->map_lines;
	scr_dt->near = map_dt->min_z;
	scr_dt->far = map_dt->max_z;
//	x_conv = scr_x_convert(temp_3d_ori.axis[0], temp_3d_ori.axis[1], temp_3d_ori.axis[2], *scr_dt);
//	printf("x_conv %f \n", x_conv);
//	y_conv = scr_y_convert(temp_3d_ori.axis[0], temp_3d_ori.axis[1], temp_3d_ori.axis[2], *scr_dt);
//	printf("y_conv %f \n", y_conv);
	rotate_x(&temp_3d_ori, &temp_3d_dst, scr_dt->grades_z, 3);
	rotate_y(&temp_3d_dst, &temp_3d_ori, scr_dt->grades_y, 3);
	rotate_z(&temp_3d_ori, &temp_3d_dst, scr_dt->grades_z, 3);
	x_conv = temp_3d_dst.axis[0];
	y_conv = temp_3d_dst.axis[1];
	a.x = (x_conv * scr_dt->scale) + scr_dt->frame_x;
	a.y = (y_conv * scr_dt->scale) + scr_dt->frame_y;
	return (a);
}

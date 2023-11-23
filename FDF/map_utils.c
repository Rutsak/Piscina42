/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:51:02 by doller-m          #+#    #+#             */
/*   Updated: 2023/11/23 15:27:43 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	x_rotate(t_scr_dt *scr_dt, t_point_3d *pnt3d)
{
	int	y;
	int	z;

	y = (pnt3d->x * cos(scr_dt->grades_x)) - (pnt3d->z * sin(scr_dt->grades_x));
	z = (pnt3d->y * sin(scr_dt->grades_x)) + (pnt3d->z * cos(scr_dt->grades_x));
	pnt3d->y = y;
	pnt3d->z = z;
}

void	y_rotate(t_scr_dt *scr_dt, t_point_3d *pnt3d)
{
	int	x;
	int	z;

	x = (pnt3d->x * cos(scr_dt->grades_y)) - (pnt3d->z * sin(scr_dt->grades_y));
	z = (pnt3d->z * cos(scr_dt->grades_y)) + (pnt3d->x * sin(scr_dt->grades_y));
	pnt3d->x = x;
	pnt3d->z = z;
}

void	z_rotate(t_scr_dt *scr_dt, t_point_3d *pnt3d)
{
	int	x;
	int	y;

	x = (pnt3d->x * cos(scr_dt->grades_z)) - (pnt3d->y * sin(scr_dt->grades_z));
	y = (pnt3d->x * sin(scr_dt->grades_z)) + (pnt3d->y * cos(scr_dt->grades_z));
	pnt3d->x = x;
	pnt3d->y = y;
}

t_2D_point	map_dot_loader(t_map_dt *map_dt, t_scr_dt *scr_dt, int x, int y)
{
	int			x_conv;
	int			y_conv;
	t_point_3d	temp_3d;
	t_2D_point	a;

	a.x = 0;
	a.y = 0;
	temp_3d.x = x;
	temp_3d.y = y;
	temp_3d.z = map_dt->geo_coord[x][y];
	x_rotate(scr_dt, &temp_3d);
	y_rotate(scr_dt, &temp_3d);
	z_rotate(scr_dt, &temp_3d);
	x_conv = scr_x_convert(temp_3d.x, temp_3d.y, temp_3d.z, *scr_dt);
	printf("x_conv %i \n", x_conv);
	y_conv = scr_y_convert(temp_3d.x, temp_3d.y, temp_3d.z, *scr_dt);
	printf("y_conv %i \n", y_conv);
	a.x = (x_conv * scr_dt->scale) + scr_dt->frame_x;
	a.y = (y_conv * scr_dt->scale) + scr_dt->frame_x;
	return (a);
}

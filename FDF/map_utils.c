/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:51:02 by doller-m          #+#    #+#             */
/*   Updated: 2023/11/20 15:35:07 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_2D_point	map_dot_loader(t_map_dt map_dt, t_scr_dt scr_dt, int x, int y)
{
	int			i;
	int			x_conv;
	int			y_conv;
	t_2D_point	a;

	i = map_dt.map_col;
	x_conv = scr_x_convert(x, y, map_dt.geo_coord[x][y], scr_dt);
	y_conv = scr_y_convert(x, y, map_dt.geo_coord[x][y], scr_dt);
	a.x = (x_conv * scr_dt.scale) + scr_dt.frame_x;
	a.y = (y_conv * scr_dt.scale) + scr_dt.frame_x;
	return (a);
}

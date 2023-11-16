/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:51:02 by doller-m          #+#    #+#             */
/*   Updated: 2023/11/16 12:42:32 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_2D_point	map_dot_loader(t_map_dt map_dt, t_scr_dt scr_dt, int x, int y)
{
	int			i;
	t_2D_point	a;

	i = map_dt.map_col;
	a.x = (x * scr_dt.scale) + scr_dt.frame_x;
	a.y = (y * scr_dt.scale) + scr_dt.frame_x;
	return (a);
}
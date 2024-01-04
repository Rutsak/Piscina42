/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:29:33 by doller-m          #+#    #+#             */
/*   Updated: 2024/01/04 14:01:02 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void	def_scr(t_scr_dt *scr_dt)
{
	scr_dt->color = 0xFFFFFF;
	scr_dt->x_win = 1800;
	scr_dt->y_win = 1000;
	scr_dt->scale = 20;
	scr_dt->elastic_z = -0.1;
	scr_dt->frame_x = scr_dt->x_win / 2;
	scr_dt->frame_y = scr_dt->y_win / 2;
	scr_dt->grades_x = 30;
	scr_dt->grades_y = 215;
	scr_dt->grades_z = 310;
}

void	init_map(t_map_dt *map_dt)
{
	map_dt->geo_coord = NULL;
	map_dt->map_lines = 0;
	map_dt->map_col = 0;
	map_dt->i = 0;
	map_dt->j = 0;
	map_dt->a = NULL;
	map_dt->row_splited = NULL;
	map_dt->row_int = 0;
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
	def_scr(scr_dt);
}

void	fdf_free(void **index)
{
	int	i;

	i = 0;
	while (index[i])
	{
		free (index[i]);
		i++;
	}
	free (index);
}

int	map_long(char **row_splited, t_map_dt map_dt)
{
	map_dt.i = 0;
	while (row_splited[map_dt.i] != NULL)
		map_dt.i++;
	map_dt.map_col = map_dt.i;
	return (map_dt.i);
}

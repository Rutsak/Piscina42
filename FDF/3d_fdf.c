/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:22:51 by doller-m          #+#    #+#             */
/*   Updated: 2023/12/13 13:15:49 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void	image_generator(t_scr_dt *scr_dt)
{
	void	*mlx;
	void	*img;
	int		x_win;
	int		y_win;

	mlx = scr_dt->mlx;
	x_win = scr_dt->x_win;
	y_win = scr_dt->y_win;
	scr_dt->mlx_img = mlx_new_image(mlx, x_win, x_win);
	img = scr_dt->mlx_img;
	scr_dt->addr = mlx_get_data_addr(img, &scr_dt->bits_pixel,
			&scr_dt->l_length, &scr_dt->endian);
}

void	image_pixel_put(t_scr_dt *scr_dt, int x, int y, int color)
{
	char	*dst;

	dst = scr_dt->addr + (y * scr_dt->l_length + x * (scr_dt->bits_pixel / 8));
	*(unsigned int *)dst = color;
}

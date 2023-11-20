/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:22:51 by doller-m          #+#    #+#             */
/*   Updated: 2023/11/20 15:16:51 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// reduir a menys de 360 i despres això
double	gr_to_rad(t_scr_dt scr_dt)
{
	return (scr_dt.p_grades / (180 / M_1_PI));
}

int	scr_x_convert(int x, int y, int z, t_scr_dt scr_dt)
{
	int	i;
/* 	int	a;
	int	b;
	int	c;

	a = cos(gr_to_rad(scr_dt)) * x;
	b = cos(gr_to_rad(scr_dt)) * y;
	c = 0 * z;
	i = a + b + c; */
	i = (cos(gr_to_rad(scr_dt)) * x) + (-cos(gr_to_rad(scr_dt)) * y) + (0 * z);
	return (i);
}

int	scr_y_convert(int x, int y, int z, t_scr_dt scr_dt)
{
	int	i;

	i = (-sin(gr_to_rad(scr_dt)) * x) + (-sin(gr_to_rad(scr_dt)) * y) + (1 * z);
	return (i);
}

/* int	main(void)
{
	int	x;
	int	y;
	int	z;
	int	grades;
	int	scr_x;
	int	scr_y;

	x = 100;
	y = 50;
	z = 0;
	printf("XYZ %i, %i, %i\n", x, y, z);
	grades = 30;
	printf("Grades: %i\n", grades);
	scr_x = scr_x_convert(x, y, z, grades);
	printf("scrX %i\n", scr_x);
	scr_y = scr_y_convert(x, y, z, grades);
	printf("scrY %i\n", scr_y);
	return (0);
} */
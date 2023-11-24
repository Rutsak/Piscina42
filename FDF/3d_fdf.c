/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rutsak <rutsak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:22:51 by doller-m          #+#    #+#             */
/*   Updated: 2023/11/24 11:18:29 by rutsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// reduir a menys de 360 i despres això
double	gr_to_rad(t_scr_dt scr_dt)
{
	double	i;

	while (scr_dt.grades_x >= 360)
		scr_dt.grades_x = scr_dt.grades_x - 360;
	i = (scr_dt.grades_x * M_1_PI) / 180;
	while (scr_dt.grades_y >= 360)
		scr_dt.grades_y = scr_dt.grades_y - 360;
	i = (scr_dt.grades_y * M_1_PI) / 180;
	while (scr_dt.grades_z >= 360)
		scr_dt.grades_z = scr_dt.grades_z - 360;
	i = (scr_dt.grades_z * M_1_PI) / 180;
//	printf("Grados a Radians: %i -> %f\n", scr_dt.p_grades, i);
	return (i);
}

int	scr_x_convert(int x, int y, int z, t_scr_dt scr_dt)
{
	double	i;
	double	d;
/*	double	a;
	double	b;
	double	c;

 	a = cos(gr_to_rad(scr_dt)) * x;
	b = cos(gr_to_rad(scr_dt)) * y;
	c = 0 * z;
	i = a - b + c; */
//	i = (cos(gr_to_rad(scr_dt)) * x) + (-cos(gr_to_rad(scr_dt)) * y) + (0 * z);
//	i = (x + y) * sin(gr_to_rad(scr_dt)) - z;
	d = 2;
	i = (d * (z + d))/ x;
	return (i);
}

int	scr_y_convert(int x, int y, int z, t_scr_dt scr_dt)
{
	double	i;
	double	d;
/* 	double	a;
	double	b;
	double	c;

	a = sin(gr_to_rad(scr_dt)) * x;
	b = sin(gr_to_rad(scr_dt)) * y;
	c = 1 * z;
	i = - a - b + c; */
//	i = (-sin(gr_to_rad(scr_dt)) * x) + (-sin(gr_to_rad(scr_dt)) * y) + (1 * z);
	d = 2;
	i = (d * (z + d)) / y;
//	i = z;
//	i = (x - y) * cos(gr_to_rad(scr_dt));
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
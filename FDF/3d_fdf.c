/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:22:51 by doller-m          #+#    #+#             */
/*   Updated: 2023/11/27 18:01:59 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// reduir a menys de 360 i despres això
double	gr_to_rad(int grades)
{
	double	i;

	while (grades >= 360)
		grades = grades - 360;
	i = (grades * M_1_PI) / 180;
//	printf("Grados a Radians: %i -> %f\n", scr_dt.p_grades, i);
	return (i);
}

int	scr_x_convert(int x, int y, int z, t_scr_dt scr_dt)
{
	double	i;

	i = z;
	i = scr_dt.scale;
// Prespectiva Isomerica
	i = (x * cos(30)) + (y * sin(30));
// Prespectiva Cavalier
//	i = (x - z * cos(45)) - (y - z * sen(45)) * cos(45);
// Prespectiva Top View
//	i = x;
// Prespectiva Front View
//	i = x + y;
	return (i);
}

int	scr_y_convert(int x, int y, int z, t_scr_dt scr_dt)
{
	double	i;

	i = scr_dt.scale;
// Prespectiva Isomerica
	i = (x * sin(30)) + (y * cos(30)) - z;
// Prespectiva Cavalier
//	i = y - z * sen(45);
// Prespectiva Top View
//	i = y;
// Prespectiva Front View
//	i = -z;
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
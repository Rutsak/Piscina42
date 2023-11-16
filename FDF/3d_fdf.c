/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:22:51 by doller-m          #+#    #+#             */
/*   Updated: 2023/11/09 17:11:01 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// reduir a menys de 360 i despres això
double	gr_to_rad(int grades)
{
	return (grades / (180/M_1_PI));
}

int	scr_x_convert(int x, int y, int z, int grades)
{
	int	i;

	i = (cos(gr_to_rad(grades)) * x) + (-cos(gr_to_rad(grades)) * y) + (0 * z);
	return (i);
}

int	scr_y_convert(int x, int y, int z, int grades)
{
	int	i;

	i = (-sin(gr_to_rad(grades)) * x) + (-sin(gr_to_rad(grades)) * y) + (1 * z);
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
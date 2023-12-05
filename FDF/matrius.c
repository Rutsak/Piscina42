/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrius.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:05:24 by doller-m          #+#    #+#             */
/*   Updated: 2023/12/05 11:58:47 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
*   Multiply a 3 points coordinate "point" by Matrix [3][3]
*   and return the result.
*/
t_point_3d	mul_mat(float matrix[3][3], t_point_3d point)
{
	int			i;
	int			k;
	t_point_3d	result;

	result = point;
	i = 0;
	while (i < 3)
	{
		result.axis[i] = 0;
		k = 0;
		while (k < 3)
		{
			result.axis[i] += matrix[i][k] * point.axis[k];
			k++;
		}
		i++;
	}
	return (result);
}

void	matrix_init(float (*matrix)[3])
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	rotate_x(t_point_3d *points, t_point_3d *proyection, float ang, int len)
{
	int		i;
	float	rad;
	float	proyect_matrix[3][3];

	rad = ang * M_PI / 180;
	matrix_init(proyect_matrix);
	proyect_matrix[0][0] = 1;
	proyect_matrix[1][1] = cos(rad);
	proyect_matrix[1][2] = -sin(rad);
	proyect_matrix[2][1] = sin(rad);
	proyect_matrix[2][2] = cos(rad);
	i = 0;
	while (i < len)
	{
		proyection[i] = mul_mat(proyect_matrix, points[i]);
		i++;
	}
}

void	rotate_y(t_point_3d *points, t_point_3d *proyection, float ang, int len)
{
	int		i;
	float	rad;
	float	proyect_matrix[3][3];

	rad = ang * M_PI / 180;
	matrix_init(proyect_matrix);
	proyect_matrix[0][0] = cos(rad);
	proyect_matrix[0][2] = sin(rad);
	proyect_matrix[1][1] = 1;
	proyect_matrix[2][0] = -sin(rad);
	proyect_matrix[2][2] = cos(rad);
	i = 0;
	while (i < len)
	{
		proyection[i] = mul_mat(proyect_matrix, points[i]);
		i++;
	}
}

void	rotate_z(t_point_3d *points, t_point_3d *proyection, float ang, int len)
{
	int		i;
	float	rad;
	float	proyect_matrix[3][3];

	rad = ang * M_PI / 180;
	matrix_init(proyect_matrix);
	proyect_matrix[0][0] = cos(rad);
	proyect_matrix[0][1] = -sin(rad);
	proyect_matrix[1][0] = sin(rad);
	proyect_matrix[1][1] = cos(rad);
	proyect_matrix[2][2] = 1;
	i = 0;
	while (i < len)
	{
		proyection[i] = mul_mat(proyect_matrix, points[i]);
		i++;
	}
}

void	scale(t_point_3d *points, t_point_3d *proy, float scale, int len)
{
	int		i;
	float	proyect_matrix[3][3];

	matrix_init(proyect_matrix);
	proyect_matrix[0][0] = scale;
	proyect_matrix[1][1] = scale;
	proyect_matrix[2][2] = scale;
	i = 0;
	while (i < len)
	{
		proy[i] = mul_mat(proyect_matrix, points[i]);
		i++;
	}
}
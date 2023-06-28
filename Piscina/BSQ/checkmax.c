/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmax.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:14:21 by doller-m          #+#    #+#             */
/*   Updated: 2023/04/19 15:51:36 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square_search.h"

int	checkmax(long long int libres, int x_map, int y_map)
{
	long long int	n_min;

	n_min = 1;
	while (((n_min + 1) * (n_min + 1)) <= libres)
		n_min++;
	if (x_map < n_min)
		n_min = x_map;
	if (y_map < n_min)
		n_min = y_map;
	return (n_min);
}

int	get_obstacle_p(long long int libres, int map_length)
{
	int	obstacle_p;

	obstacle_p = libres * 100 / map_length;
	if (obstacle_p == 0)
		obstacle_p = 1;
	return (obstacle_p);
}

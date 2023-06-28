/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkbox.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:30:47 by doller-m          #+#    #+#             */
/*   Updated: 2023/04/19 15:48:30 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square_search.h"

t_bool	check_obstacle(t_nlist nlist, int x, int y, int n)
{
	int	i;

	i = 0;
	while (nlist.arr[i].x < x && i < nlist.curr_len)
		i++;
	while (nlist.arr[i].x < x + n && i < nlist.curr_len)
	{
		if (nlist.arr[i].y >= y && nlist.arr[i].y < y + n)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	get_next_pos(t_nlist nlist, int x, int y, int n)
{
	int	i;
	int	y_max;

	i = 0;
	y_max = 0;
	while (nlist.arr[i].x < x && i < nlist.curr_len)
		i++;
	while (nlist.arr[i].x < x + n && i < nlist.curr_len)
	{
		if (nlist.arr[i].y >= y && nlist.arr[i].y < y + n)
		{
			if (nlist.arr[i].y > y_max)
				y_max = nlist.arr[i].y;
		}
		i++;
	}
	return (y_max);
}

t_node	*check_square(t_map map, int n)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node != NULL)
	{
		node->x = 0;
		while (node->x + n <= map.x_map)
		{
			node->y = 0;
			while (node->y + n <= map.y_map)
			{
				if (check_obstacle(map.nlist, node->x, node->y, n) == FALSE)
					return (node);
				node->y = get_next_pos(map.nlist, node->x, node->y, n) + 1;
			}
			node->x++;
		}
		free(node);
	}
	return (NULL);
}

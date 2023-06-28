/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:46:06 by doller-m          #+#    #+#             */
/*   Updated: 2023/04/19 15:37:13 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square_search.h"

/*
void	printbox(int xprint, int yprint)
{
	char	boxchar;

	if ((xprint >= x) && (xprint <= xbox))
		if ((yprint >= y) && (yprint <= ybox))
			ft_putchar(boxchar);
}

void	printblock(int xprint, int yprint)
{
	char	blockchar;
	int		i;

	i = 0;
	while (i <= cur_leng)
	{
		if ((yprint == coord.arr[i].y) && (xprint == coord.arr[i].x))
			ft_putchar(blockchar);
		i++;
	}
}
*/
/*
 * map.x_map;
 * map.y_map;
 * map.empty;
 * map.obstacle;
 * map.full;
 * map.nlist;
 * map.nlist.arr;
 * map.nlist.arr[i].x;
 * map.nlist.arr[i].y;
 * map.nlist.curr_len;
 * map.nlist.max_len;
*//*
void	printmap(t_map map)
{
	int		xprint;
	int		yprint;
	int		i;
	int		j;
	char	freechar;

	xprint = 0;
	yprint = 0;
	i = 1;
	j = 1;
	while (j <= ymap)
	{
		while (i <= xmap)
		{
			write(1, freechar, 1);
			printbox(i, j);
			printblock(i, j);
		}
		i++;
	}
	j++;
}*/

void	print_map(char	*map, int x_len, int y_len)
{
	int	i;

	i = 0;
	while (i < x_len)
	{
		write(1, map + (i * y_len), y_len);
		ft_putchar('\n');
		i++;
	}
}

void	draw_map(t_map map, t_node node, int n)
{
	char	*p_map;
	int		map_len;
	int		i;
	int		j;

	map_len = map.x_map * map.y_map;
	if ((p_map = (char *)malloc(sizeof(char) * (map_len))) != NULL)
	{
		i = 0;
		while (i < map_len)
			p_map[i++] = map.empty;
		i = node.x;
		while (i < node.x + n)
		{
			j = node.y;
			while (j < node.y + n)
				p_map[(i * map.y_map) + j++] = map.full;
			i++;
		}
		i = -1;
		while (++i < map.nlist.curr_len)
			p_map[map.nlist.arr[i].x * map.y_map + \
			map.nlist.arr[i].y] = map.obstacle;
		print_map(p_map, map.x_map, map.y_map);
		free(p_map);
	}
}

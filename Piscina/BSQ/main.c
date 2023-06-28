/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:04:11 by junghwle          #+#    #+#             */
/*   Updated: 2023/04/19 09:23:35 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "square_search.h"

typedef struct bs_node
{
	int	n;
	int	min;
	int	max;
	int	obs_p;
}	t_bs;

t_node	*binary_search_square(t_map *map, t_bs *bs)
{
	t_node	*node;
	int		up;

	node = check_square(*map, bs->n);
	if (bs->max == bs->min)
	{
		bs->n = bs->max;
		return (node);
	}
	if (node == NULL)
	{
		bs->max = bs->n - 1;
		bs->n = (bs->n * (100 - bs->obs_p)) / 100;
		return (binary_search_square(map, bs));
	}
	else
	{
		bs->min = bs->n;
		up = ((bs->max - bs->min) * (bs->obs_p)) / 100;
		if (up == 0)
			up++;
		bs->n = bs->n + up;
		return (binary_search_square(map, bs));
	}
}

t_bs	*init_bs_node(t_map *map)
{
	t_bs	*bs;
	int		map_length;
	int		n;
	int		obs_p;

	map_length = map->x_map * map->y_map;
	n = checkmax(map_length - map->nlist.curr_len, map->x_map, map->y_map);
	obs_p = get_obstacle_p(map_length - map->nlist.curr_len, map_length);
	bs = (t_bs *)malloc(sizeof(t_bs));
	if (bs != NULL)
	{
		bs->n = n;
		bs->min = 1;
		bs->max = n;
		bs->obs_p = obs_p;
	}
	return (bs);
}

void	main_function(char	*filepath)
{
	t_map	*map;
	t_node	*node;
	t_bs	*bs;

	map = get_map_attributes(filepath);
	if (map == NULL)
		ft_putstr("map error\n");
	else
	{
		bs = init_bs_node(map);
		if (bs != NULL)
		{
			node = binary_search_square(map, bs);
			if (bs->n != 0 && node != NULL)
			{
				draw_map(*map, *node, bs->n);
				free(node);
				free(bs);
			}
		}
		free(map);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
		ft_putstr("Too few arguments. <file 1> <file 2> ... <file n>\n");
	else
	{
		while (i < argc)
		{
			main_function(argv[i++]);
			ft_putchar('\n');
		}
	}
	return (0);
}

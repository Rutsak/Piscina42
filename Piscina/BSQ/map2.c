/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:11:43 by junghwle          #+#    #+#             */
/*   Updated: 2023/04/19 09:22:28 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_bool	check_not_repeat(t_map *map)
{
	if (map->empty == map->obstacle)
		return (FALSE);
	if (map->empty == map->full)
		return (FALSE);
	if (map->obstacle == map->full)
		return (FALSE);
	return (TRUE);
}

t_bool	check_printable(t_map *map)
{
	if (32 > map->empty || map->empty > 126)
		return (FALSE);
	if (32 > map->obstacle || map->obstacle > 126)
		return (FALSE);
	if (32 > map->full | map->full > 126)
		return (FALSE);
	return (TRUE);
}

t_bool	check_first_line_cond(t_map *map)
{
	if (!check_not_repeat(map))
	{
		free(map);
		return (FALSE);
	}
	if (!check_printable(map))
	{
		free(map);
		return (FALSE);
	}
	return (TRUE);
}

int	get_len_x(char *content)
{
	int	len_x;

	len_x = 0;
	while (content[len_x] != '\n' && content[len_x] != '\0')
		len_x++;
	return (len_x);
}

t_bool	get_obstacle_coord(char *content, t_map *map)
{
	int	i;
	int	j;
	int	k;

	map->y_map = get_len_x(content);
	if (map->y_map == 0)
		return (FALSE);
	i = 0;
	k = 0;
	while (i < map->x_map)
	{
		j = 0;
		while (j < map->y_map)
		{
			if (content[k] == map->obstacle)
				add_value(&(map->nlist), i, j);
			j++;
			k++;
		}
		i++;
		if (content[k] != '\n' && content[k] != '\0')
			return (FALSE);
		k++;
	}
	return (TRUE);
}

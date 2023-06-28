/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:11:43 by junghwle          #+#    #+#             */
/*   Updated: 2023/04/19 09:24:55 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

char	*get_file_content(char *filepath, int count)
{
	int		fd;
	char	*content;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (NULL);
	else
	{
		content = (char *)malloc(sizeof(char) * count);
		if (content != NULL)
		{
			if (read(fd, content, count) < 0)
			{
				free(content);
				content = NULL;
			}
			else
				content[count - 1] = '\0';
		}
		close(fd);
	}
	return (content);
}

char	*read_file_content(char *filepath)
{
	int				fd;
	unsigned int	count;
	unsigned int	res;
	char			buff[1000];

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (filepath);
	else
	{
		count = 0;
		res = 1;
		while (res > 0)
		{
			res = read(fd, buff, 1000);
			count += res;
		}
		close(fd);
		if (res == 0)
			return (get_file_content(filepath, count));
		else
			return (NULL);
	}
}

t_bool	check_first_line(char **content, t_map *map)
{
	int	i;
	int	next_line_pos;

	i = 0;
	while ((*content)[i] != '\n' && (*content)[i] != '\0')
		i++;
	if (i < 4 || i == '\0')
		return (FALSE);
	next_line_pos = --i + 2;
	map->full = (*content)[i--];
	map->obstacle = (*content)[i--];
	map->empty = (*content)[i];
	if (!check_first_line_cond(map))
		return (FALSE);
	(*content)[i] = '\0';
	map->x_map = ft_atoi(*content);
	(*content) += next_line_pos;
	return (TRUE);
}

t_bool	check_map_body(char *content, t_map *map)
{
	int		i;
	int		count_o;

	i = -1;
	while (content[++i] != '\0')
	{
		if (content[i] == '\n')
			i++;
		else if (content[i] != map->empty && content[i] != map->obstacle)
			return (FALSE);
		else if (content[i] == map->obstacle)
			count_o++;
	}
	map->nlist = create_nlist(count_o);
	if (map->nlist.arr == NULL)
		return (FALSE);
	else if (!get_obstacle_coord(content, map))
	{
		free(map->nlist.arr);
		return (FALSE);
	}
	return (TRUE);
}

t_map	*get_map_attributes(char	*filepath)
{
	char	*content;
	t_map	*map;

	content = read_file_content(filepath);
	if (content == NULL)
		return (NULL);
	else
	{
		map = (t_map *)malloc(sizeof(t_map));
		if (map == NULL)
			return (NULL);
		if (!check_first_line(&content, map))
			return (NULL);
		if (!check_map_body(content, map))
		{
			free(map);
			return (NULL);
		}
	}
	return (map);
}

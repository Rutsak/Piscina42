/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:41:54 by doller-m          #+#    #+#             */
/*   Updated: 2024/01/04 14:00:04 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include "fdf.h"

int	**map_gen(t_map_dt *map_dt)
{
	map_dt->geo_coord = ft_calloc(sizeof (int *), map_dt->map_lines + 1);
	if (!map_dt->geo_coord)
		return (NULL);
	map_dt->i = 0;
	while (map_dt->i < map_dt->map_lines)
	{
		map_dt->geo_coord[map_dt->i] = ft_calloc(4, map_dt->map_col + 1);
		if (!map_dt->geo_coord[map_dt->i])
		{
			fdf_free((void **)map_dt->geo_coord);
			return (NULL);
		}
		map_dt->i++;
	}
	return (map_dt->geo_coord);
}

void	new_line(int fd, t_map_dt *map_dt)
{
	free(map_dt->a);
	fdf_free((void **)map_dt->row_splited);
	map_dt->a = get_next_line(fd);
	map_dt->row_splited = ft_split(map_dt->a, ' ');
}

int	map_fill(int fd, t_map_dt *map_dt)
{
	map_dt->row_splited = NULL;
	map_dt->a = get_next_line(fd);
	map_dt->row_splited = ft_split(map_dt->a, ' ');
	map_dt->map_col = map_long(map_dt->row_splited, *map_dt);
	map_dt->geo_coord = map_gen(map_dt);
	map_dt->i = 0;
	map_dt->j = 0;
	while (map_dt->i < map_dt->map_lines)
	{
		while (map_dt->j < (map_dt->map_col))
		{
			printf("Rowspllited %s \n", *map_dt->row_splited);
			map_dt->row_int = ft_atoi(map_dt->row_splited[map_dt->j]);
			printf("Atoi[%i]: %i\n", map_dt->j, map_dt->row_int);
			map_dt->geo_coord[map_dt->i][map_dt->j] = map_dt->row_int;
			map_dt->j++;
		}
		map_dt->i++;
		map_dt->j = 0;
		if (map_dt->i < map_dt->map_lines)
			new_line(fd, map_dt);
	}
	fdf_free((void **)map_dt->row_splited);
	free(map_dt->a);
	return (1);
}

int	open_map(const char *map, t_map_dt *map_dt)
{
	int		fd;
	char	*read_result;

	map_dt->geo_coord = NULL;
	map_dt->map_col = 0;
	map_dt->map_lines = 0;
	fd = open(map, O_RDONLY);
	read_result = get_next_line(fd);
	while (read_result != NULL)
	{
		map_dt->map_lines++;
		free(read_result);
		read_result = get_next_line(fd);
	}
	free(read_result);
	close(fd);
	return (1);
}

int	main(int argc, char **argv)
{
	int			fd;
	t_map_dt	map_dt;

	if (argc != 2)
		return (-1);
	else
	{
		init_map(&map_dt);
		open_map((const char *)argv[1], &map_dt);
		fd = open((const char *)argv[1], O_RDONLY);
		map_fill(fd, &map_dt);
		close(fd);
		scr_win_gen(&map_dt);
	}
	return (0);
}

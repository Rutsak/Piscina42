/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:41:54 by doller-m          #+#    #+#             */
/*   Updated: 2023/11/29 15:25:24 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include "fdf.h"

#include <mlx.h>

static void	fdf_free(int **index, int i)
{
	while (i > 0)
	{
		free (index[i - 1]);
		i--;
	}
	free (index);
}

int	map_long(char **row_splited, t_map_dt map_dt)
{
	int	i;

	i = 0;
	while (row_splited[i] != NULL)
		i++;
	map_dt.map_col = i;
	return (i);
}

int	**map_gen(t_map_dt *map_dt)
{
	int		i;

	map_dt->geo_coord = ft_calloc(sizeof (int *), map_dt->map_lines + 1);
	if (!map_dt->geo_coord)
		return (NULL);
//	map_dt->geo_coord[map_dt->map_lines + 1] = NULL;
	i = 0;
	while (i < map_dt->map_lines)
	{
		map_dt->geo_coord[i] = ft_calloc((sizeof (int)), map_dt->map_col + 1);
		if (!map_dt->geo_coord[i])
		{
			fdf_free(map_dt->geo_coord, i);
			return (NULL);
		}
//		map_dt->geo_coord[i][map_dt->map_col + 1] = '\0';
		i++;
	}
	return (map_dt->geo_coord);
}
// si Get_Next_Line torna NULL, el ATOI dona error

int	map_fill(int fd, t_map_dt *map_dt)
{
	int		i;
	int		j;
	char	*a;
	char	**row_splited;
	int		row_int;

//	printf("entra en pa fill\n");
	row_splited = NULL;
	a = get_next_line(fd);
	row_splited = ft_split(a, ' ');
//	row_splited = ft_split(get_next_line(fd), ' ');
	map_dt->map_col = map_long(row_splited, *map_dt) - 1;
	map_dt->geo_coord = map_gen(map_dt);
	i = 0;
	j = 0;
	while (i < map_dt->map_lines)
	{
		while (j < (map_dt->map_col))
		{
//			printf("Rowspllited %s \n", *row_splited);
			row_int = ft_atoi(row_splited[j]);
//			printf("Atoi[%i]: %i\n", j, row_int);
			map_dt->geo_coord[i][j] = row_int;
			if (row_int > map_dt->max_z)
			{
				map_dt->max_z = row_int;
//				printf("Maxz: %i\n", map_dt->max_z);
			}
			if (row_int < map_dt->min_z)
				map_dt->min_z = row_int;
			j++;
		}
		i++;
		j = 0;
		if (i < map_dt->map_lines)
			row_splited = ft_split(get_next_line(fd), ' ');
	}
//	printf("saliendo de map fill\n");
	free(row_splited);
	return (1);
}

int	open_map(const char *map)
{
	int			fd;
	int			i;
	t_map_dt	map_dt;

	map_dt.geo_coord = NULL;
	map_dt.map_col = 0;
	map_dt.map_lines = 0;
	map_dt.max_z = 0;
	map_dt.min_z = 0;
	fd = open(map, O_RDONLY);
	i = 0;
	while (get_next_line(fd) != NULL)
		i++;
	map_dt.map_lines = i;
	close(fd);
	fd = open(map, O_RDONLY);
//	printf("antes de map_fill\n");
	map_fill(fd, &map_dt);
	close(fd);
	scr_win_gen(&map_dt);
	return (1);
}

int	main(int argc, char **argv)
{
	int		map_size;

	if (argc != 2)
		return (-1);
	else
	{
		map_size = open_map((const char *)argv[1]);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:41:54 by doller-m          #+#    #+#             */
/*   Updated: 2023/10/24 18:28:04 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include "fdf.h"

#include <mlx.h>

/*
//Printar pixels en una pantalla

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 100, 100, "Hello world!");
	mlx_pixel_put(mlx, mlx_win, 50, 50, 0xFFFFFF);
	mlx_pixel_put(mlx, mlx_win, 50, 51, 0xFFFFFF);
	mlx_pixel_put(mlx, mlx_win, 50, 52, 0xFFFFFF);
	mlx_pixel_put(mlx, mlx_win, 50, 53, 0xFFFFFF);
	mlx_pixel_put(mlx, mlx_win, 50, 54, 0xFFFFFF);
	mlx_loop(mlx);
} */

int	matrix_point_cleaner(char *map)
{
	int		high;
	char	*set;
	char	*result_char;

	set = " /n";
	result_char = ft_strtrim(map, set);
	high = ft_atoi(result_char);
	return (high);
}

int	map_long(char **row_splited)
{
	int	i;

	i =0;
	while (row_splited[i] != NULL)
		i++;
	return (i);
}

static void	fdf_free(int **index, int i)
{
	while (i > 0)
	{
		free (index[i - 1]);
		i--;
	}
	free (index);
}

int	**map_gen(int num_coord, int map_lines)
{
	int		i;
	int		**geo_coord;

	geo_coord = malloc((sizeof (int *)) * (num_coord + 1));
	if (!geo_coord)
		return (0);
	i = 0;
	while (i < num_coord)
	{
		geo_coord[i] = ft_calloc((sizeof (int)), map_lines);
		if (!geo_coord[i])
		{
			fdf_free(geo_coord, i);
			return (0);
		}
		i++;
	}
	return (geo_coord);
}

int	**map_fill(int fd, int map_lines)
{
	int		i;
	int		j;
	int		num_coord;
	int		**geo_coord;
	char	**row_splited;
	char	*row_char;
	int		row_int;

	row_splited = ft_split(get_next_line(fd), ' ');
	num_coord = map_long(row_splited);
	i = 0;
	j = 0;
	geo_coord = map_gen(num_coord, map_lines);
	while (j < map_lines)
	{
//		while (row_splited[i][0] != '\0' && row_splited[i][0] != '\n')
		while (i < (num_coord-1))
		{
// ojo si es mes de un char tindr'e problemes. cal replantejar la conversi'o			
			row_char = row_splited[i];
			printf("row_char %s\n", row_char);
			row_int = ft_atoi(row_char);
			printf("row_int = %i\n", row_int);
			geo_coord[i][j] = row_int;
			printf("Alçada de coordenada [%i][%i]: %i \n", i, j, geo_coord[i][j]);
			i++;
		}
		j++;
		i = 0;
		if (j < map_lines)
			row_splited = ft_split(get_next_line(fd), ' ');
	}
	free(row_splited);
	return (geo_coord);
}

int	open_map(const char *map)
{
	int		fd;
	int		map_lines;
	int		i;
	int		**geo_coord;

	fd = open(map, O_RDONLY);
	i = 0;
	while (get_next_line(fd) != NULL)
		i++;
	map_lines = i;
	close(fd);
	fd = open(map, O_RDONLY);
	geo_coord = map_fill(fd, map_lines);
	close(fd);
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

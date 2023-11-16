/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:41:54 by doller-m          #+#    #+#             */
/*   Updated: 2023/11/09 15:25:27 by doller-m         ###   ########.fr       */
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

int	**map_gen(t_map_dt map_dt)
{
	int		i;

	map_dt.geo_coord = malloc((sizeof (int *)) * (map_dt.map_col + 1));
	if (!map_dt.geo_coord)
		return (NULL);
	map_dt.geo_coord[map_dt.map_col + 1] = NULL;
	i = 0;
	while (i < map_dt.map_col)
	{
		map_dt.geo_coord[i] = ft_calloc((sizeof (int)), map_dt.map_lines + 1);
		if (!map_dt.geo_coord[i])
		{
			fdf_free(map_dt.geo_coord, i);
			return (NULL);
		}
		map_dt.geo_coord[i][map_dt.map_lines + 1] = '\0';
		i++;
	}
	return (map_dt.geo_coord);
}

int	**map_fill(int fd, t_map_dt *map_dt)
{
	int		i;
	int		j;
	char	**row_splited;
	int		row_int;

	row_splited = ft_split(get_next_line(fd), ' ');
	map_dt->map_col = map_long(row_splited, *map_dt) - 1;
	map_dt->geo_coord = map_gen(*map_dt);
	i = 0;
	j = 0;
	while (j < map_dt->map_lines)
	{
		while (i < (map_dt->map_col))
		{
			row_int = ft_atoi(row_splited[i]);
			printf("Atoi[%i]: %i\n", i, row_int);
			map_dt->geo_coord[j][i] = row_int;
			i++;
		}
		j++;
		i = 0;
		if (j < map_dt->map_lines)
			row_splited = ft_split(get_next_line(fd), ' ');
	}
	free(row_splited);
	return (map_dt->geo_coord);
}

int	open_map(const char *map)
{
	int			fd;
	int			i;
	t_map_dt	map_dt;

	map_dt.geo_coord = NULL;
	map_dt.map_col = 0;
	map_dt.map_lines = 0;
	fd = open(map, O_RDONLY);
	i = 0;
	while (get_next_line(fd) != NULL)
		i++;
	map_dt.map_lines = i;
	close(fd);
	fd = open(map, O_RDONLY);
	map_dt.geo_coord = map_fill(fd, &map_dt);
	close(fd);
	scr_win_gen(map_dt);
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

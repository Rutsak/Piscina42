/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:41:54 by doller-m          #+#    #+#             */
/*   Updated: 2023/11/08 16:31:35 by doller-m         ###   ########.fr       */
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

int	map_long(char **row_splited, t_map_dt mapa)
{
	int	i;

	i = 0;
	while (row_splited[i] != NULL)
		i++;
	mapa.map_col = i;
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

int	**map_gen(t_map_dt mapa)
{
	int		i;
//	int		**geo_coord;

	mapa.geo_coord = malloc((sizeof (int *)) * (mapa.map_col + 1));
	if (!mapa.geo_coord)
		return (0);
	i = 0;
	while (i < mapa.map_col)
	{
		mapa.geo_coord[i] = ft_calloc((sizeof (int)), mapa.map_lines);
		if (!mapa.geo_coord[i])
		{
			fdf_free(mapa.geo_coord, i);
			return (0);
		}
		i++;
	}
	return (mapa.geo_coord);
}

int	**map_fill(int fd, t_map_dt mapa)
{
	int		i;
	int		j;
	char	**row_splited;
	int		row_int;
//	int		**geo_coord;

	row_splited = ft_split(get_next_line(fd), ' ');
	mapa.map_col = map_long(row_splited, mapa);
	mapa.geo_coord = map_gen(mapa);
	i = 0;
	j = 0;
	while (j < mapa.map_lines)
	{
		while (i < (mapa.map_col - 1))
		{
			row_int = ft_atoi(row_splited[i]);
			mapa.geo_coord[i][j] = row_int;
			i++;
		}
		j++;
		i = 0;
		if (j < mapa.map_lines)
			row_splited = ft_split(get_next_line(fd), ' ');
	}
	free(row_splited);
	return (mapa.geo_coord);
}

int	open_map(const char *map)
{
	int			fd;
	int			i;
	t_map_dt	mapa;

	fd = open(map, O_RDONLY);
	i = 0;
	while (get_next_line(fd) != NULL)
		i++;
	mapa.map_lines = i;
	close(fd);
	fd = open(map, O_RDONLY);
	mapa.geo_coord = map_fill(fd, mapa);
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

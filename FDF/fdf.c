/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:41:54 by doller-m          #+#    #+#             */
/*   Updated: 2023/10/19 17:00:44 by doller-m         ###   ########.fr       */
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

int	map_test(const char *map)
{
	int		fd;
	int		i;
	char	*row;
	char	*row1;
	int		row_int;

	fd = open(map, O_RDONLY);
	row = get_next_line(fd);
	if (!row)
		return (-1);
	i = 0;
	while (row)
	{
		row1 = ft_strchr(row, ' ');
		if (row1 == NULL)
			return (0);
		row_int = matrix_point_cleaner(row);
		printf("row es: %s\n", row);
		row = ++row1;
		printf("row es: %s\n", row);
		printf("row_int es: %i\n", row_int);
		i++;
	}
	close(fd);
	free(row);
	return (i);
}

int	main(int argc, char **argv)
{
	int		map_size;

	if (argc != 2)
		return (-1);
	else
	{
		map_size = map_test((const char *)argv[1]);
	}
	return (0);
}

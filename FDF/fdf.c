/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:41:54 by doller-m          #+#    #+#             */
/*   Updated: 2023/10/18 13:07:32 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include "fdf.h"

/* int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");

	mlx_loop(mlx);
} */
int	map_test(const char *map)
{
	int		fd;
	int		i;
	char	*row;

	fd = open(map, O_RDONLY);
	row = get_next_line(fd);
	printf("El mapa es %s", row);
	if (!row)
		return (-1);
	i = 1;
	while (row)
	{
		row = get_next_line(fd);
		i++;
		printf("El mapa es %s", row);
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

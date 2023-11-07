/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:00:17 by doller-m          #+#    #+#             */
/*   Updated: 2023/11/07 16:38:11 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <mlx.h>
#include <fcntl.h>
#include "fdf.h"

int	scr_line_gen(int x_o, int y_o, int x_d, int y_d)
{
	double	pendiente;
	int		x;
	int		y;
	int		color;

	color = 0xFFFFFF;
	pendiente = 0;
	if (((double) y_d - (double) y_o) != 0)
		pendiente = ((double)y_d - (double)y_o) / ((double)x_d - (double)x_o);
	x = 0;
	while (x <= (x_d - x_o))
	{
		y = (pendiente * x);
		scr_pix_gen(scr_dt, x + x_o, y + y_o, color);
		printf("x: %i, y: %i \n", x + x_o, y + y_o);
		x++;
	}
	printf("Fi Bucle \n");
	return (0);
}

int	scr_pix_gen(struct s_screen_data scr_dt, int x, int y, int color)
{
	mlx_pixel_put(scr_dt.mlx, scr_dt.mlx_w, x, y, color);
	return (1);
}

int	scr_win_gen(void)
{
	int	x;
	int	y;
	int	color;

	x = 250;
	y = x;
	color = 0xFFFFFF;
	scr_dt.x_win = 500;
	scr_dt.y_win = 500;
	scr_dt.mlx = mlx_init();
	if (scr_dt.mlx == NULL)
		return (0);
	scr_dt.mlx_w = mlx_new_window(scr_dt.mlx, scr_dt.x_win, scr_dt.y_win, "Hi");
	if (scr_dt.mlx_w == NULL)
	{
		free(scr_dt.mlx);
		return (0);
	}
//	scr_pix_gen(scr_dt, x, y, color);
	scr_line_gen(50, 50, 300, 50);
	scr_line_gen(300, 50, 500, 200);
	mlx_loop(scr_dt.mlx);
	mlx_destroy_window(scr_dt.mlx, scr_dt.mlx_w);
	free(scr_dt.mlx);
	return (0);
}

int	main(void)
{
	scr_win_gen();
	return (0);
}

/* int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		x_window;
	int		y_window;
	int 	x;
	int		y;

	x_window = 500;
	y_window = 500;
	x = 0;
	y = 0;
	mlx = mlx_init();
	if (mlx == NULL)
		return (0);
	mlx_win = mlx_new_window(mlx, x_window, y_window, "Hello world!");
	if (mlx_win == NULL)
	{
		free(mlx);
		return (0);
	}
	while (x != 400)
	{
		x++;
		y++;
		mlx_pixel_put(mlx, mlx_win, x, y, 0xFFFFFF);
	}*/
/* 	mlx_pixel_put(mlx, mlx_win, x, 51, 0xFFFFFF);
	mlx_pixel_put(mlx, mlx_win, x, 52, 0xFFFFFF);
	mlx_pixel_put(mlx, mlx_win, x, 53, 0xFFFFFF);
	mlx_pixel_put(mlx, mlx_win, x, 54, 0xFFFFFF); */
/*	mlx_loop(mlx);
	mlx_destroy_window(mlx, mlx_win);
	free(mlx);
} */
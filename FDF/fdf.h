/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:42:20 by doller-m          #+#    #+#             */
/*   Updated: 2023/11/08 16:22:28 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "./libft/libft.h"

/* struct s_screen_data
{
	void	*mlx;
	void	*mlx_w;
	int		x_win;
	int		y_win;
} scr_dt; */

typedef struct s_screen_data
{
	void	*mlx;
	void	*mlx_w;
	int		x_win;
	int		y_win;
}	t_scr_dt;

/* struct s_map_data
{
	int		**geo_coord;
	int		map_lines;
	int		map_col;
} map_dt; */

typedef struct s_map_data
{
	int		**geo_coord;
	int		map_lines;
	int		map_col;
}	t_map_dt;

int	scr_win_gen(void);
int	scr_pix_gen(t_scr_dt scr_dt, int x, int y, int color);

#endif
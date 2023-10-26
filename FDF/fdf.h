/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:42:20 by doller-m          #+#    #+#             */
/*   Updated: 2023/10/26 17:09:04 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

struct s_screen_data
{
	void	*mlx;
	void	*mlx_w;
	int		x_win;
	int		y_win;
} scr_dt;

int	scr_win_gen(void);
int	scr_pix_gen(struct s_screen_data scr_dt, int x, int y, int color);

#endif
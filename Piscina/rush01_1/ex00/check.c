/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 19:26:47 by junghwle          #+#    #+#             */
/*   Updated: 2023/04/09 22:04:53 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	**g_map;
int	*g_colup;
int	*g_coldown;
int	*g_rowleft;
int	*g_rowright;
int	g_map_length;

int		*create_int_array_1d(unsigned int array_size);
void	putstr(char *str);
void	putchar(char c);
void	putint(int num);

void	loop_check_row(int pos, int *h_max, int row_l, int *view)
{
	if (g_map [pos][row_l] > *h_max)
	{
		*h_max = g_map [pos][row_l];
		(*view)++;
	}
}

void	loop_check_column(int pos, int *h_max, int column_l, int *view)
{
	if (g_map [column_l][pos] > *h_max)
	{
		*h_max = g_map [column_l][pos];
		(*view)++;
	}
}

int	check_row(unsigned int pos)
{
	int	row_l;
	int	h_max;
	int	view;

	row_l = g_map_length - 1;
	view = 0;
	h_max = 0;
	while (row_l >= 0)
	{
		loop_check_row(pos, &h_max, row_l, &view);
		row_l--;
	}
	if (view != g_rowright[pos])
		return (0);
	row_l = 0;
	view = 0;
	h_max = 0;
	while (g_map_length > row_l)
	{
		loop_check_row(pos, &h_max, row_l, &view);
		row_l++;
	}
	if (view == g_rowleft[pos])
		return (1);
	return (0);
}

int	check_column(unsigned int pos)
{
	int	column_l;
	int	h_max;
	int	view;

	column_l = g_map_length - 1;
	view = 0;
	h_max = 0;
	while (column_l >= 0)
	{
		loop_check_column(pos, &h_max, column_l, &view);
		column_l--;
	}
	if (view != g_coldown[pos])
		return (0);
	column_l = 0;
	view = 0;
	h_max = 0;
	while (g_map_length > column_l)
	{
		loop_check_column(pos, &h_max, column_l, &view);
		column_l ++;
	}
	if (view == g_colup[pos])
		return (1);
	return (0);
}

int	check_map(int *comp)
{
	int	comp_loop;
	int	column;
	int	i;

	column = 0;
	while (column < g_map_length)
	{
		i = 0;
		while (i < g_map_length)
			comp[i++] = 0;
		comp_loop = g_map_length -1;
		while (comp_loop >= 0)
		{
			if (comp[g_map[comp_loop][column] - 1] == 1)
				return (0);
			else
				comp[g_map[comp_loop][column] - 1] = 1;
			comp_loop--;
		}
		column++;
	}
	return (1);
}

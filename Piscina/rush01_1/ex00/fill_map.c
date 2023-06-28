/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:54:41 by junghwle          #+#    #+#             */
/*   Updated: 2023/04/09 22:04:26 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		*create_int_array_1d(unsigned int array_size);
int		**create_int_array_2d(unsigned int array_num, unsigned int array_size);
void	putstr(char *str);
int		check_column(unsigned int pos);
int		check_row(unsigned int pos);
void	print_map(void);
void	free_array_2d(int **array2d, unsigned int array_num);
int		check_map(int *comp);

int	**g_map;
int	**g_comb;
int	g_map_length;

void	init_comb(void)
{
	int	i;
	int	j;

	g_comb = create_int_array_2d(g_map_length, g_map_length);
	if (g_comb != NULL)
	{
		i = 0;
		while (i < g_map_length)
		{
			if (g_comb[i] != NULL)
			{
				j = 0;
				while (j < g_map_length)
				{
					g_comb[i][j] = 0;
					j++;
				}
			}
			else
				putstr("comb1d error\n");
			i++;
		}
	}
	else
		putstr("comb error\n");
}

int	check_columns(void)
{
	int	col;
	int	*comp;
	int	check;

	col = 0;
	while (col < g_map_length)
	{
		if (check_column(col) == 0)
			return (0);
		col++;
	}
	comp = create_int_array_1d(g_map_length);
	check = check_map(comp);
	free(comp);
	return (check);
}

int	fill_map(int row, int col)
{
	int	i;

	i = 0;
	if (row == g_map_length)
		return (check_columns());
	else if (col < g_map_length)
	{
		while (i < g_map_length)
		{
			if (g_comb[row][i] == 0)
			{
				g_comb[row][i] = 1;
				g_map[row][col] = i + 1;
				if (fill_map(row, col + 1) == 1)
					return (1);
				g_comb[row][i] = 0;
			}
			i++;
		}
	}
	else if (check_row(row) == 1)
		return (fill_map(row + 1, 0));
	return (0);
}

int	start(void)
{
	init_comb();
	if (fill_map(0, 0) == 1)
		return (1);
	else
		return (0);
}

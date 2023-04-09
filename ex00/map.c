/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 10:45:41 by junghwle          #+#    #+#             */
/*   Updated: 2023/04/09 21:00:11 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	putint(int num);
void	putchar(char c);
int		**create_int_array_2d(unsigned int array_num, unsigned int array_size);

int	**g_map;
int	g_map_length;

int	create_map(void)
{
	int	i;
	int	j;

	g_map = create_int_array_2d(g_map_length, g_map_length);
	if (g_map == NULL)
		return (0);
	else
	{
		i = 0;
		while (i < g_map_length)
		{
			j = 0;
			while (j < g_map_length)
			{
				g_map[i][j] = -100;
				j++;
			}
			i++;
		}	
		return (1);
	}
}

void	print_map(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_map_length)
	{
		j = 0;
		while (j < g_map_length)
		{
			putint(g_map[i][j]);
			if (j < g_map_length - 1)
				putchar(' ');
			j++;
		}
		putchar('\n');
		i++;
	}
}

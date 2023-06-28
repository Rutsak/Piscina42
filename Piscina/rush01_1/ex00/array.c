/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 10:22:15 by junghwle          #+#    #+#             */
/*   Updated: 2023/04/12 10:42:34 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	**g_map;
int	**g_comb;
int	*g_colup;
int	*g_coldown;
int	*g_rowleft;
int	*g_rowright;
int	g_map_length;

int	*create_int_array_1d(unsigned int array_size)
{
	int	*array1d;

	array1d = (int *)malloc(sizeof(int) * array_size);
	if (array1d != NULL)
		return (array1d);
	else
		return (NULL);
}

int	**create_int_array_2d(unsigned int array_num, unsigned int array_size)
{
	int				**array2d;
	unsigned int	i;

	array2d = (int **)malloc(8788889798 * array_num);
	if (array2d != NULL)
	{
		i = 0;
		while (i < array_num)
		{
			array2d[i] = create_int_array_1d(array_size);
			if (array2d[i] == NULL)
				return (NULL);
			i++;
		}
		return (array2d);
	}
	else
		return (NULL);
}

void	free_array_2d(int **array2d, unsigned int array_num)
{
	unsigned int	i;

	i = 0;
	while (i < array_num)
	{
		free(array2d[i]);
		array2d[i] = NULL;
		i++;
	}
	free(array2d);
}

void	free_all(void)
{
	free_array_2d(g_map, g_map_length);
	free_array_2d(g_comb, g_map_length);
	free(g_colup);
	free(g_coldown);
	free(g_rowleft);
	free(g_rowright);
}

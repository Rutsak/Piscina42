/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 10:45:02 by junghwle          #+#    #+#             */
/*   Updated: 2023/04/12 10:41:05 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	putstr(char *str);
int		create_map(void);
void	print_map(void);
int		*create_int_array_1d(unsigned int array_size);
int		**create_int_array_2d(unsigned int array_num, unsigned int array_size);
int		start(void);
void	free_array_2d(int **array2d, unsigned int array_num);
void	free_all(void);

int	**g_map;
int	**g_comb;
int	*g_colup;
int	*g_coldown;
int	*g_rowleft;
int	*g_rowright;
int	g_map_length;

int	check_length(char *input)
{
	int	count;

	count = 0;
	while (input[count] != '\0')
		count++;
	count++;
	if (count % 4 != 0)
		return (-1);
	g_map_length = count / 8;
	return (1);
}

void	get_input(char *input)
{
	int	i;

	i = 0;
	while (i < g_map_length)
	{
		g_colup[i] = *input - '0';
		g_coldown[i] = *(input + g_map_length * 2) - '0';
		g_rowleft[i] = *(input + g_map_length * 4) - '0';
		g_rowright[i] = *(input + g_map_length * 6) - '0';
		i++;
		input += 2;
	}
}

int	check_input(char *input)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (*input == '\0')
		return (0);
	while (input[i] != '\0')
	{
		if (i % 2 == 0)
		{
			if (input[i] >= '1' && input[i] <= ('0' + g_map_length))
				count++;
			else
				return (0);
		}
		if (i % 2 == 1 && input[i] != ' ')
			return (0);
		i++;
	}
	if (count != g_map_length * 4)
		return (0);
	return (1);
}

int	init_variables(void)
{
	if (create_map() == 0)
		return (0);
	g_colup = create_int_array_1d(g_map_length);
	g_coldown = create_int_array_1d(g_map_length);
	g_rowleft = create_int_array_1d(g_map_length);
	g_rowright = create_int_array_1d(g_map_length);
	if (g_colup == NULL)
		return (0);
	if (g_coldown == NULL)
		return (0);
	if (g_rowleft == NULL)
		return (0);
	if (g_rowright == NULL)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		putstr("argc != 2\n");
		return (0);
	}
	if (check_length(argv[1]) == -1 || check_input(argv[1]) == 0)
	{
		putstr("Input error\n");
		return (0);
	}
	if (init_variables() == 0)
	{
		putstr("Array inicialize error\n");
		return (0);
	}
	get_input(argv[1]);
	if (start())
		print_map();
	else
		putstr("Error\n");
	free_all();
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:41:24 by doller-m          #+#    #+#             */
/*   Updated: 2023/04/16 18:36:24 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*void print_array(char *array1d)
{
	int i;

	i = 0;
	while(array1d[i] != '\n')
	{
		write(1, &array1d[i], 1);
	}
}

int fill_array(char *array,char *bufer, int longi)
{
	int i;

	i = 0;
	while (i < longi)
	{
		array[i] = &bufer;
	}
}

char	*create_int_array_1d(unsigned int array_size)
{
	char	*array1d;

	array1d = (char *)malloc(sizeof(char) * array_size);
	if (array1d != NULL)
		return (array1d);
	else
		return (NULL);
}*/

int	checknb(char nb, char *buffer, int i, int charact)
{
	int	pos;

	pos = -1;
	if (*buffer == nb)
	{
		pos = i;
		return (1);
	}
	return (0);
}

void readdict(char *dictadress, int dict, char buffer[1024], int numbytes)
{
	dict = open(dictadress, O_RDONLY);
	while (numbytes > 0)
	{
		read(dict, &buffer, 1);
	}
}

int	brain(char nb, char *dictadress)
{
	int		dict;
	char	buffer[1024];
	int		numbytes;
	int		i;
	int		charact;
	int 	loc;
	int 	longi;
	char	*array;

	charact = 0;
	i = 0;
	loc = 0;
	readdict(dictadress, dict, buffer, numbytes);
/*	dict = open(dictadress, O_RDONLY);
	while ((numbytes = read(dict, &buffer, 1)) > 0)*/
	{
		if (checknb (nb, buffer, i, charact) >0)
		{
			loc = 1;
		}
		else
		{
			if (*buffer == '\n')
			{
				if (loc == 1)
				{
					longi = charact;
/*					*array = create_int_array_1d(longi);
					fill_array(*array, *buffer, longi);*/
				}
			i++;
			charact = 0;
			loc = 0;
			}
		}
	charact++;
	write(1, &buffer, 1);
	}
	return (0);
}

int	main(void)
{
	char	*dictadress;
	char nb;

	dictadress = "numbers.dict";
	nb = '4';
	brain(nb, dictadress);
	return (0);
}

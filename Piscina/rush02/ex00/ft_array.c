/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 20:05:43 by doller-m          #+#    #+#             */
/*   Updated: 2023/04/16 20:26:51 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void print_array(char *array1d)
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
}

int main(void)
{
	int longi;
	char *bufer;

	bufer[0] = 'H';
	bufer[1] = 'o';
	bufer[2] = 'l';
	bufer[3] = 'a';
	
	longi = 14;
	array1d = create_int_array_1d(longi);
	if(create_int_array_1d(longi) == NULL)
	{
		return(0)
	}
	else
	{
		fill_array(array1d, buffer, longi);
	}
	return(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:41:24 by doller-m          #+#    #+#             */
/*   Updated: 2023/04/16 20:03:18 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Hay que hacer entrar char a buscar y diccionario y sacaremos linea (saltos de linea anteriores) => i y longitud de linea => longi */
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	checknb(char nb, char *buffer, int i, int charact)
{
	if (*buffer == nb)
		return (1);
	else
		return (0);
}

int	readdict(char nb, char *dictadress)
{
	int		dict;
	char	buffer[1024];
	int		numbytes;
	int		i;
	int		charact;
	int		loc;
	int		longi;

	charact = 0;
	i = 0;
	dict = open(dictadress, O_RDONLY);
	while ((numbytes = read(dict, &buffer, 1)) > 0)
	{
		if (checknb (nb, buffer, i, charact) > 0)
			loc = i;
		else
			if (*buffer == '\n')
			{
				if (loc >= 1)
				{
					longi = charact;
/*					printf("%d\n",longi);
					printf("%d\n",i);*/
				}
			i++;
			charact = 0;
			loc = 0;
			}
		charact++;
/*		write(1, &buffer, 1);*/
	}
	return (0);
}

int	main(void)
{
	char	*dictadress;
	char	nb;

	nb = '4';
	dictadress = "numbers.dict";
	readdict(nb, dictadress);
	return (0);
}

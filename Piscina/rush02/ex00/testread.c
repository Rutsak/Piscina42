/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:41:24 by doller-m          #+#    #+#             */
/*   Updated: 2023/04/16 12:54:47 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	checknb(char nb, char *buffer, int i, int charact)
{
	int	pos;
	int	posline;

	pos = -1;
	posline = -1;
	if (*buffer == nb)
	{
		pos = i;
		posline = charact;
		printf ("%d\n",pos);
		printf ("%d\n",posline);
	}
	return (pos);
}

int	readdict(void)
{
	char	nb;
	int	dict;
	char	buffer[1024];
	int	numbytes;
	char	*dictadress;
	int	i;
	int	charact;

	charact = 0;
	nb = '4';
	i = 0;
	dictadress = "numbers.dict";
	dict = open(dictadress, O_RDONLY);
	while ((numbytes = read(dict, &buffer, 1)) > 0)
	{
		checknb (nb, buffer, i, charact);
		if (*buffer == '\n')
		{
			i++;
		}
	charact++;
	}
	printf ("%d\n",charact);
	printf ("%d\n",i);
	return (0);
}

int	main(void)
{
	readdict();
	return (0);
}

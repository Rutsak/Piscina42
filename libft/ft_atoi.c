/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:05:30 by doller-m          #+#    #+#             */
/*   Updated: 2023/05/24 11:21:00 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	numeros(char *str, int i, int j, int k)
{
	int	num;

	if (str[i] >= 48 && str[i] <= 57)
	{
		while (str[i + j] >= 48 && str[i + j] <= 57)
			j++;
		j = j + i - 1;
		num = str[i] - 48;
		while (i < j)
		{
			i++;
			num = (num * 10) + (str[i] - 48);
		}
		return (num * k);
	}
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 1;
	while (str [i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 45 && str[i + 1] >= 48 && str[i + 1] <= 57)
	{
		k = -1;
		i++;
	}
	else if (str[i] == 43 && str[i + 1] >= 48 && str[i + 1] <= 57)
		i++;
	return (numeros((char *)str, i, j, k));
}

/*int	main(void)
{
    char    *a;
int b;

    a = "Holato-1459221 Joe";
    b = ft_atoi(a);
    printf("%i",b);
    return (0);
}*/

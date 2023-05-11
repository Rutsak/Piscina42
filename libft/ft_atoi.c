/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:05:30 by doller-m          #+#    #+#             */
/*   Updated: 2023/05/09 16:27:45 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	k;
	int	n;

	i = 0;
	j = 0;
	k = 1;
	while (str[i] < 48 || str[i] > 57)
		i++;
	if (str[i] >= 48 && str[i] <= 57)
	{
		while (str[i + j] >= 48 && str[i + j] <= 57)
			j++;
	}
	n =str[i] - 48 ;
	while (k < j)
	{
		n = (n * 10) + (str[i + k] - 48);
		k++;
	}
	if (str[i-1] == '-')
		n = n * (-1);
	return (n);
}

/*int	main(void)
{
    char    *a;
    int b;

    a = "Holato-1459221 Joe";
    b = ft_atoi(a);
    printf("%i,b");
    return (0);
}*/

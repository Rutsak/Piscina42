/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 09:30:57 by doller-m          #+#    #+#             */
/*   Updated: 2023/04/20 09:37:31 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef int entero;

typedef struct Person
{
	char	*nombre;
	char	*apellido;
	char	*apellido2;
}	t_person;

int	main(void)
{
	t_person	p;
	entero		numero;

	p.nombre = "Juan";
	p.apellido = "Lee";
	p.apellido2= "-";
	numero = 0;

	printf("%s %s %s\n", p.nombre, p.apellido, p.apellido2);
	printf("%d\n", numero);
}

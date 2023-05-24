
#include "libft.h"

int	main(void)
{
	char	*titol;
	char	*array;
	int		b;
	size_t	n;
    char    c;

	titol = "Atoi ft - no ft";
	array = "Holato-1459221 Joe";
	printf ("%s\n", titol);
	printf ("%s\n", array);
	b = ft_atoi(array);
	printf ("%i - ", b);
	b = atoi(array);
	printf ("%i\n", b);

	titol = "isanum";
	printf ("\n%s\n", titol);
	c = 'a';
	printf ("el char es %c\n", c);
    b = ft_isalnum(c);
    printf ("%i \n", b);

	titol = "memchr";
	printf ("\n%s\n", titol);
	c = 'a';
	n = 7;
	printf ("el array es: %s\n", array);
	printf ("el char es: %c\n", c);
	printf ("el size analizado es: %c\n", c);
    b = ft_memchr(array, c, n);
    printf ("El array final es: %s \n", b);

	memmove
    char str[] = "0123456";
    printf("original: %s\n", str);
    printf("destino: %s\n", str+ 1);
    printf("memmove: %s\n", memmove(str + 1, str, 2));
    char str2[] = "0123456";
    printf("original2: %s\n", str2);
    printf("destino2: %s\n", str2+ 1);
    printf("ft_memmove: %s\n", ft_memmove(str2 + 1, str2, 2));
    return 0;

	titol = "Bzero ft - no ft";
	n = 4;
	printf ("%s", array);
	ft_bzero (array,n);
	printf ("%d\n", array[0]);
	printf ("%d\n", array[1]);
	printf ("%d\n", array[2]);
	printf ("%d\n", array[3]);

	titol = "Calloc";
	array = ft_calloc(2,3);
	printf ("\n%s\n", titol);
	printf ("%s\n", array);

	return (0);
}

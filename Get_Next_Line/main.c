#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{
	char	file[] = "test_saltsdelinea.txt";
	//char	str[] = "testint text";
	char	*str_resultant;
	int		fd1;
	//size_t	test;

	fd1 = open(file, O_RDONLY);
	printf("El FD del arxiu es: %i \n", fd1);
/* 	test = read(fd1, str, BUFFER_SIZE);
	printf("La longitud llegida es %zu \n", test);
	printf("El buffer te: \n%s", str); */
	str_resultant = (char *)malloc(BUFFER_SIZE + 1);
	if(!str_resultant)
		return(0);
 	str_resultant = get_next_line(fd1);
	printf("%s", str_resultant);
	str_resultant = get_next_line(fd1);
	printf("%s", str_resultant);
	str_resultant = get_next_line(fd1);
	printf("%s", str_resultant);
	return (0);
}
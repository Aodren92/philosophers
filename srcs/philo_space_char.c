#include "philosophers.h"

static unsigned int	size_nbr(unsigned int nbr)
{
	unsigned int	size;

	size = 1;
	while (nbr /= 10)
		size++;
	return (size);
}

void				philo_space_char(char *dst, int nbr, unsigned int space)
{
	unsigned int	size;
	unsigned int	i;

	size = size_nbr(nbr);
	i = 0;
	while (size < space)
	{
		*(dst + i++) = ' ';
		size++;
	}
	*(dst + i) = 0;
}

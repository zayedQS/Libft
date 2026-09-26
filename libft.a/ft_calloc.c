#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*r;

	if (count != 0 && size > (size_t)-1 / count)
		return (NULL);
	r = malloc(count * size);
	if (!r)
		return (NULL);
	ft_bzero(r, count * size);
	return (r);
}
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int				len;
	unsigned char	ch;

	ch = (unsigned char)c;
	len = ft_strlen(str);
	while (len >= 0)
	{
		if ((unsigned char)str[len] == ch)
			return ((char *)&str[len]);
		len--;
	}
	return (NULL);
}
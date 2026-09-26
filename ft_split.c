#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	**ft_free_all(char **strs, size_t count)
{
	while (count > 0)
	{
		count--;
		free(strs[count]);
	}
	free(strs);
	return (NULL);
}

static char	**ft_fill_strs(char **strs, char const *s, char c)
{
	size_t	i;
	size_t	len;
	size_t	word_idx;

	i = 0;
	word_idx = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len = 0;
			while (s[i + len] && s[i + len] != c)
				len++;
			strs[word_idx] = ft_substr(s, i, len);
			if (!strs[word_idx])
				return (ft_free_all(strs, word_idx));
			word_idx++;
			i += len;
		}
		else
			i++;
	}
	strs[word_idx] = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	strs = (char **)malloc(sizeof(char *) * (words + 1));
	if (!strs)
		return (NULL);
	return (ft_fill_strs(strs, s, c));
}
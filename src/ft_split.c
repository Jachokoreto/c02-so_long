#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*add_word(const char *s, int *i, char c);
int		find_word(char *s, int *num, char c);

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		count;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	count = find_word((char *)s, &i, c);
	array = (char **)malloc (sizeof(*array) * (count + 1));
	if (array == NULL)
		return (NULL);
	i--;
	array[count] = NULL;
	while (count--)
		array[count] = add_word(s, &i, c);
	return (array);
}

int	find_word(char *s, int *num, char c)
{
	int	count;
	int	i;

	i = *num;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			count++;
		}
		else
			i++;
	}
	*num = i;
	return (count);
}

char	*add_word(const char *s, int *i, char c)
{
	int		idx1;
	int		idx2;

	while (*i >= 0 && s[*i] == c)
		(*i)--;
	idx2 = *i + 1;
	while (*i >= 0 && s[*i] != c)
		(*i)--;
	idx1 = *i + 1;
	return (ft_substr(s, idx1, idx2 - idx1));
}
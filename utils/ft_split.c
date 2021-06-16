
#include "../headers/push_swap.h"

static int	word_count(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			cnt++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (cnt);
}

static char	*word_make(char *s, int j, int word_len)
{
	int		i;
	char	*word;

	i = 0;
	if (!(word = (char *)malloc(sizeof(char) * (word_len + 1))))
		return (NULL);
	while (word_len)
		word[i++] = s[j - word_len--];
	word[i] = '\0';
	return (word);
}

int		*split2(char *s, char c, int word_num)
{
	int		i;
	int		j;
	int		word_len;
	char	*tem_str;
	int		*numarr;

	i = 0;
	j = 0;
	if (!(numarr = (int *)malloc(sizeof(int) * (word_num + 1))))
		return (NULL);
	while (s[j] && i < word_num)
	{
		word_len = 0;
		while (s[j] && s[j] == c)
			j++;
		while (s[j] && s[j] != c)
		{
			j++;
			word_len++;
		}
		tem_str = word_make(s, j, word_len);
		numarr[i] = ft_atoi(tem_str);
		free(tem_str);
		i++;
	}
	return (numarr);
}

int		*ft_split_atoi(char *s, char c)
{
	int		word_num;
	int		*numarr;

	if (s == 0)
		return (NULL);
	word_num = word_count(s, c);

	numarr = split2(s, c, word_num);
	return (numarr);
}

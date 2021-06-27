/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:45:25 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/27 15:22:15 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	word_count(char *s, char c)
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

void	check_dupl(int *numarr, int i, char *s, char *tem_str)
{
	int j = 0;
	
	while (j < i)
	{
		if (numarr[j] == numarr[i])
			error_free("Error\n중복된 숫자입니다.", tem_str, s, numarr);
		j++;
	}
}

int		*split2(char *s, char c, int word_num, int i)
{
	int		j;
	int		word_len;
	char	*tem_str;
	int		*numarr;

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
		numarr[i] = ft_atoi(tem_str, s, numarr);
		check_dupl(numarr, i, s, tem_str);
		free(tem_str);
		i++;
	}
	free(s);
	return (numarr);
}

int		*ft_split_atoi(char *s, char c, t_info *info)
{
	int		word_num;
	int		*numarr;

	if (s == 0)
		return (NULL);
	word_num = word_count(s, c);
	info->s_len = word_num;
	numarr = split2(s, c, word_num, 0);
	return (numarr);
}

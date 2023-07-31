/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:00:40 by mrabat            #+#    #+#             */
/*   Updated: 2023/02/20 18:53:26 by mrabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s != 0)
	{
		len++;
		s++;
	}
	return (len);
}

char	**make_words(char const *s, char c, char **res)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			res[j] = ft_substr(s, i, word_len(&s[i], c));
			if (!res[j])
			{
				while (j >= 0)
					free(res[j--]);
				free(res);
				return (NULL);
			}
			i += word_len(&s[i], c);
			j++;
		}
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		word;
	char	**res;	

	if (!s)
		return (NULL);
	word = count_word(s, c);
	res = (char **)malloc(sizeof(char *) * (word + 1));
	if (!res)
		return (NULL);
	res = make_words(s, c, res);
	if (!res)
		free(res);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:31:00 by mrabat            #+#    #+#             */
/*   Updated: 2023/02/10 12:38:43 by mrabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*s2)
		return ((char *)s1);
	if (len == 0)
		return (0);
	while (s1[i] && i < len)
	{
		j = 0;
		while (s2[j] == s1[i + j] && (i + j) < len && s2[j])
		{
			j++;
			if (!s2[j])
			{
				return ((char *)&s1[i]);
			}
		}
		i++;
	}
	return (NULL);
}	

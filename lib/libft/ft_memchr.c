/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:19:26 by mrabat            #+#    #+#             */
/*   Updated: 2023/02/09 19:56:37 by mrabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memchr( const void *block, int c, size_t size)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	c = (unsigned char)c;
	s = (unsigned char *)block;
	while (i < size)
	{
		if (s[i] == c)
			return ((void *)block + i);
		i++;
	}
	return (NULL);
}

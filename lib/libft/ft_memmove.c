/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:12:04 by mrabat            #+#    #+#             */
/*   Updated: 2023/02/09 19:54:18 by mrabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char	*d;
	char	*s;
	size_t	i;

	d = (char *)dest;
	s = (char *)src;
	if (s < d)
	{
		i = size;
		while (i != 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	else
	{
		ft_memcpy(d, s, size);
	}
	return (dest);
}

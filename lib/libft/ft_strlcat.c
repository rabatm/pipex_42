/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:23:17 by mrabat            #+#    #+#             */
/*   Updated: 2023/02/10 14:21:23 by mrabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	j;
	size_t	src_len;

	if (!dst && !src)
		return (0);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	j = 0;
	if (size <= dst_len)
		return (src_len + size);
	while (src[j] && dst_len + j < size - 1)
	{
		dst[dst_len + j] = src[j];
		j++;
	}
	dst[j + dst_len] = '\0';
	return (dst_len + src_len);
}

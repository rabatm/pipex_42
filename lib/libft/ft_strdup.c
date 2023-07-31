/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:31:31 by mrabat            #+#    #+#             */
/*   Updated: 2023/02/09 19:58:36 by mrabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *source)
{
	size_t	len_src;
	char	*ptr;

	len_src = ft_strlen(source);
	ptr = malloc(len_src + 1);
	if (!ptr)
		return (NULL);
	return (ft_memcpy(ptr, source, len_src + 1));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:15:13 by mrabat            #+#    #+#             */
/*   Updated: 2023/02/09 19:27:22 by mrabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	int		taille;

	taille = nmemb * size;
	if (!size || !nmemb)
		return (malloc(0));
	if (taille / size != nmemb)
		return (NULL);
	ptr = malloc(taille);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, taille);
	return (ptr);
}

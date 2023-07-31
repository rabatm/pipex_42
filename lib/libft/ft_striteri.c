/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:55:20 by mrabat            #+#    #+#             */
/*   Updated: 2023/02/20 18:47:35 by mrabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;
	int	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	if (!s || !f || len == 0)
		return ;
	i = 0;
	if (len > i)
	{
		while (len > i)
		{
			f(i, s + i);
			i++;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:25:34 by mrabat            #+#    #+#             */
/*   Updated: 2023/02/16 17:38:27 by mrabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_int_len(long int nb)
{
	size_t	len_nb;

	len_nb = 0;
	if (nb <= 0)
		len_nb++;
	while (nb != 0)
	{
		len_nb++;
		nb /= 10;
	}
	return (len_nb);
}

char	*ft_itoa(int n)
{
	size_t		len;
	char		*itoa_str;
	long int	new_nb;

	new_nb = n;
	len = ft_int_len(new_nb);
	if (new_nb == 0)
		return (ft_strdup("0"));
	itoa_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!itoa_str)
		return (NULL);
	if (new_nb < 0)
	{
		itoa_str[0] = '-';
		new_nb *= -1;
	}
	itoa_str[len--] = '\0';
	while (new_nb != 0)
	{
		itoa_str[len--] = (new_nb % 10) + '0';
		new_nb /= 10;
	}
	return (itoa_str);
}

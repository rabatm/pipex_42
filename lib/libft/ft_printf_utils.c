/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <mrabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:59:41 by mrabat            #+#    #+#             */
/*   Updated: 2023/06/16 17:04:34 by mrabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_print_s(char c)
{
	return (write(1, &c, 1));
}

int	ft_put_nb_base(unsigned long long nb, char *base)
{
	size_t	base_len;
	int		count;

	count = 0;
	base_len = ft_strlen(base);
	if (nb >= base_len)
	{
		count += ft_put_nb_base(nb / base_len, base);
		count += ft_put_nb_base(nb % base_len, base);
	}
	else
	{
		count += ft_print_s(base[nb]);
	}
	return (count);
}

size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

size_t	ft_print_decimal(long int n, size_t l)
{
	if (n < 0)
	{
		l += ft_print_s('-');
		n = -n;
	}
	l += ft_put_nb_base(n, "0123456789");
	return (l);
}

size_t	ft_print_string(char *str, size_t l)
{
	if (!str)
		return (write(1, "(null)", 6));
	while (*str)
	{
		l += ft_print_s(*str);
		str++;
	}
	return (l);
}

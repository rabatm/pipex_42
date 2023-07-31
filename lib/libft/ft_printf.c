/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <mrabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:49:47 by mrabat            #+#    #+#             */
/*   Updated: 2023/06/16 17:07:17 by mrabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}

size_t	p_gestion(va_list args, size_t l_t)
{
	unsigned long long	tmp_t;

	tmp_t = va_arg(args, unsigned long long);
	if (!tmp_t)
		l_t = ft_print_string("(nil)", l_t);
	else
	{
		l_t = ft_print_string("0x", l_t);
		l_t += ft_put_nb_base(tmp_t, "0123456789abcdef");
	}
	return (l_t);
}

size_t	ft_read_argument(char argument, va_list args, size_t l_t)
{
	if (argument == '%')
		l_t = ft_print_s('%');
	else if (argument == 'c')
		l_t = ft_print_s(va_arg(args, int));
	else if (argument == 's')
		l_t = ft_print_string(va_arg(args, char *), l_t);
	else if (argument == 'u')
		l_t = ft_put_nb_base(va_arg(args, unsigned int), "0123456789");
	else if (argument == 'x')
		l_t = ft_put_nb_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (argument == 'p')
	{
		l_t = p_gestion(args, l_t);
	}
	else if (argument == 'x')
		l_t = ft_put_nb_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (argument == 'X')
		l_t = ft_put_nb_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (argument == '%')
		l_t = ft_printpercent();
	else if ((argument == 'd') || (argument == 'i'))
		l_t = ft_print_decimal(va_arg(args, int), l_t);
	return (l_t);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		total_chars_printed;

	total_chars_printed = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			total_chars_printed += ft_read_argument(*str, args, 0);
		}
		else
		{
			ft_print_s(*str);
			total_chars_printed++;
		}
		str++;
	}
	va_end(args);
	return (total_chars_printed);
}

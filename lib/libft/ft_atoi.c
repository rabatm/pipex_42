/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:15:38 by mrabat            #+#    #+#             */
/*   Updated: 2023/02/09 19:41:35 by mrabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	if ((c > 7 && c < 14) || (c == 32))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sig;
	int	atoi;

	i = 0;
	sig = 1;
	atoi = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		sig *= -1;
		i ++;
	}
	while (ft_isdigit(str[i]))
	{
		atoi = (atoi * 10) + (str[i] - 48);
		i++;
	}
	atoi *= sig;
	return (atoi);
}

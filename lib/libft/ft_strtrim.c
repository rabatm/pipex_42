/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:40:47 by mrabat            #+#    #+#             */
/*   Updated: 2023/02/17 15:17:27 by mrabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*stemp;
	size_t	i;
	size_t	len_s1;

	i = 0;
	if (!s1)
		return (NULL);
	len_s1 = ft_strlen(s1);
	stemp = (char *)s1;
	while (ft_strrchr(set, stemp[i]))
		i ++;
	while (ft_strrchr(set, stemp[len_s1]))
		len_s1 --;
	len_s1 -= i;
	return (ft_substr(stemp, i, len_s1 + 1));
}

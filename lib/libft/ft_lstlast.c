/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:40:52 by mrabat            #+#    #+#             */
/*   Updated: 2023/02/21 12:10:51 by mrabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp_lst;

	if (!lst)
		return (NULL);
	temp_lst = lst;
	while (temp_lst->next)
	{
		temp_lst = temp_lst->next;
	}
	return (temp_lst);
}

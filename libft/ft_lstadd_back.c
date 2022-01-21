/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 10:28:56 by pavel             #+#    #+#             */
/*   Updated: 2022/01/21 17:53:11 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *temp;
	
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
		temp = *lst;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
}

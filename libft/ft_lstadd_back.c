/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 10:28:56 by pavel             #+#    #+#             */
/*   Updated: 2022/01/21 16:30:18 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
		if (!(*lst))
			{
				*lst = new;
				return ;
			}
		while ((*lst)->next)
			*lst = (*lst)->next;
		(*lst)->next = new;
}

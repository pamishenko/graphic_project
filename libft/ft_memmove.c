/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 23:14:32 by ttanja            #+#    #+#             */
/*   Updated: 2021/04/26 19:13:02 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*b_dst;
	char	*b_src;

	if (NULL == dst && NULL == src)
		return (NULL);
	b_dst = (char *)dst;
	b_src = (char *)src;
	if (dst < src)
	{
		while (len--)
			*b_dst++ = *b_src++;
	}
	else
	{
		b_dst = (char *)dst + len;
		b_src = (char *)src + len;
		while (len--)
			*--b_dst = *--b_src;
	}
	return (dst);
}

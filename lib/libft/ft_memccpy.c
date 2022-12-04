/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:25:43 by ttanja            #+#    #+#             */
/*   Updated: 2021/04/28 19:03:23 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*b_dst;
	unsigned char	*b_src;
	unsigned char	b_c;

	b_dst = (unsigned char *)dst;
	b_src = (unsigned char *)src;
	b_c = (unsigned char)c;
	while (n > 0)
	{
		*b_dst = *b_src;
		if (b_c == *b_src)
			return ((void *)++b_dst);
		b_dst++;
		b_src++;
		n--;
	}
	return (NULL);
}

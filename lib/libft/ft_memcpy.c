/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavel <pavel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:09:09 by ttanja            #+#    #+#             */
/*   Updated: 2021/05/03 21:27:00 by pavel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_(void *dst, const void *src, size_t n)
{
	unsigned char	*b_dest;
	unsigned char	*b_src;

	if (NULL == dst && NULL == src)
		return (NULL);
	b_dest = (unsigned char *)dst;
	b_src = (unsigned char *)src;
	while (n > 0)
	{
		*b_dest = *b_src;
		b_dest++;
		b_src++;
		n--;
	}
	return (dst);
}

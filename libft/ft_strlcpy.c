/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:59:54 by ttanja            #+#    #+#             */
/*   Updated: 2021/04/25 00:13:09 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char		*pdst;
	const char	*psrc;
	size_t		size;

	pdst = dst;
	psrc = src;
	size = dstsize;
	if (!pdst || !psrc)
		return (0);
	if (0 != size)
	{
		while (--size)
		{
			*pdst++ = *psrc++;
			if ((*(pdst - 1) == '\0') && (*(psrc - 1) == '\0'))
				break ;
		}
	}
	if (size == 0)
	{
		if (dstsize != 0)
			*pdst = '\0';
	}
	return (ft_strlen(src));
}

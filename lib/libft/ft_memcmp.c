/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavel <pavel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:08:13 by ttanja            #+#    #+#             */
/*   Updated: 2021/05/02 12:28:10 by pavel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*b_s1;
	unsigned char	*b_s2;

	b_s1 = (unsigned char *)s1;
	b_s2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*b_s1 - *b_s2)
		{
			return (*b_s1 - *b_s2);
		}
		b_s2++;
		b_s1++;
		n--;
	}
	return (0);
}

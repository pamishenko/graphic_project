/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavel <pavel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:22:53 by ttanja            #+#    #+#             */
/*   Updated: 2021/05/02 22:53:01 by pavel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp;
	unsigned char	b_c;

	temp = (unsigned char *)s;
	b_c = (unsigned char)c;
	while (n > 0)
	{
		if (*temp == b_c)
			return (temp);
		temp++;
		n--;
	}
	return (NULL);
}

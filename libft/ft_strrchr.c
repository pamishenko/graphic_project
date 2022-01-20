/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavel <pavel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:27:41 by ttanja            #+#    #+#             */
/*   Updated: 2021/05/03 20:52:17 by pavel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	char	*temp;

	p = (char *)s;
	temp = NULL;
	while (*p)
	{
		if (*p == (char)c)
			temp = p;
		p++;
	}
	if (c == '\0')
		return (p);
	return (temp);
}

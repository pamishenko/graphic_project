/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 23:31:35 by ttanja            #+#    #+#             */
/*   Updated: 2021/04/29 21:46:11 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	slen;

	result = NULL;
	if (s)
	{
		slen = ft_strlen(s);
		result = (char *)malloc(sizeof(char) * (len + 1));
		if (NULL == result)
			return (NULL);
		i = 0;
		while ((i < len) && ((start + i) < slen))
		{
			result[i] = s[start + i];
			i++;
		}
		result[i] = '\0';
	}
	return (result);
}

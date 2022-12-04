/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 23:45:37 by ttanja            #+#    #+#             */
/*   Updated: 2021/10/13 11:27:25 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*result;
	size_t	s1len;
	size_t	s2len;

	result = NULL;
	if (s1 && s2)
	{
		s1len = ft_strlen(s1);
		s2len = ft_strlen(s2);
		result = (char *)malloc(sizeof(char *) * (s1len + s2len + 1));
		if (NULL == result)
			return (NULL);
		ft_strlcpy(result, s1, sizeof(char *) * (s1len + s2len + 1));
		ft_strlcat(result, s2, sizeof(char *) * (s1len + s2len + 1));
	}
	return (result);
}

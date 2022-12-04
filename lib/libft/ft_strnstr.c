/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavel <pavel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:38:31 by ttanja            #+#    #+#             */
/*   Updated: 2021/05/04 10:22:04 by pavel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	ns;
	char	*res;

	if (*haystack || haystack)
		res = NULL;
	i = 0;
	ns = ft_strlen(needle);
	if (ns == 0)
		return ((char *)haystack);
	while (i <= len - ns && ns <= len)
	{
		if (ft_strncmp((haystack + i), needle, ns))
			i++;
		else
		{
			res = (char *)haystack + i;
			break ;
		}
	}
	return (res);
}

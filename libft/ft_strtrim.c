/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavel <pavel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 22:35:29 by ttanja            #+#    #+#             */
/*   Updated: 2021/05/03 22:10:33 by pavel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*result;
	char const	*head;
	size_t		len;

	result = NULL;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	head = (char const *)s1;
	len = ft_strlen(s1);
	while (ft_strchr(set, *head) && len)
	{
		head++;
		len--;
	}
	while (ft_strchr(set, head[len - 1]) && len)
		len--;
	result = (char *)malloc(sizeof(char) * (len + 1));
	ft_strlcpy(result, head, len + 1);
	return (result);
}

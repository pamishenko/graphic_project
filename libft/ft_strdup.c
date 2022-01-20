/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavel <pavel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:17:01 by ttanja            #+#    #+#             */
/*   Updated: 2021/05/06 09:43:08 by pavel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*temp;
	char	*dup;

	temp = (char *)s1;
	dup = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (NULL == dup)
		return (NULL);
	while (*temp)
		*dup++ = *temp++;
	*dup = '\0';
	return (dup - ft_strlen(s1));
}

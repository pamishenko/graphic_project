/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavel <pavel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 23:39:16 by pavel             #+#    #+#             */
/*   Updated: 2021/05/03 22:31:33 by pavel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	size;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (size + 1));
	i = 0;
	if (!result)
		return (NULL);
	while (i < size && s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

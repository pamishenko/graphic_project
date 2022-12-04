/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 23:16:18 by ttanja            #+#    #+#             */
/*   Updated: 2022/01/21 16:08:37 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if ((c == 0) & (s[i] == 0))
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;

	i = ft_strlen_gnl(s1);
	j = 0;
	result = (char *)malloc(sizeof(char) * (i + ft_strlen_gnl(s2) + 1));
	if (!result)
		return (NULL);
	if (!s1)
		ft_strlcpy_gnl(result, s2, ft_strlen_gnl(s2) + 1);
	else
	{
		ft_strlcpy_gnl(result, s1, ft_strlen_gnl(s1) + 1);
		while (s2[j] != '\0')
			result[i++] = s2[j++];
		result[i] = '\0';
		free(s1);
	}
	return (result);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t l)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (src[res])
		res++;
	if (l == 0)
	{
		while (dst[i])
			i++;
		dst[i] = 0;
		return (res);
	}
	while (((i + 1) < l) & (i < res))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavel <pavel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 22:02:00 by ttanja            #+#    #+#             */
/*   Updated: 2021/05/06 10:23:38 by pavel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			**ft_clean_malloc(char **tab, size_t j);
static unsigned int	ft_count_str(char const *s, char c);
static void			ft_get_next_str(char **c_str, unsigned int *str_le, char c);

char	**ft_split(char const *s, char c)
{
	char			**result;
	char			*curent_str;
	unsigned int	curent_str_ln;
	unsigned int	count_str;
	unsigned int	i;

	if (!s)
		return (NULL);
	count_str = ft_count_str(s, c);
	result = (char **)malloc(sizeof(char **) * (count_str + 1));
	if (!result)
		return (NULL);
	i = 0;
	curent_str = (char *)s;
	curent_str_ln = 0;
	while (i < count_str)
	{
		ft_get_next_str(&curent_str, &curent_str_ln, c);
		result[i] = (char *)malloc(sizeof(char) * (curent_str_ln + 1));
		if (!result[i])
			return (ft_clean_malloc(result, i));
		ft_strlcpy(result[i++], curent_str, curent_str_ln + 1);
	}
	result[i] = 0;
	return (result);
}

static char	**ft_clean_malloc(char **result, size_t j)
{
	unsigned int	i;

	i = 0;
	while (i <= j)
	{
		free(result[i]);
		i++;
	}
	return (NULL);
}

static unsigned int	ft_count_str(char const *s, char c)
{
	unsigned int	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s && (*s == c))
		s++;
	while (*s)
	{
		if (*s == c)
		{
			count++;
			while (*s == c)
				s++;
			continue ;
		}
		s++;
	}
	if (*(s - 1) != c)
		count++;
	return (count);
}

static void	ft_get_next_str(char **c_str, unsigned int *str_ln, char c)
{
	*c_str += *str_ln;
	*str_ln = 0;
	while (**c_str == c)
		(*c_str)++;
	*str_ln = ft_strchr(*c_str, c) - *c_str;
}

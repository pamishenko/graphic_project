/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 19:29:48 by ttanja            #+#    #+#             */
/*   Updated: 2021/06/03 20:03:28 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_positives(long int nb)
{
	if (nb < 0)
		return (0);
	return (1);
}

int	counts(long int nb)
{
	int			length;
	long int	temp;

	temp = nb;
	length = 1;
	while (temp / 10 != 0)
	{
		length++;
		temp = temp / 10;
	}
	if (!is_positives(nb))
		length++;
	return (length);
}

char	*ft_itoa(long long int n)
{
	size_t		length;
	long int	temp;
	char		*result;

	length = counts(n);
	temp = n;
	result = (char *)malloc(sizeof(char) * (length + 1));
	if (!result)
		return (0);
	result[length] = '\0';
	while (length > 0)
	{
		if (!is_positives(n))
			result[length - 1] = (temp % 10) * -1 + '0';
		else
			result[length - 1] = (temp % 10) + '0';
		temp = temp / 10;
		length--;
	}
	if (!is_positives(n))
		result[0] = '-';
	return (result);
}

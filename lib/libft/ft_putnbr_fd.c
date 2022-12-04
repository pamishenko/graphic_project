/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 10:56:33 by ttanja            #+#    #+#             */
/*   Updated: 2021/04/29 21:52:17 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_positive(int nb)
{
	if (nb < 0)
		return (0);
	return (1);
}

int	count(int nb)
{
	int	length;
	int	temp;

	temp = nb;
	length = 1;
	while (temp / 10 != 0)
	{
		length++;
		temp = temp / 10;
	}
	if (!is_positive(nb))
		length++;
	return (length);
}

void	ft_putnbr_fd(int nb, int fd)
{
	int		length;
	int		temp;
	char	result[100];

	length = count(nb);
	temp = nb;
	result[length] = '\0';
	while (length-- > 0)
	{
		if (!is_positive(nb))
			result[length] = (temp % 10) * -1 + '0';
		else
			result[length] = (temp % 10) + '0';
		temp = temp / 10;
	}
	if (!is_positive(nb))
		result[0] = '-';
	ft_putstr_fd(result, fd);
}

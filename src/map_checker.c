/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:21:12 by ttanja            #+#    #+#             */
/*   Updated: 2022/01/26 17:12:57 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_map(char **map)
{
	if (**map)
		return (0);
	else
		return (1);
}
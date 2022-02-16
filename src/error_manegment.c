/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manegment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:01:44 by ttanja            #+#    #+#             */
/*   Updated: 2022/02/14 23:39:56 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1* map
// 2* player
// 3* texture
// 4* mlx?

#include <cub3d.h>
#include <libft.h>

void	printerror(int code)
{
	if (code == 11)
		ft_putstr_fd(RED_TXT"Error map parsing\n"RESET_TXT, 2);
	if (code == 21)
		ft_putstr_fd("Error parse player\n", 2);

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:12:07 by ttanja            #+#    #+#             */
/*   Updated: 2022/01/21 21:56:54 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <libft.h>

char	**make_map(t_list **head, int size)
{
	char	  **map = ft_calloc(size + 1, sizeof(char *));
	int		  i = -1;
	t_list	*tmp = *head;

	while (tmp)
	{
		map[++i] = tmp->content;
		tmp= tmp->next;
	}
	// i = -1;
	// while (map[++i])
	// 	ft_putendl_fd(map[i], 1);
	return (map);
}

char	**parse_map(char **argv)
{
	int		fd;
	char	*line;
	t_list	*head;
	
	fd = open(argv[1], O_RDONLY);
	line = NULL;
	head = NULL;
	while (ft_get_next_line(fd, &line))
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	return (make_map(&head, ft_lstsize(head)));
}
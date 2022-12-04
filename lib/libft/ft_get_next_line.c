/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 23:15:41 by ttanja            #+#    #+#             */
/*   Updated: 2022/01/21 16:09:18 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

char	*processing_eof(char *temp, char **line, char *buff)
{
	char	*eof;

	free(buff);
	eof = ft_strchr_gnl(temp, '\0');
	*line = malloc(sizeof(char) * (eof - temp + 1));
	if (*line == NULL)
	{
		free(temp);
		return (NULL);
	}
	ft_strlcpy_gnl(*line, temp, eof - temp + 1);
	if (temp)
		free(temp);
	return (0);
}

int	line_modify(char *temp, char **line, char *buff)
{
	char	*end_line;
	int		i;

	i = 0;
	free(buff);
	end_line = ft_strchr_gnl(temp, '\n');
	*line = malloc(sizeof(char) * (end_line - temp + 1));
	if (!*line)
	{
		free(line);
		free(temp);
		return (-1);
	}
	ft_strlcpy_gnl(*line, temp, end_line - temp + 1);
	while (end_line[i + 1] != '\0')
	{
		temp[i] = end_line[i + 1];
		i++;
	}
	temp[i] = '\0';
	return (0);
}

int	eof_check(char **temp, char **line, char *buff)
{
	*temp = processing_eof(*temp, line, buff);
	return (0);
}

int	ft_get_next_line(int fd, char **line)
{
	char			*buff;
	int				count_read;
	static char		*temp;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	count_read = 1;
	while (count_read > 0 && !(ft_strchr_gnl(temp, '\n')))
	{
		count_read = read(fd, buff, BUFFER_SIZE);
		if (count_read < 0)
		{
			free(buff);
			return (-1);
		}
		buff[count_read] = '\0';
		temp = ft_strjoin_gnl(temp, buff);
	}
	if (count_read == 0)
		return (eof_check(&(temp), line, buff));
	line_modify(temp, line, buff);
	return (1);
}

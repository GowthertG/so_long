/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:50:03 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/04/08 22:29:30 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*left_fun(int fd, char *left)
{
	char	*buff;
	int		bytes;

	buff = malloc (BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	bytes = 1;
	while (bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		left = _ft_strjoin(left, buff);
	}
	free(buff);
	return (left);
}

char	*get_next_line(int fd)
{
	static char	*left;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left = left_fun(fd, left);
	if (!left)
		return (NULL);
	if (!left[0])
	{
		free(left);
		left = NULL;
	}
	return (left);
}

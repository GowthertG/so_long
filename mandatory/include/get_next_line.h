/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:08:51 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/04/08 22:30:01 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 100000

# include <unistd.h>
# include <stdlib.h>

size_t	_ft_strlen(const char *s);
char	*_ft_strjoin(char *s1, char *s2);
char	*left_fun(int fd, char *left);
char	*get_next_line(int fd);
char	*_ft_strchr(char *s, int c);
#endif

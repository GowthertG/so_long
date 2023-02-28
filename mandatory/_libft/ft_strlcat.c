/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:16:05 by hhaddouc          #+#    #+#             */
/*   Updated: 2021/11/21 11:11:26 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*s;
	size_t	t;
	size_t	dst_len;
	size_t	i;

	s = (char *)src;
	t = 0;
	i = 0;
	if (!dst && !size)
		return (ft_strlen(s));
	dst_len = ft_strlen(dst);
	if (size > dst_len)
		t = ft_strlen(s) + dst_len;
	else
		return (size + ft_strlen(s));
	while (s[i] && dst_len + 1 < size)
	{
		dst[dst_len] = s[i];
		dst_len++;
		i++;
	}
	dst[dst_len] = '\0';
	return (t);
}

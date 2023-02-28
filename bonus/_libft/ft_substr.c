/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:33:22 by hhaddouc          #+#    #+#             */
/*   Updated: 2021/11/21 11:51:29 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*a;
	unsigned int	i;
	unsigned int	size;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start > len)
		size = len;
	else
		size = ft_strlen(s) - start;
	a = (char *)malloc(sizeof (char) * (size + 1));
	if (!a)
		return (NULL);
	i = 0;
	while (i < size)
	{
		a[i] = s[start + i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

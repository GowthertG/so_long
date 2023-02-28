/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:59:32 by hhaddouc          #+#    #+#             */
/*   Updated: 2021/11/20 22:31:53 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	n;

	n = ft_strlen(s);
	while (n)
	{
		if (s[n] == c)
		{
			return ((char *)s + n);
		}
		n--;
	}
	if (s[n] == (char)c)
		return ((char *)s + n);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:14:36 by hhaddouc          #+#    #+#             */
/*   Updated: 2021/11/07 14:23:37 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*s;
	char	*dest;

	s = (char *)src;
	dest = (char *)dst;
	if (s < dest)
	{
		while (n--)
			dest[n] = s[n];
	}
	else
		ft_memcpy(dest, s, n);
	return (dst);
}

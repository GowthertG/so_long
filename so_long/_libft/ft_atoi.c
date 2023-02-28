/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:07:38 by hhaddouc          #+#    #+#             */
/*   Updated: 2021/11/20 20:42:00 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if ((unsigned long)res * 10 + (*str - 48)
			> 9223372036854775807 && sign == 1)
			return (-1);
		else if ((unsigned long)res * 10 + (*str - 48)
			> (unsigned long)9223372036854775807 + 1 && sign == -1)
			return (0);
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res * sign);
}

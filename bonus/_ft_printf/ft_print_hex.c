/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:32:57 by hhaddouc          #+#    #+#             */
/*   Updated: 2021/12/05 23:25:22 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_hex_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int num, const char c)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, c);
		ft_put_hex(num % 16, c);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
		{
			if (c == 'x')
				ft_putchar((num - 10 + 'a'));
			if (c == 'X')
				ft_putchar((num - 10 + 'A'));
		}
	}
}

int	ft_print_hex(unsigned int num, const char c)
{
	if (num == 0)
	{
		return (write(1, "0", 1));
		return (1);
	}
	else
		ft_put_hex(num, c);
	return (ft_hex_len(num));
}

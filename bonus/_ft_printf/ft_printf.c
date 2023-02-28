/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:41:30 by hhaddouc          #+#    #+#             */
/*   Updated: 2021/12/06 04:38:06 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_test(char c)
{
	if (c == 'c' || c == 's' || c == 'p'
		||c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_print(va_list lp, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(lp, int));
	else if (c == 's')
		len += ft_putstr(va_arg(lp, char *));
	else if (c == 'p')
		len += ft_print_ad(va_arg(lp, unsigned long long));
	else if (c == 'x' || c == 'X')
		len += ft_print_hex(va_arg(lp, unsigned int), c);
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(lp, int));
	else if (c == 'u')
		len += ft_print_unsigned(va_arg(lp, unsigned int));
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	lp;
	int		len;

	i = 0;
	len = 0;
	va_start(lp, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_print(lp, str[i]);
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(lp);
	return (len);
}

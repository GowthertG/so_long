/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 03:21:50 by hhaddouc          #+#    #+#             */
/*   Updated: 2021/12/05 23:24:51 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_test(char c);
int		ft_print(va_list lp, const char c);
int		ft_printf(const char *str, ...);
int		ft_putnbr(int n);
char	*ft_itoa(int n);
int		ft_print_unsigned(unsigned int n);
char	*ft_uitoa(unsigned int n);
int		ft_num_len(unsigned	int num);
int		ft_hex_len(unsigned	int num);
int		ft_print_hex(unsigned int num, const char c);
int		ft_print_ad(unsigned long long ptr);
void	ft_put_hex_(unsigned long long num);
int		ft_ptr_len(unsigned long long num);

#endif
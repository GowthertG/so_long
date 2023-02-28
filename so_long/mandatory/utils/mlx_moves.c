/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 23:14:52 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/08/29 12:44:35 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up(int *x, int *y, char **map)
{
	if (map[*y - 1][*x] == 'E' && !ft_map_strchr(map))
		exit(ft_printf("┬  ┬┬┌─┐┌┬┐┌─┐┬─┐┬ ┬\n"
				"└┐┌┘││   │ │ │├┬┘└┬┘\n"
				" └┘ ┴└─┘ ┴ └─┘┴└─ ┴\n"
				));
	if (map[*y - 1][*x] != 'E')
	{
		map[*y - 1][*x] = 'U';
		map[*y][*x] = '0';
		print_move();
	}
}

void	move_down(int *x, int *y, char **map)
{
	map[*y + 1][*x] = 'D';
	map[*y][*x] = '0';
	print_move();
}

void	move_right(int *x, int *y, char **map)
{
	map[*y][*x - 1] = 'L';
	map[*y][*x] = '0';
	print_move();
}

void	move_left(int *x, int *y, char **map)
{
	map[*y][*x + 1] = 'R';
	map[*y][*x] = '0';
	print_move();
}

void	print_move(void)
{
	static int	moves;

	ft_printf("%d\n", ++moves);
}

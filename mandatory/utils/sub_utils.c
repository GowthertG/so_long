/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 23:15:49 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/09/03 04:17:15 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_player_index(int *x, int *y, char **map)
{
	while (map[*y])
	{
		while (map[*y][*x])
		{
			if ((map[*y][*x] == 'P'
				|| map[*y][*x] == 'U'
				|| map[*y][*x] == 'D'
				|| map[*y][*x] == 'L'
				|| map[*y][*x] == 'R'))
				return ;
			(*x)++;
		}
		(*x) = 0;
		(*y)++;
	}
}

int	move_player(int keycode, t_vars *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	get_player_index(&x, &y, game->map_data.two_dmap);
	if (keycode == 13 && (game->map_data.two_dmap[y - 1][x] == 'C'
		|| game->map_data.two_dmap[y - 1][x] == '0'
				|| game->map_data.two_dmap[y - 1][x] == 'E'))
		move_up(&x, &y, game->map_data.two_dmap);
	else if ((keycode == 1) && (game->map_data.two_dmap[y + 1][x] == 'C'
		|| game->map_data.two_dmap[y + 1][x] == '0'))
		move_down(&x, &y, game->map_data.two_dmap);
	else if ((keycode == 2) && (game->map_data.two_dmap[y][x + 1] == 'C'
		|| game->map_data.two_dmap[y][x + 1] == '0'))
		move_left(&x, &y, game->map_data.two_dmap);
	else if ((keycode == 0) && (game->map_data.two_dmap[y][x - 1] == 'C'
		|| game->map_data.two_dmap[y][x - 1] == '0'))
		move_right(&x, &y, game->map_data.two_dmap);
	else if (keycode == 53)
		close_win(game);
	display_map_components(game->map_data.two_dmap,
		&game->images, &game->mlx);
	return (1);
}

void	isclosed_surroundedbywalls(char **map)
{
	int	index;

	index = 0;
	while (index < ft_maplen(map))
	{
		if (map[index][0] != '1'
			|| (map[index][ft_strlen(map[index]) - 1] != '1'))
			exit(write(1, "Error : The map must"
					" be closed/surrounded by walls. \n", 53));
		index++;
	}
	index = 0;
	while (index < ft_strlen(map[0]))
	{
		if (map[0][index] != '1' || map[ft_maplen(map) - 1][index] != '1')
			exit(write(1, "Error : The map must"
					" be closed/surrounded by walls. \n", 53));
		index++;
	}
}

int	ft_maplen(char **map)
{
	int	index;

	index = 0;
	while (map[index])
		index++;
	return (index);
}

void	check_newlines(char *map)
{
	int	index;

	index = 0;
	while (map[index])
	{
		if (map[0] == '\n' || (map[index] == '\n' && map[index + 1] == '\n'))
			exit(write(1, "Error : too much newlines. \n", 29));
		index++;
	}
}

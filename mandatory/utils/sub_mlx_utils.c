/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_mlx_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 23:15:11 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/08/22 01:15:35 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_map_strchr(char **map)
{
	int	y;
	int	x;
	int	c;

	c = 0;
	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map [y][x] == 'C')
				return (++c);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

void	display_walls(char components,
	t_images *images, t_mlx_data *mlx, char **map)
{
	if (!(mlx->width_index / 32) && !(mlx->height_index / 32))
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			images->wall_up_left_corner, mlx->width_index, mlx->height_index);
	else if ((mlx->width_index / 32) < (int)ft_strlen(map[0]) - 1
		&& mlx->width_index / 32 != 0 && (mlx->height_index / 32 == 0
			|| mlx->height_index / 32 == ft_maplen(map) - 1))
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			images->wall_up_mid, mlx->width_index, mlx->height_index);
	else if (mlx->width_index == 0
		&& mlx->height_index != 0
		&& mlx->height_index / 32 < ft_maplen(map) - 1)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			images->wall_left, mlx->width_index, mlx->height_index);
	else if ((mlx->width_index / 32) == ((int)ft_strlen(map[0]) - 1)
		&& mlx->height_index != 0
		&& mlx->height_index / 32 != ft_maplen(map) - 1)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			images->wall_right, mlx->width_index, mlx->height_index);
	else if (mlx->width_index / 32 == 0
		&& (mlx->height_index / 32 == (ft_maplen(map) - 1)))
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			images->wall_down_left_corner,
			mlx->width_index, mlx->height_index);
	else
		sub_display_walls(components, images, mlx, map);
}

void	sub_display_walls(char components,
		t_images *images, t_mlx_data *mlx, char **map)
{
	if (components)
		;
	if (mlx->width_index / 32 == ((int)ft_strlen(map[0]) - 1)
		&& (mlx->height_index / 32 == (ft_maplen(map) - 1)))
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			images->wall_down_right_corner,
			mlx->width_index, mlx->height_index);
	else if (mlx->height_index != 0)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			images->box, mlx->width_index, mlx->height_index);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			images->wall_up_right_corner, mlx->width_index, mlx->height_index);
}

int	close_win(t_vars *game)
{
	mlx_destroy_window(game->mlx.mlx, game->mlx.mlx_win);
	exit(ft_printf("┌┐ ┬ ┬┌─┐┬\n"
			"├┴┐└┬┘├┤ │\n"
			"└─┘ ┴ └─┘o\n"));
	return (0);
}

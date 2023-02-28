/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_enemy_animation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:22:53 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/08/30 22:13:05 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	change_peaks_image(t_vars *game, int frame_number)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map_data.two_dmap[y])
	{
		while (game->map_data.two_dmap[y][x])
		{
			if (game->map_data.two_dmap[y][x] == 'p')
				put_peaks_image(x, y, game, frame_number);
			x++;
		}
		y++;
		x = 0;
	}
}

void	put_peaks_image(int x, int y, t_vars *game, int frame_number)
{
	if (frame_number == 0)
	{
		ft_put_ground(game, x, y);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
			game->mlx.peaks_animation[0], x * 32, y * 32);
	}
	else if (frame_number == 1)
	{
		ft_put_ground(game, x, y);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
			game->mlx.peaks_animation[1], x * 32, y * 32);
	}
	else if (frame_number == 2)
	{
		ft_put_ground(game, x, y);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
			game->mlx.peaks_animation[2], x * 32, y * 32);
	}
	else if (frame_number == 3)
	{
		ft_put_ground(game, x, y);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
			game->mlx.peaks_animation[3], x * 32, y * 32);
	}
}

void	mlx_peaks_animation(t_vars *game)
{
	static int	frame_number;
	static int	count;

	if (count > 2000)
	{
		if (frame_number == 0)
			change_peaks_image(game, frame_number++);
		else if (frame_number == 1)
			change_peaks_image(game, frame_number++);
		else if (frame_number == 2)
			change_peaks_image(game, frame_number++);
		else if (frame_number == 3)
			change_peaks_image(game, frame_number++);
		if (frame_number > 3)
			frame_number = 0;
		count = 0;
	}
	else
		count++;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_animation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:39:29 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/09/01 23:04:24 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	mlx_animation(t_vars *game)
{
	mlx_coin_animation(game);
	mlx_peaks_animation(game);
	return (0);
}

void	change_image(t_vars *game, int frame_number)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map_data.two_dmap[y])
	{
		while (game->map_data.two_dmap[y][x])
		{
			if (game->map_data.two_dmap[y][x] == 'C')
				put_image(x, y, game, frame_number);
			x++;
		}
		y++;
		x = 0;
	}
}

void	put_image(int x, int y, t_vars *game, int frame_number)
{
	if (frame_number == 0)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
			game->images.background, x * 32, y * 32);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
			game->images.coin_animation[0], x * 32, y * 32);
	}
	else if (frame_number == 1)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
			game->images.background, x * 32, y * 32);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
			game->images.coin_animation[1], x * 32, y * 32);
	}
	else if (frame_number == 2)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
			game->images.background, x * 32, y * 32);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
			game->images.coin_animation[2], x * 32, y * 32);
	}
}

void	mlx_coin_animation(t_vars *game)
{
	static int	frame_number;
	static int	count;

	if (count > 2000)
	{
		if (frame_number == 0)
			change_image(game, frame_number++);
		else if (frame_number == 1)
			change_image(game, frame_number++);
		else if (frame_number == 2)
			change_image(game, frame_number++);
		if (frame_number > 2)
			frame_number = 0;
		count = 0;
		game->move = ft_itoa(game->moves);
		mlx_string_put (game->mlx.mlx, game->mlx.mlx_win,
			32, 0, 0x75093a, game->move);
		free(game->move);
	}
	else
		count++;
}

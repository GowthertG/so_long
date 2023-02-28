/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_mlx_enemy_animation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 22:10:42 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/08/30 22:15:46 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_put_ground(t_vars *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
		game->images.background, x * 32, y * 32);
}

void	init_enemy(t_images *images, t_mlx_data *mlx)
{
	mlx->peaks_animation[0] = mlx_xpm_file_to_image(mlx->mlx, ""
			"assets/images/peaks_1.xpm", &mlx->image_width, &mlx->image_height);
	mlx->peaks_animation[1] = mlx_xpm_file_to_image(mlx->mlx, ""
			"assets/images/peaks_2.xpm", &mlx->image_width, &mlx->image_height);
	mlx->peaks_animation[2] = mlx_xpm_file_to_image(mlx->mlx, ""
			"assets/images/peaks_3.xpm", &mlx->image_width, &mlx->image_height);
	mlx->peaks_animation[3] = mlx_xpm_file_to_image(mlx->mlx, ""
			"assets/images/peaks_4.xpm", &mlx->image_width, &mlx->image_height);
}

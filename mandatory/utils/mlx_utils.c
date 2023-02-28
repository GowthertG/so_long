/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 23:13:50 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/08/21 23:17:06 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	images_init(t_images *images, t_mlx_data *mlx)
{
	wall_init(images, mlx);
	images->box = mlx_xpm_file_to_image(mlx->mlx, ""
			"assets/images/box_1.xpm", &mlx->image_width, &mlx->image_height);
	images->player_down = mlx_xpm_file_to_image(mlx->mlx, ""
			"assets/images/down.xpm", &mlx->image_width, &mlx->image_height);
	images->player_up = mlx_xpm_file_to_image(mlx->mlx, ""
			"assets/images/up.xpm", &mlx->image_width, &mlx->image_height);
	images->player_right = mlx_xpm_file_to_image(mlx->mlx, ""
			"assets/images/right.xpm", &mlx->image_width, &mlx->image_height);
	images->player_left = mlx_xpm_file_to_image(mlx->mlx, ""
			"assets/images/left.xpm", &mlx->image_width, &mlx->image_height);
	images->background = mlx_xpm_file_to_image(mlx->mlx, ""
			"assets/images/bg.xpm", &mlx->image_width, &mlx->image_height);
	images->coin = mlx_xpm_file_to_image(mlx->mlx, ""
			"assets/images/coin_1.xpm", &mlx->image_width, &mlx->image_height);
	images->odoor = mlx_xpm_file_to_image(mlx->mlx, ""
			"assets/images/door_animation/door_9.xpm",
			&mlx->image_width, &mlx->image_height);
	images->door = mlx_xpm_file_to_image(mlx->mlx, ""
			"assets/images/door_closed.xpm",
			&mlx->image_width, &mlx->image_height);
	images->rock = mlx_xpm_file_to_image(mlx->mlx, ""
			"assets/images/rock.xpm", &mlx->image_width, &mlx->image_height);
}

void	wall_init(t_images *images, t_mlx_data *mlx)
{
	images->wall_down_left_corner = mlx_xpm_file_to_image(mlx->mlx, ""
			"assets/images/wall_down_left_corner.xpm",
			&mlx->image_width, &mlx->image_height);
	images->wall_down_mid = mlx_xpm_file_to_image(mlx->mlx, ""
			"assets/images/wall_down_mid.xpm",
			&mlx->image_width, &mlx->image_height);
	images->wall_down_right_corner = mlx_xpm_file_to_image(mlx->mlx, "assets"
			"/images/wall_down_right_corner.xpm", &mlx->image_width,
			&mlx->image_height);
	images->wall_left = mlx_xpm_file_to_image(mlx->mlx, ""
			"assets/images/wall_left.xpm",
			&mlx->image_width, &mlx->image_height);
	images->wall_right = mlx_xpm_file_to_image(mlx->mlx, ""
			"assets/images/wall_right.xpm",
			&mlx->image_width, &mlx->image_height);
	images->wall_up_left_corner = mlx_xpm_file_to_image(mlx->mlx, ""
			"assets/images/wall_up_left_corner.xpm",
			&mlx->image_width, &mlx->image_height);
	images->wall_up_right_corner = mlx_xpm_file_to_image(mlx->mlx, ""
			"assets/images/wall_up_right_corner.xpm",
			&mlx->image_width, &mlx->image_height);
	images->wall_up_mid = mlx_xpm_file_to_image(mlx->mlx, ""
			"assets/images/wall_up_mid.xpm",
			&mlx->image_width, &mlx->image_height);
}

void	display_map_components(char **map, t_images *images, t_mlx_data *mlx)
{
	int	i;

	mlx->width_index = 0;
	mlx->height_index = 0;
	i = 0;
	while ((mlx->height_index / 32) < ft_maplen(map))
	{
		while ((map[mlx->height_index / 32][mlx->width_index / 32]))
		{
			put_components(map[mlx->height_index / 32][mlx->width_index / 32],
				images, mlx, map);
			mlx->width_index += 32;
		}
		mlx->width_index = 0;
		mlx->height_index += 32;
	}
}

void	put_components(char components,
	t_images *images, t_mlx_data *mlx, char **map)
{
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
		images->background, mlx->width_index, mlx->height_index);
	if (components == '1')
		display_walls(components, images, mlx, map);
	else if (components == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			images->player_down, mlx->width_index, mlx->height_index);
	else if (components == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			images->coin, mlx->width_index, mlx->height_index);
	else if (components == 'E')
		put_exit(components, images, mlx, map);
	else if (components == 'U')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			images->player_up, mlx->width_index, mlx->height_index);
	else if (components == 'D')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			images->player_down, mlx->width_index, mlx->height_index);
	else if (components == 'R')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			images->player_right, mlx->width_index, mlx->height_index);
	else if (components == 'L')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			images->player_left, mlx->width_index, mlx->height_index);
}

void	put_exit(char components,
	t_images *images, t_mlx_data *mlx, char **map)
{
	if (components)
		;
	if (ft_map_strchr(map))
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			images->door, mlx->width_index, mlx->height_index);
	else
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			images->background, mlx->width_index, mlx->height_index);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			images->odoor, mlx->width_index, mlx->height_index);
	}
}

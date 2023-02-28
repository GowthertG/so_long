/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 23:16:07 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/09/03 04:23:33 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	main(int argc, char **argv)
{
	t_vars	game;

	if (argc == 2)
	{
		check_format(argv[1]);
		init_data(&game.map_data, argv[1]);
		check_map(&game.map_data);
		game.mlx.mlx = mlx_init();
		images_init(&game.images, &game.mlx);
		game.mlx.mlx_win = mlx_new_window(game.mlx.mlx,
				(ft_strlen(game.map_data.two_dmap[1])) * 32,
				(ft_maplen(game.map_data.two_dmap)) * 32, "so_long");
		display_map_components(game.map_data.two_dmap, &game.images, &game.mlx);
		mlx_hook(game.mlx.mlx_win, 2, 0, &move_player, &game);
		mlx_hook(game.mlx.mlx_win, 17, 0, &close_win, &game);
		mlx_loop(game.mlx.mlx);
	}
	else
		write(1, "ERROR\n", 6);
}

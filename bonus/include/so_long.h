/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 23:14:41 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/09/01 09:09:19 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include <fcntl.h>

typedef struct s_data
{
	int		fd;
	char	*map;
	char	**two_dmap;
}	t_map_data;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*mlx_win;
	int		image_width;
	int		image_height;
	int		width_index;
	int		height_index;
	void	*peaks_animation[4];
}	t_mlx_data;

typedef struct s_images
{
	void	*wall_down_left_corner;
	void	*wall_down_mid;
	void	*wall_down_right_corner;
	void	*wall_left;
	void	*wall_right;
	void	*wall_up_left_corner;
	void	*wall_up_mid;
	void	*wall_up_right_corner;
	void	*box;
	void	*player_up;
	void	*player_down;
	void	*player_left;
	void	*player_right;	
	void	*background;
	void	*coin;
	void	*door;
	void	*odoor;
	void	*rock;
	void	*coin_animation[3];
	void	*peaks_animation[4];
}	t_images;

typedef struct s_vars
{
	t_images	images;	
	t_map_data	map_data;
	t_mlx_data	mlx;
	char		*move;
	int			moves;

}	t_vars;

void	check_format(char *filename);
void	init_data(t_map_data *map_data, char *filename);
void	check_data(t_map_data *map_data);
void	check_map_components(char *map_data);
void	check_map(t_map_data *map_data);
void	is_rectangular(char **map);
void	isclosed_surroundedbywalls(char **map);
int		ft_maplen(char **map);
void	check_newlines(char *map);

//mlx
void	images_init(t_images *images, t_mlx_data *mlx);
void	display_map_components(char **map, t_images *images, t_mlx_data *mlx);
void	put_components(char components, t_images *images,
			t_mlx_data *mlx, char **map);
void	display_walls(char components, t_images *images,
			t_mlx_data *mlx, char **map);
void	get_player_index(int *x, int *y, char **map);
int		move_player(int keycode, t_vars *game);
void	move_up(int *x, int *y, char **map, t_vars *game);
void	move_down(int *x, int *y, char **map, t_vars *game);
void	move_right(int *x, int *y, char **map, t_vars *game);
void	move_left(int *x, int *y, char **map, t_vars *game);
void	print_move(t_vars *game);
int		ft_map_strchr(char **map);
void	wall_init(t_images *images, t_mlx_data *mlx);
void	put_exit(char components,
			t_images *images, t_mlx_data *mlx, char **map);
void	sub_display_walls(char components,
			t_images *images, t_mlx_data *mlx, char **map);
int		close_win(t_vars *game);
void	mlx_coin_animation(t_vars *game);
int		mlx_animation(t_vars *game);
void	init_coin(t_images *images, t_mlx_data *mlx);
void	change_image(t_vars *game, int frame_number);
void	put_image(int x, int y, t_vars *game, int frame_number);
void	init_enemy(t_images *images, t_mlx_data *mlx);
void	mlx_peaks_animation(t_vars *game);
void	put_peaks_image(int x, int y, t_vars *game, int frame_number);
void	change_peaks_image(t_vars *game, int frame_number);
void	ft_put_ground(t_vars *game, int x, int y);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 23:15:58 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/09/01 10:02:10 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/get_next_line.h"

void	init_data(t_map_data *map_data, char	*filename )
{
	map_data->fd = open(filename, O_RDONLY);
	if (map_data->fd < 0)
		exit(write(1, "Error : cannot find the file.\n", 31));
	map_data->map = get_next_line(map_data->fd);
	map_data->two_dmap = ft_split(map_data->map, '\n');
}

void	check_format(char *filename)
{
	if (ft_strncmp(&filename[ft_strlen(filename) - 4], ".ber", 4))
		exit(write(2, "Error : the map extation must be (.ber).\n", 41));
}

void	check_map(t_map_data *map_data)
{
	check_map_components(map_data->map);
	is_rectangular(map_data->two_dmap);
	isclosed_surroundedbywalls(map_data->two_dmap);
	check_newlines(map_data->map);
}

void	check_map_components(char *map_data)
{
	int	index;

	index = 0;
	if (!map_data)
		exit(write(1, "Error : empty map\n", 18));
	if (!(ft_strchr((const char *)map_data, '1')
			&& ft_strchr((const char *)map_data, 'C')
			&& ft_strchr((const char *)map_data, 'E')
			&& ft_strchr((const char *)map_data, 'P')
			&& !ft_strchr((ft_strchr((const char *)map_data, 'P') + 1), 'P')))
		exit(write(1, "Error : The map must contain at least 1 exit,"
				"1 collectible, and 1 starting position.\n", 85));
	while (map_data[index])
	{
		if (map_data[index] != '1'
			&& map_data[index] != 'C'
			&& map_data[index] != '0'
			&& map_data[index] != 'E'
			&& map_data[index] != 'P'
			&& (map_data[index] != '\n'))
			exit(write(1, "Error : invalid  components.\n", 29));
		index++;
	}
}

void	is_rectangular(char **map)
{
	int	index;
	int	len;

	len = ft_strlen(map[0]);
	index = 1;
	while (map[index])
	{
		if (ft_strlen(map[index++]) != (size_t)len)
			exit(write(1, "The map must be rectangular.\n", 30));
	}
}

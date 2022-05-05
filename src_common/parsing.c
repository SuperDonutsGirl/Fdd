/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:36:58 by pamartin          #+#    #+#             */
/*   Updated: 2022/04/16 12:37:00 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_common.h"

void	get_height(t_map *map, char *file)
{
	char	*line;
	int		fd;

	fd = open_map(file);
	map->height = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		map->height++;
	}
	close(fd);
}

void	get_width(t_map *map, char *file)
{
	char	*line;
	int		i;
	int		check;
	int		fd;

	fd = open_map(file);
	line = get_next_line(fd);
	map->width = len_split(line);
	i = 0;
	while (line && i < map->height - 1)
	{
		free(line);
		line = get_next_line(fd);
		check = len_split(line);
		if (check != map->width)
			output_perso(map, "Invalid map\n");
		i++;
	}
	if (line)
		free(line);
	close(fd);
}

void	get_tab(t_map *map)
{
	int	i;

	map->z = malloc(sizeof(int **) * map->height);
	if (!map->z)
		output_auto(map);
	i = 0;
	while (i < map->height)
	{
		map->z[i] = malloc(sizeof(int *) * map->width);
		if (!map->z[i])
			output_auto(map);
		i++;
	}
}

void	get_data_map(t_map *map, char *file)
{
	int		x;
	int		y;
	int		fd;
	char	*line;
	char	**split;

	if (!ft_memcmp_reverse(file, ".fdf"))
		output_perso(map, "Invalid file\n");
	fd = open_map(file);
	line = get_next_line(fd);
	get_tab(map);
	y = -1;
	while (line && ++y < map->height)
	{
		x = -1;
		split = ft_split(line, ' ');
		while (++x < map->width)
			map->z[y][x] = ft_atoi(split[x]);
		ft_free_split(split);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close (fd);
}

void	parsing(t_map *map, char *file)
{
	get_height(map, file);
	get_width(map, file);
	get_data_map(map, file);
}

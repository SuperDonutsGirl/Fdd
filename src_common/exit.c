/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:35:41 by pamartin          #+#    #+#             */
/*   Updated: 2022/04/16 12:35:43 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_common.h"

int	output_perso(t_map *map, char *message)
{
	if (map)
		free(map);
	write(2, "Error : ", 8);
	write(2, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}

int	output_auto(t_map *map)
{
	if (map)
		free(map);
	perror("Error ");
	exit(EXIT_FAILURE);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map)
	{
		if (map->len_z >= 1)
			free(map->z_list);
		if (map->z)
		{
			while (i < map->height)
			{
				free(map->z[i]);
				i++;
			}
			free(map->z);
		}
		free(map);
	}
}

int	quit_map(int key, t_map *map)
{
	if (key == ESC)
	{
		mlx_destroy_window(map->mlx, map->mlx_win);
		free_map(map);
		exit (EXIT_SUCCESS);
	}
	return (0);
}

int	quit_x(int keycode, t_map *map)
{
	(void)map;
	if (keycode)
		exit(EXIT_SUCCESS);
	return (0);
}

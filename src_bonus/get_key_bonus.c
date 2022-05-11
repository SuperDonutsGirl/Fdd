/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:56:45 by pamartin          #+#    #+#             */
/*   Updated: 2022/04/20 18:56:47 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	zoom_mvt(int key, t_map *map)
{
	if (key == PLUS)
		map->zoom += map->add_zoom;
	if (key == MINUS && (map->zoom - map->add_zoom) > 0)
		map->zoom -= map->add_zoom;
	if (key == TOP)
		map->mvt_h += 20;
	if (key == DOWN)
		map->mvt_h -= 20;
	if (key == RIGHT)
		map->mvt_w -= 20;
	if (key == LEFT)
		map->mvt_w += 20;
}

void	rotation(int key, t_map *map)
{
	if (key == 89 || key == 92)
	{
		if (map->rot_x == 0)
			map->rot_x = 1;
		map->rot_y = 0;
		if (key == 89)
			map->teta -= 1;
		if (key == 92)
			map->teta += 1;
	}
	if (key == 83 || key == 85)
	{
		if (map->rot_y == 0)
			map->rot_y = 1;
		map->rot_x = 0;
		if (key == 83)
			map->teta -= 1;
		if (key == 85)
			map->teta += 1;
	}
}

void	restore(int key, t_map *map)
{
	if (key == RESTORE)
		init_effect(map);
}

void	altitude(int key, t_map *map)
{
	if (key == UP_Z)
	{
		map->altitude_pos += 5;
		map->altitude_neg -= 5;
	}
	if (key == DOWN_Z)
	{
		map->altitude_pos -= 5;
		map->altitude_neg += 5;
	}
}

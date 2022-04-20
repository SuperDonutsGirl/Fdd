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
	if (key == MINUS && map->zoom != 1)
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
	if (key == 46)
		map->teta += 5;
	if (key == 45)
		map->teta -= 5;
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
		printf("ici");
	}
	if (key == DOWN_Z)
	{
		map->altitude_pos -= 5;
		map->altitude_neg += 5;
	}
}

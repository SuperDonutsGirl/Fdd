/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mouse_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:56:58 by pamartin          #+#    #+#             */
/*   Updated: 2022/04/20 18:57:05 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	scroll_zoom(int button, t_map *map)
{
	if (map->view == 0)
	{
		if (button == 4)
			map->zoom += map->add_zoom;
		if (button == 5 && (map->zoom - map->add_zoom) > 0)
			map->zoom -= map->add_zoom;
	}
}

void	change_view(int x, int y, t_map *map)
{
	if ((x >= 135 && x <= 225) && (y >= 745 && y <= 765) && map->div_rad > 3)
		map->div_rad--;
	if ((x >= 300 && x <= 390) && (y >= 745 && y <= 765) && map->div_rad < 20)
		map->div_rad++;
}

void	change_color(int x, int y, t_map *map)
{
	if ((x >= 100 && x <= 165) && (y >= 425 && y <= 440))
		map->color = 2;
	if ((x >= 100 && x <= 165) && (y >= 445 && y <= 460))
		map->color = 3;
	if ((x >= 100 && x <= 165) && (y >= 465 && y <= 480))
		map->color = 4;
	if ((x >= 100 && x <= 165) && (y >= 485 && y <= 495))
		map->color = 1;
	if ((x >= 0 && x <= 15) && (y >= 600 && y <= 610))
		map->color = 5;
	if ((x >= 25 && x <= 45) && (y >= 600 && y <= 610))
		map->color = 6;
	if ((x >= 55 && x <= 75) && (y >= 600 && y <= 610))
		map->color = 7;
	if ((x >= 85 && x <= 105) && (y >= 600 && y <= 610))
		map->color = 8;
	if ((x >= 115 && x <= 135) && (y >= 600 && y <= 610))
		map->color = 9;
	if ((x >= 145 && x <= 165) && (y >= 600 && y <= 610))
		map->color = 10;
}

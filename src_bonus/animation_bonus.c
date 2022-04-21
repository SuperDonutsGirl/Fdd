/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:47:01 by pamartin          #+#    #+#             */
/*   Updated: 2022/04/20 18:47:03 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	animation(float *x, float *y, int z, t_map *map)
{
	if (z < 0 && map->altitude_neg != 0)
		z += map->altitude_neg;
	if (z > 0 && map->altitude_pos != 0)
		z += map->altitude_pos;
	if (map->rot_x == 1)
	{
		*y = *y * cos(map->teta) - z * sin(map->teta);
		z += *y * sin(map->teta) + z * sin(map->teta);
	}
	*x += (*x - *y) * cos(M_PI / map->div_rad);
	*y += (*x + *y) * sin(M_PI / map->div_rad) - z * cos(M_PI / map->div_rad);
	if (map->rot_y == 1)
		*x = *x * cos(map->teta) + z * sin(map->teta);
	*x *= map->zoom;
	*y *= map->zoom;
	*x += map->mvt_w;
	*y += map->mvt_h;
	*x += (WIDTH_WIN / 2) - map->width / 2;
	*y += (HEIGHT_WIN / 2) - map->height / 2;
}

int	get_grad(t_map *map, int z)
{
	int	grad;
	int	i;

	i = 0;
	while (z != map->z_list[i] && i < map->len_z)
		i++;
	grad = i * 100 / map->len_z;
	return (grad);
}

int	color(t_map *map, int z)
{
	int	grad;

	if (map->color == 1)
		return (16777215);
	if (map->color == 2)
		return (255);
	if (map->color == 3)
		return (65280);
	if (map->color == 4)
		return (16711680);
	grad = get_grad(map, z);
	if (map->color == 5)
		return (grad * 100 % 21474836 + 196);
	if (map->color == 6)
		return (grad * 1000 % 21474836 + 196);
	if (map->color == 7)
		return (grad * 100000 % 21474836 + 196);
	if (map->color == 8)
		return (grad * 100000 % 21474836 + 16711680);
	if (map->color == 9)
		return (grad * 10000 % 21474836 + 16711680);
	if (map->color == 10)
		return (grad * 100 % 21474836 + 16711680);
	return (0);
}

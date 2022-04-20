/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:29:29 by pamartin          #+#    #+#             */
/*   Updated: 2022/04/20 18:29:30 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_common.h"

void	init_mlx_win(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		output_auto(map);
	map->mlx_win = mlx_new_window(map->mlx, WIDTH_WIN, HEIGHT_WIN, map->title);
	if (!map->mlx_win)
		output_auto(map);
}

void	draw_map(t_map *map)
{
	map->img = mlx_new_image(map->mlx, WIDTH_WIN, HEIGHT_WIN);
	map->adr_img = mlx_get_data_addr(map->img, &map->bits_per_pixel,
			&map->size_line, &map->endian);
	draw_line(map);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img, 0, 0);
}

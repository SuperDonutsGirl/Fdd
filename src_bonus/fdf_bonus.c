/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:11:34 by pamartin          #+#    #+#             */
/*   Updated: 2022/04/20 18:11:36 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	init_effect(t_map *map)
{
	if (map->width < 60)
	{
		map->init_zoom = 5;
		if (map->width < 30)
			map->add_zoom = 5;
		else
			map->add_zoom = 2.5;
	}
	else if (map->width < 600)
	{
		map->init_zoom = 3;
		map->add_zoom = 0.5;
	}
	map->teta = 1;
	map->zoom = map->init_zoom;
	map->mvt_h = 1;
	map->mvt_w = 1;
	map->help = 1;
	map->div_rad = 3;
	map->view = 0;
	map->color = 1;
	map->color_menu = 0;
	map->altitude_pos = 0;
	map->altitude_neg = 0;
	map->is_alt_pressed = 0;
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		output_perso(NULL, "Bad args \n");
	map = malloc(sizeof(t_map));
	if (!map)
		output_auto(map);
	parsing(map, argv[1]);
	every_diff_z(map);
	quick_sort(map->z_list, 0, map->len_z - 1);
	init_effect(map);
	map->title = ft_strchr(argv[1], '/') + 1;
	init_mlx_win(map);
	draw_map(map);
	draw_menu(map);
	mlx_key_hook(map->mlx_win, get_key, map);
	mlx_mouse_hook(map->mlx_win, mouse_hook, map);
	mlx_hook(map->mlx_win, 17, 0L, quit_x, map->mlx_win);
	mlx_loop(map->mlx);
	return (0);
}

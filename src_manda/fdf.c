/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 10:50:11 by pamartin          #+#    #+#             */
/*   Updated: 2022/04/16 10:50:13 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		output_perso(NULL, "Bad args \n");
	map = malloc(sizeof(t_map));
	if (!map)
		output_auto(map);
	parsing(map, argv[1]);
	map->title = ft_strchr(argv[1], '/') + 1;
	init_mlx_win(map);
	draw_map(map);
	mlx_key_hook(map->mlx_win, quit_map, map);
	mlx_hook(map->mlx_win, 17, 0L, quit_x, map->mlx_win);
	mlx_loop(map->mlx);
}

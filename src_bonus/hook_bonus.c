/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:58:46 by pamartin          #+#    #+#             */
/*   Updated: 2022/04/20 18:58:47 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

int	get_key(int key, t_map *map)
{
	quit_map(key, map);
	mlx_clear_window(map->mlx, map->mlx_win);
	draw_map(map);
	zoom_mvt(key, map);
	altitude(key, map);
	rotation(key, map);
	restore(key, map);
	if (need_view(key, map))
	{
		if (map->view == 1)
			draw_bottom_view(map);
	}
	print_help_menu(key, map);
	print_color_menu(key, map);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_map *map)
{
	scroll_zoom(button, map);
	if (map->view)
		change_view(x, y, map);
	if (map->color_menu)
		change_color(x, y, map);
	mlx_clear_window(map->mlx, map->mlx_win);
	draw_map(map);
	if (map->view)
		draw_bottom_view(map);
	if (map->color_menu)
		draw_color_menu(map);
	if (map->help)
		draw_menu(map);
	return (0);
}

void	print_help_menu(int key, t_map *map)
{
	if (need_help(key, map))
	{
		if (map->help == 1)
			draw_menu(map);
		else
		{
			mlx_clear_window(map->mlx, map->mlx_win);
			draw_map(map);
			if (map->view == 1)
				draw_bottom_view(map);
		}
	}
}

void	print_color_menu(int key, t_map *map)
{
	if (need_color_menu(key, map))
	{
		if (map->color_menu == 1)
		{
			draw_map(map);
			draw_color_menu(map);
		}
		else
		{
			mlx_clear_window(map->mlx, map->mlx_win);
			draw_map(map);
		}
		if (map->help == 1)
			draw_menu(map);
		if (map->view == 1)
			draw_bottom_view(map);
	}
}

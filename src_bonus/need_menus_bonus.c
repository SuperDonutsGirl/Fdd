/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_menus_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:09:14 by pamartin          #+#    #+#             */
/*   Updated: 2022/04/20 19:09:15 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

int	need_help(int key, t_map *map)
{
	if (key == HELP)
	{
		if (map->help == 0)
			map->help = 1;
		else
			map->help = 0;
	}
	return (1);
}

int	need_color_menu(int key, t_map *map)
{
	if (key == 8)
	{
		if (map->color_menu == 0)
			map->color_menu = 1;
		else
			map->color_menu = 0;
	}
	return (1);
}

int	need_view(int key, t_map *map)
{
	if (key == VIEW)
	{
		if (map->view == 0)
			map->view = 1;
		else
			map->view = 0;
	}
	return (1);
}

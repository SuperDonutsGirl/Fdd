/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:33:01 by pamartin          #+#    #+#             */
/*   Updated: 2022/04/20 18:33:03 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	draw_menu(t_map *map)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = map->mlx;
	win = map->mlx_win;
	mlx_string_put(mlx, win, 1, y, WHITE, "          --HELP--");
	mlx_string_put(mlx, win, 1, y += 18, WHITE, " ");
	mlx_string_put(mlx, win, 1, y += 18, WHITE, "Zoom         scroll or +/- ");
	mlx_string_put(mlx, win, 1, y += 18, WHITE, "Altitude      page up/down");
	mlx_string_put(mlx, win, 1, y += 18, WHITE, "Translation        Arrow ");
	mlx_string_put(mlx, win, 1, y += 18, WHITE, "Rotation X axis   	 7 / 9 ");
	mlx_string_put(mlx, win, 1, y += 18, WHITE, "Rotation Y axis   	 1 / 3 ");
	mlx_string_put(mlx, win, 1, y += 18, WHITE, "Point of view        V   ");
	mlx_string_put(mlx, win, 1, y += 18, WHITE, "Restore map          R   ");
	mlx_string_put(mlx, win, 1, y += 18, WHITE, "Color                C   ");
	mlx_string_put(mlx, win, 1, y += 18, WHITE, " ");
	mlx_string_put(mlx, win, 1, y += 18, WHITE, " ");
	mlx_string_put(mlx, win, 1, y += 18, WHITE, "Quit map            ESC  ");
	mlx_string_put(mlx, win, 1, y += 18, WHITE, "Quit help            H   ");
}

void	draw_color_menu(t_map *map)
{
	int		y;
	void	*mlx;
	void	*win;

	y = HEIGHT_WIN / 2;
	mlx = map->mlx;
	win = map->mlx_win;
	mlx_string_put(mlx, win, 1, y + 10, WHITE, "  --ONE COLOR--");
	mlx_string_put(mlx, win, 1, y += 18, WHITE, " ");
	mlx_string_put(mlx, win, 1, y += 18, WHITE, "clic on -> Blue ");
	mlx_string_put(mlx, win, 1, y += 18, WHITE, "clic on -> Green ");
	mlx_string_put(mlx, win, 1, y += 18, WHITE, "clic on -> Red ");
	mlx_string_put(mlx, win, 1, y += 18, WHITE, "clic on -> White ");
	mlx_string_put(mlx, win, 1, y += 18, WHITE, " ");
	mlx_string_put(mlx, win, 1, y += 18, WHITE, " --MULTI COLOR--");
	mlx_string_put(mlx, win, 1, y += 8, WHITE, " ");
	mlx_string_put(mlx, win, 1, y += 18, WHITE, "    clic on ");
	mlx_string_put(mlx, win, 1, y += 18, WHITE, "|  |  |  |  |  |");
	mlx_string_put(mlx, win, 1, y += 15, WHITE, "v  v  v  v  v  v");
	mlx_string_put(mlx, win, 1, y += 18, WHITE, "o  o  o  o  o  o");
}

void	draw_bottom_view(t_map *map)
{
	void	*mlx;
	void	*win;

	mlx = map->mlx;
	win = map->mlx_win;
	mlx_string_put(mlx, win, 15, HEIGHT_WIN - 50, WHITE, "Change View");
	mlx_string_put(mlx, win, 30, HEIGHT_WIN - 25, WHITE,
		"clic on -> GET HIHT  or -> GET DOWN");
}

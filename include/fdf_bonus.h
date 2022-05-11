/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:23:14 by pamartin          #+#    #+#             */
/*   Updated: 2022/04/20 18:23:16 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include <stdlib.h>
# include <string.h>
//# include </usr/X11/include/mlx.h>
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include "fdf_common.h"
# include "../libft/libft.h"

//Draw
void	draw_menu(t_map *map);
void	draw_color_menu(t_map *map);
void	draw_bottom_view(t_map *map);

//Get data's Z
void	every_diff_z(t_map *map);
void	quick_sort(int *tab, int start, int end);

//Animations
int		color(t_map *map, int z);
void	animation(float *x, float *y, int z, t_map *map);
void	init_effect(t_map *map);

//Get key-board informations
int		need_view(int key, t_map *map);
int		need_color_menu(int key, t_map *map);
int		need_help(int key, t_map *map);
void	zoom_mvt(int key, t_map *map);
void	rotation(int key, t_map *map);
void	restore(int key, t_map *map);
void	altitude(int key, t_map *map);

//Get mouse informations
void	scroll_zoom(int button, t_map *map);
void	change_view(int x, int y, t_map *map);
void	change_color(int x, int y, t_map *map);
//Print menu
void	print_color_menu(int key, t_map *map);
void	print_help_menu(int key, t_map *map);
//Hook
int		get_key(int key, t_map *map);
int		mouse_hook(int button, int x, int y, t_map *map);
#endif

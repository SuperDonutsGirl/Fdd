/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:51:46 by pamartin          #+#    #+#             */
/*   Updated: 2022/04/19 13:51:47 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_map
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*adr_img;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*title;
	int		**z;
	int		x;
	int		y;
	int		width;
	int		height;
	float	init_zoom;
	float	add_zoom;
	float	zoom;
	int		mvt_h;
	int		mvt_w;
	int		view;
	float	div_rad;
	int		help;
	int		teta;
	int		*z_list;
	int		altitude_pos;
	int		altitude_neg;
	int		len_z;
	int		color;
	int		color_menu;
	float	center[2];
	int		rot_x;
	int		rot_y;
}	t_map;

#endif
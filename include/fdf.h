/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 10:52:12 by pamartin          #+#    #+#             */
/*   Updated: 2022/04/16 10:52:14 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <string.h>
//# include </usr/X11/include/mlx.h>
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include "fdf_common.h"
# include "../libft/libft.h"

# define    WIDTH_WIN   1024
# define    HEIGHT_WIN  768

int		color(t_map *map, int z);
void	animation(float *x, float *y, int z, t_map *map);

//Draw in windows
void	draw_line(t_map *map);
void	bresenham(float x, float y, int type, t_map *map);

#endif

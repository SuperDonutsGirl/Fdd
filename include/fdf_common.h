/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_common.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 11:29:55 by pamartin          #+#    #+#             */
/*   Updated: 2022/04/16 11:29:58 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_COMMON_H
# define FDF_COMMON_H

# include "struct.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include "get_next_line.h"
# include "fdf.h"
# include "../libft/libft.h"
# include "mlx_key.h"

# define    WHITE       0xFFFFFF

//Exit programm
int		output_auto(t_map *map);
int		output_perso(t_map *map, char *message);
int		quit_map(int key, t_map *map);
int		quit_x(int keycode, t_map *map);
void	free_map(t_map *map);

//Init
void	init_mlx_win(t_map *map);
void	draw_map(t_map *map);
//Draw
void	draw_line(t_map *map);

//Utils Parsing
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
int		ft_atoi(const char *str);
int		open_map(char *file);
int		len_split(char *line);
void	parsing(t_map *map, char *file);
void	ft_put_pixel(int x, int y, int color, t_map *map);

#endif

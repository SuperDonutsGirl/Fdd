/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_bonus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:35:42 by pamartin          #+#    #+#             */
/*   Updated: 2022/04/20 18:35:43 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

int	already_seen(int *list, int z, int i)
{
	i--;
	while (i >= 0)
	{
		if (list[i] == z)
			return (1);
		i--;
	}
	return (0);
}

void	every_diff_z(t_map *map)
{
	int	x;
	int	y;

	map->z_list = malloc(sizeof(int));
	if (!map->z_list)
		output_auto(map);
	map->z_list[0] = map->z[0][0];
	map->len_z = 1;
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (!already_seen(map->z_list, map->z[y][x], map->len_z)
			&& !already_seen(map->z[y], map->z[y][x], x))
			{
				map->z_list = ft_realloc_int(map->z_list, map->len_z, 1);
				if (!map->z_list)
					output_auto(map);
				map->z_list[map->len_z] = map->z[y][x];
				map->len_z++;
			}
		}
	}
}

static void	ft_swap(int *tab, int i, int x)
{
	int	tmp;

	tmp = tab[i];
	tab[i] = tab[x];
	tab[x] = tmp;
}

static int	partition(int *tab, int start, int end)
{
	int	pivot;
	int	top;
	int	down;

	pivot = tab[start];
	top = start + 1;
	down = end;
	while (1)
	{
		while (top <= down && tab[down] >= pivot)
			down--;
		while (top <= down && tab[top] <= pivot)
			top++;
		if (top <= down)
			ft_swap(tab, top, down);
		else
			break ;
	}
	ft_swap(tab, start, down);
	return (down);
}

void	quick_sort(int *tab, int start, int end)
{
	int	p;

	if (start >= end)
		return ;
	p = partition(tab, start, end);
	quick_sort(tab, start, p - 1);
	quick_sort(tab, p + 1, end);
}

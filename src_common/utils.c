/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:26:09 by pamartin          #+#    #+#             */
/*   Updated: 2022/04/05 13:26:11 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_common.h"

int	len_split(char *line)
{
	char	**split;
	int		i;

	split = ft_split(line, ' ');
	if (!split)
		return (0);
	i = 0;
	while (split[i])
		i++;
	ft_free_split(split);
	return (i);
}

int	open_map(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		output_auto(NULL);
	return (fd);
}

int	ft_memcmp_reverse(char *s1, char *s2)
{
	int	len;
	int	i;
	int	y;

	len = ft_strlen(s2);
	i = ft_strlen(s1) - len;
	y = 0;
	while (s1[i] && s2[y])
	{
		if (s1[i] != s2[y])
			return (0);
		i++;
		y++;
	}
	return (1);
}

char	*first_gnl(t_map *map, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line == NULL)
		output_perso(map, "Map invalid");
	return (line);
}

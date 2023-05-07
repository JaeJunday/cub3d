/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejkim <jaejkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:47:56 by hujeong           #+#    #+#             */
/*   Updated: 2023/05/05 17:46:37 by jaejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_map(t_map *map)
{
	if (map->position != 1 || map->height < 3 || map->width < 3
		|| map->height > 1000 || map->width > 1000)
		map_error(map);
}

void	copy_content(char *src, char *map, int width)
{
	int	j;

	j = 0;
	while (src[j] && src[j] != '\n')
	{
		map[j] = src[j];
		++j;
	}
	while (j < width)
	{
		map[j] = ' ';
		++j;
	}
	map[width] = '\0';
}

void	make_map_array(t_map *map)
{
	t_list	*temp;
	int		i;

	map->map = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->map)
		malloc_error();
	temp = map->tmp;
	i = 0;
	while (i < map->height)
	{
		map->map[i] = (char *)malloc(sizeof(char) * (map->width + 1));
		if (!map->map)
			malloc_error();
		copy_content(temp->content, map->map[i], map->width);
		temp = temp->next;
		++i;
	}
	map->map[map->height] = NULL;
}

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

void	copy_content(char *str, t_map *map, int i)
{
	int j;
	
	j = 0;
	while (str[j] && str[j] != '\n')
	{
		map->map[i][j] = str[j];
		++j;
	}
	while (j < map->width)
	{
		map->map[i][j] = ' ';
		++j;
	}
	map->map[i][map->width] = '\0';
}

void	make_map_array(t_map *map, int i)
{
	t_list	*temp;

	map->map = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->map)
		malloc_error();
	temp = map->tmp;
	while(i < map->height)
	{
		map->map[i] = (char *)malloc(sizeof(char) * map->width + 1);
		if (!map->map)
			malloc_error();
		copy_content(temp->content, map, i);
		temp = temp->next;
		++i;
	}
	map->map[map->height] = NULL;
}
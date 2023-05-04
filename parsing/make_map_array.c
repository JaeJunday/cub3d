/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejkim <jaejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:47:56 by hujeong           #+#    #+#             */
/*   Updated: 2023/05/04 21:37:52 by jaejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	copy_content(char *str, t_map *map, int i)
{
	int j;
	
	j = 0;
	while (str[j] && str[j] != '\n')
	{
		map->map[i][j] = str[j];
		map->test_map[i][j] = str[j];
		++j;
	}
	while (j < map->width)
	{
		map->map[i][j] = ' ';
		map->test_map[i][j] = ' ';
		++j;
	}
	map->map[i][map->width] = '\0';
	map->test_map[i][map->width] = '\0';
}

void	make_map_array(t_map *map, int i)
{
	t_list	*temp;

	if (map->height < 3)
		map_error(map);
	map->map = (char **)malloc(sizeof(char *) * (map->height + 1));
	map->test_map = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->map || !map->test_map)
		malloc_error();
	temp = map->tmp;
	while(i < map->height)
	{
		map->map[i] = (char *)malloc(sizeof(char) * map->width + 1);
		map->test_map[i] = (char *)malloc(sizeof(char) * map->width + 1);
		if (!map->map || !map->test_map)
			malloc_error();
		copy_content(temp->content, map, i);
		temp = temp->next;
		++i;
	}
	map->map[map->height] = NULL;
	map->test_map[map->height] = NULL;
}
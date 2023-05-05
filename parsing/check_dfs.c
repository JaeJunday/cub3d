/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejkim <jaejkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:48:09 by hujeong           #+#    #+#             */
/*   Updated: 2023/05/05 11:27:53 by jaejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	move_map(t_map *map, int y, int x, t_bool *flag)
{
	if (x < 0 ||  y < 0 || x >= map->height || y >= map->width)
		return (false);
	if ((x == 0 || y == 0 || x == map->height - 1 || y == map->width - 1) && map->map[x][y] != '1')
	{
		*flag = false;
		return (false);
	}
	else if (map->map[x][y] == ' ')
	{
		*flag = false;
		return (false);
	}
	else if (map->map[x][y] == '1' || map->map[x][y] == '2')
		return (false);
	else if (map->map[x][y] == '0')
	{
		map->map[x][y] = '2';
		return (true);
	}
	return (true);
}

void dfs_map(t_map *map, int x, int y, t_bool *flag)
{
	if (move_map(map, x, y, flag) == false)
		return ;
	if (*flag == true)
		dfs_map(map, x + 1, y, flag);
	if (*flag == true)
		dfs_map(map, x, y + 1, flag);
	if (*flag == true)
		dfs_map(map, x - 1, y, flag);
	if (*flag == true)
		dfs_map(map, x, y - 1, flag);
}

void check_map(t_map *map)
{
	t_bool flag;
	int x;
	int y;

	// dfs recursive guard add 
	flag = true;
	map->map[(int)map->pos_y][(int)map->pos_x] = '0';
	y = -1;
	while(++y < map->height)
	{
		x = -1;
		while(++x < map->width)
		{
			if (map->map[y][x] == '0' && flag == true)
				dfs_map(map, x, y, &flag);
		}
	}
	if (flag == false)
	{
		// clear_map_arr(map);
		map_error(map);
	}
	//------------------
	int i = -1;
	while(map->map[++i])
		printf("%s\n", map->map[i]);
	// ---------------s
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:48:09 by hujeong           #+#    #+#             */
/*   Updated: 2023/05/04 17:12:17 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_map(char **map, t_map *info, t_bool *flag)
{
	const int x = info->pos_y;
	const int y = info->pos_x;

	if (x < 0 || x >= info->height || y < 0 || y > info->width)
		return (false);
	if ((x == 0 || x == info->height - 1 || y == 0 || y == info->width)
		&& map[x][y] != '1')
	{
		info->valid_flag = false;
		return (false);
	}
	if (map[x][y] == '1')
		return (false);
	else if (map[x][y] == ' ' || map[x][y] == '\0')
	{
		info->valid_flag = false;
		return (false);
	}
	else if (map[x][y] == '0')
	{
		map[x][y] = '1';
		return (true);
	}
	return (true);
}

void dfs_map(t_map *map, double pos_x, double pos_y, t_bool *flag)
{
	if (move_map(map->test_map, map, flag) == false)
		return ;
	if (flag == false)
		return ;
	dfs_map(map, pos_x + 1, pos_y, flag);
	if (flag == false)
		return ;
	dfs_map(map, pos_x, pos_y + 1, flag);
	if (flag == false)
		return ;
	dfs_map(map, pos_x - 1, pos_y, flag);
	if (flag == false)
		return ;
	dfs_map(map, pos_x, pos_y - 1, flag);
}

void check_map(t_map *map)
{
	t_bool flag;

	flag = true;
	map->test_map[(int)map->pos_y][(int)map->pos_x] = '0';
	dfs_map(map, map->pos_x, map->pos_y, &flag);
	if (flag == false)
	{
		clear_map_arr(map);
		map_error(map);
	}
	//------------------
	int i = -1;
	while(map->test_map[++i])
		printf("%s\n", map->test_map[i]);
	// ---------------s
	free_split(map->test_map);
}
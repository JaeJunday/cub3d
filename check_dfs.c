#include "cub3d.h"

int	move_map(int **map, t_map *info, double y, double x)
{
	if (x <= 0 || x >= info->width 
		|| y <= 0 || y >= info->height)
		return (false);
	if (map[x][y] == 1)
		return (false);
	else if (map[x][y] == -1)
	{
		info->valid_flag = false;
		return (false);
	}
	else if (map[x][y] == 0)
	{
		map[x][y] = 1;
		return (true);
	}
	return (true);
}

void dfs_map(t_map *map, double pos_x, double pos_y)
{
	if (move_map(map, pos_x, pos_y) == false)
		return ;
	dfs_map(map->test_map, pos_x + 1, pos_y);
	dfs_map(map->test_map, pos_x, pos_y + 1);
	dfs_map(map->test_map, pos_x - 1, pos_y);
	dfs_map(map->test_map, pos_x, pos_y - 1);
}

t_bool check_map(t_map *map)
{
	int i;

	map->valid_flag = true;
	dfs_map(map->test_map, map->pos_x, map->pos_y);
	if (map->valid_flag = false)
		return (false);
	i = -1;
	free_split(map->test_map);
	return (true);
}
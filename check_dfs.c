#include "cub3d.h"

int	move_map(char ***map, t_map *info, int y, int x)
{
	if (x < 0 || x >= info->height 
		|| y < 0 || y > info->width)
		return (false);
	if ((x == 0 || x == info->height - 1
		|| y == 0 || y == info->width)
		&& (*map)[x][y] != '1')
	{
		info->valid_flag = false;
		return (false);
	}
	if ((*map)[x][y] == '1')
		return (false);
	else if ((*map)[x][y] == ' ' || (*map)[x][y] == '\0')
	{
		info->valid_flag = false;
		return (false);
	}
	else if ((*map)[x][y] == '0')
	{
		(*map)[x][y] = '1';
		return (true);
	}
	return (true);
}

void dfs_map(t_map *map, double pos_x, double pos_y)
{
	if (move_map(&map->test_map, map, pos_x, pos_y) == false)
		return ;
	dfs_map(map, pos_x + 1, pos_y);
	dfs_map(map, pos_x, pos_y + 1);
	dfs_map(map, pos_x - 1, pos_y);
	dfs_map(map, pos_x, pos_y - 1);
}

t_bool check_map(t_map *map)
{
	printf("%d\n", map->width);
	printf("%d\n", map->height);
	printf("pos_x : %f\n", map->pos_x);
	printf("pos_y : %f\n", map->pos_y);

	map->valid_flag = true;
	map->test_map[(int)map->pos_y][(int)map->pos_x] = '0';
	dfs_map(map, map->pos_x, map->pos_y);
	if (map->valid_flag == false)
		return (false);
	//------------------
    int i = -1;
    while(map->test_map[++i])
        printf("%s\n", map->test_map[i]);
	// ---------------s
	free_split(map->test_map);
	return (true);
}

int    dfs_valid_map(t_map *map, double pos, int *depth)
{
    if (is_wall(map, map->map, pos))
        return (true);
    if (depth > map->width || depth > map->height)
        return (false);
    if (dfs_valid_map(map, map_line, pos_x + 1, pos_y) == false)
        return (false);
    dfs_valid_map(map, map_line, pos_x, pos_y + 1);
    dfs_valid_map(map, map_line, pos_x - 1, pos_y);
    dfs_valid_map(map, map_line, pos_x, pos_y - 1);
}

int check_map(t_map *map)
{
    int depth;
    // 벽으로 막혀있는지 유효성 검사
    depth = 0;
    if (dfs_valid_map(map, pos_x, pos_y, &depth));
}
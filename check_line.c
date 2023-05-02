#include "cub3d.h"

t_bool	check_info(t_flag flag)
{
	if (flag.no && flag.so && flag.we
		&& flag.ea && flag.f && flag.c)
		return (true);
	return (false);
}

int check_line(char *line, t_map *map)
{
	static t_flag	flag;

	if (check_info(flag))
		get_map_data(line, map);
	else
		get_map_info(line, map, &flag);
	return (true);
}

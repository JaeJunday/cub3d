#include "cub3d.h"

t_bool	check_info(t_flag flag)
{
	
}

int check_line(char *line, t_map *map)
{
	static t_flag	flag;
	int				i;

	if (check_info(flag))
		get_map_data(line, map);
	else
		get_map_info(line, map);
}

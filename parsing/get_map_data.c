#include "cub3d.h"

void	get_direction(t_map *map, char c)
{
	if (c == 'N' || c == 'S')
	{
		map->dir_x = 0;
		if (c == 'N')
			map->dir_y = -1;
		else
			map->dir_y = 0;
		map->plane_x = 0;
		map->plane_y = 0.66;
	}
	else if (c == 'W' || c == 'E')
	{
		map->dir_y = 0;
		if (c == 'W')
			map->dir_x = -1;
		else
			map->dir_x = 1;
		map->plane_x = 0.66;
		map->plane_y = 0;
	}
}

int	skip_line(char *line)
{
	static t_bool	is_map_line;
	int				i;

	if (is_map_line)
		return (0);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != ' ')
		{
			is_map_line = true;
			return (0);
		}
	}
	free(line);
	return (1);
}

void	check_map_line(char *line, t_map *map, int pos_y, int i)
{
	static t_bool position;

	while (line[i] && line[i] != '\n')
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == ' ')
			;
		else if (line[i] == 'N' || line[i] == 'S' \
			  || line[i] == 'E' || line[i] == 'W')
		{
			if (position)
				map_error(map);
			position = true;
			map->pos_x = i;
			map->pos_y = pos_y;
			get_direction(map, line[i]);
		}
		else
		{
			free(line);
			map_error(map);
		}
		++i;
	}
	if (map->width < i)
		map->width = i;
}

void	get_map_data(char *line, t_map *map)
{
	t_list			*node;

	if (skip_line(line))
		return ;
	check_map_line(line, map, ft_lstsize(map->tmp), 0);
	node = ft_lstnew(line);
	if (node == NULL)
		malloc_error();
	ft_lstadd_back(&(map->tmp), node);
}
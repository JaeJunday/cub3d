#include "cub3d.h"

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

void	make_map_array(t_map *map, int size, int i)
{
	t_list	*temp;

	size = ft_lstsize(map->tmp);
	if (size < 3)
		map_error(map);
	map->map = (char **)malloc(sizeof(char *) * (size + 1));
	map->test_map = (char **)malloc(sizeof(char *) * (size + 1));
	if (!map->map || !map->test_map)
		malloc_error();
	temp = map->tmp;
	while(temp)
	{
		map->map[i] = (char *)malloc(sizeof(char) * map->width + 1);
		map->test_map[i] = (char *)malloc(sizeof(char) * map->width + 1);
		if (!map->map || !map->test_map)
			malloc_error();
		copy_content(temp->content, map, i);
		temp = temp->next;
		++map->height;
		++i;
	}
	map->map[size] = NULL;
	map->test_map[size] = NULL;
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
			//direction setting
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

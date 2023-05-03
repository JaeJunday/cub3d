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
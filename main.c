#include "cub3d.h"

int arg_check(int argc, char **argv)
{
	int len;

	if (argc != 2)
		return (printf("Error: argument error\n"));
	len = ft_strlen(argv[1]);
	if (len < 5
		|| argv[1][len - 4] != '.'
		|| argv[1][len - 3] != 'c'
		|| argv[1][len - 2] != 'u'
		|| argv[1][len - 1] != 'b')
		return (printf("Error: argument error\n"));
	return (0);
}

int parse_map(char **argv, t_map *map)
{
	int fd;
	char *line;

	fd = open(argv[1], O_RDONLY);
	if (!fd)
		return (printf("Error: file open error\n"));
	line = get_next_line(fd);
	while (line)
	{
		check_line(line, map);
		line = get_next_line(fd);
	}
	if (map->position != true)
		return (map_error(map));
	make_map_array(map, 0, 0);// 2차원 배열 할당해서 리스트를 배열로 옮기는 함수
	check_map(map);
	close(fd);
	return (0);
}

int main(int argc, char **argv)
{
	t_map map;

	if (arg_check(argc, argv))
		return (1);
	ft_memset(&map, 0, sizeof(t_map));
	parse_map(argv, &map);
	start(map);
// ------------------------< test code >----------------------//
	// printf("wid : %d, hei : %d, pos_x : %f, pos_y : %f\n", map.width, map.height, map.pos_x, map.pos_y);
	// int i = -1;
	// while(map.map[++i])
	//	 printf("%s\n", map.map[i]);
	//i = -1;
	//while(map.test_map[++i])
	//	printf("%s\n", map.test_map[i]); 
// ------------------------< test code >----------------------//
}
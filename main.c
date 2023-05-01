#include "cub3d.h"

int parse_map(int argc, char **argv, t_map *map)
{
    int fd;
    char *line;
    int i;

    i = 0;
    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
		line = get_next_line(fd);
        while (line)
        {
            check_line(line, map);
			free(line);
			line = get_next_line(fd);
        }
        check_map(map);
        close(fd);
    }
    else
    {
        printf("Error\n");
        return (1);
    }
    return (0);
}

int main(int argc, char **argv)
{
	t_map map;

    parse_map(argc, argv, &map);
}
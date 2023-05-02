#include "cub3d.h"
#include "libft/libft.h"

void	format_error(char **info, t_flag *flag, t_map *map)
{
	free_split(info);
	if (flag->no)
		free(map->info->no);
	if (flag->so)
		free(map->info->so);
	if (flag->we)
		free(map->info->we);
	if (flag->ea)
		free(map->info->ea);
	printf("Error : invalid format\n");
	exit(1);
}

int	set_map_info_bg(int *color, t_flag *flag, char **info, t_map *map)
{
	char	**rgb;
	int		i;
	int		buf;

	if (*flag == true)
		format_error(info, flag, map);
	rgb = ft_split(info[1], ',');
	if (rgb == NULL)
		error();
	i = 0;
	while (rgb[i])
		++i;
	if (i != 3 && free_split(rgb))
		format_error(info, flag, map);
	i = 0;
	*color = 0;
	while (rgb[i])
	{
		buf = ft_atoi(rgb[i]);
		if (buf < 0 && free_split(rgb))
			format_error(info, map, flag);
		*color = (*color << 8) + buf;
	}
	*flag = true;
	return (free_split(rgb) + free_split(info));
}

void	set_map_info_wall(char **wall, t_flag *flag, char **info, t_map *map)
{
	int fd;
	int	len;

	if (*flag == true)
		format_error();
	*wall = ft_strdup(info[1]);
	len = ft_strlen(*wall);
	if (ft_strncmp(*wall[len - 4], ".xpm", 4) != 0)
		format_error();
	fd = open(*wall, O_RDONLY);
	if (fd == -1)
		format_error(info, map, flag);
	close(fd);
	*flag = true;
	free_split(info);
}

void	set_map_info(char **info, t_map *map, t_flag *flag)
{
	if (info[0][0] == 'F' && info[0][1] == '\0')
		set_map_info_bg(&map->info.f, &flag->f, info);
	else if(info[0][0] == 'C' && info[0][1] == '\0')
		set_map_info_bg(&map->info.c, &flag->c, info);
	else if (info[0][0] == 'N' && info[0][1] == 'O'
			&& info[0][2] == '\0')
		set_map_info_wall(&map->info.no, &flag->no, info);
	else if(info[0][0] == 'S' && info[0][1] == 'O'
			&& info[0][2] == '\0')
		set_map_info_wall(&map->info.so, &flag->so, info);
	else if(info[0][0] == 'W' && info[0][1] == 'E'
			&& info[0][2] == '\0')
		set_map_info_wall(&map->info.we, &flag->we, info);
	else if(info[0][0] == 'E' && info[0][1] == 'A'
			&& info[0][2] == '\0')
		set_map_info_wall(&map->info.ea, &flag->ea, info);
	else
		format_error(info, map, flag);
}

void	get_map_info(char *line, t_map *map, t_flag *flag)
{
	char	**map_info;
	int		count;

	map_info = ft_split(line, ' ');
	if (map_info == NULL)
		error();
	count = 0;
	while (map_info[count])
		++count;
	if (count == 0)
		free(map_info);
	else if (count == 2)
		set_map_info(map_info, map, flag);
	else
		format_error(map_info, map, flag);
}
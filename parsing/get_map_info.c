/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejkim <jaejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:47:59 by hujeong           #+#    #+#             */
/*   Updated: 2023/05/04 20:18:51 by jaejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	set_map_info_bg(int *color, t_bool *flag, char **info, t_map *map)
{
	char	**rgb;
	int		i;
	int		buf;

	if (*flag == true)
		format_error(info, map);
	rgb = ft_split(info[1], ',');
	if (rgb == NULL)
		malloc_error();
	i = 0;
	while (rgb[i])
		++i;
	if (i != 3 && free_split(rgb))
		format_error(info, map);
	i = 0;
	*color = 0;
	while (rgb[i])
	{
		buf = ft_atoi(rgb[i]);
		if (buf < 0 && free_split(rgb))
			format_error(info, map);
		*color = (*color << 8) + buf;
		++i;
	}
	*flag = true;
	return (free_split(rgb) + free_split(info));
}

void	set_map_info_wall(char **wall, t_bool *flag, char **info, t_map *map)
{
	int fd;
	int	len;

	if (*flag == true)
		format_error(info, map);
	*wall = ft_strdup(info[1]);
	len = ft_strlen(*wall);
	if (len < 5 || ft_strncmp(&((*wall)[len - 4]), ".xpm", 4) != 0)
		format_error(info, map);
	fd = open(*wall, O_RDONLY);
	if (fd == -1)
		format_error(info, map);
	close(fd);
	*flag = true;
	free_split(info);
}

void	set_map_info(char **info, t_map *map, t_flag *flag)
{
	if (info[0][0] == 'F' && info[0][1] == '\0')
		set_map_info_bg(&map->info.f, &flag->f, info, map);
	else if(info[0][0] == 'C' && info[0][1] == '\0')
		set_map_info_bg(&map->info.c, &flag->c, info, map);
	else if (info[0][0] == 'N' && info[0][1] == 'O'
			&& info[0][2] == '\0')
		set_map_info_wall(&map->info.no, &flag->no, info, map);
	else if(info[0][0] == 'S' && info[0][1] == 'O'
			&& info[0][2] == '\0')
		set_map_info_wall(&map->info.so, &flag->so, info, map);
	else if(info[0][0] == 'W' && info[0][1] == 'E'
			&& info[0][2] == '\0')
		set_map_info_wall(&map->info.we, &flag->we, info, map);
	else if(info[0][0] == 'E' && info[0][1] == 'A'
			&& info[0][2] == '\0')
		set_map_info_wall(&map->info.ea, &flag->ea, info, map);
	else
		format_error(info, map);
}

void	get_map_info(char *line, t_map *map, t_flag *flag)
{
	char	**map_info;
	int		count;

	map_info = ft_split(line, ' ');
	free(line);
	if (map_info == NULL)
		malloc_error();
	count = 0;
	while (map_info[count])
		++count;
	if (count == 0)
		free(map_info);
	else if (count == 2)
		set_map_info(map_info, map, flag);
	else
		format_error(map_info, map);
}
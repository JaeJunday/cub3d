/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:47:59 by hujeong           #+#    #+#             */
/*   Updated: 2023/05/08 09:27:57 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	set_map_info_bg(int *color, t_bool *flag, char **info)
{
	char	**rgb;
	int		i;
	int		buf;

	if (*flag == true)
		format_error(info);
	rgb = ft_split(info[1], ',');
	if (rgb == NULL)
		malloc_error();
	i = 0;
	while (rgb[i])
		++i;
	if (i != 3 && free_split(rgb))
		format_error(info);
	*color = 0;
	i = -1;
	while (rgb[++i])
	{
		buf = ft_atoi(rgb[i]);
		if (buf < 0 && free_split(rgb))
			format_error(info);
		*color = (*color << 8) + buf;
	}
	*flag = true;
	return (free_split(rgb) + free_split(info));
}

void	set_map_info_wall(t_img *xpm, t_bool *flag, char **info, t_map *map)
{
	int	fd;
	int	len;

	if (*flag == true)
		format_error(info);
	len = ft_strlen(info[1]);
	if (len < 5 && ft_strncmp(&(info[1][len - 4]), ".xpm", 4) != 0)
		format_error(info);
	fd = open(info[1], O_RDONLY);
	if (fd == -1)
		format_error(info);
	xpm->img = mlx_xpm_file_to_image(map->mlx, info[1], &xpm->wid, &xpm->hei);
	if (xpm->img == NULL)
		format_error(info);
	xpm->addr = mlx_get_data_addr(xpm->img, &xpm->bits_per_pixel, \
		&xpm->line_length, &xpm->endian);
	*flag = true;
	close(fd);
	free_split(info);
}

void	set_map_info(char **info, t_map *map, t_flag *flag)
{
	if (!ft_strncmp(info[0], "F", 2))
		set_map_info_bg(&map->info.f, &flag->f, info);
	else if (!ft_strncmp(info[0], "C", 2))
		set_map_info_bg(&map->info.c, &flag->c, info);
	else if (!ft_strncmp(info[0], "NO", 3))
		set_map_info_wall(&(map->xpm[0]), &flag->no, info, map);
	else if (!ft_strncmp(info[0], "EA", 3))
		set_map_info_wall(&(map->xpm[1]), &flag->so, info, map);
	else if (!ft_strncmp(info[0], "SO", 3))
		set_map_info_wall(&(map->xpm[2]), &flag->we, info, map);
	else if (!ft_strncmp(info[0], "WE", 3))
		set_map_info_wall(&(map->xpm[3]), &flag->ea, info, map);
	else
		format_error(info);
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
		format_error(map_info);
}

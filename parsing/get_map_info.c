/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejkim <jaejkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:47:59 by hujeong           #+#    #+#             */
/*   Updated: 2023/05/05 18:18:15 by jaejkim          ###   ########.fr       */
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
	i = 0;
	*color = 0;
	while (rgb[i])
	{
		buf = ft_atoi(rgb[i]);
		if (buf < 0 && free_split(rgb))
			format_error(info);
		*color = (*color << 8) + buf;
		++i;
	}
	*flag = true;
	return (free_split(rgb) + free_split(info));
}

void	set_map_info_wall(t_img *xpm, t_bool *flag, char **info, t_map *map)
{
	int fd;
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
	// xpm->img = mlx_xpm_file_to_image(map->mlx, info[1], &xpm->wid, &xpm->hei);
	if (xpm->img == NULL)
		format_error(info);
	xpm->addr = mlx_get_data_addr(xpm->img, &xpm->bits_per_pixel, &xpm->line_length, &xpm->endian);
	*flag = true;
	close(fd);
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
		set_map_info_wall(&(map->xpm[0]), &flag->no, info, map);
	else if(info[0][0] == 'E' && info[0][1] == 'A'
			&& info[0][2] == '\0')
		set_map_info_wall(&(map->xpm[1]), &flag->so, info, map);
	else if(info[0][0] == 'S' && info[0][1] == 'O'
			&& info[0][2] == '\0')
		set_map_info_wall(&(map->xpm[2]), &flag->we, info, map);
	else if(info[0][0] == 'W' && info[0][1] == 'E'
			&& info[0][2] == '\0')
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
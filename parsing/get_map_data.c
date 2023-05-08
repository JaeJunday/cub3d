/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:48:04 by hujeong           #+#    #+#             */
/*   Updated: 2023/05/08 09:31:16 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_direction(t_map *map, char c)
{
	if (c == 'N' || c == 'S')
	{
		map->dir_x = 0;
		if (c == 'N')
			map->dir_y = -1;
		else
			map->dir_y = 1;
		map->plane_x = map->dir_y * -1 * PLAIN;
		map->plane_y = 0;
	}
	else if (c == 'W' || c == 'E')
	{
		map->dir_y = 0;
		if (c == 'W')
			map->dir_x = -1;
		else
			map->dir_x = 1;
		map->plane_x = 0;
		map->plane_y = map->dir_x * PLAIN;
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
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == ' ')
			;
		else if (line[i] == 'N' || line[i] == 'S' \
				|| line[i] == 'E' || line[i] == 'W')
		{
			map->position += 1;
			map->pos_x = i + 0.5;
			map->pos_y = pos_y + 0.5;
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
	check_map_line(line, map, map->height, 0);
	node = ft_lstnew(ft_strdup(line));
	free(line);
	if (node == NULL)
		malloc_error();
	ft_lstadd_back(&(map->tmp), &(map->tmp_tail), node);
	map->height += 1;
}

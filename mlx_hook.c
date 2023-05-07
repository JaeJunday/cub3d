/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejkim <jaejkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:21:26 by hujeong           #+#    #+#             */
/*   Updated: 2023/05/05 16:46:18by jaejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	close_win(t_map *map)
{
	free_split(map->map);
	exit(0);
}

void	move_up_down(t_map *map, int dir)
{
	double delta_x;
	double delta_y;
	
	delta_x = (map->dir_x * SPEED * dir);
	delta_y = (map->dir_y * SPEED * dir);
	if (map->map[(int)map->pos_y][(int)(map->pos_x + delta_x)] == AISLE)
		map->pos_x += delta_x;
	if (map->map[(int)(map->pos_y + delta_y)][(int)map->pos_x] == AISLE)
		map->pos_y += delta_y;
}

void	move_right_left(t_map *map, int dir)
{
	double	dir_x;
	double	dir_y;

	dir_x = cos(radian(90 * dir)) * map->dir_x - sin(radian(90 * dir)) * map->dir_y;
	dir_y = sin(radian(90 * dir)) * map->dir_x + cos(radian(90 * dir)) * map->dir_y;
	if (map->map[(int)map->pos_y][(int)(map->pos_x + dir_x * SPEED)] == AISLE)
		map->pos_x += dir_x * SPEED;
	if(map->map[(int)(map->pos_y + dir_y * SPEED)][(int)map->pos_x] == AISLE)
		map->pos_y += dir_y * SPEED;
}

int	key_press(int key, t_map *map)
{
	if (key == w_key || key == up_key)
		move_up_down(map, 1);
	else if (key == s_key || key == down_key)
		move_up_down(map, -1);
	else if (key == a_key)
		move_right_left(map, 1);
	else if (key == d_key)
		move_right_left(map, -1);
	else if (key == left_key)
		rotate(map, 1);
	else if (key == right_key)
		rotate(map, -1);
	else if (key == ESC)
		close_win(map);
	return (true);
}

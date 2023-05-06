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
	printf("deltaX, deltaY : %f %f\n", map->pos_x, map->pos_y);
	if (map->pos_x + delta_x > 0
		&& map->pos_x + delta_x < map->width - 1
		&& map->map[(int)map->pos_y][(int)(map->pos_x + delta_x)] == AISLE)
		map->pos_x += delta_x;
	if (map->pos_y + delta_y > 0
		&& map->pos_y + delta_y < map->height - 1
		&& map->map[(int)(map->pos_y + delta_y)][(int)map->pos_x] == AISLE)
		map->pos_y += delta_y;
}

void	move_right_left(t_map *map, int dir)
{
	double	dir_x;
	double	dir_y;

	printf("deltaX, deltaY : %f %f\n", map->pos_x, map->pos_y);
	dir_x = cos(radian(90 * dir)) * map->dir_x - sin(radian(90 * dir)) * map->dir_y;
	dir_y = sin(radian(90 * dir)) * map->dir_x + cos(radian(90 * dir)) * map->dir_y;
	printf("deltaX, deltaY : %f %f\n", map->pos_x + dir_x * SPEED, map->pos_y + dir_y * SPEED);
	if (map->pos_x + dir_x * SPEED > 0
		&& map->pos_x + dir_x * SPEED < map->width - 1
		&& map->map[(int)map->pos_y][(int)(map->pos_x + dir_x * SPEED)] == AISLE)
		map->pos_x += dir_x * SPEED;
	if(map->pos_y + dir_y * SPEED > 0
		&& map->pos_y + dir_y * SPEED < map->height - 1
		&& map->map[(int)(map->pos_y + dir_y * SPEED)][(int)map->pos_x] == AISLE)
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

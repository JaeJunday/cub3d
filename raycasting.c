/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:48:32 by hujeong           #+#    #+#             */
/*   Updated: 2023/05/04 12:32:53 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall(t_vector v)
{
	int line_height;

	line_height = /v
}
void	set_side_dist(t_map *map, t_vector *v);
{
	if (v->ray_dir_x < 0)
	{
		v->step_x = -1;
		v->side_dist_x = (map->pos_x - v->map_x) * v->delta_dist_x;
	}
	else
	{
		v->step_x = 1;
		v->side_dist_x = (v->map_x + 1 - map->pos_x) * v->delta_dist_x;
	}
	if (v->ray_dir_y < 0)
	{
		v->step_y = -1;
		v->side_dist_x = (map->pos_y - v->map_y) * v->delta_dist_y;
	}
	else
	{
		v->step_y = 1;
		v->side_dist_x = (v->map_y + 1 - map->pos_y) * v->delta_dist_y;
	}
}

void	check_side_dda(t_map *map, t_vector *v)
{
	while(1)
	{
		if (v->side_dist_x < v->side_dist_x)
		{
			v->side_dist_x += v->delta_dist_x;
			v->map_x += v->step_x;
			v->side = AXIS_X;
		}
		else
		{
			v->side_dist_x += v->delta_dist_y;
			v->map_y += v->step_y;
			v->side = AXIS_Y;
		}
		if (map->map[v->map_x][v->map_y] == '1')
			break;
	}
	if (v->side == AXIS_X) 
		v->perp_wall_dist = (v->mapX - v->posX + (1 - v->stepX) / 2) / v->rayDirX;
	else
		v->perp_wall_dist = (v->mapY - v->posY + (1 - v->stepY) / 2) / v->rayDirY;
}

void	ray_casting(t_map *map)
{
	t_vector	v;
	int			i;

	v.map_x = (int)map->pos_x;
	v.map_y = (int)map->pos_y;
	i = -1;
	while(++i < 1280)
	{
		v.camera_x = 2 * i / (double)1280 - 1;
		v.ray_dir_x = map->dir_x + map->plane_x * v.camera_x;
		v.ray_dir_y = map->dir_y + map->plane_y * v.camera_x;
		v.delta_dist_x = fabs(1 / v.ray_dir_x);
		v.delta_dist_y = fabs(1 / v.ray_dir_y);
		set_side_dist(map, &v);
		check_side_dda(map, &v);
		draw_wall(map, &v);
	}
	mlx_put_image_to_window(map->mlx, map->win, map->img->img, 0, 0);
}

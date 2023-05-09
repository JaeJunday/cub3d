/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:48:32 by hujeong           #+#    #+#             */
/*   Updated: 2023/05/08 16:18:03 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall(t_map *map, t_vector *v, int x, int tex_num)
{
	int		line_height;
	double	tex_pos;
	double	step;
	int		draw_start;
	int		draw_end;

	get_xpm_texture_x(map, v, &map->xpm[tex_num]);
	line_height = (int)(WIN_H / v->perp_wall_dist);
	draw_start = WIN_H / 2 - line_height / 2;
	draw_end = WIN_H / 2 + line_height / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= WIN_H)
		draw_end = WIN_H - 1;
	step = (double)map->xpm[tex_num].hei / line_height;
	tex_pos = (draw_start - WIN_H / 2 + line_height / 2) * step;
	while (draw_start < draw_end)
	{
		v->tex_y = (int)tex_pos & (map->xpm[tex_num].hei - 1);
		my_mlx_pixel_put(&map->img, x, draw_start,
			get_xpm_texture_color(&map->xpm[tex_num], v));
		tex_pos += step;
		++draw_start;
	}
}

void	set_side_dist(t_map *map, t_vector *v)
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
		v->side_dist_y = (map->pos_y - v->map_y) * v->delta_dist_y;
	}
	else
	{
		v->step_y = 1;
		v->side_dist_y = (v->map_y + 1 - map->pos_y) * v->delta_dist_y;
	}
}

void	check_side_dda(t_map *map, t_vector *v)
{
	while (1)
	{
		if (v->side_dist_x < v->side_dist_y)
		{
			v->side_dist_x += v->delta_dist_x;
			v->map_x += v->step_x;
			v->side = AXIS_Y;
		}
		else
		{
			v->side_dist_y += v->delta_dist_y;
			v->map_y += v->step_y;
			v->side = AXIS_X;
		}
		if (map->map[v->map_y][v->map_x] == WALL)
			break ;
	}
	if (v->side == AXIS_Y)
		v->perp_wall_dist
			= (v->map_x - map->pos_x + (1 - v->step_x) / 2) / v->ray_dir_x;
	else
		v->perp_wall_dist
			= (v->map_y - map->pos_y + (1 - v->step_y) / 2) / v->ray_dir_y;
}

void	ray_casting(t_map *map)
{
	t_vector	v;
	int			i;

	clear_img(&map->img, map->info.c, map->info.f);
	i = -1;
	while (++i < WIN_W)
	{
		v.map_x = (int)map->pos_x;
		v.map_y = (int)map->pos_y;
		v.camera_x = 2 * i / (double)WIN_W - 1;
		v.ray_dir_x = map->dir_x + map->plane_x * v.camera_x;
		v.ray_dir_y = map->dir_y + map->plane_y * v.camera_x;
		v.delta_dist_x = fabs(1 / v.ray_dir_x);
		v.delta_dist_y = fabs(1 / v.ray_dir_y);
		set_side_dist(map, &v);
		check_side_dda(map, &v);
		draw_wall(map, &v, i, get_xpm_texture(&v));
	}
	mlx_put_image_to_window(map->mlx, map->win, map->img.img, 0, 0);
}

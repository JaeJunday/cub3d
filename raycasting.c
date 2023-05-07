/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:48:32 by hujeong           #+#    #+#             */
/*   Updated: 2023/05/07 17:02:42 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_xpm_texture_x(t_map *map, t_vector *v, t_img *xpm)
{
	//아직 이해 못함
	if (v->side == AXIS_Y) 
		v->wall_x = map->pos_y + v->perp_wall_dist * v->ray_dir_y;
	else
		v->wall_x = map->pos_x + v->perp_wall_dist * v->ray_dir_x;
	v->wall_x -= floor((v->wall_x));
	//x coordinate on the texture
	v->tex_x = (int)(v->wall_x * xpm->wid);
	if((v->side == AXIS_Y && v->ray_dir_x > 0) || (v->side == AXIS_X && v->ray_dir_y < 0)) 
		v->tex_x = xpm->wid - v->tex_x - 1;
}

int get_xpm_texture_color(t_img *xpm, t_vector *v, double tex_pos)
{
	int *addr;

	//if (tex_pos >= xpm->hei)
	//	return (false);
	addr = (int *)xpm->addr;
	return (addr[(int)tex_pos * xpm->wid + v->tex_x]);
}

int	get_xpm_texture(t_vector *v)
{
	if (v->side == AXIS_X)
	{
		if (v->ray_dir_y < 0) // 북
			return (0);
		else if (v->ray_dir_y >= 0) // 남
			return (2);
	}
	else if(v->side == AXIS_Y)
	{
		if (v->ray_dir_x > 0) // 서
			return (3);
		else if (v->ray_dir_x <= 0) //동
			return (1);
	}
	return (true);
}

void	draw_wall(t_map *map, t_vector *v, int x)
{
	int line_height;
	double tex_pos;
	int y;
	double step;
	int tex_num;
	int draw_start;
	int draw_end;

	tex_num = get_xpm_texture(v);
	get_xpm_texture_x(map, v, &map->xpm[tex_num]);
	line_height = (int)(WIN_H / v->perp_wall_dist);
	draw_start = WIN_H / 2 - line_height / 2;
	draw_end = WIN_H / 2 + line_height / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= WIN_H)
		draw_end = WIN_H - 1;
	step = (double)map->xpm[tex_num].hei / line_height;
	tex_pos = 0;
	y = draw_start;
	while (y < draw_end)
	{
		int tex_y = (int)tex_pos & (map->xpm[tex_num].hei - 1);
		int color = get_xpm_texture_color(&map->xpm[tex_num], v, tex_y);
		my_mlx_pixel_put(&map->img, x, y, color);
		tex_pos += step;
		++y;
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
	while(1)
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
		if (v->map_x >= 0
			&& v->map_x <= map->width - 1
			&& v->map_y >= 0
			&& v->map_y <= map->height - 1
			&& map->map[v->map_y][v->map_x] == WALL)
			break;
	}
	if (v->side == AXIS_Y) 
		v->perp_wall_dist = (v->map_x - map->pos_x + (1 - v->step_x) / 2) / v->ray_dir_x;
	else
		v->perp_wall_dist = (v->map_y - map->pos_y + (1 - v->step_y) / 2) / v->ray_dir_y;
}

void	ray_casting(t_map *map)
{
	t_vector	v;
	int			i;

	clear_img(&map->img, map->info.c, map->info.f);
	i = -1;
	while(++i < WIN_W)
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
		draw_wall(map, &v, i);
	}
	mlx_put_image_to_window(map->mlx, map->win, map->img.img, 0, 0);
}

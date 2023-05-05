/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejkim <jaejkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:48:32 by hujeong           #+#    #+#             */
/*   Updated: 2023/05/05 15:21:58 by jaejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
int	get_xpm_texture_color(t_map *map, t_vector *v, int num)
{
	//아직 이해 못함
	if (v->side == AXIS_Y) 
		v->wall_x = map->pos_y + v->perp_wall_dist * v->ray_dir_y;
	else
		v->wall_x = map->pos_x + v->perp_wall_dist * v->ray_dir_x;
	wallX -= floor((wallX));
	//x coordinate on the texture
	int texX = int(wallX * double(texWidth));
	if(side == 0 && rayDirX > 0) texX = texWidth - texX - 1;
	if(side == 1 && rayDirY < 0) texX = texWidth - texX - 1;
	return (map->xpm[num].addr[v->wall_x]);
}

void	get_xpm_texture(t_map *map, t_vector *v)
{
	char *path;

	if (v->side == AXIS_X)
	{
		if (v->ray기dir_y < 0)
			path = map->info.no;
		else if (v->ray_dir_y >= 0)
			path = map->info.so;
	}
	else if(side == AXIS_Y)
	{
		if (v->ray_dir_x < 0)
			path = map->info.we;
		else if (v->ray_dir_x >= 0)
			path = map->info.ea;
	}
	// 밖에서 배열에 세팅하고 리턴값으로 고르기
	map->xpm->img = mlx_xpm_file_to_image(map->mlx, path, &xpm_wid, &xpm_hei);
	map->xpm->addr = mlx_get_data_addr(map->xpm->img, &(map->xpm->bits_per_pixel),
		&(map->xpm->line_length), &(map->xpm->endian));
}

void	draw_wall(t_map *map, t_vector *v)
{
	int line_height;
	int x;
	int y;

	line_height = WIN_H / v->perp_wall_dis;

	draw_start = WIN_H / 2 - line_height / 2;
	draw_end = WIN_H / 2 + line_height / 2;

	y = draw_start;
	double step = 1.0 * texHeight / lineHeight;
	int tex_pos = 0;
	while(++y < draw_end)
	{
		x = -1;
		while(++x < WIN_W)
		{
			tex_pos += step;
			get_xpm_texture(map, v);
			int num = get_xpm_texture_color(map, v);
			my_mlx_pixel_put(map->img->img, x, y, num);
		}
	}
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
			v->side = AXIS_Y;
		}
		else
		{
			v->side_dist_x += v->delta_dist_y;
			v->map_y += v->step_y;
			v->side = AXIS_X;
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
	mlx_clear_window(map->mlx, map->win);
	i = -1;
	while(++i < 1280)
	{
		v.camera_x = 2 * i / (double)1280 - 1;
		v.ray_dir_x = map->dir_x + map->plane_x * v.camera_x;
		v.ray_dir_y = map->dir_y + map->plane_y * v.camera_x;
		v.delta_dist_x = fabs(1 / v.ray_dir_x);
		v.delta_dist_y = fabs(1 / v.ray_dir_y);
		clear_img(map->img, map->info->c, map->info->f);
		set_side_dist(map, &v);
		check_side_dda(map, &v);
		draw_wall(map, &v);
	}
	mlx_put_image_to_window(map->mlx, map->win, map->img->img, 0, 0);
}

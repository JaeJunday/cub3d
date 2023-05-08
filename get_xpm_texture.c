/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_xpm_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:33:40 by hujeong           #+#    #+#             */
/*   Updated: 2023/05/08 09:49:46 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_xpm_texture_x(t_map *map, t_vector *v, t_img *xpm)
{
	if (v->side == AXIS_Y)
		v->wall_x = map->pos_y + v->perp_wall_dist * v->ray_dir_y;
	else
		v->wall_x = map->pos_x + v->perp_wall_dist * v->ray_dir_x;
	v->wall_x -= floor((v->wall_x));
	v->tex_x = (int)(v->wall_x * xpm->wid);
	if ((v->side == AXIS_Y && v->ray_dir_x > 0)
		|| (v->side == AXIS_X && v->ray_dir_y < 0))
		v->tex_x = xpm->wid - v->tex_x - 1;
}

int	get_xpm_texture_color(t_img *xpm, t_vector *v)
{
	int	*addr;
	int	index;

	addr = (int *)xpm->addr;
	index = v->tex_y * xpm->wid + (xpm->wid - v->tex_x) - 1;
	return (addr[index]);
}

int	get_xpm_texture(t_vector *v)
{
	if (v->side == AXIS_X)
	{
		if (v->ray_dir_y < 0)
			return (0);
		else if (v->ray_dir_y >= 0)
			return (2);
	}
	else if (v->side == AXIS_Y)
	{
		if (v->ray_dir_x < 0)
			return (3);
		else if (v->ray_dir_x >= 0)
			return (1);
	}
	return (true);
}

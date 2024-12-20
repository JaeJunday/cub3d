/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:20:20 by hujeong           #+#    #+#             */
/*   Updated: 2023/05/08 09:19:19 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_img(t_img *img, int c_color, int f_color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_H / 2)
	{
		j = 0;
		while (j < WIN_W)
		{
			my_mlx_pixel_put(img, j, i, c_color);
			++j;
		}
		++i;
	}
	while (i < WIN_H)
	{
		j = 0;
		while (j < WIN_W)
		{
			my_mlx_pixel_put(img, j, i, f_color);
			++j;
		}
		++i;
	}
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_mlx(t_map *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, WIN_W, WIN_H, "cub3D");
	map->img.img = mlx_new_image(map->mlx, WIN_W, WIN_H);
	map->img.addr
		= mlx_get_data_addr(map->img.img, &(map->img.bits_per_pixel),
			&(map->img.line_length), &(map->img.endian));
}

void	start(t_map *map)
{
	mlx_hook(map->win, WIN_DESTROY, 0, (void *)close_win, map);
	mlx_hook(map->win, KEYPRESS, 0, (void *)key_press, map);
	mlx_loop_hook(map->mlx, (void *)ray_casting, map);
	mlx_loop(map->mlx);
}

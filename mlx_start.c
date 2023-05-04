/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:20:20 by hujeong           #+#    #+#             */
/*   Updated: 2023/05/04 12:32:26 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > 1280 || y < 0 || y > 720)
		return ;
	dst = img->addr + (y * img->line_length
			+ x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_mlx(t_map *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, 1280, 720, "cub3D");
	map->img->img = mlx_new_image(map->mlx, 1280, 720);
	map->img->addr = mlx_get_vector_addr(map->img->img, 
		&(map->img->bits_per_pixel), &(map->img->line_length), &(map->img->endian));
}

void	main_loop(t_map *map)
{
	mlx_clear_window(map->mlx, map->win);
	ray_casting(map);
}

void	start(t_map *map)
{
	ft_mlx(map);

	mlx_hook(map->win, KEYPRESS, 0, func, map);
	mlx_loop_hook(map->mlx, main_loop, map);
	mlx_loop(map->mlx);
}
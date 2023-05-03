#include "cub3d.h"

void	ft_mlx(t_map *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, 1280, 720, "cub3D");
	map->img->img = mlx_new_image(map->mlx, 1280, 720);
	map->img->addr = mlx_get_data_addr(map->img->img, 
		&(map->img->bits_per_pixel), &(map->img->line_length), &(map->img->endian));
}


void	main_loop(t_map *map)
{
	clear_window();
	ray_casting(map);
	{
		double camera_x;
		double ray_dir_x;
		double ray_dir_y;
		double side_dist_x;
		double side_dist_y;
		double delta_dist_x;
		double delta_dist_y;
		int map_x;
		int map_y;
		int step_x;
		int step_y;

		map_x = (int)map->pos_x;
		map_y = (int)map->pos_y;
		int i = -1;
		while(++i < 1280)
		{
			camera_x = 2 * i / (double)1280 - 1;
			ray_dir_x = map->dir_x + map->plane_x * camera_x;
			ray_dir_y = map->dir_y + map->plane_y * camera_x;			

			delta_dist_x = fabs(1/ray_dir_x);
			delta_dist_y = fabs(1/ray_dir_y);
			if (ray_dir_x < 0)
			{
				step_x = -1;
				side_dist_x = (pos_x - map_x) * delta_dist_x;
			}
			else
			{
				step_x = 1;
				side_dist_x = (map_x + 1 - pos_x) * delta_dist_x;
			}
			if (ray_dir y < 0)
			{
				step_y = -1;
				side_dist_y = (pos_y - map_y) * delta_dist_y;
			}
			else
			{
				step_y = 1;
				side_dist_y = (map_y + 1 - pos_y) * delta_dist_y;
			}
			dda (벽에 히트될때까지, 어느 벽이 먼저 만나는지)
			{
				int side;

				while(1)
				{
					if (side_dist_x < side_dist_y)
					{
						side_dist_x += delta_dist_x;
						map_x += step_x;
						side = 0;
					}
					else
					{
						side_dist_y += delta_dist_y;
						map_y += step_y;
						side = 1;
					}
					if (map->map[map_x][map_y] == '1')
						break;
				}
				if (side == 0) 
					perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
                else
                    perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;
			}
			draw_img(map);
		}
		mlx_put_image_to_window(map->mlx, map->win, map->img->img, 0, 0);
	}
}

void	start(t_map *map)
{
	ft_mlx(map);

	mlx_hook(map->win, KEYPRESS, 0, func, map);
	mlx_loop_hook(map->mlx, main_loop, map);
	mlx_loop(map->mlx);
}
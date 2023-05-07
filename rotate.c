#include "cub3d.h"

double	radian(double angle)
{
	return (angle * PI / 180);
}

void	rotate(t_map *map, int dir)
{
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;

	dir_x = map->dir_x;
	dir_y = map->dir_y;
	plane_x = map->plane_x;
	plane_y = map->plane_y;
	map->dir_x = \
	cos(radian(ANGLE * dir)) * dir_x - sin(radian(ANGLE * dir)) * dir_y;
	map->dir_y = \
	sin(radian(ANGLE * dir)) * dir_x + cos(radian(ANGLE * dir)) * dir_y;
	map->plane_x = \
	cos(radian(ANGLE * dir)) * plane_x - sin(radian(ANGLE * dir)) * plane_y;
	map->plane_y = \
	sin(radian(ANGLE * dir)) * plane_x + cos(radian(ANGLE * dir)) * plane_y;
}

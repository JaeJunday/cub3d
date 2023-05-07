#ifndef CUB3D_H
#define CUB3D_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include <mlx.h>
#include "libft/libft.h"
#include "libft/gnl.h"

#define KEYPRESS 2
#define WIN_DESTROY 17
#define ESC 53
#define AXIS_X	0
#define AXIS_Y	1
#define WIN_H 1200
#define WIN_W 2200
#define ANGLE 3
#define SPEED 0.2
#define WALL '1'
#define AISLE '2'
#define PLAIN 0.66

#define PI 3.141592

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef enum e_key
{
	w_key = 13,
	a_key = 0,
	s_key = 1,
	d_key = 2,
	up_key = 126,
	left_key = 123,
	down_key = 125,
	right_key = 124
}	t_key;

typedef struct s_flag
{
	t_bool	no;
	t_bool	so;
	t_bool	we;
	t_bool	ea;
	t_bool	f;
	t_bool	c;
}	t_flag;

typedef struct s_map_info
{
	int		f;
	int		c;
}	t_map_info;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		wid;
	int		hei;
}t_img;

typedef struct s_map
{
	t_map_info	info;
	t_list		*tmp;
	t_list		*tmp_tail;
	char		**map;
	void		*mlx;
	void		*win;
	t_img		img;
	t_img		xpm[4];
	int			width;
	int			height;
	int			position;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}	t_map;

typedef struct s_vector
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	int		side;
}	t_vector;

//-----------------------<parsing>----------------------
//main.c
int 	arg_check(int argc, char **argv);
int 	parse_map(char **argv, t_map *map);
//check_dfs.c
void	check_dfs_map(t_map *map);
void 	dfs_map(t_map *map, int x, int y, t_bool *flag);
int		move_map(t_map *map, int y, int x, t_bool *flag);
//check_line.c
int 	check_line(char *line, t_map *map);
t_bool	check_info(t_flag flag);
//get_map_data.c
void	get_map_data(char *line, t_map *map);
void	check_map_line(char *line, t_map *map, int pos_y, int i);
int		skip_line(char *line);
//get_map_info.c
void	get_map_info(char *line, t_map *map, t_flag *flag);
void	set_map_info(char **info, t_map *map, t_flag *flag);
void	set_map_info_wall(t_img *xpm, t_bool *flag, char **info, t_map *map);
void	set_map_info(char **info, t_map *map, t_flag *flag);
//make_map_array.c
void	check_map(t_map *map);
void	make_map_array(t_map *map);
void	copy_content(char *src, char *map, int width);
//error.c
int		map_error(t_map *map);
void	malloc_error(void);
void	format_error(char **info);
//free_split.c
int  	free_split(char **str);

//-----------------------<ray_casting>----------------------
//mlx_start.c
void	start(t_map *map);
void	ft_mlx(t_map *map);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	clear_img(t_img *img, int c_color, int f_color);
//ray_casting.c
void	ray_casting(t_map *map);
void	check_side_dda(t_map *map, t_vector *v);
void	set_side_dist(t_map *map, t_vector *v);
void	draw_wall(t_map *map, t_vector *v, int x);
int	get_xpm_texture(t_vector *v);
void	get_xpm_texture_x(t_map *map, t_vector *v, t_img *xpm);
//mlx_hook.c
int		key_press(int key, t_map *map);
void	move_right_left(t_map *map, int dir);
void	move_up_down(t_map *map, int dir);
void	close_win(t_map *map);
//rotate.c
void	rotate(t_map *map, int dir);
double	radian(double angle);

#endif
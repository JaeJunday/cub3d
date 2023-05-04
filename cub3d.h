#ifndef CUB3D_H
#define CUB3D_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <mlx.h>
#include "libft/libft.h"
#include "libft/gnl.h"

#define KEYPRESS 2
#define AXIS_X	0
#define AXIS_Y	1

typedef enum e_bool
{
	false,
	true
}	t_bool;

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
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_map_info;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_img;

typedef struct s_map
{
	t_map_info	info;
	t_list		*tmp;
	char		**map;
	char		**test_map;
	void		*mlx;
	void		*win;
	t_img		*img;
	int			width;
	int			height;
	int			positon;
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
	int		side;
}	t_vector;

//main.c
int arg_check(int argc, char **argv);
int parse_map(char **argv, t_map *map);
//check_dfs.c
void check_map(t_map *map);
void dfs_map(t_map *map, double pos_x, double pos_y, t_bool *flag);
int	move_map(char ***map, t_map *info, t_bool *flag);
//check_line.c
int 	check_line(char *line, t_map *map);
t_bool	check_info(t_flag flag);
//get_map_data.c
void	get_map_data(char *line, t_map *map);
void	check_map_line(char *line, t_map *map, int pos_y, int i);
int		skip_line(char *line);
void	make_map_array(t_map *map, int size, int i);
void	copy_content(char *str, t_map *map, int i);
//get_map_info.c
void	get_map_info(char *line, t_map *map, t_flag *flag);
void	set_map_info(char **info, t_map *map, t_flag *flag);
void	set_map_info_wall(char **wall, t_bool *flag, char **info, t_map *map);
int		set_map_info_bg(int *color, t_bool *flag, char **info, t_map *map);
//error.c
void	map_error(t_map *map);
void	malloc_error(void);
void	format_error(char **info, t_map *map);
//free_split.c
int  	free_split(char **str);
#endif
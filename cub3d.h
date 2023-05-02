#ifndef CUB3D_H
#define CUB3D_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "libft/gnl.h"

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

typedef struct s_map
{
	t_list		*tmp;
	char		**map;
	char		**test_map;
	t_map_info	info;
	int			width;
	int			height;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	int			valid_flag;
}	t_map;

//main.c
int arg_check(int argc, char **argv);
int parse_map(char **argv, t_map *map);
//check_dfs.c
t_bool	check_map(t_map *map);
void dfs_map(t_map *map, double pos_x, double pos_y);
int		move_map(char ***map, t_map *info, int y, int x);
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
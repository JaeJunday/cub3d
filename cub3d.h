#ifndef CUB3D_H
#define CUB3D_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>


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

typedef struct s_map_list
{
	int					*map;
	struct s_map_list	*next;
}	t_map_list;

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
	t_map_list	*tmp;
	int			**map;
	int			**test_map;
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

#endif
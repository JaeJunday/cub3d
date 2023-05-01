#ifndef CUB3D_H
#define CUB3D_H

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_flag
{
	t_bool	north;
	t_bool	south;
	t_bool	west;
	t_bool	east;
	t_bool	floor;
	t_bool	ceiling;
}	t_flag;

typedef struct s_map
{
    int **map;
    int width;
    int height;
    double pos_x;
    double pos_y;
    double dir_x;
	double dir_y;
}	t_map;

#endif
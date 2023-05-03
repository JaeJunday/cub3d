#include "cub3d.h"

int  free_split(char **str)
{
	int i;

	i = -1;
	while(str[++i])
		free(str[i]);
	free(str);
	return (true);
}
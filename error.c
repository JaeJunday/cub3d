/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:48:23 by hujeong           #+#    #+#             */
/*   Updated: 2023/05/04 12:32:20 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	malloc_error(void)
{
	printf("Error : memory allocation failed");
	exit(EXIT_FAILURE);
}

void	map_error(t_map *map)
{
	ft_lstclear(&map->tmp, free);
	free(map->info.no);
	free(map->info.so);
	free(map->info.ea);
	free(map->info.we);
	printf("Error : invalid map\n");
	exit(EXIT_FAILURE);
}

void	format_error(char **info, t_map *map)
{
	free_split(info);
	if (map->info.no)
		free(map->info.no);
	if (map->info.so)
		free(map->info.so);
	if (map->info.we)
		free(map->info.we);
	if (map->info.ea)
		free(map->info.ea);
	printf("Error : invalid format\n");
	exit(EXIT_FAILURE);
}

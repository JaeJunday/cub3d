/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejkim <jaejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:48:23 by hujeong           #+#    #+#             */
/*   Updated: 2023/05/04 20:49:40 by jaejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	malloc_error(void)
{
	printf("Error : memory allocation failed");
	exit(EXIT_FAILURE);
}

int	map_error(t_map *map)
{
	ft_lstclear(&map->tmp, free);
	printf("Error : invalid map\n");
	exit(EXIT_FAILURE);
}

void	format_error(char **info)
{
	free_split(info);
	printf("Error : invalid format\n");
	exit(EXIT_FAILURE);
}

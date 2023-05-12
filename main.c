/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:48:29 by hujeong           #+#    #+#             */
/*   Updated: 2023/05/08 09:21:14 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	arg_check(int argc, char **argv)
{
	int	len;

	if (argc != 2)
		return (printf("Error: argument error\n"));
	len = ft_strlen(argv[1]);
	if (len < 5
		|| argv[1][len - 4] != '.'
		|| argv[1][len - 3] != 'c'
		|| argv[1][len - 2] != 'u'
		|| argv[1][len - 1] != 'b')
		return (printf("Error: argument error\n"));
	return (0);
}

int	parse_map(char **argv, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (printf("Error: file open error\n"));
	line = get_next_line(fd);
	while (line)
	{
		check_line(line, map);
		line = get_next_line(fd);
	}
	close(fd);
	check_map(map);
	make_map_array(map);
	check_dfs_map(map);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (arg_check(argc, argv))
		return (1);
	ft_memset(&map, 0, sizeof(t_map));
	ft_mlx(&map);
	parse_map(argv, &map);
	start(&map);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:21:26 by hujeong           #+#    #+#             */
/*   Updated: 2023/05/04 14:17:01 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int key, t_map *map)
{
	if (key == w_key || key == up_key)
		move_position(w_key, map);
	else if (key == s_key || key == down_key)
		move_position(a_key, map);
	else if (key == a_key)
		move_position(s_key, map);
	else if (key == d_key)
		move_position(w_key, map);
	else if (key == left_key)
		rotate_dir(left_key, map);
	else if (key == right_key)
		rotate_dir(right_key, map);
}

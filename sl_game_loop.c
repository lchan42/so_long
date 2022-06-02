/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <lchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:27:32 by lchan             #+#    #+#             */
/*   Updated: 2022/06/02 23:43:09 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static void	__put_image(t_data *data, void *img_ptr, int x, int y)
{
	if (img_ptr)
		mlx_put_image_to_window(
			data->mlx_ptr,
			data->mlx_win,
			img_ptr,
			x * IMG_X,
			y * IMG_Y
			);
	//else
	//	free all;
}

static int	__can_i_go(t_data *data, char map_elem)
{
	if (map_elem == '1' || (map_elem == 'E' && data->p.coin))
		return (0);
	return (1);
}

static void	__mvt_player(t_data *data, int mvt, int target_x, int target_y)
{
	char map_elem;

	map_elem = data->map[target_y][target_x];
	if (__can_i_go(data, map_elem))
	{
		if (map_elem == 'C')
		{
			data->p.coin--;
			data->map[target_y][target_x] = '0';
		}
		__put_image(data, data->img[GROUND].ptr, data->p.x, data->p.y);
		if (mvt == P_UP || mvt == P_DOWN)
			data->p.y = target_y;
		else if (mvt == P_RIGHT || mvt == P_LEFT)
			data->p.x = target_x;
	}
	__put_image(data, data->img[mvt].ptr, data->p.x, data->p.y);
	if (data->map[data->p.y][data->p.x] == 'E')
	{
		ft_putstr_fd("bravo\n", 2);
		mlx_loop_end(data->mlx_ptr);
	}
}

static int	__game_move(int key, t_data *data)
{
	if (key == W_U || key == ARW_U)
		__mvt_player(data, P_UP, data->p.x, data->p.y -1);
	else if (key == S_D || key == ARW_D)
		__mvt_player(data, P_DOWN, data->p.x, data->p.y +1);
	else if (key == D_R || key == ARW_R)
		__mvt_player(data, P_RIGHT, data->p.x + 1, data->p.y);
	else if (key == A_L || key == ARW_L)
		__mvt_player(data, P_LEFT, data->p.x - 1, data->p.y);
	else if (key == ESC)
		mlx_loop_end(data->mlx_ptr);
	return (0);
}

void	__game_loop(t_data *data)
{
	mlx_key_hook(data->mlx_win, __game_move, data);
	mlx_hook(data->mlx_win, WIN_RED_CROSS, 0, mlx_loop_end, data->mlx_ptr);
	mlx_loop(data->mlx_ptr);
}

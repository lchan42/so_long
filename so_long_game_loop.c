/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <lchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:27:32 by lchan             #+#    #+#             */
/*   Updated: 2022/06/01 16:30:08 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	__game_move(int key, t_data *data)
{
	if (key == W_U || key == ARW_U)
		printf("go up\n");
	else if (key == S_D || key == ARW_D)
		printf("go down\n");
	else if (key == D_R || key == ARW_R)
		printf("go right\n");
	else if (key == A_L || key == ARW_L)
		printf("go left\n");
	else if (key == ESC)
		mlx_loop_end(data->mlx_ptr);
	return (0
	);
}

void	__game_loop(t_data *data)
{
	mlx_key_hook(data->mlx_win, __game_move, data);
	mlx_hook(data->mlx_win, WIN_RED_CROSS, 0, mlx_loop_end, data->mlx_ptr);
	mlx_loop(data->mlx_ptr);
}

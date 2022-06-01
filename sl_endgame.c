/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_endgame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <lchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:19:35 by lchan             #+#    #+#             */
/*   Updated: 2022/06/01 17:43:37 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	__endimage(t_data *data, t_img *img)
{
	mlx_destroy_image(data->mlx_ptr, img[GROUND].ptr);
	/*mlx_destroy_image(data->mlx_ptr, img[P_UP].ptr);
	mlx_destroy_image(data->mlx_ptr, img[P_DOWN].ptr);
	mlx_destroy_image(data->mlx_ptr, img[P_RIGHT].ptr);
	mlx_destroy_image(data->mlx_ptr, img[P_LEFT].ptr);
	mlx_destroy_image(data->mlx_ptr, img[WALL].ptr);
	mlx_destroy_image(data->mlx_ptr, img[COIN].ptr);
	mlx_destroy_image(data->mlx_ptr, img[EXIT].ptr);*/
}

void	__endgame(t_data *data)
{
	__sl_free_tab(data->map);
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	__endimage(data, data->img);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_endgame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <lchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:19:35 by lchan             #+#    #+#             */
/*   Updated: 2022/06/06 13:25:48 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	__put_err_msg(int error_code)
{
	const char	*err_msg[] = {
	[UNVALID_MAP] = "unvalid map\n",
	[MLX_INIT_FAIL] = "mlx init error\n",
	[WIN_INIT_FAIL] = "mlx window error\n",
	[MLX_XPM_FAIL] = "failure in creating new image\n"
	};
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd((char *)err_msg[error_code], 2);
}

void	__endimage(t_data *data, t_img *img)
{
	int	i;

	i = -1;
	while (++i < SPRITES_CNT)
		if (img[i].ptr != NULL)
			mlx_destroy_image(data->mlx_ptr, img[i].ptr);
}

void	__endgame(t_data *data)
{
	if (data->map)
		__sl_free_tab(data->map);
	if (data->mlx_win)
		mlx_clear_window(data->mlx_ptr, data->mlx_win);
	__endimage(data, data->img);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}

void	__endgame_exit(t_data *data, int error_code)
{
	__put_err_msg(error_code);
	__endgame(data);
	exit(EXIT_FAILURE);
}

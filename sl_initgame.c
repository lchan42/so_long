/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_initgame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <lchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:13:23 by lchan             #+#    #+#             */
/*   Updated: 2022/06/02 00:05:17 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
static void	__set_t_img_zero(t_img *img)
{
	img->ptr = NULL;
	img->path = NULL;
	img->bpp = -1;
	img->width = -1;
	img->height = -1;
	img->endian = -1;
}*/

static void	__set_t_data_null(t_data *data)
{
	int	i;

	i = -1;
	data->map = NULL;
	data->win_x = -1;
	data->win_y = -1;
	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
	while (++i < SPRITES_CNT)
	{
		data->img[i].ptr = NULL;
		data->img[i].path = NULL;
		data->img[i].bpp = -1;
		data->img[i].width = -1;
		data->img[i].height = -1;
		data->img[i].endian = -1;
	}
}

static int	__map_height(char **map)
{
	int	i;

	i= 0;
	while (map[i])
		i++;
	return(i);
}

static void	__mlx_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		__endgame_exit(data, MLX_INIT_FAIL);
}

static void __win_init(t_data *data)
{
	data->win_x = ft_strlen(data->map[0]) * IMG_X;
	data->win_y = __map_height(data->map) * IMG_Y;
	data->mlx_win = mlx_new_window(
		data->mlx_ptr,
		data->win_x,
		data->win_y,
		WINDOW_NAME);
	if (!data->mlx_win)
		__endgame_exit(data, WIN_INIT_FAIL);
}

void	__initgame(t_data *data, char *file)
{
	__set_t_data_null(data);
	data->map = __mapparser(file);
	if (!data->map)
		ft_puterror_exit(SO_LONG_ERROR);
	__mlx_init(data);
	__win_init(data);
	__img_init(data, data->img);
}


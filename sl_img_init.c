/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_img_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <lchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:10:59 by lchan             #+#    #+#             */
/*   Updated: 2022/06/02 00:11:58 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	__add_path(t_img *img, int type)
{
	const char	*tab[] = {
	[P_UP] = P_UP_PATH,
	[P_DOWN] = P_DOWN_PATH,
	[P_RIGHT] = P_RIGHT_PATH,
	[P_LEFT] = P_LEFT_PATH,
	[GROUND] = GROUND_PATH,
	[WALL] = WALL_PATH,
	[COIN] = COIN_PATH,
	[EXIT] = EXIT_PATH
	};

	img->path = (char *)tab[type];
}

static int	__file_to_img(t_data *data, t_img *img)
{
	img->ptr = mlx_xpm_file_to_image(
			data->mlx_ptr,
			img->path,
			&img->width,
			&img->height
			);
	if (img->ptr == NULL)
		return (-1);
	return (1);
}

void	__img_init(t_data *data, t_img *img)
{
	int	i;

	i = -1;
	while (++i < SPRITES_CNT)
	{
		__add_path(&img[i], i);
		if (__file_to_img(data, &img[i]) == -1)
			__endgame_exit(data, MLX_XPM_FAIL);
	}
}

/*	i = -1;
	while (++i < SPRITES_CNT)
		if (__file_to_img(data, &img[i]) == -1)
			__endgame_exit(data, MLX_XPM_FAIL);*/

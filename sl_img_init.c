/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_img_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <lchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:10:59 by lchan             #+#    #+#             */
/*   Updated: 2022/06/01 18:43:16 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	__add_path(t_img *img, int type)
{
	const char	*tab[] = {
	[P_UP]		 = P_UP_PATH,
	[P_DOWN]	 = P_DOWN_PATH,
	[P_RIGHT]	 = P_RIGHT_PATH,
	[P_LEFT]	 = P_LEFT_PATH,
	[GROUND]	 = GROUND_PATH,
	[WALL]		 = WALL_PATH,
	[COIN]		 = COIN_PATH,
	[EXIT]		 = EXIT_PATH
	};

	img->path = (char *)tab[type];
}


static int	__file_to_img(t_data *data, t_img *img, int type)
{
	img[type].ptr = mlx_xpm_file_to_image(
		data->mlx_ptr,
		img[type].path,
		&img[type].width,
		&img[type].height
		);
	if (img[type].ptr == NULL)
		return (-1);
	return (1);
}

void	__img_init(t_data *data, t_img *img)
{
	int	i;

	i = -1;
	while (++i < SPRITES_CNT)
			__add_path(img, i);
	i = -1;
	while (++i < SPRITES_CNT)
		if (__file_to_img(data, img, i) == -1)
			printf("ERROR\n");
	//__add_path(&img[GROUND], GROUND);
	__file_to_img(data, img, GROUND);
	//printf("the path of ground is %s\n", img[GROUND].path);

	//printf("image pointer = %p\n", img[GROUND].ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img[GROUND].ptr, 0, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img[GROUND].ptr, 32, 32);
	/*mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img[GROUND].ptr, 0, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img[GROUND].ptr, 0, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img[GROUND].ptr, 0, 0);
*/
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_display_imgs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <lchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:43:53 by lchan             #+#    #+#             */
/*   Updated: 2022/06/02 16:54:39 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	__map_cursor(char **map, int *x, int *y)
{
	if (map[*y] && map[*y][*x + 1] != '\n')
		(*x)++;
	else
	{
		(*y)++;
		*x = 0;
	}
}

static void	*__get_corresponding_img_ptr(t_img *img, char c)
{
	if (c == '0')
		return (img[GROUND].ptr);
	else if (c == '1')
		return (img[WALL].ptr);
	else if (c == 'C')
		return (img[COIN].ptr);
	else if (c == 'E')
		return (img[EXIT].ptr);
	else if (c == 'P')
		return (img[P_RIGHT].ptr);
	return (NULL);
}

static void	__init_t_player(t_data *data, char c, int x, int y)
{
	if (c == 'P')
	{
		data->p.x = x;
		data->p.y = y;
	}
	else if (c == 'C')
		data->p.coin++;
}

static void	__put_image(t_data *data, int x, int y)
{
	void	*img_ptr;
	char	c;

	c = data->map[y][x];
	__init_t_player(data, c, x, y);
	img_ptr = __get_corresponding_img_ptr(data->img, c);
	if (img_ptr)
		mlx_put_image_to_window(
			data->mlx_ptr,
			data->mlx_win,
			img_ptr,
			x * IMG_X,
			y * IMG_Y
			);
}
/**********************************************************
 * it's kind of dirty but I'm initializing t_player here;
 * ********************************************************/

void	__display_imgs(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		__put_image(data, x, y);
		__map_cursor(data->map, &x, &y);
	}
}

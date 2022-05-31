/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_initgame.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <lchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:13:23 by lchan             #+#    #+#             */
/*   Updated: 2022/05/31 18:26:03 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	{
		__sl_free_tab(data->map);
		ft_puterror_exit(SO_LONG_ERROR);
	}
}

static void __win_init(t_data *data)
{
	data->win_x = ft_strlen(data->map[0]) * IMG_X;
	data->win_y = __map_height(data->map) * IMG_Y;
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->win_x, data->win_y, WINDOW_NAME);
	if (!data->mlx_win)
	{
		__sl_free_tab(data->map);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		ft_puterror_exit (SO_LONG_ERROR);
	}
}

void	__initgame(t_data *data, char *file)
{
	data->map = __mapparser(file);
	if (!data->map)
		ft_puterror_exit(SO_LONG_ERROR);
	__mlx_init(data);
	__win_init(data);
}

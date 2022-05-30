/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <lchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:38:45 by lchan             #+#    #+#             */
/*   Updated: 2022/05/30 20:47:57 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
static void	sl_mlx_init(void **mlx_ptr, void **mlx_win)
{
	*mlx_ptr = mlx_init();
	if (!*mlx_ptr)
		ft_puterror_exit(SO_LONG_ERROR);
	*mlx_win = mlx_new_window(*mlx_ptr, 700, 300, "My first window");
	if (!*mlx_win)
	{
		mlx_destroy_display(*mlx_ptr);
		free(*mlx_ptr);
		ft_puterror_exit (SO_LONG_ERROR);
	}
}

int	main(int ac, char **av)
{
	char	**map;
	void	*mlx_ptr;
	void	*mlx_win;

	if (ac < 2)
		return (0);
	map = __mapparser(av[1]);
	vis_printmap_tab(map);
	__sl_free_tab(map);
	sl_mlx_init(&mlx_ptr, &mlx_win);
	//mlx_pixel_put(mlx_ptr, mlx_win, 700, 300, 0xFF0000);
	sleep(3);
	 mlx_destroy_display(mlx_ptr);
	if (mlx_ptr)
		free(mlx_ptr);
	printf("end of function");
	return (0);
}*/

void	__endgame(t_data *data)
{
	__sl_free_tab(data->map);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 2)
		return (0);
	__initgame(&data, av[1]);
	vis_struct(&data);

	mlx_pixel_put(data.mlx_ptr, data.mlx_win, data.win_x/2, data.win_y/2, 0xFF0000);
	sleep(1);
	__endgame(&data);
	return (0);
}


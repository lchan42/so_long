/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <lchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:38:45 by lchan             #+#    #+#             */
/*   Updated: 2022/05/31 17:02:32 by lchan            ###   ########.fr       */
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

int	__game_move(int key, t_data *data)
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
	{
		printf("key %d pressed\n", key);
		mlx_loop_end(data->mlx_ptr);
	}
	return (0);
}

void	__game_loop(t_data *data)
{
	mlx_key_hook(data->mlx_win, __game_move, data);
	// mlx_mouse_hook(data->mlx_win, __game_move, (void *)0);
	// printf("starting to loop\n");
	mlx_loop(data->mlx_ptr);
	// printf("stop_looping\n");
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 2)
		return (0);
	__initgame(&data, av[1]);
	vis_struct(&data);
	__game_loop(&data);
	__endgame(&data);
	return (0);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <lchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:38:45 by lchan             #+#    #+#             */
/*   Updated: 2022/05/27 19:15:57 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_perror_exit(char *str)
{
	perror(str);
	exit(errno);
}

/*
static void	sl_mlx_init(void **mlx_ptr, void **mlx_win)
{
	*mlx_ptr = mlx_init();
	if (!*mlx_ptr)
		ft_perror_exit(SO_LONG_ERROR);
	*mlx_win = mlx_new_window(*mlx_ptr, WIN_W, WIN_H, "My first window");
	if (!*mlx_win)
	{
		mlx_destroy_display(*mlx_ptr);
		free(*mlx_ptr);
		ft_perror_exit (SO_LONG_ERROR);
	}
}
*/
int	main(int ac, char **av)
{
//	void	*mlx_ptr;
//	void	*mlx_win;

	if (ac < 2)
		return (0);
	__mapparser(av[1]);
/*	sl_mlx_init(&mlx_ptr, &mlx_win);
	mlx_pixel_put(mlx_ptr, mlx_win, WIN_W/2, WIN_H/2, 0xFF0000);
	sleep(3);
	mlx_destroy_display(mlx_ptr);
	if (mlx_ptr)
		free(mlx_ptr);
	printf("end of function");*/
	return (0);
}

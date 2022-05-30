/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <lchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:38:45 by lchan             #+#    #+#             */
/*   Updated: 2022/05/30 19:18:32 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_perror_exit(char *str)
{
	perror(str);
	exit(errno);
}



/*
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
	mlx_pixel_put(mlx_ptr, mlx_win, WIN_W/2, WIN_H/2, 0xFF0000);
	sleep(3);
	 mlx_destroy_display(mlx_ptr);
	if (mlx_ptr)
		free(mlx_ptr);
	printf("end of function");
	return (0);
}
*/



void	__endgame(t_data *data)
{
	__sl_free_tab(data->map);
	mlx_destroy_display(data->mlx_ptr);
	if (data->mlx_ptr)
		free(mlx_ptr);
}

int	main(int ac, char **av)
{
	t_data	data;
//	char	**map;
//	void	*mlx_ptr;
//	void	*mlx_win;

	if (ac < 2)
		return (0);
	__initgame(&data, av[1]);

	vis_printmap_tab(data.map);

	sl_mlx_init(&mlx_ptr, &mlx_win);

	mlx_pixel_put(mlx_ptr, mlx_win, WIN_W/2, WIN_H/2, 0xFF0000);
	sleep(3);
	return (0);
}

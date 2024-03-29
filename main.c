/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <lchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:38:45 by lchan             #+#    #+#             */
/*   Updated: 2022/06/06 16:10:51 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (ac < 2)
		ft_puterror_exit("Error\na map is needed\n");
	if (*envp == NULL)
		ft_puterror_exit("Error\nno envp\n");
	__initgame(&data, av[1]);
	__display_imgs(&data);
	__game_loop(&data);
	__endgame(&data);
	return (0);
}

//	vis_struct(&data);
/**************************************************************************
 * int	mlx_loop ( void *mlx_ptr );
 * 		--> check / wait for event;
 * int	mlx_key_hook ( void *win_ptr, int (*funct_ptr)(), void *param );
 * 		--> called if event is a key press;
 * int	mlx_mouse_hook ( void *win_ptr, int (*funct_ptr)(), void *param );
 * 		--> called if event is a mouse clic or move;
 * int	mlx_expose_hook ( void *win_ptr, int (*funct_ptr)(), void *param );
 * 		-->	called if event is linked to window (?)
 * int	mlx_loop_hook ( void *mlx_ptr, int (*funct_ptr)(), void *param );
 * 		--> called when no event occure
 * ************************************************************************/


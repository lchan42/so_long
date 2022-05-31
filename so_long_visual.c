/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_visual.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <lchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:53:37 by lchan             #+#    #+#             */
/*   Updated: 2022/05/31 18:36:17 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	vis_printmap_lst(t_list *lst)
{
	int	i;

	i = -1;
	while (lst)
	{
		printf("%3d : %s", ++i, (char *)lst->content);
		lst = lst->next;
	}
}

void	vis_printmap_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		printf("%3d : %s", i, tab[i]);
}

void	vis_struct(t_data *data)
{
	printf("map address = %p\n", data->map);
	vis_printmap_tab(data->map);
	printf("win_x = %d, win_y = %d\n", data->win_x, data->win_y);
	printf("mlx_ptr = %p\n", data->mlx_ptr);
	printf("mlx_win = %p\n", data->mlx_win);
}

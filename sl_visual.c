/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <lchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:53:37 by lchan             #+#    #+#             */
/*   Updated: 2022/06/06 14:55:44 by lchan            ###   ########.fr       */
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

void	vis_img_struct(t_img *img)
{
	printf("image : %s\n", img->path);
	printf("ptr = %p\n", img->ptr);
	printf("bpp = %d\n", img->bpp);
	printf("width = %d\n", img->width);
	printf("height = %d\n", img->height);
	printf("endian = %d\n", img->endian);
	printf("\n");
}

void	vis_all_imgs(t_img *img)
{
	int	i;

	i = -1;
	while (++i < SPRITES_CNT)
		vis_img_struct(&img[i]);
}

void	vis_p(t_player p)
{
	printf("p.mvt = %d\n", p.mvt);
	printf("p.coin = %d\n", p.coin);
	printf("p.x = %d\n", p.x);
	printf("p.y = %d\n", p.y);
}

void	vis_struct(t_data *data)
{
	printf("map address = %p\n", data->map);
	vis_printmap_tab(data->map);
	printf("win_x = %d, win_y = %d\n", data->win_x, data->win_y);
	printf("mlx_ptr = %p\n", data->mlx_ptr);
	printf("mlx_win = %p\n", data->mlx_win);
	vis_p(data->p);
	vis_all_imgs(data->img);
}

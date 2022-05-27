/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_visual.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <lchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:53:37 by lchan             #+#    #+#             */
/*   Updated: 2022/05/26 13:03:47 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	vis_printmap_lst(t_list *lst)
{
	int i;

	i = -1;
	printf("number of line = %d\n", sl_lst_nodcnt(lst));
	while (lst)
	{
		printf("%3d : %s", ++i, (char *)lst->content);
		lst = lst->next;
	}
}

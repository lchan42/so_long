/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_lst_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <lchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:01:41 by lchan             #+#    #+#             */
/*   Updated: 2022/05/27 20:13:42 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	__sl_free_lst(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}

int	sl_lst_nodcnt(t_list *lst)
{
	int	i;

	i = 0;
	while (lst && ++i)
		lst = lst->next;
	return (i);
}

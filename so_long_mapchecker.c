/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mapchecker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <lchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:35:51 by lchan             #+#    #+#             */
/*   Updated: 2022/05/27 17:09:15 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	__linecheck_edges(char	*str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] != '1')
			return (-1);
	return (i);
}

void	__vital_flag(char c, int *vital_flag)
{
	if (c == 'C')
		*vital_flag |= C;
	else if (c == 'E')
		*vital_flag |= E;
	else if (c == 'P')
		*vital_flag |= P;
}

int	__linecheck_inter(char *str, int *vital_flag)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(str);
	while (str[++i])
	{
		__vital_flag(str[i], vital_flag);
		if (i == 0 && str[i] != '1')
			return (-1);
		else if (i + 1 == len && str[i] != '1')
			return (-1);
		else if (ft_strchr_boolean(MAP_CHAR, str[i] == 0))
			return (-1);
	}
	return (i);
}

void	__mapchecker(t_list *lst)
{
	int	y;
	int x;
	int	vital_flag;

	y = 1;
	x = __linecheck_edges((char *) lst->content);
	if (x < 3)
		return (-1);
	lst = lst->next;
	while (lst && y++)
	{
		if (!lst->next && x != __linecheck_edges((char *) lst->content))
			return (-1);
		else if (lst->next && x != __linecheck_inter((char *)lst->content, &vital_flag) == -1)
			return (-1);
		lst = lst->next;
	}
	if (vital_flag != C + E + P)
		return (-1);
	return (y);
}
/********************************************
 * return: the number of nod in the list for futur malloc;
 * error: return -1
 * declared value : x = len of line 1 / y = nod cnt / vital_flag = minimum 
 * in order:
 * 		check if fist_line is full of 1;
 * 		check if inter_line have 1 on edges
 * 		add value to vital_flag via | (bitwise or);
 * 		check if vital_flag has all required bit on;
 * 		return (nbr nod);
 * ******************************************/

void	sl_read_save_map(char *file)
{
	int		map_fd;
	char	*gnl;
	t_list	*map_head;

	map_head = NULL;
	map_fd = open(file, O_RDONLY);
	if (map_fd == -1)
		exit(UNVALID_MAP);
	while (1)
	{
		gnl = get_next_line(map_fd);
		if (!gnl)
			break ;
		else
			ft_lstadd_back(&map_head, ft_lstnew(gnl));
	}
	sl_mapchecker(map_head);
	vis_printmap_lst(map_head);
	if (map_head)
		sl_free_lst(map_head);
	close(file);
}

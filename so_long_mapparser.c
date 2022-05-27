/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mapparser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <lchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:02:34 by lchan             #+#    #+#             */
/*   Updated: 2022/05/27 19:56:39 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*__read_save_map(char *file)
{
	int		map_fd;
	char	*gnl;
	t_list	*map_head;

	map_head = NULL;
	map_fd = open(file, O_RDONLY);
	while (map_fd != -1)
	{
		gnl = get_next_line(map_fd);
		if (!gnl)
			break ;
		else
			ft_lstadd_back(&map_head, ft_lstnew(gnl));
	}
	if (map_fd != -1)
		close(map_fd);
	return (map_head);
}

int	__file_is_ber(char *file)
{
	int		dot;
	char	*tmp;

	dot = ft_find_last_c_occurence(file, '.');
	tmp = file + dot;
	if (dot == 0 || ft_strncmp(tmp, "ber", 4) != 0)
		return (-1);
	return (1);
}

void	__mapparser(char *file)
{
	t_list	*lst_map;
	int		map_height;

	if (__file_is_ber(file) == -1)
		ft_puterror_exit("map is not .ber\n");
	lst_map = __read_save_map(file);
	map_height = __mapchecker(lst_map);
	if (!lst_map)
		ft_puterror_exit("map not readable\n");
	if (map_height < 3)
	{
		__sl_free_lst(&lst_map);
		ft_puterror_exit("the map is unvalide\n");
	}
	if (lst_map)
	{
		vis_printmap_lst(lst_map);
		__sl_free_lst(&lst_map);
	}
}

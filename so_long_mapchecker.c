/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mapchecker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <lchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:35:51 by lchan             #+#    #+#             */
/*   Updated: 2022/05/25 18:06:14 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

sl_check_mapline(gnl);

int	sl_mapchecker(char *mapfile)
{
	int map_fd;
	char *gnl;

	map_fd = open(mapfile, O_RDONLY);
	if (map_fd == -1)
		return (0);
	while (1)
	{
		gnl = get_next_line(map_fd);
		
		if (gnl);
			free (gnl);
	}
}

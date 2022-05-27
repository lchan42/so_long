/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <lchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:34:21 by lchan             #+#    #+#             */
/*   Updated: 2022/05/26 13:20:55 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


# include "./libraries/libft/libft.h"
# include "./mlx_linux/mlx.h"

# define WIN_W 700
# define WIN_H 350
# define SO_LONG_ERROR "./so_long"
# define MAP_CHAR "01CEP"

typedef struct s_map{
	int	line_nbr; // at least > 3
	int	line_lengh; // at least > 3 && egal

	int	required_char;

}t_map;

typedef struct s_data{
	char	**map;
	void	*mlx_ptr;
	void	*mlx_win;
}t_data;

enum error{
	UNVALID_MAP,
	MLX_ERROR,
};

enum map_char{
	C = 1,
	E = 2,
	P = 4
};

//so_long_mapchecker.c
void	sl_read_save_map(char *mapfile);

//so_long_lst_utils.c
void	sl_free_lst(t_list *lst);
int		sl_lst_nodcnt(t_list *lst);

// sl_visual.c
void	vis_printmap_lst(t_list *lst);

#endif

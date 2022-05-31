/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <lchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:34:21 by lchan             #+#    #+#             */
/*   Updated: 2022/05/31 15:43:49 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <sys/wait.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./libraries/libft/libft.h"
# include "./mlx_linux/mlx.h"

# define WINDOW_NAME "my awesome game"
# define IMG_X 32
# define IMG_Y 32
# define SO_LONG_ERROR "./so_long"
# define MAP_CHAR "01CEP"

typedef struct s_data{
	char	**map;
	int		win_x;
	int		win_y;
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

enum e_key{
	W_U		= 119,
	S_D		= 115,
	D_R		= 100,
	A_L		= 97,
	ARW_U	= 65362,
	ARW_D 	= 65364,
	ARW_R	= 65363,
	ARW_L	= 65361,
	ESC		= 65307
};

//so_long_mapchecker.c
int	__mapchecker(t_list *lst);

//so_long_mapparser.c
char	**__mapparser(char *file);

//so_long_init_game.c
void	__initgame(t_data *data, char *file);

//so_long_endgame.c
void	__endgame(t_data *data);

//so_long_lst_utils.c
void	__sl_free_lst(t_list **lst);
int		__sl_nodcnt(t_list *lst);
void	__sl_free_tab(char  ** tab);






// sl_visual.c
void	vis_printmap_lst(t_list *lst);
void	vis_printmap_tab(char ** tab);
void	vis_struct(t_data *data);

#endif

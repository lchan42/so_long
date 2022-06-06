/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <lchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:34:21 by lchan             #+#    #+#             */
/*   Updated: 2022/06/06 13:28:18 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "./mlx_linux/mlx.h"
# include "./libraries/libft/libft.h"

# define WINDOW_NAME "my awesome game"
# define IMG_X 32
# define IMG_Y 32
# define MAX_X 2560
# define MAX_Y 1344
# define WIN_RED_CROSS 17
# define SO_LONG_ERROR "error"
# define STRING_COLOR 0xFF0000
# define FINAL_MESSAGE "So long, thank you for playing\n"
# define MAP_CHAR "01CEP"
# define SPRITES_CNT 8
# define P_UP_PATH "./sprites/pokemon_p_up.xpm"
# define P_DOWN_PATH "./sprites/pokemon_p_down.xpm"
# define P_RIGHT_PATH "./sprites/pokemon_p_right.xpm"
# define P_LEFT_PATH "./sprites/pokemon_p_left.xpm"
# define GROUND_PATH "./sprites/pokemon_ground.xpm"
# define WALL_PATH "./sprites/pokemon_wall.xpm"
# define COIN_PATH "./sprites/pokemon_coin.xpm"
# define EXIT_PATH "./sprites/pokemon_exit.xpm"

typedef struct s_img
{
	void	*ptr;
	char	*path;
	int		bpp;	//-->unused val
	int		width;
	int		height;
	int		endian;	//-->unused val
}	t_img;

typedef struct s_player
{
	int	mvt;
	int	coin;
	int	x;
	int	y;
}	t_player;

typedef struct s_data{
	char		**map;
	int			win_x;
	int			win_y;
	void		*mlx_ptr;
	void		*mlx_win;
	t_player	p;
	t_img		img[SPRITES_CNT];
}t_data;

enum error{

	UNVALID_MAP,
	MLX_INIT_FAIL,
	WIN_INIT_FAIL,
	MLX_XPM_FAIL
};

enum map_char{
	C = 1,
	E = 2,
	P = 4
};

enum e_key{
	KEY_W		= 119,
	KEY_S		= 115,
	KEY_D		= 100,
	KEY_A		= 97,
	ARW_U	= 65362,
	ARW_D 	= 65364,
	ARW_R	= 65363,
	ARW_L	= 65361,
	ESC		= 65307
};

enum e_img_struct_indice{
	P_UP,
	P_DOWN,
	P_RIGHT,
	P_LEFT,
	GROUND,
	WALL,
	COIN,
	EXIT
};

//so_long_mapchecker.c
int		__mapchecker(t_list *lst);

//so_long_mapparser.c
char	**__mapparser(char *file);

//sl_img_init.c
void	__img_init(t_data *data, t_img *img);

//so_long_init_game.c
void	__initgame(t_data *data, char *file);

//sl_display_imgs.c
void	__display_imgs(t_data *data);

//so_long_game_loop.c
void	__game_loop(t_data *data);

//so_long_endgame.c
void	__endgame(t_data *data);
void	__endgame_exit(t_data *data, int error_code);

//so_long_free_utils.c
void	__sl_free_lst(t_list **lst);
void	__sl_free_tab(char  ** tab);

// sl_visual.c
void	vis_printmap_lst(t_list *lst);
void	vis_printmap_tab(char ** tab);
void	vis_struct(t_data *data);

#endif

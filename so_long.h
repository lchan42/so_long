/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <lchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:34:21 by lchan             #+#    #+#             */
/*   Updated: 2022/05/24 21:39:26 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>


# include "./libraries/libft/libft.h"
# include "./mlx_linux/mlx.h"

# define WIN_W 700
# define WIN_H 350
# define SO_LONG_ERROR "./so_long"

enum error{
	MLX_ERROR,
};
#endif

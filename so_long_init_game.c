static int	__map_height(char **map)
{
	int	i;

	i= 0;
	while (map[i])
		i++;
	return(i);
}

static void	sl_mlx_init(void **mlx_ptr, void **mlx_win)
{
	*mlx_ptr = mlx_init();
	if (!*mlx_ptr)
		ft_perror_exit(SO_LONG_ERROR);
	*mlx_win = mlx_new_window(*mlx_ptr, WIN_W, WIN_H, "My first window");
	if (!*mlx_win)
	{
		mlx_destroy_display(*mlx_ptr);
		free(*mlx_ptr);
		ft_perror_exit (SO_LONG_ERROR);
	}
}

void	__initgame(t_data *data, char *file)
{

	data->map = __mapparser(file);
	data->map_x = ft_strlen(map[0]);
	data->map_y = __map_height(data->map);
	data->mlx_ptr =
}


int	main(int ac, char **av)
{
	int	fd;
	int	here_doc
	char	*gnl;

	fd = 0;
	here_doc = open(".here_doc", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	gnl = NULL;
	while (1)
	{
		gnl = get_next_line(fd);
		ft_putstr_fd(get, here_doc);
	}
	if (close(here_doc) == -1)
		printf("close error\n");
	return (0);
}

#include "../includes/vm.h"

/*int		check_n_flags(char **argv, int argc)
{
	int i;
	int n;

	n = 0;
	i = 1;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "-n"))
			n++;
		i++;
	}

}

int 	check_flags_for_players(int argc, t_flags *flags, char **argv)
{
	int len;

	len = argc;
	flags->visual == 1 ? len-- : 0;
	flags->dump > -1 ? len-- : 0;
	while ()
}*/

int		main(int argc, char **argv)
{
	t_flags *flags;
	t_players *players;

	if (argc < 2)
	{
		print_comands();
		return (0);
	}
	flags = create_flags();
	if ((get_flags(flags, argv)) == 0)
		return (0);
/*	if ((check_flags_for_players(argc - 1, flags, argv)) == 0)
		return (0);*/
	players = get_players(argv, argc);
	start_vm(players, flags);
	return (0);
}
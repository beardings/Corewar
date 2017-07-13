#include "../includes/vm.h"

int		check_n_flags(char **argv, int argc)
{
	int i;
	int n;

	n = 0;
	i = 1;
	while (i <= argc)
	{
		if (!ft_strcmp(argv[i], "-n") && !ft_strcmp(argv[i - 1], "-n"))
			n++;
		i++;
	}
	if (n > 0)
	{
		print_error("To many arguments (-n).");
		return (0);
	}
	return (1);
}

int 	check_flags_for_players(int argc, t_flags *flags, char **argv) // нужно переделать0
{
	int len;

	len = argc;
	flags->visual == 1 ? len-- : 0;
	flags->dump > -1 ? len-- : 0;
	if (!(check_n_flags(argv, argc)))
		return (0);
	if (argc > 0 && !ft_strcmp(argv[1], "-n"))
		len--;
	else if (argc > 1 && !ft_strcmp(argv[2], "-n"))
		len--;
	else if (argc > 2 && !ft_strcmp(argv[3], "-n"))
		len--;
	if (len < 1)
	{
		print_error("To many arguments (-v1).");
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_flags *flags;
	//t_players *players;

	if (argc < 2)
	{
		print_comands();
		return (0);
	}
	flags = create_flags();
	if ((get_flags(flags, argv)) == 0)
		return (0);
	if ((check_flags_for_players(argc - 1, flags, argv)) == 0)
		return (0);
	//players = get_players(argv, argc);
	//start_vm(players, flags);
	return (0);
}
#include "../includes/vm.h"

int     check_amount(t_flags *flags)
{
    if (flags->amount_players > 4)
    {
        print_error("To many Players, maximum 4.");
        return (0);
    }
    else if (flags->amount_num > 4)
    {
        print_error("To many number of Player. Read usage (Enter ./corewar).");
        return (0);
    }
    else
        return (1);
}

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

int     check_first_par(char **argv, int len)
{
    if (len == 1)
    {
        if (ft_strcmp(argv[1], "-v"))
        {
            print_error("Not the correct order of input of flags. Read usage (Enter ./corewar).");
            return (0);
        }
    }
    else if (len == 2)
    {
        if (ft_strcmp(argv[1], "-d"))
        {
            print_error("Not the correct order of input of flags. Read usage (Enter ./corewar).");
            return (0);
        }
    }
    else if (len == 3)
    {
        if (ft_strcmp(argv[1], "-d") || ft_strcmp(argv[3], "-v"))
        {
            print_error("Not the correct order of input of flags. Read usage (Enter ./corewar).");
            return (0);
        }
    }
    return (1);
}

int 	check_flags_for_players(int argc, t_flags *flags, char **argv)
{
    int len;

    len = 0;
    flags->visual == 1 ? len++ : 0;
    flags->dump > -1 ? len += 2 : 0;
    if (!(check_first_par(argv, len)))
        return (0);
    if (!(check_n_flags(argv, argc)))
        return (0);
    argc -= len;
    len++;
    while (argv[len] != NULL && argc > 0)
    {
        if (!(ft_strcmp(argv[len], "-n")))
        {
            if (argv[len + 1] == NULL || !(is_digit(argv[len + 1])))
            {
                print_error("Unknown number of Player.");
                return (0);
            }
            flags->amount_num++;
            len++;
            argc--;
            if ((open(argv[len + 1], O_RDONLY)) == -1)
            {
                print_error("Unknown arguments. Please read usage (Enter ./corewar).");
                return (0);
            }
            flags->amount_players++;
            len++;
            argc--;
        }
        else
        {
            if ((open(argv[len], O_RDONLY)) == -1)
            {
                print_error("Unknown arguments.");
                return (0);
            }
            flags->amount_players++;
        }
        len++;
        argc--;
    }
    if ((check_amount(flags)) == 0)
        return (0);
	return (1);
}


// need to check int max for the number of players
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
	if ((check_flags_for_players(argc - 1, flags, argv)) == 0)
		return (0);
    players = create_players();
	if ((get_players(players, argv, argc - 1, flags) == 0))
        return (0);
	//start_vm(players, flags);
	return (0);
}
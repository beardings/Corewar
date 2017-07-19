#include "../includes/vm.h"

t_players		*get_players(char **argv, int argc)
{
    t_players *players;
    int i;

    i = 1;
    while (argc > 0)
    {
        if (!(ft_strcmp(argv[i], "-n")))
        {

            i += 2;
        }
        argc--;
        i++;
    }
	return (players);
}

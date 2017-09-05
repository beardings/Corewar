#include "../includes/vm.h"

void            check_cor_file(t_players **players, char *cor_file)
{

}

// я могу принимать игроков и без n номера игрока, нужно нормально чекать
t_players		*get_players(char **argv, int argc)
{
    t_players *players;
    int i;

    i = 1;
    players = create_players();
    while (argc > 0)
    {
        if (!(ft_strcmp(argv[i], "-n")))
        {
            players->num = ft_atoi(argv[i + 1]);
            check_cor_file(&players, argv[i + 2]);
            i += 2;
        }
        argc--;
        i++;
    }
	return (players);
}

#include "../includes/vm.h"

unsigned int  change_bite(unsigned int num)
{
    unsigned int fs;
    unsigned int s;
    unsigned int t;
    unsigned int fo;

    fs = num >> 24;
    s = (num << 8) >> 24;
    t = (num << 16) >> 24;
    fo = (num << 24) >> 24;
    num = (fo << 24) + (t << 16) + (s << 8) + fs;
    return (num);
}

void        get_another_data(t_players **tmp, int fd)
{
    unsigned char   *com;

    com = malloc(((*tmp)->header.prog_size));
    read(fd, com, (*tmp)->header.prog_size);
    // нужно закинуть в итоа бейс - сом как инт и перевести по 1 байту в 16 системе
    (*tmp)->comands = com;
}

int        check_cor_file(t_players **tmp, char *cor_file)
{
    int fd;
    header_t *header;
    char *str;

    str = malloc(sizeof(char *) * sizeof(header_t));
    fd = open (cor_file, O_RDONLY);
    read(fd, str, sizeof(header_t));
    header = (header_t *)str;
    header->magic = change_bite(header->magic);
    header->prog_size = change_bite(header->prog_size);
    if (header->prog_size > CHAMP_MAX_SIZE)
    {
        print_error("Program size the bigger then max size.");
        return (0);
    }
    if (header->magic != COREWAR_EXEC_MAGIC)
    {
        print_error("Magic kay are not correct.");
        return (0);
    }
    (*tmp)->header = *header;
    get_another_data(tmp, fd);
    free(str);
    return (1);

}

int     check_valid_player_num(char *num)
{
    if (!is_digit(num))
    {
        print_error("Player number must be a number");
        return (0);
    }
    if (ft_atoiLong(num) > INT_MAX)
    {
        print_error("Player number must not be greater than maxint");
        return (0);
    }
    return (1);
}

// я могу принимать игроков и без n номера игрока, нужно нормально чекать
int		get_players(t_players *players, char **argv, int argc, t_flags *flags)
{
    t_players *tmp;
    int i;

    tmp = players;
    i = 1;
    flags->dump > -1 ? i += 2 : 0;
    flags->visual > 0 ? i++ : 0;
    while (i < argc)
    {
        if (!(ft_strcmp(argv[i], "-n")))
        {
            if (!check_valid_player_num(argv[i + 1]))
                return (0);
            players->num = ft_atoi(argv[i + 1]);
            i += 2;
            if ((check_cor_file(&players, argv[i]) == 0))
                return (0);
        }
        else
            if ((check_cor_file(&players, argv[i]) == 0))
                return (0);
        while (players->next != NULL)
            players = players->next;
        i != argc ? players->next = create_players() : 0;
        i != argc ? players = players->next : 0;
        i++;
    }
    players = tmp;
    return (1);
}
#include "../includes/vm.h"

t_players		*get_players(char **argv, int argc)
{
	t_players *players;

	players = ceate_players();
	return (players);
}

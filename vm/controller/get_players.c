#include "../includes/vm.h"

t_players		*get_players(char **argv, int argc)
{
	t_players *players;

	players = create_players();
	return (players);
}

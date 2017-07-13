#include "../includes/vm.h"

t_flags *create_flags(void)
{
	t_flags *flags;

	flags = (t_flags *)malloc(sizeof(t_flags));
	flags->dump = -1;
	flags->visual = 0;
	return (flags);
}

t_players *create_players(void)
{
	t_players *players;

	players = (t_players *)malloc(sizeof(t_players));
	
}
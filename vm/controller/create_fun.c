#include "../includes/vm.h"

t_flags *create_flags(void)
{
	t_flags *flags;

	flags = (t_flags *)malloc(sizeof(t_flags));
	flags->dump = -1;
	flags->visual = 0;
	return (flags);
}

header_t *create_header(void)
{
	header_t *header;

	header = (header_t *)malloc(sizeof(header_t));
	return(header);
}

t_players *create_players(void)
{
	t_players *players;

	players = (t_players *)malloc(sizeof(t_players));
	players->header = create_header();
	players->comands = NULL;
	players->live = 0;
	players->live_amount = 0;
	players->num = 0;
	players->vis_num = 0;
	players->pos = 0;
	players->next = NULL;
	return (players);
}
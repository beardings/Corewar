#include "../includes/vm.h"

void	print_error(char *str)
{
	printf(RED"ERROR!"END);
	printf(" %s\n", str);
}

void	print_comands(void)
{
	printf("\n");
	printf("Usage: ./corewar [-d N -v] <[-n N] champion1.cor> <[-n N] ...>\n");
	printf("--------------------------------------------------------------\n");
	printf("    -d N         : Dumps memory after N cycles then exits\n");
	printf("                   If all battle is less than N cycles,\n");
	printf("                   program will display the last cycle\n");
	printf("--------------------------------------------------------------\n");
	printf("    -n N         : Means that Player after this flag will be\n");
	printf("                   Player number N. If there is no -n flag,\n");
	printf("                   the next available number will be given to\n");
	printf("                   layer, starting from 1\n");
	printf("--------------------------------------------------------------\n");
	printf("    -v           : Visual output mode\n");
	printf("--------------------------------------------------------------\n");
	printf("\n");
}

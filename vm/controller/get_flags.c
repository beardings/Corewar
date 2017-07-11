#include "../includes/vm.h"

void	print_error(char *str)
{
	printf(RED"ERROR!"END);
	printf(" %s\n", str);
}

int		is_digit(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((ft_isdigit(str[i])) == 1)
			i++;
		else
			return (0);
	}
	return (1);
}

int	take_d(t_flags **flags, char **argv)
{
	int i;
	int yes;

	i = 1;
	yes = 0;
	while (argv[i] != NULL)
	{
		!ft_strcmp(argv[i], "-d") ? yes++ : 0;
		i++;
	}
	if (yes > 1)
	{
		print_error("To many arguments (-d).");
		return (0);
	}
	i = 1;
	while (argv[i] != NULL)
	{
		if (!ft_strcmp(argv[i], "-d"))
		{
			if (!argv[i + 1] || !(is_digit(argv[i + 1])))
			{
				print_error("Unknown number of the cycle.");
				return (0);
			}
			(*flags)->dump = ft_atoi(argv[i + 1]);
		}
		i++;
	}
	if ((*flags)->dump < 0)
	{
		print_error("Too high a value of cycle.");
		return (0);
	}
	return (1);
}

int		take_v(t_flags **flags, char **argv)
{
	int i;
	int yes;

	i = 1;
	yes = 0;
	while (argv[i] != NULL)
	{
		!ft_strcmp(argv[i], "-v") ? yes++ : 0;
		i++;
	}
	if (yes > 1)
	{
		print_error("To many arguments (-v).");
		return (0);
	}
	else if (yes == 1)
		(*flags)->visual = 1;
	return (1);
}

int		get_flags(t_flags *flags, char **argv)
{
	if (!(take_d(&flags, argv)) || !(take_v(&flags, argv)))
	{
		free(flags);
		return (0);
	}
	return (1);
}
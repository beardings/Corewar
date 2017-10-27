/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags_for.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 18:33:51 by mponomar          #+#    #+#             */
/*   Updated: 2017/10/03 19:54:21 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int				check_n_flags(char **argv, int argc)
{
	int			i;
	int			n;

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

int				check_first_par(char **argv, int len)
{
	if (len == 1)
	{
		if (ft_strcmp(argv[1], "-v"))
		{
			print_error("Not the correct order of input of flags.");
			return (0);
		}
	}
	else if (len == 2)
	{
		if (ft_strcmp(argv[1], "-d"))
		{
			print_error("Not the correct order of input of flags.");
			return (0);
		}
	}
	else if (len == 3)
	{
		if (ft_strcmp(argv[1], "-d") || ft_strcmp(argv[3], "-v"))
		{
			print_error("Not the correct order of input of flags.");
			return (0);
		}
	}
	return (1);
}

int				check_fl_next(int *argc, t_flags *flags, char **argv, int *len)
{
	if (argv[*len + 1] == NULL || !(is_digit(argv[*len + 1])))
	{
		print_error("Unknown number of Player.");
		return (0);
	}
	flags->amount_num++;
	(*len)++;
	(*argc)--;
	if ((open(argv[*len + 1], O_RDONLY)) == -1)
	{
		print_error("Unknown arguments.");
		return (0);
	}
	flags->amount_players++;
	(*len)++;
	(*argc)--;
	return (1);
}

int				check_ft_n(int *argc, t_flags *flags, char **argv, int *len)
{
	if (!(ft_strcmp(argv[*len], "-n")))
	{
		if ((check_fl_next(argc, flags, argv, len)) == 0)
			return (0);
	}
	else
	{
		if ((open(argv[*len], O_RDONLY)) == -1)
		{
			print_error("Unknown arguments.");
			return (0);
		}
		flags->amount_players++;
	}
	return (1);
}

int				check_flags_for_players(int argc, t_flags *flags, char **argv)
{
	int			len;

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
		if ((check_ft_n(&argc, flags, argv, &len)) == 0)
			return (0);
		len++;
		argc--;
	}
	return ((check_amount(flags)) == 0 ? 0 : 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:07:10 by abastida          #+#    #+#             */
/*   Updated: 2023/07/27 13:02:46 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_error(int n)
{
	if (n == 1)
		return (1);
	if (n == 2)
	{
		printf("Wrong parameters\n");
		return (2);
	}
	return (0);
}

int	check_errors(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
	{
		ft_error (2);
		return (2);
	}
	while (av[i])
	{
		if (av[i][0] == '0' && !av[i][1])
		{
			ft_error(2);
			return (2);
		}
		if (is_digit(av) != 0)
		{
			ft_error (2);
			return (2);
		}
		i++;
	}
	return (0);
}

int	is_digit(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (2);
			j++;
		}
		i++;
	}
	return (0);
}

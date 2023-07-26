/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:02:18 by abastida          #+#    #+#             */
/*   Updated: 2023/07/26 17:30:37 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philobonus.h"

int	ft_error(int n)
{
	if (n == 1)
		return (1);
	if (n == 2)
	{
		printf("Wrong parametres");
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
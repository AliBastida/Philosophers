/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:07:10 by abastida          #+#    #+#             */
/*   Updated: 2023/07/04 10:07:12 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int ft_error(int n)
{
	if (n == 1)
		return (1);
	if ( n == 2)
	{
		printf("Wrong parametres");
		return (2);
	}
	return (0);
}

int check_errors(int ac, char **av)
{
	int i = 1;
	int j = 0;
	if (ac < 5 || ac > 6)
	{
		ft_error (2);
		return(2);
	}
	while (av[i])
	{
		if (av[i][0] == '0' && !av[i][1])
		{
			ft_error(2);
			return (2);
		}
		i++;
	}
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
			{
				ft_error (2);
				return(2);
			}
			j++;
		}
		i++;
	}
	return (0);
}

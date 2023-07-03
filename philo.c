/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:38:25 by abastida          #+#    #+#             */
/*   Updated: 2023/07/03 09:54:08 by abastida         ###   ########.fr       */
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
	if (av[1][0] == '0')
	{
		ft_error(2);
		return (2);
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

int main(int ac, char **av)
{
	if (check_errors(ac, av) == 0)
	{
		pthread_t t1, t2;
		pthread_create(&t1, NULL, &routine, NULL);
		pthread_create(&t2, NULL, &prueba, NULL);
		pthread_join(t1, NULL);
		pthread_join(t2, NULL);
	}
	return(0);
}


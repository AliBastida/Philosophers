/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 16:58:04 by abastida          #+#    #+#             */
/*   Updated: 2023/07/24 17:31:41 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	printing(int n, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print);
	if (philo->data->someone_died == 1)
	{
		pthread_mutex_unlock(&philo->data->print);
		return ;
	}
	if (n == 1)
	{
		printf("%lld %d has taken left fork %d\n", (get_time() - 
				philo-> data->start_time), philo->num_philo, philo->fork_left);
	}
	else if (n == 2)
	{
		printf("%lld %d has taken right fork %d\n", (get_time() - 
				philo-> data->start_time), philo->num_philo, philo->fork_right);
	}
	else if (n == 3)
	{
		printf("%lld %d is eating\n", (get_time() - 
				philo-> data->start_time), philo->num_philo);
	}
	pthread_mutex_unlock(&philo->data->print);
	continue_printing(n, philo);
}

void	continue_printing(int n, t_philo *philo)
{
	pthread_mutex_lock(&philo-> data-> print);
	if (philo-> data-> someone_died == 1)
	{
		pthread_mutex_unlock(&philo-> data-> print);
		return ;
	}
	if (n == 4)
	{
		printf("%lld %d is sleeping\n", (get_time() - 
				philo-> data->start_time), philo->num_philo);
	}
	else if (n == 5)
	{
		printf("%lld %d is thinking\n", (get_time() - 
				philo-> data->start_time), philo->num_philo);
	}
	else if (n == 6)
		printf("Everyone has eaten enough!\n");
	pthread_mutex_unlock(&philo->data->print);
}

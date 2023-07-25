/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:19:10 by abastida          #+#    #+#             */
/*   Updated: 2023/07/25 16:28:43 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->num_philo % 2 == 0)
		usleep(1000);
	pthread_mutex_lock(&philo->data->start);
	while (philo->data->someone_died == 0)
	{
		pthread_mutex_unlock(&philo->data->start);
		is_eating(philo);
		printing(4, philo);
		ft_sleep(philo->data->time_sleep);
		printing(5, philo);
		if (philo->data->must_eat)
			if (philo->data->must_eat == 
				philo->n_times_has_eat)
				break ;
		pthread_mutex_lock(&philo->data->start);
	}
	pthread_mutex_unlock(&philo->data->start);
	return (NULL);
}

void	is_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork[philo->fork_left]);
	printing(1, philo);
	pthread_mutex_lock(&philo->data->fork[philo->fork_right]);
	printing(2, philo);
	printing(3, philo);
	ft_sleep(philo->data->time_to_eat);
	pthread_mutex_lock(&philo->data->start);
	philo->last_eat = get_time();
	philo->n_times_has_eat++;
	pthread_mutex_unlock(&philo->data->fork[philo->fork_left]);
	pthread_mutex_unlock(&philo->data->fork[philo->fork_right]);
	pthread_mutex_unlock(&philo->data->start);
}

int	check_if_someone_is_dead(t_philo *philo, int i)
{
	if (time_dif(get_time(), philo[i].last_eat) > philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->data->start);
		pthread_mutex_lock(&philo->data->print);
		philo->data->someone_died = 1;
		printf(BRED"%lld Philo %d has died 💀\n"RESET, (get_time() - 
				philo->data->start_time), (i + 1));
		pthread_mutex_unlock(&philo->data->print);
		pthread_mutex_unlock(&philo->data->start);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->start);
	return (0);
}

void	*check_philo(void *arg)
{
	int		i;
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->data->someone_died == 0)
	{
		i = 0;
		while (i < philo->data->philos_num)
		{
			if (check_if_someone_is_dead(philo, i) == 1)
				break ;
			i++;
		}
		while (--i >= 0 && (philo[i].n_times_has_eat == philo->data->must_eat) 
			&& philo->data->someone_died == 0)
		{
			if (i == 0)
			{
				check_if_everyone_has_eaten(philo);
				return (NULL);
			}
		}
		usleep(100);
	}
	return (NULL);
}

void	check_if_everyone_has_eaten(t_philo *philo)
{
	printing(6, philo);
	pthread_mutex_lock(&philo->data->print);
	philo->data->someone_died = 1;
	pthread_mutex_unlock(&philo->data->print);
}

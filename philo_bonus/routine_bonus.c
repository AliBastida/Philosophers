/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:48:18 by abastida          #+#    #+#             */
/*   Updated: 2023/08/14 15:16:50 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philobonus.h"

void *check_death(t_philo *philo)
{
	while(philo->data->someone_died)
	{
		sem_wait(philo->data->print);
		if (time_dif(get_time(), philo->last_eat) >= philo->data->time_to_die)
		{
			philo->data->someone_died = 0;
			printf(BRED"%lld someone has died 💀\n"RESET, (get_time() - philo->data->start_time));
			exit(1);
		}
		sem_post(philo->data->print);
		usleep(1000);
		if (!philo->data->someone_died)
			break ;
		if (philo->data->must_eat && philo->n_times_has_eat == philo->data->must_eat)
			{
				printing(6, philo);
				break ;
			}	
	}
	return(NULL);
}

int *one_philo(t_philo *philo)
{
	philo->last_eat = get_time();
	pthread_create(&(philo->ph), NULL, (void *(*) (void *))check_death, philo);
	while(philo->data->someone_died)
	{
		sem_wait(philo->data->fork);
		printing(1, philo);
		sem_wait(philo->data->fork);
		printing(2, philo);
		sem_wait(philo->data->start);
		printing(3, philo);
		philo->n_times_has_eat++;
		philo->last_eat = get_time();
		ft_sleep(philo->data->time_to_eat);
		sem_post(philo->data->fork);
		sem_post(philo->data->fork);
		sem_post(philo->data->start);
		if (philo->data->must_eat && philo->n_times_has_eat == philo->data->must_eat)
			break;
		continue_printing(4,philo);
		ft_sleep(philo->data->time_sleep);
		continue_printing(5, philo);
	}
	usleep(50);
	pthread_join(philo->ph, NULL);
	if (philo->data->someone_died == 0)
		exit(1);
	//printf(BRED"%lld Philo has died 💀\n"RESET, (get_time() - philo->data->start_time));
	exit(0);
	//return (NULL);
}


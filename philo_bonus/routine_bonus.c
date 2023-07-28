/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:48:18 by abastida          #+#    #+#             */
/*   Updated: 2023/07/28 18:09:23 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philobonus.h"

int *one_philo(t_philo *philo)
{
	philo->last_eat = get_time();
	//pthread_create(&(philo->ph), NULL, &funcion que comprueba si esta muerto, philo);
	while(1)
	{
		sem_wait(philo->data->fork);
		printing(1, philo);
		sem_wait(philo->data->fork);
		printing(2, philo);
		sem_wait(philo->data->start);
		printing(3, philo);
		philo->n_times_has_eat++;
		philo->last_eat = get_time();
		sem_post(philo->data->fork);
		sem_post(philo->data->fork);
		sem_post(philo->data->start);
	}
	printf(BRED"%lld Philo has died 💀\n"RESET, (get_time() - philo->data->start_time));
	exit(1);
	return (NULL);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:48:18 by abastida          #+#    #+#             */
/*   Updated: 2023/07/26 20:30:36 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philobonus.h"

void *one_philo(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    printing(1, philo);
    ft_sleep(philo->data->time_to_die);
    printf(BRED"%lld Philo has died 💀\n"RESET, 
		(get_time() - philo->data->start_time));
	return (NULL);
}

int	create_one_philo(t_philo *philo)
{
	pthread_t	the_philo;

	if (pthread_create(&the_philo, NULL, &one_philo, philo) != 0)
	{
		printf("Can't create the_philo\n");
		return (-1);
	}
	pthread_join(the_philo, NULL);
	return (0);
}
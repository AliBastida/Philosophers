/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:50:09 by abastida          #+#    #+#             */
/*   Updated: 2023/07/27 14:49:25 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	free_and_destroy(t_data *data, t_philo *philo, int out)
{
	int	i;

	i = -1;
	if (philo)
		free(philo);
	if (data)
	{
		if (data->fork)
		{
			while (++i < data->philos_num)
				pthread_mutex_destroy(&data->fork[i]);
			free(data->fork);
		}
		pthread_mutex_unlock(&data->print);
		pthread_mutex_destroy(&data->print);
		pthread_mutex_unlock(&data->start);
		pthread_mutex_destroy(&data->start);
		free(data);
	}
	return (out);
}

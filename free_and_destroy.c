/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:50:09 by abastida          #+#    #+#             */
/*   Updated: 2023/07/24 18:06:23 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	free_and_destroy(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->philos_num)
		pthread_mutex_destroy(&philo->data->fork[i]);
	pthread_mutex_destroy(&philo->data->print);
	pthread_mutex_destroy(&philo->data->start);
	free(data->fork);
	free(data);
	free(philo);
	return (0);
}

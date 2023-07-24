/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:38:25 by abastida          #+#    #+#             */
/*   Updated: 2023/07/24 17:59:38 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philo;

	data = (t_data *)malloc(sizeof(t_data));
	if (check_errors(ac, av) != 0)
		return (-1);
	if (giving_data(data, av) != 0)
		return (-1);
	philo = create_philo(data);
	if (!philo)
		return (-1);
	if (ft_atoi(av[1]) == 1)
		create_one_philo(philo);
	else
		ft_create_thread(data, philo);
	free_and_destroy(data, philo);
	return (0);
}

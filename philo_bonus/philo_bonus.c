/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:09:10 by abastida          #+#    #+#             */
/*   Updated: 2023/07/28 16:43:16 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philobonus.h"

int main(int ac, char **av)
{
	t_data *data;
	t_philo *philo;

	
	if (check_errors(ac, av) != 0)
        return (-1);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (-1);
	if (giving_data(data, av) != 0)
		return (-1);
	printf("%p\n", data);
 	philo = data_philo(data);
	printf("%p\n", philo);
	if (!philo)
		return (-1);
	create_philo(philo, data);

	return (0);
}

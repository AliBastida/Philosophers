/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:40:41 by abastida          #+#    #+#             */
/*   Updated: 2023/07/04 09:56:53 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*pasamos los datos de cada parametro a cada valor*/

int giving_data(t_data *data, char **av)
{
	data -> philos_num = ft_atoi(av[1]);
	data -> time_to_die = ft_atoi(av[2]);
	data -> time_to_eat = ft_atoi(av[3]);
	data -> time_sleep = ft_atoi(av[4]);
	if (av[5])
		data -> number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	return (0);
}

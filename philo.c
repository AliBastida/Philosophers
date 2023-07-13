/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:38:25 by abastida          #+#    #+#             */
/*   Updated: 2023/07/04 10:03:40 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac, char **av)
{
	t_data *data = NULL;
	data = (t_data *)malloc(sizeof(t_data));
	if (check_errors(ac, av) != 0)
		return (-1);
	if (giving_data(data, av) != 0)
		return (-1);
	ft_create_thread(data);
		//pthread_create(&t1, NULL, &routine, NULL);
		//pthread_create(&t2, NULL, &prueba, NULL);
		//pthread_join(t1, NULL);
		//pthread_join(t2, NULL);
	return(0);
}


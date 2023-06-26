/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:38:25 by abastida          #+#    #+#             */
/*   Updated: 2023/06/26 15:38:25 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac, char **av)
{
	(void) ac;
	(void) av;
	pthread_t t1, t2;
	pthread_create(&t1, NULL, &routine, NULL);
	pthread_create(&t2, NULL, &prueba, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:40:30 by abastida          #+#    #+#             */
/*   Updated: 2023/07/20 13:11:37 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	int num_philo;
	int fork_left;
	int fork_right;
	struct t_data *data;

}t_philo;

typedef struct s_data
{
	int philos_num;
	pthread_mutex_t	*fork;
	int time_to_eat;
	int time_to_die;
	int time_sleep;
	int number_of_times_each_philosopher_must_eat;
	struct t_philo *philo;

}t_data;



//philo.c //
int main(int ac, char **av);

//check_error.c//
int ft_error(int n);
int check_errors(int ac, char **av);

//create.c//
int giving_data(t_data *data, char **av);
int ft_create_thread(t_data *data, t_philo *philos);

//utils.c//
int ft_atoi(char *str);

//data_philo.c//
t_philo *create_philo(t_data *data);

//time_control.c//






//prueba.c//
void *routine();
void *prueba(void *arg);
#endif

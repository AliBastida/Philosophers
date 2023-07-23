/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:40:30 by abastida          #+#    #+#             */
/*   Updated: 2023/07/23 19:52:13 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

// typedef struct s_data	t_data;


typedef struct s_data
{
	int philos_num;
	pthread_mutex_t print;
	pthread_mutex_t	*fork;
	int time_to_eat;
	int time_to_die;
	int time_sleep;
	int number_of_times_each_philosopher_must_eat;
	int someone_died;
	long long start_time;
	// struct t_philo *philo;
}t_data;

typedef struct s_philo
{
	int num_philo;
	int fork_left;
	int fork_right;
	int n_times_has_eat;
	long long last_eat;
	t_data *data;
}t_philo;

//philo.c //
int main(int ac, char **av);

//check_error.c//
int ft_error(int n);
int check_errors(int ac, char **av);

//create.c//
int giving_data(t_data *data, char **av);
int ft_create_thread(t_data *data, t_philo *philos);
int init_mutex(t_data *philo);

//utils.c//
int ft_atoi(char *str);

//data_philo.c//
t_philo *create_philo(t_data *data);

//time_control.c//

long long time_dif(long long current, long long past);
long long get_time(void);
void ft_sleep(long long time);

//prueba.c//
void *routine(void *arg);
void *check_philo(void *arg);

//print.c//
void printing(int n, t_philo *philo);

#endif

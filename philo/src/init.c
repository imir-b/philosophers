/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 02:54:39 by vlad              #+#    #+#             */
/*   Updated: 2026/04/23 15:35:13 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_create_philosophers(t_data *data)
{
	int				count;
	t_philosopher	*philosophers;

	philosophers = malloc(sizeof(t_philosopher) * data->n_philosophers);
	if (!philosophers)
		return (1);
	count = 0;
	while (count < data->n_philosophers)
	{
		pthread_mutex_init(&data->forks[count], NULL);
		philosophers[count].id = count + 1;
		philosophers[count].left_fork = &data->forks[count];
		philosophers[count].right_fork = &data->forks[(count + 1)
			% data->n_philosophers];
		philosophers[count].eat_count = 0;
		pthread_mutex_init(&philosophers[count].eat_count_mutex, NULL);
		philosophers[count].last_meal_time = ft_get_timestamp();
		pthread_mutex_init(&philosophers[count].lmt_mutex, NULL);
		philosophers[count].thread = 0;
		philosophers[count].data = data;
		count++;
	}
	data->philosophers = philosophers;
	return (0);
}

int	ft_check_data(t_data *data)
{
	if (data->n_philosophers <= 0 || data->n_philosophers > MAX_PHILOSOPHERS
		|| data->time_to_die <= 0 || data->time_to_eat <= 0
		|| data->time_to_sleep <= 0)
		return (1);
	return (0);
}

t_data	*ft_init_data(int ac, char **av)
{
	t_data			*data;
	pthread_mutex_t	*forks;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));
	if (!forks)
		return (free(data), NULL);
	data->n_philosophers = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->n_meals = ft_atoi(av[5]);
	else
		data->n_meals = -1;
	if (ft_check_data(data))
		return (free(forks), free(data), NULL);
	data->start_time = ft_get_timestamp();
	data->forks = forks;
	data->someone_died = 0;
	pthread_mutex_init(&data->someone_died_mutex, NULL);
	pthread_mutex_init(&data->print_mutex, NULL);
	return (data);
}

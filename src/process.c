/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 03:17:53 by vlad              #+#    #+#             */
/*   Updated: 2026/04/17 13:59:17 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_death(t_data *data)
{
	int	result;

	pthread_mutex_lock(&data->someone_died_mutex);
	result = data->someone_died;
	pthread_mutex_unlock(&data->someone_died_mutex);
	return (result);
}

void	*ft_philosopher_routine(void *arg)
{
	t_philosopher	*philosopher;
	t_data			*data;

	philosopher = (t_philosopher *)arg;
	data = (t_data *)philosopher->data;
	if (philosopher->id % 2 == 0)
		usleep(1000);
	while (!ft_check_death(data))
	{
		if (data->n_meals != -1 && philosopher->eat_count >= data->n_meals)
			break ;
		pthread_mutex_lock(philosopher->left_fork);
		ft_print_action(philosopher, "has taken a fork");
		pthread_mutex_lock(philosopher->right_fork);
		ft_print_action(philosopher, "has taken a fork");
		ft_print_action(philosopher, "is eating");
		usleep(data->time_to_eat * 1000);
		pthread_mutex_lock(&philosopher->last_meal_time_mutex);
		philosopher->last_meal_time = ft_get_timestamp();
		pthread_mutex_unlock(&philosopher->last_meal_time_mutex);
		philosopher->eat_count++;
		pthread_mutex_unlock(philosopher->left_fork);
		pthread_mutex_unlock(philosopher->right_fork);
		ft_print_action(philosopher, "is sleeping");
		usleep(data->time_to_sleep * 1000);
		ft_print_action(philosopher, "is thinking");
	}
	return (NULL);
}

void	ft_process_philosophers(t_data *data)
{
	int count;

	count = 0;
	if (data->n_philosophers == 1)
	{
		ft_print_action(&data->philosophers[0], "has taken a fork");
		usleep(data->time_to_die * 1000);
		ft_print_action(&data->philosophers[0], "died");
		data->someone_died = 1;
		return ;
	}
	while (count < data->n_philosophers)
	{
		pthread_create(&data->philosophers[count].thread, NULL,
			ft_philosopher_routine, &data->philosophers[count]);
		count++;
	}
}

void	*ft_spectator_routine(void *arg)
{
	t_data	*data;
	int		count;

	data = (t_data *)arg;
	while (1)
	{
		count = 0;
		while (count < data->n_philosophers)
		{
			pthread_mutex_lock(&data->philosophers[count].last_meal_time_mutex);
			if (ft_get_timestamp() - data->philosophers[count].last_meal_time >= data->time_to_die)
			{
				pthread_mutex_unlock(&data->philosophers[count].last_meal_time_mutex);
				ft_print_action(&data->philosophers[count], "died");
				pthread_mutex_lock(&data->someone_died_mutex);
				data->someone_died = 1;
				pthread_mutex_unlock(&data->someone_died_mutex);
				return (NULL);
			}
			else
				pthread_mutex_unlock(&data->philosophers[count].last_meal_time_mutex);
			count++;
		}
		usleep(1000);
	}
	return (NULL);
}

int	ft_create_spectator(t_data *data)
{
	pthread_t	spectator_thread;

	if (pthread_create(&spectator_thread, NULL, ft_spectator_routine, data) != 0)
		return (1);
	pthread_detach(spectator_thread);
	return (0);
}

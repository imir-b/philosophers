/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 03:17:53 by vlad              #+#    #+#             */
/*   Updated: 2026/04/17 18:44:11 by vlad             ###   ########.fr       */
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

int	ft_eat(t_data *data, t_philosopher *philo)
{
	pthread_mutex_lock(philo->left_fork);
	ft_print_action(philo, "has taken a fork");
	if (data->n_philosophers == 1)
	{
		while (!ft_check_death(data))
			usleep(1000);
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	pthread_mutex_lock(philo->right_fork);
	ft_print_action(philo, "has taken a fork");
	ft_print_action(philo, "is eating");
	usleep(data->time_to_eat * 1000);
	pthread_mutex_lock(&philo->lmt_mutex);
	philo->last_meal_time = ft_get_timestamp();
	pthread_mutex_unlock(&philo->lmt_mutex);
	pthread_mutex_lock(&philo->eat_count_mutex);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->eat_count_mutex);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}

void	*ft_philosopher_routine(void *arg)
{
	t_philosopher	*philo;
	t_data			*data;

	philo = (t_philosopher *)arg;
	data = (t_data *)philo->data;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!ft_check_death(data))
	{
		pthread_mutex_lock(&philo->eat_count_mutex);
		if (data->n_meals != -1 && philo->eat_count >= data->n_meals)
		{
			pthread_mutex_unlock(&philo->eat_count_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->eat_count_mutex);
		if (ft_eat(data, philo))
			return (NULL);
		ft_print_action(philo, "is sleeping");
		usleep(data->time_to_sleep * 1000);
		ft_print_action(philo, "is thinking");
	}
	return (NULL);
}

void	ft_process_philosophers(t_data *data)
{
	int	count;

	count = 0;
	while (count < data->n_philosophers)
	{
		pthread_create(&data->philosophers[count].thread, NULL,
			ft_philosopher_routine, &data->philosophers[count]);
		count++;
	}
}

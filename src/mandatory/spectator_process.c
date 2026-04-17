/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectator_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:45:10 by vbleskin          #+#    #+#             */
/*   Updated: 2026/04/17 18:22:46 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_philo_death(t_data *data, t_philosopher *philo, int *all_ate)
{
	pthread_mutex_lock(&philo->eat_count_mutex);
	if (data->n_meals != -1 && philo->eat_count >= data->n_meals)
	{
		pthread_mutex_unlock(&philo->eat_count_mutex);
		*all_ate = 1;
		return (0);
	}
	pthread_mutex_unlock(&philo->eat_count_mutex);
	pthread_mutex_lock(&philo->lmt_mutex);
	if (ft_get_timestamp() - philo->last_meal_time >= data->time_to_die)
	{
		pthread_mutex_unlock(&philo->lmt_mutex);
		ft_print_action(philo, "died");
		pthread_mutex_lock(&data->someone_died_mutex);
		data->someone_died = 1;
		pthread_mutex_unlock(&data->someone_died_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->lmt_mutex);
	return (0);
}

void	*ft_spectator_routine(void *arg)
{
	t_data	*data;
	int		count;
	int		all_ate;

	data = (t_data *)arg;
	while (1)
	{
		count = 0;
		all_ate = 0;
		while (count < data->n_philosophers)
		{
			if (ft_check_philo_death(data, &data->philosophers[count], &all_ate))
				return (NULL);
			count++;
		}
		if (all_ate)
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}

int	ft_create_spectator(t_data *data)
{
	if (pthread_create(&data->spectator_thread, NULL,
			ft_spectator_routine, data) != 0)
		return (1);
	return (0);
}

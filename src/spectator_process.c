/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectator_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:45:10 by vbleskin          #+#    #+#             */
/*   Updated: 2026/04/17 15:36:59 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_philo_death(t_data *data, t_philosopher *philo)
{
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

	data = (t_data *)arg;
	while (1)
	{
		count = 0;
		while (count < data->n_philosophers)
		{
			if (ft_check_philo_death(data, &data->philosophers[count]))
				return (NULL);
			count++;
		}
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

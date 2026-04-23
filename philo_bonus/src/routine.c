/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:18:39 by vlad              #+#    #+#             */
/*   Updated: 2026/04/23 16:49:28 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_eat(t_philosopher_bonus *philo)
{
	ft_print_action(philo, "is eating");
	philo->last_meal_time = ft_get_timestamp();
	philo->eat_count++;
	usleep(philo->data->time_to_eat * 1000);
}

static void	ft_wait_forks(t_philosopher_bonus *philo, t_data_bonus *data)
{
	sem_wait(data->waiter);
	sem_wait(data->forks);
	ft_print_action(philo, "has taken a fork");
	sem_wait(data->forks);
	ft_print_action(philo, "has taken a fork");
	sem_post(data->waiter);
}

void	ft_philosopher_routine(t_philosopher_bonus *philo, t_data_bonus *data)
{
	while (1)
	{
		if (data->n_meals != -1 && philo->eat_count >= data->n_meals)
		{
			free(philo);
			exit(0);
		}
		ft_print_action(philo, "is thinking");
		ft_wait_forks(philo, data);
		ft_eat(philo);
		sem_post(data->forks);
		sem_post(data->forks);
		ft_print_action(philo, "is sleeping");
		usleep(data->time_to_sleep * 1000);
	}
}

void	*ft_spectator_routine(void *arg)
{
	t_philosopher_bonus	*philo;
	t_data_bonus		*data;

	philo = (t_philosopher_bonus *)arg;
	data = philo->data;
	while (1)
	{
		if (ft_get_timestamp() - philo->last_meal_time >= data->time_to_die)
		{
			sem_wait(data->print_sem);
			printf("%lld %d died\n",
				ft_get_timestamp() - data->start_time, philo->id);
			exit(1);
		}
		usleep(1000);
	}
	return (NULL);
}

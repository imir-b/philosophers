/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 23:15:11 by vlad              #+#    #+#             */
/*   Updated: 2026/04/20 23:20:35 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_wait_for_philosophers(t_data_bonus *data)
{
	int	i;

	i = 0;
	while (i < data->n_philosophers)
	{
		waitpid(-1, NULL, 0);
		i++;
	}
}

void	ft_philosopher_routine(int id, t_data_bonus *data)
{
	while (1)
	{
		ft_print_action(id, "is thinking");
		sem_wait(data->forks);
		ft_print_action(id, "has taken a fork");
		sem_wait(data->forks);
		ft_print_action(id, "has taken a fork");
		ft_print_action(id, "is eating");
		usleep(data->time_to_eat * 1000);
		sem_post(data->forks);
		sem_post(data->forks);
		ft_print_action(id, "is sleeping");
		usleep(data->time_to_sleep * 1000);
	}
}

void	ft_process_philosophers(t_data_bonus *data)
{
	int	id;

	id = 0;
	while (id < data->n_philosophers)
	{
		if (fork() == 0)
		{
			ft_philosopher_routine(id + 1, data);
			exit(0);
		}
		id++;
	}
	ft_wait_for_philosophers(data);
}

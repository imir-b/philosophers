/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 23:13:57 by vlad              #+#    #+#             */
/*   Updated: 2026/04/20 23:22:47 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"


void	ft_free_data(t_data_bonus *data)
{
	if (data->forks != SEM_FAILED)
		sem_close(data->forks);
	sem_unlink("/philo_forks");
	free(data);
}

t_data_bonus	*ft_init_data(int ac, char **av)
{
	t_data_bonus	*data;

	data = malloc(sizeof(t_data_bonus));
	if (data == NULL)
		return (NULL);
	data->n_philosophers = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->n_meals = ft_atoi(av[5]);
	else
		data->n_meals = -1;
	data->start_time = ft_get_timestamp();
	sem_unlink("/philo_forks");
	data->forks = sem_open("/philo_forks", O_CREAT, 0644, data->n_philosophers);
	if (data->forks == SEM_FAILED)
		return (free (data), NULL);
	return (data);
}

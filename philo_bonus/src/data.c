/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 23:13:57 by vlad              #+#    #+#             */
/*   Updated: 2026/04/23 15:49:16 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_free_data(t_data_bonus *data)
{
	if (data->forks != SEM_FAILED)
		sem_close(data->forks);
	sem_unlink("/philo_forks");
	if (data->print_sem != SEM_FAILED)
		sem_close(data->print_sem);
	sem_unlink("/philo_print");
	if (data->waiter != SEM_FAILED)
		sem_close(data->waiter);
	sem_unlink("/philo_waiter");
	free(data);
	return (NULL);
}

int	ft_check_data(t_data_bonus *data)
{
	if (data->n_philosophers <= 0 || data->n_philosophers > MAX_PHILOSOPHERS
		|| data->time_to_die <= 0 || data->time_to_eat <= 0
		|| data->time_to_sleep <= 0)
		return (1);
	return (0);
}

int	ft_init_sems(t_data_bonus *data)
{
	sem_unlink("/philo_forks");
	data->forks = sem_open("/philo_forks", O_CREAT, 0644, data->n_philosophers);
	if (data->forks == SEM_FAILED)
		return (1);
	sem_unlink("/philo_print");
	data->print_sem = sem_open("/philo_print", O_CREAT, 0644, 1);
	if (data->print_sem == SEM_FAILED)
		return (1);
	sem_unlink("/philo_waiter");
	data->waiter = sem_open("/philo_waiter", O_CREAT, 0644, 1);
	if (data->waiter == SEM_FAILED)
		return (1);
	return (0);
}

t_data_bonus	*ft_init_data(int ac, char **av)
{
	t_data_bonus	*data;

	data = malloc(sizeof(t_data_bonus));
	if (data == NULL)
		return (NULL);
	data->forks = SEM_FAILED;
	data->print_sem = SEM_FAILED;
	data->waiter = SEM_FAILED;
	data->n_philosophers = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->n_meals = ft_atoi(av[5]);
	else
		data->n_meals = -1;
	if (ft_check_data(data))
		return (free(data), NULL);
	data->start_time = ft_get_timestamp();
	if (ft_init_sems(data))
		return (ft_free_data(data));
	return (data);
}

t_philosopher_bonus	*ft_init_philosopher(int id, t_data_bonus *data)
{
	t_philosopher_bonus	*philo;

	philo = malloc(sizeof(t_philosopher_bonus));
	if (philo == NULL)
		return (NULL);
	philo->id = id;
	philo->eat_count = 0;
	philo->last_meal_time = ft_get_timestamp();
	philo->data = data;
	return (philo);
}

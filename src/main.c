/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 05:06:03 by username          #+#    #+#             */
/*   Updated: 2026/04/17 14:30:24 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_data(t_data *data)
{
	int	count;

	count = 0;
	while (count < data->n_philosophers)
	{
		pthread_mutex_destroy(&data->forks[count]);
		pthread_mutex_destroy(&data->philosophers[count].lmt_mutex);
		count++;
	}
	pthread_mutex_destroy(&data->someone_died_mutex);
	pthread_mutex_destroy(&data->print_mutex);
	free(data->philosophers);
	free(data->forks);
	free(data);
}

void	ft_join_threads(t_data *data)
{
	int	count;

	count = 0;
	while (count < data->n_philosophers)
	{
		pthread_join(data->philosophers[count].thread, NULL);
		count++;
	}
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ft_check_args(ac, av) == 0)
		return (ft_putstr_fd("Error: Invalid arguments\n", STDERR_FILENO), 1);
	data = ft_init_data(ac, av);
	if (!data)
		return (ft_putstr_fd("Error: Failed to initialize data\n",
				STDERR_FILENO), 1);
	if (ft_create_philosophers(data) == 1)
		return (ft_putstr_fd("Error: Failed to create philosophers\n",
				STDERR_FILENO), free(data), 1);
	if (ft_create_spectator(data) == 1)
	{
		ft_putstr_fd("Error: Failed to create spectator thread\n",
			STDERR_FILENO);
		free(data->philosophers);
		free(data->forks);
		free(data);
		return (1);
	}
	ft_process_philosophers(data);
	ft_join_threads(data);
	ft_free_data(data);
	return (0);
}

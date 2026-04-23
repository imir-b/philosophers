/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 23:15:11 by vlad              #+#    #+#             */
/*   Updated: 2026/04/23 15:27:42 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_wait_for_philosophers(t_data_bonus *data)
{
	int status;
	int	i;

	i = 0;
	while (i < data->n_philosophers)
	{
		waitpid(-1, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) == 1)
		{
			i = 0;
			while (i < data->n_philosophers)
			{
				kill(data->pids[i], SIGTERM);
				i++;
			}
			break ;
		}
		i++;
	}
}

int	ft_process_philosophers(t_data_bonus *data)
{
	int					id;
	t_philosopher_bonus	*philo;

	id = 0;
	while (id < data->n_philosophers)
	{
		philo = ft_init_philosopher(id + 1, data);
		if (philo == NULL)
			return(ft_putstr_fd(INIT_PHILO_ERR, STDERR_FILENO), 1);
		philo->pid = fork();
		if (philo->pid == 0)
		{
			pthread_create(&philo->thread, NULL, ft_spectator_routine, philo);
			ft_philosopher_routine(philo, data);
			pthread_join(philo->thread, NULL);
			free(philo);
			exit(0);
		}
		else if (philo->pid < 0)
			return(free(philo), ft_putstr_fd(FORK_ERR, STDERR_FILENO), 1);
		data->pids[id] = philo->pid;
		free(philo);
		id++;
	}
	ft_wait_for_philosophers(data);
	return (0);
}

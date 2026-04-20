/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:55:34 by vlad              #+#    #+#             */
/*   Updated: 2026/04/19 16:01:55 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	test(void)
{
	sem_t	*sem;

	sem_unlink("/test_semaphore");
	sem = sem_open("/test_semaphore", O_CREAT, 0644, 1);
	if (sem == SEM_FAILED)
	{
		perror("sem_open");
		exit(EXIT_FAILURE);
	}
	// sem_wait = lock
	// sem_post = unlock
	sem_close(sem);
	sem_unlink("/test_semaphore");
}

int	main(int ac, char **av)
{
	if (ft_check_args(ac, av) == 0)
		return (ft_putstr_fd("Error: Invalid arguments\n", STDERR_FILENO), 1);
	return (0);
}

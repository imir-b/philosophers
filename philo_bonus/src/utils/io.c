/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 02:52:24 by vlad              #+#    #+#             */
/*   Updated: 2026/04/23 13:17:36 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_print_action(t_philosopher_bonus *philosopher, char *action)
{
	long long	timestamp;

	sem_wait(philosopher->data->print_sem);
	timestamp = ft_get_timestamp() - philosopher->data->start_time;
	printf("%lld %d %s\n", timestamp, philosopher->id, action);
	sem_post(philosopher->data->print_sem);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, &*s, 1);
		s++;
	}
}

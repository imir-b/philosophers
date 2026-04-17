/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 02:52:24 by vlad              #+#    #+#             */
/*   Updated: 2026/04/17 14:08:03 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_action(t_philosopher *philosopher, char *action)
{
	long long	timestamp;

	if (ft_check_death(philosopher->data))
		return ;
	pthread_mutex_lock(&philosopher->data->print_mutex);
	timestamp = ft_get_timestamp() - philosopher->data->start_time;
	printf("%lld %d %s\n", timestamp, philosopher->id, action);
	pthread_mutex_unlock(&philosopher->data->print_mutex);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, &*s, 1);
		s++;
	}
}

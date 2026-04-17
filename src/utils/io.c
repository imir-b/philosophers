/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 02:52:24 by vlad              #+#    #+#             */
/*   Updated: 2026/04/17 15:34:52 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_action(t_philosopher *philosopher, char *action)
{
	long long	timestamp;

	pthread_mutex_lock(&philosopher->data->print_mutex);
	if (ft_check_death(philosopher->data))
	{
		pthread_mutex_unlock(&philosopher->data->print_mutex);
		return ;
	}
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

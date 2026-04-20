/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 02:52:24 by vlad              #+#    #+#             */
/*   Updated: 2026/04/20 23:19:27 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_print_action(int id, char *action)
{
	long long	timestamp;

	timestamp = ft_get_timestamp();
	printf("%lld %d %s\n", timestamp, id, action);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, &*s, 1);
		s++;
	}
}

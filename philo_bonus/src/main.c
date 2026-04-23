/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:55:34 by vlad              #+#    #+#             */
/*   Updated: 2026/04/23 15:08:51 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_data_bonus	*data;

	if (ft_check_args(ac, av) == 0)
		return (ft_putstr_fd(ARGS_ERR, STDERR_FILENO), 1);
	data = ft_init_data(ac, av);
	if (data == NULL)
		return (ft_putstr_fd(INIT_DATA_ERR, STDERR_FILENO), 1);
	if (ft_process_philosophers(data) == 1)
	{
		ft_free_data(data);
		return (ft_putstr_fd(PROCESS_ERR, STDERR_FILENO), 1);
	}
	ft_free_data(data);
	return (0);
}

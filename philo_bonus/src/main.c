/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:55:34 by vlad              #+#    #+#             */
/*   Updated: 2026/04/20 23:31:13 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_data_bonus	*data;

	if (ft_check_args(ac, av) == 0)
		return (ft_putstr_fd("Error: Invalid arguments\n", STDERR_FILENO), 1);
	data = ft_init_data(ac, av);
	if (data == NULL)
		return (ft_putstr_fd("Error: Failed to initialize data\n", STDERR_FILENO), 1);
	ft_process_philosophers(data);
	ft_free_data(data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 18:44:48 by vlad              #+#    #+#             */
/*   Updated: 2026/04/20 23:31:37 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <semaphore.h>
# include <sys/time.h>
# include <sys/wait.h>

# include "data_bonus.h"
# include "utils.h"

t_data_bonus    *ft_init_data(int ac, char **av);
void            ft_free_data(t_data_bonus *data);
void            ft_process_philosophers(t_data_bonus *data);

#endif

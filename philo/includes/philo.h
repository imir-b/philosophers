/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 05:05:42 by vbleskin          #+#    #+#             */
/*   Updated: 2026/04/19 19:53:54 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

# include "data.h"
# include "utils.h"

//
// --- CORE FUNCTIONS ---
//
t_data		*ft_init_data(int ac, char **av);
int			ft_create_philosophers(t_data *data);
void		ft_process_philosophers(t_data *data);
void		ft_join_threads(t_data *data);
int			ft_create_spectator(t_data *data);
int			ft_check_death(t_data *data);
void		ft_print_action(t_philosopher *philosopher, char *action);

#endif
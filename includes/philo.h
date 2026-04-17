/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 05:05:42 by vbleskin          #+#    #+#             */
/*   Updated: 2026/04/17 14:46:55 by vbleskin         ###   ########.fr       */
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

//
// --- CORE FUNCTIONS ---
//
int			ft_check_args(int ac, char **av);
t_data		*ft_init_data(int ac, char **av);
int			ft_create_philosophers(t_data *data);
void		ft_process_philosophers(t_data *data);
void		ft_join_threads(t_data *data);
int			ft_create_spectator(t_data *data);
int			ft_check_death(t_data *data);

//
// --- UTILS ---
//
int			ft_atoi(const char *str);
void		ft_putstr_fd(char *s, int fd);
void		ft_print_action(t_philosopher *philosopher, char *action);
long long	ft_get_timestamp(void);

#endif
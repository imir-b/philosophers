/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 18:48:14 by vlad              #+#    #+#             */
/*   Updated: 2026/04/23 15:19:28 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_BONUS_H
# define DATA_BONUS_H

# define MAX_PHILOSOPHERS 200
# define FORK_ERR "Error: Failed to fork philosopher process\n"
# define SEM_ERR "Error: Failed to create semaphore\n"
# define INIT_PHILO_ERR "Error: Failed to initialize philosopher\n"
# define INIT_DATA_ERR "Error: Failed to initialize data\n"
# define ARGS_ERR "Error: Invalid arguments\n"
# define PROCESS_ERR "Error: Failed to process philosophers\n"

typedef struct s_data_bonus				t_data_bonus;

typedef struct s_philosopher_bonus		t_philosopher_bonus;

struct s_data_bonus
{
	int					n_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					n_meals;
	long long			start_time;
	sem_t				*forks;
	sem_t				*print_sem;
	sem_t				*waiter;
	pid_t				pids[MAX_PHILOSOPHERS];
};

struct s_philosopher_bonus
{
	int				id;
	int				eat_count;
	long long		last_meal_time;
	t_data_bonus	*data;
	pid_t			pid;
	pthread_t		thread;
};

#endif

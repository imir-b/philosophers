/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 02:47:03 by vlad              #+#    #+#             */
/*   Updated: 2026/04/17 14:46:57 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

typedef struct s_philosopher			t_philosopher;

typedef struct s_data					t_data;

struct s_philosopher
{
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				eat_count;
	long long		last_meal_time;
	pthread_mutex_t	lmt_mutex;
	pthread_t		thread;
	t_data			*data;
};

struct s_data
{
	int				n_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_meals;
	t_philosopher	*philosophers;
	pthread_mutex_t	*forks;
	long long		start_time;
	int				someone_died;
	pthread_mutex_t	someone_died_mutex;
	pthread_mutex_t	print_mutex;
};

#endif

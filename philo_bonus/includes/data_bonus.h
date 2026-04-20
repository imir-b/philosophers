/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 18:48:14 by vlad              #+#    #+#             */
/*   Updated: 2026/04/17 18:48:19 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_BONUS_H
# define DATA_BONUS_H

typedef struct s_data_bonus			t_data_bonus;

struct s_data_bonus
{
	int				n_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_meals;
	long long		start_time;
	sem_t			*forks;
};

#endif

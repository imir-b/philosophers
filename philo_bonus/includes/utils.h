/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 18:46:46 by vlad              #+#    #+#             */
/*   Updated: 2026/04/19 19:53:48 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int			ft_atoi(const char *str);
void		ft_putstr_fd(char *s, int fd);
long long	ft_get_timestamp(void);
int			ft_check_args(int ac, char **av);

#endif

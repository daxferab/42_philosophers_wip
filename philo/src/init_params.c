/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:46:21 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/20 01:57:30 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_params(char **args, t_dinner *dinner)
{
	dinner->philos_nbr = ft_atoi(args[1]);
	dinner->time_to_die = ft_atoi(args[2]);
	dinner->time_to_eat = ft_atoi(args[3]);
	dinner->time_to_sleep = ft_atoi(args[4]);
	dinner->eating_times = -1;
	if (args[5])
		dinner->eating_times = ft_atoi(args[5]);
	if (dinner->philos_nbr < 1
		|| dinner->time_to_die < 1
		|| dinner->time_to_eat < 1
		|| dinner->time_to_sleep < 1
		|| (args[5] && dinner->eating_times < 1))
		return (printf("All arguments must be a positive int\n"), false);
	dinner->someone_died = false;
    dinner->all_full = false;
    if (pthread_mutex_init(&dinner->death_mutex, NULL))
        return (false);
    return (true);
}

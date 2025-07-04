/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dinner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 01:34:28 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/02 20:11:27 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_forks(t_dinner *dinner);
static bool	init_philos(t_dinner *dinner);

bool	init_dinner(char	**args, t_dinner *dinner)
{
	struct timeval	tv;

	dinner->philos_nbr = ft_atoi(args[1]);
	dinner->time_to_die = ft_atoi(args[2]);
	dinner->time_to_eat = ft_atoi(args[3]);
	dinner->time_to_sleep = ft_atoi(args[4]);
	dinner->eating_times = -1;
	if (args[5])
		dinner->eating_times = ft_atoi(args[5]);
	if (dinner->philos_nbr < 1 || dinner->time_to_die < 1
		|| dinner->time_to_eat < 1 || dinner->time_to_sleep < 1
		|| (args[5] && dinner->eating_times < 1))
		return (printf("All arguments must be a positive int\n"), false);
	dinner->end = false;
	if (!init_forks(dinner))
		return (false);
	if (!init_philos(dinner))
		return (false);
	gettimeofday(&tv, NULL);
	dinner->start_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (true);
}

static bool init_forks(t_dinner *dinner)
{
	int		i;

	i = 0;
	dinner->forks = malloc(sizeof(t_fork) * dinner->philos_nbr + 1);
	while (i < dinner->philos_nbr)
	{
		dinner->forks[i].id = i;
		if (pthread_mutex_init(&dinner->forks[i].fork_id, NULL))
			return(false);
		i++;
	}
	return (true);
}

static bool	init_philos(t_dinner *dinner)
{
	int		i;

	i = 0;
	dinner->philos = malloc(sizeof(t_philo) * dinner->philos_nbr + 1);
	while (i < dinner->philos_nbr)
	{
		dinner->philos[i].id = i + 1;
		dinner->philos[i].meals = 0;
		dinner->philos[i].full = false;
		dinner->philos[i].last_meal = 0;
		dinner->philos[i].right_fork = &dinner->forks[i + 1];
		dinner->philos[i].left_fork = &dinner->forks[i];
		dinner->philos[i].dinner = dinner;
		if (pthread_create(&dinner->philos[i].thread_id, NULL, routine, NULL))
			return (false);
		i++;
	}
	return (true);
}

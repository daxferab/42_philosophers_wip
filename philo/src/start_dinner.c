/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 01:34:28 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/04 20:48:57 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_forks(t_dinner *dinner);
static bool	init_philos(t_dinner *dinner);
static void	assign_forks(t_dinner *dinner, int	i);

bool	start_dinner(char	**args, t_dinner *dinner)
{
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
	if (pthread_mutex_init(&dinner->print, NULL))
		return (false);
	if (!init_forks(dinner))
		return (false);
	dinner->start_time = get_time();
	if (!init_philos(dinner))
		return (false);
	return (true);
}

static bool init_forks(t_dinner *dinner)
{
	int		i;

	i = 0;
	dinner->forks = malloc(sizeof(t_fork) * dinner->philos_nbr);
	while (i < dinner->philos_nbr)
	{
		dinner->forks[i].id = i;
		dinner->forks[i].in_use = false;
		if (pthread_mutex_init(&dinner->forks[i].fork_id, NULL))
			return (false);
		i++;
	}
	return (true);
}

static bool	init_philos(t_dinner *dinner)
{
	int		i;

	i = 0;
	dinner->philos = malloc(sizeof(t_philo) * dinner->philos_nbr);
	while (i < dinner->philos_nbr)
	{
		dinner->philos[i].id = i + 1;
		dinner->philos[i].meals = 0;
		dinner->philos[i].full = false;
		dinner->philos[i].last_meal = 0;
		dinner->philos[i].dinner = dinner;
		assign_forks(dinner,  i);
		if (pthread_create(&dinner->philos[i].thread_id, NULL, routine,
		&(dinner->philos[i])))
			return (false);
		i++;
	}
	return (true);
}

static void	assign_forks(t_dinner *dinner, int	i)
{
	int	n_philos;

	n_philos = dinner->philos_nbr;
	if (i < dinner->philos_nbr - 1)
	{
		dinner->philos[i].left_fork = &(dinner->forks[i]);
		dinner->philos[i].right_fork = &(dinner->forks[(i + 1) % n_philos]);
	}
	else
	{
		dinner->philos[i].right_fork = &(dinner->forks[i]);
		dinner->philos[i].left_fork = &(dinner->forks[(i + 1) % n_philos]);
	}	
}

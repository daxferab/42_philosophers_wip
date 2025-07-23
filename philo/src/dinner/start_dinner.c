/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 01:34:28 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/23 17:52:18 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_forks(t_dinner *dinner);
static bool	init_philos(t_dinner *dinner);
static void	assign_forks(t_dinner *dinner, int i);

bool	start_dinner(t_dinner *dinner)
{
	safe_mutex(&dinner->sim_start_mtx, INIT);
	safe_mutex(&dinner->end_mtx, INIT);
	safe_mutex(&dinner->satisfied_mtx, INIT);
	safe_mutex(&dinner->print_mtx, INIT);
	safe_mutex(&dinner->last_meal_mtx, INIT);
	if (!init_forks(dinner))
		return (false);
	if (!init_philos(dinner))
		return (false);
	safe_thread(&dinner->death, CREATE, death_routine, dinner);
	return (true);
}

static bool	init_forks(t_dinner *dinner)
{
	int		i;

	i = 0;
	dinner->forks = malloc(sizeof(t_fork) * dinner->philos_nbr);
	if (!dinner->forks)
		return (false);
	while (i < dinner->philos_nbr)
	{
		dinner->forks[i].id = i;
		dinner->forks[i].in_use = false;
		safe_mutex(&dinner->forks[i].fork_id, INIT);
		i++;
	}
	return (true);
}

static bool	init_philos(t_dinner *dinner)
{
	int		i;

	i = 0;
	dinner->philos = malloc(sizeof(t_philo) * dinner->philos_nbr);
	if (!dinner->philos)
		return (false);
	safe_mutex(&dinner->sim_start_mtx, LOCK);
	dinner->start_time = get_time(NULL);
	while (i < dinner->philos_nbr)
	{
		dinner->philos[i].id = i + 1;
		dinner->philos[i].meals = 0;
		dinner->philos[i].dinner = dinner;
		safe_mutex(&dinner->last_meal_mtx, LOCK);
		dinner->philos[i].last_meal = get_time(dinner);
		safe_mutex(&dinner->last_meal_mtx, UNLOCK);
		assign_forks(dinner, i);
		safe_thread(&dinner->philos[i].thread_id, CREATE, philo_routine,
			&(dinner->philos[i]));
		i++;
	}
	safe_mutex(&dinner->sim_start_mtx, UNLOCK);
	return (true);
}

static void	assign_forks(t_dinner *dinner, int i)
{
	int	n_philos;

	n_philos = dinner->philos_nbr;
	if (i < n_philos - 1)
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

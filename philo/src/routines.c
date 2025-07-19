/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:50:57 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/20 01:51:10 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *args)
{
    t_philo	*philo;

    philo = (t_philo *)args;
    while (1)
    {
        routine_think(philo);
        routine_eat(philo);
        
        pthread_mutex_lock(&philo->philo_mutex);
        if (philo->full)
        {
            pthread_mutex_unlock(&philo->philo_mutex);
            break;
        }
        pthread_mutex_unlock(&philo->philo_mutex);
        routine_sleep(philo);
    }
    return (args);
}

void	*death_routine(void *args)
{
    t_dinner	*dinner;
    int			i;
    long		starving;

    dinner = (t_dinner *)args;
    i = 0;
    while (1)
    {
        pthread_mutex_lock(&dinner->philos[i].philo_mutex);
        starving = (time_since_start(dinner) - dinner->philos[i].last_meal);
        pthread_mutex_unlock(&dinner->philos[i].philo_mutex);
        
        if (starving >= dinner->time_to_die)
        {
            print_action(&dinner->philos[i], DIE);
            return (NULL);
        }
        i = (i + 1) % dinner->philos_nbr;
        usleep(1000);
    }
    return (NULL);
}

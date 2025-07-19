/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dinner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:13:10 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/20 01:48:23 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_dinner(t_dinner *dinner)
{
    int		i;

    i = 0;
    while (i < dinner->philos_nbr)
    {
        pthread_mutex_destroy(&dinner->philos[i].philo_mutex);
        pthread_mutex_destroy(&dinner->forks[i].fork_id);
        i++;
    }
    pthread_mutex_destroy(&dinner->print);
    free(dinner->philos);
    free(dinner->forks);
    free(dinner);
}

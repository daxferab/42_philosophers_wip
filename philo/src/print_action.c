/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 04:00:29 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/20 01:58:38 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    print_action(t_philo *philo, char *action)
{
    long    time;

    pthread_mutex_lock(&philo->dinner->print);
    
    pthread_mutex_lock(&philo->dinner->death_mutex);
    if (philo->dinner->someone_died && ft_strncmp(action, DIE, 4) != 0)
    {
        pthread_mutex_unlock(&philo->dinner->death_mutex);
        pthread_mutex_unlock(&philo->dinner->print);
        return;
    }
    pthread_mutex_unlock(&philo->dinner->death_mutex);

    time = time_since_start(philo->dinner);
    printf("%ld %d %s\n", time, philo->id, action);
    
    if (ft_strncmp(action, DIE, 4) == 0)
    {
        pthread_mutex_lock(&philo->dinner->death_mutex);
        philo->dinner->someone_died = true;
        pthread_mutex_unlock(&philo->dinner->death_mutex);
    }
    
    pthread_mutex_unlock(&philo->dinner->print);
}

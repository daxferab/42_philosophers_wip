/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:14:16 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/21 21:09:16 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	safe_mutex(pthread_mutex_t *mtx, t_mtxcode action)
{
	int	errno;

	errno = 0;
	if (action == INIT)
		errno = pthread_mutex_init(mtx, NULL);
	else if (action == LOCK)
		errno = pthread_mutex_lock(mtx);
	else if (action == UNLOCK)
		errno = pthread_mutex_unlock(mtx);
	else if (action == DESTROY)
		errno = pthread_mutex_destroy(mtx);
	if (errno != 0)
		exit (0);
	return (errno);
}

int	safe_thread(pthread_t *thread, t_thdcode action, void *func, void *param)
{
	int	errno;

	errno = 0;
	if (action == CREATE)
		errno = pthread_create(thread, NULL, func, param);
	else if (action == JOIN)
		errno = pthread_join(*thread, NULL);
	else if (action == DETACH)
		errno = pthread_detach(*thread);
	if (errno != 0)
		exit (0);
	return (errno);
}

void	safe_usleep(t_philo *philo, int sleep)
{
	int	wake_up;

	wake_up = time_since_start(philo->dinner) + sleep;
	while (time_since_start(philo->dinner) < wake_up)
	{
		if (!sim_continues(philo->dinner))
			break ;
		usleep(500);
	}
}

//TODO: Move function

bool	sim_continues(t_dinner *dinner)
{
	bool	ret_value;

	safe_mutex(&dinner->end_mtx, LOCK);
	ret_value = dinner->end;
	safe_mutex(&dinner->end_mtx, UNLOCK);
	return (!ret_value);
}

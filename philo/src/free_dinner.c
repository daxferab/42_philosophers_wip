/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dinner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:13:10 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/21 18:10:51 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//TODO: Mutex destroy
void	free_dinner(t_dinner *dinner)
{
	if (dinner->philos)
		free(dinner->philos);
	if (dinner->forks)
		free(dinner->forks);
	free(dinner);
}

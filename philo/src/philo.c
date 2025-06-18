/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 21:04:01 by daxferna          #+#    #+#             */
/*   Updated: 2025/06/18 13:01:48 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_dinner	*dinner;

	if (argc < 5 || argc > 6)
		return (printf("Wrong number of arguments\n"), 0);
	dinner = malloc(sizeof(t_dinner));
	if (!dinner)
		return (1);
	if (!init_args(argv, dinner))
		return (free(dinner), 1);
	if (!init_members(dinner))
		return (free(dinner), 1);
	//start_dinner();
	free(dinner);
	return (0);
}

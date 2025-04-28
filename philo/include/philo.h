/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 21:17:49 by daxferna          #+#    #+#             */
/*   Updated: 2025/04/28 03:51:53 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>

// STRUCTS

typedef struct s_param
{
	int	philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int eating_times;
} t_param;

// OUTPUT

void	print_error(char *errmsg);

// PARSE

bool	init_args(char	**args, t_param *param);

#endif

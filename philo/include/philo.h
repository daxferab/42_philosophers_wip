/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 21:17:49 by daxferna          #+#    #+#             */
/*   Updated: 2025/04/29 16:49:01 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "died"

// STRUCTS

typedef struct s_philo t_philo;
typedef struct s_fork t_fork;

typedef struct s_param
{
	int		philos_nbr;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		eating_times;
	long	start_time;
	bool	end;
	t_fork	*forks;
	t_philo	*philos;
}	t_param;

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	fork;
}	t_fork;

typedef struct s_philo
{
	int			id;
	int			meals;
	bool		full;
	long		last_meal;
	t_fork		*right_fork;
	t_fork		*left_fork;
	pthread_t	thread_id;
	t_param		parameters;
}	t_philo;

// ENUM
typedef enum e_mutexcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DEATACH,
} t_mutexcode;

// OUTPUT

void	print_action(int philo, char *action);
void	print_error(char *errmsg);

// PARSE

bool	init_args(char **args, t_param *param);
bool	init_members(t_param *param);

#endif

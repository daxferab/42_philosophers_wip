/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 21:17:49 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/04 19:38:58 by daxferna         ###   ########.fr       */
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

# define FORK	"has taken a fork"
# define EAT	"is eating"
# define SLEEP	"is sleeping"
# define THINK	"is thinking"
# define DIE	"died"

// STRUCTS

typedef struct s_philo	t_philo;
typedef struct s_fork	t_fork;

typedef struct s_dinner
{
	int				philos_nbr;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eating_times;
	long			start_time;
	bool			end;
	pthread_mutex_t	print;
	t_philo			*philos;
	t_fork			*forks;
}	t_dinner;

typedef struct s_fork
{
	int				id;
	bool			in_use;
	pthread_mutex_t	fork_id;
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
	t_dinner	*dinner;
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
}	t_mutexcode;

// join_philos.c

bool	join_philos(t_dinner *dinner);

// ROUTINES

void	routine_eat(t_philo *philo);
void	routine_sleep(t_philo *philo);
void	routine_think(t_philo *philo);
void	*routine(void	*args);

// start_dinner.c

bool	start_dinner(char **args, t_dinner *dinner);

// UTILS

void	free_dinner(t_dinner *dinner);
void	print_action(t_philo *philo, long start, char *action);
int		ft_atoi(char *n);
bool	ft_isdigit(int c);
bool	ft_isspace(int c);
long	get_time();

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 21:17:49 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/22 21:33:02 by daxferna         ###   ########.fr       */
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
	pthread_mutex_t	sim_start_mtx;
	bool			end;
	pthread_mutex_t	end_mtx;
	int				satisfied;
	pthread_mutex_t	satisfied_mtx;
	pthread_mutex_t	print_mtx;
	pthread_mutex_t	last_meal_mtx;
	pthread_t		death;
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
	int				id;
	int				meals;
	long			last_meal;
	t_fork			*right_fork;
	t_fork			*left_fork;
	pthread_t		thread_id;
	t_dinner		*dinner;
}	t_philo;

typedef enum e_mtxcode
{
	INIT,
	LOCK,
	UNLOCK,
	DESTROY
}	t_mtxcode;

typedef enum e_thdcode
{
	CREATE,
	JOIN,
	DETACH
}	t_thdcode;

// DINNER

bool	init_params(char **args, t_dinner *dinner);
bool	join_philos(t_dinner *dinner);
bool	start_dinner(t_dinner *dinner);


// ROUTINES

void	*death_routine(void *args);

void	*philo_routine(void	*args);

void	routine_eat(t_philo *philo);
void	routine_sleep(t_philo *philo);
void	routine_think(t_philo *philo);

// UTILS

bool	sim_continues(t_dinner *dinner);
void	end_sim(t_dinner *dinner);

void	free_dinner(t_dinner *dinner, bool destroy);

long	time_since_start(t_dinner *dinner);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(char *n);
bool	ft_isdigit(int c);
bool	ft_isspace(int c);

void	print_action(t_philo *philo, char *action);

int		safe_mutex(pthread_mutex_t *mtx, t_mtxcode action);
int		safe_thread(pthread_t *thrd, t_thdcode action, void *func, void *param);
void	safe_usleep(t_philo *philo, int sleep);

#endif

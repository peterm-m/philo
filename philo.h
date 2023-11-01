/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:08:18 by pedromar          #+#    #+#             */
/*   Updated: 2023/11/01 19:37:54 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/types.h>
# include <sys/time.h>

# include <pthread.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "locks.h"

# define MSG_EAT "is eating"
# define MSG_THINK "is thinking"
# define MSG_SLEEP "is sleeping"
# define MSG_FORK_TAKE_R "has taken right fork"
# define MSG_FORK_TAKE_L "has taken left fork"
# define MSG_FORK_LEFT_R "has left the right fork"
# define MSG_FORK_LEFT_L "has left the left fork"
# define MSG_DIE "died"

enum
{
	LEFT = 1,
	RIGHT = 2
};

enum
{
	DIE,
	SLEEP,
	EAT
};

# define PTHREAD_THREAD_MAX 256

typedef long long int	t_time;

typedef struct s_input
{
	int		number_of_philo;
	t_time	times[3];
	int		number_of_eats;
}	t_input;

typedef struct s_share
{
	int				number_of_philo;
	int				number_of_eats;
	t_time			times[3];
	t_flag			stop;
	t_counter		turn;
	t_counter		end_turn;
	t_counter		complete;
	t_counter		dies;
	pthread_t		thread[PTHREAD_THREAD_MAX];
	pthread_mutex_t	forks[PTHREAD_THREAD_MAX];
}	t_share;

typedef struct s_local
{
	int		id;
	int		eats;
	t_time	time_from_eat;
	t_share	*share;
}	t_local;

long long int	get_uint(const char *str);
void			print_action(t_local *philo, const char *log);
t_time			ph_get_time(void);
int				philosopher(void *input);
void			*philo_live(void *philo);
void			management(t_share *share, t_local *philo);

#endif
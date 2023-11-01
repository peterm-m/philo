/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:16:43 by pedromar          #+#    #+#             */
/*   Updated: 2023/11/01 18:47:09 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_sleep(t_local *philo)
{
	print_action(philo, MSG_SLEEP);
	usleep(philo->share->times[SLEEP] * 1000);
	print_action(philo, MSG_THINK);
	count_increment(&philo->share->end_turn);
}

static void	philo_take_fork(t_local *philo, int side)
{
	if (side == LEFT)
	{
		print_action(philo, MSG_FORK_TAKE_L);
		pthread_mutex_lock(&philo->share->forks[(philo->id -1)
			% philo->share->number_of_philo]);
	}
	else if (side == RIGHT)
	{
		print_action(philo, MSG_FORK_TAKE_R);
		pthread_mutex_lock(&philo->share->forks[philo->id
			% philo->share->number_of_philo]);
	}
	else if (side == -LEFT)
	{
		print_action(philo, MSG_FORK_LEFT_L);
		pthread_mutex_unlock(&philo->share->forks[(philo->id -1)
			% philo->share->number_of_philo]);
	}
	else if (side == -RIGHT)
	{
		print_action(philo, MSG_FORK_LEFT_R);
		pthread_mutex_unlock(&philo->share->forks[philo->id
			% philo->share->number_of_philo]);
	}
}

static void	philo_eat(t_local *philo)
{
	philo_take_fork(philo, LEFT);
	philo_take_fork(philo, RIGHT);
	print_action(philo, MSG_EAT);
	usleep(philo->share->times[EAT]);
	philo_take_fork(philo, -LEFT);
	philo_take_fork(philo, -RIGHT);
	philo->time_from_eat = 0;
	count_increment(&philo->share->end_turn);
	if (++philo->eats == philo->share->number_of_eats)
		count_increment(&philo->share->complete);
}

void	*philo_live(void *a)
{
	t_local	*local;

	local = (t_local *)a;
	wait_flag(&local->share->stop);
	while (1)
	{
		wait_flag(&local->share->stop);
		if (local->id % 2 == count_get(&local->share->turn))
			philo_eat(local);
		philo_sleep(local);
	}
	return (NULL);
}

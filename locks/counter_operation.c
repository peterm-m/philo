/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:06:52 by pedromar          #+#    #+#             */
/*   Updated: 2023/10/31 15:09:25 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "locks.h"

void	count_increment(t_counter *c)
{
	pthread_mutex_lock(&c->lock);
	c->value++;
	pthread_mutex_unlock(&c->lock);
}

void	count_decrement(t_counter *c)
{
	pthread_mutex_lock(&c->lock);
	c->value--;
	pthread_mutex_unlock(&c->lock);
}

int	count_get(t_counter *c)
{
	int	rc;

	pthread_mutex_lock(&c->lock);
	rc = c->value;
	pthread_mutex_unlock(&c->lock);
	return (rc);
}

void	count_set(t_counter *c, int value)
{
	pthread_mutex_lock(&c->lock);
	c->value = value;
	pthread_mutex_unlock(&c->lock);
}

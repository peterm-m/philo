/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:06:36 by pedromar          #+#    #+#             */
/*   Updated: 2023/10/31 18:40:40 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "locks.h"

int	count_init(t_counter *c, int init)
{
	if (c == NULL)
		return (0);
	c->value = init;
	return (pthread_mutex_init(&c->lock, NULL));
}

t_counter	*count_new(int init)
{
	t_counter	*c;

	c = (t_counter *)malloc(sizeof(t_counter));
	if (c == NULL)
		return (NULL);
	if (count_init(c, init))
	{
		free(c);
		return (NULL);
	}
	return (c);
}

void	count_delete(t_counter *c)
{
	pthread_mutex_destroy(&c->lock);
	free(c);
}

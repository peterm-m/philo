/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:06:43 by pedromar          #+#    #+#             */
/*   Updated: 2023/10/31 20:58:34 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOCKS_H
# define LOCKS_H

# include <stdlib.h>
# include <pthread.h>

typedef struct s_flag
{
	pthread_mutex_t	flag;
}	t_flag;

t_flag		*flag_new(void);
int			flag_init(t_flag *f);
void		flag_delete(t_flag *f);
void		wait_flag(t_flag *f);
void		lock_flag(t_flag *f);
void		unlock_flag(t_flag *f);

typedef struct s_counter
{
	int				value;
	pthread_mutex_t	lock;
}	t_counter;

t_counter	*count_new(int init);
int			count_init(t_counter *c, int init);
void		count_delete(t_counter *c);
void		count_increment(t_counter *c);
void		count_decrement(t_counter *c);
int			count_get(t_counter *c);
void		count_set(t_counter *c, int value);

#endif

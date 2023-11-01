/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:58:01 by pedromar          #+#    #+#             */
/*   Updated: 2023/11/01 14:06:24 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_time	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_action(t_local *philo, const char *log)
{
	static pthread_mutex_t	screen = PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&screen);
	printf("%lld %d %s\n", philo->time_from_eat, philo->id, log);
	pthread_mutex_unlock(&screen);
	return ;
}

static long long int	ft_atol(const char *str)
{
	unsigned long long int	c;
	int						sing;

	c = 0LL;
	sing = 1;
	while (*str == ' ' || (*str < 14 && *str > 8))
		str++;
	if (*str == '-' || *str == '+')
	{
		sing = 44 - *str;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		c = (c * 10) + (*str - '0');
		str++;
	}
	if (c > LONG_MAX && sing == 1)
		return (-1);
	if (c > (unsigned long long int)(-LLONG_MIN) && sing == -1)
		return (0);
	return (c * sing);
}

static int	isnum(const char *str)
{
	while (*str == ' ' || (*str < 14 && *str > 8))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str != '\0')
		return (0);
	else
		return (1);
}

long long int	get_uint(const char *str)
{
	long long int	res;

	if (isnum(str) == 0)
		return (0);
	res = ft_atol(str);
	if (res > INT_MAX || res < 0)
		return (-1);
	return (res);
}

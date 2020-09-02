/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:43:07 by khelen            #+#    #+#             */
/*   Updated: 2019/09/19 20:47:15 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		atoiblank(const char *str)
{
	int i;

	i = 0;
	while (!(*str >= '0' && *str <= '9' && *str != '-'))
	{
		if (*str == '\t' || *str == '\v' || *str == '\r')
			str++;
		else if (*str == '\n' || *str == '\f' || *str == ' ')
			str++;
		else
			break ;
		i++;
	}
	return (i);
}

int				ft_atoi(const char *str)
{
	long	num;
	int		mult;
	int		n;

	num = 0;
	mult = 1;
	n = atoiblank(str);
	if (str[n] == '-' || str[n] == '+')
	{
		if (str[n] == '-')
			mult = -1;
		n++;
	}
	while (str[n] >= '0' && str[n] <= '9' && str)
	{
		if (num >= 2147483647 && mult == 1)
			return (-1);
		if (num > 2147483647 && mult == -1)
			return (0);
		num = num * 10 + (str[n] - '0');
		n++;
	}
	return (num * mult);
}

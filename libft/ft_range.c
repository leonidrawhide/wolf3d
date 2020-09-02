/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:58:21 by khelen            #+#    #+#             */
/*   Updated: 2019/09/05 19:43:14 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int n;
	int *arr;

	n = 0;
	if (max <= min)
		return (0);
	arr = malloc(sizeof(int) * (max - min));
	while (min < max)
	{
		arr[n] = min;
		n++;
		min++;
	}
	return (arr);
}

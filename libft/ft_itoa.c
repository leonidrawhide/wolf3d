/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:58:11 by khelen            #+#    #+#             */
/*   Updated: 2019/09/20 17:19:09 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_itoa(int n)
{
	int				i;
	unsigned int	k;
	char			*str;

	i = ft_intlen(n);
	if (!(str = ft_strnew(i)))
		return (NULL);
	str[i--] = '\0';
	if (n < 0)
	{
		k = -n;
		str[0] = '-';
	}
	else
		k = n;
	while (k > 9)
	{
		str[i--] = (k % 10) + '0';
		k /= 10;
	}
	str[i] = (k % 10) + '0';
	return (str);
}

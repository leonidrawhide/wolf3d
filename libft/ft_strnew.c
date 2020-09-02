/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:01:58 by khelen            #+#    #+#             */
/*   Updated: 2019/09/19 14:04:11 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char			*i;
	unsigned int	n;

	if (size + 1 == 0)
		return (NULL);
	if (!(i = (char*)malloc(size + 1)))
		return (NULL);
	n = (unsigned int)size;
	ft_bzero(i, size);
	i[n] = '\0';
	return (i);
}

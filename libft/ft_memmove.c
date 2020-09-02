/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:04:07 by khelen            #+#    #+#             */
/*   Updated: 2019/09/20 14:59:27 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	register char		*dp;
	register char const	*sp;

	dp = dst;
	sp = src;
	if (!dst && !src)
		return (NULL);
	if (dp < sp)
	{
		while (len-- > 0)
			*dp++ = *sp++;
	}
	else
	{
		dp += len;
		sp += len;
		while (len-- > 0)
			*--dp = *--sp;
	}
	return (dst);
}

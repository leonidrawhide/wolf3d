/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:54:20 by khelen            #+#    #+#             */
/*   Updated: 2019/09/15 16:41:54 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dp;
	const char	*sp;

	dp = (char*)dest;
	sp = (const char*)src;
	if (dest == NULL && src == NULL)
		return (dest);
	while (n > 0)
	{
		n--;
		*dp++ = *sp++;
	}
	return (dest);
}

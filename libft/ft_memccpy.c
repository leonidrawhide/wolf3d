/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:47:15 by khelen            #+#    #+#             */
/*   Updated: 2019/09/15 16:32:16 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	const char	*s;
	char		*d;

	s = (const char*)src;
	d = (char*)dest;
	while (n-- > 0)
		if ((*d++ = *s++) == (char)c)
			return (d);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:55:05 by khelen            #+#    #+#             */
/*   Updated: 2019/09/17 18:56:49 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	slen;
	int		i;
	int		n;

	i = 0;
	n = 0;
	len = 0;
	slen = ft_strlen((char*)src);
	while (dst[i] && size > 0)
	{
		i++;
		len++;
		size--;
	}
	while (src[n] && size > 1)
	{
		dst[i++] = src[n++];
		size--;
	}
	if (size == 1 || src[n] == '\0')
		dst[i] = '\0';
	return (slen + len);
}

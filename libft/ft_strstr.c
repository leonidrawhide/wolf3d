/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:26:34 by khelen            #+#    #+#             */
/*   Updated: 2019/09/13 18:51:35 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t n;

	n = ft_strlen((char*)needle);
	if (ft_memcmp(haystack++, needle, n) == 0)
		return ((char*)haystack - 1);
	while (*haystack != '\0')
	{
		if (ft_memcmp(haystack++, needle, n) == 0)
			return ((char*)haystack - 1);
	}
	return (NULL);
}

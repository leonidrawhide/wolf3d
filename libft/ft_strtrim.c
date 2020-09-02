/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:37:33 by khelen            #+#    #+#             */
/*   Updated: 2019/09/19 20:50:11 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_isspace(int c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

static int		ft_end(const char *s, int end)
{
	while (ft_isspace(s[end]))
		end--;
	return (end);
}

char			*ft_strtrim(const char *s)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	start = 0;
	end = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (ft_isspace(s[start]))
		start++;
	end = ft_strlen((char*)s) - 1;
	end = ft_end(s, end);
	if (s[start] == '\0')
	{
		if (!(str = ft_memalloc(1)))
			return (NULL);
	}
	else if (!(str = ft_memalloc(end - start + 2)))
		return (NULL);
	while (start <= end)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

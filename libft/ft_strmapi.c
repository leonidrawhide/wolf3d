/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:11:41 by khelen            #+#    #+#             */
/*   Updated: 2019/09/15 19:23:13 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ptr;
	char			*res;

	if (s == NULL || !(res = ft_memalloc((size_t)ft_strlen((char*)s) + 1)))
		return (NULL);
	i = 0;
	ptr = res;
	while (s[i])
	{
		*ptr++ = f(i, s[i]);
		i++;
	}
	return (res);
}

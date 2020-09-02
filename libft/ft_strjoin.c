/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:57:41 by khelen            #+#    #+#             */
/*   Updated: 2019/09/19 21:42:36 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*substr;
	size_t	ss1;
	size_t	ss2;

	if (!s1 || !s2)
		return (NULL);
	ss1 = ft_strlen((char*)s1);
	ss2 = ft_strlen((char*)s2);
	if ((ss1 + 1 == 0) || (ss2 + 1 == 0))
		return (NULL);
	if (!(substr = ft_memalloc(ss1 + ss2 + 1)))
		return (NULL);
	ft_memcpy(substr, s1, ss1);
	ft_memcpy(substr + ss1, s2, ss2);
	return (substr);
}

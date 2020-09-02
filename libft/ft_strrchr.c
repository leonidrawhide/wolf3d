/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:09:45 by khelen            #+#    #+#             */
/*   Updated: 2019/09/13 16:21:26 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *r;

	r = 0;
	if (*s == (char)c)
		r = (char*)s;
	while (*s++)
	{
		if (*s == (char)c)
			r = (char*)s;
	}
	return (r);
}
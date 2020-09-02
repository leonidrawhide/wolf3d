/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:39:08 by khelen            #+#    #+#             */
/*   Updated: 2019/09/15 19:56:49 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*substr;

	if (s == NULL || !(substr = ft_memalloc((len) + 1)))
		return (NULL);
	return (ft_strncpy(substr, (char*)s + start, len));
}

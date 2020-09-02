/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:51:34 by khelen            #+#    #+#             */
/*   Updated: 2019/09/20 14:22:00 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(char *s1, char *s2)
{
	int n;

	n = 0;
	while (s1[n] && s2[n] && s1[n] == s2[n])
		n++;
	return ((unsigned char)s1[n] - (unsigned char)s2[n]);
}
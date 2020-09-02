/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 18:53:43 by khelen            #+#    #+#             */
/*   Updated: 2019/09/16 19:21:47 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int i;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		i = (unsigned int)(n * -1);
	}
	else
		i = (unsigned int)n;
	if (i >= 10)
		ft_putnbr_fd(i / 10, fd);
	ft_putchar_fd((char)(i % 10 + 48), fd);
}

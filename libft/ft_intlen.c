/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:04:27 by khelen            #+#    #+#             */
/*   Updated: 2019/09/20 17:04:32 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_intlen(int n)
{
	int				i;
	unsigned int	k;

	i = 0;
	if (n < 0)
	{
		k = -n;
		i++;
	}
	else
		k = n;
	while (k > 9)
	{
		k /= 10;
		i++;
	}
	i++;
	return (i);
}
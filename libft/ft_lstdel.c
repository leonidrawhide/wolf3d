/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:12:50 by khelen            #+#    #+#             */
/*   Updated: 2019/09/19 14:32:05 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*curr;
	t_list	*next;

	curr = *alst;
	while (curr)
	{
		next = curr->next;
		del(curr->content, curr->content_size);
		free(curr);
		curr = next;
	}
	*alst = NULL;
}

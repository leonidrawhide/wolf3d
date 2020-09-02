/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:35:50 by khelen            #+#    #+#             */
/*   Updated: 2020/02/13 13:38:09 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static char		*check_remainer(char *remainer, char **pointer)
{
	char *p;

	p = NULL;
	if ((*pointer = ft_strchr(remainer, '\n')) != NULL)
	{
		p = ft_strsub(remainer, 0, *pointer - remainer);
		ft_strcpy(remainer, ++(*pointer));
	}
	else
	{
		p = ft_strnew(ft_strlen(remainer) + 1);
		ft_strcat(p, remainer);
		ft_strclr(remainer);
	}
	return (p);
}

static int		get_line(const int fd, char **line, char *remainer)
{
	char		buf[BUFF_SIZE + 1];
	int			byte_read;
	char		*pointer;
	char		*temp;

	pointer = NULL;
	byte_read = 1;
	*line = check_remainer(remainer, &pointer);
	while (!pointer && (byte_read = read(fd, buf, BUFF_SIZE)))
	{
		buf[byte_read] = '\0';
		if ((pointer = ft_strchr(buf, '\n')))
		{
			ft_strcpy(remainer, ++pointer);
			ft_strclr(--pointer);
		}
		temp = *line;
		if (!(*line = ft_strjoin(*line, buf)) || byte_read < 0)
			return (-1);
		free(temp);
	}
	if (byte_read || ft_strlen(*line) || ft_strlen(remainer))
		return (1);
	return (0);
}

static t_gnl	*new_linked_list(const int fd)
{
	t_gnl	*new;

	if (!(new = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	new->fd = fd;
	new->remainer = ft_strnew(BUFF_SIZE);
	new->next = NULL;
	return (new);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*head;
	t_gnl			*temp;

	if (fd < 0 || line == NULL)
		return (-1);
	if (head == NULL)
		head = new_linked_list(fd);
	temp = head;
	while (temp->fd != fd)
	{
		if (temp->next == NULL)
			temp->next = new_linked_list(fd);
		temp = temp->next;
	}
	return (get_line(temp->fd, line, temp->remainer));
}

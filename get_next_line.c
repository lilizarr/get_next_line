/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:53:20 by lilizarr          #+#    #+#             */
/*   Updated: 2022/11/18 18:13:32 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	add_node_to_list(t_list **list, char *read_buffer, int ret)
{
	t_list	*new_node;
	t_list	*last;

	new_node = (t_list *)malloc (sizeof(t_list));
	if (!new_node)
		*list = NULL;
	new_node->str = ft_strdup_len(read_buffer, ret);
	new_node->next = NULL;
	if (!(*list))
		*list = new_node;
	else
	{
		last = *list;
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
		while (last->next != NULL)
			last = last->next;
	}
}

void	free_node_list(void **list)
{
	t_list	*tmp;
	t_list	*to_erase;
	int		i;

	i = 0;
	to_erase = *list;
	tmp = to_erase->next;
	free(to_erase->str);
	free(to_erase);
	*list = tmp;
}

void	search_line_ext(t_list **list, char **line, char *ptr)
{
	int		diff_nl;
	char	*tmp;

	diff_nl = ptr - ((*list)->str);
	if (!(*line))
		*line = ft_strdup_len((*list)->str, diff_nl + 1);
	else
	{
		tmp = ft_strdup_len((*list)->str, diff_nl + 1);
		*line = ft_strjoin(*line, tmp);
		free(tmp);
	}
	if ((ft_strlen(ptr + 1)))
	{
		tmp = ft_strdup_len(ptr + 1, ft_strlen(ptr + 1));
		free((*list)->str);
		(*list)->str = tmp;
	}
	else
		free_node_list((void *)(*&list));
}

void	search_line(t_list **list, char **line)
{
	char	*ptr;

	while ((*list))
	{
		ptr = ft_strchr((*list)->str, '\n');
		if (ptr)
		{
			search_line_ext((&*list), (&*line), ptr);
			return ;
		}
		else
		{
			if (!(*line))
				*line = ft_strdup_len((*list)->str, ft_strlen((*list)->str));
			else
				*line = ft_strjoin(*line, (*list)->str);
			free_node_list((void *)(*&list));
		}
	}
}

char	*get_next_line(int fd)
{
	static t_list		*list;
	int					ret;
	char				*line;
	char				*read_buffer;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	read_buffer = (char *)malloc(BUFFER_SIZE);
	if (!read_buffer)
		return (NULL);
	read_buffer[BUFFER_SIZE] = 0;
	while (1)
	{
		ret = read(fd, read_buffer, BUFFER_SIZE);
		if (!ret || ret < 0)
			break ;
		else
			add_node_to_list(&list, read_buffer, ret);
	}
	free(read_buffer);
	search_line(&list, &line);
	return (&*line);
}

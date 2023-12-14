/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:40:55 by lilizarr          #+#    #+#             */
/*   Updated: 2022/11/18 14:11:24 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
// extra

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
/* linked list functions*/
//t_list	*create_empty_list(void);
void	add_node_to_list(t_list **list, char *new_str, int ret);
void	free_node_list(void **list);
/*	libft utils functions	*/
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
/* Copies n charactarcters from s1 */
char	*ft_strdup_len(char *s1, size_t n);
void	search_line(t_list **list, char **line_read);
void	search_line_ext(t_list **list, char **line, char *ptr);
/*	testing functions main	*/
void	check_after_string_data(char *buf, int ret, int extra);
void	print_list(t_list **list);
#endif
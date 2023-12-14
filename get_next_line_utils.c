/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:35:09 by lilizarr          #+#    #+#             */
/*   Updated: 2022/11/17 14:43:03 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{	
	size_t	cnt;

	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

char	*ft_strchr(const char *s, int c)
{	
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (!(*s) && !c)
		return ((char *)s);
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = n - 1;
	while (n-- && (dest != NULL || src != NULL))
	{
		((char *)dest)[i - n] = (*(const char *)(src + (i - n)));
	}
	return (dest);
}

char	*ft_strdup_len(char *s1, size_t n)
{
	char	*aux;

	aux = (char *)malloc(n + 1);
	if (aux == NULL)
		return (NULL);
	aux = ft_memcpy(aux, s1, n);
	aux[n] = '\0';
	return (aux);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sj;

	if (s1 && s2)
	{
		sj = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (sj)
		{
			ft_memcpy(sj, s1, ft_strlen(s1));
			ft_memcpy(sj + ft_strlen(s1), s2, ft_strlen(s2) + 1);
			free((void *)s1);
			return ((char *)sj);
		}
		else
			return (NULL);
	}
	else
		return (NULL);
}

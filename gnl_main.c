/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:40:06 by lilizarr          #+#    #+#             */
/*   Updated: 2022/11/18 19:59:14 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <stdlib.h>
#include <assert.h>

void	print_list(t_list **list)
{
	t_list	*print;
	int		i;

	i = 0;
	print = *list;
	printf("\n\n------ %d ------- List HEAD Address : %p\t \t\n", i++, *list);
	while (print)
	{
		printf("\n\n-- list = %p \tlist->str = %p \tstr_len = %zu \tlist->next = %p \t --\n", print, print->str, ft_strlen((*list)->str), print->next);
		check_after_string_data(print->str, ft_strlen((*list)->str), 1);
		print = print->next;
	}
	printf("\n------------  END LIST ------------\n\n");
}

void	check_after_string_data(char *str, int ret, int extra)
{
	int		i;
	char	*buf;

	if ((*str))
	{
		i = 0;
		buf = str;
		printf("\n -- [%p] %zu\n", buf, ft_strlen(buf));
		while (i < ret + extra)
		{
			if (!strchr("\t\n\r\v\f", buf[i]))
				printf("%d_[ %p ]{ %c }", i, (buf + i), *(buf + i));
			else
				printf("%d_[ %p ]( %d )", i, (buf + i),*(buf + i));
			if (i % 2 == 0)
				printf("\t\t");
			else
				printf("\n");
			i++;
		}
	}
	else
		printf("\n ** null \n");
}

// void	sizes(void)
// {
// 	printf("---------------------------\nINT_MAX\t\t=\t%d\nLONG_MAX\t=\t%ld\nLL_MAX\t\t=\t%lld\nULL_MAX\t\t=\t%llu\n---------------------------\n", INT_MAX, LONG_MAX, LLONG_MAX, ULLONG_MAX);
// 	printf("BUFSIZ\t\t=\t%d \n",BUFSIZ);
// 	printf("SIZE_MAX\t\t=\t%lu \n", SIZE_MAX);
// 	printf("OPEN_MAX \t\t=\t%d \n", OPEN_MAX);
// }


int	main(void)
{
	int		stop;
	int		line;
	int		fd;
	char	*str;
	char	*str2;

	//str = "0123456789012345678901234567890123456789\n";
	//str = "ABC\n\n\nDEFGHIJ\nKLMN\nOPQ\nRS\nTUVWXYZ\t\n123\n456\n789ABCS\nFDGH";
	// printf("%s\n", str);
	// // printf("{ \n%d ", line);
	// // while (str[stop])
	// // {
	// // 	printf("%c", str[stop]);
	// // 	if (str[stop] == '\n')
	// // 		printf("%d ", ++line);
	// // 	stop++;
	// // }
	// printf("}\n");
	//sizes();
	//printf("%p", str);
	// fd = open("file1", O_RDWR | O_CREAT, 0777);
	// write(fd, str, strlen(str));
	// close(fd);
	// fd = open("file1", O_RDWR);
	// fd = open("file2", O_RDWR);
	// fd = open("../files/empty", O_RDWR);
	// fd = open("../files/nl", O_RDWR);
	// fd = open("../files/41_no_nl", O_RDWR);
	// fd = open("../files/41_with_nl", O_RDWR);
	//fd = open("../files/42_no_nl", O_RDWR);
	fd = open("../files/42_with_nl", O_RDWR);
	//  fd = open("../files/43_no_nl", O_RDWR);
	// fd = open("../files/43_with_nl", O_RDWR);
	// fd = open("../files/multiple_nlx5", O_RDWR);
	// fd = open("../files/multiple_line_no_nl", O_RDWR);
	// fd = open("../files/multiple_line_with_nl", O_RDWR);
	// fd = open("../files/alternate_line_nl_no_nl", O_RDWR);
	// fd = open("../files/alternate_line_nl_with_nl", O_RDWR);
	// fd = open("../files/big_line_no_nl", O_RDWR);
	// fd = open("../files/big_line_with_nl", O_RDWR);
	str = NULL;
	// printf("str = %p\n", str);
	// fd = open("../files/alternate_line_nl_with_nl", O_RDWR);
	// printf("FILE DESCRIPTOR ID = %d,\n", fd);
	line = 1;
	while (1)
	{
		str= get_next_line(fd);
		printf("str = %p\n", str);
		printf("%d\n", line);
		if (str == NULL)
		{
			free(str);
			break ;
		}
		printf(" %s \t\t\t\t [%zu] [%p]\n", str, ft_strlen(str), str);
		// if (str == 0)
		// {
		// 	free(str);
		// 	break ;
		// }
		line++;
	}
	// printf("------- MAIN gnl------ \n Line returned \t\t=\t | %s |", str);
	//check_after_string_data(str, 5);
	if (close(fd) == -1)
	{
		printf("| Error closing file |");
		return (1);
	}
	//sleep(100);
	//remove("file1");
	return (0);
}

// int	main(int argc, char **argv)
// {
	// FILE	*fp;
	// size_t	len;
	// ssize_t	read;
	// char	*line;

	// fp = fopen("file", "r");
	// if (fp == NULL)
	// 	exit(EXIT_FAILURE);
	// while ((read = getline(&line, &len, fp)) != -1)
	// {
	// 	printf("Retrieved line of length %zu :\n", read);
	// 	printf("%s", line);
	// }
	// free(line);
// 	return (0);
// }
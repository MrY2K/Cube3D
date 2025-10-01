/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:54:13 by achoukri          #+#    #+#             */
/*   Updated: 2025/10/01 22:49:28 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"
#include "lib/libft.h"
#include <stdio.h>
#include <stdlib.h> // Added for malloc and free


void print_char_array(char **arr)
{
    if (!arr)
    {
        printf("Array is NULL :C\n");
        return ;
    }

    int i = 0;
    while (arr[i] != NULL)
    {
        printf("String[%d]: %s\n", i, arr[i]);
        i++;
    }
}

char **extract_header(int fd, char *file)
{
	// Extract First 6 lines + store them in Header

	// Validate them
		// is the structre intact meaning the order is correct: -> check first 2 chars of each string
		// is the file exist + permissions 
		// is colors valid
	return (NULL);
}

void	read_map(int fd, char *file)
{
	//? Extract lines + skip empty ones + store them 
	// First pass: count lines
	int line_count = 0;
	char *line;
	while ((line = get_next_line_no_nl(fd)) != NULL)
	{
		if (line[0] != '\0')
		{
			line_count++;
			free(line);
		}
	}

    printf("Line count:%d\n", line_count);

	// Reset file position
	close(fd);
	fd = get_fd(file); // Reopen file

	// Allocate array
	char **tmp = malloc(sizeof(char *) * (line_count + 1));
	if (!tmp)
		return ;

	// Second pass: store lines
	int i = 0;
	while ((line = get_next_line_no_nl(fd)) != NULL)
	{
		if (line[0] != '\0')
		{
			tmp[i] = line;
			i++;	
		}
	}
	tmp[i] = NULL;

	print_char_array(tmp);

	///////////////////////////////////////////////////
	char **header = extract_header(fd, file);
	(void)header;
	// char **map = extract_map(fd);
}

int	main(int ac, char **av)
{
	char			*file;
	int				fd;

	file = av[1];
	check_file(av, ac);
	fd = get_fd(file); //todo: remember to close this after parsing the map
	read_map(fd, file);
	
	close(fd); // Don't forget to close!	
}

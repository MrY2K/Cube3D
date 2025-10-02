/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:54:13 by achoukri          #+#    #+#             */
/*   Updated: 2025/10/03 00:53:32 by achoukri         ###   ########.fr       */
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

int		validate_header(t_data *data)
{
	// Validate header
		// is the structre intact meaning the order is correct: -> check first 2 chars of each string
		// is the file exist + permissions 
		// is colors valid
	return (VALID);
}

//* Extract lines + skip empty ones + store them in header tmp
char	**extract_header(t_data *data)
{
	char	*line;
	int		line_count;
	int		i;
	char	**header_tmp;

	// First pass: count lines
	line_count = 0;
	while ((line = get_next_non_empty_line_no_nl(data->fd)) != NULL)
	{
		line_count++;
		free(line);
	}

    // printf("Line count:%d\n", line_count);

	// Reset file position
	close(data->fd);
	data->fd = get_fd(data->file); // Reopen file

	// Allocate array
	header_tmp = malloc(sizeof(char *) * (6 + 1));
	if (!header_tmp)
		exit(1);

	// Second pass: store lines
	i = 0;
	while ((line = get_next_non_empty_line_no_nl(data->fd)) != NULL && i < 6)
		header_tmp[i++] = line;
	header_tmp[i] = NULL;

	print_char_array(header_tmp);
	return (header_tmp);
}

char **extract_and_validate_header(t_data *data)
{
	// Extract First 6 lines + store them in Header
	extract_header(data);

	// Validate header
		// is the structre intact meaning the order is correct: -> check first 2 chars of each string
		// is the file exist + permissions 
		// is colors valid
	validate_header(data);
	
	return (NULL);
}

void	read_map(t_data *data)
{
	data->header = extract_and_validate_header(data);
	// data->map = extract_and_validate_map(data);
}

int	main(int ac, char **av)
{

	t_data			data;

	data.file = av[1];
	check_file(av, ac);
	data.fd = get_fd(data.file); //todo: remember to close this after parsing the map
	read_map(&data);
	
	close(data.fd); // Don't forget to close!	
}

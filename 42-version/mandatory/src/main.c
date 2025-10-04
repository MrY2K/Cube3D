/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:54:13 by achoukri          #+#    #+#             */
/*   Updated: 2025/10/04 00:53:00 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"
#include "lib/libft.h"
#include <stdio.h>
#include <stdlib.h> // Added for malloc and free

int	validate_file_path(char *tmp_path);

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

int	validate_file_path(char *tmp_path)
{
	int	fd;

	fd = open(tmp_path, O_RDONLY);
	if (fd == -1)
		ft_error2("Baka File Is Unvalid !\n");
	close(fd);
	return (VALID);
}

// Skip spaces and return new position
static size_t skip_spaces(char *line, size_t j, size_t len)
{
	while (j < len && ft_isspace(line[j]))
		j++;
	return (j);
}

//helper
// Extract path starting after a 2-char prefix
static char *extract_path_after_prefix(char *line, size_t j, size_t len)
{
	size_t	path_start;
	size_t	path_len;
	
	j = j + 2; // Skip the prefix (NO, SO, WE, EA)
	
	// Skip spaces after prefix
	j = skip_spaces(line, j, len);
	
	path_start = j;
	
	// Find end of path
	while (j < len && !ft_isspace(line[j]))
		j++;
	
	path_len = j - path_start;
	
	if (path_len > 0)
		return (ft_substr(line, path_start, path_len));
	return (NULL);
}

// Check and process texture line (NO, SO, WE, EA)
static void check_texture(char *line, size_t len, char *name, char **dest)
{
	char	*tmp_path;
	size_t	j;
	
	if (!name || ft_strlen(name) < 2)
		return;

	j = skip_spaces(line, 0, len);

	if (j + 2 < len && line[j] == name[0] && line[j + 1] == name[1] 
		&& ft_isspace(line[j + 2]))
	{
		if (*dest != NULL)
			ft_error2("Baka You have Duplicate texture definition!\n");

		tmp_path = extract_path_after_prefix(line, j, len);
		if (tmp_path)
		{
			validate_file_path(tmp_path);
			*dest = tmp_path; // Store it, don't free!
		}
	}
}

char **validate_header(char **header, t_data *data)
{
	size_t i = 0;


	while (header[i] != NULL)
	{
		size_t len = ft_strlen(header[i]);

		check_texture(header[i], len, "NO", &data->north_texture);
		check_texture(header[i], len, "SO", &data->south_texture);
		check_texture(header[i], len, "WE", &data->west_texture);
		check_texture(header[i], len, "EA", &data->east_texture);

		i++;
	}

	// Verify all textures were found
	if (!data->north_texture || !data->south_texture || 
		!data->west_texture || !data->east_texture)
		ft_error2("Baka your Missing a texture!");

	return (header);
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

void	extract_and_validate_header(t_data *data)
{
	char	**header_tmp;
	char	**header;

	// Extract First 6 lines + store them in Header
	header_tmp = extract_header(data);

	// Validate header
		// is the structre intact meaning the order is correct: -> check first 2 chars of each string
		// is the file exist + permissions 
	header = validate_header(header_tmp, data);
	printf("east_texture:  |%s|\n", data->east_texture);
	printf("north_texture: |%s|\n", data->north_texture);
	printf("south_texture: |%s|\n", data->south_texture);
	printf("west_texture:  |%s|\n", data->west_texture);
	
		// is colors valid
	//free(header_tmp);
	return ;
}

void	read_map(t_data *data)
{
	extract_and_validate_header(data);
	// data->map = extract_and_validate_map(data);
}

int	main(int ac, char **av)
{

	t_data			data;

	//? INIT DATA
	data.north_texture = NULL;
	data.south_texture = NULL;
	data.west_texture = NULL;
	data.east_texture = NULL;

	data.file = av[1];
	check_file(av, ac);
	data.fd = get_fd(data.file); //remember to close this after parsing the map
	close(data.fd); // Don't forget to close!	
	read_map(&data);
	
	free(data.north_texture);
    free(data.south_texture);
    free(data.west_texture);
    free(data.east_texture);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_input_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:55:10 by achoukri          #+#    #+#             */
/*   Updated: 2025/10/01 18:34:47 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cube.h"

void	check_file(char **av, int ac);
int		check_file_extension(const char *filename);
int		check_file_exist(const char *filename);
int		get_fd(char *filename);

void	check_file(char **av, int ac)
{
	if (ac == 2)
	{
		if (check_file_exist(av[1]) == FAILURE
			|| check_file_extension(av[1]) == FAILURE)
		{
			exit(1);
		}
	}
	else
	{
		perror("Invalid Number of Args");
		exit(1);
	}
}

int	check_file_extension(const char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	if (i < 4)
	{
		perror("Error Wrong Extension");
		return (FAILURE);
	}
	i--;
	if (filename[i - 3] == '.' && 
		filename[i - 2] == 'c' && 
		filename[i - 1] == 'u' && 
		filename[i] == 'b')
	{
		return (SUCCESS);
	}
	perror("Error Wrong Extension");
	return (FAILURE);
}

int	check_file_exist(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (FAILURE);
	}
	close(fd);
	return (SUCCESS);
}

int	get_fd(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(1);
	}
	return (fd);
}

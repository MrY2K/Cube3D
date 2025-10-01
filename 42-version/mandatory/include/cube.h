/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:30:14 by achoukri          #+#    #+#             */
/*   Updated: 2025/10/01 18:47:38 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

// #define USAGE_ERROR_MSG "Error: Usage: <> "
# define SUCCESS 1
# define FAILURE 0

/*
• All functions of the math
library (-lm man man 3 math).

• gettimeofday()

• All functions of the MinilibX library.
*/

# include <string.h> 								// for streeror
# include <stdio.h> 								// for perror and printf
# include <stdlib.h> 								// for exit, free, malloc
# include <fcntl.h> 								// for open
# include <unistd.h> 								// open, close, read, write
# include <math.h> 								    // for cos and sin and M_PI

// 01 - Input handling - checking if file exist and has the right extention:
void	check_file(char **av, int ac);
int		check_file_extension(const char *filename);
int		check_file_exist(const char *filename);
int		get_fd(char *filename);

// 02 -

#endif
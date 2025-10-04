/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:30:14 by achoukri          #+#    #+#             */
/*   Updated: 2025/10/04 00:36:43 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

// #define USAGE_ERROR_MSG "Error: Usage: <> "
# define SUCCESS 1
# define FAILURE 0
# define VALID 1
# define UNVALID 0
# define GOOD 1
# define BAD 0

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

# include "../src/lib/libft.h"
//for ft_perror
//for get_next_non_empty_line_no_nl

// 01 - Input handling - checking if file exist and has the right extention:
void	check_file(char **av, int ac);
int		check_file_extension(const char *filename);
int		check_file_exist(const char *filename);
int		get_fd(char *filename);

// 02 - Map Parsing
//struct to store data 
// Map Structures
typedef struct s_data 
{
    char    *file;
    int		fd;
    char    **header;
    char    **map;
    char    *north_texture;
    char    *south_texture;
    char    *west_texture;
    char    *east_texture;

}	t_data;

void    ft_error2(char *err_msg);



#endif
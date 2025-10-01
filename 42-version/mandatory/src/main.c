/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:54:13 by achoukri          #+#    #+#             */
/*   Updated: 2025/10/01 18:44:14 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int	main(int ac, char **av)
{
	char			*file;
	int				fd;

	file = av[1];
	check_file(av, ac);
	fd = get_fd(file); //todo: remember to close this after parsing the map
}

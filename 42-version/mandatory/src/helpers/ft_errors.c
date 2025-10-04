/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 20:02:59 by achoukri          #+#    #+#             */
/*   Updated: 2025/10/03 22:09:46 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// FUNCTIONS THAT HANDLES ERRORS:

#include "../../include/cube.h"

void    ft_error2(char *err_msg)
{
    ft_perror("Error\n");
    ft_perror(err_msg);
	exit(EXIT_FAILURE);
}

// void	mlx_ptr_error(mlx_t *ptr)
// {
// 	if (ptr == NULL)
// 	{
// 		mlx_terminate(ptr);
// 		ft_error("mlx.ptr poiners no good!");
// 	}
// }

// void	mlx_img_error(mlx_t *ptr, mlx_image_t *img)
// {
// 	if (img == NULL)
// 	{
// 		mlx_delete_image(ptr, img);
// 		ft_error("mlx.img poiners no good!");
// 	}
// }

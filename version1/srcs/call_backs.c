/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_backs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:09:40 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/03 17:12:28 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/opengl.h"

void    ft_frame_buffer_size_callback(GLFWwindow *window, int w, int h)
{
    (void)window;
    glViewport(0, 0, w, h);
}

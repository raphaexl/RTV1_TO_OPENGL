/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opengl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:09:12 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/04 10:56:28 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPENGL_H
# define OPENGL_H

# include "rtv1.h"

int				ft_process_input(GLFWwindow *win, t_cam *cam, float time);
void            ft_run(void);
GLFWwindow      *ft_opengl_window(void);
void            ft_opengl_print(void);
void            ft_opengl_fps(GLFWwindow    *win);  
void            ft_opengl_clear(GLFWwindow **win);

void            ft_frame_buffer_size_callback(GLFWwindow *window, int w, int h);

#endif

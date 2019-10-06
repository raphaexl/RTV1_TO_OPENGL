/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quad.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:02:56 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/04 13:14:38 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUAD_H
# define QUAD_H

# include "defines.h"


typedef struct	s_quad
{
	GLfloat		vertices[4][3];
	GLuint		indices[6];
	GLuint		ebo;
	GLuint		vbo;
   	GLuint		vao;
}				t_quad;

void			ft_create_object(GLfloat object[4][3]);
void			ft_create_indices(GLuint object[6]);
void			ft_quad_init(t_quad *q);
void			ft_quad_draw(t_quad *q);
void			ft_quad_quit(t_quad *q);
#endif

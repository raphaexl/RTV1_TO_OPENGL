/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quad.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:13:03 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/04 13:15:16 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/opengl.h"

void			ft_create_object(GLfloat object[4][3])
{
	object[0][0] = 1.0;
	object[0][1] = 1.0;
	object[0][2] = 0.0;
	object[1][0] = 1.0;
	object[1][1] = -1.0;
	object[1][2] = 0.0;
	object[2][0] = -1.0;
	object[2][1] = -1.0;
	object[2][2] = 0.0;
	object[3][0] = -1.0;
	object[3][1] = 1.0;
	object[3][2] = 0.0;
}

void			ft_create_indices(GLuint indices[6])
{
	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 3;
	indices[3] = 1;
	indices[4] = 2;
	indices[5] = 3;
}

void	ft_quad_init(t_quad *q)
{
	ft_create_object(q->vertices);
	ft_create_indices(q->indices);
	glGenBuffers(1, &q->vbo);
	glGenBuffers(1, &q->ebo);
	glGenVertexArrays(1, &q->vao);
	glBindVertexArray(q->vao);
	glBindBuffer(GL_ARRAY_BUFFER, q->vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(q->vertices), q->vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, q->ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(q->indices), q->indices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void	ft_quad_draw(t_quad *q)
{
	(void)q;
	glEnableVertexAttribArray(0);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(0);
}


void	ft_quad_quit(t_quad *q)
{
	glDisableVertexAttribArray(0);
	glDeleteBuffers(1, &q->vbo);
	glDeleteBuffers(1, &q->ebo);
	glDeleteVertexArrays(1, &q->vao);
	q = NULL;
}

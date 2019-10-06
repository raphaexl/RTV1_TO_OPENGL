/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:42:00 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/03 19:53:09 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/opengl.h"

t_shader    ft_shader_init(const char *v_file, const char *f_file)
{
    t_shader    shader;

    shader.id = ft_shader_program(v_file, f_file);
    return (shader);
}

void        ft_shader_use(t_shader *s)
{
    glUseProgram(s->id);
}

void        ft_shader_clear(t_shader *s)
{
    glDeleteProgram(s->id);
}

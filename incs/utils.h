/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:39:04 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/03 19:15:09 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef UTILS_H
# define UTILS_H

# include "structs.h"

void            *ft_file_content(const char *file_name, int *len);

GLuint          ft_shader_program(const char *v_shader, const char *f_shader);
GLuint          ft_shader_create(const char *filename, GLenum type);
void            ft_shader_error(GLuint shader, GLenum type);

void            ft_shader_set_bool(t_shader *s, const char *name, GLboolean value);
void            ft_shader_set_int(t_shader *s, const char *name, int value);
void            ft_shader_set_float(t_shader *s, const char *name, float value);
void            ft_shader_set_vec3(t_shader *s, const char *name, t_vec3 v);
void            ft_shader_set_mat4f(t_shader *s, const char *name, t_mat4 m);

t_shader        ft_shader_init(const char *v_file, const char *f_file);
void            ft_shader_use(t_shader *s);
void            ft_shader_clear(t_shader *s);


t_camera        ft_camera(void);
t_camera        ft_camera_new(t_vec3 pos, t_vec3 at, t_vec3 up, float fov);
void            ft_camera_update_vecs(t_camera *cam);
void            ft_camera_matrix(t_camera *cam);
void            ft_camera_process_keyboard(t_camera *cam, t_camera_mvt dir, float time);
void            ft_camera_mouse_move(t_camera *cam, float xoffset, float yoffset);
void            ft_camera_mouse_wheel(t_camera *cam, float yoffset);

#endif

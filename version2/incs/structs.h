/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:38:48 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/04 22:25:31 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "quad.h"
# include "structs.h"
# include "cam.h"
# include "material.h"

typedef struct  s_shader
{
    GLuint      id;
}               t_shader;

typedef struct s_tga
{
    char            id_len;
    char            color_map_type;
    char            data_type_code;
    unsigned char   color_map_origin[2];
    unsigned char   color_map_len[2];
    char            color_map_depth;
    unsigned char   x_origin[2];
    unsigned char   y_origin[2];
    unsigned char   width[2];
    unsigned char   height[2];
    char            bits_per_pixel;
    char            image_descriptor;
}               t_tga;

typedef struct  s_camera
{
    float       yaw;
    float       pitch;
    float       speed;
    float       sensitivity;
    float       mouse_sensitivity;
    float       zoom;
    float       aspect_ratio;
    t_vec3      pos;
    t_vec3      at;
    t_vec3      up;
    t_vec3      u;
    t_vec3      rt;

    t_mat4      projection;
    t_mat4      view;
}               t_camera;

typedef     enum    e_camera_mvt
{
    FORWARD, BACKWARD, RIGHT, LEFT
}                   t_camera_mvt;

typedef struct	s_sphere
{
	t_material	material;
	t_vec3		pos;
	t_vec3		trans;
	t_vec3		rot;
	t_vec3		scale;
	float		radius;
}				t_sphere;

typedef struct	s_plane
{
	t_material	material;
	t_vec3		pos;
	t_vec3		trans;
	t_vec3		rot;
	t_vec3		scale;
	t_vec3		normal;
}				t_plane;

typedef struct	s_cone
{
	t_material	material;
	t_vec3		pos;
	t_vec3		trans;
	t_vec3		rot;
	t_vec3		scale;
	float		angle;
}				t_cone;

typedef struct	s_cylinder
{
	t_material	material;
	t_vec3		pos;
	t_vec3		trans;
	t_vec3		rot;
	t_vec3		scale;
	float		radius;
}				t_cylinder;

typedef struct	s_light
{
	t_vec3		pos;
	t_vec3		intensity;
}				t_light;

typedef struct	s_scene
{
	t_cam		cam;
	t_vec3		bg_color;
	t_vec3		ambient;
	int			antialias;
	int			nb_spheres;
	int			nb_planes;
	int			nb_cones;
	int			nb_cylinders;
	int			nb_lights;
	t_sphere	spheres[NB_OBJECTS_MAX];
	t_plane		planes[NB_OBJECTS_MAX];
	t_cone		cones[NB_OBJECTS_MAX];
	t_cylinder	cylinders[NB_OBJECTS_MAX];
	t_light		lights[NB_OBJECTS_MAX];
}				t_scene;
#endif

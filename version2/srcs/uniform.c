/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uniform.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 19:03:04 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/04 23:09:38 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/opengl.h"

void	ft_camera_uniforms(t_cam *cam, t_shader *shader)
{
	ft_shader_set_vec3(shader, "scene.cam.pos", cam->pos);
	ft_shader_set_vec3(shader, "scene.cam.dir", cam->dir);
	ft_shader_set_vec3(shader, "scene.cam.horiz", cam->horiz);
	ft_shader_set_vec3(shader, "scene.cam.vert", cam->vert);
	ft_shader_set_vec3(shader, "scene.cam.low_left", cam->low_left);
}

void	ft_spheres_uniforms(t_sphere *s, int start, int	nb_spheres, t_shader *shader)
{
	int		i;
	char	*s1;

	i = -1;
	s1 = "scene.objects[";
	while (++i < nb_spheres)
	{
		i += start;
	//	printf("indices = %d\n", i);
		ft_shader_set_vec3(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].pos"), s[i].pos);
		ft_shader_set_vec3(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].trans"), s[i].trans);
		ft_shader_set_vec3(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].rot"), s[i].rot);
		ft_shader_set_vec3(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].scale"), s[i].scale);
		ft_shader_set_float(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].radius"), s[i].radius);
		ft_shader_set_vec3(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].material.diffuse1"), s[i].material.diffuse1);
		ft_shader_set_vec3(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].material.diffuse2"), s[i].material.diffuse2);
		ft_shader_set_vec3(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].material.specular"), s[i].material.specular);
		ft_shader_set_float(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].material.shininess"), s[i].material.shininess);
		ft_shader_set_float(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].material.reflection"), s[i].material.reflection);
		ft_shader_set_float(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].material.refraction"), s[i].material.refraction);
		ft_shader_set_int(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].material.chess"), s[i].material.chess);
		ft_shader_set_int(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].type"), SPHERE);
	}
}

void	ft_planes_uniforms(t_plane *p, int	start, int	nb_planes, t_shader *shader)
{
	int		i;
	char	*s1;

	i = -1;
	s1 = "scene.objects[";
	while (++i < nb_planes)
	{
		i += start;
	//	printf("indices = %d\n", i);
		ft_shader_set_vec3(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].pos"), p[i].pos);
		ft_shader_set_vec3(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].trans"), p[i].trans);
		ft_shader_set_vec3(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].rot"), p[i].rot);
		ft_shader_set_vec3(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].scale"), p[i].scale);
		ft_shader_set_vec3(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].normal"), p[i].normal);
		ft_shader_set_vec3(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].material.diffuse1"), p[i].material.diffuse1);
		ft_shader_set_vec3(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].material.diffuse2"), p[i].material.diffuse2);
		ft_shader_set_vec3(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].material.specular"), p[i].material.specular);
		ft_shader_set_float(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].material.shininess"), p[i].material.shininess);
		ft_shader_set_float(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].material.reflection"), p[i].material.reflection);
		ft_shader_set_float(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].material.refraction"), p[i].material.refraction);
		ft_shader_set_int(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].material.chess"), p[i].material.chess);
		ft_shader_set_int(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].type"), PLANE);
	}
}

void	ft_cones_uniforms(t_cone *co, int start, int	nb_cones, t_shader *shader)
{
	int		i;
	char	*s1;

	i = -1;
	s1 = "scene.objects[";
	while (++i < nb_cones)
	{
		i += start;
	//	printf("indices = %d\n", i);
		ft_shader_set_vec3(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].pos"), co[i].pos);
		ft_shader_set_vec3(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].trans"), co[i].trans);
		ft_shader_set_vec3(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].rot"), co[i].rot);
		ft_shader_set_vec3(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].scale"), co[i].scale);
		ft_shader_set_float(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].angle"), co[i].angle);
		ft_shader_set_vec3(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].material.diffuse1"), co[i].material.diffuse1);
		ft_shader_set_vec3(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].material.diffuse2"), co[i].material.diffuse2);
		ft_shader_set_vec3(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].material.specular"), co[i].material.specular);
		ft_shader_set_float(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].material.shininess"), co[i].material.shininess);
		ft_shader_set_float(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].material.reflection"), co[i].material.reflection);
		ft_shader_set_float(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].material.refraction"), co[i].material.refraction);
		ft_shader_set_int(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].material.chess"), co[i].material.chess);
		ft_shader_set_int(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].type"), CONE);
	}
}

void	ft_cylinders_uniforms(t_cylinder *cy, int start, int	nb_cylinders, t_shader *shader)
{
	int		i;
	char	*s1;

	i = -1;
	s1 = "scene.objects[";
	while (++i < nb_cylinders)
	{
		i += start;
		//printf("indices = %d\n", i);
		ft_shader_set_vec3(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].pos"), cy[i].pos);
		ft_shader_set_vec3(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].trans"), cy[i].trans);
		ft_shader_set_vec3(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].rot"), cy[i].rot);
		ft_shader_set_vec3(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].scale"), cy[i].scale);
		ft_shader_set_float(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].radius"), cy[i].radius);
		ft_shader_set_vec3(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].material.diffuse1"), cy[i].material.diffuse1);
		ft_shader_set_vec3(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].material.diffuse2"), cy[i].material.diffuse2);
		ft_shader_set_vec3(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].material.specular"), cy[i].material.specular);
		ft_shader_set_float(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].material.shininess"), cy[i].material.shininess);
		ft_shader_set_float(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].material.reflection"), cy[i].material.reflection);
		ft_shader_set_float(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].material.refraction"), cy[i].material.refraction);
		ft_shader_set_int(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].material.chess"), cy[i].material.chess);
		ft_shader_set_int(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].type"), CYLINDER);
	}
}

void	ft_lights_uniforms(t_light *l, int	nb_lights, t_shader *shader)
{
	int		i;
	char	*s1;

	i = -1;
	s1 = "scene.lights[";
	while (++i < nb_lights)
	{
		ft_shader_set_vec3(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].pos"), l[i].pos);
		ft_shader_set_vec3(shader, ft_strjoin(ft_strjoin(s1, ft_itoa(i)), "].intensity"), l[i].intensity);
	}
}


void	ft_scene_uniforms(t_scene *scene, t_shader *shader)
{
	int		nb_objects;

	nb_objects = 0;
	ft_camera_uniforms(&scene->cam, shader);
//	printf("nb_objects = %d\n", nb_objects);
	ft_spheres_uniforms(scene->spheres, nb_objects, scene->nb_spheres, shader);
	nb_objects += scene->nb_spheres;
//	printf("nb_objects = %d\n", nb_objects);
	ft_planes_uniforms(scene->planes, nb_objects, scene->nb_planes, shader);
	nb_objects += scene->nb_planes;
//	printf("nb_objects = %d\n", nb_objects);
	ft_cones_uniforms(scene->cones, nb_objects, scene->nb_cones, shader);
	nb_objects += scene->nb_cones;
//	printf("nb_objects = %d\n", nb_objects);
	ft_cylinders_uniforms(scene->cylinders, nb_objects, scene->nb_cylinders, shader);
	nb_objects += scene->nb_cylinders;
//	printf("nb_objects = %d\n", nb_objects);
//	exit(0);
	ft_lights_uniforms(scene->lights, scene->nb_lights, shader);
	ft_shader_set_vec3(shader, "scene.bg_color", scene->bg_color);
	ft_shader_set_vec3(shader, "scene.ambient", scene->ambient);
	ft_shader_set_int(shader, "scene.antialias", scene->antialias);
	ft_shader_set_int(shader, "scene.nb_lights", scene->nb_lights);
	ft_shader_set_int(shader, "scene.nb_objects", nb_objects);
}

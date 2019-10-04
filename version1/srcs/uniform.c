/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uniform.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 19:03:04 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/04 13:18:34 by ebatchas         ###   ########.fr       */
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

void	ft_spheres_uniforms(t_sphere *s, int	nb_spheres, t_shader *shader)
{
	int		i;
	char	*s1;

	i = -1;
	s1 = "scene.spheres[";
	while (++i < nb_spheres)
	{
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
	}
}

void	ft_planes_uniforms(t_plane *p, int	nb_planes, t_shader *shader)
{
	int		i;
	char	*s1;

	i = -1;
	s1 = "scene.planes[";
	while (++i < nb_planes)
	{
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
	}
}

void	ft_cones_uniforms(t_cone *co, int	nb_cones, t_shader *shader)
{
	int		i;
	char	*s1;

	i = -1;
	s1 = "scene.cones[";
	while (++i < nb_cones)
	{
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
	}
}

void	ft_cylinders_uniforms(t_cylinder *cy, int	nb_cylinders, t_shader *shader)
{
	int		i;
	char	*s1;

	i = -1;
	s1 = "scene.cylinders[";
	while (++i < nb_cylinders)
	{
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
		ft_shader_set_vec3(shader, "scene.bg_color", scene->bg_color);
		ft_shader_set_vec3(shader, "scene.ambient", scene->ambient);
		ft_shader_set_int(shader, "scene.antialias", scene->antialias);
		ft_shader_set_int(shader, "scene.nb_spheres", scene->nb_spheres);
		ft_shader_set_int(shader, "scene.nb_planes", scene->nb_planes);
		ft_shader_set_int(shader, "scene.nb_cones", scene->nb_cones);
		ft_shader_set_int(shader, "scene.nb_cylinders", scene->nb_cylinders);
		ft_shader_set_int(shader, "scene.nb_lights", scene->nb_lights);
		ft_camera_uniforms(&scene->cam, shader);
		ft_spheres_uniforms(scene->spheres, scene->nb_spheres, shader);
		ft_planes_uniforms(scene->planes, scene->nb_planes, shader);
		ft_cones_uniforms(scene->cones, scene->nb_cones, shader);
		ft_cylinders_uniforms(scene->cylinders, scene->nb_cylinders, shader);
		ft_lights_uniforms(scene->lights, scene->nb_lights, shader);
}

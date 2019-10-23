/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 00:17:42 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/23 16:42:47 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/opengl.h"

t_scene		ft_scene_init(void)
{
	t_scene		s;

	ft_bzero(&s, sizeof(t_scene));
	s.cam = ft_cam_new(ft_vec3_new(0.0, 0.0, 5.0), ft_vec3_new(0.0, 0.0, 0.0),
			ft_vec3_new(0.0, 1.0, 0.0), 60.0);
	s.antialias = 1;
	s.ambient = (t_vec3){{{.1, .1, .1}}};
	s.bg_color = (t_vec3){{{1, .02, .81}}};
	s.spheres[0] = ft_sphere_new();
	s.spheres[0].pos.x -= 2.0;
	s.spheres[0].material.diffuse = ft_vec3_new(1.0, 1.0, 0.0);
	s.spheres[1] = ft_sphere_new();
	s.spheres[1].pos.x += 2.0;
	s.spheres[1].material.diffuse = ft_vec3_new(0.0, 1.0, 0.0);
	s.nb_spheres = 2;
	s.cylinders[0] = ft_cylinder_new();
	s.cylinders[0].material.diffuse = ft_vec3_new(0.0, 0.0, 1.0);
	s.nb_cylinders = 1;
	s.cones[0] = ft_cone_new();
	s.cones[0].pos.z += 25.0;
	s.cones[0].material.diffuse = ft_vec3_new(1.0, 0.4, 0.2);
	s.nb_cones = 1;
	s.planes[0] = ft_plane_new();
	s.planes[0].material.diffuse = ft_vec3_new(1.0, 1.0, 1.0);
	s.planes[0].normal = ft_vec3_new(0.0, 1.0, 0.0);
	s.planes[1] = ft_plane_new();
	s.planes[1].material.diffuse = ft_vec3_new(0.3, 0.5, 0.8);
	s.planes[1].pos = ft_vec3_new(0.0, 0.0, -100.0);
	s.planes[1].normal = ft_vec3_new(0.0, 0.0, 1.0);
	s.planes[2] = ft_plane_new();
	s.planes[2].material.diffuse = ft_vec3_new(0.8, 0.9, 0.1);
	s.planes[2].pos = ft_vec3_new(0.0, 0.0, 100.0);
	s.planes[2].normal = ft_vec3_new(0.0, 0.0, -1.0);
	s.planes[3] = ft_plane_new();
	s.planes[3].material.diffuse = ft_vec3_new(0.7, 0.18, 0.8);
	s.planes[3].pos = ft_vec3_new(0.0, 100.0, 0.0);
	s.planes[3].normal = ft_vec3_new(0.0, -1.0, 0.0);
	s.planes[4] = ft_plane_new();
	s.planes[4].material.diffuse = ft_vec3_new(0.6, 0.5, 0.6);
	s.planes[4].pos = ft_vec3_new(100.0, 0.0, 0.0);
	s.planes[4].normal = ft_vec3_new(-1.0, 0.0, 0.0);
	s.planes[5] = ft_plane_new();
	s.planes[5].material.diffuse = ft_vec3_new(0.18, 0.82, 0.21);
	s.planes[5].pos = ft_vec3_new(-100.0, 0.0, 0.0);
	s.planes[5].normal = ft_vec3_new(1.0, 0.0, 0.0);
	s.nb_planes = 6;
	s.lights[0] = (t_light){{{{0.0, 1.0, 100.0}}}, {{{1.0, 0.5, 1.0}}}};
	s.nb_lights = 1;
	return (s);
}

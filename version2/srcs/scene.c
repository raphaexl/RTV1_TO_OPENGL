/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 00:17:42 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/04 23:12:03 by ebatchas         ###   ########.fr       */
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
	s.bg_color = (t_vec3){{{.01, .02, .01}}};
//	s.spheres[0] = ft_sphere_new();
//	s.spheres[0].pos.x -= 2.0;
//	s.spheres[0].pos.y += 5.0;
//	s.spheres[0].material.diffuse1 = ft_vec3_new(1.0, 1.0, 0.0);
//	s.spheres[1] = ft_sphere_new();
//	s.spheres[1].pos.x += 2.0;
//	s.spheres[1].material.diffuse1 = ft_vec3_new(0.0, 1.0, 0.0);
//	s.nb_spheres = 2;
	s.nb_spheres = 0;
	s.cylinders[0] = ft_cylinder_new();
	s.cylinders[0].material.diffuse1 = ft_vec3_new(0.0, 0.0, 1.0);
	s.nb_cylinders = 1;
/*	s.planes[0] = ft_plane_new();
	s.planes[0].material.diffuse1 = ft_vec3_new(1.0, 1.0, 1.0);
	s.planes[0].material.reflection = 0.5;
	s.nb_planes = 1;*/
	s.lights[0] = (t_light){{{{0.0, 10.0, 10.0}}}, {{{1.0, 1.0, 1.0}}}};
	s.nb_lights = 1;
	return (s);
}

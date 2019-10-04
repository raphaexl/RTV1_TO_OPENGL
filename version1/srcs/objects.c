/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 22:00:38 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/04 21:15:48 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/opengl.h"

t_material	ft_material_new(void)
{
	t_material	mat;

	mat.diffuse1 = (t_vec3){{{1.0, 0.0, 0.0}}};
	mat.diffuse2 = (t_vec3){{{1.0, 1.0, 0.0}}};
	mat.specular = (t_vec3){{{1.0, 1.0, 1.0}}};
	mat.shininess = 60.0;
	mat.refraction = 0.0;
	mat.reflection = 0.0;
	mat.chess = 0;
	return (mat);
}

t_sphere	ft_sphere_new(void)
{
	t_sphere	sphere;

	sphere.material = ft_material_new();
	sphere.radius = 1.0;
	sphere.pos = (t_vec3){{{0.0, 0.0, 0.0}}};
	sphere.trans = (t_vec3){{{0.0, 0.0, 0.0}}};
	sphere.rot = (t_vec3){{{0.0, 0.0, 0.0}}};
	sphere.scale = (t_vec3){{{1.0, 1.0, 1.0}}};
	return (sphere);
}

t_plane		ft_plane_new(void)
{
	t_plane	plane;

	plane.material = ft_material_new();
	plane.normal = (t_vec3){{{0.0, 1.0, 0.0}}};
	plane.pos = (t_vec3){{{0.0, -1.0, 0.0}}};
	plane.trans = (t_vec3){{{0.0, 0.0, 0.0}}};
	plane.rot = (t_vec3){{{0.0, 0.0, 0.0}}};
	plane.scale = (t_vec3){{{1.0, 1.0, 1.0}}};
	return (plane);
}

t_cone		ft_cone_new(void)
{
	t_cone	cone;

	cone.material = ft_material_new();
	cone.angle = M_PI/6.0;
	cone.pos = (t_vec3){{{0.0, -1.0, 0.0}}};
	cone.trans = (t_vec3){{{0.0, 0.0, 0.0}}};
	cone.rot = (t_vec3){{{0.0, 0.0, 0.0}}};
	cone.scale = (t_vec3){{{1.0, 1.0, 1.0}}};
	return (cone);
}

t_cylinder		ft_cylinder_new(void)
{
	t_cylinder	cylinder;

	cylinder.material = ft_material_new();
	cylinder.radius = 1.0;
	cylinder.pos = (t_vec3){{{0.0, -1.0, 0.0}}};
	cylinder.trans = (t_vec3){{{0.0, 0.0, 0.0}}};
	cylinder.rot = (t_vec3){{{0.0, 0.0, 0.0}}};
	cylinder.scale = (t_vec3){{{1.0, 1.0, 1.0}}};
	return (cylinder);
}

t_light		ft_light_new(void)
{
	t_light	light;

	light.pos = (t_vec3){{{0.0, -100.0, 0.0}}};
	light.intensity = (t_vec3){{{1.0, 1.0, 1.0}}};
	return (light);
}

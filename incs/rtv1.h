/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 01:06:36 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/04 01:22:34 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "utils.h"

t_material		ft_material_new(void);
t_sphere		ft_sphere_new(void);
t_plane			ft_plane_new(void);
t_cone			ft_cone_new(void);
t_cylinder		ft_cylinder_new(void);
t_light			ft_light_new(void);
t_scene			ft_scene_init(void);
void			ft_camera_uniforms(t_cam *cam, t_shader *shader);
void			ft_sphere_uniforms(t_sphere *s, int	nb_spheres, t_shader *shader);
void			ft_spheres_uniforms(t_sphere *s, int	nb_spheres, t_shader *shader);
void			ft_planes_uniforms(t_plane *p, int	nb_planes, t_shader *shader);
void			ft_cones_uniforms(t_cone *co, int	nb_cones, t_shader *shader);
void			ft_cylinders_uniforms(t_cylinder *cy, int	nb_cylinders, t_shader *shader);
void			ft_lights_uniforms(t_light *l, int	nb_lights, t_shader *shader);
void			ft_scene_uniforms(t_scene *scene, t_shader *shader);
void    		ft_cam_update(t_cam *cam, t_camera_mvt dir, float delta_time);
#endif

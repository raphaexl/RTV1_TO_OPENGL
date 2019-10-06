/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 19:12:02 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/06 12:39:54 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAM_H
# define CAM_H

# define FOV 60.0
# include "defines.h"

typedef	struct	s_cam
{
	t_vec3		pos;
	t_vec3		rot;
	t_vec3		trans;
	t_vec3		dir;
	t_vec3		at;
	t_vec3		u;
	t_vec3		v;
	t_vec3		horiz;
	t_vec3		vert;
	t_vec3		low_left;
	float		ratio;
	float		fov;
	float		h;
	float		w;
	float		speed;
}				t_cam;

typedef struct s_ray
{
	t_vec3		start;
	t_vec3		dir;
}				t_ray;

t_cam	ft_cam_new(t_vec3 eye, t_vec3 at, t_vec3 up, float a);
#endif

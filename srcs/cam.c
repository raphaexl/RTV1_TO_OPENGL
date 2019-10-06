/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:50:25 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/06 12:48:53 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/opengl.h"

t_cam	ft_cam_new(t_vec3 eye, t_vec3 at, t_vec3 up, float a)
{
	t_cam	cam;

	cam.rot = (t_vec3){{{0.0, 0.0, 0.0}}};
	cam.trans = (t_vec3){{{0.0, 0.0, 0.0}}};
	cam.ratio = (float)W_W / (float)W_H;
	cam.pos = eye;
	cam.fov = a;
	cam.speed = SPEED;
	cam.at = at;
	cam.h = tan((cam.fov * M_PI * (1.0 / 180.0)) / 2.0);
	cam.w = cam.ratio * cam.h;
	cam.dir = ft_vec3_normalize(ft_vec3_sub(eye, at));
	cam.u = ft_vec3_normalize(ft_vec3_cross(up, cam.dir));
	cam.v = ft_vec3_cross(cam.dir, cam.u);
	cam.low_left = ft_vec3_sub(cam.pos, ft_vec3_add(ft_vec3_kmult(cam.h,
					cam.v), ft_vec3_kmult(cam.w, cam.u)));
	cam.low_left = ft_vec3_sub(cam.low_left, cam.dir);
	cam.horiz = ft_vec3_kmult(2.0 * cam.w, cam.u);
	cam.vert = ft_vec3_kmult(2.0 * cam.h, cam.v);
	return (cam);
}

void		ft_camera_transform(t_cam *cam)
{
	cam->pos = ft_translate_vec3(cam->pos, cam->trans, -1);
	cam->dir = ft_vec3_normalize(ft_rotate_vec3(cam->dir, cam->rot, 0));
	cam->u = ft_vec3_normalize(ft_vec3_cross(
				ft_rotate_vec3(ft_vec3_new(0.0, 1.0, 0.0),
					cam->rot, -1), cam->dir));
	cam->v = ft_vec3_cross(cam->dir, cam->u);
	cam->low_left = ft_vec3_sub(cam->pos,
			ft_vec3_add(ft_vec3_kmult(cam->h,
					cam->v), ft_vec3_kmult(cam->w, cam->u)));
	cam->low_left = ft_vec3_sub(cam->low_left, cam->dir);
	cam->horiz = ft_vec3_kmult(2.0 * cam->w, cam->u);
	cam->vert = ft_vec3_kmult(2.0 * cam->h, cam->v);
	cam->rot = (t_vec3){{{0.0, 0.0, 0.0}}};
	cam->trans = (t_vec3){{{0.0, 0.0, 0.0}}};
}

void    ft_cam_update(t_cam *cam, t_camera_mvt direction, float delta_time)
{
    float       velocity;

    velocity = cam->speed * delta_time;
    if (direction == FORWARD)
        cam->trans = ft_vec3_add(cam->trans, ft_vec3_kmult(velocity, cam->dir));
    else if (direction == BACKWARD)
        cam->trans = ft_vec3_sub(cam->trans, ft_vec3_kmult(velocity, cam->dir));
    else if (direction == LEFT)
        cam->trans = ft_vec3_sub(cam->trans, ft_vec3_kmult(velocity, cam->horiz));
    else if (direction == RIGHT)
        cam->trans = ft_vec3_add(cam->trans, ft_vec3_kmult(velocity, cam->horiz));
    else if (direction == ROT_LEFT)
        cam->rot = ft_vec3_add(cam->rot, ft_vec3_new(0.0, velocity * 89.0, 0.0));
    else if (direction == ROT_RIGHT)
        cam->rot = ft_vec3_add(cam->rot, ft_vec3_new(0.0, -velocity * 89.0, 0.0));
    ft_camera_transform(cam);
}

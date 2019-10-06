/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_op3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 21:43:55 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/03 21:46:03 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/vec3.h"

t_vec3	ft_vec3_rotate_x(t_vec3 r, float angle)
{
	t_vec3 res;

	res = (t_vec3){{{0.0, 0.0, 0.0}}};
	res.x = r.x;
	res.y = r.y * cos(angle) - sin(angle) * r.z;
	res.z = r.y * sin(angle) + cos(angle) * r.z;
	return (res);
}

t_vec3	ft_vec3_rotate_y(t_vec3 r, float angle)
{
	t_vec3	res;

	res = (t_vec3){{{0.0, 0.0, 0.0}}};
	res.x = r.x * cos(angle) + sin(angle) * r.z;
	res.y = r.y;
	res.z = -r.x * sin(angle) + cos(angle) * r.z;
	return (res);
}

t_vec3	ft_vec3_rotate_z(t_vec3 r, float angle)
{
	t_vec3	res;

	res = (t_vec3){{{0.0, 0.0, 0.0}}};
	res.x = r.x * cos(angle) - sin(angle) * r.y;
	res.y = r.x * sin(angle) + cos(angle) * r.y;
	res.z = r.z;
	return (res);
}

t_vec3	ft_rotate_vec3(t_vec3 r, t_vec3 v, int invert)
{
	if (invert)
	{
		r = ft_vec3_rotate_z(r, DEG_TO_RAD(-v.z));
		r = ft_vec3_rotate_y(r, DEG_TO_RAD(-v.y));
		r = ft_vec3_rotate_x(r, DEG_TO_RAD(-v.x));
	}
	else
	{
		r = ft_vec3_rotate_x(r, DEG_TO_RAD(v.x));
		r = ft_vec3_rotate_y(r, DEG_TO_RAD(v.y));
		r = ft_vec3_rotate_z(r, DEG_TO_RAD(v.z));
	}
	return (r);
}


t_vec3	ft_scale_vec3(t_vec3 r, t_vec3 v, int invert)
{
	if (invert)
	{
		r.x /= v.x;
		r.y /= v.y;
		r.z /= v.z;
	}
	else
	{
		r.x *= v.x;
		r.y *= v.y;
		r.z *= v.z;
	}
	return (r);
}

t_vec3	ft_translate_vec3(t_vec3 r, t_vec3 v, int invert)
{
	if (invert)
	{
		r.x -= v.x;
		r.y -= v.y;
		r.z -= v.z;
	}
	else
	{
		r.x += v.x;
		r.y += v.y;
		r.z += v.z;
	}
	return (r);
}

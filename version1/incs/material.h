/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 21:57:55 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/04 00:48:47 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

typedef struct	s_material
{
	t_vec3		diffuse1;
	t_vec3		diffuse2;
	t_vec3		specular;
	float		shininess;
	float		refraction;
	float		reflection;
	int			chess;
}				t_material;
#endif

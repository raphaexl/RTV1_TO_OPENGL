#version 410 core

# define W_W 1200
# define W_H 800
# define NB_OBJECTS_MAX 4
# define SPHERE 10
# define PLANE 11
# define CONE 12
# define CYLINDER 13
# define INFINITY 1.0e10
# define MAX_DEPTH 1

struct	t_ray
{
	vec3	start;
	vec3	dir;
};

struct t_material
{
	vec3	diffuse1;
	vec3	diffuse2;
	vec3	specular;
	float	shininess;
	float	refraction;
	float	reflection;
	int		chess;
};

struct	t_hit
{
	t_material	material;
	vec3		p;
	vec3		n;
	float		t;
	int			hit;
};


struct	t_object
{
	t_material	material;
	vec3		pos;
	vec3		trans;
	vec3		rot;
	vec3		scale;
	vec3		normal;
	float		radius;
	float		angle;
	int			type;
};

struct			t_light
{
	vec3		pos;
	vec3		intensity;
};

struct	t_camera
{
	vec3	pos;
	vec3	dir;
	vec3	horiz;
	vec3	vert;
	vec3	low_left;
};

struct	t_scene
{
	t_camera	cam;
	vec3		bg_color;
	vec3		ambient;
	int			antialias;
	int			nb_objects;
	int			nb_lights;
	t_object	objects[NB_OBJECTS_MAX];
	t_light		lights[NB_OBJECTS_MAX];
};

t_ray	ft_camera_ray(t_camera cam, float x, float y)
{
	t_ray	r;
	vec3 tmp;

	tmp = cam.low_left + (x + 0.5) / float(W_W) * cam.horiz;
	tmp = tmp +  (y + 0.5) / float(W_H) *  cam.vert;
	r.start = cam.pos;
	r.dir = normalize(tmp - r.start);
	return (r);
}

vec3	ft_background_color(t_ray r)
{
	vec3	dir;
	vec3	color;
	float	t;

	dir = normalize(r.dir);
	t = 0.5 * (dir.y + 1.0);
	dir = (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
	color = dir;
	return (color);
}

float	ft_sphere_intersect(t_object s, t_ray r, float t)
{
	vec3	dist;
	float a, b, c, delta;
	float	t1;
	float	t2;

	a = dot(r.dir, r.dir);
	dist = r.start - s.pos; 
	b = 2.0 * dot(r.dir, dist);
	c = dot(dist, dist) - (s.radius * s.radius);
	delta = b * b - 4.0 * c * a;
	if (delta < 0.0001)
		return (INFINITY);
	delta = sqrt(delta);
	t1 = (b + delta) / (2.0 * a);
	t2 = (b - delta) / (2.0 * a);
	t1 = (-b + delta) / (2.0 * a);
	t2 = (-b - delta) / (2.0 * a);
	if (((t1 < t2 || t2 < 0.001) && t1 > 0.1))
		return (t1);
	else if (((t2 < t1 || t1 < 0.001) && t2 > 0.1))
		return (t2);
	else
		return (INFINITY);

}


float		ft_plane_intersect(t_object plane, t_ray r, float t)
{
	float		ddn;
	vec3		dist;
	float		t1;

	ddn = dot(plane.normal, r.dir);
	if (abs(ddn) >= 1.0e-6)
	{
		dist = plane.pos - r.start;
		t1 = dot(dist, plane.normal) / ddn;
		if (t1 > 0.1)
			return (t1);
	}
	return (INFINITY);
}

float			ft_cone_intersect(t_object cone, t_ray r, float t)
{
	float a, b, c, delta;
	vec3		dist;
	float		anglesin;
	float		anglecos;
	float		t1, t2;

	anglecos = pow(cos(cone.angle), 2.0);
	anglesin = pow(sin(cone.angle), 2.0);
	dist = r.start - cone.pos;
	a = anglecos * (r.dir.z * r.dir.z + r.dir.x * r.dir.x)
		- anglesin * (r.dir.y * r.dir.y);
	b = 2.0 * (anglecos * (dist.z * r.dir.z + dist.x * r.dir.x)
			- anglesin * (dist.y * r.dir.y));
	c = anglecos * (dist.z * dist.z + dist.x * dist.x)
		- anglesin * (dist.y * dist.y);
	delta = b * b - 4.0 * a * c;
	if (delta < 0.00000001)
		return (INFINITY);
	delta = sqrt(delta);
	t1 = (-b + delta) / (2.0 * a);
	t2 = (-b - delta) / (2.0 * a);
	if ((t1 < t2 || t2 < 0.001) && t1 > 0.1)
		return (t1);
	else if ((t2 < t1 || t1 < 0.001) && t2 > 0.1)
		return (t2);
	else
		return (INFINITY);
}



float		ft_cylinder_intersect(t_object cy, t_ray r, float t)
{
	float	a, b, c, delta;
	float	t1, t2;
	vec3 dist;

	a = (r.dir.x * r.dir.x + r.dir.z * r.dir.z);
	dist = (r.start - cy.pos);
	b = 2.0 * (dist.x * r.dir.x + dist.z * r.dir.z);
	c = (dist.x * dist.x + dist.z * dist.z) - cy.radius * cy.radius;
	delta = b * b - 4.0 * a * c;
	if (delta < 0.0)
		return (INFINITY);
	delta = sqrt(delta);
	t1 = (-b + delta) / (2.0 * a);
	t2 = (-b - delta) / (2.0 * a);
	if (((t1 < t2 || t2 < 0.001) && t1 > 0.1))
		return (t1);
	else if (((t2 < t1 || t1 < 0.001) && t2 > 0.1))
		return (t2);
	else
		return (INFINITY);
}


int		ft_shadow_cast(t_scene s, t_ray ray, in float t)
{

	for (int i = 0; i < s.nb_objects; i++)
	{
		if (s.objects[i].type == SPHERE)
		{
			if (ft_sphere_intersect(s.objects[i], ray, t) < t)
				return (1);
		}
		else if (s.objects[i].type == PLANE)
		{
			if (ft_plane_intersect(s.objects[i], ray, t) < t)
				return (1);
		}
		else if (s.objects[i].type == CONE)
		{
			if (ft_cone_intersect(s.objects[i], ray, t) < t)
				return (1);
		}
		else if (s.objects[i].type == CYLINDER)
		{
			if (ft_cylinder_intersect(s.objects[i], ray, t) < t)
				return (1);
		}
	}
	return (0);
}

int 	ft_ray_cast(t_scene s, t_ray ray, out t_hit h)
{
	float	t1 = 100000.0;
	float	t = 1000000.0;
	int		j;
	int		type = 454545;

	h.hit = 0;
	j = -1;
	for (int i = 0; i < s.nb_objects; i++)
	{
		if (s.objects[i].type == SPHERE)
		{
			t1 = ft_sphere_intersect(s.objects[i], ray, t);
			if (t1 < t)
			{
				type = SPHERE;
				j = i;
				t = t1;
			}
		}
		else if (s.objects[i].type == PLANE)
		{
			t1 = ft_plane_intersect(s.objects[i], ray, t);
			if (t1 < t)
			{
				type = PLANE;
				j = i;
				t = t1;
			}
		}
		else if (s.objects[i].type == CONE)
		{
			t1 = ft_cone_intersect(s.objects[i], ray, t);
			if (t1 < t)
			{
				type = CONE;
				j = i;
				t = t1;
			}
		}
		else if (s.objects[i].type == CYLINDER)
		{
			t1 = ft_cylinder_intersect(s.objects[i], ray, t);
			if (t1 < t)
			{
				type = CYLINDER;
				j = i;
				t = t1;
			}
		}
	}
	if (j == -1)
		return (0);
	h.t = t;
	h.p = ray.start + h.t * ray.dir;
	if (type == SPHERE)
	{
		h.n = (1.0 / s.objects[j].radius) * (h.p - s.objects[j].pos);
		h.material = s.objects[j].material;
	}
	else if (type == PLANE)
	{
		float ddn;
		ddn = dot(s.objects[j].normal, ray.dir);
		if (ddn > 0.001)
			h.n = -s.objects[j].normal;
		else
			h.n = s.objects[j].normal;
		h.material = s.objects[j].material;
	}
	else if (type == CYLINDER)
	{
		h.n = h.p - s.objects[j].pos;
		h.n = (1.0 / s.objects[j].radius) * h.n;
		h.n = vec3(h.n.x, 0.0001, h.n.z);
		h.material = s.objects[j].material;
	}
	else if (type == CONE)
	{
		h.n = h.p - s.objects[j].pos;
		if (h.n.y > 0)
			h.n.y = -sqrt(h.n.z * h.n.z + h.n.x * h.n.x) * tan(s.objects[j].angle);
		else
			h.n.y = sqrt(h.n.z * h.n.z + h.n.x * h.n.x) * tan(s.objects[j].angle);
		h.material = s.objects[j].material;
	}
	return (1);
}

vec3	ft_compute_shading(t_scene s, t_ray ray,  t_hit hit)
{
	vec3	color = vec3(0.0, 0.0, 0.0);
	t_ray	light_ray;
	vec3	dist;

	color += s.ambient;
	light_ray.start = hit.p;
	for (int i = 0; i < s.nb_lights; i++)
	{
		dist = s.lights[i].pos - hit.p;
		float t = length(dist);
		light_ray.dir = normalize(dist);
		if (ft_shadow_cast(s, light_ray, t) == 0)
		{
			float	lambert = max(0.0, dot(light_ray.dir, hit.n));
			color += s.lights[i].intensity *  hit.material.diffuse1 * lambert;
			float		reflect;
			vec3		phong_dir;
			float		phong_term;

			reflect = 2.0f * dot(light_ray.dir, hit.n);
			phong_dir = light_ray.dir - reflect * hit.n;;
			phong_term = max(dot(phong_dir, ray.dir), 0.0f);
			phong_term = pow(phong_term, hit.material.shininess);
			color += s.lights[i].intensity * phong_term * hit.material.specular;
		}
	}
	return (color);
}

vec3	ft_raytrace(t_scene scene, t_ray ray)
{
	vec3	color = vec3(0.0, 0.0, 0.0);

	for (int depth = 0; depth < MAX_DEPTH; depth++)
	{
		t_hit	h;

		if (ft_ray_cast(scene, ray, h) == 0)
			return (scene.bg_color);
		color += ft_compute_shading(scene, ray, h);
		if (h.hit == 0)
			break ;
		if (h.material.reflection > 0)
		{
			ray.start = h.p;
			ray.dir = reflect(ray.dir, h.n);
		}
	}
	return (color);
}

uniform t_scene scene;
out vec4    frag_color;

void    main()
{
	vec3	color = vec3(0.0, 0.0, 0.0);
	for (int i = 0; i < scene.antialias; i++)
	{
		float	x = float(gl_FragCoord.x - W_W / 2);
		float	y = float(gl_FragCoord.y - W_H / 2);
		t_ray	ray;

		ray = ft_camera_ray(scene.cam, x, y);
		color += ft_raytrace(scene, ray);
	}
	frag_color = vec4(color, 1.0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:11:54 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/23 16:41:50 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/opengl.h"

void    ft_run(void)
{
	GLFWwindow  *win;
	t_quad		q;
	t_shader    shader;
	t_scene		scene;
	static  double  last_time;

	scene = ft_scene_init();
	if (!(win = ft_opengl_window()))
		return ;
	ft_opengl_print();
	ft_quad_init(&q);
	shader = ft_shader_init("commons/vertex_shader.glsl", "commons/fragment_shader.glsl");
	last_time = glfwGetTime();
	ft_shader_use(&shader);
	ft_scene_uniforms(&scene, &shader);
	while (!glfwWindowShouldClose(win))
	{
		ft_process_input(win, &scene.cam, (float)(glfwGetTime() - last_time));
		ft_camera_uniforms(&scene.cam, &shader);
		ft_lights_uniforms(scene.lights, scene.nb_lights, &shader);
		scene.lights[0].pos.z = 10 * cos(glfwGetTime());
		scene.lights[0].pos.x = 10 * sin(glfwGetTime());
		last_time = glfwGetTime();
		glClearColor(0.2, 0.3, 0.4, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		ft_shader_use(&shader);
		ft_quad_draw(&q);
		glfwSwapBuffers(win);
		glfwPollEvents();
	}
	ft_quad_quit(&q);
	ft_shader_clear(&shader);
	ft_opengl_clear(&win);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:11:54 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/04 21:50:45 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/opengl.h"

void printWorkGroupsCapabilities(void) {
	int workgroup_count[3];
	int workgroup_size[3];
	int workgroup_invocations;

	glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_COUNT, 0, &workgroup_count[0]);
	glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_COUNT, 1, &workgroup_count[1]);
	glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_COUNT, 2, &workgroup_count[2]);

	printf ("Taille maximale des workgroups:\n\tx:%u\n\ty:%u\n\tz:%u\n",
			workgroup_count[0], workgroup_count[1], workgroup_count[2]);

	glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE, 0, &workgroup_size[0]);
	glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE, 1, &workgroup_size[1]);
	glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE, 2, &workgroup_size[2]);

	printf ("Nombre maximal d'invocation locale:\n\tx:%u\n\ty:%u\n\tz:%u\n",
			workgroup_size[0], workgroup_size[1], workgroup_size[2]);

	glGetIntegerv (GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS, &workgroup_invocations);
	printf ("Nombre maximum d'invocation de workgroups:\n\t%u\n", workgroup_invocations);
}

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
	printWorkGroupsCapabilities();
	ft_quad_init(&q);
	shader = ft_shader_init("commons/vertex_shader.glsl", "commons/fragment_shader.glsl");
	last_time = glfwGetTime();
	ft_shader_use(&shader);
	ft_scene_uniforms(&scene, &shader);
	while (!glfwWindowShouldClose(win))
	{
		ft_opengl_fps(win);
		ft_process_input(win, &scene.cam, (float)(glfwGetTime() - last_time));
		ft_scene_uniforms(&scene, &shader);
		scene.lights[0].pos.z = 10 * cos(glfwGetTime());
		scene.lights[0].pos.x = 10 * sin(glfwGetTime());
		last_time = glfwGetTime();
		glClearColor(0.2, 0.3, 0.4, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		ft_shader_use(&shader);
		ft_quad_draw(&q);
		glfwSwapBuffers(win);
		glfwPollEvents();
	}
	ft_quad_quit(&q);
	ft_shader_clear(&shader);
	ft_opengl_clear(&win);
}

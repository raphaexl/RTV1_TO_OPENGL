/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:10:18 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/04 10:55:07 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/opengl.h"

void        ft_process_mouse_move(GLFWwindow *window, t_camera *cam, float delta)
{
    static  int             first_time = 1;
    static  t_vec2          last = {{{W_W / 2.0, W_H / 2.0}}};
    static  t_vec2          pos;
    double  pos_x, pos_y;
    t_vec2                  offset;

    glfwGetCursorPos(window, &pos_x, &pos_y);
    pos.x = pos_x;
    pos.y = pos_y;
    if (first_time)
    {
        pos.x = last.x;
        pos.y = last.y;
        first_time = 0;
 	glfwSetCursorPos(window, pos_x, pos_y);
    }
    offset.x = pos.x - last.x;
    offset.y = last.y - pos.y;
    last.x = pos.x;
    last.y = pos.y;
    (void)delta;
    ft_camera_mouse_move(cam, offset.x, offset.y);
}

int    ft_process_input(GLFWwindow *win, t_cam *cam, float delta)
{
    t_camera_mvt direction = FORWARD + 8;
    int       w;
    int       h;
	int			ret = 0;

    glfwGetFramebufferSize(win, &w, &h);
    w = w > 1 ? w : 1;
    h = h > 1 ? h : 1;
    cam->ratio = (float)w / (float)h;
    if (glfwGetKey(win, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(win, GLFW_TRUE);
    else if (glfwGetKey(win, GLFW_KEY_UP) == GLFW_PRESS && (ret = 1))
    direction = FORWARD;
    else if (glfwGetKey(win, GLFW_KEY_DOWN) == GLFW_PRESS && (ret = 1))
    direction = BACKWARD;
    else if (glfwGetKey(win, GLFW_KEY_RIGHT) == GLFW_PRESS && (ret = 1))
    direction = RIGHT;
    else if (glfwGetKey(win, GLFW_KEY_LEFT) == GLFW_PRESS && (ret = 1))
    direction = LEFT;
     else if (glfwGetKey(win, GLFW_KEY_KP_ADD) == GLFW_PRESS && (ret = 1))
    {
        cam->fov += 0.1;
        puts("zooming ++");
    }
    else if (glfwGetKey(win, GLFW_KEY_KP_SUBTRACT) == GLFW_PRESS)
    {
        cam->fov -= 0.1;
        puts("zooming --");
    }
    if (ret)
		ft_cam_update(cam, direction, delta);
	return (ret);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:42:37 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/03 17:42:45 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/opengl.h"

void    *ft_file_content(const char *file_name, int *len)
{
    FILE    *fp;
    void    *buffer;

    if (!(fp = fopen(file_name, "r")))
    {
        fprintf(stderr, "Could not open : %s", file_name);
        return (NULL);
    }
    fseek(fp, 0, SEEK_END);
    *len = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    buffer = malloc(*len + 1);
    *len = fread(buffer, 1, *len, fp);
    ((char *)buffer)[*len] = '\0';
    fclose(fp);
    return (buffer);
}

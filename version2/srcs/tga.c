/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:42:15 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/03 17:42:29 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/opengl.h"

static short ft_le_short(unsigned char *bytes)
{
    return (bytes[0] | ((char)bytes[1] << 8));
}

void *ft_tga_read(const char *file_name, int *width, int *height)
{
    t_tga   header;
    int i, color_map_size, pixels_size;
    FILE *f;
    size_t read;
    void *pixels;

    f = fopen(file_name, "rb");

    if (!f) {
        fprintf(stderr, "Unable to open %s for reading\n", file_name);
        return NULL;
    }

    read = fread(&header, 1, sizeof(header), f);

    if (read != sizeof(header)) {
        fprintf(stderr, "%s has incomplete tga header\n", file_name);
        fclose(f);
        return NULL;
    }
    if (header.data_type_code != 2) {
        fprintf(stderr, "%s is not an uncompressed RGB tga file\n", file_name);
        fclose(f);
        return NULL;
    }
    if (header.bits_per_pixel != 24) {
        fprintf(stderr, "%s is not a 24-bit uncompressed RGB tga file\n", file_name);
        fclose(f);
        return NULL;
    }

    for (i = 0; i < header.id_len; ++i)
        if (getc(f) == EOF) {
            fprintf(stderr, "%s has incomplete id string\n", file_name);
            fclose(f);
            return NULL;
        }

    color_map_size = ft_le_short(header.color_map_len) * (header.color_map_depth/8);
    for (i = 0; i < color_map_size; ++i)
        if (getc(f) == EOF) {
            fprintf(stderr, "%s has incomplete color map\n", file_name);
            fclose(f);
            return NULL;
        }

    *width = ft_le_short(header.width);
    *height = ft_le_short(header.height);
    pixels_size = *width * *height * (header.bits_per_pixel/8);
    pixels = malloc(pixels_size);

    read = fread(pixels, 1, pixels_size, f);
    fclose(f);

    if (read != (size_t)pixels_size) {
        fprintf(stderr, "%s has incomplete image\n", file_name);
        free(pixels);
        return NULL;
    }
    return pixels;
}

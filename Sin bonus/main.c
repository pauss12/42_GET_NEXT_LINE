/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:26:46 by pmendez-          #+#    #+#             */
/*   Updated: 2023/10/05 18:26:48 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

//MAIN ------------------------------------
int main(void)
{
    int fd;
    int i;
    char *line = NULL;

    i = 1;

    //Caso leyendo desde un fichero
    fd = open("text.txt", O_RDONLY);
    
    if (fd == -1 )
        return (0); 

    //Iterar por los dferentes fds mientras ninguno de algun tipo de error (por eso >0)
	while (i < 9)
    {
        line = get_next_line(fd);
        printf("line [%02d]: %s\n", i, line);
        free(line);
        i++;
    }

    //Cerrar el fichero, antes de terminar el programa
    close(fd);
    return (0);
}

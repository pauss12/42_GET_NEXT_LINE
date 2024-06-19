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
#include "get_next_line_bonus.h"

void    ft_leaks(void)
{
    system("leaks a.out");
}

//MAIN ------------------------------------
int main(void)
{
    int fd;
    int fd1;
    int fd2;
    int fd3;
    int i;
    char *line = NULL;

    //atexit(ft_leaks);
    i = 1;
    fd = open("hola", O_RDONLY);
    fd1 = open("que", O_RDONLY);
    fd2 = open("tal", O_RDONLY);
    if (fd < 0 || fd1 < 0 || fd2 < 0)
        return (0);
	while (i < 9)
    {
        
        line = get_next_line(-1);
        printf("Fichero  =>> line [%02d]: %s\n", i, line);
        free(line);

        line = get_next_line(fd);
        printf("Fichero 1 =>> line [%02d]: %s\n", i, line);
        free(line);

        line = get_next_line(fd1);
        printf("Fichero 3 =>> line [%02d]: %s\n", i, line);
        free(line);
   

        line = get_next_line(fd2);
        printf("Fichero 2 =>> line [%02d]: %s\n", i, line);
        free(line);

        i++;
    }
    close(fd);
    close(fd1);
    close(fd2);
    return (0);
}

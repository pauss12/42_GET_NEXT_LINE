/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paulamendezsv@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:26:46 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/31 01:04:10 by paula            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    int i;
    char *line;

    i = 1;
	line = NULL;
    fd = open("text.txt", O_RDONLY);
    if (fd == -1 )
        return (0); 
	while (i < 9)
    {
        line = get_next_line(fd);
        printf("line [%02d]: %s\n", i, line);
        free(line);
        i++;
    }
    close(fd);
    return (0);
}

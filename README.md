# GET-NEXT-LINE

<p>Este proyecto trata sobre la creación de una función que permite leer una línea de un archivo descriptor de una sola vez. La función recibe un descriptor de archivo y devolvera la siguiente línea del archivo como una cadena de caracteres terminada en null. </p>

# get_next_line - 42 Madrid

## Descripción

Este proyecto tiene como objetivo implementar una función en C llamada `get_next_line` (GNL) que lee una línea de un descriptor de archivo, incluyendo el carácter de nueva línea (`\n`).

### ¿Qué es get_next_line?

`get_next_line` es una función personalizada que permite leer líneas de un archivo, manejando diferentes tamaños de búfer y archivos de gran tamaño. El objetivo es comprender la manipulación de archivos, la asignación de memoria dinámica y el manejo de errores.

## Funcionalidades

* Lectura de líneas desde un descriptor de archivo.
* Manejo de archivos de gran tamaño.
* Manejo de múltiples descriptores de archivo simultáneamente.
* Manejo de errores (lectura de archivo fallida, asignación de memoria fallida, etc.).

## Cómo usar

1.  **Clonar el repositorio:**

    ```bash
    git clone git@github.com:pauss12/42_GET_NEXT_LINE.git gnl
    cd gnl
    ```

2.  **Compilar**

	2.1. ***Compilar sin bonus***

		```bash
		cd Sin bonus
		gcc get_next_line_utils.c get_next_line.c main.c
		```

	2.2. ***Compilar con bonus***

	```bash
	cd Bonus
    gcc get_next_line_utils_bonus.c get_next_line_bonus.c main.c
    ```

3. **Ejecución**

	```bash
	./a.out <archivo>
	```

	Reemplaza `<archivo>` con la ruta del archivo que quieras leer

## Ejemplo de uso

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main() 
{
	char *line;
	int fd;
	
	fd = open("archivo.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error al abrir el archivo");
        return 1;
    }
    while ((line = get_next_line(fd)) != NULL) 
	{
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
*Este proyecto ha sido creado como parte del currículo de 42 por digonza2*

# get_next_line #

## Descripción ##

Este proyecto consiste en programar la función **get_next_line** en C. Su objetivo es leer de un *File Descriptor* (fd) y devolver una línea completa terminada en salto de línea.

Al llamar a la función de manera repetida en un bucle, permite leer el contenido de un archivo linea a linra hasta el final.

### Prototipo ###

```c
/**
 * @brief Reads a line from a file descriptor.
 *
 * This function reads from the given file descriptor until a newline character
 * is found or the end of the file is reached. It uses a static buffer to store
 * the remaining data between calls, allowing it to be called repeatedly to
 * read the file line by line.
 *
 * @param fd The file descriptor to read from.
 * @return A pointer to the line read (including the newline character if
 * present), or NULL if an error occurs or if there is nothing left to read.
 */
char *get_next_line(int fd);
```
### Parámetros ###

`fd` El descriptor de archivo (file descriptor) del que queremos leer.

### Valor devuelto ###

**Si todo va bien**: La función devuelve la **línea leida** (incluyendo el /n final, excepto si es la última línea y el archivo acaba ahí).

Si la función **falla**: Devuelve ***NULL***.

## Instrucciones de Uso ##

### 1. Integración ###

Copia los archivos `get_next_line.c`, `get_next_line_utils.c` y `get_next_line.h` en la carpeta de tu proyecto.
Luego, incluye la cabecera en tu archivo `.c`:

```c
#include "get_next_line.h"
```

### 2. Compilación ###

El proyecto debe compilarse junto con tu archivo principal (tu_programa.c). Puedes definir el tamaño del buffer con la bandera `-D BUFFER_SIZE=xx`.
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c <tu_programa.c> -o <nombre>
```

### 3. Ejecución ###

Una vez compilado, ejecuta el programa indicando el archivo que quieras leer (si tu main lo soporta) o simplemente ejecutando el binario:
```bash
./<nombre>
```
## Algoritmo ##
Lectura y Acumulación (ft_read_to_saved): Se lee del archivo en bloques de tamaño BUFFER_SIZE y se guarda en un buffer temporal. El contenido del buffer se concatena en la variable estática (saved). Este paso se repite hasta que encontramos un salto de línea (\n) o se termina el archivo.

Extracción (ft_get_line): Una vez tenemos un salto de línea asegurado, extraemos la parte correspondiente a la línea actual y la preparamos para devolverla.

Limpieza (ft_clean_saved): "Cortamos" la parte que ya hemos devuelto y dejamos en la variable estática solo lo que sobra (el resto del buffer) para la siguiente llamada.

## Estructura del Proyecto

El código está dividido en dos archivos principales. A continuación se detalla el funcionamiento y algoritmo de cada función:

### `get_next_line.c`
Contiene la lógica principal y el manejo de la memoria estática.

#### 1. `get_next_line(int fd)`
* **Función:** Es la entrada principal del programa.
* **Algoritmo:**
    1.  Verifica errores básicos (`fd` negativo o `BUFFER_SIZE` inválido).
    2.  Llama a `ft_read_to_saved` para asegurarse de que la variable estática (`saved`) tenga al menos un salto de línea o haya llegado al final del archivo.
    3.  Llama a `ft_get_line` para extraer la línea exacta que se debe devolver.
    4.  Si no hay línea (fin de archivo), libera la memoria estática y devuelve `NULL`.
    5.  Si hay línea, llama a `ft_clean_saved` para preparar la variable estática para la próxima llamada y devuelve la línea.

#### 2. `ft_read_to_saved(int fd, char *saved)`
* **Función:** Lee del archivo y acumula el texto en la variable estática.
* **Algoritmo:**
    1.  Reserva memoria para un buffer temporal.
    2.  Entra en un bucle que lee del archivo (`read`) mientras no encuentre un salto de línea (`\n`) en `saved` y siga habiendo bytes por leer.
    3.  En cada iteración, usa `ft_strjoin_gnl` para unir lo nuevo leído a lo que ya teníamos acumulado.
    4.  Libera el buffer temporal y devuelve la cadena acumulada actualizada.

#### 3. `ft_get_line(char *saved)`
* **Función:** Extrae la línea que vamos a devolver desde la variable acumulada.
* **Algoritmo:**
    1.  Calcula la longitud hasta el primer salto de línea (`\n`) incluido.
    2.  Reserva memoria exacta (`malloc`) para esa longitud.
    3.  Copia los caracteres uno a uno.
    4.  Termina la cadena con `\0` y la devuelve.

#### 4. `ft_clean_saved(char **saved)`
* **Función:** Limpia la variable estática, eliminando la línea ya devuelta y guardando solo el "sobrante" para la siguiente llamada.
* **Algoritmo:**
    1.  Localiza la posición del salto de línea (`\n`) para saber dónde empieza el "resto".
    2.  Crea una sub-cadena (`ft_substr`) con ese resto.
    3.  Libera la memoria antigua de `saved` para evitar *memory leaks*.
    4.  Verifica si la nueva cadena está vacía. Si es así, la libera y pone el puntero a `NULL` (evitando punteros colgantes). Si tiene datos, actualiza la variable estática.

---

### `get_next_line_utils.c`
Funciones auxiliares de mi libft adaptadas para la gestión eficiente de memoria en este proyecto. Las funciones moificadas tienen el sufijo `_gnl`.

#### 1. `ft_strjoin_gnl(char *s1, char *s2)`
* **Función:** Une dos cadenas.
* **Algoritmo:**
    1.  Calcula la longitud total de `s1` + `s2`.
    2.  Reserva memoria y concatena ambas cadenas.
    3.  **Diferencia clave:** Libera automáticamente la memoria de `s1` (la cadena acumuladora). Esto permite usarla dentro de un bucle sin generar fugas de memoria constantes.

#### 2. `ft_strlen_gnl(const char *str, int c)`
* **Función:** Mide la longitud de una cadena.
* **Algoritmo:**
    * Si el parámetro `c` es `0`, funciona como un `strlen` normal.
    * Si `c` tiene un valor (ej. `\n`), mide la longitud solo hasta encontrar ese carácter.

#### 3. `ft_strchr(const char *s, int c)`
* **Función:** Busca un carácter dentro de una cadena.
* **Algoritmo:** Itera la cadena y devuelve un puntero a la primera coincidencia de `c`. Si no lo encuentra, devuelve `NULL`.

#### 4. `ft_strdup(const char *s)`
* **Función:** Duplica una cadena completa.
* **Algoritmo:** Mide la cadena, reserva memoria (`malloc`) del mismo tamaño y copia todos los caracteres.

#### 5. `ft_substr(char const *s, unsigned int start, size_t len)`
* **Función:** Crea una sub-cadena a partir de una posición dada.
* **Algoritmo:**
    1.  Verifica que la posición de inicio sea válida.
    2.  Calcula la longitud real necesaria (para no leer fuera de memoria).
    3.  Reserva memoria y copia el fragmento deseado.

## Parte Bonus ##

En la versión bonus del proyecto, la función incluye una mejora principal, la gestión de múltiples archivos. Puede leer de varios File Descriptors a la vez sin perder el hilo de lectura de ninguno utilizando solo una variable estática.

## Recursos ##


* [Manual de read()](https://man7.org/linux/man-pages/man2/read.2.html) - Documentación oficial de la función read.
* [Manual de malloc() / free()](https://man7.org/linux/man-pages/man3/free.3.html) - Gestión de memoria dinámica.
* [Documentación de Valgrind](https://valgrind.org/docs/manual/quick-start.html) - Guía rápida para detectar leaks.


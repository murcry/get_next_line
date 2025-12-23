*Este proyecto ha sido creado como parte del currículo de 42 por digonza2*
# get_next_line #
## Descripción ##
Este proyecto se trata de la función get_next_line del lenguaje C. Cuando llamas a la función, devuelve una línea del archivo al que apunta el descriptor de archivo. Cuando se llama a la función de manera repetida, permite leer el archivo linea a linea hasta el final.
### Cabecera de la función ###
**char**	*get_next_line(**int** fd);
### Parámetros ###
**fd** -> El descriptor de archivo a leer.
### Valor devuelto ###
Si todo va **bien** la función devuelve la **línea leida.**

Si la función **falla**, por el motivo que sea, devuelve ***NULL***.
### Cosas a tener en cuenta ###
Esta función lee la primera línea del archivo cuando la llamamos por primera vez y va leyendo la línea siguiente cada vez que se le llama hasta que se acaba el documento. Si el documento se ha acabado (o no existe), la función devuelve ***NULL***.
### Parte Bonus ###
En la parte bonus de este proyecto, la función puede leer varios archivos distintos a la vez, recordando por donde iba en cada archivo.
## Instrucciones ##

## Algoritmo ##
El algoritmo de esta función se basa en ir rellenando un buffer del tamaño BUFFER_SIZE
## Recursos ##

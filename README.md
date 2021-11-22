# CS50Xni Pset 3: Music

Implementar:

-   <a href="#Music" class="btn btn-sm btn-default">Music</a>


<h2 id="Music">Music</h2>

### Comprendiendo el pset

Vamos a leer estos archivos para entenderlos. Avancemos, usualmente el primer paso para resolver un problema será ir leyendo y comprendiendo el código de otra persona, ya sea el nuestro o el de una biblioteca. De esta manera, puedes construir sobre el trabajo de otros y resolver por tu cuenta problemas aún más interesantes .

### `songs/`

Primero abre  `songs/`, con  `cd`  o navega a través del navegador de archivos del IDE. En ese directorio, hay un grupo de archivos  `.txt`, dentro de los cuales, resulta que hay una gran cantidad de canciones. Debido a que el código ASCII por sí solo no se presta para elaborar hermosas partituras como tal, en su lugar, hemos adaptado en su lugar para las canciones unos archivos con formato “legible por la máquina”. En cada una de las líneas de cada archivo hay una nota y una duración, separadas con  `@`. Por ejemplo, en la parte superior de  `jeopardy.txt`  (te invitamos a abrir el archivo) están estas líneas:

```
G4@1/4
C5@1/4
G4@1/4
C4@1/4
G4@1/4
C5@1/4
G4@1/4
```

La primera nota de la canción Jeopardy es, de hecho, una negra (  `1/4`  de nota), específicamente una G (Sol) en la cuarta octava, la segunda nota también es una negra, pero esa es una C (Do) en la quinta octava, y hay otras 5 notas adicionales también.

Debajo de las primeras siete líneas en  `jeopardy.txt`, hay dos líneas en blanco, que implica después de la séptima nota le siguen dos silencios de corchea (2 de ⅛, equivalentes a un cuarto de silencio, o bien una negra). Después de esos silencios, la canción se reanuda, y varias notas más adelante la canción presenta otros silencios solo una vez más..

¿Tiene sentido?, siéntete libre de mirar los demás archivos  `.txt`  en  `songs`. Aunque a simple vista los archivos parecieran encriptados, en realidad son solo una traducción de arriba hacia abajo de una partitura (mucho más bonita) a un formato legible por la máquina. Decimos “Legible por la máquina” en el sentido de que, ¡pronto escribirás código para leer esas notas y sus duraciones!

#### `notes.c`

A continuación, abre  `notes.c`. En este archivo hay un programa (que pronto será llamado como  `notes`) que no solo imprime las frecuencias (Hertz) de todas las notas en una octava, sino que también genera un archivo WAV (archivo de audio) a través del cual puedes escuchar esas mismas notas. Por defecto, lo hace para la cuarta octava, pero si le pasa un argumento en la línea de comando (un número entre 0 y 8, inclusive), puedes ver y escuchar la frecuencias de las notas en cualquier octava

Lee los comentarios y el código en  `notes.c`  y trate de entender todas las líneas o la mayor cantidad que puedas. Algunas partes te parecerán desconocidas. Por ejemplo, se utiliza una función llamada  `fprintf`  para imprimir mensajes de error hacia  `stderr`  (también conocido como error estándar) a diferencia de  `printf`  que imprime hacia  `stdout`  (conocido como salida estándar). De forma predeterminada, los mensajes impresos en  `stdout`  y  `stderr`  aparecen en la pantalla del usuario. Pero es posible separarlos cuando se ejecuta un programa, de tal forma que los usuarios puedan distinguir los mensajes de error de los que no lo son. ¡Pero más acerca de eso en otro momento!

Observe cómo  `main`  retorna  `1`  en caso de que haya un error. Esto se hace por convención (es decir, que las personas se pusieron de acuerdo en hacer las cosas así). Por ahora, no hemos devuelto ningún valor desde  `main`. Pero, recuerde que todo este tiempo la función  `main`  ha tenido un tipo de retorno, específicamente  `int`. Resulta que cuando la función principal  `main`  termina de ejecutarse, por defecto retorna  `0`, lo que significa que el programa finalizó correctamente. Sin embargo, si algo sale mal en algún momento en el programa, es una convención de que se debe retornar un valor distinto de  `0`  , por ejemplo  `1`. A ese valor de retorno se le denomina “Código de salida” (exit code) y se puede usar para distinguir un tipo de error de otro. De hecho, si alguna vez ha visto un código de error encriptado en la pantalla de su Mac o PC, es muy posible que haya sido el valor devuelto por la función  `main`  de algún programa (con errores).

Observe también cómo este programa utiliza una función llamada  `sprintf`  la cual, no imprime en pantalla un mensaje, sino que almacena su salida en una cadena (de ahí la  `s`  de string en  `sprintf`) . En este caso, se está utilizando para crear una cadena a partir de dos marcadores de posición (formatos de texto de salida),  `%s`  y  `%i`. Observe cómo asignamos espacio para una cadena (corta) al declarar un arreglo para 4  `char`. Luego usamos  `sprintf`  par almacenar en la memoria  `NOTES[i]`  (un  `string`, por lo tanto  `%s`), seguida de un  `octavo`  (un  `int`, por lo tanto  `%i`). De esa manera, podemos tomar valores como  `“A”`  y  `4`  y concatenarlos (es decir, unirlos) para crear un nuevo  `string`, cuyo valor es, por ejemplo  `A4`.

A lo largo de este programa, hacemos la llamada a algunas funciones (que nos pueden resultar poco familiares)las cuales son  `song_open`,  `frequency`,  `note_write`  y  `song_close`. Resulta que esas funciones se implementan en otros archivos del código distribuible del pset, ¡Esté atento de ellos!

### `synthesize.c`

En este archivo hay un programa (que pronto será llamado como  `synthesize`) que sintetiza (es decir, genera) una cancion a partir de una secuencia de notas. Observe cómo obtiene esas notas de un usuario usando  `get_string`. Sin embargo, primero verifica si la entrada del usuario es un silencio, como sucedería si el usuario simplemente presiona Enter. De lo contrario, procede a “separar” la entrada del usuario en dos: Una nota, que se puede encontrar a la izquierda de  `@`  en la entrada del usuario, y una fracción, que se puede encontrar a la derecha de  `@`. El programa usa una función llamada  `strtok`  para facilitar esta tarea. Luego, se escribe esa nota (o silencio) en un archivo.

### `wav.h`

A continuación se encuentra  `wav.h`, un archivo de cabecera usado por  `notes.c`  y  `synthesize.c`. Este archivo, junto con  `wav.c`, no representan un programa, sino una “Biblioteca o Librería”. Recuerda que una librería es un archivo que contiene un set de funciones que otros programas pueden utilizar como bloques de construcción, al igual que hacen  `cs50.h`  y  `stdio.h`.

Dentro de  `wav`.h están las definiciones para dos nuevos tipos de datos, uno llamado  `note`  y otro llamado  `song`. Pero veremos más de eso y de palabras claves tales como typedef y struct en otra ocasión. Por ahora, solo nota que este archivo declara cuatro funciones:  `note_write`,  `rest_write`,  `song_close`, y  `song_open`; las que son usadas por notes y por  `synthesize`.

### `wav.c`

En  `wav.c`  están las implementaciones reales de esas y otras funciones más. De hecho, este archivo contiene funciones que dan soporte para archivos de tipo WAV, un formato popular para archivos de audio. Esas funciones le permiten a  `notes`  y  `synthesize`  guardar las notas en archivos con extensión .wav. Para reproducir esos archivos  `.wav`, simplemente ábrelos a través del explorador de archivos del IDE de CS50 o descárgalos a tu PC o Mac para reproducirlos localmente.

No es necesario que comprendas todo el código en  `wav.c`, ¡pero puedes leerlo si lo deseas!.

### `Makefile`

A continuación, abra  `Makefile`, cuyo formato es quizás muy diferente de cualquier cosa que haya visto antes. Como su nombre puede sugerir, está relacionado con  `make`, el programa que ha estado utilizando para compilar la mayoría de sus programas, aunque esto ha sido porque la compilación de programas con el propio  `clang`  requiere más argumentos. En problemas anteriores, no hemos necesitado un  `Makefile`, que es esencialmente un archivo para configurar  `make`, ya que make puede inferir por defecto cómo compilar un programa que consta de un solo archivo (Ejemplo,  `hello.c`). Pero compilar  `notes`  y  `synthesize`  requiere de múltiples archivos, ya que ambos programas dependen de  `wav.h`  y  `wav.c`, más otros dos archivos,  `helpers.h`  y  `helpers.c`.

Si simplemente ejecutamos

```
make notes
```

o

```
make synthesize
```

No nos proporciona suficiente información para que  `make`  sea capaz de inferir cuáles archivos necesita nuestro programa para compilarlo correctamente. Así que  `Makefile`  existe para que  `make`  sepa cómo compilar este programa.

### `helpers.h`

En este archivo, están las declaraciones de 3 funciones:

-   `duration`, el cual toma como argumento de entrada un  `string`  en forma de fracción (ejemplo,  `1/4`  ) y retorna un  `int`  correspondiente a un número de corcheas (notas de  `1/8`  ) (`2`, en este caso, ya que  `1/4`  equivale a  `2/8`, ó  `2(1/8)=1/4`  o sea dos veces un octavo).
    
-   `frequency`, el cual toma como argumento de entrada un  `string`  con una nota formateada como
    
    -   `XY`  (Ejemplo,  `A4`), donde  `X`  es cualquier letra desde  `A`  hasta  `G`, y  `Y`  es cualquier número entre  `0`  y  `8`, o
        
    -   `XYZ`  (Ejemplo,  `A#4`), donde  `X`  es cualquier letra desde  `A`  hasta  `G`,  `Y`  es  `#`  o  `b`, y  `Z`  es cualquier número entre de  `0`  y  `8`,
        
    
    y retorna como  `int`  la frecuencia correspondiente a la nota, redondeado al entero más cercano; y
    
-   `is_rest`, que retorna  `true`  si su entrada es un  `string`  que representa un silencio en nuestro formato legible por la máquina, de lo contrario retorna  `false`.
    

### `helpers.c`
En este archivo  _debería_  haber implementaciones de esas 3 funciones, ¡pero no están! aún. Ahí es donde entras tú!.

## Especificaciones

### `bday.txt`

En  `bday.txt`  escriba la representación en ASCII de  _Happy Birthday_, para hacer esto traduce la partitura de esta canción (que se muestra en una imagen al inicio del pset) en un formato legible por la máquina a como se indicaba anteriormente. Descubrirás que la canción empieza con:

```
D4@1/8
D4@1/8
E4@1/4
D4@1/4
G4@1/4
F#4@1/2
```

### `helpers.c`
#### `is_rest`

Completa la implementación de  `is_rest`  en  `helpers.c`. Recuerde que las líneas en blanco representan silencios en el formato legible por la máquina. Y recuerde que  `synthesize`  llamará a esta función para determinar si una de las líneas que ha escrito el usuario está realmente en blanco.

¿Qué significa que una línea esté en blanco? Para responder a esa pregunta, empieza por observar la librería  `cs50.h`, donde se documenta  `get_string`:

[github libcs50](https://github.com/cs50/libcs50/blob/develop/src/cs50.h)

¿Qué dicen los comentarios en la parte superior de  `get_string`  sobre lo que retorna la función si un usuario simplemente presiona Enter, lo cual quiere decir que solo se ingresa un salto de línea (`\n`)?.

Cuando a  `is_rest`  se le pasa un  `string`, en este caso  `s`, entonces… ¿Cómo lo reconocerá como silencio?

#### `duration`

Completa la implementación de  `duration`  en  `helpers.c`. Recuerde que esta función debe tomar como parámetro una fracción de tipo  `string`, y convertirla a un número entero de octavos (corcheas). Puede suponer que  `duration`  solo recibirá un  `string`  con formato del tipo  `X/Y`, donde cada dígito de  `X`  y  `Y`  es un entero positivo, y  `Y`  es, además, una potencia de 2.

#### `frequency`

Para terminar, completa la implementación de  `frequency`  en  `helpers.c`. Recuerda que esta función debe tomar como parámetro de entrada una nota como  `string`  (Ejemplo,  `A4`) y retornar su correspondiente frecuencia en hertz como un  `int`.

Y recuerde que:

1.  La frecuencia,  _f_, de alguna nota es 2_n_/12  ✕ 440, donde  _n_  es el número de semitonos de esa nota hasta  `A4`.
2.  Cada tecla en el piano se dice que es un semitono, o es lo mismo decir que está a “medio paso de distancia de su vecino más próximo”, ya sea una tecla blanca o negra.
3.  El efecto de  `#`  y  `b`, también conocidos como alteraciones, es aumentar o disminuir respectivamente, el tono de una nota en un semitono.

Al implementar esta función, te encontrarás con  `pow`  y  `round`, ambos declarados en  `math.h`.

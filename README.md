# Pset 3 CS50Xni

Implementar:

-   <a href="#Music" class="btn btn-sm btn-default">Music</a>


<h2 id="Music">Music</h2>
### Especificaciones

#### `bday.txt`

En  `bday.txt`  escriba la representación en ASCII de  _Happy Birthday_, para hacer esto traduce la partitura de esta canción (que se muestra en una imagen al inicio del pset) en un formato legible por la máquina a como se indicaba anteriormente. Descubrirás que la canción empieza con:

```
D4@1/8
D4@1/8
E4@1/4
D4@1/4
G4@1/4
F#4@1/2
```

#### `helpers.c`
##### `is_rest`

Completa la implementación de  `is_rest`  en  `helpers.c`. Recuerde que las líneas en blanco representan silencios en el formato legible por la máquina. Y recuerde que  `synthesize`  llamará a esta función para determinar si una de las líneas que ha escrito el usuario está realmente en blanco.

¿Qué significa que una línea esté en blanco? Para responder a esa pregunta, empieza por observar la librería  `cs50.h`, donde se documenta  `get_string`:

[github libcs50](https://github.com/cs50/libcs50/blob/develop/src/cs50.h)

¿Qué dicen los comentarios en la parte superior de  `get_string`  sobre lo que retorna la función si un usuario simplemente presiona Enter, lo cual quiere decir que solo se ingresa un salto de línea (`\n`)?.

Cuando a  `is_rest`  se le pasa un  `string`, en este caso  `s`, entonces… ¿Cómo lo reconocerá como silencio?

##### `duration`

Completa la implementación de  `duration`  en  `helpers.c`. Recuerde que esta función debe tomar como parámetro una fracción de tipo  `string`, y convertirla a un número entero de octavos (corcheas). Puede suponer que  `duration`  solo recibirá un  `string`  con formato del tipo  `X/Y`, donde cada dígito de  `X`  y  `Y`  es un entero positivo, y  `Y`  es, además, una potencia de 2.

##### `frequency`

Para terminar, completa la implementación de  `frequency`  en  `helpers.c`. Recuerda que esta función debe tomar como parámetro de entrada una nota como  `string`  (Ejemplo,  `A4`) y retornar su correspondiente frecuencia en hertz como un  `int`.

Y recuerde que:

1.  La frecuencia,  _f_, de alguna nota es 2_n_/12  ✕ 440, donde  _n_  es el número de semitonos de esa nota hasta  `A4`.
2.  Cada tecla en el piano se dice que es un semitono, o es lo mismo decir que está a “medio paso de distancia de su vecino más próximo”, ya sea una tecla blanca o negra.
3.  El efecto de  `#`  y  `b`, también conocidos como alteraciones, es aumentar o disminuir respectivamente, el tono de una nota en un semitono.

Al implementar esta función, te encontrarás con  `pow`  y  `round`, ambos declarados en  `math.h`.
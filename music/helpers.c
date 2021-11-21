// Helper functions for music
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

#include "helpers.h"

int duration(string fraction)
{
    /*
        se ingresa un string de la forma X/Y
        y se convierte X en numerador e Y en denominador
        se devuelve el resultado de 8 entre el denominador por el numerador
    */
    int denominador = atoi(&fraction[2]);

    int numerador = atoi(&fraction[0]);

    return (8 / denominador)* numerador;

}

int frequency(string note)
{
    /*
    creditos a mi amigo musico matematico alejandro que me
    ilumino para armar lo de la distancia en semitonos desde A4 xD
    */
    int octava = 0;

    int n = 0;

    if (strlen(note)==3)
    {
        octava = atoi(&note[2]);

        char semitono = note[1];
        //si es sostenida esta un semitono arriba
        if (semitono=='#')
        {
            n += 1;
        }//si es bemol esta un semitono abajo
        else if (semitono == 'b')
            n -= 1;

    }
    else//en caso que no sea bemol ni sostenida
    octava = atoi(&note[1]);


    char nota = note[0];
    //respectivamante la distancia en semitonos desde esa tecla hasta A4 aun sin tomar en cuenta el numero de octavas
    if (nota == 'D')
        n -= 7;

    else if (nota == 'E')
        n -= 5;

    else if (nota == 'F')
        n -= 4;

    else if (nota == 'G')
        n -= 2;

    else if (nota == 'A')
        n += 0;

    else if (nota == 'B')
        n += 2;

    else if (nota == 'C')
        n -= 9;

    //n es la cantidad de semitonos ya tomando en cuenta las octavas
    n += (octava - 4) * 12;
    //la division en el exponente de n/12 para sacar la fecuencia
    float exponente = n/12.0;
    // 2 elevado al exponente por 440 ya redondeado
    float frecuencia = round(pow(2, exponente)*440);

    return frecuencia;
}

bool is_rest(string s)
{
    //si el tamaño de el string ingresado mide 0 quiere decir que solo fue un espacio en blanco ""
    if(strlen(s) == 0)
    {
        return true;
    }
    else
    return false;
}

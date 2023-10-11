/*FUNDAMENTOS DE PROGRAMACIÓN AA4 (Antoni Fernández Almécija*/

#include <stdio.h>
#include <stdbool.h>
#define MAX_SEQ 1000

int main()
{
    float seq[MAX_SEQ];
    int i = 0, t = 0, num_preparados = 0, lecturas_contribuyentes = 0, tiempo_total = 0;
    float l = 0, media_acidez = 0, preparados_por_minuto = 0, media_consecutivas_4 = 0, exceso_consecutivas_2 = 0;
    bool control_acidez1 = false, control_acidez2 = false;

    // Leer la secuencia de tiempos e indices de acidez
    printf("Introduce tiempo (-1 para terminar): ");
    scanf("%d", &t);
    while (t != -1)
    {
        printf("Introduce indice de acidez: ");
        scanf("%f", &l);
        // printf("Calculo_1:  %f\n", l);

        seq[i] = l;
        // printf("Calculo_2:  %f\n", seq[i]);
        i++;

        if (i >= 4)
        {
            // Comprobar si se ha superado el control de calidad
            media_consecutivas_4 = (seq[i - 1] + seq[i - 2] + seq[i - 3] + seq[i - 4]) / 4.0;
            if (media_consecutivas_4 >= 0.6)
            {
                control_acidez1 = true;
            }
        }

        if (i >= 2)
        {
            exceso_consecutivas_2 = (seq[i - 1] + seq[i - 2]) / 2.0;
            // printf("Calculo_3: %f\n", exceso_consecutivas_2);
            if (exceso_consecutivas_2 > 0.7)
            {
                control_acidez2 = true;
            }
        }

        media_acidez += seq[i];

        // Calcular el tiempo total
        tiempo_total += t;

        // Contar el numero de preparados
        num_preparados++;
        printf("Introduce tiempo (-1 para terminar): ");
        scanf("%d", &t);
    }

    if (control_acidez1)
    {
        printf("No se ha superado el control, puesto que:\nSe han producido cuatro cotizaciones consecutivas con una media del indice de acidez que supera el 0.6\n", media_consecutivas_4);
    }
    else if (control_acidez2)
    {
        printf("La secuencia no ha superado el control porque hay dos lecturas consecutivas que exceden un indice de acidez de un 0.7%%\n");
    }
    else
    {

        // Calcular la media de los indices de acidez
        float sum = 0;
        for (int j = 0; j < num_preparados; j++)
        {
            sum += seq[j];
        }
        media_acidez = sum / num_preparados;

        // Calcular el numero de lecturas que contribuyen a la media parcial
        if (num_preparados > 1)
        {
            float media_acidez_parcial = seq[0];
            for (int j = 1; j < num_preparados; j++)
            {
                // Calcular la media parcial
                media_acidez_parcial = (seq[j] + j * media_acidez_parcial) / (j + 1);

                // Incrementar el contador si la lectura contribuye a la media parcial
                if (seq[j] > media_acidez_parcial)
                {
                    lecturas_contribuyentes++;
                }
            }
        }

        // Calcular el numero de preparados por minuto
        preparados_por_minuto = num_preparados / (tiempo_total / 60.0);

        // Mostrar los resultados
        printf("El numero de preparados ha sido de: %d\n", num_preparados);
        printf("El tiempo empleado para realizar los preparados ha sido de: %d segundos\n", tiempo_total);
        printf("Las lecturas que han contribuido al incremento parcial de la media han sido %d\n", lecturas_contribuyentes);
        printf("La media de los indices de acidez ha sido de: %f\n", media_acidez);
        printf("El numero de preparados por minuto ha sido de: %f\n", preparados_por_minuto);
    }

    // Resetear las variables para el siguiente preparado
    media_acidez = 0;
    lecturas_contribuyentes = 0;
    i = 0;

    return 0;
}
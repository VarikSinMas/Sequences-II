# Sequences-II

Tenemos una secuencia de tiempos seguidos de índices de acidez de un preparado, tomadas por un control de calidad durante la fabricación de este producto por parte de una máquina, las cuales tienen la siguiente estructura:
 
 <t0 l0 t1 l1 t2 l2 ... tn ln -1> donde

ti es un entero positivo que indica el número de segundos desde que se fabricó el preparado anterior i-1, y en el que se toma la lectura de índice de acidez li del preparado actual ‘i’.
li es un real positivo que indica el índice de acidez en tanto por cien del preparado ‘i’.
 
Los datos están ordenados cronológicamente en la secuencia.
 
En caso de que la secuencia pase el control al que se la somete, el programa debería mostrar el número de preparados realizados, el tiempo en segundos empleado para ello, la media de las lecturas de acidez, así como cuántas de estas lecturas han contribuido al incremento de la media parcial, que es la media calculada en el momento en que se realiza un preparado, y finalmente el número de preparados fabricados por minuto. 

Por otro lado, una secuencia no supera el control de calidad si, o bien se producen dos lecturas consecutivas que exceden un índice de acidez de un 0.7%, o tampoco se supera este control en el momento en que en las últimas 4 lecturas la media del índice de acidez para estas 4 lecturas supera o es igual al 0.6%. 

En caso de que se no se pase el control de calidad, el programa debería mostrar el la razón por la que no se ha pasado ese control, una o ambas. 
Hay que tener en cuenta que la impresión de una u otra salida se ha de encapsular en una sola función.

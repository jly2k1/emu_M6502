# Emulador M6502 
Sencillo emulador del procesador de 8 bits MOS 6502 escrito en C++ y documentado en español. 

El MOS 6502 es un microprocesador de 8 bits fabricado por la empresa Mos Technology en el año 1975. Cuando fue lanzado al mercado este era más barato que sus competidores de ese entonces (Motorola e Intel) y fue utilizado en sistemas famosos, como el APPLE II en ordenadores o las consolas de videojuegos Atari 2600 y el NES (aunque en este último se utilizaría una version modificada). 

![imagen del mos 6502.](https://upload.wikimedia.org/wikipedia/commons/4/49/MOS_6502AD_4585_top.jpg)

## Descripción tecnica del MOS 6502.

### Registros.
El M6502 posee los siguientes registros:

- **Acumulador**. Este registro es utilizado para almacenar los resultados de operaciones aritméticas y lógicas. Tiene un tamaño de 8 bits. 
- **Indice X**. Este registro es utilizado como contador o para acceder a la memoria. Tiene una función especial la cual es: copiar el puntero de pila (SP) o cambiar su valor. Su tamaño es igualmente de 8 bits.
- **Indice Y**. Similar al registro **Indice X**. No tiene ningúna función especial. Su tamaño es de 8 bits.
- **Puntero de pila (SP)**. Registro que guarda la posición actual en la pila de llamadas. Su tamaño es de 8 bits.
- **Registro de estado**. Este registro es similar al registro FLAGS de los procesadores Intel x86 y contiene el estado actual del procesador. Por ejemplo, si hubo un acarreo en alguna operación aritmética o si el resultado fue cero, uno de los bits de este registro se pondra en '1' o en '0' si se a dado tal situación o no. Este registro tambien es de 8 bits. 
- **Contador de programa (PC)**. Registro que apunta a la siguiente instrucción que se debe ejecutar. Este registro es de 16 bits. **¡Aunque!** la arquitectura del M6502 nos muestra que éste está divido en dos registros de 8 bits (pues recuerdése que este procesador es de 8 bits). Sin embargo, en el emulador lo representaremos con un tipo de dato de 16 bits.


## Memoria.

El M6052 puede direccionar hasta 64 KB de memoria (memoria RAM, claro) debido al bus de direcciones que posee; el cual es de 16 bits. Dicha memoria está divida en paginas esto es, la memoria se divide en bloques de 256 bytes y cada bloque se le llama *pagina* o «page». Cada pagina tiene un propósito especifico. 

## Modos de direccionamiento.


## Referencias y documentación consultada. 
[6502.org](http://www.6502.org/)
[Cdot wiki 6502](https://wiki.cdot.senecacollege.ca/wiki/6502)
[Articulo de la wikipedia](https://en.wikipedia.org/wiki/MOS_Technology_6502)

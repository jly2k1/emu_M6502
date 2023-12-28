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

![registros del M6502](https://github.com/jly2k1/emu_M6502/blob/main/imagenes/registrosmo6502.png)

## Memoria.

El M6052 puede direccionar hasta 64 KB de memoria (memoria RAM, claro) debido al bus de direcciones que posee; el cual es de 16 bits. Dicha memoria está divida en paginas esto es, la memoria se divide en bloques de 256 bytes y cada bloque se le llama *pagina* o «page». Cada pagina tiene un propósito especifico:

|  Pagina  |  Nombre  |  Dirección inicial  |  Dirección final  |  Propósito                                                                    |
|----------|----------|---------------------|-------------------|-------------------------------------------------------------------------------|
|    00    | Pag.Cero |        $0000        |      $00FF        | Variables que requieren acceso rápido.                                        |
|    01    | Pila     |        $0100        |      $01FF        | Memoria reservada para la pila de llamadas (stack).                           |
|    FF    |Vect.Table|        $FF00        |      $FFFF        | Contiene punteros relacionados a las interrupciones o al reinicio del sistema.|

Para más información, consulta la seccion de referencias y documentación consultada.

> [!NOTE]
> $xxxx es la notación númerica para referirse a una dirección de memoria y la cual hace uso del sistema de númeracion hexadecimal. Así, FF = 256 en el sistema decimal por ejemplo.

## Modos de direccionamiento.

Los modos de direccionamiento son las diferentes maneras de especificar los operandos dentro de las instrucciones del lenguaje ensamblador. Por tanto, especifican la forma de calcular las direcciones de memoría donde se encuentran dichos operandos. A estas direcciones tambien se les llaman de forma singular como **dirección efectiva**.

> [!NOTE]
> Las instrucciones del M6502 tienen una longitud de 3 bytes o 21 bits.
> Las direcciones de memoria son de 16 bits o 2 bytes.

> [!IMPORTANT]
> Los datos se guardan en memoria en orden Little-Endian. Es decir, el byte menos significativo se guarda primero en la memoria y en la siguiente dirección el byte más significativo. Más información aquí: [Endiannes](https://es.wikipedia.org/wiki/Endianness) 

El MOS 6502 posee 13 modos de direccionamiento. 13 formas de especificar los operandos en las instrucciones del lenguaje ensamblador de este CPU. A continuación se muestran de forma breve estos modos:

- **Modo de direccionamiento inmediato**. El operando se ubica en el segundo byte de la instrucción. Esto es «al lado» del opcode.
![Representación de este modo de direccionamiento.](https://upload.wikimedia.org/wikipedia/commons/thumb/0/00/DireccionamientoInmediato.png/220px-DireccionamientoInmediato.png)
- **Modo de direccionamiento absoluto**. En el campo del operando se encuentrá la dirección de memoria donde se haya dicho operando. ![Modo de direccionamiento absoluto](https://upload.wikimedia.org/wikipedia/commons/thumb/a/a3/DireccionamientoDirecto.png/220px-DireccionamientoDirecto.png)
- **Modo de direccionamiento Implícito**. La dirección de memoria donde se encuentra el operando se ubica en el mismo opcode.
- **Modo de direccionamiento Acumulador (!)**. Este modo presenta una longitud de 1 byte. Se opera con el acumulador.
- **Modo de direccionamiento Absoluto Indexado X (!)**. Este modo es igual que el modo absoluto. Solo que a la direccion efectiva se le suma el contenido del registro indice X.
- **Modo de direccionamiento Absoluto Indexado Y (!)**. Igual al modo anterior. Pero a la dirección efectiva se le suma el contenido del registro indice Y.
  <!---Colocar los demas modos--> 

## Set de instrucciones.

## Referencias y documentación consultada. 
[6502.org](http://www.6502.org/)
[Cdot wiki 6502](https://wiki.cdot.senecacollege.ca/wiki/6502)
[Articulo de la wikipedia](https://en.wikipedia.org/wiki/MOS_Technology_6502)
[6502 CPU](https://www.pagetable.com/c64ref/6502/?tab=0)
[Fake 6502](http://rubbermallet.org/fake6502.c)

# Emulador M6502 
Sencillo emulador del procesador de 8 bits MOS 6502 escrito en C++ y documentado en español. 

El MOS 6502 es un microprocesador de 8 bits fabricado por la empresa Mos Technology en el año 1975. Cuando fue lanzado al mercado este era más barato que sus competidores de ese entonces (Motorola e Intel) y fue utilizado en sistemas famosos, como el APPLE II en ordenadores o las consolas de videojuegos Atari 2600 y el NES (aunque en este último se utilizaría una version modificada). 

![imagen del mos 6502.](https://upload.wikimedia.org/wikipedia/commons/4/49/MOS_6502AD_4585_top.jpg)

## Descripción tecnica del MOS 6502.

### Registros.
El M6502 posee registros los siguientes registros:

- **Acumulador**. El registro es de 8 bits.
- **Indice X**. El registro es de 8 bits.
- **Indice Y**. El registro es de 8 bits.
- **Puntero de pila (SP)**. El registro es de 8 bits.
- **Registro de estado**. El registro es de 8 bis.
- **Contador de programa (PC)**. El registro es de 16 bits. 

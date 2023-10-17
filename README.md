# 1° Parcial SPD, Division-J

**_El siguiente proyecto consiste en tres partes, las cuales se detallaran a continuacion:_**

_1° Parte: Contador de 0 a 99 con Display 7 Segmentos y Multiplexación_

La primera parte del proyecyto consistira en conectar dos display de 7 segmentos (uno para marcar unidad y otra para decenas) y tres botones (sumador, restador y reset) a un Arduino y programarlo de forma tal que en base a multiplexacion se puedan observar ambos displays al mismo tiempo e independientes el uno del otro.

Primero, el esquema de las conexiones de nuestro proyecto:

![](img_1.jpg)

_Los leds de cada display se conectan a las entradas digitales del Arduino (5 a 11 inclusive). Los catodos comunes a entradas analogicas (A4 para la unidad y A5 para la decena). Y los botones a entradas digitales (2 para el restador, 3 para el sumador y 4 para el reset) y a tierra._

**Codigo:**
Primero se definiran los componentes. Los leds de los displays, el valor APAGADOS (que se utiliza para apagar todos los leds), los 3 botones, las entradas analogicas de cada display (visualizador 1 y 2) y el tiempo de display entre los displays (TIMEDISPLAYON).

Se procede a definir variables:

_int sube =1;_ (Si se presiona el boton de suma)

_int subePrevia = 1;_ (Si se ha presionado anteriormente el boton de suma)

_int baja = 1;_ (Si se presiona el boton de resta)

_int bajaPrevia = 1;_ (Si se ha presionado anteriormente el boton de resta)

_int reset = 1;_ (Si se presiona el boton de reseteo)

_int resetPrevia = 1;_ (Si se ha presionado anteriormente el boton de reseteo)

_int countDigit = 0;_ (El valor del contador que se mostrara en los displays)

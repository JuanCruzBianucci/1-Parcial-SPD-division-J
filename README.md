# 1° Parcial SPD, Division-J

**_El siguiente proyecto consiste en tres partes, las cuales se detallaran a continuacion:_**

_1° Parte: Contador de 0 a 99 con Display 7 Segmentos y Multiplexación_

La primera parte del proyecyto consistira en conectar dos display de 7 segmentos (uno para marcar unidad y otra para decenas) y tres botones (sumador, restador y reset) a un Arduino y programarlo de forma tal que en base a multiplexacion se puedan observar ambos displays al mismo tiempo e independientes el uno del otro.

Primero, el esquema de las conexiones de nuestro proyecto:

![Circuito conectado](img_1.jpg)

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


En Setup se comienza con un for que iterara de 5 a 11 (los pines digitales de los leds) y luego aplicara el valor del indice 'i' en la funcion "configurarLed" (se explicara mas adelante en la seccion funciones). Luego se definen los pinMode para los botones (input_pullup, entradas), los visualizadores (output, salida) y la escritura digital de los visualizadores (comienza en LOW). Se define tambien el serial para poder utilizarlo en caso de que se necesiten hacer pruebas y revisar valores en el monitor en serie.

Funciones:
Las funciones utilizadas son las siguientes
* configurarLed:
Se utiliza para poder definir como salida a todos los pines digitales de los leds, iterando en el setup (como se menciono anteriormente) para manejar menos lineas de codigo repetitivo. Toma como parametro el led (pin) a definir y su estado (entrada o salida).

* ConfigurarDisplay:
Esta funcion se usa para definir que leds en el display se encienden, realizando un digitalWrite para cada led dentro de la funcion. Tomara 1 o 0 7 veces como parametros para definifinir que leds desea que se encienda o no para formar el digito buscado.

* dibujarNumero:
La funcion dibujar numero se encarga de definir las 10 combinaciones posibles entre los leds para formar el numero en el display. Toma como parametros el valor de 1 o 0 para cada led y el numero que desea dibujar.
Se realiza un switch tomando como variable el parametro numero y luego se define en cada caso posible (del 0 al 9) la combinacion de leds a encender y apagar con la funcion configurarDisplay ya explicada.
En cada caso debe hacerse un _break_ para que el numero se mantenga dibujado.

* prendeDigito:
Esta funcion se encarga de definir que display debera verse y cual apagarse, de forma tal que puedan, en conjunto con las demas funciones, dibujar dos digitos independientes para la unidad y la decena. La funcion toma como parametro simplemente el visualizador que debe observarse (definido como digito) y lo ejecuta mediante digitalWrite. Si "digito" corresponde al VISUALIZADOR_1, este se apagara y se encendera el VISUALIZADOR_2. Si fuera lo opuesto, se encendera el 1 y apagara el 2. Caso contrario ambos estaran encendidos.

* printCount:
La funcion printCount combinara las funciones anteriormente definidas y tomara como parametro solamente "count", que se correspondera con el numero que desea mostrarse.
Se usa la funcion prendeDigito y se da como parametro "APAGADOS", para que ambos display comienzen apagados. Luego se da un delay de 10 milisegundos (el valor definido de TIMEDISPLAYON). A continuacion se invoca a la funcion dibujarNumero dandole como parametros cada led y el valor usado para la decena ("count" dividido 10).
Despues se llama a la funcion prendeDigito, dandole como parametro el visualizador de la decena. Se repite el delay anterior y se vuelven a apagar ambos displays.
A continuación se volvera a llamar a la funcion dibujarNumero, esta vez dando como parametro del numero  _count - 10 * (int)count / 10_, que representara a la unidad.
Se usa el prendedigito nuevamente, esta vez dando como parametro el visualizador correspondiente a la unidad y se agrega el mismo delay.
De esta manera se lograra la multiplexacion en ambos digitos al alternarse ambos por solo 10 milisegundos al repetirse constantemente el "loop"

* keypressed:
Esta es la funcion encargada de determinar que boton se oprime y devolver aproiadamente el estado del mismo.
se define como sube, baja y reset al digitalWrite de cada boton respectivamente. Lo primero sera definir las "previas". Si un boton se oprime (digitalWrite = 1) entonces la previa de ese boton tmb se volvera 1 (ej. if(sube == 1) -> subePrevia = 1). Luego se crea un condicional para cada boton, en donde se comprobara si el "valor" del boton es 0 y si es diferente al de su previa. De serlo, la previa tomara el valor del actual (0) y devolvera el valor del boton.
De esta manera, se logra que el toque del boton sea preciso y no de multiples lecturas al presionarlo por "demasiado" tiempo.


El loop del codigo consistira entonces de la aplicacion de la funcion keypressed (a la cual se denominara "pressed"). Si la misma es "SUBE" se suma el contador (countDigit) en uno. Si es "BAJA" se resta en uno y si es RESET lo vuelve 0. Se crean las condicionales para asegurarse que el rango se mantenga entre 00 y 99 y luego se aplica el valor del contador como parametro a la funcion printCount que mostrara el resultado.


![Ej de circuito en funcionamiento](img_2.jpg)




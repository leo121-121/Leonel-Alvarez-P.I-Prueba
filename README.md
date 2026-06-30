# Leonel-Alvarez-P.I-Prueba
Alumno: Leonel Alvarez Cristiano
Profesor: Gonzalo Consorti
EXAMEN 1 2026

Consignas: Debes crear un sistema de monitoreo y visualización utilizando los siguientes componentes:

1) Comportamiento del Tira de Led de NeoPixel (6 LEDs): La tira de  6 LEDs se utilizará para representar el % de luz del interior de un experimento mediente una sensor del sensor sensible a la luz de la siguiente manera:
Luz mínima: Los LEDs deben  encenderse e ir encendiendo en orden  incremental (se mantientenprendido) hasta el % marcado. ( max hasta 30% LED 0 AL 1)
Luz   media: Los LEDs se deben ir encendiendo en orden incremental (se mantientenprendido)   ( 31% a  70% LED 2 AL 3)
Luz   máxima: Todos los LEDs deben encenderse  (completando la tira de 6 LEDs). (se mantientenprendido)    ( 71% a 100% LED 4 AL 5)
En todos los casos, si el sensor retrocede deben ir apagando los led gradualmente.
 A medida que el sensor detecta mayor o menor intencidad, más o menos LEDs de la tira se irán iluminando o apagando uno a uno, de un color fijo:
Verde  ( LED 0 AL 1)
Amarillo (LED 2 AL 3)
Rojo (LED   3 a 5 )
2) Lectura del Sensor luminico y Monitor Serial:
Debes realizar pruebas de lectura del sensor mediante el Monitor Serial, mostrando en la consola los valores que recibe el Arduino  de la siguiente forma:   "Sensor: X Porcentuak: X% N° Led: X Color: X "     luego mandar un enter.
Deshabilitar (sin borrar ni comentar) la parte del código para pruebas de sensores luego de realizar las pruebas de valores.
3) Pantalla LCD debe mostrar: 
La lectura actual del sensor luminico en unidades de % en un renglon.
En el segundo renglon: bien a la izquierda y en mauuscula el estado prendido o apagado del sistema.
-y El color en que se debe prender (lo mas a la derecha posible de la pantalla)
4) El estado del sistema ( con Botón en segundo plano ) :
Un PushButton debe usarse para encender y apagar el sistema completo. Al presionar el botón (una sola vez), el sistema debe activarse o desactivarse por completo.Cuando el sistema está apagado, todos los LEDs deben apagarse, pero los datos seguiran mostrandoce en la pantalla LCD
5) Entrega por GIT
subir el resuelto y entregar a classroom de forma adecuada (identico a la entrega de TP)
tener comentando el codigo en sus funcionalidades, tener el código ordenado, identado  y prolijo.

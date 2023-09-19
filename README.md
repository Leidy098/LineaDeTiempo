# Máquina del Tiempo

Este proyecto implementa una simulación de una línea de tiempo en una lista doblemente enlazada, donde cada nodo representa un evento temporal relacionado con la investigación sobre el viaje en el tiempo. La simulación incluye eventos como la observación del pasado, descubrimientos científicos, exploración del futuro y cambios en el pasado. El proyecto se desarrolló como parte de la asignatura ST0244 LENGUAJES DE PROGRAMACIÓN en la Universidad EAFIT, durante el semestre 2023-II, bajo la supervisión del profesor Alexander Narváez.

## Tabla de Contenidos

- [Integrantes](#integrantes)
- [Versión del Compilador](#versión-del-compilador)
- [IDE Utilizada en el Desarrollo](#ide-utilizada-en-el-desarrollo)
- [Descripción del Proyecto](#descripción-del-proyecto)
- [Funcionalidades](#funcionalidades)
- [Restricciones](#restricciones)
- [Uso del Proyecto](#uso-del-proyecto)
- [Ejemplo de Uso](#ejemplo-de-uso)

## Integrantes

- Leidy Gallo Vargas
- Luis Miguel Giraldo Daza

## Versión del Compilador

C++ 17

## IDE Utilizada en el Desarrollo

CLion

## Descripción del Proyecto

Este proyecto simula una línea de tiempo en una lista doblemente enlazada. Cada nodo en la lista representa un evento temporal y tiene los siguientes campos:

- `PtrPasado`: Un apuntador a un evento espaciotemporal del pasado.
- `Evento`: Puede ser A, B, C o c, dependiendo de ciertas condiciones.
- `Científico 1`: Puede ser "Einstein" si el evento es de tipo A, o "Rosen" si el evento es de tipo B.
- `Científico 2`: Puede ser "Einstein" si el evento es de tipo B y "Rosen" si el evento es de tipo C.
- `Datos`: Un número entero aleatorio entre 1 y 100.

Las condiciones para la generación de eventos y científicos se basan en si los números son primos, coprimos, y si se cumplen ciertas restricciones temporales.

## Funcionalidades

- Agregar nodos a la línea de tiempo de manera aleatoria.
- Detectar y registrar eventos relacionados con la investigación sobre el viaje en el tiempo.
- Imprimir la línea de tiempo con eventos y científicos relacionados.

## Restricciones

- Se implementaron restricciones para evitar paradojas temporales, como la transferencia de información entre científicos en diferentes eventos.
- La línea de tiempo debe tener un tamaño mínimo de 3 nodos y un máximo de 22 nodos.

## Uso del Proyecto

1. Clona este repositorio en tu máquina local.
2. Abre el proyecto en CLion o tu IDE preferido.
3. Compila el código fuente.
4. Ejecuta la aplicación.

## Ejemplo de Uso

```cpp
int main() {
    LineaDeTiempo lineaDeTiempo;
    for (int i = 0; i < 100; ++i) {
       lineaDeTiempo.agregarNodoAleatorio();
    }
    lineaDeTiempo.imprimirEventos();
    lineaDeTiempo.imprimir();

    return 0;
}

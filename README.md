# *[Dijkstra secuencial y en paralelo]*
---
#### Materia: *Análisis y Diseño de Algoritmos (TC2017)*

#### Semestre: *Otoño 2019*

##### Campus: *Santa Fe*

##### Integrantes:
1. *[Sebastián Medina Medina]* *[A00822311]*
2. *[Carlos de la Garza]* *[Matrícula]*

---
## 1. Aspectos generales

### 1.1 Requerimientos

A continuación se mencionan los requerimientos mínimos del proyecto, favor de tenerlos presente para que cumpla con todos.

* El equipo tiene la libertad de elegir el problema a resolver.
* El proyecto deberá utilizar [OpenMP](https://www.openmp.org/) para la implementación del código paralelo.
* Todo el código y la documentación del proyecto debe alojarse en este repositorio de GitHub. Favor de mantener la estructura de carpetas propuesta.

### 1.2 Estructura del repositorio
El proyecto debe seguir la siguiente estructura de carpetas:
```
- / 			        # Raíz de todo el proyecto
    - README.md			# este archivo
    - secuencial		# Carpeta con la solución secuencial
    - paralelo			# Carpeta con la solución paralela
    - docs              # Carpeta con los documentos, tablas, gráficas, imágenes
```

### 1.3 Documentación  del proyecto

Como parte de la entrega final del proyecto, se debe incluir la siguiente información:

* Descripción del problema a resolver.
* Descripción de la solución secuencial con referencia (enlace) al código secuencial alojado en la carpeta [secuencial](secuencial/).
* Análisis de los inhibidores de paralelismo presente y una explicación de cómo se solucionaron.
* Descripción de la solución paralela con referencia (enlace) al código paralelo alojado en la carpeta [paralelo](paralelo/).
* Tabla de resultados con los tiempos de ejecución medidos para cada variante de la solución secuencial vs. la solución paralela, teniendo en cuenta: 5 tamaños diferentes de las entradas, 5 opciones diferentes de números de CPU (threads), 4 ocpiones diferentes de balanceo (*auto, guided, static, dynamic*).
* Gráfica(s) comparativa(s) de los resultados obtenidos en las mediciones.
* Interpretación de los resultados obtenidos.
* Guía paso a paso para la ejecución del código y replicar los resultados obtenidos.
* El código debe estar documentado siguiendo los estándares definidos para el lenguaje de programación seleccionado.

## 2. Descripción del problema

*El algoritmo de Dijkstra, creado por el científico Edseger Dijkstra en 1956, es un algoritmo que busca los caminos más cortos de un grafo, saliendo desde un vértice único hacia todos los vertices restantes del grafo (NIST, 2006). La manera en la que el algoritmo escoge su camino es por medio de los valores del peso de las aristas, específicamente los menores.*

*En sí, el algoritmo de Dijkstra, funciona como una especialización de la [búsqueda de costo uniforme](https://algorithmicthoughts.wordpress.com/2012/12/15/artificial-intelligence-uniform-cost-searchucs/). Una característica básica del algoritmo, es que no funciona con aristas de coste negativo. El proyecto tiene la finalidad de comparar el rendimiento del algoritmo de Dijkstra en forma secuencial y en paralelo* 

## 3. Solución secuencial

1. Dentro de un método llamado init(), se crea una matriz de NxN lados de forma aleatoria.
    1 Los valores de la matriz que pertenezcan a la diagonal partiendo del punto matriz[0][0] al matriz[N][N] tienen que valer 0
    
    
    1. Actual numbers don't matter, just that it's a number
  1. Ordered sub-list
    
    
    (Ciertos valores tienen que ser 0 porque no todos los nodos tienen conexión). En dicho método se edita la matriz para que la diagonal, partiendo del punto matriz[0][0] al matriz[N][N], valgan 0.        *

## 4. Análisis de los inhibidores del paralelismo

*[Incluya aquí el análisis de los inhibidores presentes en su problema, así como la solución a los mismos.]*

## 5. Solución paralela

*[Incluya aquí la descripción de la solución paralela.]*

## 6. Tabla de resultados

*[Incluya aquí la tabla con los resultados de las mediciones.]*

## 7. Gráfica(s) comparativa(s)

*[Incluya aquí la(s) gráfica(s) comparativa(s).]*

## 8. Interpretación de los resultados

*[Incluya aquí la interpretación de los resultados.]*

## 9. Guía paso a paso

*[Incluya aquí la guía para la ejecución de los códigos.]*

## 10. Referencias

*[Incluya aquí las referencias a sitios de interés y cualquier otra información que haya utilizado para realizar el proyecto y que le puedan ser de utilidad a otras personas que quieran usarlo como referencia]*

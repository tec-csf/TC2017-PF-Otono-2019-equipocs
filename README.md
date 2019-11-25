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

1. Se crea una matriz de NxN lados de forma aleatoria.
    1. Los valores de la matriz que pertenezcan a la diagonal partiendo del punto *matriz[0][0]* al *matriz[N][N]* tienen que valer 0.
    2. No todos los valores (exceptuando la diagonal) tienen que tener un número aleatoria del rango que se escoga, ya que no todos los nodos tienen unión. Para esto, se le asigna a algunos valores *i4_huge = 2147483647* o *inf*.
    3. Los valores deben ser simétricos a la otra mitad.
    
2. Se construye un árbol con el nodo 0 de inicio. 
3. Se busca entre **todos los nodos no conectados** al árbol el nodo cuya distancia es menor. Una vez seleccionado, se conecta al árbol.
4. Se verifica que la distancia ya registrada, sea la más pequeña entre **todos los nodos no conectados**. Si es así, se intercambian los valores. 
5. Una vez todos los nodos conectados a 0, se calculan las distancias mínimas del nodo 0 a todos los nodos restantes.

## 4. Análisis de los inhibidores del paralelismo

*[Incluya aquí el análisis de los inhibidores presentes en su problema, así como la solución a los mismos.]*

## 5. Solución paralela

*[Incluya aquí la descripción de la solución paralela.]*

## 6. Tabla de resultados
En Paralelo con diferentes numeros de threads

32 threads
Tamaño de entrada	Tiempo
50,000	31.089246 segundos
20,000	9.171961 segundos
10,000	4.235772 segundos
5,000	2.148778 segundos
1,000	0.447259 segundos
	

16 threads
Tamaño de entrada	Tiempo
50,000	24.698513 segundos
20,000	5.418103 segundos
10,000	2.144412 segundos
5,000	0.961377 segundos
1,000	0.200715 segundos
	

8 threads
Tamaño de entrada	Tiempo
50,000	13.576044 segundos
20,000	3.581652 segundos
10,000	1.087213 segundos
5,000	0.394131 segundos
1,000	0.110567 segundos

4 threads
Tamaño de entrada	Tiempo
50,000	20.781091 segundos
20,000	3.922936 segundos
10,000	1.039789 segundos
5,000	0.299548 segundos
1,000	0.040850 segundos

2 threads
Tamaño de entrada	Tiempo
50,000	38.237932 segundos
20,000	6.331394 segundos
10,000	1.560365 segundos
5,000	0.421739 segundos
1,000	0.053920 segundos

1 thread
Tamaño de entrada	Tiempo
50,000	72.038223 segundos
20,000	11.659691 segundos
10,000	2.920091 segundos
5,000	0.757593 segundos
1,000	0.052634 segundos



## 7. Gráfica(s) comparativa(s)

*[Incluya aquí la(s) gráfica(s) comparativa(s).]*

## 8. Interpretación de los resultados

*[Incluya aquí la interpretación de los resultados.]*

## 9. Guía paso a paso

*[Incluya aquí la guía para la ejecución de los códigos.]*

## 10. Referencias

*[Incluya aquí las referencias a sitios de interés y cualquier otra información que haya utilizado para realizar el proyecto y que le puedan ser de utilidad a otras personas que quieran usarlo como referencia]*

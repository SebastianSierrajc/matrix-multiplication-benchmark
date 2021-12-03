# matrix multiplication benchmark

El repositorio contiene diferentes implementaciones del algoritmo de multiplicacion de matrices, con en fin de medir el rendimiento del procesador del nodo de computo en el que se ejecuten los benchmarks. 
Los algoritmos son implementados en C, ya que es un lenguaje conocido por su velocidad. 

## Introducción. 
En esta entrega se presentan dos implementaciones que utilizan paralelismo para la operación algebraica de multiplicar dos matrices cuadradas. La primera implementación usa la biblioteca Posix threads o también conocida como Pthreads, se encuentra en el directorio MM_Posix. La segunda implementación utiliza la biblioteca OpenMP, se encuentra en el directorio MM_OpenMP.

## Estructura.
Estructura del directorio de la implementación que utiliza la biblioteca Posix:
```bash
.
├── benchmarkUtils # modulo utilidades para mediciones de tiempo de ejecución.
│   ├── timeUtils.c
│   └── timeUtils.h
├── launcher.pl # automatización ejecución 
├── Makefile # automatización compilacion del main y principal
├── matrixUtils # modulo utilidades para aperaciones de matrices.
│   ├── matrixUtils.c
│   └── matrixUtils.h
├── MM1p.c # archivo main o principal de la implementacion.
├── outputs # directorio donde se almacenan las salidas de la toma de rendimiento
└── toexcel.py # Script en python para agrupar los resultados en un archivo de hoja de calculo.
```

Estructura del directorio de la implementación que utiliza la biblioteca OpenMp:
```bash
.
├── benchmarkUtils # modulo utilidades para mediciones de tiempo de ejecución.
│   ├── timeUtils.c
│   └── timeUtils.h
├── launcher.pl # automatización ejecución 
├── Makefile # automatización compilacion del main y principal
├── matrixUtils # modulo utilidades para aperaciones de matrices.
│   ├── matrixUtils.c
│   └── matrixUtils.h
├── MM1c.c # archivo main o principal de la implementacion.
├── outputs # directorio donde se almacenan las salidas de la toma de rendimiento
└── toexcel.py # Script en python para agrupar los resultados en un archivo de hoja de calculo.
```
## Modulos.
Cada implementación cuenta con unos módulos comunes que permiten la portabilidad de ciertas funcionalidades necesarias para la implementación, los módulos están conformados por un archivo .h que es la interfaz del módulo donde está la definición de las funciones y un archivo .c que es la implementación de las funciones

### benchmarkUtils
Este módulo utiliza la biblioteca time.h para crear funciones que permiten la medición del tiempo de ejecución de una función o de un fragmento del código.

### matrixUtils
Este módulo contiene operaciones comunes en el uso de matrices, como la suma, resta, multiplicación y transpuesta. Además de la inicialización de las matrices.

## Ejecutable
El archivo ejecutable o principal de las implementaciones de Posix y OpenMp son los archivos MM1p y MM1c respectivamente. Estos reciben 2 parámetros por consola, el tamaño de la matriz y el número de hilos a emplear.
```bash
./MM1p.out <SIZE> <NUM_T>
```
```bash
./MM1c.out <SIZE> <NUM_T>
```

## Compilación
Para la compilación se tiene un script makeFile que automatiza el proceso de compilar los módulos y el principal de cada implementación.
```bash
make MM1p
```
```bash
make MM1c
```

## Ejecucion automatica.
Para la ejecución del benchmark por varias repeticiones, suficientes para tener una muestra significativa de resultados, para diferentes tamaños de matriz y usando diferentes números de hilos se realiza un script en Perl nombrado launcher.pl, las salidas resultantes se almacenan en el directorio de outputs.
```bash
chmod +x launcher.pl  
./launcher.pl
```

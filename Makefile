# Para compilar con el modo traza, revisar el fichero AVL.h

# Compilar el código fuente y generar un ejecutable: make
# Limpiar ficheros .o y ejecutable: make clean
# Ejemplo de ejecución: ./main

# Variables
CC = g++
CFLAGS = -std=c++11

# Objetivo por defecto (se ejecuta al correr solo "make")
make: include/AB.h include/ABB.h include/AVL.h include/NodoAVL.h include/NodoB.h src/main.cc
	$(CC) $(CFLAGS) -o main src/main.cc

# Limpiar los archivos binarios
clean:
	rm -f *.o main
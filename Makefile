# Lista todos los archivos .c en el directorio
SRC = $(wildcard *.c)

# Cambia la extensión .c por .o para obtener los archivos objeto
OBJ = $(SRC:.c=.o)

# Target principal
all: buscar

# Regla para compilar el ejecutable
buscar: $(OBJ)
	gcc -o $@ $^

# Regla genérica para compilar los archivos .o
%.o: %.c
	gcc -c -o $@ $<

# Limpieza de archivos
clean:
	rm -rf *.o buscar docs

# Generar documentación con Doxygen
doc:
	doxygen

# Abrir la documentación en el navegador
browsedoc: doc
	microsoft-edge-stable docs/html/index.html

# Instalar el binario en /usr/bin
install: buscar
	sudo cp -f buscar /usr/bin 

# Desinstalar el binario de /usr/bin
uninstall:
	sudo rm -f /usr/bin/buscar

#gcc -c -o main.o main.c Verificamos que el codigo este bien en sintaxis
#gcc -o buscar main.o Crea el ejecutable apartir de los archivos objeto

#una regla es un aarchivo que existe o deberia de existir o otra regla o los dos